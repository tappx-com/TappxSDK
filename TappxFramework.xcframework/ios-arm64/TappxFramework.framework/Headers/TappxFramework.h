//
//  TappxFramework.h
//  TappxFramework
//
//  Created by Guybrush Threepwood on 06/07/2020.
//  Copyright © 2020 Tappx. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for TappxFramework.
FOUNDATION_EXPORT double TappxFrameworkVersionNumber;

//! Project version string for TappxFramework.
FOUNDATION_EXPORT const unsigned char TappxFrameworkVersionString[];

#import <TappxFramework/TappxAds.h>
#import <TappxFramework/TappxBannerView.h>
#import <TappxFramework/TappxBannerViewDelegate.h>
#import <TappxFramework/TappxInterstitialAd.h>
#import <TappxFramework/TappxInterstitialAdDelegate.h>
#import <TappxFramework/TappxRewardedAd.h>
#import <TappxFramework/TappxRewardedAdDelegate.h>
#import <TappxFramework/TappxSettings.h>
#import <TappxFramework/TappxErrorAd.h>
#import <TappxFramework/TappxVASTURL.h>

#import <TappxFramework/TappxBannerViewController.h>
#import <TappxFramework/TappxBannerViewControllerDelegate.h>
#import <TappxFramework/TappxInterstitialViewController.h>
#import <TappxFramework/TappxInterstitialViewControllerDelegate.h>
#import <TappxFramework/TappxRewardedViewController.h>
#import <TappxFramework/TappxRewardedViewControllerDelegate.h>

extern NSString * const _Nonnull TappxNotificationUIInterfaceOrientationMaskLock;

@interface TappxFramework : NSObject

/**
 Adds a Tappx key for use in the SDK.

 @param tappxKey The Tappx key to be added.
 */
+ (void)addTappxKey:(nonnull NSString *)tappxKey NS_SWIFT_NAME(add(tappxKey:));

/**
 Adds a Tappx key for use in the SDK with a specified platform.

 @param tappxKey The Tappx key to be added.
 @param platform The platform from which the key originates (non-native platform).
 */
+ (void)addTappxKey:(nonnull NSString *)tappxKey fromNonNative:(nonnull NSString *)platform NS_SWIFT_NAME(add(tappxKey:fromNative:)) __deprecated_msg("Use setPlatformMediation: + addTappxKey: instead.");

/**
 Adds a Tappx key with the option to enable or disable test mode.

 @param tappxKey The Tappx key to be added.
 @param test Whether to enable test mode.
 */
+ (void)addTappxKey:(nonnull NSString *)tappxKey testMode:(BOOL)test NS_SWIFT_NAME(add(tappxKey:testMode:));

/**
 Sets the platform mediation identifier for the Tappx SDK.

 Replaces the platform argument previously passed via the deprecated
 `+addTappxKey:fromNonNative:`. Both entry points route to the SAME storage
 slot — no state divergence.

 @param platform The platform identifier string.
 */
+ (void)setPlatformMediation:(nonnull NSString *)platform NS_SWIFT_NAME(setPlatformMediation(platform:));

/**
 Sets the endpoint for the Tappx SDK.

 @param endpoint The endpoint URL for the Tappx service.
 */
+ (void)setEndpoint:(nonnull NSString *)endpoint NS_SWIFT_NAME(set(endpoint:));

/**
 Accepts or rejects personal information content for the Tappx SDK.

 @param accept A boolean indicating whether to accept personal information content.
 */
+ (void)acceptPersonalInfoContent:(BOOL)accept NS_SWIFT_NAME(acceptPersonalInfoContent(accept:)) __deprecated_msg("Use setGDPRApply: instead.");

/**
 Sets the GDPR "apply" flag for the Tappx SDK.

 Replaces `+acceptPersonalInfoContent:` with a spec-aligned name.
 Both entry points route to the SAME storage slot — no state divergence.

 @param accept A boolean indicating whether GDPR applies.
 */
+ (void)setGDPRApply:(BOOL)accept NS_SWIFT_NAME(setGDPRApply(accept:));

/**
 Sets the GDPR consent status for the Tappx SDK.

 @param consent The GDPR consent string (e.g., "YES" or "NO").
 */
