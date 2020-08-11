//
//  CubeConferenceService.h
//  CubeEngine
//
//  Created by Zhu Guoqiang on 16/2/19.
//  Copyright (c) 2014-2016 Cube Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CubePrerequisites.h"
#import "CubeConferenceConfig.h"

typedef void(^QueryAllComferenceHandler)(int count,int index,NSArray *conferences);

/**
 会议协议
 */
@interface CubeConferenceService :NSObject

/**
 会议服务代理
 */
@property (nonatomic, weak) id<CubeConferenceServiceDelegate> conferenceServiceDelegate;

/**
 申请会议

 @param groupName 组号
 @param expired 有效时间
 @return 是否处理成功
 */
- (BOOL)applyConference:(NSString *)groupName andExpired:(long long)expired DEPRECATED_MSG_ATTRIBUTE("use applyConference: instead");


/**
 申请会议

 @param groupId 群组id
 @param mergeScreen 是否合并屏幕
 @param expiredTime 有效时间
 @return 是否处理成功
 */
- (BOOL)applyConferenceWithGroupId:(NSString *)groupId andMergeScreen:(BOOL)mergeScreen andExpiredTime:(long long)expiredTime DEPRECATED_MSG_ATTRIBUTE("use applyConference: instead");


/**
 申请会议

 @param cubeIds 用户ID列表
 @param mergeScreen 是否合并屏幕
 @param expiredTime 有效时间
 @return 是否处理成功
 */
- (BOOL)applyConferenceWithCubeIds:(NSArray *)cubeIds andMergeScreen:(BOOL)mergeScreen andExpiredTime:(long long)expiredTime DEPRECATED_MSG_ATTRIBUTE("use applyConference: instead");


/**
 申请会议

 @param groupId 群组号
 @param cubeIds 用户ID
 @param mergeScreen 是否融屏
 @param expiredTime 有效时间
 @param forceCreate 是否强制创建
 @return 是否处理成功
 */
- (BOOL)applyConferenceWithGroupid:(NSString *)groupId andCubeIds:(NSArray *)cubeIds andMergeScreen:(BOOL)mergeScreen andExpiredTime:(long long)expiredTime andForceCreate:(BOOL)forceCreate DEPRECATED_MSG_ATTRIBUTE("use applyConference: instead");


/**
 申请会议
 
 forceCreate为true解绑之前的会议重新创建新会议，如果force为false并且群主下已存在绑定的会议，那么ack 状态码1500表示会议已存在。并且在data中返回已创建好的Conference数据。
 expired 如果expired为0则在最后一个人退出会议时，服务器主动关闭会议。
 group和cubeIds同时存在时，用cubeIds的成员创建会议，并绑定到group。如果cubeIds没有数据，或数据为空，则使用group的成员创建会议，并将会议绑定到group，没有传group就根据传的cubeIds创建一个新的group然后绑定。
 
 @param groupId 群组号
 @param cubeIds 用户ID列表
 @param type 会议类型
 @param MaxMember 允许的用户最大数量
 @param mergeScreen 是否融屏
 @param expiredTime 过期时间
 @param forceCreate 是否强制创建
 @return 是否处理成功
 */
- (BOOL)applyConferenceWithGroupid:(NSString *)groupId andCubeIds:(NSArray *)cubeIds andConferenceType:(ConferenType)type andMaxMember:(int)MaxMember andMergeScreen:(BOOL)mergeScreen andExpiredTime:(long long)expiredTime andForceCreate:(BOOL)forceCreate DEPRECATED_MSG_ATTRIBUTE("use applyConference: instead");


/**
 申请会议

 @param conferenceConfig 申请会议配置
 @return 是否处理成功
 */
- (BOOL)applyConference:(CubeConferenceConfig *)conferenceConfig;


/**
 加入会议 默认开启视频
 
 @param conferenceId 会议ID
 @return 是否处理成功
 */
- (BOOL)joinConference:(NSString *)conferenceId;


/**
 加入会议
 @discuss (默认不强制加入)
 @param conferenceId 会议ID
 @param videoEnable 是否开启视频
 @return 是否处理成功
 */
- (BOOL)joinConference:(NSString *)conferenceId withVideoEnable:(BOOL)videoEnable;


/**
 申请加入会议
 
 @param conferenceId 会议ID
 @param videoEnable 是否开启视频
 @param force 是否强制加入
 @return 是否处理成功
 */
- (BOOL)applyJoinConference:(NSString *)conferenceId withVideoEnable:(BOOL)videoEnable force:(BOOL)force;


