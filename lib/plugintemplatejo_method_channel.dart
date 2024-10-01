import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'plugintemplatejo_platform_interface.dart';

/// An implementation of [PlugintemplatejoPlatform] that uses method channels.
class MethodChannelPlugintemplatejo extends PlugintemplatejoPlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('plugintemplatejo');

  @override
  Future<String?> getPlatformVersion() async {
    final version = await methodChannel.invokeMethod<String>('getPlatformVersion');
    return version;
  }
}
