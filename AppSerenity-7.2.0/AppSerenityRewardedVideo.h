//
//  AppSerenityRewardedVideo.h
//  AppSerenitySDK
//
//  Copyright (c) 2012 Duksel Corp. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AppSerenityRewardedVideo : NSObject

+ (BOOL)isReady;

+ (void)playInViewController:(UIViewController*)viewController withCallback:(void(^)(BOOL success))callback;

@end
