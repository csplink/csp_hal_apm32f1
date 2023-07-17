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
 *  Copyright (C) 2006-2022 RT-Thread Development Team
 *  Copyright (C) 2023-2023 xqyjlj<xqyjlj@126.com>
 *
 * ****************************************************************************
 *  Change Logs:
 *  Date           Author       Notes
 *  ------------   ----------   -----------------------------------------------
 *  2023-07-15     xqyjlj       copy from RT-Thread
 *  2023-07-15     xqyjlj       initial version
 */

#ifndef __CLINK_DEF_H__
#define __CLINK_DEF_H__

#include <clink/compiler.h>
#include <clink/rtos.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup def
 */

/**@{*/

#define CLINK_UNUSED(x) ((void)(x))

/* boolean type definitions */
#define CLINK_TRUE      1 /**< boolean true  */
#define CLINK_FALSE     0 /**< boolean fails */

/* null pointer definition */
#define CLINK_NULL      0

#define CLINK_EOK       0            /**< There is no error */
#define CLINK_ERROR     1            /**< A generic error happens */
#define CLINK_ETIMEOUT  2            /**< Timed out */
#define CLINK_EFULL     3            /**< The resource is full */
#define CLINK_EEMPTY    4            /**< The resource is empty */
#define CLINK_ENOMEM    5            /**< No memory */
#define CLINK_ENOSYS    6            /**< No system */
#define CLINK_EBUSY     7            /**< Busy */
#define CLINK_EIO       8            /**< IO error */
#define CLINK_EINTR     9            /**< Interrupted system call */
#define CLINK_EINVAL    10           /**< Invalid argument */
#define CLINK_ETRAP     11           /**< Trap event */
#define CLINK_ENOENT    12           /**< No entry */
#define CLINK_ENOSPC    13           /**< No space left */

typedef size_t        clink_err_t;   /**< Type for error number */
typedef int           clink_bool_t;  /**< boolean type */
typedef signed long   clink_base_t;  /**< Nbit CPU related date type */
typedef unsigned long clink_ubase_t; /**< Nbit unsigned CPU related data type */

/**@}*/

#ifdef __cplusplus
}
#endif

#endif