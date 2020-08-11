//
//  SmartConferenceConfig.h
//  CubeEngine
//
//  Created by Ashine on 2020/1/9.
//  Copyright © 2020 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SmartConferenceEnum.h"
#import "CubeJSONObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface SmartConferenceConfig : NSObject <CubeJSONObject>

//绑定群组
@property (nonatomic,copy) NSString *bindGroupId;
//会议类型
@property (nonatomic,assign) SmartConferenceType type;
//最大人数
@property (nonatomic,assign) int maxMember;
//开始时间
@property (nonatomic,assign) long startTime;
//会议时长
@property (nonatomic,assign) long durationTime;
//成员可空
@property (nonatomic,strong) NSArray *cubeIds;
//自定义数据
@property (nonatomic,strong) NSDictionary *custom;

@end

NS_ASSUME_NONNULL_END
