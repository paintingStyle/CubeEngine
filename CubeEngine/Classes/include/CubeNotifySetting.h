//
//  CubeNotifySetting.h
//  CubeEngine
//
//  Created by Ashine on 2019/4/16.
//  Copyright © 2019 CubeTeam. All rights reserved.
//

#ifndef CubeNotifySetting_h
#define CubeNotifySetting_h

#import <Foundation/Foundation.h>


typedef enum : NSUInteger {
    CubeNotifySettingPolicyTypePersonal = 1, // 个人
    CubeNotifySettingPolicyTypeGroup,    // 群组
    CubeNotifySettingPolicyTypeAll,      // 全局
} CubeNotifySettingPolicyType;


@interface CubeNotifySetting : NSObject


/**
 * 数据唯一识别符
 */

//@property (nonatomic,strong) NSString *identify;

/**
 * 1个人 2群组 3全局
 */
@property (nonatomic,assign) CubeNotifySettingPolicyType policyType;

/**
 * cube号/群组号
 */
@property (nonatomic,strong) NSString *policyTo;

/**
 * 是否显示推送详情
 */
@property (nonatomic,assign) BOOL details;

/**
 * 是否免打扰，true为可以打扰,false不能打扰,要判断免打扰时间
 */
@property (nonatomic,assign) BOOL disturb;

/**
 * HH:mm
 * 免打扰开始时间  24小时制   不传时间表示持续保持状态
 */
@property (nonatomic,strong) NSString *disStartTime;

/**
 * 免打扰结束时间  24小时制，结束时间小于开始时间表示隔天
 */
@property (nonatomic,strong) NSString *disEndTime;

/**
 * 是否开启声音  true为开启声音,false为静音 (暂不提供)
 */
//@property (nonatomic,assign) BOOL sound;

/**
 * 静音开始时间    不传时间表示一直持续,传了时间则根据时间静音
 */
@property (nonatomic,strong) NSString *souStartTime;

/**
 静音结束时间
 */
@property (nonatomic,strong) NSString *souEndTime;

/**
 是否震动 (暂不提供)
 */
//@property (nonatomic,assign) BOOL vibrate;


/**
 更新时间(毫秒时间戳)
 */
@property (nonatomic, assign) long updatedTime;

@end


#endif /* CubeNotifySetting_h */
