//
//  CubeImageMessage.h
//  CubeEngine
//
//  Created by guoqiangzhu on 15/8/11.
//  Copyright (c) 2015年 Cube Team. All rights reserved.
//

#import "CubeFileMessage.h"


/**
 * 图片消息文件类型枚举。
 * 应用程序可据此判断需要接收的文件类型。
 */
typedef enum  _CubeImageFileType {
    CubeImageFileType_Origin = 1 << 0, /*!< 原图。*/
    CubeImageFileType_Thumb = 1 << 1,  /*!< 缩略图。*/
} CubeImageFileType;

/**
 用于发送或接收图片的图片消息类
 */
@interface CubeImageMessage : CubeFileMessage

/** 缩略图*/
@property (nonatomic, strong) NSData *thumbFile;

/** 缩略图url*/
@property (nonatomic, strong) NSString *thumbUrl;

/** 文件类型*/
@property (nonatomic, assign) CubeImageFileType imageFileType;

/** 缩略文件路径*/
@property (nonatomic, strong) NSString *thumbPath;


/**
 图片高度
 */
@property (nonatomic, assign) int height;


/**
 图片宽度
 */
@property (nonatomic, assign) int width;

/**
 构造函数
 @param fileName 文件名, 不能为nil。
 @param receiver 指定消息接收者。
 @param sender 指定消息发送者。
 @param file 指定待发送文件。
 */
- (id)initWithFile:(NSData *)file andFileName:(NSString *)fileName andReceiver:(Receiver *)receiver andSender:(Sender *)sender;

/**
 构造函数
 @param fileName 文件名, 不能为nil。
 @param receiver 指定消息接收者。
 @param sender 指定消息发送者。
 @param fileUrl 指定待发送文件url。
 @param thumbUrl 指定缩略图url。
 */
- (id)initWithFileUrl:(NSURL *)fileUrl andThumbUrl:(NSURL *)thumbUrl andFileName:(NSString *)fileName andReceiver:(Receiver *)receiver andSender:(Sender *)sender;

/**
 构造函数
 @param fileName 文件名, 不能为nil。
 @param receiver 指定消息接收者。
 @param sender 指定消息发送者。
 @param filePath 指定待发送文件路径。
 @param thumbPath 指定缩略图路径。
 */
- (id)initWithFilePath:(NSString *)filePath andThumbPath:(NSString *)thumbPath andFileName:(NSString *)fileName andReceiver:(Receiver *)receiver andSender:(Sender *)sender;

/**
 设置图片大小
 @param w 宽度。
 @param h 高度。
 */
- (void)setImageWidth:(int)w andHeight:(int)h;

@end
