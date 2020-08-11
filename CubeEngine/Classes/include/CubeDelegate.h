//
//  CubeDelegate.h
//  Cube Engine
//
//  Created by Xu Jiangwei on 14/9/28.
//  Copyright (c) 2014-2016 Cube Team. All rights reserved.
//

#ifndef CubeDelegate_h
#define CubeDelegate_h

#import "CubePrerequisites.h"

#pragma mark - 注册相关
/**
 注册状态委派
 通过注册状态委派来监听引擎注册状态的变化。
 */
@protocol CubeRegistrationDelegate <NSObject>
@optional


/**
 当注册流程正在处理时此方法被回调
 
 @param session 本次注册流程的会话对象实例
 */
- (void)onRegistrationProgress:(CubeSession *)session;


/**
 当注册成功时此方法被回调
 
 @param session 本次注册流程的会话对象实例
 */
- (void)onRegistrationOk:(CubeSession *)session;


/**
 当注册状态被清除时此方法被回调
 
 @param session 本次注册流程的会话对象实例
 */
- (void)onRegistrationCleared:(CubeSession *)session;


/**
 当注册流程发生错误时此方法被回调
 
 @param session 本次注册流程的会话对象实例
 @param errorCode 错误码
 */
- (void)onRegistrationFailed:(CubeSession *)session andErrorCode:(CubeStateCode)errorCode;


/**
 当注册状态实时维护进行网络数据心跳时此方法被回调
 
 @param session 本次注册流程的会话对象实例
 */
- (void)onHeartbeat:(CubeSession *)session;


/**
 在其他设备上线时回调
 
 @param session session
 @param device fromDevice
 @param deviceInfoArray onLinesDevice
 */
- (void)onDeviceOnline:(CubeSession *)session withDevice:(CubeDeviceInfo *)device withOnLines:(NSArray *)deviceInfoArray;


/**
  在其他设备下线时回调
 
 @param session session
 @param device fromDevice
 @param deviceInfoArray offLinesDevice
 */
- (void)onDeviceOffline:(CubeSession *)session withDevice:(CubeDeviceInfo *)device withOffLines:(NSArray *)deviceInfoArray;

@end


#pragma mark - 一对一通话相关

/**
 呼叫状态委派
 通过指定呼叫状态委派来监听呼叫状态，从而发起对应的操作
 此委派可以收到的监听事件涵盖了呼叫会话的所有环节
 */
@protocol CubeCallServiceDelegate <NSObject>
@optional


/**
 当引擎发起或收到新呼叫时此方法被回调
 
 @param callDirection 本次呼叫的方向
 @param session 本次呼叫的会话
 */
- (void)onNewCall:(CubeCallDirection)callDirection session:(CubeSession *)session;

/**
 当引擎呼叫的对方正在呼叫自己时，回掉此方法，提示反转通话，引擎会自动应答对方的通话
 
 @param session 呼叫会话
 */
- (void)onReverseCall:(CubeSession *)session;

/**
 有未接听的通话
 
 @param isVideo 是否是视频通话
 @param cubeId 呼叫人ID
 */
- (void)onNoAnsweredCall:(BOOL)isVideo from:(NSString *)cubeId;

/**
 当呼叫正在处理时此方法被回调
 
 @param session 本次呼叫的会话
 */
- (void)onInProgress:(CubeSession *)session;


/**
 当对方振铃时此方法被回调
 
 @param session 本次呼叫的会话
 */
- (void)onCallRinging:(CubeSession *)session;


/**
 当呼叫已经接通时此方法被回调
 
 @param session 本地呼叫的会话
 */
- (void)onCallConnected:(CubeSession *)session;


/**
 当呼叫结束时此方法被回调
 
 @param session 本次呼叫的会话
 */
- (void)onCallEnded:(CubeSession *)session;


/**
 当呼叫过程发生错误时此方法被回调
 
 @param session 本次呼叫的会话
 @param errorCode 发生错误时导致呼叫失败的错误码
 */
- (void)onCallFailed:(CubeSession *)session errorCode:(CubeStateCode)errorCode;

@end

#pragma mark - 媒体相关
/**
 实时媒体服务状态委派
 通过实现媒体服务委派可以监听到媒体状态
 */
