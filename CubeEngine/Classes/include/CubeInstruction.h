//
//  CubeInstruction.h
//  CubeEngine
//
//  Created by 曾長歡 on 2017/3/13.
//  Copyright © 2017年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CubeInstruction : NSObject

/**
  指令有效期
 */
@property (nonatomic, assign) long long expires;

/**
 指令动作
 */
@property (nonatomic, copy) NSString *name;


/**
 指令数据
 */
@property (nonatomic, strong) NSDictionary *data;


/**
 指令集
 */
@property (nonatomic, strong) NSMutableDictionary *instructioDic;
/**
 初始化指令

 @param name 指令动作
 @param data 指令数据
 @return 指令对象
 */
- (id)initWithInstructionWithName:(NSString *)name withData:(NSDictionary *)data;


/**
 设置指令

 @param name 指令动作
 @param data 指令数据
 */
- (void)addInstructionName:(NSString *)name withData:(NSDictionary *)data;


/**
 删除指令

 @param name 指令动作
 */
- (void)removeInstructionName:(NSString *)name;


/**
 通过自定义动作获取指令数据

 @param name 指令动作
 @return 指令数据
 */
- (NSDictionary *)getInstructionData:(NSString *)name;

/**
 toJSONObject

 @return Dictionary
 */
- (NSMutableDictionary *)toJSONObject;
@end
