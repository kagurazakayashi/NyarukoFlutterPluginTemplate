package moe.yashi.plugintemplatejo;

import androidx.annotation.NonNull;

import io.flutter.embedding.engine.plugins.FlutterPlugin;
import io.flutter.plugin.common.MethodCall;
import io.flutter.plugin.common.MethodChannel;
import io.flutter.plugin.common.MethodChannel.MethodCallHandler;
import io.flutter.plugin.common.MethodChannel.Result;

/** 
 * PlugintemplatejoPlugin
 * 这是一个 Flutter 插件的实现类，用于在 Flutter 和原生 Android 之间进行通信。
 */
public class PlugintemplatejoPlugin implements FlutterPlugin, MethodCallHandler {
  // 用于 Flutter 和原生 Android 之间通信的 MethodChannel
  // 此变量用于注册插件到 Flutter 引擎，并在 Flutter 引擎从 Activity 中分离时解除注册
  private MethodChannel channel;

  /**
   * 当插件被附加到 Flutter 引擎时调用。
   * @param flutterPluginBinding 提供与 Flutter 引擎交互的绑定。
   */
  @Override
  public void onAttachedToEngine(@NonNull FlutterPluginBinding flutterPluginBinding) {
    // 初始化 MethodChannel 并指定名称 "plugintemplatejo"
    channel = new MethodChannel(flutterPluginBinding.getBinaryMessenger(), "plugintemplatejo");
    // 设置 MethodCallHandler 以处理来自 Flutter 的方法调用
    channel.setMethodCallHandler(this);
  }

  /**
   * 处理来自 Flutter 的方法调用。
   * @param call 包含调用方法的名称和参数。
   * @param result 用于返回方法调用的结果给 Flutter。
   */
  @Override
  public void onMethodCall(@NonNull MethodCall call, @NonNull Result result) {
    // 检查方法名称是否为 "getPlatformVersion"
    if (call.method.equals("getPlatformVersion")) {
      // 返回当前 Android 系统版本
      result.success("Android " + android.os.Build.VERSION.RELEASE);
    } else {
      // 如果方法未实现，返回 notImplemented
      result.notImplemented();
    }
  }

  /**
   * 当插件从 Flutter 引擎分离时调用。
   * @param binding 提供与 Flutter 引擎交互的绑定。
   */
  @Override
  public void onDetachedFromEngine(@NonNull FlutterPluginBinding binding) {
    // 移除当前的 MethodCallHandler
    channel.setMethodCallHandler(null);
  }
}
