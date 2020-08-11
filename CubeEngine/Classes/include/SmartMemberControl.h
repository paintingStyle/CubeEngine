//
//  SmartMemberControl.h
//  CubeEngine
//
//  Created by Ashine on 2020/1/9.
//  Copyright © 2020 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SmartConferenceEnum.h"
#import "CubeJSONObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface SmartMemberControl : NSObject <CubeJSONObject>

//发起者
@property (nonatomic,copy) NSString *from;
//被控者
@property (nonatomic,copy) NSString *to;
//会控指令
@property (nonatomic,assign) SmartControlAction action;
//是否启用
@property (nonatomic,assign) BOOL enabled;
//自定义
@property (nonatomic,strong) NSDictionary *custom;

@end

NS_ASSUME_NONNULL_END