@protocol CubeMediaServiceDelegate <NSObject>
@optional


/**
 当呼叫过程中媒体状态发生改变时此方法被回调
 
 @param state 媒体状态
 */
- (void)onMediaServiceStateChanged:(CubeMediaState)state;


/**
 当相机麦克风权限开启失败此方法被回调
 
 @param error 错误信息
 */
- (void)onMediaServiceAuthFailedWithError:(CubeErrorInfo *)error;

@end


/**
 通过实现记录状态监听器接口，可以监听语音、视频记录器工作时的状态
 根据不同的状态进行必要的数据处理
 */
@protocol CubeRecordDelegate <NSObject>
@optional


/**
 当音视频录制开始时此方法被回调
 
 @param type 录制类型
 */
- (void)onRecordStarted:(CubeRecordType)type;


/**
 当音视频录制停止时此方法被回调
 
 @param type 录制类型
 */
- (void)onRecordStoped:(CubeRecordType)type;


/**
 当音视频录制发生错误时此方法被回调
 
 @param type 录制类型
 @param error 录制失败错误信息
 */
- (void)onRecordFailed:(CubeRecordType)type error:(CubeErrorInfo *)error;


/**
 onReadyForDisplay
 
 @param type video时使用
 */
- (void)onReadyForDisplay:(CubeRecordType)type;
@end



/**
 音视频播放委派
 通过音视频播放委派可以监听音视频播放操作
 */
@protocol CubePlayDelegate <NSObject>

@optional


/**
 当音视频播放开始时此方法被回调
 
 @param type 文件类型
 */
- (void)onPlayStarted:(CubeRecordType)type;


/**
 当音视频播放停止时此方法被回调
 
 @param type 文件类型
 */
- (void)onPlayStoped:(CubeRecordType)type;


/**
 当音视频播放错误时此方法被回调
 
 @param type 文件类型
 @param error 失败的错误码
 */
- (void)onPlayFailed:(CubeRecordType)type error:(CubeErrorInfo *)error;

@end


#pragma mark - 群组相关
/**
 群组委派
 通过实现群组委派可以监听到群组的操作
 */
@protocol CubeGroupServiceDelegate <NSObject>
@optional


/**
 当创建组成功时回调
 
 @param groupContext 组的相关信息
 */
- (void)onGroupCreated:(GroupContext *)groupContext;


/**
 当组销毁时回调
 
 @param groupContext 组的相关信息
 */
- (void)onGroupDeleted:(GroupContext *)groupContext;


/**
 当向组添加成员时回调
 
 @param groupContext 组的相关信息
 @param members 所有成员
 @param addedMembers 新添加成员
 */
- (void)onMemberAdded:(GroupContext *)groupContext andMembers:(NSArray *)members andAddedMembers:(NSArray *)addedMembers;


/**
 当向组移除成员时回调
 
 @param groupContext 组的相关信息
 @param members 所有成员
 @param removeMembers 移除的成员
 */
- (void)onMemberRemoved:(GroupContext *)groupContext andMembers:(NSArray *)members andRemoveMembers:(NSArray *)removeMembers;


/**
 当组操作失败时回调
 
 @param errorCode 错误码
 */
- (void)onGroupFailed:(GroupContext *)groupContext andErrorCode:(CubeStateCode)errorCode;


/**
 当组添加管理员时回调
 
 @param groupContext 群组相关信息上下文
 @param master id号
 */
- (void)onMasterAdded:(GroupContext *)groupContext withAddedMaster:(NSString *)master;


/**
 当组移除管理员时回调
 
 @param groupContext 群组相关信息上下文
 @param master id号
 */
- (void)onMasterRemoved:(GroupContext *)groupContext withRemovedMaster:(NSString *)master;


/**
 修改群组昵称
 
 @param groupContext 群组相关信息上下文
 */
- (void)onGroupNameChanged:(GroupContext *)groupContext;

@end



#pragma mark - 会议相关
/**
 会议委派
 通过实现会议委派可以监听到会议的操作
 */
@protocol CubeConferenceServiceDelegate <NSObject>

@optional


/**
 当申请会议成功时回调
 
 @param conference 会议信息
 */
- (void)onConferenceApplied:(Conference *)conference;


