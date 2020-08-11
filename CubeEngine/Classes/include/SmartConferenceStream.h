//
//  SmartConferenceStream.h
//  CubeEngine
//
//  Created by Ashine on 2020/1/9.
//  Copyright © 2020 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SmartConferenceEnum.h"
#import "CubeJSONObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface SmartConferenceStream : NSObject <CubeJSONObject>
//会议ID
@property (nonatomic,copy) NSString *conferenceId;
//成员ID
@property (nonatomic,copy) NSString *cubeId;
//流Key
@property (nonatomic,copy) NSString *streamKey;
//平台
@property (nonatomic,copy) NSString *platform;
//开启视频
@property (nonatomic,assign) BOOL video;
//开启音频
@property (nonatomic,assign) BOOL audio;
//是否本地
@property (nonatomic,assign) BOOL local;
//流类型
@property (nonatomic,assign) SmartStreamType streamType;

/**
 流标识(用于获取本地流视图)(通过SmartConferenceService 中api获取)
 */
@property (nonatomic,copy) NSString *streamTarget;

/**
 是否本地流
 */
@property (nonatomic,assign) BOOL isLocal;

@end

NS_ASSUME_NONNULL_END
