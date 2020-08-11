//
//  CubeFileManagerService.h
//  CubeEngine
//
//  Created by Zhu Guoqiang on 16/5/30.
//  Copyright (c) 2014-2016 Cube Team. All rights reserved.
//

#ifndef CubeFileManagerService_h
#define CubeFileManagerService_h

#import <Foundation/Foundation.h>
#import "CubeFileInfo.h"
#include "CubePrerequisites.h"

/** 文件管理服务。
 *
 * 用于管理文件操作。
 *
 */
@interface CubeFileManagerService : NSObject

/**
 状态代理
 */
@property (nonatomic, weak) _Nullable id <CubeFileManagerStatusDelegate>fileManagerStatusDelegate;

/**
 管理器代理
 */
@property (nonatomic, weak) _Nullable id <CubeFileManagerDelegate>fileManagerDelegate;

/**
 文件操作代理
 */
@property (nonatomic, weak) _Nullable id <CubeFileOperationDelegate>fileOperationDelegate;


/**
 上传文件

 @param fileInfo 待上传文件
 @param folder 文件夹名
 */
- (void)uploadToFolder:(CubeFileInfo *_Nullable)fileInfo withFolder:(NSString *_Nullable)folder;

/**
 上传文件

 @param fileInfo 待上传文件
 @param parent 上传到该文件夹
 */
- (void)uploadFile:(CubeFileInfo *_Nullable)fileInfo withParent:(CubeFileInfo *_Nullable)parent;

/**
 上传文件
 
 @param fileInfo 待上传文件
 @param parentSN 上传到指定文件
 */
- (void)upload:(CubeFileInfo *_Nullable)fileInfo with:(NSString *_Nullable)parentSN;

/**
 上传文件
 
 @param fileInfo 待上传文件
 @param parent 上传的目标文件夹
 @param folderSN 文件夹的SN
 */
- (void)uploadFile:(CubeFileInfo *_Nullable)fileInfo withParent:(CubeFileInfo *_Nullable)parent withFolder:(NSString *_Nullable)folder withFolderSN:(NSString *_Nullable)folderSN;

/**
 暂停上传

 @param file 待上传文件
 @param completionHandler 回调
 */
- (void)pauseUploadFile:(CubeFileInfo *_Nonnull)file withCompletionHandler:(void(^_Nullable)(CubeFileInfo * _Nullable file, NSError * _Nullable error))completionHandler;

/**
 恢复上传

 @param file 待上传文件
 @param completionHandler 回调
 */
- (void)resumeUploadFile:(CubeFileInfo *_Nonnull)file withCompletionHandler:(void (^_Nullable)(CubeFileInfo * _Nullable, NSError * _Nullable))completionHandler;

/**
 取消上传

 @param fileInfo 待上传文件
 */
- (void)cancelUpload:(CubeFileInfo *_Nonnull)fileInfo;

/**
 下载文件

 @param fileSN 待下载文件sn
 */
- (void)downloadFile:(NSString *_Nonnull)fileSN;

/**
 暂停下载

 @param fileSN 待下载文件sn
 @param completionHandler 回调
 */
- (void)pauseDownloadFile:(NSString *_Nonnull)fileSN WithCompletionHandler:(void (^ _Nonnull)(NSString * _Nullable fileSN, NSError * _Nullable error))completionHandler;

/** 恢复下载
 *
 * @param fileSN 正在下载的文件sn
 */
- (void)resumeDownloadFile:(NSString *_Nonnull)fileSN;

/** 取消下载
 *
 * @param fileSN 正在下载的文件sn
 */
- (void)cancelDownload:(NSString * _Nonnull)fileSN;

/** 删除一个文件
 *
 * @param fileSN 被删除的文件sn
 */
- (void)deleteFile:(NSString *_Nonnull)fileSN;

/** 删除多个文件
 *
 * @param fileSNArray 被删除的文件
 */
- (void)deleteFileArray:(NSArray *_Nonnull)fileSNArray;

/** 创建目录
 * @param dirName 文件夹名
 * @param parentSN 父文件sn
 */
- (void)mkdir:(NSString *_Nonnull)dirName withParent:(NSString *_Nonnull)parentSN;

/** 获取路径下的文件列表信息（含目录)
 * fileInfo 获取路径下的文件列表信息
 * completionHandler 文件列表
 */
- (void)fileArray:(NSString *_Nonnull)fileSN completionHandler:(void (^ _Nonnull )(NSArray *_Nonnull fileArray,NSError * _Nullable error))completionHandler;

