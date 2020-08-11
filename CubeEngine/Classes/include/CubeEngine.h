//
//  CubeEngine.h
//  Cube Engine
//
//  Created by Xu Jiangwei on 14/9/28.
//  Copyright (c) 2014-2016 Cube Team. All rights reserved.
//

#ifndef CubeEngine_h
#define CubeEngine_h

#include "CubePrerequisites.h"

typedef NS_ENUM(int, CubeWorkType)
{
    CubeWorkTypeNone = 0,               //闲置
    CubeWorkTypeRequestAccess = 1 << 0, //权限申请
    CubeWorkTypePullMessage = 1 << 1,   //收取消息
    CubeWorkTypeSendMessage = 1 <<  2,  //发送消息
    CubeWorkTypeSendUnreadBadge = 1 <<  3,  //发送未读消息数统计
};

typedef enum _CubeState {
    CubeStateStart,      //启动        所有模块初始化完成后的状态
    CubeStatePause,      //暂停        没有网络时，启动后无法工作时的状态
    CubeStateReady,      //就绪        引擎注册成功，可以收发数据的状态---引擎断网或者引擎无法收发数据时会回到START状态
    CubeStateBusy,       //工作中      当有有超过一条消息需要接收处理时，处理数据过程中处于此状态---数据收发完成后回到READY状态
    CubeStateStop        //停止        默认值或引擎shutdown之后的状态
}CubeState;


typedef enum _CubeCacheType {
    CacheType_All,//全部
    CacheType_Image,//图片
    CacheType_Voice,//音频
    CacheType_Video,//视频
    CacheType_File,//文件
    CacheTypeE_Whb,//白板
    CacheType_Log//日志
}CubeCacheType;

//typedef enum _CubeLoginStatus
//{
//    CubeLoginStatusUnkown,
//    CubeLoginStatusSleep,//用户回到后台
//    CubeLoginStatusLogoff //用户主动退出
//}CubeLoginStatus;
/**
 引擎代理
 */
@protocol CubeEngineDelegate <CubeDatabaseDelegate,CubeLicenseServiceDelegate>

@optional


/**
 引擎启动完成
 */
- (void)onStarted;


/**
 引擎状态更新

 @param engingState 引擎State
 */
- (void)onStateChange:(CubeState)engingState;


/**
 引擎停止
 */
- (void)onStopped;


/**
 引擎错误
 */
- (void)onFailed:(CubeErrorInfo *)error;

@end


/**
 魔方引擎核心入口对象
 此对象是魔方引擎的核心对象，且为单例模式
 应用程序通过该对象来完成所需的协作功能
 这些功能包括视频、语音对话，即时消息，白板，短音频等
 引擎的生命周期控制管理接口都通过该对象的方法进行维护
 */
@interface CubeEngine : NSObject


/** 返回 CubeEngine 单例。
 *
 * @return 返回 CubeEngine 单例指针。
 */
+ (CubeEngine *)sharedSingleton;

/**
 引擎状态代理
 */
@property (nonatomic, weak) id<CubeEngineDelegate> cubeEngineDelegate;

/**
 注册状态代理
 */
@property (nonatomic, weak) id<CubeRegistrationDelegate> registrationDelegate;

/**
 引擎是否已经启动
 */
@property (nonatomic, assign, readonly) BOOL started;

/**
 当前有效的会话实例
 */
@property (nonatomic, strong, readonly) CubeSession *session;

/**
 当前生效的配置实例
 */
@property (nonatomic, strong, readonly) CubeConfig *config;


/**
 音/视频呼叫服务
 */
@property (nonatomic, strong, getter=getCallService) CubeCallService *callService;

/**
 消息服务
 */
@property (nonatomic, strong, getter=getMessageService) CubeMessageService *messageService;


/**
 群组服务
 */
@property (nonatomic, strong, getter=getGroupService) CubeGroupService *groupService;

/**
 会议服务
 */
@property (nonatomic, strong, getter=getConferenceService) CubeConferenceService *conferenceService;

/**
 智能会议服务
 */
