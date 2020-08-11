//
//  CubeVideoClipMessage.h
//  CubeEngine
//
//  Created by guoqiangzhu on 15/8/11.
//  Copyright (c) 2015年 Cube Team. All rights reserved.
//

#import "CubeFileMessage.h"

/** 视频消息文件类型枚举。
 * 视频消息文件类型枚举。
 * 应用程序可据此判断需要接收的文件类型。
 */

typedef enum  _CubeVideoFileType {
    CubeVideoFileType_Origin = 1 << 0, /*!< 原文件。*/
    CubeVideoFileType_Thumb = 1 << 1,  /*!< 视频截图帧。*/
} CubeVideoFileType;

/**
 用于发送或接收视频的视频消息类。
 */
@interface CubeVideoClipMessage : CubeFileMessage

/**
 剪辑时长，单位秒
 */
@property (nonatomic, assign) long long duration;

/**
 视频缩略图
 */
@property (nonatomic, strong) NSData *thumbFile;


/**
 缩略图路径
 */
@property (nonatomic, strong) NSString *thumbPath;

/**
 缩略图url
 */
@property (nonatomic, strong) NSString *thumbUrl;

@property (nonatomic, assign) int thumbImageHeight;

@property (nonatomic, assign) int thumbImageWidth;
/**
 构造函数

 @param file 文件二进制
 @param fileName 文件名, 不能为nil
 @param receiver 指定消息接收者
 @param sender 指定消息发送者
 @return 视频消息实体
 */
- (id)initWithFile:(NSData *)file andFileName:(NSString *)fileName andReceiver:(Receiver *)receiver andSender:(Sender *)sender;


/**
 构造函数

 @param filePath 文件路径, 不能为nil
 @param thumbPath 缩略图路径
 @param durations 时长
 @param receiver 指定消息接收者
 @param sender 指定消息发送者
 @return 视频消息实体
 */
- (id)initWithFilePath:(NSString *)filePath andThumbPath:(NSString *)thumbPath andDuration:(long long)durations andReceiver:(Receiver *)receiver andSender:(Sender *)sender;

/**
 构造函数

 @param fileUrl 指定待发送文件url
 @param thumbUrl 指定缩略图url
 @param fileName 文件名
 @param durations 时长
 @param receiver 指定消息接收者
 @param sender 指定消息发送者
 @return 视频消息实体
 */
- (id)initWithFileUrl:(NSURL *)fileUrl andThumbUrl:(NSURL *)thumbUrl andFileName:(NSString *)fileName andDuration:(long long)durations andReceiver:(Receiver *)receiver andSender:(Sender *)sender;


/**
 设置缩略图参数

 @param w 缩略图宽度
 @param h 缩略图高度
 */
- (void)setResolutionWidth:(int)w andHeight:(int)h;

@end
