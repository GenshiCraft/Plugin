#include <llapi/LLAPI.h>
#include <llapi/LoggerAPI.h>
#include <llapi/ServerAPI.h>
#include <windows.h>

#include <iostream>
#include <map>
#include <string>

#include "version.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call,
                      LPVOID lpReserved) {
  switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
      ll::registerPlugin(
          PLUGIN_NAME, PLUGIN_DESCRIPTION,
          ll::Version(PLUGIN_VERSION_MAJOR, PLUGIN_VERSION_MINOR,
                      PLUGIN_VERSION_PATCH,
                      static_cast<ll::Version::Status>(PLUGIN_STATUS)),
          std::map<std::string, std::string>{
              {"Author", PLUGIN_AUTHOR},
          });
      break;

    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
      break;
  }
  return TRUE;
}

void CheckProtocolVersion() {
  auto currentProtocol = ll::getServerProtocolVersion();
  if (PLUGIN_TARGET_PROTOCOL_VERSION != currentProtocol) {
    auto logger = Logger(PLUGIN_NAME);

    logger.warn(
        "Protocol version not match, target version: {}, current version: {}.",
        PLUGIN_TARGET_PROTOCOL_VERSION, currentProtocol);
    logger.warn(
        "This will most likely crash the server, please use the Plugin that "
        "matches the BDS version!");
  }
}

extern "C" {
_declspec(dllexport) void onPostInit() {
  std::ios::sync_with_stdio(false);
  CheckProtocolVersion();
}
}
