#ifndef FLUTTER_PLUGIN_PLUGINTEMPLATEJO_PLUGIN_H_
#define FLUTTER_PLUGIN_PLUGINTEMPLATEJO_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

namespace plugintemplatejo {

    // 插件类，用于处理 Flutter 与 Windows 之间的交互。
    class PlugintemplatejoPlugin : public flutter::Plugin {
    public:
        // 将插件注册到 Flutter 的插件注册器。
        // @param registrar Flutter 的插件注册器，用于绑定插件与 Flutter 引擎。
        static void RegisterWithRegistrar(flutter::PluginRegistrarWindows* registrar);

        // 构造函数，初始化插件实例。
        PlugintemplatejoPlugin();

        // 析构函数，销毁插件实例时调用。
        virtual ~PlugintemplatejoPlugin();

        // 禁止拷贝构造和赋值操作，防止在不必要的情况下复制插件实例。
        PlugintemplatejoPlugin(const PlugintemplatejoPlugin&) = delete;
        PlugintemplatejoPlugin& operator=(const PlugintemplatejoPlugin&) = delete;

        // 当 Dart 端通过 MethodChannel 调用插件方法时，会触发此函数。
        // @param method_call 包含调用方法的名称及参数。
        // @param result 用于向 Dart 返回方法调用结果。
        void HandleMethodCall(
            const flutter::MethodCall<flutter::EncodableValue>& method_call,
            std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
    };

}  // namespace plugintemplatejo

#endif  // FLUTTER_PLUGIN_PLUGINTEMPLATEJO_PLUGIN_H_
