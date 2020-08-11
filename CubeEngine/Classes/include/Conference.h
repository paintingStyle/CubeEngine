//
//  Conference.h
//  CubeEngine
//
//  Created by Zhu Guoqiang on 15/10/12.
//  Copyright (c) 2014-2016 Cube Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CubePrerequisites.h"


/**
 会议
 */
@interface Conference : NSObject

/**绑定的群组*/
@property (nonatomic, copy) NSString *bindGroup;

/**会议ID*/
@property (nonatomic, copy) NSString *conferenceId;

/**会议房间号*/
@property (nonatomic, strong) NSString *number;

/**会议最多人数限制*/
@property (nonatomic, assign) int maxMember;

/**会议人数*/
@property (nonatomic, assign) int memberSize;

/**会议的ip地址*/
@property (nonatomic, copy) NSString *host;

/**会议的创建者*/
@property (nonatomic, copy) NSString *founder;

/**会议的主持人数组*/
@property (nonatomic, strong) NSMutableArray *presenters;

/** 会议关闭时间*/
@property (nonatomic, assign) long long closed;

/**会议创建时间*/
@property (nonatomic, assign) long long created;

/**会议有效期*/
@property (nonatomic, assign) long long expired;

//! 有否有游客
@property (nonatomic, assign) BOOL hasGuest;

/**会议视频分辨率*/
@property (nonatomic, strong, readonly) NSString *videoSize;

/** 是否容屏*/
@property (nonatomic, assign) BOOL isMergeScreen;
/**会议类型*/
@property (nonatomic, assign) ConferenType type;

/**
 对会议进行操作的时间
 */
@property (nonatomic, assign) long long currentTimestamp;

/**
 当前会议成员信息
 
 @discusstion members存储方式{memberId:member}
 */
@property (nonatomic, strong) NSDictionary *members;


/**
 解析会议对象

 @param dict 会议信息字典
 @return 会议对象
 */
+ (Conference *)parse:(NSDictionary *)dict;


/**
 解析会议action

 @param pType action类型字符串
 @return 会议类型枚举
 */
+ (CubeConferenceAction)parseConferenceAction:(NSString *)pType;

/**
 字符串转会议类型枚举

 无法识别的会议类型字符串会被转换成ConferenTypeUnKnown
 @param typeString 会议类型字符串
 @return 会议类型枚举
 */
+(ConferenType)conferenceTypeWithString:(NSString *)typeString;

/**
 会议类型转字符串
 ConferenTypeUnKnown 会被转换成"unknown"
 @param type 会议类型枚举
 @return 相应的字符串
 */
+(NSString *)confernceTypeStringWithType:(ConferenType)type;

/**
 生成字典
 
 @return 字典
 */
- (NSMutableDictionary *)toJSON;

@end

/** 
 会议成员
 */
@interface Member : NSObject


/**
 用户ID
 */
@property (nonatomic, copy) NSString *cubeId;

/**
 听
 */
@property (nonatomic, assign) BOOL canHear;

/**
 说
 */
@property (nonatomic, assign) BOOL canSpeak;

/**
 看
 */
@property (nonatomic, assign) BOOL canWatch;

/**
 主讲
 */
@property (nonatomic, assign) BOOL hasFloor;

/**
 加入时间
 */
@property (nonatomic, assign) long long joinTime;

/**
 是否加入
 */
@property (nonatomic, assign) BOOL joined;

/**
 是否已经呼叫会议(先join，再呼叫)
 */
@property (nonatomic, assign) BOOL call;

/**
 踢人
 */
@property (nonatomic, assign) BOOL kicked;

/**
 退出时间
 */
@property (nonatomic, assign) long long quitTime;

/**
 是否用视频呼叫
 */
@property (nonatomic, assign) BOOL videoEnabled;

/**
 是否用音频呼叫
 */
@property (nonatomic, assign) BOOL audioEnabled;

/**
 设备ID
 */
@property (nonatomic, copy) NSString *deviceId;

/**
 talking状态
 */
@property (nonatomic,assign) BOOL talking;

/**
 sfu token令牌
 */
@property (nonatomic, copy) NSString *sfuToken;


/**
 构造方法

 @param dict 字典
 @return 实例对象
 */
- (instancetype)initWithDict:(NSDictionary *)dict;


/**
 生成字典

 @return 字典
 */
- (NSMutableDictionary *)toJSON;

@end


/**
 成员动作
 */
@interface MemberAction : NSObject

/**
 用户ID
 */
@property (nonatomic, copy) NSString *cubeId;

/**
 用户动作列表
 */
@property (nonatomic, strong) NSArray *actions;

/**
 设备ID
 */
@property (nonatomic, copy) NSString *deviceId;

/**
 动作原因，可以为空
 {
    "code":"",
    "desc":""
 }
 */
@property (nonatomic, strong) NSDictionary *reason;

/**
 创建实例对象，并使用字典初始化

 @param dic 初始化信息字典
 @return 实例对象
 */
+(MemberAction *)memberActionWithDictionary:(NSDictionary *)dic;

@end

