//
//  CubeResponderDelegate.h
//  CubeEngine
//
//  Created by ZengChanghuan on 16/11/21.
//  Copyright © 2016年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol CubeResponderDelegate <NSObject>
@optional


/**
 一对一潜伏时间回调

 @param selfLatency 自已的潜伏期
 @param peerLatency 对方的潜伏期
 */
- (void)onLatencyRespond:(long long)selfLatency withPeerLatency:(long long)peerLatency;


/**
 UPD 数据回调

 @param maxDelay 最大延迟
 @param minDelay 最小延迟
 @param packetLoss 丢包率
 */
- (void)onUDPWithMaxDelay:(long long)maxDelay withMinDelay:(long long)minDelay withPacketLoss:(float)packetLoss;

@end
