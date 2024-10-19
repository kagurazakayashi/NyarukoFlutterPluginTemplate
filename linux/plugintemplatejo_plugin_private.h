#include <flutter_linux/flutter_linux.h>

#include "include/plugintemplatejo/plugintemplatejo_plugin.h"

// 此文件暴露了一些插件内部实现以便进行单元测试。
// 有关单元测试 API 的当前限制，请参阅 https://github.com/flutter/flutter/issues/88724。

/**
 * @brief 处理 getPlatformVersion 方法调用。
 * 
 * 此函数实现了对 "getPlatformVersion" 方法的响应，通常用于获取当前平台的版本信息。
 * 返回的响应以 FlMethodResponse 对象的形式表示。
 * 
 * @return FlMethodResponse* 包含平台版本信息的响应。
 */
FlMethodResponse *get_platform_version();
