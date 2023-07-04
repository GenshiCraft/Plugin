#ifndef GENSHICRAFT_EVENTS_PLAYER_SWING_EVENT_H_
#define GENSHICRAFT_EVENTS_PLAYER_SWING_EVENT_H_

#include <llapi/mc/Player.hpp>

#include "genshicraft/context.h"
#include "genshicraft/events/event_interface.h"

namespace genshicraft {

/// @brief The event that is triggered when a player clicks his left mouse
/// button.
class PlayerClickMouseLeftButtonEvent : IEvent {
 public:
  PlayerClickMouseLeftButtonEvent(Context& context, Player* player);

  PlayerClickMouseLeftButtonEvent(const PlayerClickMouseLeftButtonEvent&) =
      delete;
  PlayerClickMouseLeftButtonEvent& operator=(
      const PlayerClickMouseLeftButtonEvent&) = delete;

  PlayerClickMouseLeftButtonEvent(PlayerClickMouseLeftButtonEvent&&);
  PlayerClickMouseLeftButtonEvent& operator=(PlayerClickMouseLeftButtonEvent&&);

  ~PlayerClickMouseLeftButtonEvent();

  /// @brief Triggers the event.
  /// @return False to stop the event chain.
  bool Trigger() const override;

 protected:
 private:
  Context& context_;
  Player* player_;
};

}  // namespace genshicraft

#endif  // GENSHICRAFT_EVENTS_PLAYER_SWING_EVENT_H_
