//
//  CubeRichContentMessage.h
//  CubeEngine
//
//  Created by yanghuiliang on 2017/7/21.
//  Copyright © 2017年 CubeTeam. All rights reserved.
//

#import "MessageEntity.h"

@interface CubeRichContentMessage : MessageEntity
/**
 多条消息
 */
@property (nonatomic, strong) NSArray <MessageEntity *>*richcontents;
@end
