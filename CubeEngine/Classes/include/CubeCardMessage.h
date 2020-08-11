//
//  CubeCardMessage.h
//  CubeEngine
//
//  Created by Mario on 17/5/3.
//  Copyright © 2017年 CubeTeam. All rights reserved.
//

#import "MessageEntity.h"
#import "CubeCardContent.h"

@interface CubeCardMessage : MessageEntity

/**卡片消息标题*/
@property (nonatomic, copy) NSString *title;

/**卡片消息头像*/
@property (nonatomic, copy) NSString *icon;

/**卡片内容*/
@property (nonatomic, copy) NSString *content;

/**卡片对象*/
@property (nonatomic, strong) NSArray<CubeCardContent *> *cardContents;

/**
 创建一条卡片消息，其中只带有一个卡片内容

 @param title 卡片消息标题
 @param icon 卡片消息图标
 @param content 卡片消息内容
 @param cardContent 卡片对象
 @param receiver 指定消息接收者
 @param sender 指定消息发送者
 @return 实例对象
 */
- (id)initWithCardTitle:(NSString *)title andIcon:(NSString *)icon andContent:(NSString *)content andCardContent:(CubeCardContent *)cardContent andReceiver:(Receiver *)receiver andSender:(Sender *)sender;


/**
 创建一条包含多个卡片内容的卡片消息

 @param title 卡片消息标题
 @param icon 卡片消息图标
 @param content 卡片消息内容
 @param cardContents 卡片对象列表
 @param receiver 指定消息接收者
 @param sender 指定消息发送者
 @return 卡片消息
 */
- (id)initWithCardTitle:(NSString *)title andIcon:(NSString *)icon andContent:(NSString *)content andCardContents:(NSArray<CubeCardContent *> *)cardContents andReceiver:(Receiver *)receiver andSender:(Sender *)sender;

@end
