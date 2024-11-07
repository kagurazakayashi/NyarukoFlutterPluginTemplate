/// 代表一个包含 `data` 和 `payload` 两个属性的对象。
/// 提供序列化和反序列化的方法。
class MyObject {
  /// 构造函数，创建一个 `MyObject` 实例。
  ///
  /// 参数：
  /// - [data]: 字符串类型的数据。
  /// - [payload]: 整数列表类型的有效载荷。
  const MyObject({
    required this.data, // 字符串类型的数据。
    required this.payload, // 整数列表类型的有效载荷。
  });

  /// `data` 字段，表示与对象相关的字符串数据。
  final String data;

  /// `payload` 字段，表示与对象相关的整数列表数据。
  final List<int> payload;

  /// 将当前对象转换为 JSON 格式的 Map。
  ///
  /// 返回：
  /// 一个包含 `data` 和 `payload` 的 Map。
  Map<String, Object?> toJson() {
    return {
      'data': data, // 转换后的数据字段。
      'payload': payload, // 转换后的有效载荷字段。
    };
  }

  /// 从 Map 中创建一个 `MyObject` 实例。
  ///
  /// 参数：
  /// - [map]: 包含 `data` 和 `payload` 数据的 Map。
  ///
  /// 返回：
  /// 一个新的 `MyObject` 实例。
  factory MyObject.fromMap(Map<String, Object?> map) {
    // 提取并转换 `payload` 列表的内容为整数列表。
    List payloadList = map['payload'] as List;
    List<int> payload = payloadList.map((e) => e as int).toList();
    return MyObject(
      data: map['data'] as String, // 提取并强制转换为字符串类型。
      payload: payload, // 提取并转换为整数列表类型。
    );
  }

  /// 重写的 `toString` 方法，用于提供对象的字符串表示形式。
  ///
  /// 返回：
  /// 当前对象的字符串表示，例如：`{data: value, payload: [1, 2, 3]}`。
  @override
  String toString() {
    return '{data: $data, payload: $payload}'; // 拼接 `data` 和 `payload` 字段。
  }
}
