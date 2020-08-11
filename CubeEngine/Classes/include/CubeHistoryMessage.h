//
//  CubeHistoryMessage.h
//  CubeEngine
//
//  Created by Mario on 17/5/8.
//  Copyright © 2017年 CubeTeam. All rights reserved.
//

#import "MessageEntity.h"

@interface CubeHistoryMessage : MessageEntity

/**
 多条消息SN
 */
@property (nonatomic, strong) NSArray<NSString *> *sns;

///**
// 多条消息 旧
// */
//@property (nonatomic, strong) NSArray *histories;

/**
 多条消息 新增
 */
@property (nonatomic, strong) NSArray *messages;
/**
 超文本消息url
 */
@property (nonatomic,strong) NSString *url;
/**
 构造函数
 @param receiver 指定消息接收者Cube。
 @param sender 指定消息发送者。
 @param sns 消息sn数组
 */
- (id)initWithSNs:(NSArray<NSString *> *)sns andReceiver:(Receiver *)receiver andSender:(Sender *)sender;

/**
 通过消息sns设置历史消息内容。  // 通过sns查询 本地组装消息集合 超过TCP限制 上传文件服务器并且组装url

 @param sns 消息sn数组
 */
- (void)addMessages:(NSArray <NSString *>*)sns;

/**
 返回历史消息内容。

 @param url 历史消息url
 @param completionHandler 返回历史消息内容回调
 */
+ (void)getMessages:(NSString *)url completionHandler:(void (^)(NSArray <MessageEntity *>*messages,BOOL result))completionHandler;
@end
