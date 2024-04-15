//
//  TappxBannerViewController.h
//  TappxFramework
//
//  Created by Guybrush Threepwood on 06/04/2021.
//  Copyright © 2021 Tappx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TappxFramework/TappxSettings.h>
#import <TappxFramework/TappxBannerViewControllerDelegate.h>

@interface TappxBannerViewController : NSObject

- (nonnull instancetype)initWithDelegate:(nonnull id<TappxBannerViewControllerDelegate>)delegate
                                 andSize:(TappxBannerSize)size
                             andPosition:(TappxBannerPosition)position;

- (nonnull instancetype)initWithDelegate:(nonnull id<TappxBannerViewControllerDelegate>)delegate
                                 andSize:(TappxBannerSize)size
                             andLocation:(CGPoint)location;

- (nonnull instancetype)initWithDelegate:(nonnull id<TappxBannerViewControllerDelegate>)delegate
                                 andSize:(TappxBannerSize)size
                                 andView:(nonnull UIView *)viewAd;

- (nonnull instancetype)initWithDelegate:(nonnull id<TappxBannerViewControllerDelegate>)delegate
                                 andSize:(TappxBannerSize)size
                                 andView:(nonnull UIView *)viewAd
                             andLocation:(CGPoint)location;

- (void)load;
- (void)load:(nonnull TappxSettings *)settings;
- (void)removeBanner;
- (void)setRefreshTimeSeconds:(NSInteger)seconds;
- (void)setEnableAutoRefresh:(BOOL)autoRefresh;
- (void)setAnimation:(TappxAnimation)animation;
- (void)setExtraTappxKey:(nonnull NSString *)tappxExtraKey;

@end
