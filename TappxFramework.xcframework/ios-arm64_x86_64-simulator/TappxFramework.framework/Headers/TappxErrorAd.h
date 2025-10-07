//
//  TappxErrorAd.h
//  TappxFramework
//
//  Created by Guybrush Threepwood on 02/07/2020.
//  Copyright © 2020 Tappx. All rights reserved.
//

#import <Foundation/Foundation.h>

/// Error codes for Tappx.
///
/// This enumeration defines possible error codes that may be returned by Tappx.
NS_SWIFT_NAME(TappxErrorCode)
typedef NS_ENUM(NSInteger, TappxErrorCode) {
    
    /// No ad fill available.
    NO_FILL,
    
    /// A server-side error occurred.
    SERVER_ERROR,
    
    /// A developer-side implementation error occurred.
    DEVELOPER_ERROR,
    
    /// An inconsistency was detected in the ad view.
    VIEW_INCONSISTENCY_ERROR,
    
    /// The ad request was cancelled.
    CANCELLED,
    
    /// No internet connection was detected.
    NO_CONNECTION,
    
    /// Bidding Ad error on string response
    BIDDING_AD_ERROR,
    
};

NS_SWIFT_NAME(TappxErrorAd)
@interface TappxErrorAd : NSError

/// Creates a `TappxErrorAd` instance with a specific error code.
/// - Parameter errorCode: The error code associated with the failure.
/// - Returns: An instance of `TappxErrorAd`.
+ (nonnull instancetype)tappxErrorAdWithCode:(TappxErrorCode)errorCode NS_SWIFT_NAME(init(errorCode:));

/// Creates a `TappxErrorAd` instance with a specific error code and description.
/// - Parameters:
///   - errorCode: The error code associated with the failure.
///   - description: An optional description providing more context about the error.
/// - Returns: An instance of `TappxErrorAd`.
+ (nonnull instancetype)tappxErrorAdWithCode:(TappxErrorCode)errorCode andContextualDescription:(nullable NSString*)description NS_SWIFT_NAME(init(errorCode:description:));

/// Creates a `TappxErrorAd` instance with a specific error code and an underlying error.
/// - Parameters:
///   - errorCode: The error code associated with the failure.
///   - error: An optional underlying `NSError` object.
/// - Returns: An instance of `TappxErrorAd`.
+ (nonnull instancetype)tappxErrorAdWithCode:(TappxErrorCode)errorCode error:(nullable NSError *)error NS_SWIFT_NAME(init(errorCode:error:));

/// The error code associated with this error.
/// - Returns: A `TappxErrorCode` value.
@property (nonatomic, assign, readonly) TappxErrorCode errorCode NS_SWIFT_NAME(errorCode);

/// Provides a human-readable description of the error.
/// - Returns: A string describing the error.
- (nonnull NSString *)descriptionError NS_SWIFT_NAME(descriptionError());

@end
