//
//  CubeMediaProbe.h
//  CubeEngine
//
//  Created by Zhu Guoqiang on 15/7/28.
//  Copyright (c) 2015-2016 Cube Team. All rights reserved.
//

#ifndef CubeMediaProbe_h
#define CubeMediaProbe_h
#import <Foundation/Foundation.h>
#import "CubePrerequisites.h"

/** 媒体层探针接口。
 *
 * 媒体层探针用于实时监测媒体设备的工作状态。
 *
 */
@interface CubeMediaProbe : NSObject

/** 当远端视频帧率数据刷新时该方法被调用。
 */
- (void)onRemoteVideo:(CubeMediaService *)mediaService withFps:(int)fps withAvgFps:(int)avgFps;

/** 当探针检测到帧率明显降低时该方法被调用。
 */
- (void)onFrameRateWarning:(CubeMediaService *)mediaService withFps:(int)curFps andAvgFps:(int)avgFps;

/** 当探针检测到帧率恢复时该方法被调用。
 */
- (void)onFrameRateRecovering:(CubeMediaService *)mediaService withFps:(int)curFps andAvgFps:(int)avgFps;

/** 当探针检测到对方视频关闭时该方法被调用。
 */
- (void)onVideoClosed;

/**
 通话质量探测

 @param quality 通话质量探测类型
 */
- (void)onMediaProbeQuality:(CubeMediaQuality)quality;

@end

#endif
