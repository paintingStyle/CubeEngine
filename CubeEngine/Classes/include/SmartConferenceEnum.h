//
//  SmartConferenceEnum.h
//  CubeEngine
//
//  Created by Ashine on 2020/1/9.
//  Copyright © 2020 CubeTeam. All rights reserved.
//

#ifndef SmartConferenceEnum_h
#define SmartConferenceEnum_h

//////////// SmartConferenceType //////////
typedef enum : NSUInteger {
    UnKnown, //未知类型
    Normal,  //正常
    Advanced,//高级
    Custom,  //自定义
} SmartConferenceType;

//////////// SmartMemberRoleType //////////
typedef enum : NSUInteger {
    Presenter, //主持人
    Speaker,   //主讲人
    Viewer,    //观看人
} SmartMemberRoleType;

//////////// SmartStreamType //////////
typedef enum : NSUInteger {
    Camera, //摄像头
    Screen, //屏幕
    File,   //文件
} SmartStreamType;

//////////// SmartControlAction //////////
typedef enum : NSUInteger {
    HEAR,      //控听
    WATCH,     //控视
    SPEAK,     //控言
    KICK,      //踢人
    SPEAKER,   //主讲
    PRESENTER, //主持
    AUDIO,     //开启音频
    VIDEO,     //开启视频
    UNKNOWN,   //未知
} SmartControlAction;




#endif /* SmartConferenceEnum_h */
