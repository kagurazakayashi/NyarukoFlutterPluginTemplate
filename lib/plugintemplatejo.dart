import 'plugintemplatejo_platform_interface.dart';

/// Plugintemplatejo 类封装了插件的核心功能，用于与平台相关的接口通信。
class Plugintemplatejo {
  /// 获取平台的版本号。
  ///
  /// 这是一个异步方法，会返回一个 `Future`，包含平台的版本号（`String` 类型），
  /// 如果失败则返回 `null`。
  ///
  /// 示例：
  /// ```dart
  /// final version = await Plugintemplatejo().getPlatformVersion();
  /// print('Platform Version: $version');
  /// ```
  Future<String?> getPlatformVersion() {
    // 调用平台接口的实例方法，获取平台版本号。
    return PlugintemplatejoPlatform.instance.getPlatformVersion();
    // -> _platform_interface.dart
  }
}
