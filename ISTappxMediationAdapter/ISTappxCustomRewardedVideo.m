//
//  ISTappxCustomRewardedVideo.m
//
//  Created by Yvan DL on 13/04/23.


#import "ISTappxCustomRewardedVideo.h"

@interface ISTappxCustomRewardedVideo ()

@property (strong, nonatomic) TappxRewardedViewController* rewardedVideoAd;
@property (strong, nonatomic) id<ISRewardedVideoAdDelegate> adDelegate;

@property (strong, nonatomic) void (^completionHandler)(ISAdData* ad, ISAdapterErrors error);

@end

@implementation ISTappxCustomRewardedVideo

static UIViewController* rootVC;

+ (UIViewController *) _getRootVC {
    return rootVC;
}

+ (void) _setRootVC:(UIViewController *) vc {
    rootVC = vc;
}

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
        self->_rewardedVideoAd = [[TappxRewardedViewController alloc] initWithDelegate:self];
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
    [ISTappxCustomRewardedVideo _setRootVC:viewController];
    
    if([_rewardedVideoAd isReady]) {
        dispatch_async(dispatch_get_main_queue(), ^{
            [_rewardedVideoAd show];
        });
        _adDelegate = delegate;
        return;
    }
    
    [self descriptionError:IS_NO_FILL andDescription:@"RewardedAd not ready"];
}

- (void)present:(nonnull UIViewController *)viewController {
    [[ISTappxCustomRewardedVideo _getRootVC] presentViewController:viewController animated:false completion:nil];
}

- (nonnull UIViewController *)presentViewController {
    return [ISTappxCustomRewardedVideo _getRootVC];
}

- (void)tappxRewardedViewControllerDidFinishLoad:(nonnull TappxRewardedViewController *)viewController {
    [_adDelegate adDidLoad];
}

- (void)tappxRewardedViewControllerDidFail:(nonnull TappxRewardedViewController *)viewController withError:(nonnull TappxErrorAd *)error {
    [_adDelegate adDidFailToShowWithErrorCode:error.code errorMessage:error.localizedDescription];
}

- (void) tappxRewardedViewControllerClicked:(nonnull TappxRewardedViewController*) viewController {
    [_adDelegate adDidClick];
}

- (void) tappxRewardedViewControllerPlaybackFailed:(nonnull TappxRewardedViewController*) viewController {
    [_adDelegate adDidFailToShowWithErrorCode:IS_NO_FILL errorMessage:@"RewardedAd playback failed"];
}

- (void) tappxRewardedViewControllerVideoClosed:(nonnull TappxRewardedViewController*) viewController {
    [_adDelegate adDidClose];
}

- (void) tappxRewardedViewControllerVideoCompleted:(nonnull TappxRewardedViewController*) viewController { }

- (void)tappxRewardedViewControllerDidAppear:(nonnull TappxRewardedViewController *)viewController {
    [_adDelegate adDidOpen];
}

- (void)onTappxRewardedViewControllerDismissed:(nonnull TappxRewardedViewController *)RewardedVideo {
    [_adDelegate adDidEnd];
}

- (void) tappxRewardedViewControllerUserDidEarnReward:(nonnull TappxRewardedViewController*) viewController {
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
