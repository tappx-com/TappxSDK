//
//  ALTappxMediationAdapter.m
//  TappxDemo
//
//  Created by Antonio Lai on 18/09/23.
//  Copyright © 2023 Tappx. All rights reserved.
//

#import "ALTappxMediationAdapter.h"
#import <TappxFramework/TappxAds.h>

#define ADAPTER_VERSION @"4.0.10.0"

/**
 * Interstitial Delegate
 */
@interface AppLovinTappxRewardedDelegate : NSObject<TappxRewardedAdDelegate>
@property (nonatomic,   weak) ALTappxMediationAdapter *parentAdapter;
@property (nonatomic, strong) id<MARewardedAdapterDelegate> delegate;
- (instancetype)initWithParentAdapter:(ALTappxMediationAdapter *)parentAdapter andNotify:(id<MARewardedAdapterDelegate>)delegate;
@end

/**
 * Interstitial Delegate
 */
@interface AppLovinTappxInterstitialDelegate : NSObject<TappxInterstitialAdDelegate>
@property (nonatomic,   weak) ALTappxMediationAdapter *parentAdapter;
@property (nonatomic, strong) id<MAInterstitialAdapterDelegate> delegate;
- (instancetype)initWithParentAdapter:(ALTappxMediationAdapter *)parentAdapter andNotify:(id<MAInterstitialAdapterDelegate>)delegate;
@end

/**
 * AdView Delegate
 */
@interface AppLovinTappxAdViewDelegate : NSObject<TappxBannerViewDelegate>
@property (nonatomic,   weak) ALTappxMediationAdapter *parentAdapter;
@property (nonatomic, strong) id<MAAdViewAdapterDelegate> delegate;
- (instancetype)initWithParentAdapter:(ALTappxMediationAdapter *)parentAdapter andNotify:(id<MAAdViewAdapterDelegate>)delegate;
@end

@interface ALTappxMediationAdapter()

// Interstitial Properties
@property (nonatomic, strong) TappxInterstitialAd *interstitialAd;
@property (nonatomic, strong) AppLovinTappxInterstitialDelegate *interstitialAdDelegate;

// Rewarded Properties
@property (nonatomic, strong) TappxRewardedAd *rewardedAd;
@property (nonatomic, strong) AppLovinTappxRewardedDelegate *rewardedAdDelegate;

// AdView Properties
@property (nonatomic, strong) TappxBannerView *adView;
@property (nonatomic, strong) AppLovinTappxAdViewDelegate *adViewAdDelegate;

@end

@implementation ALTappxMediationAdapter

#pragma mark - MAAdapter Methods

- (void)initializeWithParameters:(id<MAAdapterInitializationParameters>)parameters completionHandler:(void (^)(MAAdapterInitializationStatus, NSString * _Nullable))completionHandler
{
    [self log: @"Initializing Tappx adapter... "];
    
    NSString *appKey = [parameters.serverParameters al_stringForKey: @"app_id"];
    NSDictionary *customParameters = parameters.customParameters;

    if ( [parameters isTesting] || [customParameters al_boolForKey: @"is_testing"] || [customParameters al_boolForKey: @"test" ] ) {
        [TappxFramework addTappxKey: appKey testMode: YES];
    } else {
        [TappxFramework addTappxKey: appKey fromNonNative: @"applovin"];
    }
    
    NSString *endpoint = [parameters.serverParameters al_stringForKey: @"endpoint"];
    if ( [endpoint al_isValidString] ) {
        [TappxFramework setEndpoint: endpoint];
    }
    
    completionHandler(MAAdapterInitializationStatusDoesNotApply, nil);
}

- (NSString *)SDKVersion
{
    return [TappxFramework versionSDK];
}

- (NSString *)adapterVersion
{
    return ADAPTER_VERSION;
}

- (void)destroy
{
    [self log: @"Destroy called for adapter %@", self];
    
    self.interstitialAd = nil;
    self.interstitialAdDelegate = nil;
    
    [self.adView removeBanner];
    self.adView = nil;
    self.adViewAdDelegate = nil;
}

