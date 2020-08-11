//
//  CubeWhiteboardSlide.h
//  CubeEngine
//
//  Created by Zhu Guoqiang on 15/9/24.
//  Copyright (c) 2015-2016 Cube Team. All rights reserved.
//

#import <Foundation/Foundation.h>

/** 幻灯片实体类。
 *
 * 用于白板分享的幻灯片实体类。
 *
 */
@interface CubeWhiteboardSlide : NSObject

/** 幻灯片文件名 */
@property (nonatomic, strong) NSString *docName;

/** 幻灯片当前页 */
@property (nonatomic, assign) int currentPage;

/** 幻灯片总页数 */
@property (nonatomic, assign) int numsOfPage;

/** 分享源 */
@property (nonatomic, strong) NSString *from;

/** 所属群组 */
@property (nonatomic, strong) NSString *group;

@end
