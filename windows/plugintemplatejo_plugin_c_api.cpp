#include "include/plugintemplatejo/plugintemplatejo_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "plugintemplatejo_plugin.h"

void PlugintemplatejoPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  plugintemplatejo::PlugintemplatejoPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
