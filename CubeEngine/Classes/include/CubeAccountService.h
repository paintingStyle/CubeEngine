//
//  CubeAccountService.h
//  CubeEngine
//
//  Created by 曾長歡 on 2017/4/26.
//  Copyright © 2017年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CubeErrorInfo;
@protocol CubeAccountDelegate;
@protocol CubeDeviceDelegate;

@interface CubeAccountService : NSObject

/**账号服务代理*/
@property (nonatomic, weak) id<CubeAccountDelegate> accountDelegate;

/**设备代理，默认为空数组*/
@property (nonatomic, weak) id<CubeDeviceDelegate> deviceDelegate;

/**
 账号注册

 @param customString 用户名
 @param password 密码
 @param displayName 显示名称
 @param licenseToken licenseToken
 */
- (void)registerWithCustomString:(NSString *)customString withPassword:(NSString *)password withDisplayName:(NSString *)displayName withLicenseToken:(NSString *)licenseToken;


/**
 登录账号

 @param name 用户名
 @param password 密码
 @param displayName 显示名称
 @param licenseToken licenseToken
 */
- (void)loginWithName:(NSString *)name withPassword:(NSString *)password withDisplayName:(NSString *)displayName andLicenseToken:(NSString *)licenseToken;


/**
 查询设备在线

 @param name 用户名
 @param completionHandler 完成回调
 */
- (void)queryOnlineDeviceWithName:(NSString *)name completionHandler:(void (^ )(NSArray *DeviceArray, CubeErrorInfo *error))completionHandler;


/**
 登出账号，非强制退出
 */
- (void)logout;


/**
 登出账号
 强制退出会挂断通话等信息
 
 @param force 是否强制退出
 */
- (void)logoutWithForce:(BOOL)force;

@end
