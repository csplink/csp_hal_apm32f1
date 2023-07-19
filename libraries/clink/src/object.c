/*
 * ****************************************************************************
 *  @author      xqyjlj
 *  @file        object.c
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
 *  Copyright (C) 2006-2021 RT-Thread Development Team
 *  Copyright (C) 2023-2023 xqyjlj<xqyjlj@126.com>
 *
 * ****************************************************************************
 *  Change Logs:
 *  Date           Author       Notes
 *  ------------   ----------   -----------------------------------------------
 *  2023-07-15     xqyjlj       copy from RT-Thread
 *  2023-07-15     xqyjlj       initial version
 */
#include <clink/debug.h>
#include <clink/object.h>

struct clink_custom_object
{
    struct clink_object parent;
    void               *data;
};

#define _OBJ_CONTAINER_LIST_INIT(c)                                                                                    \
    {                                                                                                                  \
        &(_object_container[c].object_list), &(_object_container[c].object_list)                                       \
    }

static struct clink_object_information _object_container[CLINK_Object_Class_Unknown] = {
    {_OBJ_CONTAINER_LIST_INIT(CLINK_Object_Class_Device)},
};

/**
 * @addtogroup KernelObject
 */

/**@{*/

/**
 * @brief This function will return the specified type of object information.
 *
 * @param type is the type of object, which can be
 *             CLINK_Object_Class_Device/... etc
 *
 * @return the object type information or CLINK_NULL
 */
struct clink_object_information *clink_object_get_information(uint8_t type)
{
    if (type > CLINK_Object_Class_Null && type < CLINK_Object_Class_Unknown)
        return &_object_container[type];

    return CLINK_NULL;
}

/**
 * @brief This function will return the length of object list in object container.
 *
 * @param type is the type of object, which can be
 *             CLINK_Object_Class_Device/... etc
 *
 * @return the length of object list
 */
int clink_object_get_length(uint8_t type)
{
    int                              count = 0;
    clink_base_t                     level;
    struct clink_list_node          *node        = CLINK_NULL;
    struct clink_object_information *information = CLINK_NULL;

    information = clink_object_get_information(type);
    if (information == CLINK_NULL)
        return 0;

    level = clink_hw_interrupt_disable();
    /* get the count of objects */
    clink_list_for_each(node, &(information->object_list))
    {
        count++;
    }
    clink_hw_interrupt_enable(level);

    return count;
}

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
int clink_object_get_pointers(uint8_t type, clink_object_t *pointers, int maxlen)
{
    int          index = 0;
    clink_base_t level;

    struct clink_object             *object;
    struct clink_list_node          *node        = CLINK_NULL;
    struct clink_object_information *information = CLINK_NULL;

    if (maxlen <= 0)
        return 0;

    information = clink_object_get_information(type);
    if (information == CLINK_NULL)
        return 0;

    level = clink_hw_interrupt_disable();
    /* retrieve pointer of object */
    clink_list_for_each(node, &(information->object_list))
    {
        object = clink_list_entry(node, struct clink_object, list);

        pointers[index] = object;
        index++;

        if (index >= maxlen)
            break;
    }
    clink_hw_interrupt_enable(level);

    return index;
}

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
#if defined(CLINK_NAME_MAX) && CLINK_NAME_MAX > 0
void clink_object_init_byname(struct clink_object *object, uint8_t type, const char *name)
{
    clink_base_t                     level;
    struct clink_object_information *information;

    /* get object information */
    information = clink_object_get_information(type);
    CLINK_ASSERT(information != CLINK_NULL);

    /* initialize object's parameters */
    object->type = type;

    clink_strncpy(object->name, name, CLINK_NAME_MAX); /* copy name */

    /* lock interrupt */
    level = clink_hw_interrupt_disable();

    /* insert object into information object list */
    clink_list_insert_after(&(information->object_list), &(object->list));

    /* unlock interrupt */
    clink_hw_interrupt_enable(level);
}
#endif

/**
 * @brief This function will detach a static object from object system,
 *        and the memory of static object is not freed.
 *
 * @param object the specified object to be detached.
 */
void clink_object_detach(clink_object_t object)
{
    clink_base_t level;

    /* object check */
    CLINK_ASSERT(object != CLINK_NULL);

    /* reset object type */
    object->type = 0;

    /* lock interrupt */
    level = clink_hw_interrupt_disable();

    /* remove from old list */
    clink_list_remove(&(object->list));

    /* unlock interrupt */
    clink_hw_interrupt_enable(level);
}

/**
 * @brief This function will return the type of object.
 *
 * @param object is the specified object to be get type.
 *
 * @return the type of object.
 */
uint8_t clink_object_get_type(clink_object_t object)
{
    /* object check */
    CLINK_ASSERT(object != CLINK_NULL);

    return object->type;
}

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
#if defined(CLINK_NAME_MAX) && CLINK_NAME_MAX > 0
clink_object_t clink_object_find_byname(const char *name, uint8_t type)
{
    struct clink_object             *object      = CLINK_NULL;
    struct clink_list_node          *node        = CLINK_NULL;
    struct clink_object_information *information = CLINK_NULL;

    information = clink_object_get_information(type);

    /* parameter check */
    if ((name == CLINK_NULL) || (information == CLINK_NULL))
        return CLINK_NULL;

    /* enter critical */
    clink_enter_critical();

    /* try to find object */
    clink_list_for_each(node, &(information->object_list))
    {
        object = clink_list_entry(node, struct clink_object, list);
        if (clink_strncmp(object->name, name, CLINK_NAME_MAX) == 0)
        {
            /* leave critical */
            clink_exit_critical();

            return object;
        }
    }

    /* leave critical */
    clink_exit_critical();

    return CLINK_NULL;
}
#endif

/**@}*/
