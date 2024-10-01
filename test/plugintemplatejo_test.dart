import 'package:flutter_test/flutter_test.dart';
import 'package:plugintemplatejo/plugintemplatejo.dart';
import 'package:plugintemplatejo/plugintemplatejo_platform_interface.dart';
import 'package:plugintemplatejo/plugintemplatejo_method_channel.dart';
import 'package:plugin_platform_interface/plugin_platform_interface.dart';

class MockPlugintemplatejoPlatform
    with MockPlatformInterfaceMixin
    implements PlugintemplatejoPlatform {

  @override
  Future<String?> getPlatformVersion() => Future.value('42');
}

void main() {
  final PlugintemplatejoPlatform initialPlatform = PlugintemplatejoPlatform.instance;

  test('$MethodChannelPlugintemplatejo is the default instance', () {
    expect(initialPlatform, isInstanceOf<MethodChannelPlugintemplatejo>());
  });

  test('getPlatformVersion', () async {
    Plugintemplatejo plugintemplatejoPlugin = Plugintemplatejo();
    MockPlugintemplatejoPlatform fakePlatform = MockPlugintemplatejoPlatform();
    PlugintemplatejoPlatform.instance = fakePlatform;

    expect(await plugintemplatejoPlugin.getPlatformVersion(), '42');
  });
}
