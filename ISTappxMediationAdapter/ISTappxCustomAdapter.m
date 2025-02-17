//
//  ISTappxCustomAdapter.m
//
//  Created by Yvan DL on 13/04/23.
//

#import "ISTappxCustomAdapter.h"

@implementation ISTappxCustomAdapter

- (void)init:(ISAdData *)adData delegate:(id<ISNetworkInitializationDelegate>)delegate {
    if(adData == nil || ![adData.configuration objectForKey:@"tappxkey"]) {
        [delegate onInitDidFailWithErrorCode:508 errorMessage:@"ISTappxCustomAdapter init failed"];
        return;
    }
    
    [delegate onInitDidSucceed];
}

- (NSString *) networkSDKVersion {
   return [TappxFramework versionSDK];
}
- (NSString *) adapterVersion {
   return @"1.0.0";
}

@end
