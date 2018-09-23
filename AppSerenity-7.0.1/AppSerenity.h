//
//  AppSerenity.h
//  AppSerenitySDK
//
//  Copyright (c) 2012 Duksel Corp. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AppSerenity : NSObject

+ (void)startSessionWithAppId:(NSString*)appId appSecret:(NSString*)appSecret;

+ (void)setCustomUserId:(NSString*)userCustomId;

@end
