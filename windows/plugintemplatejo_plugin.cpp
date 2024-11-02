#include "plugintemplatejo_plugin.h"

// ������������� Windows ͷ�ļ�֮ǰ�������ļ���
#include <windows.h>

// ���� getPlatformVersion��������ʵ���в���Ҫ������ɾ����
#include <VersionHelpers.h>

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>

#include <memory>
#include <sstream>

namespace plugintemplatejo {

    // ��̬������������ Flutter ע����
    void PlugintemplatejoPlugin::RegisterWithRegistrar(
        flutter::PluginRegistrarWindows* registrar) {
        // ����һ������ͨ��������Ϊ "plugintemplatejo"������ Flutter �Ͳ��֮���ͨ��
        auto channel =
            std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
                registrar->messenger(), "plugintemplatejo",
                &flutter::StandardMethodCodec::GetInstance());

        // �������ʵ��
        auto plugin = std::make_unique<PlugintemplatejoPlugin>();

        // ���÷������ô���������ͨ�����յ� Flutter �ķ�������ʱ��������ָ���Ĵ�����
        channel->SetMethodCallHandler(
            [plugin_pointer = plugin.get()](const auto& call, auto result) {
                plugin_pointer->HandleMethodCall(call, std::move(result));
            });

        // �����ʵ����ӵ�ע������
        registrar->AddPlugin(std::move(plugin));
    }

    // ���캯��
    PlugintemplatejoPlugin::PlugintemplatejoPlugin() {}

    // ��������
    PlugintemplatejoPlugin::~PlugintemplatejoPlugin() {}

    // �������ô�����
    void PlugintemplatejoPlugin::HandleMethodCall(
        const flutter::MethodCall<flutter::EncodableValue>& method_call,
        std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {
        // ��鷽�����Ƿ�Ϊ "getPlatformVersion"
        if (method_call.method_name().compare("getPlatformVersion") == 0) {
            std::ostringstream version_stream; // ���ڹ����汾��Ϣ���ַ�����
            version_stream << "Windows ";
            // �жϵ�ǰ����ϵͳ�İ汾����Ӷ�Ӧ�İ汾����Ϣ
            if (IsWindows10OrGreater()) {
                version_stream << "10+";
            }
            else if (IsWindows8OrGreater()) {
                version_stream << "8";
            }
            else if (IsWindows7OrGreater()) {
                version_stream << "7";
            }
            // ���ذ汾��Ϣ�� Flutter
            result->Success(flutter::EncodableValue(version_stream.str()));
        }
        else {
            // �������δʵ�֣����� NotImplemented
            result->NotImplemented();
        }
    }

}  // namespace plugintemplatejo
