//
//  CubeTextMessage.h
//  CubeEngine
//
//  Created by Zhu on 15/5/8.
//  Copyright (c) 2015年 Cube Team. All rights reserved.
//

#import "MessageEntity.h"

/**
 文本形式消息。
 */
@interface CubeTextMessage : MessageEntity

/**
 消息内容
 */
@property (nonatomic , strong) NSString *content;

/**
 构造函数

 @param receiver 指定消息接收者
 @return 消息实体
 */
- (id)initWithReceiver:(Receiver *)receiver;

/**
 构造函数

 @param content 消息内容
 @return 消息实体
 */
- (id)initWithContent:(NSString *)content;


/**
 构造函数

 @param content 指定消息内容
 @param receiver 指定消息接收者
 @return 消息实体
 */
- (id)initWithMessageContent:(NSString *)content andReceiver:(Receiver *)receiver;


/**
 转化为字典

 @return 字典
 */
- (NSDictionary *)toJSONObject;
@end
