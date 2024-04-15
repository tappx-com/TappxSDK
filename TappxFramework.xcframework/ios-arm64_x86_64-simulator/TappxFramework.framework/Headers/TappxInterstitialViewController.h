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

@interface TappxInterstitialViewController : NSObject

- (nonnull instancetype)initWithDelegate:(nonnull id<TappxInterstitialViewControllerDelegate>)delegate;

- (void)setAutoShowWhenReady:(BOOL)autoShow;
- (void)load;
- (void)load:(nonnull TappxSettings *)settings;
- (BOOL)isReady;
- (void)show;
- (void)setAnimation:(TappxAnimation)animation;
- (void)setExtraTappxKey:(nonnull NSString *)tappxExtraKey;

@end
