//
//  AppSerenityAdsDelegate.h
//  AppSerenitySDK
//
//  Copyright (c) 2012 Duksel Corp. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol AppSerenityAdsDelegate

@required

- (void)AppSerenityAdsRequireShowBannerView:(UIView*)bannerBox;
- (void)AppSerenityAdsRequireHideBannerView:(UIView*)bannerBox;

@optional

- (void)AppSerenityAdsBannerDidRefresh:(UIView*)bannerBox;
- (void)AppSerenityAdsFailedLoadBannerWithError:(NSString*)error;

@end
