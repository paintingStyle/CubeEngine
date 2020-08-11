//
//  CubeEngineDeprecationMacros.h
//  CubeEngine
//
//  Created by zhuguoqiang on 17/2/15.
//  Copyright © 2017年 CubeTeam. All rights reserved.
//

#ifndef CubeEngineDeprecationMacros_h
#define CubeEngineDeprecationMacros_h

#define CUBE_DEPRECATED_WILL_BE_REMOVED_IN(VERSION) __attribute__((deprecated("This method has been deprecated and will be removed in CubeEngine " VERSION ".")))
#define CUBE_DEPRECATED_WILL_BE_REMOVED_IN_PLEASE_USE(VERSION, METHOD) __attribute__((deprecated("This method has been deprecated and will be removed in CubeEngine " VERSION ". Please use `" METHOD "` instead.")))

#endif /* CubeEngineDeprecationMacros_h */
