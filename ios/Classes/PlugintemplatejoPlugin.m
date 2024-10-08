#import "PlugintemplatejoPlugin.h"

@implementation PlugintemplatejoPlugin

/// 注册插件到 Flutter 框架
/// @param registrar Flutter 插件注册器，用于与 Flutter 框架通信
+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
    // 创建一个 Flutter 方法通道，用于 Dart 和原生 iOS 之间的通信
    FlutterMethodChannel* channel = [FlutterMethodChannel
                                     methodChannelWithName:@"plugintemplatejo" // Dart 和原生的通道名称
                                     binaryMessenger:[registrar messenger]]; // 获取消息传递器
    
    // 实例化插件对象
    PlugintemplatejoPlugin* instance = [[PlugintemplatejoPlugin alloc] init];
    
    // 将插件实例作为方法调用的代理
    [registrar addMethodCallDelegate:instance channel:channel];
}

/// 处理来自 Flutter 的方法调用
/// @param call 包含来自 Flutter 的调用信息，包括方法名和参数
/// @param result 回调，用于返回调用结果给 Flutter
- (void)handleMethodCall:(FlutterMethodCall*)call result:(FlutterResult)result {
    // 判断方法名是否为 "getPlatformVersion"
    if ([@"getPlatformVersion" isEqualToString:call.method]) {
        // 返回 iOS 系统版本号，格式为 "iOS [版本号]"
        result([@"iOS " stringByAppendingString:[[UIDevice currentDevice] systemVersion]]);
    } else {
        // 如果调用的方法未被实现，返回 FlutterMethodNotImplemented
        result(FlutterMethodNotImplemented);
    }
}

@end
