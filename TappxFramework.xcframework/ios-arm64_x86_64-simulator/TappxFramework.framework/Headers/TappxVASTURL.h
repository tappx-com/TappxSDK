//
//  TappxVASTURL.h
//  TappxFramework
//
//  Created by Guybrush Threepwood on 10/06/2021.
//  Copyright © 2021 Tappx. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, TappxVASTVideoPosition) {
    TappxVASTVideoPositionOutstream = 0,
    TappxVASTVideoPositionPreRoll = 1,
    TappxVASTVideoPositionMidRoll = 2,
    TappxVASTVideoPositionPostRoll = 3
};

typedef NS_ENUM(NSUInteger, TappxVASTVideoFormat) {
    TappxVASTVideoFormatAll = 0,
    TappxVASTVideoFormatVideoMP4 = 1,
    TappxVASTVideoFormatVideoWMV = 2,
    TappxVASTVideoFormatVideoWebM = 3
};

typedef NS_ENUM(NSUInteger, TappxVASTVersion) {
    TappxVASTVersionV2 = 2,
    TappxVASTVersionV3 = 3
};

typedef NS_ENUM(NSUInteger, TappxVASTVPAIDVersion) {
    TappxVASTVPAIDVersionV1AndV2 = 0,
    TappxVASTVPAIDVersionV1 = 1,
    TappxVASTVPAIDVersionV2 = 2
};

typedef NS_ENUM(NSUInteger, TappxVASTPlaybackMethod) {
    TappxVASTPlaybackMethodAutoPlaySoundOn = 0,
    TappxVASTPlaybackMethodAutoPlaySoundOff = 1
};


@interface TappxVASTURL : NSObject

+ (nullable instancetype)VASTURLforHost:(nonnull NSString *)host
                               tappxKey:(nonnull NSString *)key
                          videoPosition:(TappxVASTVideoPosition)videoPosition
                                   with:(nonnull NSNumber *)width
                                 height:(nonnull NSNumber *)height
                        applicationName:(nonnull NSString *)applicationName
                    applicationStoreURL:(nonnull NSString *)applicationStoreURL;
                              
- (void)setGDPROptin:(BOOL)gdprOptin;
- (void)setMinDurationVideoSeconds:(nullable NSNumber *)minDurationVideoSeconds;
- (void)setMaxDurationVideoSeconds:(nullable NSNumber *)maxDurationVideoSeconds;
/**
 Arrays of TappxVASTVPAIDVersion items
 
 Eg: @[@(TappxVASTVideoFormatVideoMP4), @(TappxVASTVideoFormatVideoWMV)]
 */
- (void)setVASTVideoFormat:(nullable NSArray <NSNumber *> *)vastVideoFormat;

#pragma mark - Recommended parameters

- (void)setAppCategory:(nullable NSString *)appCategory;

- (void)setGDPRConsent:(nullable NSString *)gdprConsent;
- (void)setUsPrivacy:(nullable NSString *)usPrivacy;
/**
Arrays of TappxVASTVersion items

Eg: @[@(TappxVASTVersionV2), @(TappxVASTVersionV3)]
*/
- (void)setVASTVersion:(nullable NSArray <NSNumber *> *)vastVersion;
- (void)setVASTPlaybackMethod:(TappxVASTPlaybackMethod)vastPlaybackMethod;

- (void)setVPAIDAd:(BOOL)vpaidAd;
- (void)setVPAIDVersion:(TappxVASTVPAIDVersion)vpaidVersion;

- (void)setOMSDKSupported:(BOOL)omsdkSupported;
- (void)setOMSDKIdentifier:(nullable NSString *)omsdkIdentifier;
- (void)setOMSDKVersionString:(nullable NSString *)omsdkVersionString;

#pragma mark - Optional parameters

- (void)setCOPPA:(BOOL)coppa;

- (void)setTest:(BOOL)test;

#pragma mark - Build URL

- (void)URL:(void (^_Nonnull)(NSURL* _Nullable url))completion;
- (nullable NSString *)stringURL;

@end

