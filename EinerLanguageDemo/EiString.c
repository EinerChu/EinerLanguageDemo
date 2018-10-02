//
//  EiString.c
//  EinerLanguageDemo
//
//  Created by 褚鹏 on 2018/10/2.
//  Copyright © 2018年 Einer. All rights reserved.
//

#include "EiString.h"

// 初始化字符串
void EiStringInit (EiString * string) {

    printf("EiString init ...\n");
    EiStringInitWithCacheLength(string, 10);
}

// 初始化指定长度的字符串
void EiStringInitWithCacheLength (EiString * string, int cacheLength) {

    if (string != NULL) {
        // 记录首地址
        string->data = malloc (cacheLength * sizeof(char));
        string->length = 0;
        string->cacheLength = cacheLength;
        printf("EiString init success ..., string:%p\n", string->data);
    } else {
        printf("EiString init failed ..., string:%p\n", string);
    }
}

// 释放字符串
void EiStringFree (EiString * string) {

    if (string != NULL) {
        if (string->data) {
            free (string->data);
            string->length = -1;
            string->cacheLength = -1;
        }
    }
    
    printf("EiString free ...\n");
}
