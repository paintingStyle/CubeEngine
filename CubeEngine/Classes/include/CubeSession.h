//
//  CubeSession.h
//  Cube Engine
//
//  Created by Xu Jiangwei on 14/9/28.
//  Copyright (c) 2014-2016 Cube Team. All rights reserved.
//

#ifndef CubeSession_h
#define CubeSession_h

#include "CubePrerequisites.h"

/** 协作交互时通信会话对象。
 *
 * 每个会话表示一个可被管理的端到端的状态描述。
 * 可以从会话对象中获取关于本次会话相关的信息。
 */
@interface CubeSession : NSObject

/** 正在使用的音/视频通话对端。 */
@property (nonatomic, strong, readonly) CubeCallPeer *callPeer;

/** 己方（本地端）名称。 */
@property (nonatomic, strong, readonly) NSString *name;

/** 己方 （本地端） 显示名称。 */
@property (nonatomic, strong, readonly) NSString *displayName;

/** 己方的注册状态。 */
@property (nonatomic, assign, readonly) CubeRegistrationState registrationState;

/** 己放的通话状态。 */
@property (nonatomic, assign, readonly) CubeSignalingState callState;

/** 己方通话时是否使用视频。 */
@property (nonatomic, assign, readonly) BOOL videoEnabled;

/** 当前通话的通话方向。 */
@property (nonatomic, assign, readonly) CubeCallDirection callDirection;
/** 当前通话结束动作。 */
@property (nonatomic, assign, readonly) CubeCallEndAction callEndAction;

/** 本地视频视图。 */
@property (nonatomic, weak, readonly) CubeLocalVideoView *localVideoView;
/** 远程视频视图。 */
@property (nonatomic, weak, readonly) UIView *remoteViewView;

/** 当前会议实例。 */
@property (nonatomic, readonly) Conference *conference;

/**通话时长*/
@property (nonatomic, readonly) NSInteger callTime;

/**
 延迟时间
 */
@property (nonatomic, assign) long long latency;
/** 返回会话是否已经注册。
 */
- (BOOL)hasRegistered;

/** 是否正在呼叫。
 */
- (BOOL)isCalling;

/** 是否会议呼叫。
 */
- (BOOL)isConferenceCall;

/**
 更新displayName
 */
- (void)upadateDisplayName:(NSString *)displayName;

/**
 更新session.name
 */
- (void)upadateName:(NSString *)name;


/**
 注册状态转字符串

 @param registrationState 已方注册状态
 @return 已方注册状态的字符串表示
 */
+ (NSString *)parseRegistrationState:(CubeRegistrationState)registrationState;
@end

#endif
