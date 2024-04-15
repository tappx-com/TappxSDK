//
//  TappxInterstitialViewControllerDelegate.h
//  TappxFramework
//
//  Created by Guybrush Threepwood on 03/07/2020.
//  Copyright © 2020 Tappx. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TappxFramework/TappxErrorAd.h>
@class TappxInterstitialViewController;

@protocol TappxInterstitialViewControllerDelegate <NSObject>
@required
- (void)present:(nonnull UIViewController*)viewController;
- (nonnull UIViewController *)presentViewController;
@optional
- (void)onTappxInterstitialDismissed:(nonnull TappxInterstitialViewController *)interstitial;
- (void)tappxInterstitialViewControllerDidFinishLoad:(nonnull TappxInterstitialViewController *)viewController;
- (void)tappxInterstitialViewControllerDidPress:(nonnull TappxInterstitialViewController *)viewController;
- (void)tappxInterstitialViewControllerDidClose:(nonnull TappxInterstitialViewController *)viewController;
- (void)tappxInterstitialViewControllerDidFail:(nonnull TappxInterstitialViewController *)viewController withError:(nonnull TappxErrorAd *)error;
- (void)tappxInterstitialViewControllerDidAppear:(nonnull TappxInterstitialViewController *)viewController;
@end
