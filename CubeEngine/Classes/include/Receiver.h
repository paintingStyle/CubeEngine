//
//  Receiver.h
//  CubeEngine
//
//  Created by Zhu on 15/5/11.
//  Copyright (c) 2015年 Cube Team. All rights reserved.
//

#import "Peer.h"

/**
 消息接收者类
 */
@interface Receiver : Peer


/**
 接收者显示名
 */
@property (nonatomic, strong) NSString *displayName;


/**
  构造函

 @param name 指定接收者名称
 @return 消息接收者实体
 */
- (id)initWithName:(NSString *)name;

/**
 转字典

 @return 字典
 */
- (NSDictionary *) toJSON;


@end
