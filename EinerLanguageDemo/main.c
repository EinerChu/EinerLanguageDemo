//
//  main.c
//  EinerLanguageDemo
//
//  Created by 褚鹏 on 2018/10/2.
//  Copyright © 2018年 Einer. All rights reserved.
//

#include "EiFoundation.h"
#include <string.h>

int main (int argc, const char * argv[]) {
    
    EiString string;
    char tmpString[20] = "\0";

    EiStringInit(&string);
    
    // 文本输入
    printf("plase input something:");
    gets(tmpString);

    printf("length:%d\n", strlen(tmpString));
    printf("length:%d\n", sizeof(tmpString));

    // 文本使用
    printf("content:%s-%s length:%d cacheLength:%d\n", tmpString, string.data, string.length, string.cacheLength);

    pauseProgress();
    
    return 0;
}
