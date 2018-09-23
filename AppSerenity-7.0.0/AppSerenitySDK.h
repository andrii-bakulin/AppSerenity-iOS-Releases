//
//  AppSerenitySDK.h
//  AppSerenitySDK
//
//  Copyright (c) 2012 Duksel Corp. All rights reserved.
//

#import <Foundation/Foundation.h>

//======================================================================================================================
// AdNetworkIDs

#define kAPPSERENITY_ADMOB                              @"Admob"        // Banner | Interstitial | -
#define kAPPSERENITY_APPLOVIN                           @"AppLovin"     // -      | Interstitial | RewardedVideo
#define kAPPSERENITY_CHARTBOOST                         @"Chartboost"   // -      | Interstitial | RewardedVideo
#define kAPPSERENITY_FACEBOOK                           @"FacebookAds"  // Banner | Inters.@BUG@ | -
#define kAPPSERENITY_UNITY_ADS                          @"UnityAds"     // -      | Interstitial | RewardedVideo

typedef enum
{
    kAppSerenityCfgBannerSizeAuto   = 0,
    kAppSerenityCfgBannerSize320x50 = 1,
    kAppSerenityCfgBannerSize728x90 = 2,
}   kAppSerenityCfgBannerSize;

//======================================================================================================================
// AppSerenity

@interface AppSerenity : NSObject

+ (AppSerenity*)shared;

- (void)startSessionWithAppId:(NSString*)appId appSecret:(NSString*)appSecret;

- (void)setCustomUserId:(NSString*)userCustomId;

+ (BOOL)isIPad;

@end

//======================================================================================================================
// AppSerenityAdsDelegate

@protocol AppSerenityAdsDelegate
@optional
- (void)AppSerenityAdsRequireToShowBannerBox:(UIView*)bannerBox byNetwork:(NSString*)networkId;
- (void)AppSerenityAdsRequireToHideBannerBox:(UIView*)bannerBox byNetwork:(NSString*)networkId;
- (void)AppSerenityAdsUserActionShouldBegin:(UIView*)bannerBox byNetwork:(NSString*)networkId;
- (void)AppSerenityAdsUserActionDidFinish:(UIView*)bannerBox byNetwork:(NSString*)networkId;
- (void)AppSerenityAdsBannerDidRefreshed:(UIView*)bannerBox byNetwork:(NSString*)networkId;
- (void)AppSerenityAdsFailedLoadContentWithError:(NSString*)error byNetwork:(NSString*)networkId;
@end

//======================================================================================================================
// AppSerenityAds

@interface AppSerenityAds : NSObject

@property (nonatomic, weak) UIViewController<AppSerenityAdsDelegate>* delegate;

- (void)startRequestAds;
- (void)startRequestAdsWithDelegate:(UIViewController<AppSerenityAdsDelegate>*)delegate;
- (void)stopRequestAds;

@end

//======================================================================================================================
// AppSerenityInterstitial

@interface AppSerenityInterstitial : NSObject

+ (AppSerenityInterstitial*)shared;

- (BOOL)isReady;
- (BOOL)isReadyForced:(BOOL)isForced;

- (BOOL)showAdWithCloseCallback:(void(^)(void))callback;
- (BOOL)showAdWithCloseCallback:(void(^)(void))callback isForced:(BOOL)isForced;

@end

//======================================================================================================================
// AppSerenityRewardedVideo

@interface AppSerenityRewardedVideo : NSObject

+ (AppSerenityRewardedVideo*)shared;

- (BOOL)isReady;

- (void)playVideoInViewController:(UIViewController*)viewController
                     withCallback:(void(^)(BOOL success))callback;

@end

//======================================================================================================================
