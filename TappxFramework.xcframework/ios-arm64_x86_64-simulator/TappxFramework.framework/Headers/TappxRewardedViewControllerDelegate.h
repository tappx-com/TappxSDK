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

NS_SWIFT_NAME(TappxRewardedViewControllerDelegate)
@protocol TappxRewardedViewControllerDelegate <NSObject>
@required
- (void)present:(nonnull UIViewController*)viewController NS_SWIFT_NAME(present(viewController:));
- (nonnull UIViewController *)presentViewController;
@optional
- (void) tappxRewardedViewControllerDidFinishLoad:(nonnull TappxRewardedViewController*) viewController NS_SWIFT_NAME(tappxRewardedViewControllerDidFinishLoad(viewController:));
- (void) tappxRewardedViewControllerDidFail:(nonnull TappxRewardedViewController*) viewController withError:(nonnull TappxErrorAd*) error NS_SWIFT_NAME(tappxRewardedViewControllerDidFail(viewController:error:));
- (void) tappxRewardedViewControllerClicked:(nonnull TappxRewardedViewController*) viewController NS_SWIFT_NAME(tappxRewardedViewControllerClicked(viewController:));
- (void) tappxRewardedViewControllerPlaybackFailed:(nonnull TappxRewardedViewController*) viewController NS_SWIFT_NAME(tappxRewardedViewControllerPlaybackFailed(viewController:));
- (void) tappxRewardedViewControllerVideoClosed:(nonnull TappxRewardedViewController*) viewController NS_SWIFT_NAME(tappxRewardedViewControllerVideoClosed(viewController:));
- (void) tappxRewardedViewControllerVideoCompleted:(nonnull TappxRewardedViewController*) viewController NS_SWIFT_NAME(tappxRewardedViewControllerVideoCompleted(viewController:));
- (void) tappxRewardedViewControllerDidAppear:(nonnull TappxRewardedViewController *)viewController NS_SWIFT_NAME(tappxRewardedViewControllerDidAppear(viewController:));
- (void) tappxRewardedViewControllerDismissed:(nonnull TappxRewardedViewController *) viewController NS_SWIFT_NAME(tappxRewardedViewControllerDismissed(viewController:));
- (void) tappxRewardedViewControllerUserDidEarnReward:(nonnull TappxRewardedViewController*) viewController NS_SWIFT_NAME(tappxRewardedViewControllerUserDidEarnReward(viewController:));
@end



