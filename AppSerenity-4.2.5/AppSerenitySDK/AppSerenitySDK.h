//
//  AppSerenitySDK.h
//  AppSerenitySDK
//
//  Copyright (c) 2012 Duksel Corp. All rights reserved.
//

#import <Foundation/Foundation.h>

//==============================================================================
// AdNetworkIDs

#define APPSER_ADMOB_ID                             @"am"
#define APPSER_CHARTBOOST_ID                        @"cb"
#define APPSER_FACEBOOK_ID                          @"fb"
#define APPSER_GOOGLEANALYTICS_ID                   @"ga"
#define APPSER_IAD_ID                               @"i"
#define APPSER_INMOBI_ID                            @"im"
#define APPSER_SERENITY_ID                          @"s"
#define APPSER_STARTAPP_ID                          @"sa"
#define APPSER_UNITY_ADS_ID                         @"ua"
#define APPSER_VUNGLE_ID                            @"vu"

//==============================================================================
// Typedef

typedef enum
{
    kAppSerenityUserStateUndefined      = 0,
    kAppSerenityUserStateFreemium       = 1,
    kAppSerenityUserStatePremium        = 2,
}   kAppSerenityUserState;

//==============================================================================
// AppSerenity

@interface AppSerenity : NSObject

@property (nonatomic, assign)   BOOL                    isEnableDebugLogs;
@property (nonatomic, readonly) kAppSerenityUserState   userState;

+ (AppSerenity*)shared;

- (void)startSessionWithAppKey:(NSString*)appSerenityKey secretKey:(NSString*)appSecretKey;
- (void)startSessionWithAppKey:(NSString*)appSerenityKey secretKey:(NSString*)appSecretKey callbackOnLoad:(void(^)(BOOL isSuccessDataLoaded))callbackBlock;

- (BOOL)moreAppsIsExists;
- (BOOL)moreAppsShow;

- (void)sendGoogleAnalyticAppView:(NSString*)appView;
- (void)sendGoogleAnalyticEventWithCategory:(NSString*)category action:(NSString*)action label:(NSString*)label value:(NSNumber*)number;

- (void)markUserAsPremiumWithCallbackOnLoad:(void(^)(BOOL isSuccessDataLoaded))callbackBlock;
- (void)markUserAsFreemiumWithCallbackOnLoad:(void(^)(BOOL isSuccessDataLoaded))callbackBlock;

- (NSInteger)getUserId;

- (NSDictionary*)getKeyValuesList;
- (NSString*)getKeyValueByKey:(NSString*)key;

@end

//==============================================================================
// AppSerenityAdCloseButton

@interface AppSerenityAdCloseButton : NSObject

- (void)addCloseButtonToView:(UIView*)baseview;
- (void)addCloseButtonToView:(UIView*)baseview withOnClickCodeBlock:(void(^)())callbackBlock;

@end

//==============================================================================
// AppSerenityAdsDelegate

@protocol AppSerenityAdsDelegate
@optional
// Extended methods
- (void)AppSerenityAdsLoadedContentAndRequireToShowBannerBox:(UIView*)bannerBox withAdCloseButton:(AppSerenityAdCloseButton*)adCloseButton;
- (void)AppSerenityAdsReloadedContentInBannerBox:(UIView*)bannerBox withAdCloseButton:(AppSerenityAdCloseButton*)adCloseButton;
- (void)AppSerenityAdsRequireToHideBannerBox:(UIView*)bannerBox withAdCloseButton:(AppSerenityAdCloseButton *)adCloseButton;

// Simple methods
- (void)AppSerenityAdsLoadedContentAndRequireToShowBannerBox:(UIView*)bannerBox;
- (void)AppSerenityAdsReloadedContentInBannerBox:(UIView*)bannerBox;
- (void)AppSerenityAdsRequireToHideBannerBox:(UIView*)bannerBox;

// Other methods
- (void)AppSerenityAdsFailedLoadContentWithError:(NSString*)error;
- (void)AppSerenityAdsShowBannerInfoForBannerBox:(UIView*)bannerBox;
- (void)AppSerenityAdsHideBannerInfoForBannerBox:(UIView*)bannerBox;
- (void)AppSerenityAdsDidShutdown;
@end

//==============================================================================
// AppSerenityAds

@interface AppSerenityAds : NSObject

// @notice: require change with value before call [startRequestAdsWithDelegate]
// default value is 3 minutes
@property (nonatomic, assign) NSTimeInterval verboseRestartRequestInterval;

- (void)startRequestAdsWithDelegate:(UIViewController<AppSerenityAdsDelegate>*)delegate;
- (void)stopRequestAds;

@end

//==============================================================================
// AppSerenityAdsInterstitial

@interface AppSerenityAdsInterstitial : NSObject

+ (AppSerenityAdsInterstitial*)shared;

- (BOOL)isAllowShowAdForArea:(NSString*)area;

- (BOOL)isAllowShowAdForArea:(NSString*)area
            withSleepTimeout:(NSTimeInterval)sleepTimeout;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

- (BOOL)showAdForArea:(NSString*)area;

- (BOOL)showAdForArea:(NSString*)area
     withSleepTimeout:(NSTimeInterval)sleepTimeout
       callbackOnShow:(void(^)(NSString *adNetwork))callbackOnShow
      callbackOnClose:(void(^)(BOOL isSuccessShowed,NSString *adNetwork))callbackOnClose;

@end

//==============================================================================
// AppSerenityRewardedVideo

@interface AppSerenityRewardedVideo : NSObject

+ (AppSerenityRewardedVideo*)shared;

- (BOOL)isReady;

- (void)playVideoInViewController:(UIViewController*)viewController
                     withCallback:(void(^)(BOOL success))callback;

@end
