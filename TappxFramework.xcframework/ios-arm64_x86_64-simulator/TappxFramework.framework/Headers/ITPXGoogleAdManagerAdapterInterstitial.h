//
//  ITPXGoogleAdManagerAdapterInterstitial.h
//  TappxFramework
//
//  Created by Sara on 27/5/25.
//  Copyright © 2025 Tappx. All rights reserved.
//
 
#import <UIKit/UIKit.h>
#import <TappxFramework/ITPXAdapterDelegate.h>

NS_SWIFT_NAME(ITPXGoogleAdManagerAdapterInterstitial)
@protocol ITPXGoogleAdManagerAdapterInterstitial <ITPXAdapter>
@required
/**
 Loads an interstitial ad with the specified ad unit ID.

 @param adUnit The ad unit ID for the interstitial ad.
 @param completionHandler A completion handler that will be called once the ad is loaded or failed to load.
 */
-(void) loadInterstitialAd:(nonnull NSString *)adUnit additionalData:(nullable NSDictionary*)additionalData completionHandler:(nonnull ITPXAdapterCompletionHandler)completionHandler NS_SWIFT_NAME(loadInterstitialAd(adUnit:additionalData:completionHandler:));

/**
 Presents the loaded interstitial ad from the specified view controller.

 @param viewController The view controller from which the interstitial ad will be presented.
 */
-(void) presentInterstitialAd:(nonnull UIViewController *)viewController NS_SWIFT_NAME(presentInterstitialAd(viewController:));

@end
