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
#include <string.h>

typedef struct EiString {
    int     length;             // string's data length
    int     cacheLength;        // string's memory length
    char *  data;               // data
} EiString;

#define EISTRING_INIT_SIZE 12   // Eistring 默认的初始化大小

/*
    使用一:
    EiString string;
    char tmpString[20] = "\0";

    EiStringInit(&string);

    printf("plase input something:");
    gets(tmpString);
    EiStringAddString(&string, tmpString);
    printf("content:%s length:%d cacheLength:%d\n", string.data, string.length, string.cacheLength);
    
    EiStringRelease(&string);

    使用二:
    EiString * string = (EiString *)malloc(sizeof(struct EiString));
    char tmpString[20] = "\0";

    EiStringInit(string);
    
    printf("plase input something:");
    gets(tmpString);
    EiStringAddString(string, tmpString);
    printf("content:%s length:%d cacheLength:%d\n", string->data, string->length, string->cacheLength);

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
 @brief 追加内容 string:字符串变量 appendString:文本数据
 */
int EiStringAddString (EiString * string, char * appendString);

/*!
 @brief 释放字符串变量 string:字符串变量
 */
int EiStringRelease (EiString * string);

#endif /* EiString_h */
