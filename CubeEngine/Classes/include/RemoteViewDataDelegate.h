//
//  RemoteViewDataDelegate.h
//  CubeEngine
//
//  Created by 曾長歡 on 2017/6/7.
//  Copyright © 2017年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol RemoteViewDataDelegate <NSObject>

@optional

- (void)onBitMap:(FrameData *)frameData;

- (void)onCursor;

- (void)onConnect;

- (void)onClose;

- (void)onError;

@end
