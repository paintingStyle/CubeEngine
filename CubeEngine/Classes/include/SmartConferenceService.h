//
//  SmartConferenceService.h
//  CubeEngine
//
//  Created by Ashine on 2020/1/9.
//  Copyright © 2020 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CubePrerequisites.h"

NS_ASSUME_NONNULL_BEGIN


//////// conference call back
typedef void(^SmartConferenceCallBack)(SmartConference *conference);
typedef void(^SmartConferenceListCallBack)(NSArray <SmartConference *> *list);
//////// error call back
typedef void(^SmartErrorCallBack)(int code,NSString *desc);
//////// member call back
typedef void(^SmartMemberCallBack)(SmartMember * member);
typedef void(^SmartMemberListCallBack)(NSArray <SmartMember *> *list);
/////// control call back
typedef void(^SmartControlCallBack)(SmartConference *conference,SmartMemberControl *control);
//typedef void(^SmartMediaCallBack)(SmartMediaData *data);


@interface SmartConferenceService : NSObject


/**
 会议服务代理
 */
@property (nonatomic, weak) id<SmartConferenceServiceDelegate> smartConferenceServiceDelegate;

#pragma mark - 会议控制通知

/**
 * 订阅会控通知
 *
 * @param conferenceId
 * @param callback
 */
-(void)subscribe:(NSString *)conferenceId completion:(SmartConferenceCallBack)callback failure:(SmartErrorCallBack)failure;

/**
 * 取消会控通知
 *
 * @param conferenceId
 * @param callback
 */
-(void)unsubscribe:(NSString *)conferenceId completion:(SmartConferenceCallBack)callback failure:(SmartErrorCallBack)failure;



#pragma mark - 会议基本操作
/**
 * 创建会议
 *
 * @param config   会议配置
 * @param callback
 */
-(void)create:(SmartConferenceConfig *)config completion:(SmartConferenceCallBack)callback failure:(SmartErrorCallBack)failure;

/**
 * 销毁会议
 *
 * @param conferenceId 会议Id
 * @param callback
 */
-(void)destroy:(NSString *)conferenceId completion:(SmartConferenceCallBack)callback failure:(SmartErrorCallBack)failure;

/**
 * 加入会议
 *
 * @param conferenceId
 * @param callback
 */
-(void)join:(NSString *)conferenceId completion:(SmartConferenceCallBack)callback failure:(SmartErrorCallBack)failure;

/**
 * 退出会议
 *
 * @param conferenceId
 * @param callback
 */
-(void)quit:(NSString *)conferenceId completion:(SmartConferenceCallBack)callback failure:(SmartErrorCallBack)failure;

/**
 * 邀请会议成员
 *
 * @param conferenceId 会议Id
 * @param members      被邀请列表
 * @param callback
 */
-(void)invite:(NSString *)conferenceId members:(NSArray <NSString *> *)members completion:(SmartConferenceCallBack)callback failure:(SmartErrorCallBack)failure;

/**
 * 回应邀请
 *
 * @param conferenceId 会议ID
 * @param invitor      邀请者ID
 * @param agreed       是否同意
 * @param reason       原因
 * @param callback     回调
 */
-(void)respondInvite:(NSString *)conferenceId invitor:(NSString *)invitor agreed:(BOOL)agreed reason:(NSString *)reason completion:(SmartConferenceCallBack)callback failure:(SmartErrorCallBack)failure;


/**
 * 举手
 *
 * @param conferenceId 会议ID
 * @param reason       举手原因
 * @param callback
 */
-(void)handUp:(NSString *)conferenceId reason:(NSString *)reason completion:(SmartConferenceCallBack)callback failure:(SmartErrorCallBack)failure;


/**
 * 回应举手
 *
 * @param conferenceId 会议ID
 * @param handup       举手者ID
 * @param agreed       是否同意
 * @param reason       原因
 * @param callback     回调
 */
-(void)respondHandUp:(NSString *)conferenceId handup:(NSString *)handup agreed:(BOOL)agreed reason:(NSString *)reason completion:(SmartConferenceCallBack)callback failure:(SmartErrorCallBack)failure;

#pragma mark - 媒体监听

/**
 通话媒体质量检测

 @param listen 是否开启通话检测
 @param streamTarget 媒体通话流标识
 */
- (void)mediaQualityCheck:(BOOL)listen streamTarget:(NSString *)streamTarget;

#pragma mark - 本地媒体控制
/**
 * 设置视频是否可用 （仅控制自己音频通话时可用）
 *
 * @param enable
 * @param callback
 */
-(void)setVideoEnabled:(BOOL)enabled completion:(SmartControlCallBack)callback failure:(SmartErrorCallBack)failure;


/**
 * 判断视频是否可用 （仅控制自己音频通话时可用）
 *
 * @return
 */
-(BOOL)isVideoEnabled;


/**
 * 设置音频是否可用
 *
 * @param enable
 */
-(void)setAudioEnabled:(BOOL)enabled completion:(SmartControlCallBack)callback failure:(SmartErrorCallBack)failure;


/**
 * 判断音频是否可用
 *
 * @return
 */
-(BOOL)isAudioEnabled;


/**
 * 扬声器开启与关闭（仅控制自己音频通话时可用）
 *
 * @param enable
 */
-(void)setSpeakerEnabled:(BOOL)enabled;


/**
 * 扬声器是否可用 （仅获取自己音频通话时可用）
 */
-(BOOL)isSpeakerEnabled;


/**
 * 切换摄像头（仅控制自己音频通话时可用）
 */
-(void)switchCamera;



#pragma mark - 会议及成员信息查询
/**
 * 获取会议信息
 *
 * @param conferenceId
 * @param callback
 */
-(void)queryConference:(NSString *)conferenceId completion:(SmartConferenceListCallBack)callback failure:(SmartErrorCallBack)failure;

/**
 * 获取会议信息
 *
 * @param cubeId   自己的cube号
 * @param types    需要查询的会议类型
 * @param callback 监听器
 */
-(void)queryConference:(NSString *)cubeId types:(NSArray *)types completion:(SmartConferenceListCallBack)callback failure:(SmartErrorCallBack)failure;

/**
 * 查询成员信息
 *
 * @param conferenceId
 * @param callback
 */
-(void)queryMembers:(NSString *)conferenceId completion:(SmartMemberListCallBack)callback failure:(SmartErrorCallBack)failure;

/**
 * 查询成员信息
 * @param cubeId   待查询的cube号
 * @param callback
 */
-(void)getMember:(NSString *)cubeId completion:(SmartMemberCallBack)callback failure:(SmartErrorCallBack)failure;


#pragma mark - 通话视图获取

/**
 根据通话标识获取通话视图 (通话标识从返回的流信息中获取)

 @param target 标识
 @return 视图
 */
-(UIView *)getViewForTarget:(NSString *)target;



@end

NS_ASSUME_NONNULL_END
