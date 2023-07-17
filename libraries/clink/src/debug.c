/*
 * ****************************************************************************
 *  @author      xqyjlj
 *  @file        debug.c
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
 *  2023-07-16     xqyjlj       initial version
 */
#include <clink/debug.h>

#if defined(CLINK_DEBUG) && CLINK_DEBUG > 0

CLINK_WEAK void clink_assert_handler(const char *ex, const char *func, size_t line)
{
    CLINK_UNUSED(ex);
    CLINK_UNUSED(func);
    CLINK_UNUSED(line);
}

#endif
