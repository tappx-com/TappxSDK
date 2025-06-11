//
//  ITPXAdMobAdapterDelegate.h
//  TappxFramework
//
//  Created by Antonio Lai on 09/12/23.
//  Copyright © 2023 Tappx. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_SWIFT_NAME(ITPXAdapterDelegate)
@protocol ITPXAdapterDelegate <NSObject>
@required

/**
 Called when an error occurs while receiving an ad.

 @param error The error that occurred while attempting to load the ad.
 */
-(void) didFailToReceiveAdWithError:(nonnull NSError *)error NS_SWIFT_NAME(didFailToReceivedAd(error:));

/**
 Called when the ad finishes loading successfully.
 */
-(void) adDidLoad NS_SWIFT_NAME(adDidLoad());

/**
 Called when the ad is pressed.
 */
-(void) adDidPress NS_SWIFT_NAME(adDidPress());

/**
 Called when the ad is closed.
 */
-(void) adDidClose NS_SWIFT_NAME(adDidClose());
@end
