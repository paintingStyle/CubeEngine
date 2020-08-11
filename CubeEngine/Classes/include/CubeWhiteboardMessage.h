//
//  CubeWhileboardMessage.h
//  CubeEngine
//
//  Created by ZengChanghuan on 16/7/27.
//  Copyright © 2016年 Cube Team. All rights reserved.
//

#import "CubeFileMessage.h"

@interface CubeWhiteboardMessage : CubeFileMessage

@property (nonatomic, assign) int currentPage;

@property (nonatomic, copy) NSString *firstPath;

@property (nonatomic, copy) NSString *slideName;

@property (nonatomic, strong) NSArray *slideUrls;

@property (nonatomic, strong) NSData *thumbFile;

@property (nonatomic, copy) NSString *thumbImage;

@property (nonatomic, copy) NSString *thumbUrl;

@property (nonatomic, copy) NSString *whiteboardRecords;


@end
