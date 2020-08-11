//
//  CubeErrorInfo.h
//  CubeEngine
//
//  Created by ZengChanghuan on 16/11/7.
//  Copyright © 2016年 Cube Team. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CubeErrorInfo : NSObject

@property (nonatomic, assign) int code;
@property (nonatomic, copy) NSString * _Nullable descString;
@property (nonatomic, copy) NSDictionary *_Nullable userInfo;

- (id _Nullable )initWithCode:(int)code withDesc:(NSString *_Nonnull)descString;

- (id _Nullable )initWithCode:(int)code withDesc:(NSString *_Nonnull)descString andUserInfo:(NSDictionary *_Nullable)userInfo;

+(CubeErrorInfo *_Nullable)errorWithCode:(int)errorCode andErrorInfo:(NSString *_Nullable)errorInfo andUserInfo:(NSDictionary *_Nullable)userInfo;

@end
