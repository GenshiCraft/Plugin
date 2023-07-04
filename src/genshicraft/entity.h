#ifndef GENSHICRAFT_ENTITY_H_
#define GENSHICRAFT_ENTITY_H_

#include <llapi/mc/Actor.hpp>

namespace genshicraft {

class Entity {
 public:
  Entity(Actor* actor);

  Entity(const Entity& other) = delete;
  Entity& operator=(const Entity& other) = delete;

  Entity(Entity&& other);
  Entity& operator=(Entity&& other);

  ~Entity();

  /// @brief Gets the unique ID of the entity.
  /// @return The unique ID of the entity.
  long long GetUniqueID() const;

 protected:
 private:
};

}  // namespace genshicraft

#endif  // GENSHICRAFT_ENTITY_H_
