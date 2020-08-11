//
//  CubeRecallInfo.h
//  CubeEngine
//
//  Created by pretty on 2018/12/7.
//  Copyright © 2018 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CubeOperateUser : NSObject

/**
 发起撤回操作的人Cube
 */
@property (nonatomic , strong)NSString *cubeId;

- (NSMutableDictionary *)toJSONObject;

+ (CubeOperateUser *)operateUserParse:(NSDictionary *)data;
@end

@interface CubeRecallInfo : NSObject

/**
 operateUser:发起撤回操作的人
 */
@property (nonatomic,strong) CubeOperateUser * opu;

/**
 operatePermissions 操作等级(普通用户:0(默认),管理员:1,系统:2),标记用户的权限等级
 */
@property (nonatomic,assign) NSInteger opp;

/**
 operateCode 操作码(正常撤回,其他原因被撤回)
 */
@property (nonatomic,assign) NSInteger opc;

/**
 operateDesc 撤回描述
 */
@property (nonatomic,strong) NSString *opd;

- (NSMutableDictionary *)toJSONObject;

+ (CubeRecallInfo *)recallInfoParse:(NSDictionary *)data;
@end


