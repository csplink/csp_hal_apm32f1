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
#error CLINK_NAME_MAX must be greater than 0
#endif
    uint8_t      type; /**< type of object */
    uint8_t      flag; /**< flag of object */
    clink_list_t list; /**< list node of object */
} *clink_object_t;

enum clink_object_class_type
{
    Clink_Object_Class_Null   = -1,   /**< The object is not used. */
    Clink_Object_Class_Device = 0x00, /**< The object is a device. */
    Clink_Object_Class_Unknown,       /**< The object is unknown. */
};

/**
 * The information of the object
 */
typedef struct clink_object_information
{
    clink_list_t object_list; /**< object list */
} *clink_object_information_t;

/**
 * @brief This function will return the specified type of object information.
 *
 * @param type is the type of object, which can be
 *             CLINK_Object_Class_Device/... etc
 *
 * @return the object type information or CLINK_NULL
 */
clink_object_information_t clink_object_get_information(uint8_t type);

/**
 * @brief This function will return the length of object list in object container.
 *
 * @param type is the type of object, which can be
 *             CLINK_Object_Class_Device/... etc
 *
 * @return the length of object list
 */
int clink_object_get_length(uint8_t type);

/**
 * @brief This function will copy the object pointer of the specified type,
 *        with the maximum size specified by maxlen.
 *
 * @param type is the type of object, which can be
 *             CLINK_Object_Class_Device/... etc
 *
 * @param pointers is the pointer will be saved to.
 *
 * @param maxlen is the maximum number of pointers can be saved.
 *
 * @return the copied number of object pointers.
 */
int clink_object_get_pointers(uint8_t type, clink_object_t *pointers, int maxlen);

/**
 * @brief This function will detach a static object from object system,
 *        and the memory of static object is not freed.
 *
 * @param object the specified object to be detached.
 */
void clink_object_detach(clink_object_t object);

/**
 * @brief This function will return the type of object.
 *
 * @param object is the specified object to be get type.
 *
 * @return the type of object.
 */
uint8_t clink_object_get_type(clink_object_t object);

/**
 * @brief This function will initialize an object and add it to object system
 *        management.
 *
 * @param object is the specified object to be initialized.
 *
 * @param type is the object type.
 *
 * @param name is the object name. In system, the object's name must be unique.
 */
void clink_object_init(struct clink_object *object, uint8_t type, const char *name);

/**
 * @brief This function will find specified name object from object
 *        container.
 *
 * @param name is the specified name of object.
 *
 * @param type is the type of object
 *
 * @return the found object or CLINK_NULL if there is no this object
 * in object container.
 *
 * @note this function shall not be invoked in interrupt status.
 */
clink_object_t clink_object_find(const char *name, uint8_t type);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
