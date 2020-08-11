//
//  CubeRemoteDesktopService.h
//  CubeEngine
//
//  Created by 曾長歡 on 2017/3/15.
//  Copyright © 2017年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CubePrerequisites.h"
#import "CubeErrorInfo.h"
@interface CubeRemoteDesktopService : NSObject

@property (nonatomic, weak) id<CubeRemoteDesktopDelegate>rdDelegate;



/**
 分享桌面

 @param name 分享桌面名称，可以是群的displayName，也可是自己的
 @param bindGroupId 绑定群组，可以为空
 */
- (void)create:(NSString *)name withBindGroupId:(NSString *)bindGroupId;


/**
 分享桌面
 */

/**
 分享桌面

 @param name 分享桌面名称
 @param cubeIdArray 绑定群组 可以为空
 @param groupId  绑定群组 可以为空
 */
- (void)share:(NSString *)name withList:(NSArray <NSString *>*)cubeIdArray withGroupId:(NSString *)groupId;
//- (void)shareWithTargets:(NSArray *<NSString *>)tragets;


/**
 停止分享

 @param desktopId desktopId
 */
- (void)revoke:(NSString *)desktopId;

/**
 申请查看远程桌面
 
 @param name cube号
 */
- (void)apply:(NSString *)desktopId;


/**
 申请查看远程桌面

 @param desktopId desktopId
 @param groupId 群组
 */
- (void)apply:(NSString *)desktopId withGroupId:(NSString *)groupId;

/**
 离开远程桌面
 */
- (void)leave:(NSString *)desktopId;

/**
 * 销毁远程桌面
 *
 * @param desktopId
 */
- (void)destroy:(NSString *)desktopId;

/**
 获取远端桌面画面

 @return 远程桌面View
 */
- (UIView *)getRemoteView;


/**
 获取本地桌面画面

 @return 本地桌面画面
 */
//- (UIView *)getLocalView;
@end
