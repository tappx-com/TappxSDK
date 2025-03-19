//
//  TappxInterstitialViewControllerDelegate.h
//  TappxFramework
//
//  Created by Guybrush Threepwood on 03/07/2020.
//  Copyright © 2020 Tappx. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TappxFramework/TappxErrorAd.h>
@class TappxInterstitialAd;

NS_SWIFT_NAME(TappxInterstitialAdDelegate)
@protocol TappxInterstitialAdDelegate <NSObject>
@optional

/**
 Called when the interstitial ad is dismissed.

 @param interstitialAd The TappxInterstitialAd instance that was dismissed.
 */
- (void)tappxInterstitialAdDismissed:(nonnull TappxInterstitialAd *)interstitialAd NS_SWIFT_NAME(tappxInterstitialAdDismissed(interstitialAd:));

/**
 Called when the interstitial ad finishes loading.

 @param interstitialAd The TappxInterstitialAd instance that finished loading.
 */
- (void)tappxInterstitialAdDidFinishLoad:(nonnull TappxInterstitialAd *)interstitialAd NS_SWIFT_NAME(tappxInterstitialAdDidFinishLoad(interstitialAd:));

/**
 Called when the interstitial ad is pressed.

 @param interstitialAd The TappxInterstitialAd instance that was pressed.
 */
- (void)tappxInterstitialAdDidPress:(nonnull TappxInterstitialAd *)interstitialAd NS_SWIFT_NAME(tappxInterstitialAdDidPress(interstitialAd:));

/**
 Called when the interstitial ad is closed.

 @param interstitialAd The TappxInterstitialAd instance that was closed.
 */
- (void)tappxInterstitialAdDidClose:(nonnull TappxInterstitialAd *)interstitialAd NS_SWIFT_NAME(tappxInterstitialAdDidClose(interstitialAd:));

/**
 Called when the interstitial ad fails to load.

 @param interstitialAd The TappxInterstitialAd instance that failed to load.
 @param error The error that occurred during loading.
 */
- (void)tappxInterstitialAdDidFail:(nonnull TappxInterstitialAd *)interstitialAd withError:(nonnull TappxErrorAd *)error NS_SWIFT_NAME(tappxInterstitialAdDidFail(interstitialAd:error:));

/**
 Called when the interstitial ad appears on the screen.

 @param interstitialAd The TappxInterstitialAd instance that appeared.
 */
- (void)tappxInterstitialAdDidAppear:(nonnull TappxInterstitialAd *)interstitialAd NS_SWIFT_NAME(tappxInterstitialAdDidAppear(interstitialAd:));
@end
