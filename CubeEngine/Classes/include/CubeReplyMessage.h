//
//  CubeReplyMessage.h
//  CubeEngine
//
//  Created by jianchengpan on 2018/1/30.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import "MessageEntity.h"

@interface CubeReplyMessage : MessageEntity

-(instancetype)initWithSourceMessage:(MessageEntity *)source andReplyMessage:(MessageEntity *)reply;

/**
 源消息
 */
@property (nonatomic, strong) MessageEntity *source;

/**
 回复消息
 */
@property (nonatomic, strong) MessageEntity *reply;

@end
