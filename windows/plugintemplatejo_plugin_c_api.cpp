#include "include/plugintemplatejo/plugintemplatejo_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "plugintemplatejo_plugin.h"

// ������PlugintemplatejoPluginCApiRegisterWithRegistrar
// ���ܣ������ע�ᵽFlutter����������У���Flutter���á�
// ������
//   - registrar: Flutter������ע���������ã�������ɲ����ע�ᡣ
// ����ֵ����
void PlugintemplatejoPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
    // ���ò�������ռ��е�RegisterWithRegistrar�����������ע�ᵽ
    // Flutter���ע�����У���Windowsƽ̨��Flutter����ʹ�á�
    plugintemplatejo::PlugintemplatejoPlugin::RegisterWithRegistrar(
        flutter::PluginRegistrarManager::GetInstance()
        ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
