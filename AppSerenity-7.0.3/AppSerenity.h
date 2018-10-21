//
//  AppSerenity.h
//  AppSerenitySDK
//
//  Copyright (c) 2012 Duksel Corp. All rights reserved.
//

#import <Foundation/Foundation.h>

//----------------------------------------------------------------------------------------------------------------------

typedef enum
{
    kAppSerenityLogLevel_None           = 0,
    kAppSerenityLogLevel_Info           = 1,
    kAppSerenityLogLevel_Warning        = 2,
    kAppSerenityLogLevel_Error          = 4,
}   kAppSerenityLogLevel;

//----------------------------------------------------------------------------------------------------------------------

@interface AppSerenity : NSObject

+ (void)startSessionWithAppId:(NSString*)appId appSecret:(NSString*)appSecret;

+ (void)setCustomUserId:(NSString*)userCustomId;

+ (void)setLogLevel:(kAppSerenityLogLevel)logLevel;

+ (NSString*)getSdkVersion;

@end
