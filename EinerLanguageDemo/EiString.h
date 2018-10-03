//
//  EiString.h
//  EinerLanguageDemo
//
//  Created by 褚鹏 on 2018/10/2.
//  Copyright © 2018年 Einer. All rights reserved.
//

#ifndef EiString_h
#define EiString_h

#include <stdio.h>
#include <stdlib.h>

typedef struct EiString {
    int     length;             // string's data length
    int     cacheLength;        // string's memory length
    char *  data;               // data
} EiString;

/*!
 @brief 初始化字符串变量 string 字符串变量
 */
int EiStringInit (EiString * string);

/*!
 @brief 初始化字符串变量 string:字符串变量 cacheLength:数据缓存长度
 */
int EiStringInitWithCacheLength (EiString * string, int cacheLength);

/*!
 @brief 追加内容 string:字符串变量 ch:数据
 */
int EiStringAddCharWithChar (EiString * string, char ch);

/*!
 @brief 释放字符串变量 string:字符串变量
 */
int EiStringFree (EiString * string);

#endif /* EiString_h */
