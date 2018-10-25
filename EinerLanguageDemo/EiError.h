//
//  EiError.h
//  EinerLanguageDemo
//
//  Created by 褚鹏 on 2018/10/21.
//  Copyright © 2018年 Einer. All rights reserved.
//

#ifndef EiError_h
#define EiError_h

#include <stdio.h>

/* 错误级别 */
enum e_ErrorLevel {
    LEVEL_WARNING,
    LEVEL_ERROR,
};

/* 工作阶段 */
enum e_WorkStage {
    STAGE_COMPILE,
    STAGE_LINK,
};

void warning(char *fmt, ...);
void error(char *fmt, ...);
void expect(char *msg);
void skip(int c);
void link_error(char *fmt, ...);


#endif /* EiError_h */
