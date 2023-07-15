/*
 * ****************************************************************************
 *  @author      xqyjlj
 *  @file        def.h
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
 *  2023-07-15     xqyjlj       initial version
 */

#ifndef __CLINK_DEF_H__
#define __CLINK_DEF_H__

#include <clink/compiler.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup def
 */

/**@{*/

#define CLINK_UNUSED(x) ((void)x)

/* boolean type definitions */
#define CLINK_TRUE      1 /**< boolean true  */
#define CLINK_FALSE     0 /**< boolean fails */

/* null pointer definition */
#define CLINK_NULL      0

/**@}*/

#ifdef __cplusplus
}
#endif

#endif