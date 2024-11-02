#ifndef FLUTTER_PLUGIN_PLUGINTEMPLATEJO_PLUGIN_H_
#define FLUTTER_PLUGIN_PLUGINTEMPLATEJO_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

namespace plugintemplatejo {

    // ����࣬���ڴ��� Flutter �� Windows ֮��Ľ�����
    class PlugintemplatejoPlugin : public flutter::Plugin {
    public:
        // �����ע�ᵽ Flutter �Ĳ��ע������
        // @param registrar Flutter �Ĳ��ע���������ڰ󶨲���� Flutter ���档
        static void RegisterWithRegistrar(flutter::PluginRegistrarWindows* registrar);

        // ���캯������ʼ�����ʵ����
        PlugintemplatejoPlugin();

        // �������������ٲ��ʵ��ʱ���á�
        virtual ~PlugintemplatejoPlugin();

        // ��ֹ��������͸�ֵ��������ֹ�ڲ���Ҫ������¸��Ʋ��ʵ����
        PlugintemplatejoPlugin(const PlugintemplatejoPlugin&) = delete;
        PlugintemplatejoPlugin& operator=(const PlugintemplatejoPlugin&) = delete;

        // �� Dart ��ͨ�� MethodChannel ���ò������ʱ���ᴥ���˺�����
        // @param method_call �������÷��������Ƽ�������
        // @param result ������ Dart ���ط������ý����
        void HandleMethodCall(
            const flutter::MethodCall<flutter::EncodableValue>& method_call,
            std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
    };

}  // namespace plugintemplatejo

#endif  // FLUTTER_PLUGIN_PLUGINTEMPLATEJO_PLUGIN_H_
