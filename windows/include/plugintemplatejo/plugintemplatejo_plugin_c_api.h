#ifndef FLUTTER_PLUGIN_PLUGINTEMPLATEJO_PLUGIN_C_API_H_
#define FLUTTER_PLUGIN_PLUGINTEMPLATEJO_PLUGIN_C_API_H_

// ���� Flutter ���ע���ͷ�ļ�
#include <flutter_plugin_registrar.h>

// ���嵼���꣬�����Ƿ����� FLUTTER_PLUGIN_IMPL ������������
#ifdef FLUTTER_PLUGIN_IMPL
#define FLUTTER_PLUGIN_EXPORT __declspec(dllexport) // ��������� FLUTTER_PLUGIN_IMPL���򵼳�����
#else
#define FLUTTER_PLUGIN_EXPORT __declspec(dllimport) // ���δ���� FLUTTER_PLUGIN_IMPL����� DLL �������
#endif

// ���ʹ�õ��� C++ ��������ȷ��ʹ�� C ���Եĺ���������
#if defined(__cplusplus)
extern "C" {
#endif

    // �������ע�ắ��
    // �ú������ڽ����ע�ᵽ Flutter ���滷����
    // ������registrar - Flutter ������ע��������
    FLUTTER_PLUGIN_EXPORT void PlugintemplatejoPluginCApiRegisterWithRegistrar(
        FlutterDesktopPluginRegistrarRef registrar);

#if defined(__cplusplus)
}  // extern "C"
#endif

#endif  // FLUTTER_PLUGIN_PLUGINTEMPLATEJO_PLUGIN_C_API_H_
