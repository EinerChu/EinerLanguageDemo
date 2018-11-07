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

#define EISTRING_INIT_SIZE 12   // Eistring 默认的初始化大小

/*
    // 文本创建
    EiString * string = (EiString *)malloc(sizeof(struct EiString));
    EiStringInit(string);

    // 文本输入
    char ch;
    printf("plase input something:");
    while ((ch = getchar()) != '\n') {
        EiStringAddCharWithChar(string, ch);
    }

    // 文本使用
    printf("content:%s length:%d cacheLength:%d\n", string->data, string->length, string->cacheLength);

    // 文本释放
    EiStringRelease(string);
    free(string);
    string = NULL;
 */

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
int EiStringRelease (EiString * string);

#endif /* EiString_h */
