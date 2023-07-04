#include "player_click_mouse_left_button_event.h"

#include <llapi/LoggerAPI.h>

#include <utility>

#include "genshicraft/context.h"

namespace genshicraft {

PlayerClickMouseLeftButtonEvent::PlayerClickMouseLeftButtonEvent(
    Context& context, Player* player)
    : context_(context), player_(player) {}

PlayerClickMouseLeftButtonEvent::PlayerClickMouseLeftButtonEvent(
    PlayerClickMouseLeftButtonEvent&& other)
    : context_(other.context_), player_(other.player_) {}

PlayerClickMouseLeftButtonEvent& PlayerClickMouseLeftButtonEvent::operator=(
    PlayerClickMouseLeftButtonEvent&& other) {
  context_ = std::move(other.context_);
  player_ = other.player_;
  other.player_ = nullptr;
  return *this;
}

PlayerClickMouseLeftButtonEvent::~PlayerClickMouseLeftButtonEvent() {}

bool PlayerClickMouseLeftButtonEvent::Trigger() const {
  context_.GetLogger().info("PlayerClickMouseLeftButtonEvent triggered.");
  return true;
}

}  // namespace genshicraft
