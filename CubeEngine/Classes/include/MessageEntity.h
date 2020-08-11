//
//  MessageEntity.h
//  CubeEngine
//
//  Created by Zhu Guoqiang on 15/5/8.
//  Copyright (c) 2016年 Cube Team. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Sender.h"
#import "Receiver.h"
#import "CubeDeviceInfo.h"
#import "CubeRecallInfo.h"
/** 一般消息类型描述。
 *
 */
typedef enum _CubeMessageType {
    /** 文本类型的消息。 */
    CubeMessageTypeText,
    /** 文件类型的消息。 */
    CubeMessageTypeFile,
    /** 图片类型的消息。 */
    CubeMessageTypeImage,
    /** 语音剪辑类型的消息。 */
    CubeMessageTypeVoiceClip,
    /** 视频剪辑类型的消息。 */
    CubeMessageTypeVideoClip,
    /** 自定义消息。 */
    CubeMessageTypeCustom,
    /** 卡片消息。 */
    CubeMessageTypeCard,
    /** 历史消息。 */
    CubeMessageTypeHistory,
    /** 普通白板消息。 */
    CubeMessageTypeWhiteboard,
    /** 白板剪辑消息。 */
    CubeMessageTypeWhiteboardClip,
    /** 富文本消息。 */
    CubeMessageTypeRichContent,
    /** 地理位置消息。 */
    CubeMessageTypeLocation,
	/** 回复消息 */
	CubeMessageTypeReply,
    /** 未知类型消息。 */
    CubeMessageTypeUnknown = -1

} CubeMessageType;
/** 消息方向。
 *
 */
typedef enum _CubeMessageDirection
{
    /** 消息方向未定义。 */
    CubeMessageDirectionNone,
    /** 收到的消息。 */
    CubeMessageDirectionReceived,
    /** 发出的消息。 */
    CubeMessageDirectionSent
}
CubeMessageDirection;

/** 消息状态描述。
 */
typedef enum _CubeMessageStatus {
    /** 创建成功待发送。 */
    CubeMessageStatusCreated = 0,
    /** 发送过程中。 */
    CubeMessageStatusSending = 1,
    /** 接收过程中。 */
    CubeMessageStatusReceiving = 2,
    /** 消息处理成功。 */
    CubeMessageStatusSucceed = 3,
    /**消息暂停*/
    CubeMessageStatusPaused = 4,
    /** 消息处理失败。 */
    CubeMessageStatusFailed = -1
    
} CubeMessageStatus;


typedef enum _CubeMessageAttachmentType
{
    CubeMessageAttachmentConference,
    CubeMessageAttachmentUnknown
}CubeMessageAttachmentType;

//消息操作类型
typedef enum _CubeMessageOperator
{
    CubeMessageOperatorUnknown,
    CubeMessageOperatorImageOriginal,
    CubeMessageOperatorImageThumb,
    CubeMessageOperatorVideoThumb,
    CubeMessageOperatorVideoMP4,
    CubeMessageOperatorVoiceMP3,
    CubeMessageOperatorWhiteboard,
    CubeMessageOperatorFile
    /* 下载操作暂不支持
    CubeMessageOperatorVideoOriginal,
    CubeMessageOperatorVideoWebM,
    CubeMessageOperatorVoiceOriginal,
    CubeMessageOperatorVoiceOGG,
     */


}CubeMessageOperator;
/** 消息实体类。
 *
 * 消息实体类描述了一个可被有效管理的输出传输单元。
 * 该类是所有可被远程传输的消息对象的父类/基类。
 *
 */
@interface MessageEntity : NSObject

/** 消息序列号 */
@property (nonatomic, assign) long long SN;

/** 消息类型 */
@property (nonatomic, assign, readonly) CubeMessageType type;

/** 消息状态 */
@property (nonatomic, assign) CubeMessageStatus status;

/** 发件人 */
@property (nonatomic, strong) Sender *sender;

/** 发送时间 */
@property (nonatomic, assign) long long sendTime;

/** 接收人 */
@property (nonatomic, strong) Receiver *receiver;

/** 接收时间 */
@property (nonatomic, assign) long long receiveTime;

/** 是否被其他终端拉取 */
@property (nonatomic, assign) BOOL pulled;

/** 群组号 */
@property (nonatomic, strong) NSString *groupName;

/** 撤回扩展 */
@property (nonatomic, strong) CubeRecallInfo * recallInfo;

