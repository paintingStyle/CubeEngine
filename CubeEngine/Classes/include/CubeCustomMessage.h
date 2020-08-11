//
//  CubeCustomMessage.h
//  CubeEngine
//
//  Created by guoqiangzhu on 15/9/18.
//  Copyright (c) 2015年 Cube Team. All rights reserved.
//

#import "MessageEntity.h"

/**
 发送或接收自定义消息类。
 */
@interface CubeCustomMessage : MessageEntity

/**消息体*/
@property (nonatomic, strong) NSString *body;

/**
 消息超期时间 单位秒
 */
@property (nonatomic, assign) int expires;

/**
 构造函数
 @param receiver 指定消息接收者。
 */
- (id)initWithReceiver:(Receiver *)receiver;

@end
