Pod::Spec.new do |s|
  s.name                = "Adfurikun-Networkmonitoring-iOS"
  s.version             = "1.0.0"
  s.summary             = "Adfurikun Network Monitoring SDK."
  s.homepage            = "https://adfurikun.jp/adfurikun/"
  s.license             = { :type => 'Copyright', :text => 'Copyright Glossom Inc. All rights reserved.' }
  s.author              = "Glossom Inc."
  s.platform            = :ios, "11.0"
  s.source              = { :git => "https://github.com/glossom-dev/Adfurikun-Networkmonitoring-iOS.git", :tag => "#{s.version}" }
  s.vendored_frameworks = '**/ADFNetworkMonitor.xcframework'
  s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => ['-ObjC', '-fobjc-arc'] }
end