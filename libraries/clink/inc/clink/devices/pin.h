/*
 * ****************************************************************************
 *  @author      xqyjlj
 *  @file        pin.h
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
 *  2023-07-21     xqyjlj       copy from RT-Thread
 *  2023-07-21     xqyjlj       initial version
 */

#ifndef __CLINK_DEVICES_PIN_H__
#define __CLINK_DEVICES_PIN_H__

#include <clink/device.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup pin
 */

/**@{*/

enum clink_device_ctrl_cmd
{
    CLINK_PIN_CTRL_GET_MODE = 0x01,
    CLINK_PIN_CTRL_SET_MODE,
    CLINK_PIN_CTRL_WRITE_VALUE,
    CLINK_PIN_CTRL_READ_VALUE,
    CLINK_PIN_CTRL_GET_IRQ_HDR,
    CLINK_PIN_CTRL_SET_IRQ_HDR,
    CLINK_PIN_CTRL_ENABLE_IRQ,
    CLINK_PIN_CTRL_DISABLE_IRQ
};

typedef struct clink_device_pin_mode
{
    clink_base_t pin;
    uint8_t      mode; /* e.g. CLINK_PIN_MODE_OUTPUT */
} *clink_device_pin_mode_t;

typedef struct clink_device_pin_value
{
    clink_base_t pin;
    uint8_t      value; /* CLINK_PIN_LOW or CLINK_PIN_HIGH */
} *clink_device_pin_value_t;

typedef struct clink_device_pin_irq_hdr
{
    clink_base_t pin;
    uint8_t      mode; /* e.g. PIN_IRQ_MODE_RISING */
    void (*hdr)(void *args);
    void *args;
} *clink_device_pin_irq_hdr_t;

int         clink_device_pin_register(const char *name, const struct clink_device_ops *ops, void *user_data);
clink_err_t clink_device_pin_attach_irq(clink_base_t pin, uint8_t mode, void (*hdr)(void *args), void *args);
clink_err_t clink_device_pin_detach_irq(clink_base_t pin);
clink_err_t clink_device_pin_irq_enable(clink_base_t pin, uint8_t enabled);
void        clink_device_pin_mode(clink_base_t pin, uint8_t mode);
void        clink_device_pin_write(clink_base_t pin, uint8_t value);
int8_t      clink_device_pin_read(clink_base_t pin);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
