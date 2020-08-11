//
//  CubeFileInfo.h
//  CubeEngine
//
//  Created by Zhu Guoqiang on 16/6/1.
//  Copyright (c) 2016 Cube Team. All rights reserved.
//

#ifndef CubeFileInfo_h
#define CubeFileInfo_h

#import <Foundation/Foundation.h>

/** 一般文件类型描述。
 */
typedef enum _CubeFileType {
    /** 文件夹类型。 */
    CubeFileTypeDir = 1,
    /** PDF类型。 */
    CubeFileTypePDF = 2,
    /** DOC类型。 */
    CubeFileTypeDOC = 3,
    /** EXCEL类型。 */
    CubeFileTypeEXCEL = 4,
    /** PPT类型。 */
    CubeFileTypePPT = 5,
    /** 图片类型。 */
    CubeFileTypeImage = 11,
    /** OFFICE类型。 */
    CubeFileTypeOFFIC = 12,
    /** 视频类型。 */
    CubeFileTypeVideo = 13,
    /** 音频类型。 */
    CubeFileTypeAudio = 14,
    /** 应用类型。 */
    CubeFileTypeApp = 15,
    /** 压缩包类型。 */
    CubeFileTypeZip = 16,
    /** 白板类型。 */
    CubeFileTypeWhiteboard = 20,
    /** 其他常规文件类型。 */
    CubeFileTypeNormal = 99,
    /** 未知类型 */
    CubeFileTypeUnknown = 100

} CubeFileType;


/** 文件操作权限描述。
 */
typedef enum _CubeFilePermission {
    /** 可读文件内容。 */
    CubeFilePermRead = 1<<0,
    /** 可创建新文件。 */
    CubeFilePermNewFile = 1<<1,
    /** 可创建新目录。 */
    CubeFilePermNewFolder = 1<<2,
    /** 可移动文件或目录。 */
    CubeFilePermMove = 1<<3,
    /** 可重命名文件或目录。 */
    CubeFilePermRename = 1<<4,
    /** 可删除文件或目录。 */
    CubeFilePermDelete = 1<<5,
    /** 可下载文件数据。 */
    CubeFilePermDownload = 1<<6,
    /** 可分享文件。 */
    CubeFilePermShare = 1<<7

} CubeFilePermission;


/** 文件信息类。
 *
 * 文件信息类描述了一个可被有效管理的输出传输单元。
 * 该类是所有可被远程传输的文件对象。
 *
 */
@interface CubeFileInfo : NSObject

/** 序列号。 */
@property (nonatomic, strong) NSString *SN;

/** 创建时间。 */
@property (nonatomic, assign) long long createdTime;

/** 权限。 */
@property (nonatomic, assign) CubeFilePermission permission;

/** 文件路径。 */
@property (nonatomic, strong) NSString *filePath;

/** 文件数据。 */
@property (nonatomic, strong) NSData *fileData;

/** 文件URL file:///xxx*/
@property (nonatomic, strong) NSURL *fileUrl;

/** 缩略图URL */
@property (nonatomic, strong) NSURL *thumbUrl;

/** 创建者 */
@property (nonatomic, strong) NSString *founder;

/** 文件名 */
@property (nonatomic, strong) NSString *fileName;

/**偏移量*/
@property (nonatomic, assign) long long offset;

/** 文件大小 */
@property (nonatomic, assign) long long fileSize;

/** 文件类型 */
@property (nonatomic, assign) CubeFileType fileType;

/** 父文件夹 */
@property (nonatomic, strong) CubeFileInfo *parentFile;


/**
 上传进度
 */
@property (nonatomic, assign) long long uploadProgress;


/**
 下载进度
 */
@property (nonatomic, assign) long long downloadProgress;

/**
 初始化方法

 @param dict 传进来的dict

 @return 实例对象
 */
+ (CubeFileInfo *)parse:(NSDictionary *)dict;
/** 使用文件 URL 进行初始化。
 */
- (id)initWithFileUrl:(NSURL *)fileUrl;

/** 使用文件 URL 进行初始化。
 */
- (id)initWithFileUrl:(NSURL *)fileUrl andFileType:(CubeFileType)fileType;

/** 描述信息。
 */
- (NSString *)description;

@end

#endif
