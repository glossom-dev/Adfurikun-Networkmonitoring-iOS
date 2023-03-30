## Network Monitoringについて

Network Monitoringモジュールはアドフリくんで使っているアドネットワークの通信内容をモニターリングして通信のResponse Time, Request Sizeなどを監視して負荷が高いアドネットワークに対して適切な対応が出来るライブラリーです。

## 導入手順

### CocoaPodsを利用する場合

Podfile に以下の記述を追加して下さい。

```
  pod 'Adfurikun-Networkmonitoring-iOS'
```


### 手動で導入する場合

Network Monitoring Libraryファイル（ADFNetworkMonitor.xcframework）をXcode Projectに追加します。

### Dependency Library

* Foundation.framework

## 実装について

### 初期化

Network Monitoringを初期化するためには次の関数を呼び出してください。アプリケーション起動直後に初期化するのをお勧めします。

`ADFmyNetworkMonitor.enableNetworkMonitoring()`

```
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        ADFmyNetworkMonitor.enableNetworkMonitoring()
        FirebaseApp.configure()
        return true
    }

```

また、アプリケーションの方でFirebaseなどNetwork Performance Monitoring機能を提供する他のツールを利用する場合には、そのツールを初期化する前にNetwork Monitoringの初期化を行なってください。

### Debug Log

Network Monitoring ModuleのDebug Logを確認する場合には、出力するDebug Log Levelを設定する必要があります。

Debug Log Levelは次のようになっています。

```
typedef NS_OPTIONS(NSInteger, ADFNMLogLevel) {
    ADFNMLogLevelNone = 0,
    ADFNMLogLevelTrace = 1 << 0,
    ADFNMLogLevelDebug = 1 << 1,
    ADFNMLogLevelInfo = 1 << 2,
    ADFNMLogLevelAllowedHost = 1 << 3,
    ADFNMLogLevelDeniedHost = 1 << 4,
    ADFNMLogLevelResult = 1 << 5,
    ADFNMLogLevelWarning = 1 << 6,
    ADFNMLogLevelError = 1 << 7,
    ADFNMLogLevelAll = 0xffff
};
```

DefaultはNoneになっていて、出力するLog LevelをBit演算で指定することで複数Levelの出力ができます。

```Swift
Swift

ADFmyNetworkMonitor.setLogLevel([.debug, .allowedHost, .deniedHost])
```

```
Objective-C

[ADFNMLogger setLogLevel:ADFNMLogLevelDebug | ADFNMLogLevelAllowedHost | ADFNMLogLevelDeniedHost];
```

出力されるLogには**[ADFNM]**というPrefixeがついて出力されます。

```
2022-05-31 16:58:30.373 [ADFNM] [INFO] [replaceMethod L:291] NSURLConnection sendAsynchronousRequest:queue:completionHandler: implementation is replaced (0x11097be61 to 0x10f039410) 
2022-05-31 16:58:30.373 [ADFNM] [INFO] [replaceMethod L:291] NSURLConnection initWithRequest:delegate: implementation is replaced (0x11097ba58 to 0x10f039763) 
2022-05-31 16:58:30.373 [ADFNM] [INFO] [replaceMethod L:291] NSURLConnection initWithRequest:delegate:startImmediately: implementation is replaced (0x11097ba32 to 0x10f0399e5) 
2022-05-31 16:58:32.804 [ADFNM] [TRACE] [replaceSessionWithConfiguration L:367] 
2022-05-31 16:58:32.804 [ADFNM] [TRACE] [replaceSessionWithConfigurationDelegate L:379] 
2022-05-31 16:58:32.886 [ADFNM] [TRACE] [replaceInitWithURLCachePolicy L:359] 
2022-05-31 16:58:32.887 [ADFNM] [TRACE] [replaceSessionWithConfigurationDelegate L:379] 
2022-05-31 16:58:32.887 [ADFNM] [TRACE] [replaceDataTaskWithRequest L:444] 
```
