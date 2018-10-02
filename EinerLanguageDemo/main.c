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

    // insert code here...
    EiString * string = (EiString *) malloc (sizeof (EiString *));
    EiStringInit (string);
    printf("%d\n", string->cacheLength);

    EiStringFree (string);

    printf("%d\n", string->cacheLength);

    free (string);

    printf("%d\n", string->cacheLength);

    return 0;
}
