//
//  CubeWhiteBoard.h
//  CubeEngine
//
//  Created by jianchengpan on 2017/8/7.
//  Copyright © 2017年 CubeTeam. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface CubeWhiteBoard : NSObject

/**
 白板ID
 */
@property (nonatomic, copy) NSString *whiteboardId;

/**
 白板创建者ID
 */
@property (nonatomic, copy) NSString *master;

/**
 白板名称
 用户创建白板时输入
 */
@property (nonatomic, copy) NSString *name;


/**
 当前共享此白板用户的cubeId
 */
@property (nonatomic, strong) NSMutableArray *shares;

/**
 此白板是否被共享
 */
@property (nonatomic, assign) BOOL isShared;

@property (nonatomic, assign) BOOL createdDIV;

/**
 初始化方法

 @param name 白板名
 @param masterName 创建人ID
 @return 白板对象
 */
-(instancetype)initWithName:(NSString *)name andMaster:(NSString *)master;

+(CubeWhiteBoard *)parse:(NSDictionary *)dic;

@end
