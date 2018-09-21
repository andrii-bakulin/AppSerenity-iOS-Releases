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
#define kAPPSERENITY_CHARTBOOST                         @"Chartboost"   // -      | Interstitial | -
#define kAPPSERENITY_FACEBOOK                           @"FacebookAds"  // Banner | Interstitial | -
#define kAPPSERENITY_IAD                                @"iAd"          // Banner | -            | -
#define kAPPSERENITY_INMOBI                             @"InMobi"       // Banner | -            | -
#define kAPPSERENITY_STARTAPP                           @"StartApp"     // Banner | Interstitial | -
#define kAPPSERENITY_UNITY_ADS                          @"UnityAds"     // -      | Interstitial | RewardedVideo
#define kAPPSERENITY_VUNGLE                             @"Vungle"       // -      | -            | RewardedVideo

typedef enum
{
    kAppSerenityGenderUndefined     = 0,
    kAppSerenityGenderMale          = 1,
    kAppSerenityGenderFemale        = 2,
}   kAppSerenityGender;

typedef enum
{
    kAppSerenityCfgBannerSizeAuto   = 0,
    kAppSerenityCfgBannerSize320x50 = 1,
    kAppSerenityCfgBannerSize728x90 = 2,
}   kAppSerenityCfgBannerSize;

//======================================================================================================================
// AppSerenityCfg

@interface AppSerenityCfg : NSObject

+ (AppSerenityCfg*)shared;

@property (nonatomic, assign) kAppSerenityCfgBannerSize Overall_bannerSize;

@property (nonatomic, strong) NSString* Admob_bannerAppKey;                     // nil
@property (nonatomic, strong) NSString* Admob_interstitialAppKey;               // nil
@property (nonatomic, strong) NSString* AppLovin_sdkKey;                        // nil
@property (nonatomic, assign) BOOL      AppLovin_rewardedVideoIsEnabled;        // YES
@property (nonatomic, strong) NSString* Chartboost_appKey;                      // nil
@property (nonatomic, strong) NSString* Chartboost_appSignature;                // nil
@property (nonatomic, strong) NSString* Facebook_bannerPlacementId;             // nil
@property (nonatomic, strong) NSString* Facebook_interstitialPlacementId;       // nil
@property (nonatomic, strong) NSString* GoogleAnalytics_appKey;                 // nil
@property (nonatomic, assign) BOOL      iAd_bannerIsEnabled;                    // YES
@property (nonatomic, strong) NSString* InMobi_accountId;                       // nil
@property (nonatomic, assign) long long InMobi_bannerPlacementId;               // 0
@property (nonatomic, strong) NSString* StartApp_appId;                         // nil
@property (nonatomic, strong) NSString* StartApp_developerId;                   // nil
@property (nonatomic, strong) NSString* UnityAds_gameId;                        // nil
@property (nonatomic, strong) NSString* Vungle_appKey;                          // nil

/* DEFAULT = @[
 kAPPSERENITY_FACEBOOK,
 kAPPSERENITY_FACEBOOK,
 kAPPSERENITY_FACEBOOK,
 kAPPSERENITY_INMOBI,
 kAPPSERENITY_INMOBI,
 kAPPSERENITY_IAD,
 kAPPSERENITY_STARTAPP,
 kAPPSERENITY_ADMOB,
 ]; --------------------> will be use by choose random 1 item each time network change (so may use few times to increase chance)
 */
@property (atomic, strong) NSArray*     BannersQueue;

/* DEFAULT = @[
 kAPPSERENITY_FACEBOOK,
 kAPPSERENITY_APPLOVIN,
 kAPPSERENITY_UNITY_ADS,
 kAPPSERENITY_CHARTBOOST,
 kAPPSERENITY_STARTAPP,
 kAPPSERENITY_ADMOB,
 ]; --------------------> will be use from 1st to last. 1st availble network will show ad
 */
@property (atomic, strong) NSArray*     InterstitialQueue;

/* DEFAULT = @[
 kAPPSERENITY_UNITY_ADS,
 kAPPSERENITY_APPLOVIN,
 kAPPSERENITY_VUNGLE,
 ]; --------------------> will be use from 1st to last. 1st availble network will show rewarded-video
 */
@property (atomic, strong) NSArray*     RewardedVideoQueue;

@property (atomic, assign) NSInteger    BannersInnerRefresh;                    // 45
@property (atomic, assign) NSInteger    BannersVerboseRefresh;                  // 120
@property (atomic, assign) NSInteger    InterstitialSleep;                      // 0
@property (atomic, assign) NSInteger    InterstitialTimeout;                    // 0

@property (atomic, assign) BOOL         IsRequireSyncTimeouts;                  // YES

@end

//======================================================================================================================
// AppSerenity

@interface AppSerenity : NSObject

+ (AppSerenity*)shared;

- (void)startSession;
- (void)startSessionWithAppKey:(NSString*)appSerenityKey;

- (void)GoogleAnalytic_sendAppView:(NSString*)appView;
- (void)GoogleAnalytic_sendEventWithCategory:(NSString*)category
                                      action:(NSString*)action
                                       label:(NSString*)label
                                       value:(NSNumber*)number;

- (BOOL)moreAppsIsExists;
- (BOOL)moreAppsShow;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

- (void)resetUserParams;

- (void)setUserGender:(kAppSerenityGender)gender;
- (kAppSerenityGender)getUserGender;

- (void)setUserBirtdayYear:(NSInteger)year month:(NSInteger)month day:(NSInteger)day;
- (NSInteger)getUserBirthdayYear;
- (NSInteger)getUserBirthdayMonth;
- (NSInteger)getUserBirthdayDay;
- (NSInteger)getUserAge;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

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
- (BOOL)isReadyVerbose:(BOOL)isVerbose;

- (BOOL)showAdWithCloseCallback:(void(^)(void))callback;
- (BOOL)showAdWithCloseCallback:(void(^)(void))callback verbose:(BOOL)isVerbose;

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
