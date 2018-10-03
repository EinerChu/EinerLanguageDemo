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

    printf(" \n");
    EiString * string = (EiString *)malloc(sizeof(struct EiString));
    EiStringInit(string);

    char ch;

    printf("plase input something:");

    while ((ch = getchar()) != '\n') {
        EiStringAddCharWithChar(string, ch);
    }

    printf("content:%s length:%d cacheLength:%d\n", string->data, string->length, string->cacheLength);

    EiStringFree(string);

    free(string);
    string = NULL;

    return 0;
}
