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

DEPRECATED_MSG_ATTRIBUTE("TappxBannerViewController to be removed in future releases, you can use new TappxBannerView")
NS_SWIFT_NAME(TappxBannerViewController)
@interface TappxBannerViewController : NSObject

- (nonnull instancetype)initWithDelegate:(nonnull id<TappxBannerViewControllerDelegate>)delegate
                                 andSize:(TappxBannerSize)size
                             andPosition:(TappxBannerPosition)position NS_SWIFT_NAME(init(delegate:size:position:));

- (nonnull instancetype)initWithDelegate:(nonnull id<TappxBannerViewControllerDelegate>)delegate
                                 andSize:(TappxBannerSize)size
                             andLocation:(CGPoint)location NS_SWIFT_NAME(init(delegate:size:location:));

- (nonnull instancetype)initWithDelegate:(nonnull id<TappxBannerViewControllerDelegate>)delegate
                                 andSize:(TappxBannerSize)size
                                 andView:(nonnull UIView *)viewAd NS_SWIFT_NAME(init(delegate:size:adView:));

- (nonnull instancetype)initWithDelegate:(nonnull id<TappxBannerViewControllerDelegate>)delegate
                                 andSize:(TappxBannerSize)size
                                 andView:(nonnull UIView *)viewAd
                             andLocation:(CGPoint)location NS_SWIFT_NAME(init(delegate:size:adView:location:));

- (void)load;
- (void)load:(nonnull TappxSettings *)settings NS_SWIFT_NAME(load(settings:));
- (void)removeBanner;
- (void)setRefreshTimeSeconds:(NSInteger)seconds NS_SWIFT_NAME(setRefreshTime(seconds:));
- (void)setEnableAutoRefresh:(BOOL)autoRefresh NS_SWIFT_NAME(setAutoRefresh(enable:));
- (void)setAnimation:(TappxAnimation)animation NS_SWIFT_NAME(setAnimation(animation:));
- (void)setExtraTappxKey:(nonnull NSString *)tappxExtraKey NS_SWIFT_NAME(setExtraKey(tappxKey:));

@end
