//
//  TappxErrorAd.h
//  TappxFramework
//
//  Created by Guybrush Threepwood on 02/07/2020.
//  Copyright © 2020 Tappx. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_SWIFT_NAME(TappxErrorCode)
typedef NS_ENUM(NSInteger, TappxErrorCode) {
    NO_FILL,
    SERVER_ERROR,
    DEVELOPER_ERROR,
    VIEW_INCONSISTENCY_ERROR,
    CANCELLED,
    NO_CONNECTION
};

NS_SWIFT_NAME(TappxErrorAd)
@interface TappxErrorAd : NSError

+ (nonnull instancetype)tappxErrorAdWithCode:(TappxErrorCode)errorCode NS_SWIFT_NAME(init(errorCode:));
+ (nonnull instancetype)tappxErrorAdWithCode:(TappxErrorCode)errorCode andContextualDescription:(nullable NSString*)description NS_SWIFT_NAME(init(errorCode:description:));
+ (nonnull instancetype)tappxErrorAdWithCode:(TappxErrorCode)errorCode error:(nullable NSError *)error NS_SWIFT_NAME(init(errorCode:error:));

@property (nonatomic, assign, readonly) TappxErrorCode errorCode;

- (nonnull NSString *)descriptionError;

@end
