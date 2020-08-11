//
//  CubeMessageService.h
//  CubeEngine
//
//  Created by guoqiangzhxu on 16/2/18.
//  Copyright © 2016年 Cube Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CubePrerequisites.h"
#import "CubeTextMessage.h"
#import "CubeFileMessage.h"
#import "CubeImageMessage.h"
#import "CubeCustomMessage.h"
#import "CubeVoiceClipMessage.h"
#import "CubeVideoClipMessage.h"
#import "CubeWhiteboardMessage.h"
#import "CubeCardMessage.h"
#import "CubeHistoryMessage.h"
#import "CubeLocationMessage.h"

/**
 消息服务
 */
@interface CubeMessageService : NSObject


/**
 消息服务代理
 */
@property (nonatomic, weak) id<CubeMessageServiceDelegate> messageServiceDelegate;


/**
 消息状态代理
 */
@property (nonatomic, weak) id<CubeMessageStateDelegate> messageStateDelegate;


/**
 发送消息
 
 @param message 消息
 @return 如果消息被引擎正确处理则返回 \c YES ，否则返回 \c NO
 */
-(BOOL)sendMessage:(MessageEntity *)message;

/**
 发送指定的文本消息
 
 @param message 指定待发送的文本消息对象
 @return 如果消息被引擎正确处理则返回 \c YES ，否则返回 \c NO
 */
- (BOOL)sendTextMessage:(CubeTextMessage *)message;

/**
 发送文件消息
 即上传文件类型消息
 @param message 文件消息
 @return 如果消息被引擎正确处理则返回 \c YES ，否则返回 \c NO
 */
- (BOOL)sendFileMessage:(CubeFileMessage *)message;


/**
 转发消息
 旧API 废弃
 @param cubeIDs 接收者列表
 @param messageSNs 指定转发消息sn数组
 @return 如果消息被引擎正确处理则返回 \c YES ，否则返回 \c NO
 */
- (BOOL)forwardMessageWithCubes:(NSArray *)cubeIDs andMessages:(NSArray *)messageSNs;

/**
 转发消息
 新API 使用中
 @param cubeIds 接收者列表
 @param sn 消息唯一标示
 @param header 自定义Header数据
 @return 如果消息被引擎正确处理则返回 \c YES ，否则返回 \c NO
 */
- (BOOL)forwardMessage:(NSArray *)cubeIds withSn:(NSString *)sn withHeader:(NSDictionary *)header;

/**
 消息转发添加留言功能
 
 *为保证被转发消息和留言的消息保证特定的顺序(被转发消息在前,评论消息在后),转发消息指令参数添加留言消息列表
 
 @param cubeIds 接收者
 @param sns 待转发的消息列表
 @param header 自定义转发的消息头
 @param messages 留言消息列表(可选) ※消息体数组
 @return 引擎是否处理成功
 */
- (BOOL)forwardMessage:(NSArray *)cubeIds withSns:(NSArray *)sns withHeader:(NSDictionary *)header withMessages:(NSArray <MessageEntity *> *)messages;

/**
 撤回指定的消息
 
 @param messageSN 指定待撤回的文本消息ID
 @return 如果消息被引擎正确处理则返回 \c YES ，否则返回 \c NO
 */
- (BOOL)recallMessage:(long long)messageSN;


/**
 查询历史消息
 
 @param cubeId cube号
 @param timestamp 时间戳
 @param max 大小
 @return 如果历史消息查询被引擎正确处理则返回 \c YES ，否则返回 \c NO
 */
- (BOOL)queryHistory:(NSString *)cubeId withTimestamp:(long long)timestamp withMax:(int)max;

/**
 发送指定的白板桢消息
 
 @param whiteboard 指定待发送的白板消息对象
 @return 如果消息被引擎正确处理则返回 \c YES ，否则返回 \c NO
 */
- (BOOL)sendWhiteboardMessage:(CubeWhiteboardMessage *)whiteboard;

/**
 下载未知类型的文件消息
 
 @return 如果消息被引擎正确处理则返回 \c YES ，否则返回 \c NO
 */
- (BOOL)acceptMessage:(MessageEntity *)message;

/**
 取消上传
 
 @param message 文件x消息
 @return 如果消息被引擎正确处理则返回 \c YES ，否则返回 \c NO
 */
- (BOOL)cancelUploadFileMessage:(CubeFileMessage *)message;

/**
 下载消息中文件
 
 @param message 消息
 @param messageOperator 下载类型
 @return 如果消息被引擎正确处理则返回 \c YES ，否则返回 \c NO
 */
- (BOOL)acceptMessage:(MessageEntity *)message withMessageOperator:(CubeMessageOperator)messageOperator;

/**
 取消下载
 
 @param fileMessage 文件消息
 @param messageOperator 下载类型
 @return 如果消息被引擎正确处理则返回 \c YES ，否则返回 \c NO
 */
