//
//  ISTappxCustomBanner.m
//
//  Created by Rubén on 28/01/25.
//

#import "ISTappxCustomBanner.h"

@interface ISTappxCustomBanner ()

@property (strong, nonatomic) TappxBannerView* bannerAd;
@property (strong, nonatomic) id<ISBannerAdDelegate> adDelegate;

@end

@implementation ISTappxCustomBanner

typedef NS_ENUM (NSInteger) {
    IS_NO_FILL = 0,
    IS_SERVER_ERROR,
    IS_DEVELOPER_ERROR,
    IS_VIEW_INCONSISTENCY_ERROR,
    IS_CANCELLED,
    IS_NO_CONNECTION
} ISTappxError;

- (void)loadAdWithAdData:(nonnull ISAdData *)adData
     viewController:(UIViewController *)viewController
          size:(ISBannerSize *)size
        delegate:(nonnull id<ISBannerAdDelegate>)delegate{
    
    _adDelegate = delegate;
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
    
    TappxBannerSize tappxsize = TappxBannerSmartBanner;
    CGRect sizeFrame = CGRectMake(0, 0, (([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone) ? 320 : 728 ), (([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone) ? 50 : 90));
    if (size.sizeDescription == kSizeBanner){
        tappxsize = TappxBannerSize320x50;
        sizeFrame = CGRectMake(0, 0, 320, 50);
    }else if (size.sizeDescription == kSizeLarge){
        tappxsize = TappxBannerSize728x90;
        sizeFrame = CGRectMake(0, 0, 728, 90);
    }else if (size.sizeDescription == kSizeRectangle){
        tappxsize = TappxBannerSize300x250;
        sizeFrame = CGRectMake(0, 0, 300, 250);
    }
    
    self.bannerAd = [[TappxBannerView alloc] initWithDelegate:self andSize:tappxsize];
    [self.bannerAd load];

}

- (void) destroyAdWithAdData:(nonnull ISAdData *)adData {
    if(self.bannerAd != nil){
        [self.bannerAd removeBanner];
    }
}

- (void)dealloc {
    if(self.bannerAd != nil){
        [self.bannerAd removeBanner];
        self.bannerAd = nil;
    }
}

//MARK: - TAPPXBannerDelegate

- (void) tappxBannerViewDidFinishLoad:(TappxBannerView*) vc {
    [_adDelegate adDidLoadWithView:self.bannerAd];
    [_adDelegate adDidOpen];
}

- (void) tappxBannerViewDidPress:(TappxBannerView*) vc {
    [_adDelegate adDidClick];
}

- (void) tappxBannerViewDidFail:(TappxBannerView*) vc withError:(TappxErrorAd*) error {
    [self descriptionError:error.code andDescription:error.localizedDescription];
    
    if(self.bannerAd != nil){
        [self.bannerAd removeBanner];
        self.bannerAd = nil;
    }
}
- (void) tappxBannerViewDidClose:(TappxBannerView*) vc {
    [_adDelegate adDidDismissScreen];
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
            errorType = ISAdapterErrorTypeInternal;
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