/**
 已加入会议
 
 @param conference 会议信息
 */
- (void)onConferenceJoined:(Conference *)conference;


/**
 邀请参加会议回掉
 
 @param conference 邀请参加的会议
 @param successList 成功的用户ID列表
 @param failureList 失败的用户ID列表
 @param vTooLow 版本过低用户ID列表
 @param busy 用户正忙ID列表
 */
- (void)onConferenceInviteResponded:(Conference *)conference withSucessList:(NSArray *)successList andFailureList:(NSArray *)failureList vTooLow:(NSArray *)vTooLow busy:(NSArray *)busy;

/**
 正在连接会议
 
 @param conference 会议
 */
- (void)onConnecteingConference:(Conference *)conference;


/**
 连接会议成功
 
 @param conference 会议
 */
- (void)onConnectedToConference:(Conference *)conference;


/**
 当会议关闭时回调
 
 @param conference 会议
 */
- (void)onConferenceClosed:(Conference *)conference;


/**
 当会议更新时回调
 
 @param conference 会议
 @param actions 操作动作集合
 */
- (void)onConferenceUpdated:(Conference *)conference withActions:(NSArray<MemberAction *> *)actions;


/**
 当会议成员talking状态更新时回调
 @param conference 会议
 */
- (void)onConferenceTalkingUpdated:(Conference *)conference;

/**
 收到会议邀请
 
 @param conference 会议
 @param cubeId 邀请人
 */
- (void)onInviteIntoConference:(Conference *)conference from:(NSString *)cubeId;


/**
 会议结束
 
 @param conference 会议
 */
- (void)onConferenceEnd:(Conference *)conference;

/**
 拒绝会议
 
 @param conference 会议
 @param cubeId 拒绝者
 */
- (void)onConferenceReject:(Conference *)conference from:(NSString *)cubeId;


/**
 当会议操作失败时回调
 
 @param error 信息
 */
- (void)onConferenceFailed:(CubeErrorInfo *)error;

#pragma mark - conference network observer

/**
 会议网络连接状态更新
 
 @param newstate 新的状态
 */
-(void)onConferenceNetWorkUpdate:(CubeMediaQuality)newstate;

#pragma mark - 会议视频流监听 -- sfu

/**
 当自己所在的会议视频流增加时。

 @param stream 流信息
 */
- (void)onConferenceAddStream:(CubeConferenceStream *)stream;


/**
 当自己所在的会议视频流移除时。

 @param stream 流信息
 */
- (void)onConferenceRemoveStream:(CubeConferenceStream *)stream;


/**
 当自己所在会议流更新时

 @param stream 流信息
 */
- (void)onConferenceUpdate:(CubeConferenceStream *)stream;


/**
 会议状态监听

 @param state 会议状态
 */
- (void)onConferenceStateChanged:(ConferenceState)state;

@end


#pragma mark - smart conference

@protocol SmartConferenceServiceDelegate <NSObject>

@optional

/**
 * 创建会议成功
 *
 * @param conference 会议实体
 * @param from       会议创建者
 */
-(void)onCreated:(SmartConference *)conference from:(SmartMember *)from;

/**
 * 会议销毁成功
 *
 * @param conference 会议实体
 * @param from       会议销毁者（默认为创建者）
 */
-(void)onDestroyed:(SmartConference *)conference from:(SmartMember *)from;

/**
 * 收到会议邀请
 *
 * @param conference 会议实体
 * @param from       邀请者
 */
-(void)onInvited:(SmartConference *)conference from:(SmartMember *)from;

/**
 * 邀请回应
 *
 * @param conference 会议实体
 * @param from       发起者
 * @param isAgreed   是否同意
 * @param reason     原因
 */
-(void)onInviteResponded:(SmartConference *)conference from:(SmartMember *)from isAgreed:(BOOL)isAgreed reason:(NSString *)reason;

/**
 * 成员加入会议
 *
 * @param conference 会议实体
 * @param from       加入者
 */
-(void)onJoined:(SmartConference *)conference from:(SmartMember *)from;

/**
 * 成员离开会议
 *
 * @param conference 会议实体
 * @param from       退出者
 */
-(void)onQuited:(SmartConference *)conference from:(SmartMember *)from;

