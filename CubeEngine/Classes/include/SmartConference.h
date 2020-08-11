//
//  SmartConference.h
//  CubeEngine
//
//  Created by Ashine on 2020/1/9.
//  Copyright © 2020 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SmartConferenceEnum.h"
#import "CubeJSONObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface SmartConference : NSObject <CubeJSONObject>


//会议ID
@property (nonatomic,copy) NSString *conferenceId;
//绑定群组
@property (nonatomic,copy) NSString *bindGroupId;
//会议类型
@property (nonatomic,assign) SmartConferenceType type;
//当前人数
@property (nonatomic,assign) int memberSize;
//最大人数
@property (nonatomic,assign) int maxMember;
//创建时间
@property (nonatomic,assign) int createTime;
//销毁时间
@property (nonatomic,assign) int destroyTime;
//开始时间
@property (nonatomic,assign) int startTime;
//会议时长
@property (nonatomic,assign) int durationTime;
//自定义数据
@property (nonatomic,strong) NSDictionary *custom;
//域
@property (nonatomic,copy) NSString *domain;
//房间ID
@property (nonatomic,copy) NSString *roomId;
//密码
@property (nonatomic,copy) NSString *password;
//名称
@property (nonatomic,copy) NSString *name;
//头像
@property (nonatomic,copy) NSString *photo;


@end

NS_ASSUME_NONNULL_END
