//
//  Cube.h
//  Cube Engine
//
//  Created by Xu Jiangwei on 14/9/28.
//  Copyright (c) 2014-2016 Cube Team. All rights reserved.
//

#ifndef Cube_h
#define Cube_h

/** @mainpage 魔方实时协作引擎指南

  该手册包含如下章节：

  @ref intro

  @ref installation

  @ref getting_started

  @ref api_manual

 */


/** @page intro 引擎简介
  @tableofcontents

  魔方引擎（Cube Engine）是跨平台、全功能的实时协作引擎，是完备的即时信息交换解决方案。

  @section engine_features 特性
  <p>
  TODO
  </p>

  @subsection features_video_audio 实时视频语音
  <p>
  TODO
  </p>

  @subsection features_whiteboard 多功能白板
  <p>
  TODO
  </p>

  @subsection features_im_voice 即时消息与短语音
  <p>
  TODO
  </p>

  @subsection features_filesharing 文档共享
  <p>
  TODO
  </p>

  <p>&nbsp;</p>

  @section engine_platform 全平台支持

  支持平台包括：
  - iOS
  - Android
  - Windows
  - Mac OS X
  - Linux
  - Web Browser ( Chrome, Firefox )
 */


/** @page installation 安装
  @tableofcontents

  @em 我们正在努力制作中……

 */


/** @page getting_started 入门指南
  @tableofcontents

  @em 我们正在努力制作中……

 */


/** @page api_manual API 手册
  @tableofcontents

  @em 我们正在努力制作中……

 */


#import "CubePrerequisites.h"
#import "CubeConfig.h"
#import "CubeEngine.h"
#import "CubeSession.h"
#import "CubePeer.h"
#import "CubeCallPeer.h"
#import "CubeLocalVideoView.h"
#import "CubeRemoteVideoView.h"
#import "CubeTextMessage.h"
#import "CubeFileMessage.h"
#import "CubeImageMessage.h"
#import "CubeVoiceClipMessage.h"
#import "CubeVideoClipMessage.h"
#import "CubeCustomMessage.h"
#import "CubeCardMessage.h"
#import "CubeHistoryMessage.h"
#import "CubeRichContentMessage.h"
#import "Receiver.h"
#import "Sender.h"
#import "CubeMediaProbe.h"
#import "CubeRecordVideoView.h"
#import "CubePlayVideoView.h"
#import "MessageEntity.h"
#import "CubeWhiteboardFile.h"
#import "CubeWhiteboardSlide.h"
#import "Conference.h"
#import "CubeConferenceStream.h"
#import "GroupContext.h"
#import "CubeContact.h"
#import "CubeReplyMessage.h"

#import "CubeMessageService.h"
#import "CubeGroupService.h"
#import "CubeConferenceService.h"
#import "CubeCallService.h"
#import "CubeWhiteboardService.h"
#import "CubeMediaService.h"
#import "CubeWhiteboardMessage.h"
#import "CubeAccountService.h"
#import "CubeWhiteboardFrameMessage.h"
#import "CubeWhiteboardClipMessage.h"
#import "CubeErrorInfo.h"
#import "CubeInstructionService.h"
#import "CubeRemoteDesktopService.h"
#import "CubeLiveService.h"
#import "CubeContactService.h"
#import "CubeSettingService.h"

#import "SmartMacroDefine.h"

#endif