-(BOOL)cancelDownloadFileMessage:(CubeFileMessage *)fileMessage withMessageOperator:(CubeMessageOperator)messageOperator;

/**
 拒绝并终止来自服务器的指定文件消息内的文件
 
 @param message 指定文件消息
 @return 如果消息被引擎正确处理则返回 \c YES ，否则返回 \c NO
 */
- (BOOL)rejectFileMessage:(CubeFileMessage *)message;


/**
 返回未被处理的消息
 
 @return 返回未被处理的消息列表
 */
- (NSArray *)getPendingFileMessages;


/**
 发送指定的自定义消息
 
 @param message 指定待发送的自定义消息对象
 @return 如果消息被引擎正确处理则返回 \c YES ，否则返回 \c NO
 */
- (BOOL)sendCustomMessage:(CubeCustomMessage *)message;

/**
 删除消息
 
 @param sn 序列号
 @return 如果消息被引擎正确处理则返回 \c YES ，否则返回 \c NO
 */
- (BOOL)deleteMessage:(long long)sn;


/**
 存储消息
 
 @param messageEntity 消息实体
 @param completionHandler 处理回调
 */
- (void)saveMessage:(MessageEntity *)messageEntity completionHandler:(void (^)(MessageEntity *savedMessage,BOOL result))completionHandler;

///**
// （旧接口) 已废弃
// - 消息回执/sn以及sn之前的消息都要回执
// + 离线回执
//
// - @param sn 消息sn
// - @return 如果消息被引擎正确处理则返回 \c YES ，否则返回 \c NO
// + @param cube [群组/个人ID,群组/个人ID]
// + @return  如果消息被引擎正确处理则返回 \c YES ，否则返回 \c NO
// */
//- (BOOL)sendAllMessageReceipt:(long long)sn ;


/**
 新接口
 回执某个会话某个时间点之前的所有未回执消息
 @param sessionId 会话ID
 @param timestamp 回执该时间点之前的所有未回执的消息
 @return 如果消息被引擎正确处理则返回 \c YES ，否则返回 \c NO
 */
- (BOOL)sendReceiptMessages:(NSString *)sessionId andTimestamp:(long long)timestamp;

/**
 检索消息
 
 @param sn 序列号
 @return 如果消息被引擎正确处理则返回 \c YES ，否则返回 \c NO
 */
- (BOOL)queryMessage:(long long)sn;

/**
 检索本地消息
 
 @param sn 序列号
 @param completionHandler 回调
 */
- (void)queryDBMessage:(long long)sn completionHandler:(void (^)(MessageEntity *queryMessage,BOOL result))completionHandler;
/**
 发送指定的卡片消息
 
 @param message 指定待发送的卡片消息对象
 @return 如果消息被引擎正确处理则返回 \c YES ，否则返回 \c NO
 */
- (BOOL)sendCardMessage:(CubeCardMessage *)message;

/**
 发送指定的历史消息
 
 @param message 指定待发送的历史消息对象
 @return 如果消息被引擎正确处理则返回 \c YES ，否则返回 \c NO
 */
- (BOOL)sendHistoryMessage:(CubeHistoryMessage *)message;

/**
 重发消息
 
 @param sn 序列号
 @return 如果消息被引擎正确处理则返回 \c YES ，否则返回 \c NO
 */
- (BOOL)resendMessage:(long long)sn;

/**
 发送位置消息
 
 @param message 指定待发送的位置消息对象
 @return 如果消息被引擎正确处理则返回 \c YES ，否则返回 \c NO
 */
- (BOOL)sendLocationMessage:(CubeLocationMessage *)message;



/**
 发送消息未读数角标列表到服务器进行统计同步
 
 @param badges 未读数角标列表
 @return 该发送被引擎正确处理则返回 \c YES ，否则返回 \c NO
 */
- (BOOL)sendUnreadBadgesArray:(NSArray *)badges;

/**
 获取某个会话
 新版http接口
 @param sessionId 会话ID
 @param startTime 同步特定时间段的开始时间
 @param endTime 同步特定时间段的结束时间
 @param count 同步的消息最大数量
 */
- (void)getHistoryMessage:(NSString*) sessionId andStartTime:(long long) startTime andEndTime:(long long) endTime andCount:(int) count;
#pragma mark - query message

/**
 根据sn查询本地消息
 
 @param sn 消息sn
 @return 消息实体
 */
-(MessageEntity *)messageWithSN:(long long)sn;

/**
 根据sn查询本地消息
 
 @param sns sns列表
 @return 消息列表
 */
-(NSArray *)messagesWithSNS:(NSArray<NSString *> *)sns;

#pragma mark - sync message
/**
 同步最近未读消息列表
 同步时间，取内部保存的时间。
 */
- (void)syncMessages;
/**
 同步最近回执列表，同步成功后，进行离线消息拉取
 */
- (void)syncReceiptList;
@end