@property (nonatomic, strong, getter=getSmartConferenceService) SmartConferenceService *smartConferenceService;

/**
 智能白板服务
 */
@property (nonatomic, strong, getter=getWhiteboardService) CubeWhiteboardService *whiteboardService;

/**
 媒体服务
 */
@property (nonatomic, strong, getter=getMediaService) CubeMediaService *mediaService;

/**
 文件服务
 */
@property (nonatomic, strong, getter=getFileService) CubeFileService *fileService;

/**
 账号服务
 */
@property (nonatomic, strong, getter=getAccountService) CubeAccountService *accountService;

/**
 指令服务
 */
@property (nonatomic, strong, getter=getInstructionService) CubeInstructionService *instructionService;


/**
 设置服务
 */
@property (nonatomic, strong, getter=getSettingService) CubeSettingService *settingService;


/**
 远程桌面服务
 */
@property (nonatomic, strong, getter=getRemoteDesktopService) CubeRemoteDesktopService *remoteDesktopService;

@property (nonatomic, strong) CubeLiveService *liveService;

/**
 联系人服务
 */
@property (nonatomic, strong) CubeContactService *contactService;

/**
 引擎当前状态
 */
@property (nonatomic, assign, getter=getCubeEngingState) CubeState cubeEngingState;

/**
 当前设备
 */
@property (nonatomic, strong, getter=getDeviceInfo) CubeDeviceInfo *deviceInfo;


/**
 用户登录状态
 */
//@property (nonatomic, assign) CubeLoginStatus loginStatus;

#pragma mark Engine

/** 启动引擎，引擎完成初始化操作。
 *
 * 此方法用于启动引擎，将引擎置为工作状态。
 * 调用该方法后引擎将完成各种初始化工作。
 *
 * @note 此方法必须在 UI 线程中调用。
 *
 * @param appId 指定在魔方开发者中心申请的应用程序的 ID 。
 * @param appKey 指定和应用程序 ID 匹配的应用程序的标识 Key 。
 * @return 返回魔方引擎是否启动成功。如果返回 <code>YES</code> 则表示引擎启动成功，否则表示引擎启动失败。
 */
#pragma mark *** Deprecated/discouraged API ***
- (BOOL)startup:(NSString *)appId appKey:(NSString *)appKey
CUBE_DEPRECATED_WILL_BE_REMOVED_IN_PLEASE_USE("2.0", "startup: withToken:");
/**
 启动引擎，引擎完成初始化操作

 @param cubeConfig 引擎配置文件
 */
- (BOOL)startWithCubeConfig:(CubeConfig *)cubeConfig;

/** 启动引擎，引擎完成初始化操作。
 *
 * 此方法用于启动引擎，将引擎置为工作状态。
 * 调用该方法后引擎将完成各种初始化工作。
 *
 * @note 此方法必须在 UI 线程中调用。
 *
 * @param appId 指定在魔方开发者中心申请的应用程序的 ID 。
 * @param token 指定和应用程序 ID 匹配的应用程序的标识 Key 。
 * @return 返回魔方引擎是否启动成功。如果返回 <code>YES</code> 则表示引擎启动成功，否则表示引擎启动失败。
 */


- (BOOL)startup:(NSString *)appId withToken:(NSString *)token CUBE_DEPRECATED_WILL_BE_REMOVED_IN_PLEASE_USE("2.3", "startWithCubeConfig:");;

/** 停止引擎，引擎停止所有工作，并释放内存。
 *
 * 此方法用于停止引擎，将引擎置为关闭状态。
 * 调用该方法后引擎将关闭各项功能，并释放内存。
 *
 * @note 此方法必须在 UI 线程中调用。
 */
- (void)shutdown;

/** 暂停引擎工作。
 *
 * 暂停引擎工作时，引擎会暂停所有正在进行的实时协作操作。
 *
 * @see UIApplicationDelegate#applicationWillResignActive 被回调时应当调用该方法。
 */
- (void)sleep;

/** 恢复引擎工作。
 *
 * 恢复引擎时，引擎会恢复到工作状态。
 * 
 * @see UIApplicationDelegate#applicationDidBecomeActive 被回调时应当调用该方法。
 */