- (void)initializeWithParameters:(nonnull id<MAAdapterInitializationParameters>)parameters withCompletionHandler:(nonnull void (^)(void))completionHandler { 
    [self log: @"Initializing Tappx adapter... "];
    
    NSString *appKey = [parameters.serverParameters al_stringForKey: @"app_id"];
    NSDictionary *customParameters = parameters.customParameters;

    if ( [parameters isTesting] || [customParameters al_boolForKey: @"is_testing"] || [customParameters al_boolForKey: @"test" ] )
    {
        [TappxFramework addTappxKey: appKey testMode: YES];
    }
    else
    {
        [TappxFramework addTappxKey: appKey fromNonNative:@"applovin"];
    }
    
    NSString *endpoint = [parameters.serverParameters al_stringForKey: @"endpoint"];
    if ( [endpoint al_isValidString] )
    {
        [TappxFramework setEndpoint: endpoint];
    }
    
    completionHandler();
}


#pragma mark - MAInterstitial Methods

- (void)loadInterstitialAdForParameters:(id<MAAdapterResponseParameters>)parameters andNotify:(id<MAInterstitialAdapterDelegate>)delegate
{
    [self log: @"Loading interstitial ad..."];
    
    self.interstitialAdDelegate = [[AppLovinTappxInterstitialDelegate alloc] initWithParentAdapter:self andNotify:delegate];
    self.interstitialAd = [[TappxInterstitialAd alloc] initWithDelegate: self.interstitialAdDelegate];
    
    [self.interstitialAd setAutoShowWhenReady:NO];
    [self.interstitialAd load];
}

- (void)showInterstitialAdForParameters:(id<MAAdapterResponseParameters>)parameters andNotify:(id<MAInterstitialAdapterDelegate>)delegate
{
    [self log: @"Showing interstitial ad..."];
    
    if ( [self.interstitialAd isReady] )
    {
        UIViewController* viewController;
        if (ALSdk.versionCode >= 11020199)
        {
            viewController = parameters.presentingViewController;
        }
        
        [self.interstitialAd showFrom:viewController ?: [ALUtils topViewControllerFromKeyWindow]];
    }
    else
    {
        [self log: @"Interstitial ad not ready"];
        [delegate didFailToDisplayInterstitialAdWithError: MAAdapterError.adNotReady];
    }
}

#pragma mark - MAAdViewAdapter Methods

- (void)loadAdViewAdForParameters:(id<MAAdapterResponseParameters>)parameters adFormat:(MAAdFormat *)adFormat andNotify:(id<MAAdViewAdapterDelegate>)delegate
{
    [self log: @"Loading %@ ad view ad...", adFormat.label];
    
    self.adViewAdDelegate = [[AppLovinTappxAdViewDelegate alloc] initWithParentAdapter:self andNotify: delegate];
    
    self.adView = [[TappxBannerView alloc] initWithDelegate : self.adViewAdDelegate
                                                    andSize : [self sizeFromAdFormat: adFormat]];
    
    UIViewController* viewController;
    if ( ALSdk.versionCode >= 11020199 ) {
        viewController = parameters.presentingViewController;
    }
    
    [self.adView setRootViewController:viewController ?: [ALUtils topViewControllerFromKeyWindow]];
    [self.adView load];
}

#pragma mark - MARewarded Methods

- (void)loadRewardedAdForParameters:(nonnull id<MAAdapterResponseParameters>)parameters andNotify:(nonnull id<MARewardedAdapterDelegate>)delegate {
    [self log: @"Loading rewarded ad..."];
    
    self.rewardedAdDelegate = [[AppLovinTappxRewardedDelegate alloc] initWithParentAdapter: self andNotify: delegate];
    self.rewardedAd = [[TappxRewardedAd alloc] initWithDelegate:self.rewardedAdDelegate];
    
    [self.rewardedAd setAutoShowWhenReady:NO];
    [self.rewardedAd load];
}

