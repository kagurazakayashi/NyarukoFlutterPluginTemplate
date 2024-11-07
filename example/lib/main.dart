import 'dart:convert';

import 'package:flutter/material.dart';
import 'dart:async';

import 'package:flutter/services.dart';
import 'package:plugintemplatejo/plugintemplatejo.dart';

void main() {
  runApp(const MyApp());
}

// 应用的根组件
class MyApp extends StatefulWidget {
  const MyApp({super.key});

  @override
  State<MyApp> createState() => _MyAppState();
}

// 应用的状态类
class _MyAppState extends State<MyApp> {
  String _platformVersion = 'Unknown'; // 当前平台的版本信息
  final _plugintemplatejoPlugin = Plugintemplatejo(); // 插件实例

  // 示例插件中提供的对象类型新建对象
  MyObject myObject = const MyObject(data: 'Hello', payload: [1, 2, 3]);

  @override
  void initState() {
    super.initState();
    // 初始化平台状态
    initPlatformState();
    print('插件初始化: $_plugintemplatejoPlugin'); // 打印插件实例

    // 示例插件中提供的对象类型的序列化和反序列化
    print('插件中的对象类型演示: $myObject'); // 打印初始化的对象
    String myObjectString = jsonEncode(myObject); // 将对象转为 JSON 字符串
    print('插件对象的 JSON 字符串输出功能: $myObjectString'); // 打印 JSON 字符串
    MyObject myObjectNew =
        MyObject.fromMap(jsonDecode(myObjectString)); // 从 JSON 字符串解析对象
    print('将 JSON 字符串转换回对象: $myObjectNew'); // 打印新解析的对象
  }

  /// 初始化平台状态的方法
  ///
  /// 平台消息是异步的，因此我们使用 `async` 方法进行初始化。
  Future<void> initPlatformState() async {
    String platformVersion;
    // 平台消息可能会失败，因此我们使用 try/catch 捕获 PlatformException。
    // 同时我们也处理了消息可能返回 null 的情况。
    try {
      platformVersion = await _plugintemplatejoPlugin.getPlatformVersion() ??
          'Unknown platform version'; // 获取平台版本信息
    } on PlatformException {
      platformVersion = 'Failed to get platform version.'; // 捕获异常时的默认消息
    }

    // 如果在异步消息返回之前，Widget 已从树中移除，则放弃处理该消息。
    if (!mounted) return;

    // 更新状态以刷新界面
    setState(() {
      _platformVersion = platformVersion;
    });
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Plugin example app'), // 应用标题
        ),
        body: Center(
          child: Text('Running on: $_platformVersion\n'), // 显示平台版本信息
        ),
      ),
    );
  }
}