/** 移动文件
 *
 * @param fileSN 被移动的文件sn
 * @param targetDirSN 目标文件夹sn
 */
- (void)moveWithFileSN:(NSString *_Nonnull)fileSN withTargetDirectory:(NSString *_Nonnull)targetDirSN;

/** 分享文件
 *
 * @param fileSN 文件sn
 * @param cubeId 目标用户
 */
- (void)share:(NSString *_Nonnull)fileSN withCubeId:(NSString *_Nonnull)cubeId;

/**
 云盘文件分享到白板
 
 @param sn 文件序列号
 */
- (void)convertToWhiteboardFile:(NSString *_Nonnull)sn;

/**
 保存文件到云盘
 
 @param fileSN   文件序列号
 @param folderSN 文件夹序列号
 */
- (void)save:(NSString *_Nonnull)fileSN withFolederSN:(NSString *_Nonnull)folderSN;


/**
 保存文件到云盘
 
 @param fileSN     文件序列号
 @param folderName 文件夹名
 */
- (void)saveToFolder:(NSString *_Nonnull)fileSN withFolder:(NSString *_Nonnull)folderName;

/** 文件重命名
 *
 * @param oldFileInfo 被重命名的文件
 * @param newName 命名后的文件
 */
- (void)rename:(CubeFileInfo *_Nonnull)oldFileInfo withFileInfo:(NSString *_Nonnull)newName;





/** 上传文件。
 *
 * @param data 文件二进制数据。
 * @param name 文件名。
 * @param targetDirSN 上传目标文件夹SN。
 * @param folderName 上传到该文件夹。
 * @param progressHandler 上传进度回调。
 * @param completionHandler 上传完成回调。
 */
- (void)uploadFileWithData:(NSData * _Nonnull)data
                  fileName:(NSString * _Nonnull)name
           targetDirectory:(NSString * _Nullable)targetDirSN
                folderName:(NSString * _Nullable)folderName
           progressHandler:(void (^ _Nonnull)(NSProgress * _Nonnull progress))progressHandler
         completionHandler:(void (^ _Nonnull)(NSURLResponse * _Nullable response,
                                              CubeFileInfo * _Nullable fileInfo, NSError * _Nullable error))completionHandler;

/** 上传文件。
 *
 * @param fileURL 文件URL, 例：file://...。
 * @param targetDirSN 上传目标文件夹SN。
 * @param folderName 上传到该文件夹。
 * @param progressHandler 上传进度回调。
 * @param completionHandler 上传完成回调。
 */
- (void)uploadFileWithFileURL:(NSURL * _Nonnull)fileURL
              targetDirectory:(NSString * _Nullable)targetDirSN
                   folderName:(NSString * _Nullable)folderName
               progressHandler:(void (^ _Nonnull)(NSProgress * _Nonnull progress))progressHandler
            completionHandler:(void (^ _Nonnull)(NSURLResponse * _Nullable response,
                                                CubeFileInfo * _Nullable fileInfo, NSError * _Nullable error))completionHandler;

/** 请求下载链接。
 *
 * @param fileSN 文件序列号。
 * @param completionHandler 完成回调。
 */
- (void)requestDownloadURLForFile:(NSString * _Nonnull)fileSN
                completionHandler:(void (^ _Nonnull)(NSURL * _Nullable url, NSError * _Nullable error))completionHandler;

/** 下载文件。
 *
 * @param fileSN 文件序列号
 * @param progressHandler 下载进度回调。
 * @param completionHandler 下载完成回调。
 */
- (void)downloadFileWithFileSN:(NSString * _Nonnull)fileSN
               progressHandler:(void (^ _Nonnull)(NSProgress * _Nonnull progress))progressHandler
             completionHandler:(void (^ _Nonnull)(NSURLResponse * _Nullable response, CubeFileInfo * _Nullable file, NSError * _Nullable error))completionHandler;

/** 下载文件。
 *
 * @param URL 文件 URL 地址
 * @param progressHandler 下载进度回调。
 * @param completionHandler 下载完成回调。
 */
- (void)downloadFileWithURL:(NSURL * _Nonnull)URL
            progressHandler:(void (^ _Nonnull)(NSProgress * _Nonnull progress))progressHandler
          completionHandler:(void (^ _Nonnull)(NSURLResponse * _Nullable response, CubeFileInfo * _Nullable file, NSError * _Nullable error))completionHandler;

