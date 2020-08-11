//
//  SmartInviteFailure.h
//  CubeEngine
//
//  Created by Ashine on 2020/2/14.
//  Copyright © 2020 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CubeJSONObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface SmartInviteFailure : NSObject <CubeJSONObject>

@property (nonatomic , assign) int code;

@property (nonatomic , strong) NSString *desc;

@property (nonatomic , strong) NSString *cubeId;

@end

NS_ASSUME_NONNULL_END
