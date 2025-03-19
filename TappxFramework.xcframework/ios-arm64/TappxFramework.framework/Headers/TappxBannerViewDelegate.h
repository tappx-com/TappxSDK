//
//  TappxBannerViewControllerDelegate.h
//  TappxFramework
//
//  Created by Guybrush Threepwood on 02/07/2020.
//  Copyright © 2020 Tappx. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TappxFramework/TappxErrorAd.h>
@class TappxBannerView;

NS_SWIFT_NAME(TappxBannerViewDelegate)
@protocol TappxBannerViewDelegate <NSObject>
@optional

/**
 Called when the banner finishes loading.

 @param bannerView The TappxBannerView that finished loading.
 */
- (void)tappxBannerViewDidFinishLoad:(nonnull TappxBannerView *)bannerView NS_SWIFT_NAME(tappxBannerViewDidFinishLoad(bannerView:));

/**
 Called when the banner is pressed.

 @param bannerView The TappxBannerView that was pressed.
 */
- (void)tappxBannerViewDidPress:(nonnull TappxBannerView *)bannerView NS_SWIFT_NAME(tappxBannerViewDidPress(bannerView:));

/**
 Called when the banner fails to load.

 @param bannerView The TappxBannerView that failed to load.
 @param error The error that occurred during loading.
 */
- (void)tappxBannerViewDidFail:(nonnull TappxBannerView *)bannerView withError:(nonnull TappxErrorAd *) error NS_SWIFT_NAME(tappxBannerViewDidFail(bannerView:error:));

/**
 Called when the banner is closed.

 @param bannerView The TappxBannerView that was closed.
 */
- (void)tappxBannerViewDidClose:(nonnull TappxBannerView *)bannerView NS_SWIFT_NAME(tappxBannerViewDidClose(bannerView:));
@end
