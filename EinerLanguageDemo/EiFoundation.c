//
//  EiFoundation.c
//  EinerLanguageDemo
//
//  Created by 褚鹏 on 2018/10/25.
//  Copyright © 2018年 Einer. All rights reserved.
//

#include "EiFoundation.h"

// 取hash地址  hashKey:哈希关键字
int getHashAddress (char * hashKey) {

    int h = 0, g;

    while (* hashKey) {
        h = (h << 4) + *hashKey++;
        g = h & 0xf0000000;
        if (g) {
            h ^= g >> 24;
            h &= ~g;
        }
    }

    return h % HASH_MAX_KEY_LENGTH;
}

// 暂停程序
void pauseProgress () {

    if (SYSTEM_TYPE) {
        // Mac 环境
        printf("\n_Mac_\nPress any key to continue...\n\n");
        getchar();
    } else {
        // Win 环境
        printf("\n_Win_\nPress any key to continue...\n\n");
        getchar();
    }
}