/**
 * 会议会控
 *
 * @param conference   会议实体
 * @param memberAction 会控载体
 */
-(void)onControlled:(SmartConference *)conference controlAction:(SmartMemberControl *)memberAction;

/**
 * 举手
 *
 * @param conference 会议实体
 * @param from       发起者
 * @param reason     原因
 */
-(void)onHandUp:(SmartConference *)conference from:(SmartMember *)from reason:(NSString *)reason;

/**
 * 举手回应
 *
 * @param conference 会议实体
 * @param from       发起者
 * @param isAgreed   是否同意
 * @param reason     原因
 */
-(void)onHandUpResponded:(SmartConference *)conference from:(SmartMember *)from isAgreed:(BOOL)isAgreed reason:(NSString *)reason;


/**
 * 有流加入
 *
 * @param stream 新增流
 */
-(void)onStreamAdded:(SmartConferenceStream *)stream;

/**
 * 有流移除
 *
 * @param stream 移除流
 */
-(void)onStreamRemoved:(SmartConferenceStream *)stream;

/**
 * 有流更新
 *
 * @param stream 更新流
 */
-(void)onStreamUpdate:(SmartConferenceStream *)stream;

/**
 * 错误回调
 *
 * @param code 错误码
 * @param desc 错误描述
 */
-(void)onFailed:(int)code desc:(NSString *)desc;

/**
 通话质量检测回调(需开启通话质量检测listen true)

 @param data 通话质量数据
 */
-(void)onMediaQualityCheck:(SmartMediaData *)data;

@end

#pragma mark - 白板相关
/**
 白板服务委派
 通过实现白板委派可以监听到白板
 */
@protocol CubeWhiteboardServiceDelegate <NSObject>
@optional

-(void)onCreatWhiteBoard:(CubeWhiteBoard *)whiteboard;


/**
 共享回掉
 
 @param whiteboard 共享的白板
 @param cubeId 加入共享的人
 */
-(void)onShared:(CubeWhiteBoard *)whiteboard from:(NSString *)cubeId;

/**
 撤销共享
 
 @param whiteboard 撤销共享的白板
 @param cubeId 撤销人ID
 */
-(void)onRevoked:(CubeWhiteBoard *)whiteboard from:(NSString *)cubeId;


/**
 收到邀请
 
 @param whiteboard 邀请加入的白板
 @param cubeId 邀请人
 */
-(void)onWhiteboardInvite:(CubeWhiteBoard *)whiteboard from:(NSString *)cubeId;

/**
 收到邀请请求的确认
 
 @param whiteboard 邀请请求的白板
 @param sucessList 成功邀请列表
 @param failureList 失败邀请列表
 */
-(void)onWhiteboardInviteResponded:(CubeWhiteBoard *)whiteboard withSuccess:(NSArray *)sucessList andFailure:(NSArray *)failureList;

/**
 拒绝白板分享
 
 @param whiteboard 被拒绝的白板
 @param cubeId 拒绝人ID
 */
-(void)onWhiteboardReject:(CubeWhiteBoard *)whiteboard from:(NSString *)cubeId;

/**
 白板切换
 
 @param whiteboard 已切换的白板
 */
-(void)onWhiteboardSwitch:(CubeWhiteBoard *)whiteboard;

/**
 错误毁掉
 
 @param error 错误信息
 */
-(void)onWhiteboardFailed:(CubeErrorInfo *)error;

@end


#pragma mark - 消息相关

/** 实时消息状态委派。
 *
 * 通过实现消息委派可以监听到消息的收发状态。
 */
@protocol CubeMessageServiceDelegate <NSObject>
@optional

/**
 当指定的消息已发送时此方法被回调
 
 @param message 当前发送的消息实例
 */
- (void)onSent:(MessageEntity *)message;

/**
 当接收到消息时此方法被回调
 
 @param message 当前收到的消息实例
 */
- (void)onReceived:(MessageEntity *)message;

/**
 当指定的消息已撤回时此方法被回调
 
 @param message 撤回的消息实例
 */
- (void)onRecalled:(MessageEntity *)message;

/**
 消息暂停时此方法被回调
 
 @param message 当前收到的实例
 */
- (void)onPaused:(MessageEntity *)message;

/**
 消息恢复时此方法被回调
 
 @param message 当前收到的实例
 */
