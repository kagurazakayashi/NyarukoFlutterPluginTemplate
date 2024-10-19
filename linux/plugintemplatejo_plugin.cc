#include "include/plugintemplatejo/plugintemplatejo_plugin.h"

#include <flutter_linux/flutter_linux.h>
#include <gtk/gtk.h>
#include <sys/utsname.h>

#include <cstring>

#include "plugintemplatejo_plugin_private.h"

// 定义一个宏，用于强制转换为 PlugintemplatejoPlugin 类型
#define PLUGINTEMPLATEJO_PLUGIN(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), plugintemplatejo_plugin_get_type(), \
                              PlugintemplatejoPlugin))

// 插件的实例结构体，继承自 GObject
struct _PlugintemplatejoPlugin {
  GObject parent_instance;
};

// 定义 PlugintemplatejoPlugin 类型
G_DEFINE_TYPE(PlugintemplatejoPlugin, plugintemplatejo_plugin, g_object_get_type())

// 当从 Flutter 收到方法调用时调用的函数
static void plugintemplatejo_plugin_handle_method_call(
    PlugintemplatejoPlugin* self,
    FlMethodCall* method_call) {
  g_autoptr(FlMethodResponse) response = nullptr;

  // 获取方法名
  const gchar* method = fl_method_call_get_name(method_call);

  // 根据方法名执行相应的操作
  if (strcmp(method, "getPlatformVersion") == 0) {
    // 调用 get_platform_version() 方法，获取平台版本
    response = get_platform_version();
  } else {
    // 返回方法未实现的响应
    response = FL_METHOD_RESPONSE(fl_method_not_implemented_response_new());
  }

  // 发送响应给 Flutter
  fl_method_call_respond(method_call, response, nullptr);
}

// 获取平台版本信息
FlMethodResponse* get_platform_version() {
  // 使用 uname 获取系统版本信息
  struct utsname uname_data = {};
  uname(&uname_data);

  // 格式化版本信息为字符串
  g_autofree gchar *version = g_strdup_printf("Linux %s", uname_data.version);

  // 创建一个 FlValue 包含版本信息
  g_autoptr(FlValue) result = fl_value_new_string(version);

  // 返回包含成功响应的 FlMethodResponse
  return FL_METHOD_RESPONSE(fl_method_success_response_new(result));
}

// 清理插件对象时调用
static void plugintemplatejo_plugin_dispose(GObject* object) {
  G_OBJECT_CLASS(plugintemplatejo_plugin_parent_class)->dispose(object);
}

// 初始化插件类
static void plugintemplatejo_plugin_class_init(PlugintemplatejoPluginClass* klass) {
  G_OBJECT_CLASS(klass)->dispose = plugintemplatejo_plugin_dispose;
}

// 初始化插件实例
static void plugintemplatejo_plugin_init(PlugintemplatejoPlugin* self) {}

// 方法调用回调函数
static void method_call_cb(FlMethodChannel* channel, FlMethodCall* method_call,
                           gpointer user_data) {
  // 获取插件实例
  PlugintemplatejoPlugin* plugin = PLUGINTEMPLATEJO_PLUGIN(user_data);

  // 处理方法调用
  plugintemplatejo_plugin_handle_method_call(plugin, method_call);
}

// 在注册表中注册插件
void plugintemplatejo_plugin_register_with_registrar(FlPluginRegistrar* registrar) {
  // 创建插件实例
  PlugintemplatejoPlugin* plugin = PLUGINTEMPLATEJO_PLUGIN(
      g_object_new(plugintemplatejo_plugin_get_type(), nullptr));

  // 创建一个标准方法编解码器
  g_autoptr(FlStandardMethodCodec) codec = fl_standard_method_codec_new();

  // 创建一个方法通道
  g_autoptr(FlMethodChannel) channel =
      fl_method_channel_new(fl_plugin_registrar_get_messenger(registrar), "plugintemplatejo", // 通道名称
      FL_METHOD_CODEC(codec));

  // 设置方法调用处理程序
  fl_method_channel_set_method_call_handler(channel, method_call_cb, g_object_ref(plugin), g_object_unref);

  // 释放插件实例
  g_object_unref(plugin);
}
