//
//  main.c
//  EinerLanguageDemo
//
//  Created by 褚鹏 on 2018/10/2.
//  Copyright © 2018年 Einer. All rights reserved.
//

#include <stdio.h>
#include "EiHeader.h"

int main (int argc, const char * argv[]) {

    // 文本创建
    EiString * string = (EiString *)malloc(sizeof(struct EiString));
    EiStringInit(string);
    EiString * stringTwo = (EiString *)malloc(sizeof(struct EiString));
    EiStringInit(stringTwo);

    // 文本输入
    char ch;
    printf("plase input textOne:");
    while ((ch = getchar()) != '\n') {
        EiStringAddCharWithChar(string, ch);
    }

    printf("plase input textTwo:");
    while ((ch = getchar()) != '\n') {
        EiStringAddCharWithChar(stringTwo, ch);
    }

    // 文本使用
    printf("stringOne:%s stringTwo:%s\n", string->data, stringTwo->data);

    // 数组的使用
    EiArray * array = (EiArray *)malloc(sizeof(struct EiArray));
    EiArrayInit(array);
    EiArrayAddObject(array, string);
    EiArrayAddObject(array, stringTwo);

    // 文本使用
    printf("stringOne:%s stringTwo:%s arrayOne:%s arrayTwo:%s\n", string->data, stringTwo->data, ((EiString *)(array->data[0]))->data, ((EiString *)(array->data[1]))->data);

    // 数组释放
    EiArrayRelease(array);
    free(array);
    array = NULL;

    // 文本释放
    EiStringRelease(string);
    free(string);
    string = NULL;

    EiStringRelease(stringTwo);
    free(stringTwo);
    stringTwo = NULL;

    return 0;
}
