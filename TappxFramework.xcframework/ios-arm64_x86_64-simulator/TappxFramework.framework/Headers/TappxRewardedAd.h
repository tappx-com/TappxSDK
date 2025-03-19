//
//  TappxRewardedViewController.h
//  TappxFramework
//
//  Created by Antonio Lai on 12/12/22.
//  Copyright © 2022 Tappx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TappxFramework/TappxSettings.h>
#import <TappxFramework/TappxRewardedAdDelegate.h>

NS_SWIFT_NAME(TappxRewardedAd)
@interface TappxRewardedAd : NSObject

/**
 Initializes a TappxRewardedAd instance with a delegate.

 @param delegate The delegate to handle rewarded ad events.
 @return An initialized TappxRewardedAd instance.
 */
- (nonnull instancetype)initWithDelegate:(nonnull id<TappxRewardedAdDelegate>)delegate NS_SWIFT_NAME(init(delegate:));

/**
 Sets whether the rewarded ad should automatically show when it is ready.
 
 @param autoShow A boolean indicating whether the ad should auto-show when ready.
 */
- (void)setAutoShowWhenReady:(BOOL)autoShow NS_SWIFT_NAME(setAutoShowWhenReady(enable:));

/**
 Loads the rewarded ad with default settings.
 */
- (void)load;

/**
 Loads the rewarded ad with custom settings.

 @param settings The settings to customize the ad load.
 */
- (void)load:(nonnull TappxSettings *)settings NS_SWIFT_NAME(load(settings:));

/**
 Checks if the rewarded ad is ready to be shown.

 @return A boolean indicating whether the ad is ready to be shown.
 */
- (BOOL)isReady;

/**
 Shows the rewarded ad from the specified view controller.

 @param viewController The view controller from which the ad will be presented.
 */
- (void)showFrom:(nullable UIViewController*) viewController NS_SWIFT_NAME(show(from:));

/**
 Sets the animation style for the rewarded ad.

 @param animation The animation style to be applied to the ad.
 */
- (void)setAnimation:(TappxAnimation)animation NS_SWIFT_NAME(setAnimation(animation:));

/**
 Sets an additional key for Tappx integration.

 @param tappxExtraKey The additional key for Tappx.
 */
- (void)setExtraTappxKey:(nonnull NSString *)tappxExtraKey NS_SWIFT_NAME(setExtraKey(tappxKey:));

/**
 Sets the countdown message before and after the ad starts.

 @param beforeTime The message to be shown before the countdown starts.
 @param afterTime The message to be shown after the countdown ends.
 */
- (void)setCountDownMessage:(nonnull NSString *)beforeTime andAfterTime:(nonnull NSString *)afterTime NS_SWIFT_NAME(setMessage(beforeCountDown:afterCountDown:));

/**
 Sets the popup message with accept and cancel buttons.

 @param message The popup message.
 @param accept The text for the accept button.
 @param cancel The text for the cancel button.
 */
- (void)setPopupMessage:(nonnull NSString *)message andAcceptButton:(nonnull NSString *)accept andCancelButton:(nonnull NSString *)cancel NS_SWIFT_NAME(setPopup(message:accept:cancel:));
@end
