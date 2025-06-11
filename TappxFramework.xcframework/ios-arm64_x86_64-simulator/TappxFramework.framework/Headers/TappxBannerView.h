//
//  TappxBannerViewController.h
//  TappxFramework
//
//  Created by Guybrush Threepwood on 06/04/2021.
//  Copyright © 2021 Tappx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TappxFramework/TappxSettings.h>
#import <TappxFramework/TappxBannerViewDelegate.h>

NS_SWIFT_NAME(TappxBannerView)
@interface TappxBannerView : UIView

/**
 Initializes the banner view with a specified size.
 
 @param size The size of the banner.
 @return An initialized TappxBannerView instance.
 */
- (nonnull instancetype)initWithSize:(TappxBannerSize)size NS_SWIFT_NAME(init(size:));

/**
 Initializes the banner view with a delegate, size, and a specific location.
 
 @param delegate The delegate to handle banner events.
 @param size The size of the banner.
 @param location The location of the banner.
 @return An initialized TappxBannerView instance.
 */
- (nonnull instancetype)initWithDelegate:(nonnull id<TappxBannerViewDelegate>)delegate
                                 andSize:(TappxBannerSize)size
                             andLocation:(CGPoint)location NS_SWIFT_NAME(init(delegate:size:location:));

/**
 Initializes the banner view with a delegate and size.
 
 @param delegate The delegate to handle banner events.
 @param size The size of the banner.
 @return An initialized TappxBannerView instance.
 */
- (nonnull instancetype)initWithDelegate:(nonnull id<TappxBannerViewDelegate>)delegate
                                 andSize:(TappxBannerSize)size NS_SWIFT_NAME(init(delegate:size:));

/**
 Loads the banner with default settings.
 */
- (void)load;

/**
 Loads the banner with custom settings.
 
 @param settings Custom settings for the banner.
 */
- (void)load:(nonnull TappxSettings *)settings NS_SWIFT_NAME(load(settings:));

/**
 Removes the banner from the view.
 */
- (void)removeBanner;

/**
 Sets the time interval (in seconds) to refresh the banner.
 
 @param seconds The time interval in seconds for refreshing the banner.
 */
- (void)setRefreshTimeSeconds:(NSInteger)seconds NS_SWIFT_NAME(setRefreshTime(seconds:));

/**
 Enables or disables automatic banner refresh.
 
 @param autoRefresh A boolean indicating whether auto-refresh is enabled.
 */
- (void)setEnableAutoRefresh:(BOOL)autoRefresh NS_SWIFT_NAME(setAutoRefresh(enable:));


/**
 Sets the animation style for the banner.
 
 @param animation The animation style to be applied to the banner.
 */
- (void)setAnimation:(TappxAnimation)animation NS_SWIFT_NAME(setAnimation(animation:));

/**
 Sets an additional key for Tappx integration.
 
 @param tappxExtraKey The additional key for Tappx.
 */
- (void)setExtraTappxKey:(nonnull NSString *)tappxExtraKey NS_SWIFT_NAME(setExtraKey(tappxKey:));

/**
 Sets the root view controller for presenting any banner-related content.
 
 @param rootViewController The root view controller to be set.
 */
- (void)setRootViewController:(nonnull UIViewController*) rootViewController NS_SWIFT_NAME(setRootViewController(rootViewController:));

/**
 Sets the delegate for handling banner events.
 
 @param delegate The delegate to handle banner events.
 */
- (void) setDelegate:(nonnull id<TappxBannerViewDelegate>) delegate NS_SWIFT_NAME(setDelegate(delegate:));

@end
