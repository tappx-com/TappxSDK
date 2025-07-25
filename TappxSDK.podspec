#
#  Be sure to run `pod spec lint TappxFrameworkWithCross.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |spec|
  spec.name         = "TappxSDK"
  spec.version      = "4.2.5"
  spec.summary      = "Tappx SDK for iOS monetization."
  
  spec.description  = <<-DESC
  Tappx, an AdTech firm that offers innovative app monetization, user acquisition, and advertising solutions for mobile publishers, app developers, and advertisers; helps developers: 

  Maximize its revenue and optimize the monetization performance
  Increase its eCPMs being sure that the highest bid always wins
  Get high fill rates and the best quality ads from top brands worldwide

  Thanks to the simple and flexible Tappx SDK, publishers and app developers can integrate the Tappx network to maximize their advertising revenue with 100% brand campaigns and increase the eCPMs with a convenient self-serve monetization platform.

                   DESC

  spec.homepage     = "https://www.tappx.com"

  spec.license      = "MIT"
  spec.static_framework = true
  spec.author = { "Tappx" => "tappx@tappx.com" }
  spec.platform     = :ios, "12.0"
  spec.source       = { :git => "https://github.com/tappx-com/TappxSDK.git", :tag => "#{spec.version}" }

  spec.default_subspec = 'TappxFramework'

  spec.subspec 'OMSDK_Tappx' do |ss|
    ss.name         = "OMSDK_Tappx"
    ss.vendored_frameworks = "OMSDK_Tappx.xcframework"
    ss.platform = :ios
    ss.ios.deployment_target  = '12.0'
    ss.xcconfig = { 
      "OTHER_LDFLAGS" => "-ObjC"
    }
  end

  spec.subspec 'TappxFramework' do |ss|
    ss.name         = "TappxFramework"
    ss.vendored_frameworks = "TappxFramework.xcframework"
    ss.platform = :ios
    ss.ios.deployment_target  = '12.0'
    ss.dependency "TappxSDK/OMSDK_Tappx"
    ss.xcconfig = { 
      "OTHER_LDFLAGS" => "-ObjC"
    }
  end

  spec.subspec 'TappxAppLovinAdapter' do |ss|
    ss.name         = "TappxAppLovinAdapter"
    ss.platform = :ios
    ss.ios.deployment_target  = '12.0'
    ss.source_files = 'ALTappxMediationAdapter/*.{h,m}'
    ss.dependency "TappxSDK/TappxFramework"
    ss.dependency "AppLovinSDK", "~> 13.1.0"
    ss.xcconfig = { 
      "OTHER_LDFLAGS" => "-ObjC"
    }
  end

  spec.subspec 'TappxIronSourceAdapter' do |ss|
    ss.name         = "TappxIronSourceAdapter"
    ss.platform = :ios
    ss.ios.deployment_target  = '12.0'
    ss.source_files = 'ISTappxMediationAdapter/*.{h,m}'
    ss.dependency "TappxSDK/TappxFramework"
    ss.dependency "IronSourceSDK", "~> 8.6.1.0"
    ss.dependency "IronSourceAdQualitySDK", "~> 7.23.0"
    ss.xcconfig = { 
      "OTHER_LDFLAGS" => "-ObjC"
    }
  end

  spec.subspec 'TappxGoogleAdsAdapter' do |ss|
    ss.name         = "TappxGoogleAdsAdapter"
    ss.platform = :ios
    ss.ios.deployment_target  = '12.0'
    ss.source_files = 'TPXCrossPromotionAdapter/*.{h,m}'
    ss.dependency "TappxSDK/TappxFramework"
    ss.dependency "Google-Mobile-Ads-SDK"
    ss.xcconfig = { 
      "OTHER_LDFLAGS" => "-ObjC"
    }
  end

  spec.subspec 'TappxGoogleAdManager' do |ss|
    ss.name         = "TappxGoogleAdManager"
    ss.platform = :ios
    ss.ios.deployment_target  = '12.0'
    ss.source_files = 'GoogleAdManager/*.{h,m}'
    ss.dependency "TappxSDK/TappxFramework"
    ss.dependency "Google-Mobile-Ads-SDK"
    ss.xcconfig = { 
      "OTHER_LDFLAGS" => "-ObjC"
    }
  end

end
