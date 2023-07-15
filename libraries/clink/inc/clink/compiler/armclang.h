/*
 * ****************************************************************************
 *  @author      xqyjlj
 *  @file        armclang.h
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

#ifndef __CLINK_COMPILER_ARMCLANG_H__
#define __CLINK_COMPILER_ARMCLANG_H__

#ifndef __ARMCC_VERSION
#error This file should only be compiled by Arm Compiler
#endif

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION < 6010050)
#error "Please use Arm Compiler Toolchain V6.6 or later!"
#endif

#include <stdarg.h>
#define CLINK_SECTION(x)  __attribute__((section(x)))
#define CLINK_USED        __attribute__((used))
#define CLINK_ALIGN(n)    __attribute__((aligned(n)))

#define CLINK_WEAK        __attribute__((weak))
#define CLINK_INLINE      static __inline
#define CLINK_FORCEINLINE __attribute__((always_inline)) static __inline

#endif  // __CLINK_COMPILER_ARMCLANG_H__
