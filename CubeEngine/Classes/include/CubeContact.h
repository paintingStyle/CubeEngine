//
//  CubeContact.h
//  CubeEngine
//
//  Created by jianchengpan on 2017/11/30.
//  Copyright © 2017年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CubeContact : NSObject

/*cubeID**/
@property (nonatomic, copy) NSString *name;
/*显示昵称**/
@property (nonatomic, copy) NSString *display;
/*头像**/
@property (nonatomic, copy) NSString *icon;
/*是否置顶**/
@property (nonatomic, assign) BOOL top;
/*最近一条消息时间戳**/
@property (nonatomic, assign) long long timestamp;
/*置顶时间戳(排序)**/
@property (nonatomic, assign) long long topTimestamp;
/*最近一条消息sn**/
@property (nonatomic, assign) long long sn;

+(CubeContact *)contactWithJson:(NSDictionary *)dic;

@end
