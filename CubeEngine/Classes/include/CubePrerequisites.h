//
//  CubePrerequisites.h
//  Cube Engine
//
//  Created by Xu Jiangwei on 14/9/28.
//  Copyright (c) 2014-2016 Cube Team. All rights reserved.
//

#ifndef CubePrerequisites_h
#define CubePrerequisites_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class CubeEngine;
@class CubeSession;
@class CubePeer;
@class CubeCallPeer;
@class CubeLocalVideoView;
@class CubeRemoteVideoView;
@class CubeConfig;
@class CubeTextMessage;
@class CubePredictorResult;
@class CubeFileMessage;
@class CubeImageMessage;
@class CubeVoiceClipMessage;
@class CubeVideoClipMessage;
@class CubeCustomMessage;
@class MediaProbe;
@class CubePlayVideoView;
@class CubeRecordVideoView;
@class Sender;
@class Receiver;
@class MessageEntity;
@class CubeWhiteboardFile;
@class CubeWhiteboardSlide;
@class GroupContext;

@class Conference;
@class MemberAction;

@class CubeContact;

@class CubeMessageService;
@class CubeGroupService;
@class CubeConferenceService;
@class CubeCallService;
@class CubeWhiteBoard;
@class CubeWhiteboardService;
@class CubeMediaService;
@class CubeAccountService;
@class CubeWhiteboardFrameMessage;
@class CubeLicense;
@class CubeFileInfo;
@class CubeErrorInfo;
@class CubeVersion;
@class CubeDeviceInfo;
@class CubeInstruction;
@class CubeInstructionRequestedResult;
@class CubeInstructionService;
@class CubeRemoteDesktop;
@class CubeRemoteDesktopService;
@class CubeLiveService;
@class CubeContactService;
@class CubeFileService;
@class CubeSettingService;
@class CubeConferenceStream;

@class SmartConference;
@class SmartConferenceStream;
@class SmartMember;
@class SmartMemberControl;
@class SmartMemberRole;
@class SmartConferenceConfig;
@class SmartConferenceService;
@class SmartMediaData;

//全局通知
#define CubeAccountDidLogoutNotification @"CubeAccountDidLogout"

/** 引擎接口定义。
 */
@interface Cube : NSObject

/** 注册状态枚举。
 *
 * 当执行注册流程时，引擎通过委派机制向应用程序通知注册状态。
 * 通过获知注册状态，应用程序开发者可以及时了解到用户使用帐号的注册状态。
 */
typedef enum _CubeRegistrationState {
    /** 引擎初始化时使用的状态，表示没有执行过注册流程。 */
    CubeRegistrationNone,

    /** 正在处理注册状态。 */
    CubeRegistrationProgress,

    /** 注册成功状态。 */
    CubeRegistrationOk,

    /** 成功清理注册状态。 */
    CubeRegistrationCleared,

    /** 注册失败。 */
    CubeRegistrationFailed

} CubeRegistrationState;


/** 信令状态枚举。
 */
typedef enum _CubeSignalingState {
    /** 信令初始状态。 */
    CubeSignalingNone,

    /** 正在处理执行状态。 */
    CubeSignalingProgress,

    /** 发出邀请状态。 */
    CubeSignalingInvite,

    /** 呼叫响铃状态。 */
    CubeSignalingRinging,

    /** 通话已经建立。 */
    CubeSignalingIncall,

    /** 通话结束状态。 */
    CubeSignalingEnd

} CubeSignalingState;


/** 通话呼叫方向枚举。
 * 视频/语音通话呼叫方向，即主、被叫枚举。
 * 应用程序可根据此判断呼叫时的通话方向。
 */
typedef enum _CubeCallDirection {
    /** 主叫呼出，呼叫方向为呼出。 */
    CubeCallOutgoing = 1 << 0,

    /** 被叫呼入，呼叫方向为呼入。 */
    CubeCallIncoming = 1 << 1,

    /** 表示呼叫方向未定义。 */
    CubeCallNone = 0

} CubeCallDirection;