- (void)onResumed:(MessageEntity *)message;

/**
 当指定的消息转发时此方法被回调
 
 @param succeedMessages 转发成功列表
 @param failedMessages 转发失败列表
 */
- (void)onForwardedWithSucceed:(NSArray *)succeedMessages andFailed:(NSArray *)failedMessages;

/**
 当查询用户状态时此方法被回调
 
 @param states 用户状态
 */
- (void)onReceivedRemoteAcountsState:(NSArray *)states;

/**
 当消息处理失败时此方法被回调
 
 @param errorInfo 发生错误时的错误信息
 @param message 发生错误时正在处理的消息
 */
- (void)onMessageFailed:(CubeErrorInfo *)errorInfo withMessageEntity:(MessageEntity *)message;

/**
 删除消息
 
 @param message 消息实体
 */
- (void)onMessageDelete:(MessageEntity *)message;

/**
 检索消息
 
 @param message 消息实体
 */
- (void)onSearchMessage:(MessageEntity *)message;

// - sync message
/**
 上层设置同步开始时间
 如果上层需要设置同步开始时间，需实现此方法，否则不用实现。
 @return 开始时间
 */
- (long long)setSyncBeginTime;

/**
 开始同步回执列表
 */
- (void)onMessageSyncReceiptListBegin;

/**
 开始同步消息
 */
- (void)onMessageSyncBegin;

/**
 已同步的消息
 已同步的消息已字典形式返回,key为用户ID，value为消息数组({cubeid:[messages]})
 @param messages 已同步的消息字典
 */
- (void)onMessagesSync:(NSDictionary *)messages;

/**
 同步消息结束
 */
- (void)onMessageSyncEnd;

/**
 预测结果回调
 
 @param result 预测结果
 */
- (void)onPredictor:(CubePredictorResult *)result;

/**
 预测出错回调
 
 @param error 错误
 */
- (void)onPredictorFailed:(CubeErrorInfo *)error;

/**
 回执回调
 
 @param sessionID 会话ID
 @param timestamp 回执时间错
 @param from  操作方 //预留字段，以后如果需要做一对一对方已读提示时使用
 @param deviceInfo 设备信息
 */
- (void)onReceiptSession:(NSString *)sessionID timestamp:(long long)timestamp from:(NSString *)from deviceInfo:(CubeDeviceInfo *)deviceInfo;

/**
 回执出错
 
 @param error  错误信息
 */
- (void)onReceiptedAllFailed:(CubeErrorInfo *)error;

/**
 旧接口回调  废弃
 */
- (void)onReceiptAll:(MessageEntity *)lastMessage from:(CubeDeviceInfo *)deviceInfo;

/**
 旧接口回调 废弃
 */
- (void)onReceiptMessages:(NSArray *)messageArray from:(CubeDeviceInfo *)deviceInfo;

/**
 获取到历史消息
 新版http接口
 @param sessionId 会话ID
 @param messages 消息列表
 */
- (void)onGotHistoryMessage:(NSString *) sessionId andMessages:(NSArray<MessageEntity *>*)messages;

/**
 当查询历史消息时此方法被回调
 旧版本指令接口
 @param messagesArray 消息集合
 @param cubeId cube号
 @param timestamp 时间戳
 @param max 历史消息总数
 */
- (void)onReceivedHistory:(NSArray *)messagesArray withConversation:(NSString *)cubeName withTimestamp:(long long)timestamp withMax:(int)max;


#pragma mark - 文件相关
//--------------------------filedelegate---------------------------
/**
 上传中
 
 @param message 消息体
 @param processed 进度
 @param total 总大小
 */
- (void)onUploading:(MessageEntity *)message withProcessed:(long long)processed withTotal:(long long)total;

/**
 上传完成
 
 @param message 消息体
 */
-(void)onUploadComplete:(MessageEntity *)message;

/**
 取消上传
 
 @param message 消息体
 */
-(void)onUploadFileCanceled:(MessageEntity *)message;

/**
 上传出错
 
 @param message 消息体
 @param error 错误信息
 */
-(void)onUploadFileError:(MessageEntity *)message withErrorInfo:(CubeErrorInfo *)error;

/**
 下载中
 
 @param message 消息体
 @param progress 进度
 @param total 总大小
 */
