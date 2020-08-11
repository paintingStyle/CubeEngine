//
//  CubeWhiteboardFrameMessage.h
//  CubeEngine
//
//  Created by ZengChanghuan on 16/7/27.
//  Copyright © 2016年 Cube Team. All rights reserved.
//

#import "CubeWhiteboardMessage.h"

@interface CubeWhiteboardFrameMessage : CubeWhiteboardMessage

- (id)initWithWhiteboardRecords:(NSString *)whiteboardRecords;

- (id)initWithWhiteboardFilePath:(NSString *)whiteboardFilePath withFileName:(NSString *)fileName;

- (id)initWithWhiteboardRecords:(NSString *)whiteboardRecords
                    andReceiver:(Receiver *)receiver
                      andSender:(Sender *)sender;
//- (NSMutableDictionary *)toJSONObject;

- (void)encode;

- (void)decode;

@end
