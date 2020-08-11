//
//  CubeLiveInfo.h
//  CubeEngine
//
//  Created by jianchengpan on 2017/8/21.
//  Copyright © 2017年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CubeLiveServerInfo : NSObject

/**
 频道地址
 */
@property (nonatomic, copy) NSString *host;

/**
 频道端口
 */
@property (nonatomic, assign) int port;

/**
 推流端口
 */
@property (nonatomic, copy) NSString *streamPort;

+(CubeLiveServerInfo *)parse:(NSDictionary *)jsonObject;

-(NSDictionary *)toJson;

@end


@interface CubeLiveInfo : NSObject

/**
 绑定的群组ID
 */
@property (nonatomic, copy) NSString *groupId;

/**
 直播频道
 */
@property (nonatomic, assign) NSInteger channel;

/**
 直播名
 */
@property (nonatomic, copy) NSString *liveName;

/**
 直播人cubeID
 */
@property (nonatomic, copy) NSString *master;

/**
 服务器信息
 */
@property (nonatomic, strong) CubeLiveServerInfo *LiveServerInfo;

/**
 观看人列表
 */
@property (nonatomic, strong) NSArray *members;

/**
 直播URL
 */
@property (nonatomic, copy) NSString *url;



+(CubeLiveInfo *)parse:(NSDictionary *)jsonObject;

-(NSDictionary *)toJson;

@end
