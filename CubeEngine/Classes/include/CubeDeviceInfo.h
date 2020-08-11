//
//  CubeDeviceInfo.h
//  CubeEngine
//
//  Created by 曾長歡 on 2017/1/11.
//  Copyright © 2017年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CubeDeviceInfo : NSObject

/**平台名*/
@property (nonatomic, copy) NSString *name;
/**版本号*/
@property (nonatomic, copy) NSString *version;
/**平台信息*/
@property (nonatomic, copy) NSString *platform;
/**设备ID*/
@property (nonatomic, copy) NSString *deviceId;
/**用户ID*/
@property (nonatomic, copy) NSString *cubeId;
/**
 创建实例对象并初始化

 @param dict 初始化信息字典
 @return 实例对象
 */
+ (CubeDeviceInfo *)deviceInfoParse:(NSDictionary *)dict;

/**
 生产字典

 @return 字典
 */
- (NSMutableDictionary *)deviceInfoToJSON;

/**是否是当前设备*/
-(BOOL)isCurrentDevice;

@end
