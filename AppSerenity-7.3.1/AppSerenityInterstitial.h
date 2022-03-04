//
//  AppSerenityInterstitial.h
//  AppSerenitySDK
//
//  Copyright (c) 2012 Duksel Corp. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AppSerenityInterstitial : NSObject

+ (BOOL)isReady;
+ (BOOL)isReadyForced;

+ (BOOL)showAd;
+ (BOOL)showAdForced;
+ (BOOL)showAdWithCallback:(void(^)(void))callback;
+ (BOOL)showAdForcedWithCallback:(void(^)(void))callback;

@end