- (void)showRewardedAdForParameters:(nonnull id<MAAdapterResponseParameters>)parameters andNotify:(nonnull id<MARewardedAdapterDelegate>)delegate {
    [self log: @"Showing rewarded ad..."];
    
    if ( [self.rewardedAd isReady] )
    {
        UIViewController* viewController;
        if ( ALSdk.versionCode >= 11020199 )
        {
            viewController = parameters.presentingViewController;
        }
        
        [self.rewardedAd showFrom:viewController ?: [ALUtils topViewControllerFromKeyWindow]];
    }
    else
    {
        [self log: @"Rewarded ad not ready"];
        [delegate didFailToDisplayRewardedAdWithError: MAAdapterError.adNotReady];
    }
}

#pragma mark - Helper Methods

+ (MAAdapterError *)toMaxError:(TappxErrorAd *)tappxAdError
{
    TappxErrorCode tappxErrorCode = tappxAdError.code;
    MAAdapterError *adapterError = MAAdapterError.unspecified;
    switch ( tappxErrorCode )
    {
        case VIEW_INCONSISTENCY_ERROR: NS_FALLTHROUGH;
        case DEVELOPER_ERROR:
            adapterError = MAAdapterError.invalidConfiguration;
            break;
        case NO_CONNECTION:
            adapterError = MAAdapterError.noConnection;
            break;
        case NO_FILL:
            adapterError = MAAdapterError.noFill;
            break;
        case CANCELLED:
            adapterError = MAAdapterError.internalError;
            break;
        case SERVER_ERROR:
            adapterError = MAAdapterError.serverError;
            break;
    }
    
    return [
        MAAdapterError errorWithAdapterError:adapterError mediatedNetworkErrorCode:tappxErrorCode mediatedNetworkErrorMessage:tappxAdError.description
    ];
}

- (TappxBannerSize)sizeFromAdFormat:(MAAdFormat *)adFormat
{
    if ( adFormat == MAAdFormat.banner )
    {
        return TappxBannerSize320x50;
    }
    else if ( adFormat == MAAdFormat.leader )
    {
        return TappxBannerSize728x90;
    }
    else if ( adFormat ==  MAAdFormat.mrec )
    {
        return TappxBannerSize300x250;
    }
    else
    {
        [NSException raise: NSInvalidArgumentException format: @"Invalid ad format: %@", adFormat];
        return TappxBannerSize320x50;
    }
}

@end

#pragma mark - Interstitial Delegate

@implementation AppLovinTappxInterstitialDelegate

- (instancetype)initWithParentAdapter:(ALTappxMediationAdapter *)parentAdapter andNotify:(id<MAInterstitialAdapterDelegate>)delegate {
    if (self = [super init]) {
        self.parentAdapter = parentAdapter;
        self.delegate = delegate;
    }
    return self;
}

- (void)tappxInterstitialAdDidFinishLoad:(TappxInterstitialAd *)interstitialAd
{
    [self.parentAdapter log: @"Interstitial ad loaded"];
    [self.delegate didLoadInterstitialAd];
}

- (void)tappxInterstitialAdDidFail:(TappxInterstitialAd *)interstitialAd withError:(TappxErrorAd *)error
{
    MAAdapterError *adapterError = [ALTappxMediationAdapter toMaxError: error];
    
    [self.parentAdapter log: @"Interstitial ad failed to load with error: %@", adapterError];
    [self.delegate didFailToLoadInterstitialAdWithError: adapterError];
}

- (void)tappxInterstitialAdDidAppear:(TappxInterstitialAd *)interstitialAd
{
    [self.parentAdapter log: @"Interstitial ad shown"];
    [self.delegate didDisplayInterstitialAd];
}

- (void)tappxInterstitialAdDidPress:(TappxInterstitialAd *)interstitialAd
{
    [self.parentAdapter log: @"Interstitial ad clicked"];
    [self.delegate didClickInterstitialAd];
}

- (void)tappxInterstitialAdDidClose:(TappxInterstitialAd *)interstitialAd
{
    [self.parentAdapter log: @"Interstitial ad hidden"];
    [self.delegate didHideInterstitialAd];
}

@end

@implementation AppLovinTappxAdViewDelegate

