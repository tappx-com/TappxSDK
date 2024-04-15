//
//  ITappxMediationAdapterDelegate.h
//  TappxFramework
//
//  Created by Antonio Lai on 09/12/23.
//  Copyright © 2023 Tappx. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_SWIFT_NAME(ITPXCrossPromotionAdapterDelegate)
@protocol ITPXCrossPromotionAdapterDelegate <NSObject>
@required
-(void) didFailToReceiveAdWithError:(nonnull NSError *)error NS_SWIFT_NAME(didFailToReceivedAd(error:));
-(void) adDidLoad;
-(void) adDidPress;
-(void) adDidClose;
@end
