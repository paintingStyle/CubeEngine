//
//  CubeRemoteView.h
//  CubeEngine
//
//  Created by 曾長歡 on 2017/6/5.
//  Copyright © 2017年 CubeTeam. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol CubeRemoteViewDelegate <NSObject>

@optional

- (void)isLoading;

- (void)isPlay;

@end

@class FrameData;
@interface CubeRemoteView : UIView

@property (nonatomic, weak) id<CubeRemoteViewDelegate>remoteViewDelegate;

-(instancetype)initWithFrame:(CGRect)frame;

- (void)frameData:(FrameData *)frameData;

/**
 更改自身View的大小

 @param rect 尺寸
 */
-(void)changeFrame:(CGRect)rect;
@end
