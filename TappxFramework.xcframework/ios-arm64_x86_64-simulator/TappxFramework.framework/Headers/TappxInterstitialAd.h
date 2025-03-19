//
//  TappxInterstitialViewController.h
//  TappxFramework
//
//  Created by Guybrush Threepwood on 07/04/2021.
//  Copyright © 2021 Tappx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TappxFramework/TappxSettings.h>
#import <TappxFramework/TappxInterstitialAdDelegate.h>

NS_SWIFT_NAME(TappxInterstitialAd)
@interface TappxInterstitialAd : NSObject

/**
 Initializes a TappxInterstitialAd instance with a delegate.

 @param delegate The delegate to handle interstitial ad events.
 @return An initialized TappxInterstitialAd instance.
 */
- (nonnull instancetype)initWithDelegate:(nonnull id<TappxInterstitialAdDelegate>)delegate NS_SWIFT_NAME(init(delegate:));

/**
 Sets whether the interstitial ad should automatically show when it is ready.

 @param autoShow A boolean indicating whether the ad should auto-show when ready.
 */
- (void)setAutoShowWhenReady:(BOOL)autoShow NS_SWIFT_NAME(setAutoShowWhenReady(enable:));

/**
 Loads the interstitial ad with default settings.
 */
- (void)load;

/**
 Loads the interstitial ad with custom settings.

 @param settings The settings to customize the ad load.
 */
- (void)load:(nonnull TappxSettings *)settings NS_SWIFT_NAME(load(settings:));

/**
 Checks if the interstitial ad is ready to be shown.

 @return A boolean indicating whether the ad is ready to be shown.
 */
- (BOOL)isReady;

/**
 Shows the interstitial ad from the specified view controller.

 @param viewController The view controller from which the ad will be presented.
 */
- (void)showFrom:(nullable UIViewController*) viewController NS_SWIFT_NAME(show(from:));

/**
 Sets the animation style for the interstitial ad.

 @param animation The animation style to be applied to the ad.
 */
- (void)setAnimation:(TappxAnimation)animation NS_SWIFT_NAME(setAnimation(animation:));

/**
 Sets an additional key for Tappx integration.

 @param tappxExtraKey The additional key for Tappx.
 */
- (void)setExtraTappxKey:(nonnull NSString *)tappxExtraKey NS_SWIFT_NAME(setExtraKey(tappxKey:));

@end
