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

+ (void)addTappxKey:(nonnull NSString *)tappxKey;
+ (void)addTappxKey:(nonnull NSString *)tappxKey fromNonNative:(nonnull NSString *)platform;
+ (void)addTappxKey:(nonnull NSString *)tappxKey testMode:(BOOL)test;

+ (void)setEndpoint:(nonnull NSString *)endpoint;

+ (void)acceptPersonalInfoContent:(BOOL)accept;
+ (void)setGDPRConsent:(nonnull NSString *)consent;
+ (void)setUsPrivacy:(nonnull NSString *)consent;
+ (void)setGlobalPrivacyPlatform:(nonnull NSString *)consent;
+ (void)setCoppaCompliance:(BOOL)coppa;

+ (nonnull NSString *)versionSDK;
+(UIInterfaceOrientationMask)getUIInterfaceOrientationMaskFrom:(nullable NSNotification *)notification;
@end
