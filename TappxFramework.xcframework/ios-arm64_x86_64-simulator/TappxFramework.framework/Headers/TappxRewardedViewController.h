//
//  TappxRewardedViewController.h
//  TappxFramework
//
//  Created by Antonio Lai on 12/12/22.
//  Copyright © 2022 Tappx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TappxFramework/TappxSettings.h>
#import <TappxFramework/TappxRewardedViewControllerDelegate.h>

NS_SWIFT_NAME(TappxRewardedViewController)
@interface TappxRewardedViewController : NSObject
- (nonnull instancetype)initWithDelegate:(nonnull id<TappxRewardedViewControllerDelegate>)delegate NS_SWIFT_NAME(init(delegate:));

- (void)setAutoShowWhenReady:(BOOL)autoShow NS_SWIFT_NAME(setAutoShowWhenReady(enable:));
- (void)load;
- (void)load:(nonnull TappxSettings *)settings NS_SWIFT_NAME(load(settings:));
- (BOOL)isReady;
- (void)show;
- (void)setAnimation:(TappxAnimation)animation NS_SWIFT_NAME(setAnimation(animation:));
- (void)setExtraTappxKey:(nonnull NSString *)tappxExtraKey NS_SWIFT_NAME(setExtraKey(tappxKey:));
- (void)setCountDownMessage:(nonnull NSString *)beforeTime andAfterTime:(nonnull NSString *)afterTime NS_SWIFT_NAME(setMessage(beforeCountDown:afterCountDown:));
- (void)setPopupMessage:(nonnull NSString *)message andAcceptButton:(nonnull NSString *)accept andCancelButton:(nonnull NSString *)cancel NS_SWIFT_NAME(setPopup(message:accept:cancel:));
@end
