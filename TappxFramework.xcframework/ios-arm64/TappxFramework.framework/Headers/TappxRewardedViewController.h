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

@interface TappxRewardedViewController : NSObject
- (nonnull instancetype)initWithDelegate:(nonnull id<TappxRewardedViewControllerDelegate>)delegate;

- (void)setAutoShowWhenReady:(BOOL)autoShow;
- (void)load;
- (void)load:(nonnull TappxSettings *)settings;
- (BOOL)isReady;
- (void)show;
- (void)setAnimation:(TappxAnimation)animation;
- (void)setExtraTappxKey:(nonnull NSString *)tappxExtraKey;
- (void)setCountDownMessage:(nonnull NSString *)beforeTime andAfterTime:(nonnull NSString *)afterTime;
- (void)setPopupMessage:(nonnull NSString *)message andAcceptButton:(nonnull NSString *)accept andCancelButton:(nonnull NSString *)cancel;
@end
