//
//  CubeCallService.h
//  CubeEngine
//
//  Created by guoqiangzhu on 16/2/22.
//  Copyright © 2016年 Cube Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CubePrerequisites.h"


/**
 * 音/视频呼叫服务。
 *
 */

@interface CubeCallService : NSObject

/** 音/视频通话状态委派*/
@property (nonatomic, weak) id<CubeCallServiceDelegate> callServiceDelegate;

/** 本地视频视图*/
@property (nonatomic, strong, readonly) CubeLocalVideoView *localVideoView;

/** 远程视频视图*/
@property (nonatomic, strong, readonly) UIView *remoteVideoView;

/**
 * 向指定号码的对端发起视频、语音呼叫。
 * @discussion 此方法必须在 UI 线程中调用。
 *
 * @param callee 指定对端号码。
 * @param videoEnabled 指定是否使用视频通话。
 * @return 如果呼叫发起成功则返回 \c YES ，否则返回 \c NO 。
 */
- (BOOL)makeCall:(NSString *)callee videoEnabled:(BOOL)videoEnabled;

/**
 * 应答对端发起的视频、语音呼叫。
 * @discussion 此方法必须在 UI 线程中调用。
 *
 * @param videoEnabled 指定是否使用视频方法进行应答。
 * @return 如果应答被成功执行则返回 \c YES ，否则返回 \c NO 。
 */
- (BOOL)answerCall:(BOOL)videoEnabled;

/**
 * 终止或拒绝呼叫。
 * @discussion 此方法必须在 UI 线程中调用。
 *
 * @return 如果终止呼叫被成功执行则返回 \c YES ，否则返回 \c NO 。
 */
- (BOOL)terminateCall;

///**
// 重新协商(为方便调试暂放外部接口,之后隐藏在内部实现)
//
// @param target target
// @param enable enable
// */
//- (void)renegotiateCallWithTarget:(NSString *)target andVideoEnable:(BOOL)enable;

@end
