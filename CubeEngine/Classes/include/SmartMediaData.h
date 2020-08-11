//
//  SmartMediaData.h
//  CubeEngine
//
//  Created by Ashine on 2020/1/20.
//  Copyright © 2020 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SmartMediaData : NSObject

//流key
@property (nonatomic, copy) NSString *streamKey;
//宽
@property (nonatomic, assign) int width;
//高
@property (nonatomic, assign) int height;
//上行宽带
@property (nonatomic, assign) long upBandwidth;
//下行宽带
@property (nonatomic, assign) long downBandwidth;
//上行丢包
@property (nonatomic, assign) long upLostRate;
//下行丢包
@property (nonatomic, assign) long downLostRate;
//网络延时
@property (nonatomic, assign) long rtt;

@end

NS_ASSUME_NONNULL_END