typedef enum _CubeMessageState {
    CubeMessageStateNormal,     //无状态
    CubeMessageStateStart,      //启动
    CubeMessageStateReady,      //就绪
    CubeMessageStatePulling,    //工作中
    CubeMessageStateStop        //停止
}CubeMessageState;

/** 通话结束动作枚举。
 *
 * 视频/语音通话结束动作枚举。
 * 应用程序可根据此判断触发通话结束的动作。
 */
typedef enum _CubeCallEndAction {
    /** 取消通话。 */
    CubeCallCancel = 1 << 0,

    /** 对端取消通话。 */
    CubeCallPeerCancel = 1 << 1,

    /** 挂断通话。 */
    CubeCallBye = 1 << 2,

    /** 其他。 */
    CubeCallUnexpected = 1 << 3,

    /*!< 其他终端接听。*/
    CubeCallAnswerByOther = 1 << 4,
    
    CubeCallCancelByOther = 1 << 5,
	
	/**应答超时*/
	CubeCallAnswerTimeOut = 1 << 6

} CubeCallEndAction;


/** 媒体状态枚举。
 */
typedef enum _CubeMediaState {
    /** 音频开启。 */
    CubeAudioOpened = 2001,
    /** 音频关闭。 */
    CubeAudioClosed = 2000,
    /** 视频开启。 */
    CubeVideoOpened = 1001,
    /** 视频关闭。 */
    CubeVideoClosed = 1000

} CubeMediaState;


/** 全局状态码定义。
 */
