//
//  Sender.h
//  CubeEngine
//
//  Created by Zhu on 15/5/11.
//  Copyright (c) 2015年 Cube Team. All rights reserved.
//

#import "Peer.h"
/**
 消息发送者类
 */
@interface Sender : Peer

/**
 发送者显示名
 */
@property (nonatomic, strong) NSString *displayName;

/**
 构造函数

 @param name 指定发送者名称
 @return 消息发送者实体
 */
- (id)initWithName:(NSString *)name;

/**
 转字典

 @return 字典
 */
- (NSDictionary *) toJSON;

@end
