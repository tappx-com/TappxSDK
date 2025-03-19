//
//  ISTappxCustomRewardedVideo.m
//
//  Created by Yvan DL on 13/04/23.


#import "ISTappxCustomRewardedVideo.h"

@interface ISTappxCustomRewardedVideo ()

@property (strong, nonatomic) TappxRewardedAd* rewardedVideoAd;
@property (strong, nonatomic) id<ISRewardedVideoAdDelegate> adDelegate;

@property (strong, nonatomic) void (^completionHandler)(ISAdData* ad, ISAdapterErrors error);

@end

@implementation ISTappxCustomRewardedVideo

typedef NS_ENUM (NSInteger) {
    IS_NO_FILL = 0,
    IS_SERVER_ERROR,
    IS_DEVELOPER_ERROR,
    IS_VIEW_INCONSISTENCY_ERROR,
    IS_CANCELLED,
    IS_NO_CONNECTION
} ISTappxError;


- (void)loadAdWithAdData:(ISAdData *)adData delegate:(id<ISRewardedVideoAdDelegate>)delegate {
    
    if (adData != nil){
        NSString *tappxKey = [adData.configuration valueForKey:@"tappxkey"];
        NSString *isTest = [adData.configuration valueForKey:@"test"];
        if (isTest != nil && [isTest isEqualToString:@"1"]){
            [TappxFramework addTappxKey:tappxKey testMode:YES];
        }
        else {
            [TappxFramework addTappxKey:tappxKey fromNonNative:@"ironsource"];
        }
    
    } else {
        [self descriptionError:IS_NO_FILL andDescription: @"missing ad unit"];
        return;
    }

    _adDelegate = delegate;
    
    dispatch_async(dispatch_get_main_queue(), ^{
        self->_rewardedVideoAd = [[TappxRewardedAd alloc] initWithDelegate:self];
        [self->_rewardedVideoAd load];
    });
}

- (void)dealloc {
    if(_rewardedVideoAd != nil)
        _rewardedVideoAd = nil;
}

- (BOOL)isAdAvailableWithAdData:(ISAdData *)adData {
    return _rewardedVideoAd != nil;
}

- (void)showAdWithViewController:(UIViewController *)viewController adData:(ISAdData *)adData delegate:(id<ISRewardedVideoAdDelegate>)delegate {
    if([_rewardedVideoAd isReady]) {
        dispatch_async(dispatch_get_main_queue(), ^{
            [self->_rewardedVideoAd showFrom:viewController];
        });
        _adDelegate = delegate;
        return;
    }
    
    [self descriptionError:IS_NO_FILL andDescription:@"RewardedAd not ready"];
}

- (void)tappxRewardedAdDidFinishLoad:(nonnull TappxRewardedAd *)rewardedAd {
    [_adDelegate adDidLoad];
}

- (void)tappxRewardedAdDidFail:(nonnull TappxRewardedAd *)rewardedAd withError:(nonnull TappxErrorAd *)error {
    [_adDelegate adDidFailToShowWithErrorCode:error.code errorMessage:error.localizedDescription];
}

- (void) tappxRewardedAdClicked:(nonnull TappxRewardedAd*) rewardedAd {
    [_adDelegate adDidClick];
}

- (void) tappxRewardedAdPlaybackFailed:(nonnull TappxRewardedAd*) rewardedAd {
    [_adDelegate adDidFailToShowWithErrorCode:IS_NO_FILL errorMessage:@"RewardedAd playback failed"];
}

- (void) tappxRewardedAdVideoClosed:(nonnull TappxRewardedAd*) rewardedAd {
    [_adDelegate adDidClose];
}

- (void) tappxRewardedAdVideoCompleted:(nonnull TappxRewardedAd*) rewardedAd { }

- (void)tappxRewardedAdDidAppear:(nonnull TappxRewardedAd *)rewardedAd {
    [_adDelegate adDidOpen];
}

- (void)onTappxRewardedAdDismissed:(nonnull TappxRewardedAd *) rewardedAd {
    [_adDelegate adDidEnd];
}

- (void) tappxRewardedAdUserDidEarnReward:(nonnull TappxRewardedAd*) rewardedAd {
    [_adDelegate adRewarded];
}

- (void)descriptionError:(NSInteger)errorCode andDescription:(nullable NSString *)description
{
    NSString *errorString = @"IS Error: ";
    NSInteger tappxErrorCode = 0;
    ISAdapterErrorType errorType;
    
    switch (errorCode) {
        case IS_NO_FILL:
            errorString = [errorString stringByAppendingString:@"IS_NO_FILL"];
            errorType = ISAdapterErrorTypeNoFill;
            tappxErrorCode = IS_NO_FILL;
            break;
            
        case IS_SERVER_ERROR:
            errorString = [errorString stringByAppendingString:@"IS_SERVER_ERROR"];
            errorType = ISAdapterErrorTypeInternal;
            tappxErrorCode = IS_SERVER_ERROR;
            break;
            
        case IS_DEVELOPER_ERROR:
            errorString = [errorString stringByAppendingString:@"IS_DEVELOPER_ERROR"];
            errorType = ISAdapterErrorTypeInternal;
            tappxErrorCode = IS_DEVELOPER_ERROR;
            break;
            
        case IS_VIEW_INCONSISTENCY_ERROR:
            errorString = [errorString stringByAppendingString:@"IS_VIEW_INCONSISTENCY_ERROR"];
            errorType = ISAdapterErrorTypeInternal;
            tappxErrorCode = IS_VIEW_INCONSISTENCY_ERROR;
            break;
            
        case IS_CANCELLED:
            errorString = [errorString stringByAppendingString:@"IS_CANCELLED"];
            errorType = ISAdapterErrorTypeInternal;
            tappxErrorCode = IS_CANCELLED;
            break;
            
        case IS_NO_CONNECTION:
            errorString = [errorString stringByAppendingString:@"NO_CONNECTION"];
            errorType = ISAdapterErrorTypeNoFill;
            tappxErrorCode = IS_NO_CONNECTION;
            break;
        
        default:
            errorString = [errorString stringByAppendingString:@"IS_SERVER_ERROR"];
            errorType = ISAdapterErrorTypeInternal;
            tappxErrorCode = IS_SERVER_ERROR;
            break;
    }
    
    if(description) {
        errorString = [[errorString stringByAppendingString:@" "] stringByAppendingString:description];
    }
    
    if (tappxErrorCode == IS_VIEW_INCONSISTENCY_ERROR){
        [_adDelegate adDidFailToShowWithErrorCode:tappxErrorCode errorMessage:errorString];
        
        return;
    }
    
    [_adDelegate adDidFailToLoadWithErrorType:errorType errorCode:tappxErrorCode errorMessage:errorString];
}


@end
