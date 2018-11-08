//
//  EiArray.h
//  EinerLanguageDemo
//
//  Created by 褚鹏 on 2018/10/5.
//  Copyright © 2018年 Einer. All rights reserved.
//

#ifndef EiArray_h
#define EiArray_h

#include <stdio.h>
#include <stdlib.h>

typedef struct EiArray {
    int     count;              // array's data count
    int     cacheLength;        // array's memory length
    void ** data;               // data
} EiArray;

#define EIARRAY_INIT_SIZE 12   // Eistring 默认的初始化大小

/*!
 @brief 初始化数组变量 array 数组变量
 */
int EiArrayInit (EiArray * array);

/*!
 @brief 初始化数组变量 array 数组变量 cacheLength:数据缓存长度
 */
int EiArrayInitWithCacheLength (EiArray * array, int cacheLength);

/*!
 @brief 初始化数组变量 array 数组变量 newSize:新数据长度
 */
int EiArrayRealloc (EiArray * array, int newSize);

/*!
 @brief 添加对象到数组变量 array 数组变量 object:新数据对象
 */
int EiArrayAddObject (EiArray * array, void * object);

/*!
 @brief 释放数组变量 array 数组变量
 */
int EiArrayRelease (EiArray * array);

#endif /* EiArray_h */