typedef enum _CubeStateCode {
    /** 会议号码不可用。 */
    CubeStateInvalidConference = 100,
    /** 成功。 */
    CubeStateOk = 200,
    /** 请求无效。 */
    CubeStateBadRequest = 400,
    /** 未授权请求。 */
    CubeStateUnauthorized = 401,
    /** 需要付费。 */
    CubeStatePaymentRequired = 402,
    /** 服务器无法识别请求。 */
    CubeStateForbidden = 403,
    /** 服务器没有找到对应的请求目标。 */
    CubeStateNotFound = 404,
    /** 请求指定的方法服务器不允许执行。 */
    CubeStateMethodNotAllowed = 405,
    /** 代理需要授权。 */
    CubeStateProxyAuthenticationRequired = 407,
    /** 客户端的请求超时。 */
    CubeStateRequestTimeout = 408,
    /** 不支持的媒体类型。 */
    CubeStateUnsupportedMediaType  = 415,
    /** 请求数据发送失败。 */
    CubeStateRequestSendFailed = 477,
    /** 临时不可用。 */
    CubeStateTemporarilyUnavailable = 480,
    /** 呼叫事务不存在。 */
    CubeStateCallTransactionDoesNotExist = 481,
    /** 线路正忙。 */
    CubeStateBusyHere = 486,
    /** 对方未接听。 */
    CubeStateRequestTerminated = 487,
    /** 无人接听。 */
    CubeStateNotAcceptableHere = 488,
    /** 已被踢出无法呼入。 */
    CubeStateKick = 489,
    /** 服务器内部错误。 */
    CubeStateServerInternalError = 500,
    /** 网关超时。 */
    CubeStateGateWayTimeout = 504,
    /** 当前版本过低，请升级版本 */
    CubeVersionTooLow = 505,     //!< 当前版本过低，请升级版本
    /** 对方版本过低 */
    CubeVersionOtherTooLow = 506,     //!< 对方版本过低，
    /** 勿扰模式。 */
    CubeStateDoNotDisturb = 600,
    /** 拒绝请求。 */
    CubeStateDeclined = 603,

    /** 连接失败。 */
    CubeStateConnectionFailed = 700,
    /** SIP 错误。 */
    CubeStateSIPError = 701,
    /** 信令链路传输数据错误。 */
    CubeStateTransportError = 702,
    /** ICE 连接失败。 */
    CubeStateICEConnectionFailed = 703,
    /** ICE 断开连接 */
    CubeStateICEConnectionDisConnected = 704,
    /** 创建 SDP 失败。 */
    CubeStateCreateSessionDescriptionFailed = 705,
    /** 设置 SDP 失败。 */
    CubeStateSetSessionDescriptionFailed = 706,
    /** RTC 初始化失败。 */
    CubeStateRTCInitializeFailed = 707,
    /** 正在呼叫时，新呼叫进入。 */
    CubeStateDuplicationException = 710,
    /** 工作机状态异常。 */
    CubeStateWorkerStateException = 711,
    /** 呼叫超时。 */
    CubeStateCallTimeout = 712,
    /** 会议失败。 */
    CubeStateConferenceFailed = 714,
    /** 会议不存在。 */
    CubeStateConferenceNotExist = 715,
    /** 会议未成功退出。 */
    CubeStateConferenceNotQuit = 716,
    /** 应答超时 */
    AnswerTimeout = 717,
    /** 会议配置出错 */
    CubeStateConferenceConfigError = 718,
    /** publish failed */
    CubeStateSfuPublishFailed = 799,
    /** sfu reconnect失败 */
    CubeStateSfuReconnectFailed = 798,
    /** socket.io重连超时失败 */
    CubeStateSocketIOReconnectFailed = 797,
    /** 挂断超时 */
    CubeStateCallQuitTimeout = 796,
    /** 加入超时 */
    CubeStateCallJoinTimeout = 795,
    /** bye 超时(p2p) */
    CubeStateCallByeTimeout = 794,
    /** cancel 超时(p2p) */
    CubeStateCallCancelTimeout = 793,
    /** invite 超时(p2p) */
    CubeStateCallInviteTimeout = 792,
    /** answer 超时(p2p) */
    CubeStateCallAnswerTimeout = 791,
    
    /** 不正确的状态。 */
    CubeStateIncorrectState = 801,
    
     /** 网络质量差 网络已连接实际不可达。 */
    CubeStateLossyNetwork = 808,
    
    /** 网络不可达。 */
    CubeStateNetworkNotReachable = 809,
    
    /** 内容长度越界。 */
    CubeStateContentTooLong = 810,
    /** 内容长度太短。 */
    CubeStateContentTooShort = 811,
    /** 消息缓存块大小超限。 */
    CubeStateBlockOversize = 812,
    /** 格式错误。 */
    CubeStateFormatError = 813,
    /** 消息内容错误。 */
    CubeStateContentError = 814,
    /** 消息内容参数越限，比如文件大小越限。 */
    CubeStateOutOfLimit = 815,
    /** 消息没有接收人。 */
    CubeStateNoReceiver = 816,
    /** db检索消息为nil。 */
    CubeStateQueryNOData = 817,
    /** 消息分发失败。 */
    CubeStateDispatchFailed = 818,
    /** 过期的消息，消息超过5分钟不能撤回。 */
    CubeStateOutDateMessage = 818,
    
    /** 消息sn错误。 */
    CubeStateMessageSNError = 819,
    
    /** 发送者错误*/
    CubeStateMessageSenderError = 821,

    /** 丢失资源文件。 */
    CubeStateLostAssets = 820,
    /** 上传文件失败。 */
    CubeStateUploadFailed = 823,
    /** 处理文件失败。 */
    CubeStateProcessFailed = 825,
    /** 文件重命名失败失败。 */
    CubeStateRenamedFailed = 827,
    /** 文件加载失败。 */
    CubeStateLoadFileFailed = 828,
    /** 文件删除失败。 */
    CubeStateDeleteFailed = 829,
    /** 创建文件夹失败。 */
    CubeStateMkdirFailed = 830,

    /** 摄像头开启失败。 */
    CubeStateCameraOpenFailed = 901,
    /** 激活音频失败。 */
    CubeStateActiveAudioSessionFailed = 902,
    /** 麦克风开启失败。 */
    CubeStateMicphoneOpenFailed = 903,
    /** 录制视频转换失败。 */
    CubeStateVideoConvertFailed = 904,
    /** 音频录制初始化失败。 */
    CubeStateAudioRecorderInitialFailed = 905,
    /** 音频准备录制失败。 */
    CubeStateAudioRecorderPrepareFailed = 906,
    /** 解码出错。 */
    CubeStateAudioPlayDecodeFailed = 907,
    /** 用户取消录制。 */
    CubeStateRecordCancel = 908,
    /** 音频编码错误 */
    CubeStateAudioEncodingError = 909,
    
    
    
    //账号相关 1000~1100
    /** 注册失败。 */
    CubeStateRegisterFailed = 1004,
    /** AppId 为空或错误。 */
    CubeStateRegisterAppIdFailed = 1005,
    /** 请登录账号(未登录账号、账号已注销或者正在登录中)*/
    CubeStatePleaseLogin = 1006,
    /** 与服务器的连接已断开 */
    CubeStateAccountDisConnected = 1007,
    
    /**license文件为空 */
    CubeStateLicenseFileIsEmpty = 1011,
    /**license内容格式错误*/
    CubeStateLicenseFormatError = 1012,
    /**创建license文件出错*/
    CubeStateLicenseCreateFileError = 1013,
    /**写入license文件出错*/
    CubeStateLicenseWriteFileError = 1014,
    /** 授权过期。 */
    CubeStateLicenseOutDate = 1015,
    /**license 授权错误。 */
    CubeStateLicenseAuthError = 1016,
    /**license 错误。 */
    CubeStateLicenseError = 1017,
    /**license更新错误*/
    CubeStateLicenseUpdateError = 1018,
    /**license 授权错误。appid与token不匹配 */
    CubeStateLicenseAuthAppIdNotMatchTokenError = 1019,
    
    //消息相关 1100~1200
    /**文件上传失败*/
    CubeStateMessageFileUploadError = 1101,
    /**暂停文件上传失败*/
    CubeStateMessageFileUploadPauseError = 1102,
    /**文件上传失败 文件大小不一致*/
    CubeStateMessageFileSizeNotEqualError = 1103,
    /**获取文件进度失败*/
    CubeStateMessageGetProgressError = 1104,
    /**读取本地文件失败*/
    CubeStateMessageReadLocalFileError = 1105,
    /**文件上传进度错误*/
    CubeStateMessageFileUploadProgressError = 1106,
	/**找不到消息*/
	CubestateMessageQueryNODataError = 1107,
    /**视频录制时间太短*/
    CubeStateMessageVideoRecordingTimeIsTooShortError = 1111,
   /**对方已被设置免打扰*/
    CubeStateMessageMaskingError = 1131,
    /**已被设置了免打扰*/
	CubeStateMessageBeMaskedError = 1132,
	//////////////////////////////////////////////////////// FileManager  1200~1300 ////////////////////////////////////////////////////////
	/**文件接受异常无法通过md5验证*/
	CubeStateFileAcceptanceNoPassMd5 = 1200,
	/**文件不存在*/
	CubeStateFileNotExist = 1201,
	/**文件已过期*/
    CubeStateFileExpire = 1202,
	/**来源未授权*/
	CubeStateRefererNotAuthenticated = 1203,
	/**已上传部分数据丢失*/
	CubeStateFileAcceptanceLose = 1204,
	/**文件正在操作*/
	CubeStateFileAcceptanceing = 1205,
	/**已上传文件一部分数据*/
	CubeStateFilePartialAcceptance = 1206,
	/**客户端终止下载*/
	CubeStateClientTerminateDownload = 1207,
	/**下载URL已过期*/
	CubeStateDynamicUrlExpire = 1208,
	/**下载URL不存在*/
	CubeStateDynamicUrlNotExist = 1209,
	/**Key不存在*/
	CubeStateKeyNotExist = 1210,
	/**不是图片或视频*/
	CubeStateNotImageOrVideo = 1211,
	/**上传信息不存在*/
	CubeStateNotUploadInfo = 1214,
	
	/**无法读取文件内容*/
	CubeStateUploadBlockSizeError = 1298,
	/**无法读取文件内容*/
	CubeStateCannotReadContentOfFile = 1299,
	
    //Group 1300~1400
    /**添加管理员失败*/
    CubeStateGroupAddMasterFailed = 1300,
    /**删除管理员失败*/
    CubeStateGroupRemoveMasterFailed = 1301,
    
    
    //call 1400~1500
    //用户正忙，或者用户正在会议中
    AlreadyInCalling = 1400,
    StartWebrtcError = 1499,
    SdpIsNil         = 1498,
    SipOrSdpError    = 1497,
    
    //Conference 1500~1600
    //------服务端错误码------
    //会议已经存在
    CubeStateConferenceAlreadyExist = 1500,
    //会议人数已达上限
    CubeStateConferenceOverMaxNumber = 1501,
    //会议被其他终端拒绝
    CubeStateConferenceRejectByOther = 1502,
    //您已在其他终端参会
    CubeStateConferenceJoinFromOther = 1503,
    //您已在其他终端参会
    CubeStateConferenceJoinFailed = 1506,
    //拒绝失败
    CubeStateConferenceRejectFailed = 1507,
    //会议已经结束
    CubeStateConferenceAlreadyClosed = 1508,
    
    /** 您已在PC端参会 */
    CubeStateConferenceJoinFromPC = 1520,      //您已在PC端参会
    /** 您已在Android终端参会 */
    CubeStateConferenceJoinFromAndroid = 1521,      //您已在Android终端参会
    /** 您已在iOS终端参会 */
    CubeStateConferenceJoinFromIOS = 1522,      //您已在iOS终端参会
    /** 您已在其它移动设备参会 */
    CubeStateConferenceJoinFromMobile = 1523,      //您已在其它移动设备参会
    
    CubeStateGroupExistConference = 1530, // 该群已经存在多人音频或视频等，无法再次创建多人音视频会议及远程桌面等
    
    CubeStateGroupExistRemoteDesktop = 1531, // 该群已经存在正在进行的屏幕分享，无法再次创建多人音视频或远程桌面等
    
    //------本地错误码------
	CubeStateConferenceForbbidenJoin = 1550,
    /**申请会议出错*/
    CubeStateConferenceApplyError = 1551,
    /**申请加入会议出错*/
    CubeStateConferenceApplyJoinError = 1552,
    /**申请关闭会议出错*/
    CubeStateConferenceCloseError = 1553,
    /**会议邀请出错*/
    CubeStateConferenceInviteError = 1554,
    /**会议拒绝出错*/
    CubeStateConferenceRejectError = 1555,
    /**查询全部会议出错*/
    CubeStateConferenceQueyAllError = 1556,
    /**加入会议出错*/
    CubeStateConferenceJoinError = 1557,
    /**退出会议出错*/
    CubeStateConferenceQuitError = 1558,
    /**查询会议出错*/
    CubeStateConferenceQueyError = 1559,
//    /**
//     * ice链接失败
//     */
//    CubeErrorTypeIceConnectedFailed = 1597,
    /**
     * SocketIO 已断开
     */
    CubeErrorTypeSocketIODisconnected = 1596,
    /**
     * 正在处理其它会议指令
     */
    CubeErrorTypeConferenceIsBusy = 1598,
    /**
     * 会议操作超时
     */
    CubeErrorTypeConferenceTimeout = 1599,
    
    //Whiteboard  1600~1700
    //白板资源不存在
    CubeStateWhiteboardAssetNotExist = 1600,
    //白板资源解压出错
    CubeStateWhiteboardDecompressFailed = 1601,
    //白板加载失败
    CubeStateWhiteboardLoadFailed = 1602,

    
    //RemoteDesk  2000~2100
    /**停止接收远程桌面出错*/
    CubestateRemoteDeskStopReceiveRemoteDeskError = 2001,
    
    /** 未知的错误发生。 */
    CubeStateUnknown = 0
    
    //////////////////////////////////////////////////////// Smart-Conference  5000~5100 ////////////////////////////////////////////////////////
    

} CubeStateCode;


