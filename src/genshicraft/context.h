#ifndef GENSHICRAFT_CONTEXT_H_
#define GENSHICRAFT_CONTEXT_H_

#include <llapi/LoggerAPI.h>

#include <string>

namespace genshicraft {

class Context {
 public:
  /// @brief Constructs a new context.
  /// @param plugin_name The name of the plugin.
  Context(const std::string& plugin_name);

  Context(const Context&) = delete;
  Context& operator=(const Context&) = delete;

  Context(Context&&);
  Context& operator=(Context&&);

  ~Context();

  /// @brief Gets the logger.
  Logger& GetLogger();

 protected:
 private:
  Logger logger_;
};

}  // namespace genshicraft

#endif
