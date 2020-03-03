//
//  AppSerenityAds.h
//  AppSerenitySDK
//
//  Copyright (c) 2012 Duksel Corp. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "AppSerenityAdsDelegate.h"

@interface AppSerenityAds : NSObject

@property (nonatomic, weak) UIViewController<AppSerenityAdsDelegate>* delegate;

- (void)startRequestAds;

- (void)startRequestAdsWithDelegate:(UIViewController<AppSerenityAdsDelegate>*)delegate;

- (void)stopRequestAds;

@end
