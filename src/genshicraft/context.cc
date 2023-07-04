#include "context.h"

#include <llapi/LoggerAPI.h>

#include <string>

namespace genshicraft {

Context::Context(const std::string& plugin_name)
    : logger_(Logger(plugin_name)) {}

Context::Context(Context&&) {}

Context& Context::operator=(Context&&) {}

Context::~Context() {}

Logger& Context::GetLogger() { return logger_; }

}  // namespace genshicraft
