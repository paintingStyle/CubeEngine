//
//  CubeLiveService.h
//  CubeEngine
//
//  Created by 曾長歡 on 2017/8/16.
//  Copyright © 2017年 CubeTeam. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CubePrerequisites.h"
#import "CubeLiveInfo.h"

@protocol CubeLiveServiceDelegate <NSObject>

-(void)onLiveApply:(CubeLiveInfo *)liveInfo;

-(void)onliveClose:(CubeLiveInfo *)liveInfo;

-(void)onLiveWatch:(CubeLiveInfo *)liveInfo fromCurrentUser:(BOOL)current;

-(void)onLiveStopWatch:(CubeLiveInfo *)liveInfo fromCurrentUser:(BOOL)current;

-(void)onLiveFailed:(CubeLiveInfo *)liveInfo withError:(CubeErrorInfo *)error;

@end

@interface CubeLiveService : NSObject

@property (nonatomic, weak) id<CubeLiveServiceDelegate> delegate;



/**
 查询直播列表

 @param callback 回调 error为nil表示成功，返回直播的群组ID
 @return 引擎是否处理成功
 */
-(BOOL)queryLivesWithCallBack:(void(^)(NSArray<NSString *>*groupIds ,CubeErrorInfo *error))callback;


/**
 查询直播信息

 @param groupIds 群组ID
 @param channels 直播频道ID
 @param callback 回调 
 @return 引擎是否处理成功
 */
-(BOOL)queryLives:(NSArray <NSString *> *)groupIds andChannel:(NSArray <NSString *>*)channels withCallBack:(void(^)(NSArray<CubeLiveInfo *> * liveinfos,CubeErrorInfo *error))callback;

/**
 申请直播
 
 @param groupId 绑定群组ID
 @param name 直播名称
 @return 引擎是否处理成功
 */
-(BOOL)applyLive:(NSString *)groupId withName:(NSString *)name;

/**
 关闭直播
 
 @param groupId 直播棒的的群组ID
 @return 引擎是否处理成功
 */
-(BOOL)closeLive:(NSString *)groupId;


/**
 观看直播

 @param groupId 群组ID
 @return 引擎是否处理成功
 */
-(BOOL)watchLive:(NSString *)groupId;


/**
 推出直播

 @param groupId 群组ID
 @return 引擎是否处理成功
 */
-(BOOL)stopWatchLive:(NSString *)groupId;

@end
