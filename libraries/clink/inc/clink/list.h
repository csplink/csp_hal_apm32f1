/*
 * ****************************************************************************
 *  @author      xqyjlj
 *  @file        list.h
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

#ifndef __CLINK_LIST_H__
#define __CLINK_LIST_H__

#include <clink/def.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup list
 */

/**@{*/

/**
 * clink_container_of - return the start address of struct type, while ptr is the
 * member of struct type.
 */
#define clink_container_of(ptr, type, member) ((type *)((char *)(ptr) - (unsigned long)(&((type *)0)->member)))

/**
 * Double List structure
 */
struct clink_list_node
{
    struct clink_list_node *next;            /**< point to next node. */
    struct clink_list_node *prev;            /**< point to prev node. */
};
typedef struct clink_list_node clink_list_t; /**< Type for lists. */

/**
 * @brief initialize a list object
 */
#define CLINK_LIST_OBJECT_INIT(object)                                                                                 \
    {                                                                                                                  \
        &(object), &(object)                                                                                           \
    }

/**
 * @brief initialize a list
 *
 * @param l list to be initialized
 */
CLINK_INLINE void clink_list_init(clink_list_t *l)
{
    l->next = l->prev = l;
}

/**
 * @brief insert a node after a list
 *
 * @param l list to insert it
 * @param n new node to be inserted
 */
CLINK_INLINE void clink_list_insert_after(clink_list_t *l, clink_list_t *n)
{
    l->next->prev = n;
    n->next       = l->next;

    l->next = n;
    n->prev = l;
}

/**
 * @brief insert a node before a list
 *
 * @param n new node to be inserted
 * @param l list to insert it
 */
CLINK_INLINE void clink_list_insert_before(clink_list_t *l, clink_list_t *n)
{
    l->prev->next = n;
    n->prev       = l->prev;

    l->prev = n;
    n->next = l;
}

/**
 * @brief remove node from list.
 * @param n the node to remove from the list.
 */
CLINK_INLINE void clink_list_remove(clink_list_t *n)
{
    n->next->prev = n->prev;
    n->prev->next = n->next;

    n->next = n->prev = n;
}

/**
 * @brief tests whether a list is empty
 * @param l the list to test.
 */
CLINK_INLINE int clink_list_isempty(const clink_list_t *l)
{
    return l->next == l;
}

/**
 * @brief get the list length
 * @param l the list to get.
 */
CLINK_INLINE unsigned int clink_list_len(const clink_list_t *l)
{
    unsigned int        len = 0;
    const clink_list_t *p   = l;
    while (p->next != l)
    {
        p = p->next;
        len++;
    }

    return len;
}

/**
 * @brief get the struct for this entry
 * @param node the entry point
 * @param type the type of structure
 * @param member the name of list in structure
 */
#define clink_list_entry(node, type, member) clink_container_of(node, type, member)

/**
 * clink_list_for_each - iterate over a list
 * @param pos the clink_list_t * to use as a loop cursor.
 * @param head the head for your list.
 */
#define clink_list_for_each(pos, head)       for (pos = (head)->next; pos != (head); pos = pos->next)

/**
 * clink_list_for_each_safe - iterate over a list safe against removal of list entry
 * @param pos the clink_list_t * to use as a loop cursor.
 * @param n another clink_list_t * to use as temporary storage
 * @param head the head for your list.
 */
#define clink_list_for_each_safe(pos, n, head)                                                                         \
    for (pos = (head)->next, n = pos->next; pos != (head); pos = n, n = pos->next)

/**
 * clink_list_for_each_entry  -   iterate over list of given type
 * @param pos the type * to use as a loop cursor.
 * @param head the head for your list.
 * @param member the name of the list_struct within the struct.
 */
#define clink_list_for_each_entry(pos, head, member)                                                                   \
    for (pos = clink_list_entry((head)->next, typeof(*pos), member); &pos->member != (head);                           \
         pos = clink_list_entry(pos->member.next, typeof(*pos), member))

/**
 * clink_list_for_each_entry_safe - iterate over list of given type safe against removal of list entry
 * @param pos the type * to use as a loop cursor.
 * @param n another type * to use as temporary storage
 * @param head the head for your list.
 * @param member the name of the list_struct within the struct.
 */
#define clink_list_for_each_entry_safe(pos, n, head, member)                                                           \
    for (pos = clink_list_entry((head)->next, typeof(*pos), member),                                                   \
         n = clink_list_entry(pos->member.next, typeof(*pos), member);                                                 \
         &pos->member != (head); pos = n, n = clink_list_entry(n->member.next, typeof(*n), member))

