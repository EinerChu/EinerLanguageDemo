//
//  main.c
//  EinerLanguageDemo
//
//  Created by 褚鹏 on 2018/10/2.
//  Copyright © 2018年 Einer. All rights reserved.
//

#include "EiFoundation.h"

int main (int argc, const char * argv[]) {
    
    EiString string;
    char tmpString[20] = "\0";

    EiStringInit(&string);

    printf("plase input something:");
    gets(tmpString);
    EiStringAddString(&string, tmpString);

    printf("content:%s length:%d cacheLength:%d\n", string.data, string.length, string.cacheLength);
    EiStringRelease(&string);
    
    pauseProgress();
    
    return 0;
}