/**
 邀请用户加入会议
 
 @param cubeIds 用户ID列表
 @param conferenceId 会议ID
 @return 是否处理成功
 */
- (BOOL)inviteUsers:(NSArray<NSString *> *)cubeIds intoConference:(NSString *)conferenceId;


/**
 拒绝会议
 
 @param conferenceId 会议ID
 @return 是否处理成功
 */
- (BOOL)rejectConference:(NSString *)conferenceId;


/**
 退出会议
 
 @param conferenceId 会议ID
 @return 是否处理成功
 */
- (BOOL)quitConference:(NSString *)conferenceId;


/**
 结束会议

 @param conferenceId 会议ID
 @return 是否处理成功
 */
- (BOOL)closeConference:(NSString *)conferenceId;


/**
 批量获取指定会议的参会人员的视频快照

 @param conferenceId 会议Id
 @param members 参会人员
 @return 是否处理成功
 */
- (NSDictionary *)getCapturedCameraImages:(NSString *)conferenceId withMembers:(NSArray *)members;


/**
 获取指定会议的参会人员的视频快照

 @param conferenceId 会议Id
 @param member 参会人员
 @return 是否处理成功
 */
- (NSDictionary *)getCapturedCameraImage:(NSString *)conferenceId withMember:(NSString *)member;


#pragma mark - conference control

/**
 设置成员禁听

 @param conferenceId 会议ID
 @param memberName 成员ID
 @param deaf 是否禁听，<code>YES</code> 表示禁听
 @return 是否处理成功
 */
- (BOOL)setMemberDeaf:(NSString *)conferenceId withMember:(NSString *)memberName deaf:(BOOL)deaf;


/**
 设置成员静音

 @param conferenceId 会议ID
 @param memberName 成员ID
 @param mute 是否静音，<code>YES</code> 表示静音
 @return 是否处理成功
 */
- (BOOL)setMemberMute:(NSString *)conferenceId withMember:(NSString *)memberName mute:(BOOL)mute;


/**
 置成员可视

 @param conferenceId 会议ID
 @param memberName 成员ID
 @param watch 是否可视，<code>YES</code> 表示可视
 @return 是否处理成功
 */
- (BOOL)setMemberWatch:(NSString *)conferenceId withMember:(NSString *)memberName watch:(BOOL)watch;


/**
 踢出会议

 @param conferenceId 会议ID
 @param memberName 成员ID
 @return 是否处理成功
 */
- (BOOL)kickMember:(NSString *)conferenceId withMember:(NSString *)memberName;


/**
 增加主持人

 @param conferenceId 会议ID
 @param memberName 主持人ID
 @return 是否处理成功
 */
- (BOOL)addPresenter:(NSString *)conferenceId withMember:(NSString *)memberName;


/**
 删除主持人

 @param conferenceId 会议ID
 @param memberName 主持人ID
 @return 是否处理成功
 */
- (BOOL)removePresenter:(NSString *)conferenceId withMember:(NSString *)memberName;


/**
 变更主讲人。每个会议中，有且仅有一个主讲人
 
 @param conferenceId 会议ID
 @param memberName 成员ID
 @return 是否处理成功
 */
- (BOOL)changeSpeaker:(NSString *)conferenceId withMember:(NSString *)memberName;


#pragma mark - media control
/**
 打开或关闭音频
 
 @param enable 开启或关闭
 @param conferenceId 会议ID
 @return 设置是否成功
 */
- (BOOL)setAudioEnable:(BOOL)enable withConferenceId:(NSString *)conferenceId;

/**
 打开或关闭视频
 
 @param enable 开启或关闭
 @param conferenceId 会议ID
 @return 设置是否成功
 */
- (BOOL)setVideoEnable:(BOOL)enable withConferenceId:(NSString *)conferenceId;


#pragma mark - query

/**
 查询会议详情
 
 @param conferenceId 会议ID
 @param completeHandler 完成回掉
 @return 引擎是否处理成功
 */
-(BOOL)queryConference:(NSString *)conferenceId withCompleteHandler:(void (^)(Conference *conference,CubeErrorInfo *error)) completeHandler;


/**
 查询会议

 @param cubeId 用户ID
 @param types 会议类型 多个会议类型使用‘|’合并 e.g.: ConferenTypeVoiceCall|ConferenTypeVideoCall
 @param completeHandler 查询会议成功的回掉
 @return 是否处理成功
 */
- (BOOL)queryConferencesWithUserId:(NSString *)cubeId andConferenceTypes:(int)types andComplteHandler:(QueryAllComferenceHandler)completeHandler;


@end
