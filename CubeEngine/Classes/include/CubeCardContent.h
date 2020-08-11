//
//  CubeCardContent.h
//  CubeEngine
//
//  Created by Mario on 17/5/3.
//  Copyright © 2017年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CubeCardContent : NSObject

/**卡片消息URL*/
@property (nonatomic, copy) NSString *url;

/**卡片消息头像*/
@property (nonatomic, copy) NSString *icon;

/** 卡片名称*/
@property (nonatomic, copy) NSString *name;

/**描述*/
@property (nonatomic, copy) NSString *desc;

/**
 构造函数。
 @param icon 卡片消息头像。
 @param url 卡片消息URL。
 @param name 卡片名称。
 */
- (id)initWithCardIcon:(NSString *)icon andUrl:(NSString *)url andName:(NSString *)name;

/**
 构造函数。
 @param icon 卡片消息头像。
 @param url 卡片消息URL。
 @param name 卡片名称。
 @param desc 描述信息
 @return 卡片消息
 */
- (id)initWithCardIcon:(NSString *)icon andUrl:(NSString *)url andName:(NSString *)name andDesc:(NSString *)desc;


/**
 转换为字典

 @return 字典
 */
- (NSMutableDictionary *)toJSON;

@end
