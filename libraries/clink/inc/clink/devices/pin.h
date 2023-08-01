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

#if defined(CLINK_USING_DEVICES_PIN) && CLINK_USING_DEVICES_PIN > 0

enum clink_pin_value_type
{
    CLINK_PIN_VALUE_LOW = 0x00,
    CLINK_PIN_VALUE_HIGH
};

enum clink_pin_mode_type
{
    CLINK_PIN_MODE_OUTPUT = 0x00,
    CLINK_PIN_MODE_OUTPUT_PP,
    CLINK_PIN_MODE_OUTPUT_OD,
    CLINK_PIN_MODE_INPUT,
    CLINK_PIN_MODE_INPUT_PULLUP,
    CLINK_PIN_MODE_INPUT_PULLDOWN
};

enum clink_pin_speed_type
{
    CLINK_PIN_SPEED_LOW = 0x00,
    CLINK_PIN_SPEED_MEDIUM,
    CLINK_PIN_SPEED_HIGH,
    CLINK_PIN_SPEED_VERY_HIGH
};

enum clink_pin_ctrl_cmd_type
{
    CLINK_PIN_CTRL_SET_MODE = 0x00,
    CLINK_PIN_CTRL_WRITE_VALUE,
    CLINK_PIN_CTRL_READ_VALUE,
    CLINK_PIN_CTRL_TOGGLE,
    CLINK_PIN_CTRL_SET_IRQ,
    CLINK_PIN_CTRL_ENABLE_IRQ,
    CLINK_PIN_CTRL_DISABLE_IRQ
};

enum clink_pin_irq_mode_type
{
    CLINK_PIN_IRQ_MODE_RISING = 0x00,
    CLINK_PIN_IRQ_MODE_FALLING,
    CLINK_PIN_IRQ_MODE_RISING_FALLING,
    CLINK_PIN_IRQ_MODE_HIGH_LEVEL,
    CLINK_PIN_IRQ_MODE_LOW_LEVEL
};

typedef struct clink_pin_mode
{
    clink_base_t pin;
    uint8_t      mode;  /* e.g. CLINK_PIN_MODE_OUTPUT */
    uint8_t      speed; /* e.g. CLINK_PIN_SPEED_LOW */
} *clink_pin_mode_t;

typedef struct clink_pin_value
{
    clink_base_t pin;
    uint8_t      value; /* CLINK_PIN_LOW or CLINK_PIN_HIGH */
} *clink_pin_value_t;

typedef struct clink_pin_irq_hdr
{
    clink_base_t pin;
    void (*hdr)(void *args);
    void *args;
} *clink_pin_irq_hdr_t;

typedef struct clink_pin_irq
{
    clink_base_t pin;
    uint8_t      mode;  /* e.g. PIN_IRQ_MODE_RISING */
    uint8_t      speed; /* e.g. CLINK_PIN_SPEED_LOW */
} *clink_pin_irq_t;

int            clink_pin_register(const struct clink_device_ops *ops, void *user_data);
clink_err_t    clink_pin_attach_irq(clink_base_t pin, void (*hdr)(void *args), void *args);
clink_err_t    clink_pin_detach_irq(clink_base_t pin);
clink_err_t    clink_pin_irq_enable(clink_base_t pin, uint8_t mode, uint8_t speed);
clink_err_t    clink_pin_irq_disable(clink_base_t pin);
void           clink_pin_mode(clink_base_t pin, uint8_t mode, uint8_t speed);
void           clink_pin_write(clink_base_t pin, uint8_t value);
int8_t         clink_pin_read(clink_base_t pin);
clink_device_t clink_pin_get_device();

#endif  // CLINK_USING_DEVICES_PIN

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
