//
//  ITappxMediationAdapter.h
//  TappxFramework
//
//  Created by Antonio Lai on 07/12/23.
//  Copyright © 2023 Tappx. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TappxFramework/ITPXCrossPromotionAdapterDelegate.h>

typedef void (^ITPXCrossPromotionAdapterCompletionHandler)(NSError *_Nullable error) NS_SWIFT_NAME(ITPXCrossPromotionAdapterCompletionHandler);

NS_SWIFT_NAME(ITPXCrossPromotionAdapter)
@protocol ITPXCrossPromotionAdapter <NSObject>
@required
- (nonnull NSString *) adapterVersion;
- (void) initAdapterWithDelegate:(nonnull id <ITPXCrossPromotionAdapterDelegate>) delegate NS_SWIFT_NAME(init(delegate:));
- (void) setAdRootViewController:(nonnull UIViewController *)viewController NS_SWIFT_NAME(setAdRootViewController(viewController:));
- (nullable UIView *) getBannerView;
- (void) initBannerView:(nonnull NSString *)adUnit bannerSize:(CGSize)bannerSize NS_SWIFT_NAME(initBannerView(adUnit:size:));
- (void) loadInterstitialAd:(nonnull NSString *)adUnit completionHandler:(nonnull ITPXCrossPromotionAdapterCompletionHandler)completionHandler NS_SWIFT_NAME(loadInterstitialAd(adUnit:completionHandler:));
- (void) loadBannerAd;
- (void) presentInterstitialAd:(nonnull UIViewController *)viewController NS_SWIFT_NAME(presentInterstitialAd(viewController:));
@end
