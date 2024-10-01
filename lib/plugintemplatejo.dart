
import 'plugintemplatejo_platform_interface.dart';

class Plugintemplatejo {
  Future<String?> getPlatformVersion() {
    return PlugintemplatejoPlatform.instance.getPlatformVersion();
  }
}
