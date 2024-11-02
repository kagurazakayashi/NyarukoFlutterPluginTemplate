#include "plugintemplatejo_plugin.h"

// 必须在许多其他 Windows 头文件之前包含此文件。
#include <windows.h>

// 用于 getPlatformVersion；如果插件实现中不需要，可以删除。
#include <VersionHelpers.h>

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>

#include <memory>
#include <sstream>

namespace plugintemplatejo {

    // 静态方法，用于向 Flutter 注册插件
    void PlugintemplatejoPlugin::RegisterWithRegistrar(
        flutter::PluginRegistrarWindows* registrar) {
        // 创建一个方法通道，名字为 "plugintemplatejo"，用于 Flutter 和插件之间的通信
        auto channel =
            std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
                registrar->messenger(), "plugintemplatejo",
                &flutter::StandardMethodCodec::GetInstance());

        // 创建插件实例
        auto plugin = std::make_unique<PlugintemplatejoPlugin>();

        // 设置方法调用处理器，当通道接收到 Flutter 的方法调用时，将调用指定的处理函数
        channel->SetMethodCallHandler(
            [plugin_pointer = plugin.get()](const auto& call, auto result) {
                plugin_pointer->HandleMethodCall(call, std::move(result));
            });

        // 将插件实例添加到注册器中
        registrar->AddPlugin(std::move(plugin));
    }

    // 构造函数
    PlugintemplatejoPlugin::PlugintemplatejoPlugin() {}

    // 析构函数
    PlugintemplatejoPlugin::~PlugintemplatejoPlugin() {}

    // 方法调用处理函数
    void PlugintemplatejoPlugin::HandleMethodCall(
        const flutter::MethodCall<flutter::EncodableValue>& method_call,
        std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {
        // 检查方法名是否为 "getPlatformVersion"
        if (method_call.method_name().compare("getPlatformVersion") == 0) {
            std::ostringstream version_stream; // 用于构建版本信息的字符串流
            version_stream << "Windows ";
            // 判断当前操作系统的版本并添加对应的版本号信息
            if (IsWindows10OrGreater()) {
                version_stream << "10+";
            }
            else if (IsWindows8OrGreater()) {
                version_stream << "8";
            }
            else if (IsWindows7OrGreater()) {
                version_stream << "7";
            }
            // 返回版本信息给 Flutter
            result->Success(flutter::EncodableValue(version_stream.str()));
        }
        else {
            // 如果方法未实现，返回 NotImplemented
            result->NotImplemented();
        }
    }

}  // namespace plugintemplatejo
