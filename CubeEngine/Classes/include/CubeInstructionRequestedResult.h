//
//  CubeInstructionRequestedResult.h
//  CubeEngine
//
//  Created by 曾長歡 on 2017/3/13.
//  Copyright © 2017年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CubeInstruction.h"
#import "CubeDeviceInfo.h"
@interface CubeInstructionRequestedResult : NSObject

@property (nonatomic, strong) CubeInstruction *instruction;
@property (nonatomic, strong) NSArray<NSString *>*targets;
@property (nonatomic, strong) NSArray<CubeDeviceInfo *> *succeedDevices;
@property (nonatomic, strong) NSArray<CubeDeviceInfo *> *failedDevices;

@end
