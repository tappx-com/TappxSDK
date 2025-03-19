//
//  TappxInterstitialViewController.h
//  TappxFramework
//
//  Created by Guybrush Threepwood on 07/04/2021.
//  Copyright © 2021 Tappx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TappxFramework/TappxSettings.h>
#import <TappxFramework/TappxInterstitialViewControllerDelegate.h>

DEPRECATED_MSG_ATTRIBUTE("TappxInterstitialViewController to be removed in future releases, you can use new TappxInterstitialAd")
NS_SWIFT_NAME(TappxInterstitialViewController)
@interface TappxInterstitialViewController : NSObject

- (nonnull instancetype)initWithDelegate:(nonnull id<TappxInterstitialViewControllerDelegate>)delegate NS_SWIFT_NAME(init(delegate:));

- (void)setAutoShowWhenReady:(BOOL)autoShow NS_SWIFT_NAME(setAutoShowWhenReady(enable:));
- (void)load;
- (void)load:(nonnull TappxSettings *)settings NS_SWIFT_NAME(load(settings:));
- (BOOL)isReady;
- (void)show;
- (void)setAnimation:(TappxAnimation)animation NS_SWIFT_NAME(setAnimation(animation:));
- (void)setExtraTappxKey:(nonnull NSString *)tappxExtraKey NS_SWIFT_NAME(setExtraKey(tappxKey:));

@end
