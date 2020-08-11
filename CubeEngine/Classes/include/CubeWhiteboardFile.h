//
//  CubeSharedFile.h
//  CubeEngine
//
//  Created by Zhu Guoqiang on 15/9/24.
//  Copyright (c) 2015-2016 Cube Team. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 用于白板共享的文件类
 */
@interface CubeWhiteboardFile : NSObject

/** 文件ID */
@property (nonatomic, assign) long fileId;

/** 账号 */
@property (nonatomic, strong) NSString *acount;

/** 原始文件名 */
@property (nonatomic, strong) NSString *originFileName;

/** 文件别名 */
@property (nonatomic, strong) NSString *aliasFileName;

/** 文件长度 */
@property (nonatomic, assign) long length;

/** 文件 */
@property (nonatomic, strong) NSData *data;

/** 文件分享地址 */
@property (nonatomic, strong) NSArray *urls;


/**
 构造方法

 @param NSDictionary数据
 @return 白板实体
 */
- (id)initWithDic:(NSDictionary *)data;

@end
