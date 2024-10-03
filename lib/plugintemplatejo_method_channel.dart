import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'plugintemplatejo_platform_interface.dart';

/// [PlugintemplatejoPlatform] 的一个实现类，
/// 使用方法通道（Method Channel）与原生平台进行交互。
class MethodChannelPlugintemplatejo extends PlugintemplatejoPlatform {
  /// 用于与原生平台交互的方法通道。
  ///
  /// `@visibleForTesting` 修饰符表示此字段在测试时可见。
  @visibleForTesting
  final methodChannel = const MethodChannel('plugintemplatejo');

  /// 调用原生平台方法获取平台版本信息。
  ///
  /// 使用方法通道调用原生平台上的 `getPlatformVersion` 方法，
  /// 并返回结果。
  ///
  /// 返回：
  /// - 一个 [Future]，其中包含从原生平台返回的版本字符串，
  ///   如果调用失败，返回 `null`。
  @override
  Future<String?> getPlatformVersion() async {
    // 调用原生方法 'getPlatformVersion' 获取平台版本信息。
    final version =
        await methodChannel.invokeMethod<String>('getPlatformVersion');
    return version; // 返回从原生平台获取的版本信息。
  }
}
