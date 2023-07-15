/*
 * ****************************************************************************
 *  @author      xqyjlj
 *  @file        compiler.h
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

#ifndef __CLINK_COMPILER_H__
#define __CLINK_COMPILER_H__

#include <stdint.h>

/*
 * Arm Compiler 4/5
 */
#if defined(__CC_ARM)
#include <clink/compiler/armcc.h>

/*
 * Arm Compiler 6 (armclang)
 */
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#include <clink/compiler/armclang.h>

/*
 * GNU Compiler
 */
#elif defined(__GNUC__)
#include <clink/compiler/gcc.h>

/*
 * IAR Compiler
 */
#elif defined(__ICCARM__)
#include <clink/compiler/iccarm.h>

#else
#error Unknown compiler.
#endif

#endif  // __CLINK_COMPILER_H__
