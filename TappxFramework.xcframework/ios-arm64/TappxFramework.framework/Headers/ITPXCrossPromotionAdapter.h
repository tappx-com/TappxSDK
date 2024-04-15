//
//  ITappxMediationAdapter.h
//  TappxFramework
//
//  Created by Antonio Lai on 07/12/23.
//  Copyright © 2023 Tappx. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TappxFramework/ITPXCrossPromotionAdapterDelegate.h>

typedef void (^ITPXCrossPromotionAdapterCompletionHandler)(NSError *_Nullable error);

@protocol ITPXCrossPromotionAdapter <NSObject>
@required
- (nonnull NSString *) adapterVersion;
- (void) initAdapterWithDelegate:(nonnull id <ITPXCrossPromotionAdapterDelegate>) delegate;
- (void) setAdRootViewController:(nonnull UIViewController *)viewController;
- (nullable UIView *) getBannerView;
- (void) initBannerView:(nonnull NSString *)adUnit bannerSize:(CGSize)bannerSize;
- (void) loadInterstitialAd:(nonnull NSString *)adUnit completionHandler:(nonnull ITPXCrossPromotionAdapterCompletionHandler)completionHandler;
- (void) loadBannerAd;
- (void) presentInterstitialAd:(nonnull UIViewController *)viewController;
@end
