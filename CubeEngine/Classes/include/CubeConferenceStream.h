//
//  CubeConferenceStream.h
//  CubeEngine
//
//  Created by Ashine on 2019/11/5.
//  Copyright © 2019 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
/*
 sfu会议类型 流模型
 */


///////////// sfu type //////////////

@class Conference;
NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    CubeStreamTypeCamera,
    CubeStreamTypeScreen,
    /*expand*/
} CubeStreamType;

///////////////////////////

@interface CubeConferenceStream : NSObject

/**
 会议id
 */
@property (nonatomic,copy) NSString *conferenceId;

/**
 cubeId
 */
@property (nonatomic,copy) NSString *cubeId;

/**
 流id
 */
@property (nonatomic,assign) long long streamId;

/**
 流标识(用于获取本地流视图)
 */
@property (nonatomic,copy) NSString *streamTarget;

/**
 发布平台
 */
@property (nonatomic,copy) NSString *platform;

/**
 视频开关
 */
@property (nonatomic,assign) BOOL  videoEnabled;

/**
 音频开关
 */
@property (nonatomic,assign) BOOL  audioEnabled;

/**
 是否本地流
 */
@property (nonatomic,assign) BOOL isLocalStream;

/**
 流类型
 */
@property (nonatomic,assign) CubeStreamType streamType;

/**
 会议对象
 */
@property (nonatomic,strong) Conference *conference;

@end

NS_ASSUME_NONNULL_END
