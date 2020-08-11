//
//  CubeVoiceClipMessage.h
//  CubeEngine
//
//  Created by guoqiangzhu on 15/8/11.
//  Copyright (c) 2015年 Cube Team. All rights reserved.
//

#import "CubeFileMessage.h"


/**
 用于发送或接收音频的音频消息类
 */
@interface CubeVoiceClipMessage : CubeFileMessage

/**
 时长，单位秒
 */
@property (nonatomic, assign) long long duration;

/**
 构造函数

 @param file 文件二进制
 @param fileName 文件名, 不能为nil
 @param receiver 指定消息接收者
 @param sender 指定消息发送者
 @return 音频消息实体
 */
- (id)initWithFile:(NSData *)file andFileName:(NSString *)fileName andReceiver:(Receiver *)receiver andSender:(Sender *)sender;


/**
 构造函数

 @param path 文件路径, 不能为nil
 @param durations 时长
 @param receiver 指定消息接收者
 @param sender 指定消息发送者
 @return 音频消息实体
 */
- (id)initWithFilePath:(NSString *)path andDuration:(long long)durations andReceiver:(Receiver *)receiver andSender:(Sender *)sender;



/**
 构造函数

 @param fileUrl 指定待发送文件url
 @param fileName 文件名
 @param durations 时长
 @param receiver 指定消息接收者
 @param sender 指定消息发送者
 @return 音频消息实体
 */
- (id)initWithFileUrl:(NSURL *)fileUrl andFileName:(NSString *)fileName andDuration:(long long)durations andReceiver:(Receiver *)receiver andSender:(Sender *)sender;

@end