/** 撤回时间 */
@property (nonatomic, assign) long long recallTime;

/** 时间戳 */
@property (nonatomic, assign) long long timestamp;

/**
 默认或者不设置时为 false，当参数为 true 时，消息将仅发送给在线的设备，所有当前离线设备将无法取得该消息 不入库 直接透传
 增加对方正在输入功能（采用自定义消息的透传功能实现，服务器验证traceless属性为true时，不入库，直接透传功能
 */
@property (nonatomic, assign) BOOL traceless;

/**
 消息方向
 */
@property (nonatomic, assign) CubeMessageDirection messageDirection;
/**
 附件类型
 */
@property (nonatomic, assign) CubeMessageAttachmentType attachmentType;

/**消息头*/
@property (nonatomic, strong) NSMutableDictionary *header;

/**
 消息从哪种设备发出
 */
@property (nonatomic, strong) CubeDeviceInfo *deviceInfo;


/**
 消息在此之前被什么设备收取过
 */
@property (nonatomic, strong) NSArray<CubeDeviceInfo *> *pulledDevices;


/**
 是否加密
 */
@property (nonatomic, assign) BOOL secret;


/**
 回执时间
 */
@property (nonatomic, assign) long long receiptTimestamp;


/**
 是否已读
 */
@property (nonatomic, assign) BOOL receipted;

/**
 消息回执设备
 */
@property (nonatomic, strong) NSMutableArray<CubeDeviceInfo *> *receiptedDevices;


/**
 是否是密聊消息
 */
@property (nonatomic, assign) BOOL anonymous;


/**
 是否为有效消息
 */
@property (nonatomic, assign) BOOL valid;

/**
 同步，
 0. 都同步，1. 仅对方同步 2. 仅自己同步
 */
@property (nonatomic, assign) int sync;

/**
 消息被修改的时间
 */
@property (nonatomic, assign) long long update;

/**
 需要路由者，群消息可以设置此属性，表示只有此列表的人才能收到，不设置没有此属性
 */
@property (nonatomic, strong) NSArray *tos;

/** 构造函数。
 *
 * @param type 消息类型
 */
- (id)initWithMessageType:(CubeMessageType )type;

/** 构造函数。
 *
 * @param type 消息类型
 * @param receiver 接收人
 */
- (id)initWithMessageType:(CubeMessageType)type andReceiver:(Receiver *)receiver;

/** 构造函数。
 *
 * @param type 消息类型
 * @param receiver 接收人
 * @param sender 发送人
 *
 * TODO 这个函数不能对外开放
 */
- (id)initWithMessageType:(CubeMessageType)type andReceiver:(Receiver *)receiver andSender:(Sender *)sender;


/**
 updateSender

 @param sender sender
 @param sendTime sendTime
 @param timestamp timestamp
 */
- (void)updateSender:(Sender *)sender
        withSendTime:(long long)sendTime
       withTimestamp:(long long)timestamp;

/**
 updateReceiver

 @param receiver receiver
 @param receiveTime receiveTime
 @param timestamp timestamp
 */
- (void)updateReceiver:(Receiver *)receiver
       withReceiveTime:(long long)receiveTime
         withTimestamp:(long long)timestamp;

/**
 toJSONObject

 @return NSMutableDictionary
 */
- (NSMutableDictionary *)toJSONObject;


/**
 解析消息实体

 @param data 数据
 @return MessageEntity
 */
+ (MessageEntity *)messageParse:(NSDictionary *)data;

/**
 消息实体转NSString

 @param message 消息实体
 @return 字符串
 */
+ (NSString *)convertMessageString:(MessageEntity *)message;

/**
 消息类型判断

 @param input CubeMessageType
 @return NSString
 */
+ (NSString *)stringWithMessageType:(CubeMessageType)input;


/**
 判断消息类型

 @param type 消息类型
 @return CubeMessageType
 */
+ (CubeMessageType)parse:(NSString *)type;


/**
 消息类型转字符串

 @param status 消息状态
 @return 消息状态对应的字符串
 */
+ (NSString *)messageState:(CubeMessageStatus)status;

/**
 判断是否是发出的消息

 @return 是发出的消息为YES 否则为NO
 */
- (BOOL)isSendMessage;


/**
 判读就否是文件消息

 @return @return 是发出的消息为YES 否则为NO
 */
+ (BOOL)isFileMessage:(MessageEntity *)message;
@end
