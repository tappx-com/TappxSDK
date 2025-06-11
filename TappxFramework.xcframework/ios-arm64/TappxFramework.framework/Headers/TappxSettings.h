//
//  TappxSettings.h
//  TappxFramework
//
//  Created by Guybrush Threepwood on 02/07/2020.
//  Copyright © 2020 Tappx. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Converts a TappxGender enum to its corresponding string representation.
 */
#define TappxGenderString(enum) [@[@"male", @"female", @"Other"] objectAtIndex:enum]

/**
 Enum representing gender options.
 */
NS_SWIFT_NAME(TappxGender)
typedef NS_ENUM(NSInteger, TappxGender) {
    TappxGenderMale = 0,
    TappxGenderFemale = 1,
    TappxGenderOther = 2,
};

/**
 Converts a TappxMarital enum to its corresponding string representation.
 */
#define TappxMaritalString(enum) [@[@"Single", @"Living Common", @"Married", @"Divorced", @"Widowed"] objectAtIndex:enum]

/**
 Enum representing marital status options.
 */
NS_SWIFT_NAME(TappxMarital)
typedef NS_ENUM(NSInteger, TappxMarital) {
    TappxMaritalSingle = 0,
    TappxMaritalLivingCommon = 1,
    TappxMaritalMarried = 2,
    TappxMaritalDivorced = 3,
    TappxMaritalWidowed = 4,
};

/**
 Converts a TappxBannerSize enum to its corresponding string representation.
 */
#define TappxBannerSizeString(enum) [@[@"Smart Banner", @"320x50", @"728x90", @"300x250", @"not specified"] objectAtIndex:enum]

/**
 Enum representing various banner ad sizes.
 */
NS_SWIFT_NAME(TappxBannerSize)
typedef NS_ENUM(NSInteger, TappxBannerSize) {
    TappxBannerSmartBanner = 0,
    TappxBannerSize320x50 = 1,
    TappxBannerSize728x90 = 2,
    TappxBannerSize300x250 = 3,
    TappxBannerNotSpecified = 4,
};

/**
 Converts a TappxAnimation enum to its corresponding string representation.
 */
#define TappxAnimation(enum) [@[@"NONE", @"RANDOM", @"LEFT_To_RIGHT", @"LEFT_To_RIGHT_BOUNCE", @"RIGHT_To_LEFT", @"RIGHT_To_LEFT_BOUNCE"] objectAtIndex:enum]

/**
 Enum representing various ad animation styles.
 */
NS_SWIFT_NAME(TappxAnimation)
typedef NS_ENUM(NSInteger, TappxAnimation) {
    TappxAnimationNone = 0,
    TappxAnimationRandom = 1,
    TappxAnimationLeftToRight = 2,
    TappxAnimationLeftToRightBounce = 3,
    TappxAnimationRightToLeft = 4,
    TappxAnimationRightToLeftBounce = 5
};

NS_SWIFT_NAME(TappxSettings)
@interface TappxSettings : NSObject

/// Retrieves the user's year of birth.
/// - Returns: The year of birth as an integer.
- (NSInteger)getYearOfBirth NS_SWIFT_NAME(getYearOfBirth());

/// Retrieves the user's age.
/// - Returns: The age as an integer.
- (NSInteger)getAge NS_SWIFT_NAME(getAge());

/// Retrieves the user's gender.
/// - Returns: A `TappxGender` value representing the user's gender.
- (TappxGender)getGender NS_SWIFT_NAME(getGender());

/// Retrieves the user's marital status.
/// - Returns: A `TappxMarital` value representing the user's marital status.
- (TappxMarital)getMarital NS_SWIFT_NAME(getMarital());

/// Retrieves the mediation platform being used.
/// - Returns: A string representing the mediation platform, or `nil` if not set.
- (nullable NSString *)getMediation NS_SWIFT_NAME(getMediation());

/// Retrieves the list of keywords associated with the user.
/// - Returns: An array of strings representing keywords, or `nil` if not set.
- (nullable NSArray <NSString*> *)getKeywords NS_SWIFT_NAME(getKeywords());

/// Sets the user's year of birth.
/// - Parameter year: The year of birth as an integer.
- (void)setYearOfBirth:(NSInteger)year NS_SWIFT_NAME(setYearOfBirth(year:));

/// Sets the user's age.
/// - Parameter age: The age as an integer.
- (void)setAge:(NSInteger)age NS_SWIFT_NAME(setAge(age:));

/// Sets the user's gender.
/// - Parameter gender: A `TappxGender` value representing the user's gender.
- (void)setGender:(TappxGender)gender NS_SWIFT_NAME(setGender(gender:));

/// Sets the user's marital status.
/// - Parameter marital: A `TappxMarital` value representing the user's marital status.
- (void)setMarital:(TappxMarital)marital NS_SWIFT_NAME(setMarital(marital:));

/// Sets the mediation platform.
/// - Parameter mediation: A string representing the mediation platform, or `nil` to unset.
- (void)setMediation:(nullable NSString *)mediation NS_SWIFT_NAME(setMediation(mediation:));

/// Sets the list of keywords associated with the user.
/// - Parameter keywords: An array of strings representing keywords, or `nil` to unset.
- (void)setKeywords:(nullable NSArray <NSString*> *)keywords NS_SWIFT_NAME(setKeywords(keywords:));

@end
