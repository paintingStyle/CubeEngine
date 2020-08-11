//
//  CubeGroupService.h
//  CubeEngine
//
//  Created by guoqiangzhu on 16/2/19.
//  Copyright © 2016年 Cube Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CubePrerequisites.h"

/**
 群组服务。
  */
@interface CubeGroupService : NSObject


/**
 群组服务委派
 */
@property (nonatomic, weak) id<CubeGroupServiceDelegate> groupServiceDelegate;


/**
 创建群组

 @param displayName 群组昵称
 @return 是否成功
 */
- (BOOL)createGroup:(NSString *)displayName;


/**
 创建群组

 @param displayName 群组昵称
 @param members 群组成员
 @return 是否成功
 */
- (BOOL)createGroup:(NSString *)displayName withMembers:(NSArray *)members;


/**
 创建群组

 @param customId 自定义ID
 @param displayName 群名称
 @param members 成员列表
 @param masters 群主列表
 @return 是否成功
 */
- (BOOL)createGroupWithCustomId:(NSString *)customId
                withDisplayName:(NSString *)displayName
                    withMembers:(NSArray *)members
                    withMasters:(NSArray *)masters;


/**
 删除群组

 @param name 组号
 @return 是否成功
 */
- (BOOL)deleteGroup:(NSString *)name;


/**
 向群组添加成员

 @param members 群组成员
 @param name 组号
 @return 是否成功
 */
- (BOOL)addMembers:(NSArray *)members toGroup:(NSString *)name;


/**
 从群组移除成员

 @param members 群组成员
 @param name 组号
 @return 是否成功
 */
- (BOOL)removeMembers:(NSArray *)members fromGroup:(NSString *)name;


/**
 查询用户所属组

 @param callback 回调block。回调参数groupDic :[size:groups.count, list: {GroupContext *group}]
 @param errorCallback 错误回调
 @return 是否成功
 */
- (BOOL)queryGroupsWithCallBack:(void (^)(NSDictionary *groupDic))callback andError:(void (^)(NSString *errorCode))errorCallback;


/**
 查询指定组详细数据

 @param groupName 组号
 @param callback 回调block。回调参数groupContext : 组相关信息, members : 组成员
 @param errorCallback 错误回调
 @return 是否成功
 */
- (BOOL)queryGroupDetailsWithName:(NSString *)groupName andCallback:(void (^)(GroupContext *groupContext))callback andError:(void (^)(NSString *errorCode))errorCallback;


/**
 添加管理员

 @param groupName 组号
 @param master 群管理员
 @return 是否成功
 */
- (BOOL)addMasters:(NSString *)groupName withMasters:(NSString *)master;


/**
 删除管理员

 @param groupName 组号
 @param master 群管理员
 @return 是否成功
 */
- (BOOL)removeMasters:(NSString *)groupName withMasters:(NSString *)master;


/**
 添加修改群组昵称

 @param groupName 组号
 @param nickname 昵称
 @return 是否成功
 */
- (BOOL)changeGroupName:(NSString *)groupName withNickName:(NSString *)nickname;

@end
