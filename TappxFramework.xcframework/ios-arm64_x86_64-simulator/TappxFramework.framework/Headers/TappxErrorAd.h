//
//  TappxErrorAd.h
//  TappxFramework
//
//  Created by Guybrush Threepwood on 02/07/2020.
//  Copyright © 2020 Tappx. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, TappxErrorCode) {
    NO_FILL,
    SERVER_ERROR,
    DEVELOPER_ERROR,
    VIEW_INCONSISTENCY_ERROR,
    CANCELLED,
    NO_CONNECTION
};

@interface TappxErrorAd : NSError

+ (nonnull instancetype)tappxErrorAdWithCode:(TappxErrorCode)errorCode;
+ (nonnull instancetype)tappxErrorAdWithCode:(TappxErrorCode)errorCode andContextualDescription:(nullable NSString*)description;
+ (nonnull instancetype)tappxErrorAdWithCode:(TappxErrorCode)errorCode error:(nullable NSError *)error;

@property (nonatomic, assign, readonly) TappxErrorCode errorCode;

- (nonnull NSString *)descriptionError;

@end
