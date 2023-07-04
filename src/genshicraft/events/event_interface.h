#ifndef GENSHICRAFT_EVENTS_EVENT_INTERFACE_H_
#define GENSHICRAFT_EVENTS_EVENT_INTERFACE_H_

namespace genshicraft {

/// @brief The interface for all events.
class IEvent {
 public:
  /// @brief Triggers the event.
  /// @return False to stop the event chain.
  virtual bool Trigger() const = 0;
};

}  // namespace genshicraft

#endif  // GENSHICRAFT_EVENTS_EVENT_INTERFACE_H_
