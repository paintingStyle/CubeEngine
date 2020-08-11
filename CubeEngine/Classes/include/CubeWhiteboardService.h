//
//  CubeWhiteboardService.h
//  CubeEngine
//
//  Created by guoqiangzhu on 15/8/26.
//  Copyright (c) 2015-2016 Cube Team. All rights reserved.
//

#ifndef CubeWhiteboardService_h
#define CubeWhiteboardService_h

#import <UIKit/UIKit.h>
#include "CubePrerequisites.h"
#include "CubeWhiteboardFrameMessage.h"
#import "CubeWhiteBoard.h"
/** 白板服务。
 *
 */
@interface CubeWhiteboardService : NSObject

@property (nonatomic, strong) UIView *view;

/**
 当前正在使用的白板
 nil表示当前没有创建任何白板
 */
@property (nonatomic, copy) NSString *currentWhiteboardId;

/**
 白板信息
 保存以创建的白板信息，保存格式为:@{whiteBoardName:WhiteBoard}
 */
@property (nonatomic, strong) NSMutableDictionary *whiteBoardInfo;

/** 白板服务委派。 */
@property (nonatomic, weak) id<CubeWhiteboardServiceDelegate> whiteboardServiceDelegate;

/** 创建新白板。
 * 新创建的白板默认为currentWhiteBoard
 *
 * @param whiteboardName 白板文件名。
 */
- (void)createWhiteboard:(NSString *)whiteboardName;

/** 切换到指定的白板。
 *
 * @param whiteboardId 白板ID。
 */
- (void)switchWhiteboard:(NSString *)whiteboardId;

/**
 共享指定白板
 将白板指定为共享对象
 @param whiteBoardId 白板ID
 @return 是否处理成功
 */
-(BOOL)shareWhiteBoard:(NSString *)whiteBoardId;

/**
 取消共享白板
 
 @param whiteboardId 需要取消的白板
 @return 是否处理成功
 */
-(BOOL)revokeSharing:(NSString *)whiteboardId;

/**
 邀请共享白板
 邀请所指定的白板需要已经共享才能成功
 
 @param whiteboardId 共享的白板的ID
 @param cubeIds 被邀请人列表
 @return 是否处理成功
 */
-(BOOL)inviteWhiteBoard:(NSString *)whiteboardId withCubeIds:(NSArray *)cubeIds;

/**
 拒绝分享邀请

 @param whiteboardId 白板ID
 @return 是否处理成功
 */
-(BOOL)rejectWhiteboard:(NSString *)whiteboardId;

/**
 销毁白板

 @param whiteboardId 白板ID
 */
-(void)destroyWhiteboard:(NSString *)whiteboardId;

/**
 销毁所有白板
 */
-(void)destroyAllWhiteboard;

/**
 查询是否正在共享白板
 
 @param whiteboardId 白板ID
 @return 是否正在共享
 */
-(BOOL)isSharing:(NSString *)whiteboardId;

/** 白板适配大小。
 *
 * 完成白板适配大小操作。
 */
- (void)changeViewFrame:(CGRect)frame;

/** 取消已选择工具。
 */
- (void)unselect;

/** 选择铅笔工具。
 */
- (void)selectPencil;

/** 选择方框工具。
 */
- (void)selectRect;

/** 选择文本输入工具。
 */
- (void)selectText;

/** 选择圆圈工具。
 */
- (void)selectEllipse;

/** 选择箭头工具。
 */
- (void)selectArrow;

/** 撤销一步操作。
 */
- (void)undo;

/* 重做一步操作。
 */
- (void)redo;

/* 擦除白板内容。
 */
- (void)erase;

/** 清空白板内容。
 */
- (void)cleanup;

/** 设置工具线重。
 *
 * @param weight 线重。
 */
- (void)configLineWeight:(int)weight;

/** 设置工具笔触颜色。
 *
 * @param color 颜色。
 */
- (void)configLineColor:(UIColor *)color;

/** 缩放白板。
 *
 * @param ratio 缩放比例。
 */
- (void)zoomWithRatio:(float)ratio;

/** 获取白板缩放比例。
 *
 * @param callback 回调方法。
 */
- (void)getZoomRatioWithCallBack:(void (^)(float ratio))callback;

/** 设置白板背景颜色。
 *
 * @param color 十六进制颜色。
 */
- (void)setBackgroundColor:(NSString *)color;

@end

#endif
