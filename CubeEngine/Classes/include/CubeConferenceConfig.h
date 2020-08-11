//
//  CubeConferenceConfig.h
//  CubeEngine
//
//  Created by 陆川 on 2018/3/20.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CubePrerequisites.h"


@interface CubeConferenceConfig : NSObject
/**
 依赖群组
 */
@property (nonatomic, copy) NSString *groupId;
/**
 参会人员
 */
@property (nonatomic, strong) NSArray<NSString *> *cubeIds;
/**
 会议类型
 */
@property (nonatomic, assign) ConferenType conferenType;
/**
 最大人数
 */
@property (nonatomic, assign) NSInteger maxMember;
/**
 是否容屏
 */
@property (nonatomic, assign) BOOL isMux;
/**
 有效时间
 */
@property (nonatomic, assign) long long expired;
/**
 强制覆盖依赖群组下关联的上一个会议
 */
@property (nonatomic, assign) BOOL force;
/**
 会议号(如果是Cisco等传统会议类型，同时会议号不为空，则需要以会员号为key来生成conferenceId，并且将申请者加入到conferenceId组中)
 */
@property (nonatomic, copy) NSString *number;

/**
 会议配置

 @param groupId 依赖群组
 @param cubeIds 参会人员
 @param conferenType 会议类型
 @param maxMember 大人数
 @param isMux 是否容屏
 @param expired 有效时间
 @param force 强制覆盖依赖群组下关联的上一个会议
 @return CubeConferenceConfig
 */
+ (instancetype)conferenceConfigWithGroupId:(NSString *)groupId cubeIds:(NSArray<NSString *> *)cubeIds conferenceType:(ConferenType)conferenType maxMember:(int)maxMember isMux:(BOOL)isMux expired:(long long)expired force:(BOOL)force;

/**
  会议配置

 @param groupId 依赖群组
 @param cubeIds 参会人员
 @param conferenType 会议类型
 @param maxMember 大人数
 @param isMux 是否容屏
 @param expired 有效时间
 @param force 强制覆盖依赖群组下关联的上一个会议
 @param number  会议号
 @return CubeConferenceConfig
 */
+ (instancetype)conferenceConfigWithGroupId:(NSString *)groupId cubeIds:(NSArray<NSString *> *)cubeIds conferenceType:(ConferenType)conferenType maxMember:(int)maxMember isMux:(BOOL)isMux expired:(long long)expired force:(BOOL)force number:(NSString *)number;

- (NSDictionary *)toDictionary;

- (NSString *)toJSONStr;

@end

