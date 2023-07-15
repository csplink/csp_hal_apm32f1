/*
 * ****************************************************************************
 *  @author      xqyjlj
 *  @file        iccarm.h
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
 *  2023-07-09     xqyjlj       initial version
 */

#ifndef __CLINK_COMPILER_ICCARM_H__
#define __CLINK_COMPILER_ICCARM_H__

#ifndef __ICCARM__
#error This file should only be compiled by ICCARM
#endif

#define CLINK_SECTION(x) @x
#define CLINK_USED        __root
#define CLINK_ALIGN(n)    PRAGMA(data_alignment = n)

#define CLINK_WEAK        __weak
#define CLINK_INLINE      static inline
#define CLINK_FORCEINLINE _Pragma("inline=forced")

#endif  // __CLINK_COMPILER_ICCARM_H__
