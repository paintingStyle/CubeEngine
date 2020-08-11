//
//  CubeRemoteDesktop.h
//  CubeEngine
//
//  Created by 曾長歡 on 2017/8/15.
//  Copyright © 2017年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CubeRemoteDesktop : NSObject

/**
 远程桌面ID远程桌面的唯一标示，可是是一个新的群组号，也可以是之前定义的sn
 */
@property (nonatomic, copy) NSString *desktopId;

/**
 远程桌面名称
 */
@property (nonatomic, copy) NSString *name;

/**
 远程桌面地址
 */
@property (nonatomic, copy) NSString *host;


/**
 远程桌面分享端口
 */
@property (nonatomic, assign) int sharePort;


/**
 远程桌面接收端口
 */
@property (nonatomic, assign) int receivePort;


/**
 远程桌面分享者
 */
@property (nonatomic, copy) NSString *sharer;


/**
 被邀请查看远程桌面的人
 */
@property (nonatomic, strong) NSArray <NSString *> *invites;


/**
 查看远程桌面的人
 */
@property (nonatomic, strong) NSArray <NSString *> *appliers;


/**
 远程桌面绑定群组ID
 */
@property (nonatomic, copy) NSString *bindGroupId;

+ (CubeRemoteDesktop *)parse:(NSDictionary *)dict;
- (NSMutableDictionary *)toJSON;
/**
  构造方法

 @param desktopId desktopId
 @param name name
 @param sharePort sharePort
 @param receivePort receivePort
 @param sharer sharer
 @param invites invites
 @param appliers appliers
 @param bindGroupId bindGroupId
 @return return CubeRemoteDesktop Object
 */
//- (id)initWithDesktopId:(NSString *)desktopId withName:(NSString *)name withSharePort:(int)sharePort withReceivePort:(int)receivePort withSharer:(NSString *)sharer withInvites:(NSArray <NSString *> *)invites withAppliers:(NSArray <NSString *> *)appliers withBindGroupId:(NSString *)bindGroupId;


@end
