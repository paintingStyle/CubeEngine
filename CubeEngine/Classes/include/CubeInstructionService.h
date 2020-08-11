//
//  CubeInstructionService.h
//  CubeEngine
//
//  Created by 曾長歡 on 2017/3/13.
//  Copyright © 2017年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CubePrerequisites.h"
#import "CubeInstruction.h"
#import "CubeDeviceInfo.h"
@interface CubeInstructionService : NSObject

/**
 发送指令给特定设备

 @param device 设备
 @param instruction 指令
 */
- (void)exeInstructionWithDeviceInfo:(CubeDeviceInfo *)device withInstruction:(CubeInstruction *)instruction;


/**
 发送指令给某个用户或群组的所有设备

 @param target 目标
 @param instruction 指令
 */
- (void)exeInstructionWithTarget:(NSString *)target withInstruction:(CubeInstruction *)instruction;

/**
 发送指令给多个用户或群组的所有设备
 
 @param targets 目标集
 @param instruction 指令
 */
- (void)exeInstructionWithTargets:(NSArray<NSString *> *)targets withInstruction:(CubeInstruction *)instruction;
@end
