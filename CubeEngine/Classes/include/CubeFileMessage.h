//
//  CubeFileMessage.h
//  CubeEngine
//
//  Created by Zhu on 15/5/8.
//  Copyright (c) 2015年 Cube Team. All rights reserved.
//

#import "MessageEntity.h"
#import "Receiver.h"
//#define ZIPNEWPROPERTY @"zipProperty"
/**
 文件消息状态
 */
typedef enum _CubeFileMessageState
{
    CubeFileMessageStateNone = 0,
    CubeFileMessageStateUploading = 1,
    CubeFileMessageStateDownloading = 2,
    CubeFileMessageStateSucceed = 3,
    CubeFileMessageStatePaused = 4,
    CubeFileMessageStateFailed = -1
}
CubeFileMessageState;

typedef enum _CubeFileType
{
    CubeFileTypeFile = 0,   //文件
    CubeFileTypeFolder = 1, //文件夹
}CubeFileType;

typedef enum _CubeCompressType
{
    CubeCompressTypeNone = 0,   //未压缩
    CubeCompressTypeZip = 1,    //Zip压缩
    CubeCompressTypeGzip = 2,   //Gzip压缩
}CubeCompressType;

/**
 用于发送或接收文件的文件消息类。
 */
@interface CubeFileMessage : MessageEntity

/** 文件数据*/
@property (nonatomic, strong) NSData *file;

/** 文件名*/
@property (nonatomic, strong) NSString *fileName;

/** 文件处理进度*/
@property (nonatomic, assign) long long progress;

/** 文件大小*/
@property (nonatomic, assign) long long fileSize;

/** 最近修改时间（绝对时间）*/
@property (nonatomic, assign) long long lastModified;

/** 文件url*/
@property (nonatomic, strong) NSString *url;

/** 文件url*/
@property (nonatomic, strong) NSString *filePath;

/** 文件MD5*/
@property (nonatomic, strong) NSString *md5;

@property (nonatomic, strong) NSString *key;

/** 缩略图url*/
@property (nonatomic, strong) NSString *thumbUrl;

///**------新增属性------*/
#ifdef ZIPNEWPROPERTY
/**
 *文件key
 */
@property (nonatomic, assign) CubeFileType fileType;
/**
 *压缩类型
 */
@property (nonatomic, assign) CubeCompressType compressType;

/**
 *压缩文件路径
 */
@property (nonatomic, strong) NSString *compressPath;
#endif
/**
 文件消息状态
 */
@property (nonatomic, assign) CubeFileMessageState fileMessageState;

/**
 构造函数。
 @param fileName 文件名, 不能为nil。
 @param receiver 指定消息接收者。
 */
- (id)initWithFileName:(NSString *)fileName andReceiver:(Receiver *)receiver;

/**
 构造函数
 @param fileName 文件名, 不能为nil。
 @param receiver 指定消息接收者。
 @param file 指定待发送文件。
 */
- (id)initWithFile:(NSData *)file andFileName:(NSString *)fileName andReceiver:(Receiver *)receiver;

/**
 构造函数
 @param fileName 文件名, 不能为nil。
 @param receiver 指定消息接收者。
 @param sender 指定消息发送者。
 @param file 指定待发送文件。
 */

- (id)initWithFile:(NSData *)file andFileName:(NSString *)fileName andReceiver:(Receiver *)receiver andSender:(Sender *)sender;

/**
 @param fileName 文件名, 不能为nil。
 @param receiver 指定消息接收者。
 @param sender 指定消息发送者。
 @param type  指定消息类型。
 @param file 指定待发送文件。
 */
- (id)initWithFile:(NSData *)file andFileName:(NSString *)fileName andMessageType:(CubeMessageType )type andReceiver:(Receiver *)receiver andSender:(Sender *)sender;

/**
 构造函数
 @param fileName 文件名, 不能为nil。
 @param receiver 指定消息接收者。
 @param sender 指定消息发送者。
 @param type  指定消息类型。
 @param url 指定文件url。
 */
- (id)initWithFileURL:(NSURL *)url andFileName:(NSString *)fileName andMessageType:(CubeMessageType )type andReceiver:(Receiver *)receiver andSender:(Sender *)sender;

/**
 构造函数
 @param fileName 文件名, 不能为nil。
 @param receiver 指定消息接收者。
 @param sender 指定消息发送者。
 @param type  指定消息类型。
 @param filePath 指定文件路径。
 */
- (id)initWithFilePath:(NSString *)filePath andFileName:(NSString *)fileName andMessageType:(CubeMessageType )type andReceiver:(Receiver *)receiver andSender:(Sender *)sender;


/**
 转化为字典

 @return 字典
 */
- (NSMutableDictionary *)toJSONObject;


@end

