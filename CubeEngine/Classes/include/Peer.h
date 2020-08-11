//
//  Peer.h
//  CubeEngine
//
//  Created by Zhu on 15/5/11.
//  Copyright (c) 2015年 Cube Team. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 引擎协作对端描述基类
 每个 Peer 表示一个有效被管理的协作对端
 通过 Peer 可以获得对端的相关信息
 */
@interface Peer : NSObject

/**
  端名称
 */
@property (nonatomic, strong) NSString *name;

/**
 构造方法

 @param name 指定名称
 @return 对端实体
 */
- (id)initWithName:(NSString *)name;

@end
