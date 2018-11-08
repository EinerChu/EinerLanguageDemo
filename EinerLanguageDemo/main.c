//
//  main.c
//  EinerLanguageDemo
//
//  Created by 褚鹏 on 2018/10/2.
//  Copyright © 2018年 Einer. All rights reserved.
//

#include "EiFoundation.h"

int main (int argc, const char * argv[]) {

#if 0    
    EiString string;
    char tmpString[20] = "\0";

    EiStringInit(&string);

    printf("plase input something:");
    gets(tmpString);
    EiStringAddString(&string, tmpString);

    printf("content:%s length:%d cacheLength:%d\n", string.data, string.length, string.cacheLength);
    EiStringRelease(&string);
#endif

    EiArray array;
    char tmpString[20] = "\0";

    EiArrayInit(&array);
    
    int number = 5;

    // 文本创建
    for (int i = 0; i < number; i++) {
        EiString * string = (EiString *)malloc(sizeof(struct EiString));
        EiStringInit(string);

        printf("plase input something:");
        gets(tmpString);
        
        EiStringAddString(string, tmpString);
        EiArrayAddObject(&array, string);
    }

    // 输出文本
    for (int i = 0; i < number; i++) {
        EiString * tmpStr = (EiString *)array.data[i];
        printf("array index:%d count:%d string:%s\n", i, array.count, tmpStr->data);
    }

    if (EiArrayRelease(&array)) {
        printf("Array relese success!\n");
    }

    pauseProgress();
    
    return 0;
}
