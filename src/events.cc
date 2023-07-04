#include "events.h"

#include <llapi/EventAPI.h>
#include <llapi/HookAPI.h>

#include <llapi/mc/AnimatePacket.hpp>
#include <llapi/mc/NetworkIdentifier.hpp>
#include <llapi/mc/Player.hpp>
#include <llapi/mc/ServerNetworkHandler.hpp>
#include <llapi/mc/ServerPlayer.hpp>

#include "genshicraft/context.h"
#include "genshicraft/events/player_click_mouse_left_button_event.h"

bool HandlePlayerAttackEvent(Event::PlayerAttackEvent& event);
bool HandlePlayerSwingEvent(Event::PlayerSwingEvent& event);

// ---------------------------------------------------------

extern ::genshicraft::Context* g_context;

// ---------------------------------------------------------

void SubscribeToEvents() {
  Event::PlayerAttackEvent::subscribe_ref(HandlePlayerAttackEvent);
  Event::PlayerSwingEvent::subscribe_ref(
      HandlePlayerSwingEvent);  // Wait for LL fix.
}

bool HandlePlayerAttackEvent(Event::PlayerAttackEvent& mc_event) {
  // Check if the context is initialized.
  if (g_context == nullptr) {
    return false;
  }

  g_context->GetLogger().info("PlayerAttackEvent");

  return false;
}

bool HandlePlayerSwingEvent(Event::PlayerSwingEvent& mc_event) {
  // This event will be triggered when a player clicks his left mouse button.

  // Check if the context is initialized.
  if (g_context == nullptr) {
    return false;
  }

  auto event = ::genshicraft::PlayerClickMouseLeftButtonEvent(
      *g_context, (mc_event.mPlayer));

  return event.Trigger();
}

// ---------------------------------------------------------

THook(void,
      "?handle@ServerNetworkHandler@@UEAAXAEBVNetworkIdentifier@@"
      "AEBVAnimatePacket@@@Z",
      ServerNetworkHandler* serverNetworkHandler,
      NetworkIdentifier const& networkIdentifier,
      AnimatePacket const& animatePacket) {
  if (animatePacket.mAction == AnimatePacket::Action::Swing) {
    Event::PlayerSwingEvent ev{};
    ev.mPlayer = serverNetworkHandler->getServerPlayer(networkIdentifier);
    if (!ev.call()) {
      return;
    }
  }
  return original(serverNetworkHandler, networkIdentifier, animatePacket);
}