- (instancetype)initWithParentAdapter:(ALTappxMediationAdapter *)parentAdapter andNotify:(id<MAAdViewAdapterDelegate>)delegate
{
    self = [super init];
    if ( self )
    {
        self.parentAdapter = parentAdapter;
        self.delegate = delegate;
    }
    return self;
}

#pragma mark - TappxAdViewDelegate Methods

- (void)tappxBannerViewDidFinishLoad:(TappxBannerView *)viewController
{
    [self.parentAdapter log: @"AdView ad loaded"];
    [self.delegate didLoadAdForAdView: self.parentAdapter.adView];
    [self.delegate didDisplayAdViewAd];
}

- (void)tappxBannerViewDidFail:(TappxBannerView *)viewController withError:(TappxErrorAd *)error
{
    MAAdapterError *adapterError = [ALTappxMediationAdapter toMaxError: error];
    
    [self.parentAdapter log: @"AdView ad failed to load with error: %@", adapterError];
    [self.delegate didFailToLoadAdViewAdWithError: adapterError];
}

- (void)tappxBannerViewDidPress:(TappxBannerView *)viewController
{
    [self.parentAdapter log: @"AdView ad clicked"];
    [self.delegate didClickAdViewAd];
}

- (void)tappxBannerViewDidClose:(TappxBannerView *)viewController
{
    [self.parentAdapter log: @"AdView ad closed"];
}

@end

@implementation AppLovinTappxRewardedDelegate

- (instancetype)initWithParentAdapter:(ALTappxMediationAdapter *)parentAdapter andNotify:(id<MARewardedAdapterDelegate>)delegate {
    self = [super init];
    if ( self )
    {
        self.parentAdapter = parentAdapter;
        self.delegate = delegate;
    }
    return self;
}

- (void) tappxRewardedAdDidFinishLoad:(nonnull TappxRewardedAd*) rewardedAd {
    [self.parentAdapter log: @"Rewarded ad loaded"];
    [self.delegate didLoadRewardedAd];
}

- (void) tappxRewardedAdDidFail:(nonnull TappxRewardedAd*) rewardedAd withError:(nonnull TappxErrorAd*) error {
    MAAdapterError *adapterError = [ALTappxMediationAdapter toMaxError: error];
    
    [self.parentAdapter log: @"Rewarded ad failed to load with error: %@", adapterError];
    [self.delegate didFailToLoadRewardedAdWithError: adapterError];
}

- (void) tappxRewardedAdClicked:(nonnull TappxRewardedAd*) rewardedAd {
    [self.parentAdapter log: @"Rewarded ad clicked"];
    [self.delegate didClickRewardedAd];
}

- (void) tappxRewardedAdPlaybackFailed:(nonnull TappxRewardedAd*) rewardedAd {
    [self.parentAdapter log: @"Rewarded ad Playback failed"];
    [self.delegate didFailToDisplayRewardedAdWithError:[MAAdapterError errorWithCode:[MAAdapterError errorCodeRewardError]]];
}

- (void) tappxRewardedAdVideoClosed:(nonnull TappxRewardedAd*) rewardedAd {
    [self.parentAdapter log: @"Rewarded ad closed"];
}

- (void) tappxRewardedAdVideoCompleted:(nonnull TappxRewardedAd*) rewardedAd {
    [self.parentAdapter log: @"Rewarded ad video completed"];
}

- (void) tappxRewardedAdDidAppear:(nonnull TappxRewardedAd *) rewardedAd {
    [self.parentAdapter log: @"Rewarded ad appear"];
    [self.delegate didDisplayRewardedAd];
}

- (void) tappxRewardedAdDismissed:(nonnull TappxRewardedAd *) rewardedAd {
    [self.parentAdapter log: @"Rewarded ad dismissed"];
    [self.delegate didHideRewardedAd];
}

- (void) tappxRewardedAdUserDidEarnReward:(nonnull TappxRewardedAd*) rewardedAd {
    [self.parentAdapter log: @"Rewarded ad rewardUser"];
    [self.delegate didRewardUserWithReward:[self.parentAdapter reward]];
}

@end
