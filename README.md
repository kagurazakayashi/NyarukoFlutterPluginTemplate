# plugintemplatejo

一个 Flutter 插件项目模板，用于记录 Flutter 是如何和原生语言交互。

Java + Objective-C 版本

[官方文档](https://docs.flutter.dev/packages-and-plugins/developing-packages#edit-plugin-package)

## Flutter 端代码

### `lib/plugintemplatejo.dart`

这是插件的主要入口文件，通常用来暴露插件提供的功能给 Dart 层使用。

- 定义插件的公共 API。
- 通过调用底层的 `platform_interface` 来实现平台交互。
- 如果插件是纯 Dart 实现，则可能直接在这个文件中完成所有逻辑。

### `plugintemplatejo_method_channel.dart`

定义使用 `MethodChannel` 与平台（如 Android 和 iOS）通信的逻辑。

- 继承或实现自 `plugintemplatejo_platform_interface.dart` 中定义的接口。
- 使用 Flutter 提供的 `MethodChannel` 在 Dart 层和原生代码之间通信。
- 处理平台特定的逻辑。

### `plugintemplatejo_platform_interface.dart`

定义插件的跨平台接口（Platform Interface），是所有平台实现的基础。

- 定义抽象类或接口，描述插件功能。
- 提供默认实现（可选）。
- 通过 `instance` 或其他设计模式，使 Dart 层能够使用具体的实现（如 `MethodChannel`）。
- 确保插件支持灵活的扩展性（如 Web 或其他平台实现）。

### 上面三个文件的关系

`plugintemplatejo.dart` 调用 `plugintemplatejo_platform_interface.dart` 定义的接口，接口的内容在 `plugintemplatejo_method_channel.dart` 。

- `plugintemplatejo.dart` 是入口文件，负责调用 `plugintemplatejo_platform_interface.dart` 中的接口。
- `plugintemplatejo_platform_interface.dart` 是插件的核心接口文件，定义了插件的功能。
- `plugintemplatejo_method_channel.dart` 提供了一个具体实现，使用 `MethodChannel` 与原生代码通信，并实现了接口中的功能。

通过这种结构，可以轻松扩展支持新的平台。这种分层设计让插件更易于维护、扩展和测试。例如：

- 使用 MethodChannel 处理 iOS 和 Android。
- 使用另一个 Dart-only 实现处理 Web。

## Android 端代码

在编辑代码之前，先至少构建过一次。

```sh
cd example
flutter build apk --config-only
```

1. 启动 `Android Studio`，在“欢迎使用 Android Studio”对话框中选择“打开现有 Android Studio 项目”，或从菜单中选择“文件 > 打开”，然后选择 `example/android/build.gradle` 文件。
2. 在 Gradle 同步对话框中，选择确定。在 Android Gradle 插件更新对话框中，选择此项目不再提醒我。

源码文件在 `Android Studio` 中: [android/src/main/java/moe/yashi/plugintemplatejo/PlugintemplatejoPlugin.java](android/src/main/java/moe/yashi/plugintemplatejo/PlugintemplatejoPlugin.java)

位于项目文件夹: 同上

![Android Studio](readme.img/android_src.png)

## iOS 端代码

在编辑代码之前，先至少构建过一次。

```sh
cd example
flutter build ios --no-codesign --config-only
open example/ios/Runner.xcworkspace # 打开 Xcode
```

源码文件在 `Xcode` 中: `Pods/Development Pods/plugintemplatejo/../../example/ios/.symlinks/plugins/plugintemplatejo/ios/Classes/PlugintemplatejoPlugin.m`

位于项目文件夹: [ios/Classes/PlugintemplatejoPlugin.m](ios/Classes/PlugintemplatejoPlugin.m)

如果使用的是 `sharedDarwinSource` ，路径将以 `plugintemplatejo/darwin/Classes/PlugintemplatejoPlugin.m` 结尾。

![Xcode](readme.img/ios_src.png)