/** 录制文件类型定义。
 */
typedef enum _CubeRecordType {
    /** 音频录制。 */
    AudioRecord = 2000,

    /** 视频录制。 */
    VideoRecord = 1000

} CubeRecordType;


/** 返回魔方引擎的版本信息。
 * 引擎版本信息包括主版本号、副版本号和修订号。
 *
 * @return 返回字符串形式的版本描述信息。
 */
+ (NSString *)versionDescription;


/** 会议相关操作的动作描述枚举。
 */
typedef enum _CubeConferenceAction {
    /** 查询 */
    ConferenceActionQuery,
    /** 设为主讲人 */
    ConferenceActionFloor,
    /** 禁听 */
    ConferenceActionDeaf,
    /** 禁言 */
    ConferenceActionVoiceMute,
    /** 禁视 */
    ConferenceActionVideoMute,
    /** 加入会议 */
    ConferenceActionJoin,
    /** 退出会议 */
    ConferenceActionQuit,
    /** 踢出会议 */
    ConferenceActionKick,
    /** 关闭会议 */
    ConferenceActionClose,
    /** 设为主讲人 */
    ConferenceActionPresenter,
    /** 未知动作 */
    ConferenceActionUnknown

} CubeConferenceAction;

typedef NS_ENUM(int,ConferenType){
    // fs type
    ConferenTypeUnKnown = 0,                 //未知类型
    ConferenTypeVoiceCall = 1 << 0,          //多人语音
    ConferenTypeVideoCall = 1 << 1,          //多人视频
    ConferenTypeVoiceConference = 1 << 2,    //多人语音会议
    ConferenTypeVideoConference = 1 << 3,    //多人视频会议
    ConferenTypeVoiceDesktop = 1 << 4,       //语音桌面
    ConferenTypeVoiceCiscoConference = 1 <<5,//思科语音会议
    ConferenTypeVideoCiscoConference = 1 <<6,//思科视频会议
    ConferenTypeShareScreen= 1 <<7,           //共享屏幕
    
    // sfu type
    ConferenType_Voice_Call_sfu                 = 1 << 8,                // 多人语音
    ConferenType_Video_Call_sfu                 = 1 << 9,                // 多人视频
    ConferenType_Voice_Conference_sfu           = 1 << 10,                // 音频会议
    ConferenType_Video_Conference_sfu           = 1 << 11,                // 视频会议
    ConferenType_Voice_Cisco_Conference_sfu     = 1 << 12,                // 思科语音会议
    ConferenType_Video_Cisco_Conference_sfu     = 1 << 13,                // 思科视频会议
    ConferenType_Share_Desktop_sfu              = 1 << 14,                // 共享桌面
    ConferenType_Share_WB_sfu                   = 1 << 15,                // 共享白板
};

typedef enum _cubeMediaQuality
{
	CubeMediaQualityExcellent,
    CubeMediaQualityGood,
    CubeMediaQualityNoraml,
    CubeMediaQualityPoor,
    CubeMediaQualityUnkown
}CubeMediaQuality;

typedef enum : NSUInteger {
    ConferenceStateReconnecting,
    ConferenceStateReconnected,
} ConferenceState;

@end

#import "CubeEngineDeprecationMacros.h"

#import "CubeDelegate.h"
#import "CubeConfig.h"

#endif
