//
//  EiArray.c
//  EinerLanguageDemo
//
//  Created by 褚鹏 on 2018/10/5.
//  Copyright © 2018年 Einer. All rights reserved.
//

#include "EiArray.h"

// 初始化数组
int EiArrayInit (EiArray * array) {

    return EiArrayInitWithCacheLength(array, EIARRAY_INIT_SIZE);
}

// 初始化字符串变量 array:数组变量 cacheLength:数据缓存长度
int EiArrayInitWithCacheLength (EiArray * array, int cacheLength) {

    int result = 0;

    if (array != NULL) {
        array->data = (void **)malloc(cacheLength * sizeof(void *));
        array->cacheLength = cacheLength;
        array->count = 0;
        result = 1;
    } else {
        printf("\nFunc:EiArrayInitWithCacheLength, EiArray init failed, array is Null!\n");
    }

    return result;
}

// 重新分配数组
int EiArrayRealloc (EiArray * array, int newSize) {

    int result = 0, cacheLength = 0;
    void * data;

    if (array != NULL) {
        cacheLength = array->cacheLength;

        while (cacheLength < newSize) {
            cacheLength = cacheLength * 2;
        }

        data = (void *)realloc(array->data, cacheLength * sizeof(void *));

        if (data) {
            array->cacheLength = cacheLength;
            array->data[0] = data;
            result = 1;
        } else {
            printf("\nFunc:EiArrayRealloc, EiArrayRealloc progress failed, realloc memory error!\n");
        }
    } else {
        printf("\nFunc:EiArrayRealloc, EiArrayRealloc progress failed, array is Null!\n");
    }

    return result;
}

// 数组添加对象
int EiArrayAddObject (EiArray * array, void * object) {

    int result = 0, count = 0;

    if (array != NULL) {
        count = array->count + 1;

        if (count > array->cacheLength) {
            if (!EiArrayRealloc (array, count)) {
                return result;
            }
        }
        array->data [count - 1] = object;
        array->count = count;
        result = 1;
    } else {
        printf("\nFunc:EiArrayAddObject, EiArrayAddObject progress failed, string is Null!\n");
    }

    return result;
}

// 释放数组变量
int EiArrayRelease (EiArray * array) {

    int result = 0;

    if (array != NULL) {
        if (array->data != NULL) {
            free (array->data);
            array->data = NULL;
            array->count = 0;
            array->cacheLength = 0;
            result = 1;
        } else {
            printf("\nFunc:EiArrayRelease, EiArrayRelease progress failed, array's data is Null!\n");
        }
    } else {
        printf("\nFunc:EiArrayRelease, EiArrayRelease progress failed, array is Null!\n");
    }

    return result;
}
