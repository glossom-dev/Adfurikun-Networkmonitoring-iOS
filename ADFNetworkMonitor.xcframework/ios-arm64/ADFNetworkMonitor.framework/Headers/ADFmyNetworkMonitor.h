//
//  ADFmyNetworkMonitor.h
//  ADFNetworkMonitor
//
//  Created by Sungil Kim on 2022/01/25.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSInteger, ADFNMLogLevel) {
    ADFNMLogLevelNone = 0,
    ADFNMLogLevelTrace = 1 << 0,
    ADFNMLogLevelDebug = 1 << 1,
    ADFNMLogLevelInfo = 1 << 2,
    ADFNMLogLevelAllowedHost = 1 << 3,
    ADFNMLogLevelDeniedHost = 1 << 4,
    ADFNMLogLevelResult = 1 << 5,
    ADFNMLogLevelWarning = 1 << 6,
    ADFNMLogLevelError = 1 << 7,
    ADFNMLogLevelAll = 0xffff
};

NS_ASSUME_NONNULL_BEGIN

@interface ADFmyNetworkMonitor : NSObject

@property (nonatomic) NSString *appId;
@property (nonatomic) NSString *trackingId;
@property (nonatomic) NSString *sdkVer;

+ (void)enableNetworkMonitoring;
+ (void)setLogLevel:(ADFNMLogLevel)level;
- (void)startWithInfo:(NSDictionary *)info;

@end

NS_ASSUME_NONNULL_END
