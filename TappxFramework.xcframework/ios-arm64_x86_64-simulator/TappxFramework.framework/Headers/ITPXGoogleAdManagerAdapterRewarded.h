//
//  ITPXGoogleAdManagerAdapterRewarded.h
//  TappxFramework
//
//  Created by Sara on 27/5/25.
//  Copyright © 2025 Tappx. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TappxFramework/ITPXAdapterDelegate.h>

NS_SWIFT_NAME(ITPXGoogleAdManagerAdapterRewarded)
@protocol ITPXGoogleAdManagerAdapterRewarded <ITPXAdapter>
@required
/**
 Loads an interstitial ad with the specified ad unit ID.

 @param adUnit The ad unit ID for the interstitial ad.
 @param completionHandler A completion handler that will be called once the ad is loaded or failed to load.
 */
-(void) loadRewardedAd:(nonnull NSString *)adUnit additionalData:(nullable NSDictionary*)additionalData completionHandler:(nonnull ITPXAdapterCompletionHandler)completionHandler NS_SWIFT_NAME(loadRewardedAd(adUnit:additionalData:completionHandler:));

/**
 Presents the loaded interstitial ad from the specified view controller.

 @param viewController The view controller from which the interstitial ad will be presented.
 */
-(void) presentRewardedAd:(nonnull UIViewController *)viewController userDidEarnRewardHandler:(nonnull void(^)(void))handler  NS_SWIFT_NAME(presentRewardedAd(viewController:userDidEarnRewardHandler:));

@end
