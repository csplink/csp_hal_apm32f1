/*
 * ****************************************************************************
 *  @author      xqyjlj
 *  @file        service.h
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
 *  2023-08-02     xqyjlj       initial version
 */

#ifndef __CLINK_SERVICE_H__
#define __CLINK_SERVICE_H__

#include <clink/def.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup service
 */

/**@{*/

void clink_delay_ms(uint32_t ms);
void clink_delay_us(uint32_t us);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
