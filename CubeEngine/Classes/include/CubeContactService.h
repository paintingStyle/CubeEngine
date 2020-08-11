//
//  CubeContactService.h
//  CubeEngine
//
//  Created by jianchengpan on 2017/11/30.
//  Copyright © 2017年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CubePrerequisites.h"

@interface CubeContactService : NSObject

@property (nonatomic, weak) id<CubeContactServiceDelegate> delegate;

/**
 
 查询联系人制定列表

 @param handler 查询结果回掉，error 为空则成功，否者失败
 @return 引擎是否处理成功
 */
-(BOOL)queryTopContactsWithHandler:(void(^)(NSArray<CubeContact *> *contacts,CubeErrorInfo *error))handler;

/**
 设置置顶

 @param top 是否置顶
 @param cube cube号
 @return 是否处理成功
 */
-(BOOL)setTop:(BOOL)top forCube:(NSString *)cube;

@end
