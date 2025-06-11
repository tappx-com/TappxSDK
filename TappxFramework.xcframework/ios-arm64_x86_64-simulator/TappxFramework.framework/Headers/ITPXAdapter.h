//
//  ITPXAdMobAdapter.h
//  TappxFramework
//
//  Created by Antonio Lai on 07/12/23.
//  Copyright © 2023 Tappx. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TappxFramework/ITPXAdapterDelegate.h>
 
typedef void (^ITPXAdapterCompletionHandler)(NSError *_Nullable error) NS_SWIFT_NAME(ITPXAdapterCompletionHandler);

NS_SWIFT_NAME(ITPXAdapter)
@protocol ITPXAdapter <NSObject>
@required

/**
 Returns the version of the cross-promotion adapter.

 @return A string representing the version of the adapter.
 */
- (nonnull NSString *) adapterVersion NS_SWIFT_NAME(adapterVersion());

/**
 Initializes the cross-promotion adapter with the given delegate.

 @param delegate The delegate to handle events related to cross-promotion ads.
 */
- (void) initAdapterWithDelegate:(nonnull id <ITPXAdapterDelegate>) delegate NS_SWIFT_NAME(init(delegate:));
@end
