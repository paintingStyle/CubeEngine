//
//  GroupContext.h
//  CubeEngine
//
//  Created by guoqiangzhu on 15/10/12.
//  Copyright (c) 2015年 Cube Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Conference.h"

/**
 组的上下文信息类
 */
@interface GroupContext : NSObject

/**
 组名
 */
@property (nonatomic, strong) NSString *name;

/**
 组昵称
 */
@property (nonatomic, strong) NSString *displayName;

/**
 组创建者
 */
@property (nonatomic, strong) NSString *founder;

/**
 创建时间
 */
@property (nonatomic, assign) long long createdTime;

/**
 组成员
 */
@property (nonatomic, strong) NSArray *members;

/**
 组会议
 */
@property (nonatomic, strong) Conference *conference;

/**
 countMembers 组成员数量
 */
@property (nonatomic, assign) int countMembers;


/**
 构造函数

 @param name 组名
 @param displayName 组昵称
 @param founder 创建者
 @param createTime 创建时间
 @param members 组成员
 @param conf 组会议
 @param countMembers 组成员数量
 @return 组实体
 */
- (id)initWithName:(NSString *)name
    andDisplayName:(NSString *)displayName
        andFounder:(NSString *)founder
     andCreateTime:(long long)createTime
        andMembers:(NSArray *)members
     andConference:(Conference *)conf
   andCountMembers:(int)countMembers;


/**
 转字典

 @return 字典
 */
- (NSMutableDictionary *)toJSON;


/**
 解析群组实体

 @param dictionary 数据字典
 @return 群组对象
 */
+ (GroupContext *)GroupParse:(NSDictionary *)dictionary;

@end
