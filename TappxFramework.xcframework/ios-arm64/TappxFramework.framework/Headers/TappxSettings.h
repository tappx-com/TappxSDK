//
//  TappxSettings.h
//  TappxFramework
//
//  Created by Guybrush Threepwood on 02/07/2020.
//  Copyright © 2020 Tappx. All rights reserved.
//

#import <Foundation/Foundation.h>

#define TappxGenderString(enum) [@[@"male", @"female", @"Other"] objectAtIndex:enum]
NS_SWIFT_NAME(TappxGender)
typedef NS_ENUM(NSInteger, TappxGender) {
    TappxGenderMale = 0,
    TappxGenderFemale = 1,
    TappxGenderOther = 2,
};

#define TappxMaritalString(enum) [@[@"Single", @"Living Common", @"Married", @"Divorced", @"Widowed"] objectAtIndex:enum]
NS_SWIFT_NAME(TappxMarital)
typedef NS_ENUM(NSInteger, TappxMarital) {
    TappxMaritalSingle = 0,
    TappxMaritalLivingCommon = 1,
    TappxMaritalMarried = 2,
    TappxMaritalDivorced = 3,
    TappxMaritalWidowed = 4,
};

#define TappxBannerSizeString(enum) [@[@"Smart Banner", @"320x50", @"728x90", @"300x250", @"not specified"] objectAtIndex:enum]
NS_SWIFT_NAME(TappxBannerSize)
typedef NS_ENUM(NSInteger, TappxBannerSize) {
    TappxBannerSmartBanner = 0,
    TappxBannerSize320x50 = 1,
    TappxBannerSize728x90 = 2,
    TappxBannerSize300x250 = 3,
    TappxBannerNotSpecified = 4,
};

#define TappxBannerPositionString(enum) [@[@"TOP", @"BOTTOM", @"CUSTOM"] objectAtIndex:enum]
NS_SWIFT_NAME(TappxBannerPosition)
typedef NS_ENUM(NSInteger, TappxBannerPosition) {
    TappxBannerPositionTop = 0,
    TappxBannerPositionBottom = 1,
    TappxBannerPositionCustom = 2,
};

#define TappxAnimation(enum) [@[@"NONE", @"RANDOM", @"LEFT_To_RIGHT", @"LEFT_To_RIGHT_BOUNCE", @"RIGHT_To_LEFT", @"RIGHT_To_LEFT_BOUNCE"] objectAtIndex:enum]
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

- (NSInteger)getYearOfBirth;
- (NSInteger)getAge;
- (TappxGender)getGender;
- (TappxMarital)getMarital;
- (nullable NSString *)getMediation;
- (nullable NSArray <NSString*> *)getKeywords;

- (void)setYearOfBirth:(NSInteger)year NS_SWIFT_NAME(setYearOfBirth(year:));
- (void)setAge:(NSInteger)age NS_SWIFT_NAME(setAge(age:));
- (void)setGender:(TappxGender)gender NS_SWIFT_NAME(setGender(gender:));
- (void)setMarital:(TappxMarital)marital NS_SWIFT_NAME(setMarital(marital:));
- (void)setMediation:(nullable NSString *)mediation NS_SWIFT_NAME(setMediation(mediation:));
- (void)setKeywords:(nullable NSArray <NSString*> *)keywords NS_SWIFT_NAME(setKeywords(keywords:));

@end
