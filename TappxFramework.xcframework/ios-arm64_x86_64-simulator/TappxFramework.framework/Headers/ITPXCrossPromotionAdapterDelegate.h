//
//  ITappxMediationAdapterDelegate.h
//  TappxFramework
//
//  Created by Antonio Lai on 09/12/23.
//  Copyright © 2023 Tappx. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ITPXCrossPromotionAdapterDelegate <NSObject>
@required
-(void) didFailToReceiveAdWithError:(nonnull NSError *)error;
-(void) adDidLoad;
-(void) adDidPress;
-(void) adDidClose;
@end
