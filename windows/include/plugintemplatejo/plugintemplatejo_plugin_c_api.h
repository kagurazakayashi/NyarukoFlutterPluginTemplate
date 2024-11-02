#ifndef FLUTTER_PLUGIN_PLUGINTEMPLATEJO_PLUGIN_C_API_H_
#define FLUTTER_PLUGIN_PLUGINTEMPLATEJO_PLUGIN_C_API_H_

// 包含 Flutter 插件注册的头文件
#include <flutter_plugin_registrar.h>

// 定义导出宏，根据是否定义了 FLUTTER_PLUGIN_IMPL 决定导出符号
#ifdef FLUTTER_PLUGIN_IMPL
#define FLUTTER_PLUGIN_EXPORT __declspec(dllexport) // 如果定义了 FLUTTER_PLUGIN_IMPL，则导出符号
#else
#define FLUTTER_PLUGIN_EXPORT __declspec(dllimport) // 如果未定义 FLUTTER_PLUGIN_IMPL，则从 DLL 导入符号
#endif

// 如果使用的是 C++ 编译器，确保使用 C 语言的函数名规则
#if defined(__cplusplus)
extern "C" {
#endif

    // 声明插件注册函数
    // 该函数用于将插件注册到 Flutter 桌面环境中
    // 参数：registrar - Flutter 桌面插件注册器引用
    FLUTTER_PLUGIN_EXPORT void PlugintemplatejoPluginCApiRegisterWithRegistrar(
        FlutterDesktopPluginRegistrarRef registrar);

#if defined(__cplusplus)
}  // extern "C"
#endif

#endif  // FLUTTER_PLUGIN_PLUGINTEMPLATEJO_PLUGIN_C_API_H_
