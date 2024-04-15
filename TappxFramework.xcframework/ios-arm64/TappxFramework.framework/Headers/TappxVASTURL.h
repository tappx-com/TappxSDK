//
//  TappxVASTURL.h
//  TappxFramework
//
//  Created by Guybrush Threepwood on 10/06/2021.
//  Copyright © 2021 Tappx. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_SWIFT_NAME(TappxVASTVideoPosition)
typedef NS_ENUM(NSUInteger, TappxVASTVideoPosition) {
    TappxVASTVideoPositionOutstream = 0,
    TappxVASTVideoPositionPreRoll = 1,
    TappxVASTVideoPositionMidRoll = 2,
    TappxVASTVideoPositionPostRoll = 3
};

NS_SWIFT_NAME(TappxVASTVideoFormat)
typedef NS_ENUM(NSUInteger, TappxVASTVideoFormat) {
    TappxVASTVideoFormatAll = 0,
    TappxVASTVideoFormatVideoMP4 = 1,
    TappxVASTVideoFormatVideoWMV = 2,
    TappxVASTVideoFormatVideoWebM = 3
};

NS_SWIFT_NAME(TappxVASTVersion)
typedef NS_ENUM(NSUInteger, TappxVASTVersion) {
    TappxVASTVersionV2 = 2,
    TappxVASTVersionV3 = 3
};

NS_SWIFT_NAME(TappxVASTVPAIDVersion)
typedef NS_ENUM(NSUInteger, TappxVASTVPAIDVersion) {
    TappxVASTVPAIDVersionV1AndV2 = 0,
    TappxVASTVPAIDVersionV1 = 1,
    TappxVASTVPAIDVersionV2 = 2
};

NS_SWIFT_NAME(TappxVASTPlaybackMethod)
typedef NS_ENUM(NSUInteger, TappxVASTPlaybackMethod) {
    TappxVASTPlaybackMethodAutoPlaySoundOn = 0,
    TappxVASTPlaybackMethodAutoPlaySoundOff = 1
};


NS_SWIFT_NAME(TappxVASTURL)
@interface TappxVASTURL : NSObject

+ (nullable instancetype)VASTURLforHost:(nonnull NSString *)host
                               tappxKey:(nonnull NSString *)key
                          videoPosition:(TappxVASTVideoPosition)videoPosition
                                   with:(nonnull NSNumber *)width
                                 height:(nonnull NSNumber *)height
                        applicationName:(nonnull NSString *)applicationName
                    applicationStoreURL:(nonnull NSString *)applicationStoreURL NS_SWIFT_NAME(init(host:key:videoPosition:width:height:applicationName:applicationStoreUrl:));
                              
- (void)setGDPROptin:(BOOL)gdprOptin;
- (void)setMinDurationVideoSeconds:(nullable NSNumber *)minDurationVideoSeconds NS_SWIFT_NAME(setMinDurationVideo(seconds:));
- (void)setMaxDurationVideoSeconds:(nullable NSNumber *)maxDurationVideoSeconds NS_SWIFT_NAME(setMaxDurationVideo(seconds:));
/**
 Arrays of TappxVASTVPAIDVersion items
 
 Eg: @[@(TappxVASTVideoFormatVideoMP4), @(TappxVASTVideoFormatVideoWMV)]
 */
- (void)setVASTVideoFormat:(nullable NSArray <NSNumber *> *)vastVideoFormat NS_SWIFT_NAME(setVideoFormat(videoFormat:));

#pragma mark - Recommended parameters

- (void)setAppCategory:(nullable NSString *)appCategory NS_SWIFT_NAME(setAppCategory(category:));

- (void)setGDPRConsent:(nullable NSString *)gdprConsent NS_SWIFT_NAME(setGDPRConsent(consent:));
- (void)setUsPrivacy:(nullable NSString *)usPrivacy NS_SWIFT_NAME(setUsPrivacy(privacy:));
/**
Arrays of TappxVASTVersion items

Eg: @[@(TappxVASTVersionV2), @(TappxVASTVersionV3)]
*/
- (void)setVASTVersion:(nullable NSArray <NSNumber *> *)vastVersion NS_SWIFT_NAME(setVersion(vastVersion:));
- (void)setVASTPlaybackMethod:(TappxVASTPlaybackMethod)vastPlaybackMethod NS_SWIFT_NAME(setPlaybackMethod(playbackMethod:));

- (void)setVPAIDAd:(BOOL)vpaidAd NS_SWIFT_NAME(setVPAIDAd(vpaid:));
- (void)setVPAIDVersion:(TappxVASTVPAIDVersion)vpaidVersion NS_SWIFT_NAME(setVPAIDVersion(version:));

- (void)setOMSDKSupported:(BOOL)omsdkSupported NS_SWIFT_NAME(setOMSDKSupported(supported:));
- (void)setOMSDKIdentifier:(nullable NSString *)omsdkIdentifier NS_SWIFT_NAME(setOMSDKIdentifier(identidier:));
- (void)setOMSDKVersionString:(nullable NSString *)omsdkVersionString NS_SWIFT_NAME(setOMSDKVersionString(version:));

#pragma mark - Optional parameters

- (void)setCOPPA:(BOOL)coppa NS_SWIFT_NAME(setCOPPA(coppa:));

- (void)setTest:(BOOL)test NS_SWIFT_NAME(setTest(enable:));

#pragma mark - Build URL

- (void)URL:(void (^_Nonnull)(NSURL* _Nullable url))completion NS_SWIFT_NAME(url(completion:));
- (nullable NSString *)stringURL;

@end

