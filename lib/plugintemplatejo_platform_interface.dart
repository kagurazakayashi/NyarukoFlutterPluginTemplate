import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'plugintemplatejo_method_channel.dart';

/// 抽象类，定义插件的跨平台接口。
/// 所有平台特定的实现都需要继承自此类并实现其方法。
abstract class PlugintemplatejoPlatform extends PlatformInterface {
  /// 构造函数，用于创建一个 [PlugintemplatejoPlatform] 实例。
  PlugintemplatejoPlatform() : super(token: _token);

  // 用于验证实例合法性的令牌。
  static final Object _token = Object();

  // 默认实现的实例，使用 [MethodChannelPlugintemplatejo]。
  static PlugintemplatejoPlatform _instance = MethodChannelPlugintemplatejo();

  /// 获取当前默认的 [PlugintemplatejoPlatform] 实例。
  ///
  /// 默认为 [MethodChannelPlugintemplatejo]。
  static PlugintemplatejoPlatform get instance => _instance;

  /// 设置 [PlugintemplatejoPlatform] 的实例。
  ///
  /// 平台特定的实现应该通过注册它们自己的实现类来设置此实例。
  /// 在设置实例时，会使用 [_token] 验证实例的合法性。
  static set instance(PlugintemplatejoPlatform instance) {
    // 验证传入的实例是否具有正确的 token，确保其合法性。
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  /// 获取平台版本号的异步方法。
  ///
  /// 平台特定的实现需要重写此方法以返回实际的版本号。
  /// 如果没有实现该方法，则会抛出 [UnimplementedError]。
  Future<String?> getPlatformVersion() {
    throw UnimplementedError('platformVersion() 方法尚未实现。');
  }
}
