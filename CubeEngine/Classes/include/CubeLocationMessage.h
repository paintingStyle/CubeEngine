//
//  CubeLocationMessage.h
//  CubeEngine
//
//  Created by Mario on 2017/7/29.
//  Copyright © 2017年 CubeTeam. All rights reserved.
//

/**
 * 地理位置消息
 *
 * @author Mario
 */

#import "MessageEntity.h"

@interface CubeLocationMessage : MessageEntity

/**
 纬度
 */
@property (nonatomic, assign) double lat;

/**
 经度
 */
@property (nonatomic, assign) double lng;

/**
 地址信息
 */
@property (nonatomic, copy) NSString *address;


/**
 构造方法

 @param lat 纬度
 @param lng 经度
 @param address 地址信息
 @return 实体对象
 */
- (id)initWithLocationLat:(double)lat andLng:(double)lng andAddress:(NSString *)address;


/**
 构造方法
 
 @param lat 纬度
 @param lng 经度
 @param address 地址信息
 @param receiver 指定消息接收者
 @param sender 指定消息发送者
 @return 实体对象
 */
- (id)initWithLocationLat:(double)lat andLng:(double)lng andAddress:(NSString *)address andReceiver:(Receiver *)receiver andSender:(Sender *)sender;


/**
 转化为字典
 
 @return 字典
 */
- (NSDictionary *)toJSONObject;

@end
