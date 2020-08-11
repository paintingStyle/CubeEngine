//
//  SmartMemberRole.h
//  CubeEngine
//
//  Created by Ashine on 2020/1/9.
//  Copyright © 2020 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SmartConferenceEnum.h"
#import "CubeJSONObject.h"

NS_ASSUME_NONNULL_BEGIN

@interface SmartMemberRole : NSObject <CubeJSONObject>

//角色类型
@property (nonatomic,assign) SmartMemberRoleType type;
//控言权限
@property (nonatomic,assign) BOOL speak;
//控听权限
@property (nonatomic,assign) BOOL hear;
//控见权限
@property (nonatomic,assign) BOOL watch;
//踢人权限
@property (nonatomic,assign) BOOL kick;

@end

NS_ASSUME_NONNULL_END
