//
//  SmartMember.h
//  CubeEngine
//
//  Created by Ashine on 2020/1/9.
//  Copyright © 2020 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SmartConferenceService.h"
#import "CubeJSONObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface SmartMemberStatus : NSObject <CubeJSONObject>

//邀请时间
@property (nonatomic,assign) long inviteTime;
//加入时间
@property (nonatomic,assign) long joinTime;
//退出时间
@property (nonatomic,assign) long quitTime;
//主持人
@property (nonatomic,assign) BOOL present;
//发言状态
@property (nonatomic,assign) BOOL speak;
//旁听状态
@property (nonatomic,assign) BOOL hear;
//看见权限
@property (nonatomic,assign) BOOL watch;
//被踢状态
@property (nonatomic,assign) BOOL kick;
//视频状态
@property (nonatomic,assign) BOOL video;
//音频状态
@property (nonatomic,assign) BOOL audio;
//媒体认证
@property (nonatomic,copy) NSString *token;

@end


@interface SmartMember : NSObject <CubeJSONObject>


//会议ID
@property (nonatomic,copy) NSString *conferenceId;
//成员ID
@property (nonatomic,copy) NSString *cubeId;

//拥有角色 [SmartMemberRoleType]
@property (nonatomic,strong) NSArray *roles;
//成员状态
@property (nonatomic,strong) SmartMemberStatus *status;
//参会设备ID
@property (nonatomic,copy) NSString *deviceId;
//变更时间
@property (nonatomic,assign) long updateTime;
//名称
@property (nonatomic,copy) NSString *displayName;
//头像
@property (nonatomic,copy) NSString *photo;
//自定义数据
@property (nonatomic,strong) NSDictionary *custom;


/**
 * 主持人控制
 *
 * @param enabled
 * @param callback
 */
-(void)presenter:(BOOL)enabled completion:(SmartControlCallBack)callback failure:(SmartErrorCallBack)failure;

/**
 * 主讲人控制
 *
 * @param tobe
 * @param callback
 */
-(void)speaker:(BOOL)enabled completion:(SmartControlCallBack)callback failure:(SmartErrorCallBack)failure;

/**
 * 控听
 *
 * @param canHear
 * @param callback
 */
-(void)hear:(BOOL)enabled completion:(SmartControlCallBack)callback failure:(SmartErrorCallBack)failure;

/**
 * 控言
 *
 * @param canSpeak
 * @param callback
 */
-(void)speak:(BOOL)enabled completion:(SmartControlCallBack)callback failure:(SmartErrorCallBack)failure;

/**
 * 控视
 *
 * @param canWatch
 * @param callback
 */
-(void)watch:(BOOL)enabled completion:(SmartControlCallBack)callback failure:(SmartErrorCallBack)failure;

/**
 * 踢人
 *
 * @param callback
 */
-(void)kick:(SmartControlCallBack)callback failure:(SmartErrorCallBack)failure;


@end

NS_ASSUME_NONNULL_END
