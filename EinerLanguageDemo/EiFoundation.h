//
//  EiFoundation.h
//  EinerLanguageDemo
//
//  Created by 褚鹏 on 2018/10/25.
//  Copyright © 2018年 Einer. All rights reserved.
//

#ifndef EiFoundation_h
#define EiFoundation_h

#include <stdio.h>
#include <stdlib.h>
#include "EiString.h"
//#include "EiArray.h"
//#include "EiError.h"

#define SYSTEM_TYPE 0                               /* 系统类型 windows:0 mac:1 */
#define HASH_MAX_KEY_LENGTH 1024                    // 哈希表容量

/*!
 @brief 计算hash地址 hashKey:哈希关键字
 */
int getHashAddress (char * hashKey);

/*!
 @brief 暂停程序
 */
void pauseProgress (void);

#endif /* EiFoundation_h */
