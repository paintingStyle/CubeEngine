//
//  CubeMediaService.h
//  CubeEngine
//
//  Created by Zhu Guoqiang on 15/6/10.
//  Copyright (c) 2014-2016 Cube Team. All rights reserved.
//

#ifndef CubeMediaService_h
#define CubeMediaService_h

#import <Foundation/Foundation.h>
#import <Photos/Photos.h>
#include "CubeMediaProbe.h"
#include "CubePrerequisites.h"
#import "CubeCallType.h"
#import "CubeMediaType.h"

#pragma mark - call control service
@protocol CubeCallControlService <NSObject>

@optional
// 获取通话状态
-(BOOL)isCalling;

//-(CubeLocalVideoView *)getLocalView;

/**
 多人视频获取通话target 目标标识号
 @disuss *** 仅限于多人视频获取方式, 一对一通话target为对端cubeid, 多人语音容屏会议为conferenceId ***
 @param conferenceId conferenceId
 @param cubeId cubeId
 @param isScreen isScreen
 @return 通话target 目标标识号
 */
- (NSString *)generateConferenceCallTargetWithConfernceId:(NSString *)conferenceId cubeId:(NSString *)cubeId isScreen:(BOOL)isScreen;

/**
 获取指定target的远程视图

 @param target 目标标识号
 @return 远程视图
 */
-(UIView *)getRemoteViewForTarget:(NSString *)target;

/**
 获取指定本地视图

 @param target 本地视图target
 @return 本地视图
 */
- (UIView *)getLocalViewForTarget:(NSString *)target;

/**
 获取当前通话类型的通话
 
 @param types 通话类型
 @return 所有通话
 */
- (NSArray *)currentCallWithCallType:(CubeCallType )types;

/**
 获取当前通话类型的通话
 
 @param types 通话类型
 @return 所有通话target
 */
- (NSArray <NSString *> *)currentCallTargets:(CubeCallType )types;

/**
获取当前所有通话

@return 所有通话
*/
- (NSString *)currentCallTarget;

/**
 获取指定媒体类型是否已开启
 
 @param mediaType 媒体类型
 @param target 通话对端cubeID
 @return 是否开启
 */
-(BOOL)enableMediaType:(CubeMediaType)mediaType forTarget:(NSString *)target;

/**
 控制指定媒体类型的开关
 
 @param mediaType 媒体类型
 @param enable 开启|关闭
 @param target 通话对端cubeId
 */
-(void)setMediaType:(CubeMediaType)mediaType enable:(BOOL)enable forTarget:(NSString *)target;

@end


@interface CubeMediaService : NSObject<CubeCallControlService>

/** 即时媒体状态委派。 */
@property (nonatomic, weak) id<CubeMediaServiceDelegate> mediaServiceDelegate;

/** 录制委派。 */
@property (nonatomic, weak) id<CubeRecordDelegate> recordDelegate;

/** 播放委派。 */
@property (nonatomic, weak) id <CubePlayDelegate> playDelegate;

/** 录制视频视图。 */
@property (nonatomic,strong,readonly) CubeRecordVideoView *recordView;

/** 播放视频视图。 */
@property (nonatomic,strong,readonly) CubePlayVideoView *playView;

/** 录制音频时长。 */
@property (nonatomic,assign, readonly) long long audioDuration;

/** audioRecorder **/
@property (strong, nonatomic) AVAudioRecorder *audioRecoder;

/** avPlayer **/
@property (strong, nonatomic) AVAudioPlayer *audioPlayer;

/** 录制视频时长。 */
@property (assign ,nonatomic, readonly) long long videoDuration;

/** 横竖屏方向  */
@property (nonatomic, assign) AVCaptureVideoOrientation deviceOrientation;

@property (nonatomic, assign) CGFloat effectiveScale;

@property (nonatomic, assign) CGFloat beginGestureScale;

@property (nonatomic, assign) BOOL shouldScale;

/** 判断扬声器是否开启。
 *
 * @return 已关闭，则返回 <code>NO</code>, 否则返回 <code>YES</code> 。
 */
- (BOOL)speakerEnabled;

/** 打开内置扬声器。
 *
 * 在通话时，调用该方法后可以打开内置扬声器。
 */
- (void)openSpeaker;

/** 关闭内置扬声器。
 *
 * 在通话时，调用该方法后可以关闭内置扬声器。
 */
- (void)closeSpeaker;

/** 判断本地音频是否已关闭。
 *
 * @return 已关闭，则返回 <code>YES</code>, 否则返回 <code>NO</code> 。
 */
- (BOOL)isVoiceEnabled;

/** 打开本地音频。
 *
 * 在通话时，调用该方法后可以打开本地音频。
 */
- (void)openVoice;

/** 关闭本地音频。
 *
 * 在通话时，调用该方法后可以关闭本地音频。
 */
- (void)closeVoice;

/** 判断本地视频是否已关闭。
 *
 * @return 已关闭，则返回 <code>YES</code>, 否则返回 <code>NO</code> 。
 */
- (BOOL)isVideoEnabled;

/** 打开本地视频。
 *
 * 在通话时，调用该方法后可以打开本地视频。
 */
- (void)openVideoWithConsult:(BOOL)consult;

/** 关闭本地视频。
 *
 * 在通话时，调用该方法后可以关闭本地视频。
 */
- (void)closeVideoWithConsult:(BOOL)consult;

