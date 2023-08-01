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

#if defined(CLINK_USING_DEVICES_PIN) && CLINK_USING_DEVICES_PIN > 0

struct clink_device chal_pin_device = {0};

int clink_pin_register(const struct clink_device_ops *ops, void *user_data)
{
    chal_pin_device.rx_indicate = CLINK_NULL;
    chal_pin_device.tx_complete = CLINK_NULL;
    chal_pin_device.ops         = ops;
    chal_pin_device.user_data   = user_data;

    /* register a pin device */
    clink_device_register(&chal_pin_device, CLINK_DEVICE_FLAG_RDWR);

    return 0;
}

clink_err_t clink_pin_attach_irq(clink_base_t pin, void (*hdr)(void *args), void *args)
{
    CLINK_ASSERT(chal_pin_device.ops != CLINK_NULL);
    struct clink_pin_irq_hdr irq_hdr = {0};

    irq_hdr.pin  = pin;
    irq_hdr.hdr  = hdr;
    irq_hdr.args = args;
    return clink_device_control(&chal_pin_device, CLINK_PIN_CTRL_SET_IRQ, (void *)&irq_hdr);
}

clink_err_t clink_pin_detach_irq(clink_base_t pin)
{
    CLINK_ASSERT(chal_pin_device.ops != CLINK_NULL);
    struct clink_pin_irq_hdr irq_hdr = {0};

    irq_hdr.pin  = pin;
    irq_hdr.hdr  = CLINK_NULL;
    irq_hdr.args = CLINK_NULL;
    return clink_device_control(&chal_pin_device, CLINK_PIN_CTRL_SET_IRQ, (void *)&irq_hdr);
}

clink_err_t clink_pin_irq_enable(clink_base_t pin, uint8_t mode, uint8_t speed)
{
    CLINK_ASSERT(chal_pin_device.ops != CLINK_NULL);
    struct clink_pin_irq irq;

    irq.pin   = pin;
    irq.mode  = mode;
    irq.speed = speed;

    return clink_device_control(&chal_pin_device, CLINK_PIN_CTRL_ENABLE_IRQ, (void *)&irq);
}

clink_err_t clink_pin_irq_disable(clink_base_t pin)
{
    CLINK_ASSERT(chal_pin_device.ops != CLINK_NULL);
    struct clink_pin_irq irq;

    irq.pin   = pin;
    irq.mode  = 0;
    irq.speed = 0;
    return clink_device_control(&chal_pin_device, CLINK_PIN_CTRL_DISABLE_IRQ, (void *)&irq);
}

void clink_pin_mode(clink_base_t pin, uint8_t mode, uint8_t speed)
{
    CLINK_ASSERT(chal_pin_device.ops != CLINK_NULL);
    struct clink_pin_mode pin_mode = {0};

    pin_mode.pin   = pin;
    pin_mode.mode  = mode;
    pin_mode.speed = speed;
    clink_device_control(&chal_pin_device, CLINK_PIN_CTRL_SET_MODE, (void *)&pin_mode);
}

void clink_pin_write(clink_base_t pin, uint8_t value)
{
    CLINK_ASSERT(chal_pin_device.ops != CLINK_NULL);
    struct clink_pin_value pin_value = {0};

    pin_value.pin   = pin;
    pin_value.value = value;
    clink_device_control(&chal_pin_device, CLINK_PIN_CTRL_WRITE_VALUE, (void *)&pin_value);
}

int8_t clink_pin_read(clink_base_t pin)
{
    CLINK_ASSERT(chal_pin_device.ops != CLINK_NULL);
    struct clink_pin_value pin_value = {0};

    pin_value.pin = pin;
    if (clink_device_control(&chal_pin_device, CLINK_PIN_CTRL_READ_VALUE, (void *)&pin_value) != CLINK_EOK)
    {
        return (int8_t)pin_value.value;
    }
    else
    {
        return -1;
    }
}

void clink_pin_toggle(clink_base_t pin)
{
    CLINK_ASSERT(chal_pin_device.ops != CLINK_NULL);
    struct clink_pin_value pin_value = {0};

    pin_value.pin = pin;
    clink_device_control(&chal_pin_device, CLINK_PIN_CTRL_TOGGLE, (void *)&pin_value);
}

clink_device_t clink_pin_get_device()
{
    return &chal_pin_device;
}

#endif  // CLINK_USING_DEVICES_PIN
