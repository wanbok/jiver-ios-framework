Pod::Spec.new do |s|
  s.name         = "JiverSDK"
  s.version      = "1.1.34"
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

  s.public_header_files = 'JiverSDK.framework/Headers/JiverSDK.h', 'JiverSDK.framework/Headers/Jiver.h', 'JiverSDK.framework/Headers/JiverAPIClient.h', 'JiverSDK.framework/Headers/JiverBroadcastMessage.h', 'JiverSDK.framework/Headers/JiverChannel.h', 'JiverSDK.framework/Headers/JiverChannelListQuery.h', 'JiverSDK.framework/Headers/JiverClient.h', 'JiverSDK.framework/Headers/JiverCommand.h', 'JiverSDK.framework/Headers/JiverError.h', 'JiverSDK.framework/Headers/JiverFileInfo.h', 'JiverSDK.framework/Headers/JiverFileLink.h', 'JiverSDK.framework/Headers/JiverMember.h', 'JiverSDK.framework/Headers/JiverMemberInMessagingChannel.h', 'JiverSDK.framework/Headers/JiverMemberListQuery.h', 'JiverSDK.framework/Headers/JiverMention.h', 'JiverSDK.framework/Headers/JiverMessage.h', 'JiverSDK.framework/Headers/JiverMessageListQuery.h', 'JiverSDK.framework/Headers/JiverMessageModel.h', 'JiverSDK.framework/Headers/JiverMessagingChannel.h', 'JiverSDK.framework/Headers/JiverMessagingChannelListQuery.h', 'JiverSDK.framework/Headers/JiverMessagingUnreadCountQuery.h', 'JiverSDK.framework/Headers/JiverReadStatus.h', 'JiverSDK.framework/Headers/JiverSender.h', 'JiverSDK.framework/Headers/JiverSystemMessage.h', 'JiverSDK.framework/Headers/JiverTypeStatus.h', 'JiverSDK.framework/Headers/JiverUser.h', 'JiverSDK.framework/Headers/JiverWSClient.h', 'JiverSDK.framework/Headers/JiverUser.h', 'JiverSDK.framework/Headers/SRWebSocket.h'
end
