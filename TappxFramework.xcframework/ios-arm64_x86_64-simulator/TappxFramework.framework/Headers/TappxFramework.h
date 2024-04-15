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
#import <TappxFramework/TappxBannerViewController.h>
#import <TappxFramework/TappxBannerViewControllerDelegate.h>
#import <TappxFramework/TappxInterstitialViewController.h>
#import <TappxFramework/TappxInterstitialViewControllerDelegate.h>
#import <TappxFramework/TappxRewardedViewController.h>
#import <TappxFramework/TappxRewardedViewControllerDelegate.h>
#import <TappxFramework/TappxSettings.h>
#import <TappxFramework/TappxErrorAd.h>
#import <TappxFramework/TappxVASTURL.h>

extern NSString * const _Nonnull TappxNotificationUIInterfaceOrientationMaskLock;

@interface TappxFramework : NSObject

+ (void)addTappxKey:(nonnull NSString *)tappxKey NS_SWIFT_NAME(add(tappxKey:));
+ (void)addTappxKey:(nonnull NSString *)tappxKey fromNonNative:(nonnull NSString *)platform NS_SWIFT_NAME(add(tappxKey:fromNative:));
+ (void)addTappxKey:(nonnull NSString *)tappxKey testMode:(BOOL)test NS_SWIFT_NAME(add(tappxKey:testMode:));

+ (void)setEndpoint:(nonnull NSString *)endpoint NS_SWIFT_NAME(set(endpoint:));

+ (void)acceptPersonalInfoContent:(BOOL)accept NS_SWIFT_NAME(acceptPersonalInfoContent(accept:));
+ (void)setGDPRConsent:(nonnull NSString *)consent NS_SWIFT_NAME(setGDPRConsent(consent:));
+ (void)setUsPrivacy:(nonnull NSString *)consent NS_SWIFT_NAME(setUsPrivacy(privacy:));
+ (void)setGlobalPrivacyPlatform:(nonnull NSString *)consent NS_SWIFT_NAME(setGlobalPrivacyPlatform(privacy:));
+ (void)setCoppaCompliance:(BOOL)coppa NS_SWIFT_NAME(setCoppaCompliance(compliance:));

+ (nonnull NSString *)versionSDK;
+ (UIInterfaceOrientationMask)getUIInterfaceOrientationMaskFrom:(nullable NSNotification *)notification NS_SWIFT_NAME(getUIOrientationMask(from:));
@end