- (void)wakeup;

/** 引擎进入后台运行。
 *
 * @see UIApplicationDelegate#applicationDidEnterBackground 被回调时调用该方法。
 */
- (void)enterBackground;

/** 启动后台守护任务。
 */
- (void)backgroudKeepAlive;

/** 引擎进入前台运行。
 *
 * @see UIApplicationDelegate#applicationWillEnterForeground 被回调时调用该方法。
 */
- (void)enterForeground;

/** 对引擎进行指定的参数配置。
 *
 * @param config 指定配置参数对象。
 */
- (void)configure:(CubeConfig *)config;


/**
 获取某个人的时延

 @param cubeId cube id

 @return 获取某个人的时延
 */
//- (long long)getDelayTime:(NSString *)cubeId;

#pragma mark - cache
/// 清除本地缓存文件
/// @param cacheType 缓存类型
- (BOOL)cleanCache:(CubeCacheType)cacheType;

/// 获取缓存大小
/// @param cacheType 缓存类型
- (NSInteger)getCacheSize:(CubeCacheType)cacheType;

#pragma mark - Registration

/** 注册账号。
 *
 * 每个应用程序通过注册账号来标识唯一终端。
 * 在调用其他 API 前都应当先使用一个已知账号执行注册操作。
 *
 * @param name 指定注册名，即 Cube Name 。
 * @param password 指定注册名对应的密码。
 * @param displayName 指定显示姓名
 * @return 如果执行注册成功，则返回 <code>YES</code> ，否则返回 <code>NO</code> 。当执行失败时，应用程序应当检测网络连接状态。
 *
 * @note 该方法是异步执行方法，返回值表示方法是否被成功执行，不表示注册是否成功。
 */
- (BOOL)registerAccount:(NSString *)name password:(NSString *)password displayName:(NSString *)displayName
CUBE_DEPRECATED_WILL_BE_REMOVED_IN_PLEASE_USE("2.0", "registerAccount: password: displayName: withToken:");

/** 注册账号。
 *
 * 每个应用程序通过注册账号来标识唯一终端。
 * 在调用其他 API 前都应当先使用一个已知账号执行注册操作。
 *
 * @param name 指定注册名，即 Cube Name 。
 * @param password 指定注册名对应的密码。
 * @param displayName 指定显示姓名
 * @param token 访问token
 * @return 如果执行注册成功，则返回 <code>YES</code> ，否则返回 <code>NO</code> 。当执行失败时，应用程序应当检测网络连接状态。
 *
 * @note 该方法是异步执行方法，返回值表示方法是否被成功执行，不表示注册是否成功。
 */
- (BOOL)registerAccount:(NSString *)name password:(NSString *)password displayName:(NSString *)displayName withToken:(NSString *)token;



/** 注销账号。
 *
 * @return 如果执行注销成功，则返回 <code>YES</code> ，否则返回 <code>NO</code> 。
 *
 * @note 该方法是异步执行方法，返回值表示方法是否被成功执行，不表示注销是否成功。
 */
- (BOOL)unregisterAccount;

/** 注册 APNS。
 *
 * @param application 应用上下文。
 * @param deviceToken 设备标识。
 */
- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;

/**
 判断是否有访问某种设备的权限，如果没有，则自动申请权限，申请完成后，通过回掉通知
 
 @param mediaType 权限类型
 @param completeHandler 完成回掉
 @return 是否需要申请权限,YES，表示未申请，接下来会自动申请，NO，表示申请
 */

- (BOOL)shouldRequestAccessForMediaType:(NSString *)mediaType andRequestCompleteHandler:(void(^)(BOOL granted))completeHandler;


#pragma mark - working state

-(void)beginWorkWithType:(CubeWorkType)workType;

-(void)endWorkWithType:(CubeWorkType)workType;


#pragma mark - tool

/**
 引擎状态转字符串
 
 @param state 引擎状态
 @return 引擎状态字符串
 */
+(NSString *)cubeStateStringFrom:(CubeState)state;


@end

#endif
