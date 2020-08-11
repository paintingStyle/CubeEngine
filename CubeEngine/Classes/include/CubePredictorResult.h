//
//  CubePredictorResult.h
//  CubeEngine
//
//  Created by Zeng Changhuan on 2018/9/13.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CubePredictorResult : NSObject

/**
 原始数据
 */
@property (nonatomic, strong) NSString *text;

/**
 请求唯一值
 */
@property (nonatomic, strong) NSString *nonce;

/**
 预测结果json字符串
 */
@property (nonatomic, strong) NSString *result;


/**
 解析预测结果

 @param dict 预测结果
 @return 预测结果实体对象
 */
+ (CubePredictorResult *)predictorResultParse:(NSDictionary *)dict;

/**
 转化为字典

 @return 字典
 */
- (NSDictionary *)toJSONObject;
@end
