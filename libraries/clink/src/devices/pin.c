/*
 * ****************************************************************************
 *  @author      xqyjlj
 *  @file        pin.c
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
 *  Copyright (C) 2006-2023 RT-Thread Development Team
 *  Copyright (C) 2023-2023 xqyjlj<xqyjlj@126.com>
 *
 * ****************************************************************************
 *  Change Logs:
 *  Date           Author       Notes
 *  ------------   ----------   -----------------------------------------------
 *  2023-07-23     xqyjlj       copy from RT-Thread
 *  2023-07-23     xqyjlj       initial version
 */

#include <clink/debug.h>
#include <clink/devices/pin.h>

static struct clink_device _hw_pin = {0};

int clink_device_pin_register(const char *name, const struct clink_device_ops *ops, void *user_data)
{
    _hw_pin.type        = Clink_Device_Class_Pin;
    _hw_pin.rx_indicate = CLINK_NULL;
    _hw_pin.tx_complete = CLINK_NULL;
    _hw_pin.ops         = ops;
    _hw_pin.user_data   = user_data;

    /* register a pin device */
    clink_device_register(&_hw_pin, name, CLINK_DEVICE_FLAG_RDWR);

    return 0;
}

clink_err_t clink_device_pin_attach_irq(clink_base_t pin, uint8_t mode, void (*hdr)(void *args), void *args)
{
    CLINK_ASSERT(_hw_pin.ops != CLINK_NULL);
    struct clink_device_pin_irq_hdr irq_hdr = {0};

    irq_hdr.pin  = pin;
    irq_hdr.mode = mode;
    irq_hdr.hdr  = hdr;
    irq_hdr.args = args;
    return clink_device_control(&_hw_pin, CLINK_PIN_CTRL_SET_IRQ_HDR, (void *)&irq_hdr);
}

clink_err_t clink_device_pin_detach_irq(clink_base_t pin)
{
    CLINK_ASSERT(_hw_pin.ops != CLINK_NULL);
    struct clink_device_pin_irq_hdr irq_hdr = {0};

    irq_hdr.pin  = pin;
    irq_hdr.mode = 0;
    irq_hdr.hdr  = CLINK_NULL;
    irq_hdr.args = CLINK_NULL;
    return clink_device_control(&_hw_pin, CLINK_PIN_CTRL_SET_IRQ_HDR, (void *)&irq_hdr);
}

clink_err_t clink_device_pin_irq_enable(clink_base_t pin, uint8_t enabled)
{
    CLINK_ASSERT(_hw_pin.ops != CLINK_NULL);
    if (enabled)
        return clink_device_control(&_hw_pin, CLINK_PIN_CTRL_ENABLE_IRQ, (void *)&pin);
    else
        return clink_device_control(&_hw_pin, CLINK_PIN_CTRL_DISABLE_IRQ, (void *)&pin);
}

void clink_device_pin_mode(clink_base_t pin, uint8_t mode)
{
    CLINK_ASSERT(_hw_pin.ops != CLINK_NULL);
    struct clink_device_pin_mode pin_mode = {0};

    pin_mode.pin  = pin;
    pin_mode.mode = mode;
    clink_device_control(&_hw_pin, CLINK_PIN_CTRL_SET_MODE, (void *)&pin_mode);
}

void clink_device_pin_write(clink_base_t pin, uint8_t value)
{
    CLINK_ASSERT(_hw_pin.ops != CLINK_NULL);
    struct clink_device_pin_value pin_value = {0};

    pin_value.pin   = pin;
    pin_value.value = value;
    clink_device_control(&_hw_pin, CLINK_PIN_CTRL_WRITE_VALUE, (void *)&pin_value);
}

int8_t clink_device_pin_read(clink_base_t pin)
{
    CLINK_ASSERT(_hw_pin.ops != CLINK_NULL);
    struct clink_device_pin_value pin_value = {0};

    pin_value.pin = pin;
    if (clink_device_control(&_hw_pin, CLINK_PIN_CTRL_READ_VALUE, (void *)&pin_value) != CLINK_EOK)
    {
        return (int8_t)pin_value.value;
    }
    else
    {
        return -1;
    }
}
