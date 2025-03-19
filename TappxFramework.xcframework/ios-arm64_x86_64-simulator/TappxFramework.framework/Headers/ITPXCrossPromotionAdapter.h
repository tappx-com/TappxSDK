//
//  ITappxMediationAdapter.h
//  TappxFramework
//
//  Created by Antonio Lai on 07/12/23.
//  Copyright © 2023 Tappx. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TappxFramework/ITPXCrossPromotionAdapterDelegate.h>

typedef void (^ITPXCrossPromotionAdapterCompletionHandler)(NSError *_Nullable error) NS_SWIFT_NAME(ITPXCrossPromotionAdapterCompletionHandler);

NS_SWIFT_NAME(ITPXCrossPromotionAdapter)
@protocol ITPXCrossPromotionAdapter <NSObject>
@required

/**
 Returns the version of the cross-promotion adapter.

 @return A string representing the version of the adapter.
 */
- (nonnull NSString *) adapterVersion NS_SWIFT_NAME(adapterVersion());

/**
 Initializes the cross-promotion adapter with the given delegate.

 @param delegate The delegate to handle events related to cross-promotion ads.
 */
- (void) initAdapterWithDelegate:(nonnull id <ITPXCrossPromotionAdapterDelegate>) delegate NS_SWIFT_NAME(init(delegate:));

/**
 Sets the root view controller for displaying ads.

 @param viewController The view controller used to present ads.
 */
- (void) setAdRootViewController:(nonnull UIViewController *)viewController NS_SWIFT_NAME(setAdRootViewController(viewController:));

/**
 Retrieves the banner view for displaying a cross-promotion banner ad.

 @return A `UIView` representing the banner ad, or `nil` if it is not available.
 */
- (nullable UIView *) getBannerView NS_SWIFT_NAME(getBannerView());

/**
 Initializes the banner view with the specified ad unit ID and size.

 @param adUnit The ad unit ID for the banner ad.
 @param bannerSize The size of the banner ad.
 */
- (void) initBannerView:(nonnull NSString *)adUnit bannerSize:(CGSize)bannerSize NS_SWIFT_NAME(initBannerView(adUnit:size:));

/**
 Loads an interstitial ad with the specified ad unit ID.

 @param adUnit The ad unit ID for the interstitial ad.
 @param completionHandler A completion handler that will be called once the ad is loaded or failed to load.
 */
- (void) loadInterstitialAd:(nonnull NSString *)adUnit completionHandler:(nonnull ITPXCrossPromotionAdapterCompletionHandler)completionHandler NS_SWIFT_NAME(loadInterstitialAd(adUnit:completionHandler:));

/**
 Loads a banner ad.

 This method loads a banner ad with default settings.
 */
- (void) loadBannerAd NS_SWIFT_NAME(loadBannerAd());

/**
 Presents the loaded interstitial ad from the specified view controller.

 @param viewController The view controller from which the interstitial ad will be presented.
 */
- (void) presentInterstitialAd:(nonnull UIViewController *)viewController NS_SWIFT_NAME(presentInterstitialAd(viewController:));
@end