/**
 * clink_list_first_entry - get the first element from a list
 * @param ptr the list head to take the element from.
 * @param type the type of the struct this is embedded in.
 * @param member the name of the list_struct within the struct.
 *
 * Note, that list is expected to be not empty.
 */
#define clink_list_first_entry(ptr, type, member) clink_list_entry((ptr)->next, type, member)

/**
 * Single List structure
 */
struct clink_slist_node
{
    struct clink_slist_node *next;             /**< point to next node. */
};
typedef struct clink_slist_node clink_slist_t; /**< Type for single list. */

#define CLINK_SLIST_OBJECT_INIT(object)                                                                                \
    {                                                                                                                  \
        CLINK_NULL                                                                                                     \
    }

/**
 * @brief initialize a single list
 *
 * @param l the single list to be initialized
 */
CLINK_INLINE void clink_slist_init(clink_slist_t *l)
{
    l->next = CLINK_NULL;
}

CLINK_INLINE void clink_slist_append(clink_slist_t *l, clink_slist_t *n)
{
    struct clink_slist_node *node;

    node = l;
    while (node->next)
        node = node->next;

    /* append the node to the tail */
    node->next = n;
    n->next    = CLINK_NULL;
}

CLINK_INLINE void clink_slist_insert(clink_slist_t *l, clink_slist_t *n)
{
    n->next = l->next;
    l->next = n;
}

CLINK_INLINE unsigned int clink_slist_len(const clink_slist_t *l)
{
    unsigned int         len  = 0;
    const clink_slist_t *list = l->next;
    while (list != CLINK_NULL)
    {
        list = list->next;
        len++;
    }

    return len;
}

CLINK_INLINE clink_slist_t *clink_slist_remove(clink_slist_t *l, clink_slist_t *n)
{
    /* remove slist head */
    struct clink_slist_node *node = l;
    while (node->next && node->next != n)
        node = node->next;

    /* remove node */
    if (node->next != (clink_slist_t *)0)
        node->next = node->next->next;

    return l;
}

CLINK_INLINE clink_slist_t *clink_slist_first(clink_slist_t *l)
{
    return l->next;
}

CLINK_INLINE clink_slist_t *clink_slist_tail(clink_slist_t *l)
{
    while (l->next)
        l = l->next;

    return l;
}

CLINK_INLINE clink_slist_t *clink_slist_next(clink_slist_t *n)
{
    return n->next;
}

CLINK_INLINE int clink_slist_isempty(clink_slist_t *l)
{
    return l->next == CLINK_NULL;
}

/**
 * @brief get the struct for this single list node
 * @param node the entry point
 * @param type the type of structure
 * @param member the name of list in structure
 */
#define clink_slist_entry(node, type, member) clink_container_of(node, type, member)

/**
 * clink_slist_for_each - iterate over a single list
 * @param pos the clink_slist_t * to use as a loop cursor.
 * @param head the head for your single list.
 */
#define clink_slist_for_each(pos, head)       for (pos = (head)->next; pos != CLINK_NULL; pos = pos->next)

/**
 * clink_slist_for_each_entry  -   iterate over single list of given type
 * @param pos the type * to use as a loop cursor.
 * @param head the head for your single list.
 * @param member the name of the list_struct within the struct.
 */
#define clink_slist_for_each_entry(pos, head, member)                                                                  \
    for (pos = clink_slist_entry((head)->next, typeof(*pos), member); &pos->member != (CLINK_NULL);                    \
         pos = clink_slist_entry(pos->member.next, typeof(*pos), member))

/**
 * clink_slist_first_entry - get the first element from a slist
 * @param ptr the slist head to take the element from.
 * @param type the type of the struct this is embedded in.
 * @param member the name of the slist_struct within the struct.
 *
 * Note, that slist is expected to be not empty.
 */
#define clink_slist_first_entry(ptr, type, member) clink_slist_entry((ptr)->next, type, member)

/**
 * clink_slist_tail_entry - get the tail element from a slist
 * @param ptr the slist head to take the element from.
 * @param type the type of the struct this is embedded in.
 * @param member the name of the slist_struct within the struct.
 *
 * Note, that slist is expected to be not empty.
 */
#define clink_slist_tail_entry(ptr, type, member)  clink_slist_entry(clink_slist_tail(ptr), type, member)

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
