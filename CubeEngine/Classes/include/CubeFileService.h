//
//  CubeFileService.h
//  CubeEngine
//
//  Created by jianchengpan on 2019/1/3.
//  Copyright © 2019 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CubeErrorInfo.h"

NS_ASSUME_NONNULL_BEGIN

/**
 文件服务代理
 */
@protocol CubeFileServiceDelegate <NSObject>

@optional

#pragma mark - upload

/**
 正在上传文件

 @param identifier 上传任务标志
 @param progress 上传进度
 @param total 文件总大小
 */
-(void)onUploadingFile:(NSString *)identifier withProgress:(long long)progress andTotal:(long long)total;

/**
 文件上传成功

 @param identifier 上传任务标志符
 @param fileInfo 文件信息，包括url,大小等
 */
-(void)onUploadFileComplete:(NSString *)identifier withFileInfo:(NSDictionary *)fileInfo;

/**
 文件上传取消
 
 @param identifier 上传任务标志符
 */
-(void)onUploadFileCanceled:(NSString *)identifier;

/**
 上传文件错误

 @param identifier 上传任务标志符
 @param error 错误信息
 */
-(void)onUploadFileError:(NSString *)identifier withErrorInfo:(CubeErrorInfo *)error;

#pragma mark - download

/**
 正在下载文件

 @param identifier 文件标志符
 @param progress 下载进度
 @param total 文件总大小
 */
-(void)onDownloadingFile:(NSString *)identifier withProgress:(long long)progress andTotal:(long long)total;

/**
 文件下载取消

 @param identifier 文件下载标志符
 */
-(void)onDownloadFileCanceled:(NSString *)identifier;

/**
 下载完成

 @param identifier 下载标志
 @param filepath 文件路径
 */
-(void)onDownloadFileComplete:(NSString *)identifier andFilePath:(NSString *)filepath;

/**
 下载错误

 @param identifier 下载标志
 @param error 错误信息
 */
-(void)onDownloadFileError:(NSString *)identifier withErrorInfo:(CubeErrorInfo *)error;

@end

/**
 文件服务
 */
@interface CubeFileService : NSObject

/**
 文件上传块大小
 @discussion 默认为0，表示使用服务器指定的大小,非0则使用自定义大小
 */
@property (nonatomic, assign) long long uploadBlockSize;

@property (nonatomic, weak) id<CubeFileServiceDelegate> delegate;

/**
 外部设置上传文件存储路径 不设置默认为Upload
 */
@property (nonatomic, copy) NSString *uploadfolder;

/**
 外部设置下载文件存储路径  不设置默认为Download
 */
@property (nonatomic, copy) NSString *downloadfolder;
#pragma mark - upload

/**
 上传文件
 
 @param filePath 文件地址
 @param identifier 上传任务唯一标志符
 @return 是否处理成功,filePath或者identifier为空返回NO
 */
-(BOOL)uploadFile:(NSString *)filePath withIdentifier:(NSString *)identifier;

/**
 取消上传任务

 @param identifier 任务上传标志符
 */
-(void)cancelUploadTaskWithIdentifier:(NSString *)identifier;

/**
 下载文件

 @param url 文件url
 @param identifier 下载任务唯一标志
 @return 是否处理成功,url或者identifier为空返回NO
 */
-(BOOL)downLoadFile:(NSString *)url withIdentifier:(NSString *)identifier;

/**
 取消下载任务

 @param identifier 下载任务标志
 */
-(void)cancelDownloadTaskWithIdentifier:(NSString *)identifier;

@end

NS_ASSUME_NONNULL_END
