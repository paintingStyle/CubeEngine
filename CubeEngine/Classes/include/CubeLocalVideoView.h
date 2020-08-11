//
//  CubeLocalVideoView.h
//  CubeEngine
//
//  Created by Zhu on 15/6/5.
//  Copyright (c) 2015年 Cube Team. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CubePrerequisites.h"

/**
 本地视频视图。
 用于显示本地摄像头采集的视频影像数据。
 */
@interface CubeLocalVideoView : UIView


/**
 根据屏幕比例及其frame自动裁剪以充满view.
 */
@property (nonatomic,assign) BOOL autoAspect;

/**
 改变视频视图大小。
 @param frame 视图大小
 */
- (void)changeFrame:(CGRect)frame;


///**
// 裁剪本地通话来适应外部设置的frame
//
// @param frame 外部设置容器frame
// */
//- (void)aspectToFitFrame:(CGRect )frame;

@end
