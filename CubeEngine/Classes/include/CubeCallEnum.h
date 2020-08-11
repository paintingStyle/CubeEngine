//
//  CubeCallEnum.h
//  CubeEngineMediaKit
//
//  Created by Ashine on 2018/5/14.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#ifndef CubeCallEnum_h
#define CubeCallEnum_h

/**
 * 呼叫状态
 */
typedef enum : NSUInteger {
    CubeCallStateNone,                                  // 空闲
    CubeCallStateInvited,                               // 邀请
    CubeCallStateInCall,                                // 通话中
    CubeCallStateRinging,                               // 响铃
} CubeCallState;


///**
// * 视频/语音通话呼叫方向，即主、被叫枚举。
// * 应用程序可根据此判断呼叫时的通话方向。
// */
//typedef enum : NSUInteger {
//    CubeCallDirectionOutgoing,                              // 主叫呼出，呼叫方向为呼出。
//    CubeCallDirectionIncoming,                              // 被叫呼入，呼叫方向为呼入。
//} CubeCallDirection;

#endif /* CubeCallEnum_h */
