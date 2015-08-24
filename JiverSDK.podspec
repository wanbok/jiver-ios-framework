Pod::Spec.new do |s|
  s.name         = "JiverSDK"
  s.version      = "1.1.30"
  s.summary      = "JIVER iOS Framework"
  s.description  = <<-DESC
                   JIVER is the simplest solution for chat and messaging.
                   DESC
  s.homepage     = "https://jiver.io"
  s.license      = "Commercial"
  s.author       = { "Jed Gyeong" => "jed@jiver.io" }
  s.source       = { :git => "https://github.com/smilefam/jiver-ios-framework.git", :tag => "v#{s.version}" }
  s.requires_arc = true

  s.platform     = :ios, "6.0"
  s.ios.platform = :ios, "6.0"
  s.ios.vendored_frameworks = 'JiverSDK.framework'
  s.ios.frameworks = ["AdSupport", "UIKit", "QuartzCore", "CFNetwork", "Security", "Foundation", "MobileCoreServices"]
  s.ios.library   = "icucore"
end
