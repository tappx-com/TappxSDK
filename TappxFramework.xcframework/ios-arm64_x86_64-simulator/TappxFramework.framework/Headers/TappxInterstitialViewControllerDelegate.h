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

NS_SWIFT_NAME(TappxInterstitialViewControllerDelegate)
@protocol TappxInterstitialViewControllerDelegate <NSObject>
@required
- (void)present:(nonnull UIViewController*)viewController NS_SWIFT_NAME(present(viewController:));
- (nonnull UIViewController *)presentViewController;
@optional
- (void)onTappxInterstitialDismissed:(nonnull TappxInterstitialViewController *)interstitial NS_SWIFT_NAME(onTappxInterstitialDismissed(viewController:));
- (void)tappxInterstitialViewControllerDidFinishLoad:(nonnull TappxInterstitialViewController *)viewController NS_SWIFT_NAME(tappxInterstitialViewControllerDidFinishLoad(viewController:));
- (void)tappxInterstitialViewControllerDidPress:(nonnull TappxInterstitialViewController *)viewController NS_SWIFT_NAME(tappxInterstitialViewControllerDidPress(viewController:));
- (void)tappxInterstitialViewControllerDidClose:(nonnull TappxInterstitialViewController *)viewController NS_SWIFT_NAME(tappxInterstitialViewControllerDidClose(viewController:));
- (void)tappxInterstitialViewControllerDidFail:(nonnull TappxInterstitialViewController *)viewController withError:(nonnull TappxErrorAd *)error NS_SWIFT_NAME(tappxInterstitialViewControllerDidFail(viewController:error:));
- (void)tappxInterstitialViewControllerDidAppear:(nonnull TappxInterstitialViewController *)viewController NS_SWIFT_NAME(tappxInterstitialViewControllerDidAppear(viewController:));
@end