+ (void)setGDPRConsent:(nonnull NSString *)consent NS_SWIFT_NAME(setGDPRConsent(consent:));

/**
 Sets the US privacy consent status for the Tappx SDK.

 @param consent The US privacy consent string (e.g., "YES" or "NO").
 */
+ (void)setUsPrivacy:(nonnull NSString *)consent NS_SWIFT_NAME(setUsPrivacy(privacy:));

/**
 Sets the global privacy platform consent status for the Tappx SDK.

 @param consent The global privacy platform consent string.
 */
+ (void)setGlobalPrivacyPlatform:(nonnull NSString *)consent NS_SWIFT_NAME(setGlobalPrivacyPlatform(privacy:)) __deprecated_msg("Use setGPPString: instead.");

/**
 Sets the GPP (Global Privacy Platform) consent string for the Tappx SDK.

 Replaces `+setGlobalPrivacyPlatform:` with an IAB-GPP-aligned name.
 Both entry points route to the SAME storage slot — no state divergence.

 @param gppString The GPP consent string.
 */
+ (void)setGPPString:(nonnull NSString *)gppString NS_SWIFT_NAME(setGPPString(gppString:));

/**
 Sets COPPA (Children's Online Privacy Protection Act) compliance status for the Tappx SDK.

 @param coppa A boolean indicating whether the SDK should comply with COPPA regulations.
 */
+ (void)setCoppaCompliance:(BOOL)coppa NS_SWIFT_NAME(setCoppaCompliance(compliance:)) __deprecated_msg("Use setCoppa: instead.");

/**
 Sets COPPA (Children's Online Privacy Protection Act) compliance status for the Tappx SDK.

 Replaces `+setCoppaCompliance:` with a shorter, spec-aligned name.
 Both entry points route to the SAME storage slot — no state divergence.

 @param coppa A boolean indicating whether the SDK should comply with COPPA regulations.
 */
+ (void)setCoppa:(BOOL)coppa NS_SWIFT_NAME(setCoppa(coppa:));

/**
 Retrieves the SDK version.

 @return A string representing the current version of the SDK.
 */
+ (nonnull NSString *)versionSDK NS_SWIFT_NAME(sdkVersion());

/**
 Retrieves the UIInterfaceOrientationMask from a given notification.

 @param notification An optional notification object that may contain orientation information.
 @return The corresponding UIInterfaceOrientationMask value.
 */
+ (UIInterfaceOrientationMask)getUIInterfaceOrientationMaskFrom:(nullable NSNotification *)notification NS_SWIFT_NAME(getUIOrientationMask(from:));

/**
 Sets the IAB TCF v2.x CMP identifier for the Tappx SDK.

 Overrides the auto-detected `IABTCF_CmpSdkID` value when set.

 @param cmpID The CMP identifier string.
 */
+ (void)setGDPRCMPID:(nonnull NSString *)cmpID NS_SWIFT_NAME(setGDPRCMPID(cmpID:));

/**
 Sets the IAB TCF v2.x CMP version for the Tappx SDK.

 Overrides the auto-detected `IABTCF_CmpSdkVersion` value when set.

 @param cmpVersion The CMP version string.
 */
+ (void)setGDPRCMPVersion:(nonnull NSString *)cmpVersion NS_SWIFT_NAME(setGDPRCMPVersion(cmpVersion:));

/**
 Sets the IAB GPP specification version. Not the GPP string itself —
 see `+setGPPString:` and `+setGPPSID:`.

 Overrides the auto-detected `IABGPP_HDR_Version` value when set.

 @param gppVersion The GPP spec version string.
 */
+ (void)setGPPVersion:(nonnull NSString *)gppVersion NS_SWIFT_NAME(setGPPVersion(gppVersion:));

/**
 Sets the IAB GPP Section ID (SID) array for the Tappx SDK.

 Overrides the auto-detected `IABGPP_GppSID` value when set.

 @param gppSID The GPP SID string (format per backend contract).
 */
+ (void)setGPPSID:(nonnull NSString *)gppSID NS_SWIFT_NAME(setGPPSID(gppSID:));
@end