- (void)onDownloading:(MessageEntity *)message withProcessed:(long long)processed withTotal:(long long)total;

/**
 下载取消
 
 @param message 消息体
 */
-(void)onDownloadFileCanceled:(MessageEntity *)message;

/**
 下载失败
 
 @param message 消息体
 @param error 错误信息
 */
-(void)onDownloadFileError:(MessageEntity *)message withErrorInfo:(CubeErrorInfo *)error;

/**
 下载完成
 
 @param message 消息体
 */
- (void)onDownloadComplete:(MessageEntity *)message;
@end



@protocol CubeMessageStateDelegate <NSObject>

@optional


/**
 消息工作状态
 
 @param state 状态枚举
 */
- (void)onChangeState:(CubeMessageState)state;

@end



#pragma mark - 文件夹相关

//--------------------------CubeFileManagerDelegate---------------------------

/**
 文件管理代理方法
 通过实现文件管理代理方法可以监听到文件的各种操作
 */
@protocol CubeFileManagerDelegate <NSObject>

@optional

/**
 文件操作错误
 
 @param error 发生错误时的错误代码
 */
- (void)onFileError:(CubeErrorInfo *)error;

/**
 文件添加
 
 @param fileInfoArray 文件添加后的集合
 @param parent 父目录
 */
- (void)onFileAdded:(NSArray *)fileInfoArray withParent:(CubeFileInfo *)parent;

/**
 文件删除
 
 @param fileInfoArray 文件删除后的集合
 @param parent 父目录
 */
- (void)onFileDeleted:(NSArray *)fileInfoArray withParent:(CubeFileInfo *)parent;

/**
 文件移动
 
 @param fileInfoArray 文件移动后的集合
 @param parent 父目录
 */
- (void)onFileMove:(NSArray *)fileInfoArray withParent:(CubeFileInfo *)parent;

/**
 文件重命名
 
 @param from 命名前的文件
 @param to 命名后的文件
 */
- (void)onFileRename:(CubeFileInfo *)from withParent:(CubeFileInfo *)to;

@end


/**
 文件操作进度代理方法
 通过实现文件操作进度代理方法可以监听到文件的各种操作进度
 */
@protocol CubeFileManagerStatusDelegate <NSObject>

@optional

/**
 文件操作完成
 
 @param fileInfo 完成的文件
 */
- (void)onFileCompleted:(CubeFileInfo *)fileInfo;

/**
 文件操作失败
 
 @param fileInfo 失败的文件
 */
- (void)onFileFailed:(CubeFileInfo *)fileInfo;

/**
 文件操作进度
 
 @param fileInfo 被操作的文件
 @param progress 进度
 @param total 文件总大小
 */
- (void)onFileProgress:(CubeFileInfo *)fileInfo withProgress:(long long)progress withTotal:(long long)total;

/**
 文件开始上传
 
 @param fileInfo 被操作的文件
 */
- (void)onFileStarted:(CubeFileInfo *)fileInfo;

@end

//--------------------------CubeInstructionServiceDelegate---------------------------

@protocol CubeInstructionServiceDelegate <NSObject>

@optional

/**
 接收指令
 
 @param instruction 指令
 */
- (void)onInstructionRequestedWithInstruction:(CubeInstruction *)instruction;

/**
 指令执行结果
 
 @param result 指令执行结果
 */
- (void)onInstructionRespondedWithInstructionRequestedResult:(CubeInstructionRequestedResult *)result;

@end


#pragma mark - 远程桌面相关

//--------------------------CubeRemoteDesktopDelegate---------------------------

@protocol CubeRemoteDesktopDelegate <NSObject>

@optional

/**
 * 创建桌面回调（仅创建的设备收到）
 *
 * @param rd
 */
- (void)onRemoteDesktopCreated:(CubeRemoteDesktop *)rd;

/**
 * 分享桌面回调
 *
 * @param rd
 * @param from
 */
- (void)onRemoteDesktopShared:(CubeRemoteDesktop *)remoteDesktop;

/**
 * 撤销分享桌面回调
 *
 * @param rd
 * @param from
 */
- (void)onRemoteDesktopRevoked:(CubeRemoteDesktop *)rd;

