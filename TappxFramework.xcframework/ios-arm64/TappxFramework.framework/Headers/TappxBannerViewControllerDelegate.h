//
//  TappxBannerViewControllerDelegate.h
//  TappxFramework
//
//  Created by Guybrush Threepwood on 02/07/2020.
//  Copyright © 2020 Tappx. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TappxFramework/TappxErrorAd.h>
@class TappxBannerViewController;

DEPRECATED_MSG_ATTRIBUTE("TappxBannerViewControllerDelegate to be removed in future releases, you can use new TappxBannerViewDelegate")
NS_SWIFT_NAME(TappxBannerViewControllerDelegate)
@protocol TappxBannerViewControllerDelegate <NSObject>
@required
- (nonnull UIViewController *)presentViewController;
@optional
- (void)tappxBannerViewControllerDidFinishLoad:(nonnull TappxBannerViewController *)vc NS_SWIFT_NAME(tappxBannerViewControllerDidFinishLoad(viewController:));
- (void)tappxBannerViewControllerDidPress:(nonnull TappxBannerViewController *)vc NS_SWIFT_NAME(tappxBannerViewControllerDidPress(viewController:));
- (void)tappxBannerViewControllerDidFail:(nonnull TappxBannerViewController *)vc withError:(nonnull TappxErrorAd *) error NS_SWIFT_NAME(tappxBannerViewControllerDidFail(viewController:error:));
- (void)tappxBannerViewControllerDidClose:(nonnull TappxBannerViewController *)vc NS_SWIFT_NAME(tappxBannerViewControllerDidClose(viewController:));
@end
