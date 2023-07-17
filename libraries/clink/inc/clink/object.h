/*
 * ****************************************************************************
 *  @author      xqyjlj
 *  @file        object.h
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
#ifndef __CLINK_OBJECT_H__
#define __CLINK_OBJECT_H__

#include <clink/def.h>
#include <clink/list.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup object
 */

/**@{*/

/**
 * Base structure of object
 */
typedef struct clink_object
{
#if defined(CLINK_NAME_MAX) && CLINK_NAME_MAX > 0
    char name[CLINK_NAME_MAX]; /**< dynamic name of object */
#else
    uint8_t id;
#endif
    uint8_t      type; /**< type of object */
    uint8_t      flag; /**< flag of object */
    clink_list_t list; /**< list node of object */
} *clink_object_t;

enum clink_object_class_type
{
    CLINK_Object_Class_Null = 0x00, /**< The object is not used. */
    CLINK_Object_Class_Device,      /**< The object is a device. */
    CLINK_Object_Class_Unknown,     /**< The object is unknown. */
};

/**
 * The information of the object
 */
struct clink_object_information
{
    enum clink_object_class_type type;        /**< object class type */
    clink_list_t                 object_list; /**< object list */
    size_t                       object_size; /**< object size */
};

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
