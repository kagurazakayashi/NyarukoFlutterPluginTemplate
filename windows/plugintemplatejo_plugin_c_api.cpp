#include "include/plugintemplatejo/plugintemplatejo_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "plugintemplatejo_plugin.h"

// 函数：PlugintemplatejoPluginCApiRegisterWithRegistrar
// 功能：将插件注册到Flutter插件管理器中，供Flutter调用。
// 参数：
//   - registrar: Flutter桌面插件注册器的引用，用于完成插件的注册。
// 返回值：无
void PlugintemplatejoPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
    // 调用插件命名空间中的RegisterWithRegistrar方法，将插件注册到
    // Flutter插件注册器中，供Windows平台的Flutter程序使用。
    plugintemplatejo::PlugintemplatejoPlugin::RegisterWithRegistrar(
        flutter::PluginRegistrarManager::GetInstance()
        ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
