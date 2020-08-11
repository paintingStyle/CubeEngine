//
//  SmartMediaStats.h
//  CubeEngine
//
//  Created by Ashine on 2020/1/20.
//  Copyright © 2020 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SmartMediaStats : NSObject

//流key
@property (nonatomic, strong) NSString *streamKey;
//宽
@property (nonatomic, assign) int width;
//高
@property (nonatomic, assign) int height;
//上行宽带
@property (nonatomic, assign) float upBandwidth;
//下行宽带
@property (nonatomic, assign) float downBandwidth;
//上行丢包
@property (nonatomic, assign) float upLostRate;
//下行丢包
@property (nonatomic, assign) float downLostRate;
//网络延时 （只计算本地流rtt值，对于远端流为0默认）
@property (nonatomic, assign) long rtt;
//帧率
@property (nonatomic , assign) int frameRate;
//编码
@property (nonatomic , strong) NSString *codec;
//网络质量 （只对于本地流有效，对于远端流 不计算其网络质量）
@property (nonatomic , assign) int networkQuality; // 0 未知 1 极差 2 一般 3 较好 4 很好
// 音量（暂未实现）
@property (nonatomic , assign) double audioLevel;

@end

NS_ASSUME_NONNULL_END
