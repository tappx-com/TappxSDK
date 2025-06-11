//
//  ITPXGoogleAdManagerAdapterBanner.h
//  TappxFramework
//
//  Created by Sara on 27/5/25.
//  Copyright © 2025 Tappx. All rights reserved.
//
 
#import <UIKit/UIKit.h>
#import <TappxFramework/ITPXAdapterDelegate.h>

NS_SWIFT_NAME(ITPXGoogleAdManagerAdapterBanner)
@protocol ITPXGoogleAdManagerAdapterBanner <ITPXAdapter>
@required

/**
 Sets the root view controller for displaying ads.

 @param viewController The view controller used to present ads.
 */
-(void) setAdRootViewController:(nonnull UIViewController *)viewController NS_SWIFT_NAME(setAdRootViewController(viewController:));

/**
 Retrieves the banner view for displaying a cross-promotion banner ad.

 @return A `UIView` representing the banner ad, or `nil` if it is not available.
 */
-(nullable UIView *) getBannerView NS_SWIFT_NAME(getBannerView());

/**
 Initializes the banner view with the specified ad unit ID and size.

 @param adUnit The ad unit ID for the banner ad.
 @param bannerSize The size of the banner ad.
 */
-(void) initBannerView:(nonnull NSString *)adUnit bannerSize:(CGSize)bannerSize NS_SWIFT_NAME(initBannerView(adUnit:size:));

/**
 Loads a banner ad.

 This method loads a banner ad with default settings.
 */
-(void) loadBannerAdWithAdditionalData:(nullable NSDictionary*)additionalData NS_SWIFT_NAME(loadBannerAd(additionalData:));

/**
 Destroy the banner view.

 This method loads a banner ad with default settings.
 */
-(void) destroyAd NS_SWIFT_NAME(destroyAd());

@end
