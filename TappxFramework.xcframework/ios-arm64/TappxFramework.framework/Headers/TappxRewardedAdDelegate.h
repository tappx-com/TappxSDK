//
//  TappxRewardedViewControllerDelegate.h
//  TappxFramework
//
//  Created by Antonio Lai on 12/12/22.
//  Copyright © 2022 Tappx. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TappxFramework/TappxErrorAd.h>
@class TappxRewardedAd;

NS_SWIFT_NAME(TappxRewardedAdDelegate)
@protocol TappxRewardedAdDelegate <NSObject>
@optional

/**
 Called when the rewarded ad finishes loading.

 @param rewardedAd The TappxRewardedAd instance that finished loading.
 */
- (void) tappxRewardedAdDidFinishLoad:(nonnull TappxRewardedAd*) rewardedAd NS_SWIFT_NAME(tappxRewardedAdDidFinishLoad(rewardedAd:));

/**
 Called when the rewarded ad fails to load.

 @param rewardedAd The TappxRewardedAd instance that failed to load.
 @param error The error that occurred while loading the ad.
 */
- (void) tappxRewardedAdDidFail:(nonnull TappxRewardedAd*) rewardedAd withError:(nonnull TappxErrorAd*) error NS_SWIFT_NAME(tappxRewardedAdDidFail(rewardedAd:error:));

/**
 Called when the rewarded ad is clicked.

 @param rewardedAd The TappxRewardedAd instance that was clicked.
 */
- (void) tappxRewardedAdClicked:(nonnull TappxRewardedAd*) rewardedAd NS_SWIFT_NAME(tappxRewardedAdClicked(rewardedAd:));

/**
 Called when playback of the rewarded ad fails.

 @param rewardedAd The TappxRewardedAd instance where playback failed.
 */
- (void) tappxRewardedAdPlaybackFailed:(nonnull TappxRewardedAd*) rewardedAd NS_SWIFT_NAME(tappxRewardedAdPlaybackFailed(rewardedAd:));

/**
 Called when the rewarded ad video is closed.

 @param rewardedAd The TappxRewardedAd instance whose video was closed.
 */
- (void) tappxRewardedAdVideoClosed:(nonnull TappxRewardedAd*) rewardedAd NS_SWIFT_NAME(tappxRewardedAdVideoClosed(rewardedAd:));

/**
 Called when the rewarded ad video completes.

 @param rewardedAd The TappxRewardedAd instance whose video was completed.
 */
- (void) tappxRewardedAdVideoCompleted:(nonnull TappxRewardedAd*) rewardedAd NS_SWIFT_NAME(tappxRewardedAdVideoCompleted(rewardedAd:));

/**
 Called when the rewarded ad appears on the screen.

 @param rewardedAd The TappxRewardedAd instance that appeared.
 */
- (void) tappxRewardedAdDidAppear:(nonnull TappxRewardedAd *)rewardedAd NS_SWIFT_NAME(tappxRewardedAdDidAppear(rewardedAd:));

/**
 Called when the rewarded ad is dismissed.

 @param rewardedAd The TappxRewardedAd instance that was dismissed.
 */
- (void) tappxRewardedAdDismissed:(nonnull TappxRewardedAd *) rewardedAd NS_SWIFT_NAME(tappxRewardedAdDismissed(rewardedAd:));

/**
 Called when the user earns a reward from watching the rewarded ad.

 @param rewardedAd The TappxRewardedAd instance where the user earned the reward.
 */
- (void) tappxRewardedAdUserDidEarnReward:(nonnull TappxRewardedAd*) rewardedAd NS_SWIFT_NAME(tappxRewardedAdUserDidEarnReward(rewardedAd:));
@end