/**
 * 申请查看远程桌面回调
 *
 * @param rd
 * @param from
 */
- (void)onRemoteDesktopApplied:(CubeRemoteDesktop *)rd;

/**
 * 离开远程桌面
 *
 * @param rd
 * @param from
 */
- (void)onRemoteDesktopLeaved:(CubeRemoteDesktop *)rd;

/**
 * 销毁远程桌面（仅发起销毁的设备收到）
 *
 * @param rd
 */
- (void)onRemoteDesktopDestroyed:(CubeRemoteDesktop *)rd;

/**
 * 远程桌面出错回调
 *
 * @param error
 */
- (void)onRemoteDesktopFailed:(CubeErrorInfo *)errorInfo;

/**
 * 数据加载中
 */
- (void)onRemoteDesktopLoading;

/**
 * 画面播放
 */
- (void)onRemoteDesktopPlay;

@end

//--------------------------CubeFileOperationDelegate---------------------------

/**
 文件转换代理方法
 */
@protocol CubeFileOperationDelegate <NSObject>

@optional

/**
 白板共享成功回调
 
 @param whiteboardFile 回调成功返回白板文件
 */
- (void)onSucceed:(CubeWhiteboardFile *)whiteboardFile;

/**
 文件分享或保存成功回调
 */
- (void)onSucceed;

/**
 文件操作失败回调
 
 @param errorInfo 回调失败错误码
 */
- (void)onFailed:(CubeErrorInfo *)errorInfo;

@end


#pragma mark - 账户相关

//--------------------------CubeAccountDelegate---------------------------

@protocol CubeAccountDelegate <NSObject>

@optional

/**
 账号登录成功回调
 
 @param session session
 */
- (void)onLoginWithSession:(CubeSession *)session;

/**
 账号登出回调
 
 @param session session
 */
- (void)onLogoutWithSession:(CubeSession *)session;

/**
 账号出错回调
 
 @param error error
 */
- (void)onAccountFailed:(CubeErrorInfo *)error;

@end

//--------------------------CubeDeviceDelegate---------------------------

@protocol CubeDeviceDelegate <NSObject>

@optional

/**
 设备上线
 
 @param loginDevice loginDevice
 @param onLineDevices onLineDevices
 */
- (void)onDeviceOnlineWithLoginDevice:(CubeDeviceInfo *)loginDevice withOnlineDevices:(NSArray<CubeDeviceInfo *> *)onLineDevices withLoginTimestamp:(long long)timestamp;

/**
 设备下线
 
 @param logoutDevice logoutDevice
 @param onlineDevices onlineDevices
 */
- (void)onDeviceOfflineWithLogoutDevice:(CubeDeviceInfo *)logoutDevice withOnlineDevices:(NSArray<CubeDeviceInfo *> *)onlineDevices;

@end

//--------------------------CubeDatabaseDelegate---------------------------

@protocol CubeDatabaseDelegate <NSObject>

@optional

/**
 数据库升级完成回掉
 
 @param error 错误信息，为nil表示成功
 */
-(void)cubeDatabaseUpgradeEndWithError:(NSError *)error;

@end

//--------------------------CubeLicenseServiceDelegate---------------------------

@protocol CubeLicenseServiceDelegate <NSObject>

@optional

/**
 lisence出错
 
 @param errorCode 错误码
 */
-(void)licenseError:(CubeStateCode)errorCode;

/**
 license即将更新
 @param updateHandler 更新操作，界面提示完成以后，调用block即可开始更新
 */
-(void)licenseWillUpdate:(void(^)(void)) updateHandler;

/**
 license更新结束
 
 @param error 错误信息，nil表示更新正常
 @param isForce 是否需要强制重连
 */
-(void)licenseUpdateEndWithError:(CubeErrorInfo *)error isForceReconnect:(BOOL)isForce;

@end

//--------------------------CubeContactServiceDelegate---------------------------

@protocol CubeContactServiceDelegate<NSObject>

@optional

/**
 联系人置顶更新
 
 @param contact 联系人信息
 */
-(void)onConcatTop:(CubeContact *)contact;

/**
 联系人置顶错误
 
 @param error 错误信息
 */
-(void)onContactFailed:(CubeErrorInfo *)error;

@end

#endif
