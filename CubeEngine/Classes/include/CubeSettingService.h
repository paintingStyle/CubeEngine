//
//  CubeSettingService.h
//  CubeEngine
//
//  Created by Ashine on 2019/4/16.
//  Copyright © 2019 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CubeNotifySetting.h"
#import "CubeErrorInfo.h"



// 推送环境
typedef enum : NSUInteger {
    
    /*
     推送开发环境
     */
    Sandboxie = 1,
    
    /*
     推送生产环境
     */
    Prd,
    
} WorkType;


// 推送类型
typedef enum : NSUInteger {
    
    /*
     苹果apns推送
     */
    APNS  = 1,
    
    /*
     阿里推送
     */
    ALIPUSH,
    
} VendorType;


@protocol CubeSettingServiceDelegate <NSObject>

/**
 通知注册回调
 
 @param isRegister 是否注册成功
 @param registerId 注册id标志(三方应用服务器可根据此id标志推送对象)
 */
- (void)onNotifyRegister:(BOOL)isRegister registerId:(NSString *)registerId;



/**
 通知设置更新回调(暂未提供,目前采用方法内block回调)
 
 @note 通知设置更新回调/静音/免打扰等配置变更都会回调
 @param setting 通知设置
 */
- (void)onNotifySettingUpdate:(CubeNotifySetting *)setting;



/**
 错误回调

 @param error 错误信息
 */
- (void)onSettingFailed:(CubeErrorInfo *)error;

@end


@interface CubeSettingService : NSObject



/**
 监听回调代理
 */
@property (nonatomic,weak) id<CubeSettingServiceDelegate> delegate;



#pragma mark - notification register & unregister

/**
 注册推送服务(完成注册是在引擎登陆成功以后)
 
 @note token对应参数,如果是苹果推送则为苹果的devicetoken,如果是阿里推送则为在阿里注册的deviceId,其它类推
 @param wType   推送环境
 @param vType  推送类型
 @param token 推送token
 */
- (void)registerNotify:(WorkType )wType vendorType:(VendorType )vType token:(NSString *)token;



/**
 注销推送服务
 @note 注册id标志通过注册监听回调中返回
 @param registerId 注册id标志
 */
- (void)unregisterNotify:(NSString *)registerId;



#pragma mark - notification setting 


/**
 设置免打扰

 @param targetId 免打扰目标对象(如果是自己，则代表全局,可以是群组、个人、全局,这三种方式)
 @param enble 免打扰开关
 @param startTime 免打扰开启时间
 @param stopTime 免打扰结束时间
 */
- (void)setDisturb:(NSString *)targetId
     disturbEnable:(BOOL)enable
         startTime:(NSString *)startTime
          stopTime:(NSString *)stopTime
           success:(void(^)(CubeNotifySetting *setting))success
           faliure:(void(^)(CubeErrorInfo *error))failure;




/**
 设置通知详情

 @param targetId 目标对象(如果是自己，则代表全局,可以是群组、个人、全局,这三种方式)
 @param enable 通知详情开关
 */
- (void)setNotifyDetail:(NSString *)targetId
           detailEnable:(BOOL)enable
                success:(void(^)(CubeNotifySetting *setting))success
                faliure:(void(^)(CubeErrorInfo *error))failure;




/**
 获取单个配置

 @note 目标对象可以是 个人、群组、全局(如果目标id为自己的的cubeId则表示全局)
 @param targetId 目标对象id
 @param success 成功回调
 @param failure 失败回调
 */
- (void)getNotifySettingByTargetId:(NSString *)targetId
                         success:(void(^)(CubeNotifySetting *setting,long updateTime))success
                         failure:(void(^)(CubeErrorInfo *error))failure;




/**
 同步最新配置
 
 @note 如果更新时间为零，则从最旧的数据返回给终端
 @param updateTime 更新时间戳
 */
- (void)syncNotifySettings:(long )updateTime
                   success:(void(^)(NSArray <CubeNotifySetting *> *settings,long updateTime,BOOL hasNext))success
                   failure:(void(^)(CubeErrorInfo *error))failure;



@end
