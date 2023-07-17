/*
 * ****************************************************************************
 *  @author      xqyjlj
 *  @file        debug.h
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

#ifndef __CLINK_DEBUG_H__
#define __CLINK_DEBUG_H__

#include <clink/def.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup debug
 */

/**@{*/

#if defined(CLINK_DEBUG) && CLINK_DEBUG > 0
void clink_assert_handler(const char *ex, const char *func, size_t line);
#define CLINK_ASSERT(EX)                                                                                               \
    if (!(EX))                                                                                                         \
    {                                                                                                                  \
        clink_assert_handler(#EX, __FUNCTION__, __LINE__);                                                             \
    }
#else
#define CLINK_ASSERT(EX) CLINK_UNUSED(EX)
#endif

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
