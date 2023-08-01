/*
 * ****************************************************************************
 *  @author      xqyjlj
 *  @file        rtos.h
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
 *  2023-07-17     xqyjlj       initial version
 */

#ifndef __CLINK_RTOS_H__
#define __CLINK_RTOS_H__

#include <clink/def.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup debug
 */

/**@{*/

#if defined(CLINK_USING_RTTHREAD) && CLINK_USING_RTTHREAD > 0

#include <rtthread.h>
#define clink_lock      rt_enter_critical
#define clink_unlock    rt_exit_critical
#define clink_lockirq   rt_hw_interrupt_disable
#define clink_unlockirq rt_hw_interrupt_enable

#else
#define clink_lock()
#define clink_unlock()
#define clink_lockirq()    (0)
#define clink_unlockirq(X) ((void)(X))

#endif

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
