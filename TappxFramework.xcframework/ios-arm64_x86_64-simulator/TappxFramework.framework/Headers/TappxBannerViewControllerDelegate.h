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

@protocol TappxBannerViewControllerDelegate <NSObject>
@required
- (nonnull UIViewController *)presentViewController;
@optional
- (void)tappxBannerViewControllerDidFinishLoad:(nonnull TappxBannerViewController *)vc;
- (void)tappxBannerViewControllerDidPress:(nonnull TappxBannerViewController *)vc;
- (void)tappxBannerViewControllerDidFail:(nonnull TappxBannerViewController *)vc withError:(nonnull TappxErrorAd *) error;
- (void)tappxBannerViewControllerDidClose:(nonnull TappxBannerViewController *)vc;
@end
