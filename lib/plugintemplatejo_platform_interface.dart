import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'plugintemplatejo_method_channel.dart';

abstract class PlugintemplatejoPlatform extends PlatformInterface {
  /// Constructs a PlugintemplatejoPlatform.
  PlugintemplatejoPlatform() : super(token: _token);

  static final Object _token = Object();

  static PlugintemplatejoPlatform _instance = MethodChannelPlugintemplatejo();

  /// The default instance of [PlugintemplatejoPlatform] to use.
  ///
  /// Defaults to [MethodChannelPlugintemplatejo].
  static PlugintemplatejoPlatform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [PlugintemplatejoPlatform] when
  /// they register themselves.
  static set instance(PlugintemplatejoPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<String?> getPlatformVersion() {
    throw UnimplementedError('platformVersion() has not been implemented.');
  }
}
