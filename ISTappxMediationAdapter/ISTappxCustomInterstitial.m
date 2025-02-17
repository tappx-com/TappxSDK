//
//  ISTappxCustomInterstitial.m
//
//  Created by Yvan DL on 13/4/23.
//

#import "ISTappxCustomInterstitial.h"

@interface ISTappxCustomInterstitial ()

@property (strong, nonatomic) TappxInterstitialViewController* interstitialAd;
@property (strong, nonatomic) id<ISInterstitialAdDelegate> adDelegate;

@end

@implementation ISTappxCustomInterstitial

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

- (void)loadAdWithAdData:(ISAdData *)adData delegate:(id<ISInterstitialAdDelegate>)delegate {
    
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
        [self descriptionError:IS_NO_FILL andDescription: @"Missing AdUnit"];
        return;
    }
    
    _adDelegate = delegate;
    
    dispatch_async(dispatch_get_main_queue(), ^{
        self->_interstitialAd = [[TappxInterstitialViewController alloc] initWithDelegate:self];
        [self->_interstitialAd load];
        
    });
}

- (void)dealloc {
    if(_interstitialAd != nil)
        _interstitialAd = nil;
}

- (BOOL)isAdAvailableWithAdData:(ISAdData *)adData {
    return _interstitialAd != nil;
}
- (void)showAdWithViewController:(nonnull UIViewController *)viewController
                          adData:(nonnull ISAdData *)adData
                        delegate:(nonnull id<ISInterstitialAdDelegate>)delegate {
    [ISTappxCustomInterstitial _setRootVC:viewController];
    
    if([_interstitialAd isReady]) {
        dispatch_async(dispatch_get_main_queue(), ^{
            [_interstitialAd show];
        });
        _adDelegate = delegate;
        return;
    }
    [self descriptionError:IS_NO_FILL andDescription: @"interstitial ad not ready"];
   
}
- (void)present:(nonnull UIViewController *)viewController {
    [[ISTappxCustomInterstitial _getRootVC] presentViewController:viewController animated:false completion:nil];
}

- (nonnull UIViewController*)presentViewController{
    return [ISTappxCustomInterstitial _getRootVC];
}

- (void)onTappxInterstitialDismissed:(nonnull TappxInterstitialViewController *)interstitial {
    [_adDelegate adDidEnd];
}

- (void)tappxInterstitialViewControllerDidFinishLoad:(nonnull TappxInterstitialViewController *)viewController {
    [_adDelegate adDidLoad];
}

- (void)tappxInterstitialViewControllerDidPress:(nonnull TappxInterstitialViewController *)viewController {
    [_adDelegate adDidClick];
}

- (void)tappxInterstitialViewControllerDidClose:(nonnull TappxInterstitialViewController *)viewController {
    [_adDelegate adDidClose];
}

- (void)tappxInterstitialViewControllerDidFail:(nonnull TappxInterstitialViewController *)viewController withError:(nonnull TappxErrorAd *)error {
    [self descriptionError:error.code andDescription:error.localizedDescription];
}

- (void)tappxInterstitialViewControllerDidAppear:(nonnull TappxInterstitialViewController *)viewController {
    [_adDelegate adDidOpen];
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
