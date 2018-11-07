//
//  EiString.c
//  EinerLanguageDemo
//
//  Created by 褚鹏 on 2018/10/2.
//  Copyright © 2018年 Einer. All rights reserved.
//

#include "EiString.h"

// 初始化字符串
int EiStringInit (EiString * string) {

    return EiStringInitWithCacheLength(string, EISTRING_INIT_SIZE);
}

// 初始化指定长度的字符串
int EiStringInitWithCacheLength (EiString * string, int cacheLength) {

    int result = 0;

    if (string != NULL) {
        string->data = (char *) malloc (cacheLength * sizeof (char));
        string->length = 0;
        string->cacheLength = cacheLength;
        result = 1;
        for (int i = string->length; i < cacheLength; i++) {
                string->data[i] = '\0';
        }
    } else {
        printf("\nFunc:EiStringInitWithCacheLength, Eistring init failed, string is Null!\n");
    }

    return result;
}

// 重新分配字符串
int EiStringRealloc (EiString * string, int newSize) {

    int result = 0, cacheLength = 0;
    char * data;

    if (string != NULL) {
        cacheLength = string->cacheLength;

        while (cacheLength < newSize) {
            cacheLength = cacheLength * 2;
        }

        data = (char *)realloc(string->data, cacheLength);

        if (data) {
            for (int i = string->length; i < cacheLength; i++) {
                string->data[i] = '\0';
            }
            string->cacheLength = cacheLength;
            string->data = data;
            result = 1;
        } else {
            printf("\nFunc:EiStringRealloc, EiStringRealloc progress failed, realloc memory error!\n");
        }
    } else {
        printf("\nFunc:EiStringRealloc, EiStringRealloc progress failed, string is Null!\n");
    }

    return result;
}

// 追加字符串
int EiStringAddString (EiString * string, char * appendString) {

    int result = 0, count = 0;

    if (string != NULL) {
        count = string->length + 1;
        if (count > string->cacheLength) {
            EiStringRealloc (string, count);
        }
        string->data [count - 1] = ch;
        string->length = count;
        result = 1;
    } else {
        printf("\nFunc:EiStringAddCharWithChar, EiStringAddCharWithChar progress failed, string is Null!\n");
    }

    return result;
}

// 释放字符串
int EiStringRelease (EiString * string) {

    int result = 0;

    if (string != NULL) {
        if (string->data != NULL) {
            free (string->data);
            string->data = NULL;
            string->length = 0;
            string->cacheLength = 0;
            result = 1;
        } else {
            printf("\nFunc:EiStringRelease, EiStringRelease progress failed, string's data is Null!\n");
        }
    } else {
        printf("\nFunc:EiStringRelease, EiStringRelease progress failed, string is Null!\n");
    }
    
    return result;
}