/** 暂停上传
 *
 * @param file 文件传输类。
 * @param completionHandler 暂停上传完成回调。
 */
- (void)pauseUploadFile:(CubeFileInfo * _Nonnull)file
      completionHandler:(void (^ _Nonnull)(CubeFileInfo * _Nullable file, NSError * _Nullable error))completionHandler;

/** 恢复上传
 *
 * @param file 文件传输类。
 * @param completionHandler 恢复上传完成回调。
 */
- (void)resumeUploadFile:(CubeFileInfo * _Nonnull)file
       completionHandler:(void (^ _Nonnull)(CubeFileInfo * _Nullable file, NSError * _Nullable error))completionHandler;

/** 取消上传
 *
 * @param file 文件传输类。
 * @param completionHandler 取消上传完成回调。
 */
- (void)cancelUploadFile:(CubeFileInfo * _Nonnull)file
       completionHandler:(void (^ _Nonnull)(CubeFileInfo * _Nullable file, NSError * _Nullable error))completionHandler;

/** 暂停下载
 *
 * @param file 文件传输类。
 * @param completionHandler 暂停下载完成回调。
 */
- (void)pauseDownloadFile:(CubeFileInfo * _Nonnull)file
        completionHandler:(void (^ _Nonnull)(CubeFileInfo * _Nullable file, NSError * _Nullable error))completionHandler;

/** 恢复下载
 *
 * @param file 文件传输类。
 * @param completionHandler 恢复下载完成回调。
 */
- (void)resumeDownloadFile:(CubeFileInfo * _Nonnull)file
         completionHandler:(void (^ _Nonnull)(CubeFileInfo * _Nullable file, NSError * _Nullable error))completionHandler;

/** 新建目录
 *
 * @param dirName 文件夹name。
 * @param dirSN 父文件夹序列号。
 * @param completionHandler 新建目录完成回调。
 */
- (void)makeDirectoryWithName:(NSString * _Nonnull)dirName
            parentDirectorySN:(NSString * _Nullable)dirSN
            completionHandler:(void(^ _Nonnull)(CubeFileInfo * _Nullable file, NSError * _Nullable error))completionHandler;

/** 重命名
 *
 * @param fileSN 重命名文件序列号。
 * @param newName 新文件名。
 * @param completionHandler 重命名完成回调。
 */
- (void)renameFileWithFileSN:(NSString * _Nonnull)fileSN
                     newName:(NSString * _Nonnull)newName
           completionHandler:(void (^ _Nonnull)(CubeFileInfo * _Nullable file, NSError * _Nullable error))completionHandler;

/** 获取文件信息。
 *
 * @param fileSN 文件序列号。
 * @param completionHandler 完成回调。
 */
- (void)fileInfoWithFileSN:(NSString * _Nonnull)fileSN
         completionHandler:(void (^ _Nonnull)(CubeFileInfo * _Nullable file, NSError * _Nullable error))completionHandler;

/** 移动文件到文件夹
 *
 * @param fileSN 文件序列号。
 * @param targetDirSN 目标文件夹序列号。
 * @param completionHandler 移动文件完成回调。
 */
- (void)moveFileWithFileSN:(NSString  * _Nonnull)fileSN
           targetDirectory:(NSString * _Nonnull)targetDirSN
         completionHandler:(void (^ _Nonnull)(CubeFileInfo * _Nullable file, NSError * _Nullable error))completionHandler;

/** 复制单个文件
 *
 * @param fileSN 文件序列号。
 * @param completionHandler 复制完成回调。
 */
- (void)copyFile:(NSString * _Nonnull)fileSN
completionHandler:(void (^ _Nonnull)(CubeFileInfo * _Nullable file, NSError * _Nullable error))completionHandler;

/** 批量删除文件
 *
 * @param fileSNArray 文件序列号数组。
 * @param completionHandler 完成回调。
 */
- (void)deleteFilesWithSN:(NSArray * _Nonnull)fileSNArray
    completionHandler:(void (^ _Nonnull)(NSError * _Nullable error))completionHandler;

/** 查看目录下所有文件和文件夹
 *
 * @param dirSN 文件夹序列号。
 * @param completionHandler 查看文件列表完成回调。
 */
- (void)fileListWithDirectorySN:(NSString * _Nullable)dirSN
              completionHandler:(void (^ _Nonnull)(NSArray * _Nullable fileInfos, NSError * _Nullable error))completionHandler;
@end

#endif
