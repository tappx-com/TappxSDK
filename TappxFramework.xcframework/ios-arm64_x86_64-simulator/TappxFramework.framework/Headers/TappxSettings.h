//
//  TappxSettings.h
//  TappxFramework
//
//  Created by Guybrush Threepwood on 02/07/2020.
//  Copyright © 2020 Tappx. All rights reserved.
//

#import <Foundation/Foundation.h>

#define TappxGenderString(enum) [@[@"male", @"female", @"Other"] objectAtIndex:enum]
typedef NS_ENUM(NSInteger, TappxGender) {
    TappxGenderMale = 0,
    TappxGenderFemale = 1,
    TappxGenderOther = 2,
};

#define TappxMaritalString(enum) [@[@"Single", @"Living Common", @"Married", @"Divorced", @"Widowed"] objectAtIndex:enum]
typedef NS_ENUM(NSInteger, TappxMarital) {
    TappxMaritalSingle = 0,
    TappxMaritalLivingCommon = 1,
    TappxMaritalMarried = 2,
    TappxMaritalDivorced = 3,
    TappxMaritalWidowed = 4,
};

#define TappxBannerSizeString(enum) [@[@"Smart Banner", @"320x50", @"728x90", @"300x250", @"not specified"] objectAtIndex:enum]
typedef NS_ENUM(NSInteger, TappxBannerSize) {
    TappxBannerSmartBanner = 0,
    TappxBannerSize320x50 = 1,
    TappxBannerSize728x90 = 2,
    TappxBannerSize300x250 = 3,
    TappxBannerNotSpecified = 4,
};

#define TappxBannerPositionString(enum) [@[@"TOP", @"BOTTOM", @"CUSTOM"] objectAtIndex:enum]
typedef NS_ENUM(NSInteger, TappxBannerPosition) {
    TappxBannerPositionTop = 0,
    TappxBannerPositionBottom = 1,
    TappxBannerPositionCustom = 2,
};

#define TappxAnimation(enum) [@[@"NONE", @"RANDOM", @"LEFT_To_RIGHT", @"LEFT_To_RIGHT_BOUNCE", @"RIGHT_To_LEFT", @"RIGHT_To_LEFT_BOUNCE"] objectAtIndex:enum]
typedef NS_ENUM(NSInteger, TappxAnimation) {
    TappxAnimationNone = 0,
    TappxAnimationRandom = 1,
    TappxAnimationLeftToRight = 2,
    TappxAnimationLeftToRightBounce = 3,
    TappxAnimationRightToLeft = 4,
    TappxAnimationRightToLeftBounce = 5
};

@interface TappxSettings : NSObject

- (NSInteger)getYearOfBirth;
- (NSInteger)getAge;
- (TappxGender)getGender;
- (TappxMarital)getMarital;
- (nullable NSString *)getMediation;
- (nullable NSArray <NSString*> *)getKeywords;

- (void)setYearOfBirth:(NSInteger)year;
- (void)setAge:(NSInteger)age;
- (void)setGender:(TappxGender)gender;
- (void)setMarital:(TappxMarital)marital;
- (void)setMediation:(nullable NSString *)mediation;
- (void)setKeywords:(nullable NSArray <NSString*> *)keywords;

@end
