import Cocoa
import FlutterMacOS

/// 插件类，继承自 `NSObject` 并实现 `FlutterPlugin` 协议。
/// 用于处理 Flutter 与 macOS 原生代码之间的交互。
public class PlugintemplatejoPlugin: NSObject, FlutterPlugin {
    
    /// 注册插件到 Flutter 中。
    /// - 参数:
    ///   - registrar: Flutter 提供的注册器，用于将插件与 Flutter 通信通道关联起来。
    public static func register(with registrar: FlutterPluginRegistrar) {
        // 创建一个方法通道，名称为 "plugintemplatejo"，用于与 Flutter 进行通信。
        let channel = FlutterMethodChannel(name: "plugintemplatejo", binaryMessenger: registrar.messenger)
        // 实例化插件类。
        let instance = PlugintemplatejoPlugin()
        // 将插件实例与方法通道绑定，这样可以监听来自 Flutter 的方法调用。
        registrar.addMethodCallDelegate(instance, channel: channel)
    }
    
    /// 处理来自 Flutter 的方法调用。
    /// - 参数:
    ///   - call: 包含方法名称和参数的对象，表示一次来自 Flutter 的调用。
    ///   - result: 一个闭包，用于返回处理结果给 Flutter。
    public func handle(_ call: FlutterMethodCall, result: @escaping FlutterResult) {
        switch call.method {
        case "getPlatformVersion":
            // 如果方法名为 "getPlatformVersion"，返回 macOS 的操作系统版本字符串。
            result("macOS " + ProcessInfo.processInfo.operatingSystemVersionString)
        default:
            // 如果方法名未定义，返回未实现的标识。
            result(FlutterMethodNotImplemented)
        }
    }
}
