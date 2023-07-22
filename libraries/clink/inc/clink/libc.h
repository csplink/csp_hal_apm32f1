/*
 * ****************************************************************************
 *  @author      xqyjlj
 *  @file        libc.h
 *  @brief
 *
 * ****************************************************************************
 *  @attention
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  You may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  Copyright (C) 2023-2023 xqyjlj<xqyjlj@126.com>
 *
 * ****************************************************************************
 *  Change Logs:
 *  Date           Author       Notes
 *  ------------   ----------   -----------------------------------------------
 *  2023-07-17     xqyjlj       initial version
 */

#ifndef __CLINK_LIBC_H__
#define __CLINK_LIBC_H__

#include <clink/def.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup libc
 */

/**@{*/
#ifndef CLINK_USING_STDLIB
void  *clink_memset(void *s, int c, size_t count);
void  *clink_memcpy(void *dst, const void *src, size_t count);
void  *clink_memmove(void *dest, const void *src, size_t n);
int    clink_memcmp(const void *cs, const void *ct, size_t count);
char  *clink_strstr(const char *s1, const char *s2);
int    clink_strcasecmp(const char *a, const char *b);
char  *clink_strncpy(char *dst, const char *src, size_t n);
char  *clink_strcpy(char *dst, const char *src);
int    clink_strncmp(const char *cs, const char *ct, size_t count);
int    clink_strcmp(const char *cs, const char *ct);
size_t clink_strlen(const char *s);
size_t clink_strnlen(const char *s, size_t maxlen);
#else
#include <string.h>
#define clink_memset     memset
#define clink_memcpy     memcpy
#define clink_memmove    memmove
#define clink_memcmp     memcmp
#define clink_strstr     strstr
#define clink_strcasecmp strcasecmp
#define clink_strncpy    strncpy
#define clink_strcpy     strcpy
#define clink_strcmp     strcmp
#define clink_strlen     strlen
#define clink_strnlen    strnlen

#endif
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
