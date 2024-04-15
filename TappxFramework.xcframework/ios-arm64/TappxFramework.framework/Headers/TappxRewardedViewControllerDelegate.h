//
//  TappxRewardedViewControllerDelegate.h
//  TappxFramework
//
//  Created by Antonio Lai on 12/12/22.
//  Copyright © 2022 Tappx. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TappxFramework/TappxErrorAd.h>
@class TappxRewardedViewController;

@protocol TappxRewardedViewControllerDelegate <NSObject>
@required
- (void)present:(nonnull UIViewController*)viewController;
- (nonnull UIViewController *)presentViewController;
@optional
- (void) tappxRewardedViewControllerDidFinishLoad:(nonnull TappxRewardedViewController*) viewController;
- (void) tappxRewardedViewControllerDidFail:(nonnull TappxRewardedViewController*) viewController withError:(nonnull TappxErrorAd*) error;
- (void) tappxRewardedViewControllerClicked:(nonnull TappxRewardedViewController*) viewController;
- (void) tappxRewardedViewControllerPlaybackFailed:(nonnull TappxRewardedViewController*) viewController;
- (void) tappxRewardedViewControllerVideoClosed:(nonnull TappxRewardedViewController*) viewController;
- (void) tappxRewardedViewControllerVideoCompleted:(nonnull TappxRewardedViewController*) viewController;
- (void) tappxRewardedViewControllerDidAppear:(nonnull TappxRewardedViewController *)viewController;
- (void) tappxRewardedViewControllerDismissed:(nonnull TappxRewardedViewController *) viewController;
- (void) tappxRewardedViewControllerUserDidEarnReward:(nonnull TappxRewardedViewController*) viewController;
@end