/** 切换摄像头。
 *
 * 在通话时，调用该方法后可以切换摄像头。
 */
- (void)switchCamera;

/** 添加媒体探针。
 *
 * @param probe 媒体探针实例。
 */
- (void)addMediaProbe:(CubeMediaProbe *)probe;

/** 删除媒体探针。
 *
 * @param probe 媒体探针实例。
 */
- (void)removeMediaProbe:(CubeMediaProbe *)probe;

/** 是否正在录制音频
 */
- (BOOL)isVoiceRecording;

/** 启动语音录制。
 *
 * @param duration 指定本次录音的最大时长, 1 ~ 60s。
 * @return 如果录音被启动则返回 <code>YES</code> ，否则返回 <code>NO</code> 。
 */
- (BOOL)startRecordVoice:(long)duration;

/** 停止语音录制。
 *
 * @return 如果录音被停止则返回 <code>YES</code> ，否则返回 <code>NO</code> 。
 */
- (BOOL)stopRecordVoice;

/** 取消语音录制。
 */
- (void)cancelRecordVoice;

/** 获取录制的语音文件地址。
 */
- (NSString *)getVoiceFilePath;

/** 播放录制的语音
 *
 * @param path 录制的语音文件路径
 */
- (void)playRecordVoice:(NSString *)path;

/** 停止播放录制的语音
 */
- (void)stopPlayRecordVoice;

/// \cond
//! 启动视频录制。(自定义)

/** 加载视频录制界面
 *
 * @param customView 自定义视图
 * @param frame 录制界面的位置大小
 * @param camera 前/后置摄像头，1为后置、2为前置
 * @return 如果成功则返回 <code>YES</code> ，否则返回 <code>NO</code>
 */
- (BOOL)loadRecordVideoView:(UIView *)customView WithFrame:(CGRect)frame andCamera:(int)camera;

/** 启动视频录制
 *
 * @param duration 指定本次录制视频的最大时长, 1 ~ 30s。
 * @return 如果视频录制成功启动则返回 <code>YES</code> ，否则返回 <code>NO</code> 。
 */
- (BOOL)startRecordVideo:(NSTimeInterval)duration;

/** 停止视频录制。
 * 默认转码成通用格式
 *
 * @return 如果视频录制停止则返回 <code>YES</code> ，否则返回 <code>NO</code> 。
 */
- (BOOL)stopRecordVideo;

/**
 停止录制视频
 
 @param needConvert 是否需要转码
 @return 如果视频录制停止则返回 <code>YES</code> ，否则返回 <code>NO</code>
 */
- (BOOL)stopRecordVideoWithNeedConvert:(BOOL)needConvert;

/** 取消视频录制。
 */
- (void)cancelRecordVideo;

/** 删除视频文件。
 */
- (void)removeVideoFile;

/** 切换摄像头。
 */
- (void)switchRecordCamera;

/** 是否正在录制视频
 *
 * @return 如果正在录制则返回 <code>YES</code> ，否则返回 <code>NO</code>
 */
- (BOOL)isVideoRecording;

/** 获取录制的视频文件地址
 */
- (NSString *)getVideoFilePath;

/** 获取录制的视频缩略图地址
 */
- (NSString *)getVideothumbImagePath;

/** 播放录制的视频
 *
 * @param frame 播放视频窗口的位置大小
 * @param videoFilePath 播放视频的文件路径
 * @return 如果播放成功则返回 <code>YES</code> ，否则返回 <code>NO</code>
 */
- (BOOL)playVideoView:(UIView *)playView andFrame:(CGRect)frame andVideoFilePath:(NSString *)videoFilePath;

/** 结束播放
 *
 * @return 如果停止播放成功则返回 <code>YES</code> ，否则返回 <code>NO</code>
 */
- (BOOL)stopPlayVideo;

/** 录制视频（默认）
 *
 * @param name 视频接收者
 * @parma duration 视频最大时长
 * @parma camera 前/后置摄像头，1为后置、2为前置
 */
- (BOOL)loadRecordVideoViewWithReceiverName:(NSString *)name andDuration:(int)duration andCamera:(int)camera;

/** 播放视频的URL
 */
- (void)loadPlayVideoViewWithPlayURL:(NSString *)url;

/** 播放录制的视频
 *
 * @param path 录制的视频文件路径
 */
//- (void)playRecordedVideo:(NSString *)path;

/** 停止播放录制的视频
 */
- (void)stopPlayRecordedVideo;


/**
 获取媒体通话质量
 
 @return 获取媒体通话质量枚举类型
 */
- (CubeMediaQuality)getMediaQuality;


/**
 开启通话质量检测任务,检测任务会在当前通话结束后自动停止
 
 @param callBack 通话质量回掉
 */
-(void)checkMeadiaQuality:(void(^)(CubeMediaQuality quality))callBack;

/**
 拍照
 
 @param completionHandler 回调
 */
- (void)takePictureCompletionHandler:(void (^ )(UIImage *image, NSData *jpegData ,NSDictionary *attachments))completionHandler;


/**
 当前设备方向
 
 @return 方向
 */
- (AVCaptureVideoOrientation)getDeviceOrientation;


/**
 自动对焦
 
 @param point 焦点
 */
- (void)focusAtPoint:(CGPoint)point;

/**
 滑动缩放
 
 @param slideScale 缩放比例 0~1缩小 1~10放大
 */
- (void)slideToScale:(CGFloat)slideScale;

@end

#endif
