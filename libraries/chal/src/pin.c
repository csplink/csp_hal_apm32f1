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
 *  Copyright (C) 2023-2023 xqyjlj<xqyjlj@126.com>
 *
 * ****************************************************************************
 *  Change Logs:
 *  Date           Author       Notes
 *  ------------   ----------   -----------------------------------------------
 *  2023-07-26     xqyjlj       initial version
 */

#include <chal/pin.h>
#include <clink/debug.h>

#if defined(CLINK_USING_DEVICES_PIN) && CLINK_USING_DEVICES_PIN > 0

#define __PORT(pin)       ((uint8_t)(((pin) >> 4) & 0xFu))
#define __PIN(pin)        ((uint8_t)((pin)&0xFu))

#define __HAL_PORT(pin)   ((GPIO_T *)(GPIOA_BASE + (0x400u * __PORT(pin))))
#define __HAL_PIN(pin)    ((uint16_t)(1u << __PIN(pin)))

#define __CLOCK_PORT(pin) ((uint16_t)(1u << (__PORT(pin) + 2)))

struct _pin_irq_hdr
{
    void (*hdr)(void *args);
    void *args;
};

#if defined(CLINK_USING_DEVICES_PIN_IRQ) && CLINK_USING_DEVICES_PIN_IRQ > 0
static struct _pin_irq_hdr _pin_irq_hdr_tab[16] = {{0}};
#endif  // CLINK_USING_DEVICES_PIN_IRQ

CLINK_WEAK void chal_pin_set_mode_user_callback(GPIO_T *port, uint16_t pin, clink_pin_mode_t mode)
{
    CLINK_UNUSED(port);
    CLINK_UNUSED(pin);
    CLINK_UNUSED(mode);
}

CLINK_WEAK void chal_pin_enable_irq_user_callback(GPIO_T *port, uint16_t pin, clink_pin_irq_t irq)
{
    CLINK_UNUSED(port);
    CLINK_UNUSED(pin);
    CLINK_UNUSED(irq);
}

CLINK_WEAK void chal_pin_disable_irq_user_callback(GPIO_T *port, uint16_t pin, clink_pin_irq_t irq)
{
    CLINK_UNUSED(port);
    CLINK_UNUSED(pin);
    CLINK_UNUSED(irq);
}

static clink_err_t pin_set_mode(clink_pin_mode_t mode)
{
    CLINK_ASSERT(mode != CLINK_NULL);

    GPIO_Config_T config;
    clink_err_t   err  = CLINK_EOK;
    GPIO_T       *port = CLINK_NULL;
    uint16_t      pin  = 0;

    port = __HAL_PORT(mode->pin);
    pin  = __HAL_PIN(mode->pin);

    config.pin = pin;

    switch (mode->mode)
    {
        case CLINK_PIN_MODE_OUTPUT:
        case CLINK_PIN_MODE_OUTPUT_PP: config.mode = GPIO_MODE_OUT_PP; break;
        case CLINK_PIN_MODE_OUTPUT_OD: config.mode = GPIO_MODE_OUT_OD; break;
        case CLINK_PIN_MODE_INPUT:
        case CLINK_PIN_MODE_INPUT_PULLUP: config.mode = GPIO_MODE_IN_PU; break;
        case CLINK_PIN_MODE_INPUT_PULLDOWN: config.mode = GPIO_MODE_IN_PD; break;
        default: return -CLINK_EINVAL;
    }
    switch (mode->speed)
    {
        case CLINK_PIN_SPEED_LOW: config.speed = GPIO_SPEED_10MHz; break;
        case CLINK_PIN_SPEED_MEDIUM: config.speed = GPIO_SPEED_2MHz; break;
        case CLINK_PIN_SPEED_HIGH:
        case CLINK_PIN_SPEED_VERY_HIGH: config.speed = GPIO_SPEED_50MHz; break;
        default: return -CLINK_EINVAL;
    }

    RCM_EnableAPB2PeriphClock(__CLOCK_PORT(mode->pin));
    GPIO_Config(port, &config);

    chal_pin_set_mode_user_callback(port, pin, mode);

    return err;
}

static clink_err_t pin_set_value(clink_pin_value_t value)
{
    CLINK_ASSERT(value != CLINK_NULL);

    GPIO_T  *port = CLINK_NULL;
    uint16_t pin  = 0;

    port = __HAL_PORT(value->pin);
    pin  = __HAL_PIN(value->pin);

    GPIO_WriteBitValue(port, pin, (uint8_t)value->value);
    return CLINK_EOK;
}

static clink_err_t pin_read_value(clink_pin_value_t value)
{
    CLINK_ASSERT(value != CLINK_NULL);

    GPIO_T  *port = CLINK_NULL;
    uint16_t pin  = 0;

    port = __HAL_PORT(value->pin);
    pin  = __HAL_PIN(value->pin);

    value->value = GPIO_ReadInputBit(port, pin);

    return CLINK_EOK;
}

#if defined(CLINK_USING_DEVICES_PIN_IRQ) && CLINK_USING_DEVICES_PIN_IRQ > 0
static clink_err_t pin_set_irq(clink_pin_irq_hdr_t irq_hdr)
{
    CLINK_ASSERT(irq_hdr != CLINK_NULL);

    uint8_t irqindex = __PIN(irq_hdr->pin);
    if (irqindex >= (sizeof(_pin_irq_hdr_tab) / sizeof(_pin_irq_hdr_tab[0])))
    {
        return -CLINK_EINVAL;
    }

    _pin_irq_hdr_tab[irqindex].hdr  = irq_hdr->hdr;
    _pin_irq_hdr_tab[irqindex].args = irq_hdr->args;

    return CLINK_EOK;
}

static clink_err_t pin_enable_irq(clink_pin_irq_t irq)
{
    CLINK_ASSERT(irq != CLINK_NULL);

    GPIO_Config_T gpio_config;
    EINT_Config_T eint_config;
    GPIO_T       *port  = CLINK_NULL;
    uint16_t      pin   = 0;
    uint8_t       pinno = 0;
    IRQn_Type     irqn  = 0;

    port  = __HAL_PORT(irq->pin);
    pin   = __HAL_PIN(irq->pin);
    pinno = __PIN(irq->pin);

    gpio_config.pin = pin;
    switch (irq->mode)
    {
        case CLINK_PIN_IRQ_MODE_RISING: {
            gpio_config.mode    = GPIO_MODE_IN_PD;
            eint_config.trigger = EINT_TRIGGER_RISING;
            break;
        }
        case CLINK_PIN_IRQ_MODE_FALLING: {
            gpio_config.mode    = GPIO_MODE_IN_PU;
            eint_config.trigger = EINT_TRIGGER_FALLING;
            break;
        }
        case CLINK_PIN_IRQ_MODE_RISING_FALLING: {
            gpio_config.mode    = GPIO_MODE_IN_FLOATING;
            eint_config.trigger = EINT_TRIGGER_RISING_FALLING;
            break;
        }
        default: return -CLINK_EINVAL;
    }
    switch (irq->speed)
    {
        case CLINK_PIN_SPEED_LOW: gpio_config.speed = GPIO_SPEED_10MHz; break;
        case CLINK_PIN_SPEED_MEDIUM: gpio_config.speed = GPIO_SPEED_2MHz; break;
        case CLINK_PIN_SPEED_HIGH:
        case CLINK_PIN_SPEED_VERY_HIGH: gpio_config.speed = GPIO_SPEED_50MHz; break;
        default: return -CLINK_EINVAL;
    }

    if (pinno <= 4)
        irqn = (IRQn_Type)(pinno + (uint8_t)EINT0_IRQn);
    else if (pinno >= 5 && pinno <= 9)
        irqn = EINT9_5_IRQn;
    else
        irqn = EINT15_10_IRQn;

    GPIO_Config(port, &gpio_config);

    RCM_EnableAPB2PeriphClock(RCM_APB2_PERIPH_AFIO);
    GPIO_ConfigEINTLine((GPIO_PORT_SOURCE_T)(__PORT(irq->pin)), (GPIO_PIN_SOURCE_T)(pinno));

    eint_config.line    = pin;
    eint_config.mode    = EINT_MODE_INTERRUPT;
    eint_config.lineCmd = ENABLE;
    EINT_Config(&eint_config);

    NVIC_EnableIRQRequest(irqn, 5, 0);

    chal_pin_enable_irq_user_callback(port, pin, irq);

    return CLINK_EOK;
}

static clink_err_t pin_disable_irq(clink_pin_irq_t irq)
{
    CLINK_ASSERT(irq != CLINK_NULL);

    GPIO_T   *port  = CLINK_NULL;
    uint16_t  pin   = 0;
    uint8_t   pinno = 0;
    IRQn_Type irqn  = 0;

    port  = __HAL_PORT(irq->pin);
    pin   = __HAL_PIN(irq->pin);
    pinno = __PIN(irq->pin);

    if (pinno <= 4)
        irqn = (IRQn_Type)(pinno + (uint8_t)EINT0_IRQn);
    else if (pinno >= 5 && pinno <= 9)
        irqn = EINT9_5_IRQn;
    else
        irqn = EINT15_10_IRQn;

    NVIC_DisableIRQRequest(irqn);

    chal_pin_disable_irq_user_callback(port, pin, irq);

    return CLINK_EOK;
}
#endif  // CLINK_USING_DEVICES_PIN_IRQ

static clink_err_t pin_toggle(clink_pin_value_t value)
{
    CLINK_ASSERT(value != CLINK_NULL);

    GPIO_T  *port = CLINK_NULL;
    uint16_t pin  = 0;

    port = __HAL_PORT(value->pin);
    pin  = __HAL_PIN(value->pin);

    port->ODATA ^= pin;

    return CLINK_EOK;
}

static clink_err_t pin_control(clink_device_t dev, int cmd, void *args)
{
    CLINK_UNUSED(dev);

    clink_err_t err = CLINK_EOK;

    switch (cmd)
    {
        case CLINK_PIN_CTRL_SET_MODE: {
            err = pin_set_mode((clink_pin_mode_t)args);
            break;
        }
        case CLINK_PIN_CTRL_WRITE_VALUE: {
            err = pin_set_value((clink_pin_value_t)args);
            break;
        }
        case CLINK_PIN_CTRL_READ_VALUE: {
            err = pin_read_value((clink_pin_value_t)args);
            break;
        }
        case CLINK_PIN_CTRL_TOGGLE: {
            err = pin_toggle((clink_pin_value_t)args);
            break;
        }
#if defined(CLINK_USING_DEVICES_PIN_IRQ) && CLINK_USING_DEVICES_PIN_IRQ > 0
        case CLINK_PIN_CTRL_SET_IRQ: {
            err = pin_set_irq((clink_pin_irq_hdr_t)args);
            break;
        }
        case CLINK_PIN_CTRL_ENABLE_IRQ: {
            err = pin_enable_irq((clink_pin_irq_t)args);
            break;
        }
        case CLINK_PIN_CTRL_DISABLE_IRQ: {
            err = pin_disable_irq((clink_pin_irq_t)args);
            break;
        }
#endif  // CLINK_USING_DEVICES_PIN_IRQ
        default: err = -CLINK_EINVAL; break;
    }

    return err;
}

static clink_err_t pin_open(clink_device_t dev, int oflag)
{
    CLINK_UNUSED(dev);
    CLINK_UNUSED(oflag);

    return CLINK_EOK;
}

static clink_err_t pin_close(clink_device_t dev)
{
    CLINK_UNUSED(dev);

    return CLINK_EOK;
}

static const struct clink_device_ops _pin_ops = {
    CLINK_NULL,   // init
    pin_open,     // open
    pin_close,    // close
    CLINK_NULL,   // read
    CLINK_NULL,   // write
    pin_control,  // control
};

void chal_pin_register()
{
    clink_pin_register(&_pin_ops, CLINK_NULL);
}

#if defined(CLINK_USING_DEVICES_PIN_IRQ) && CLINK_USING_DEVICES_PIN_IRQ > 0
static void _pin_irq_handler(uint8_t line)
{
    if (EINT_ReadIntFlag((EINT_LINE_T)(1U << line)) != RESET)
    {
        EINT_ClearIntFlag(1U << line);
        if (_pin_irq_hdr_tab[line].hdr)
        {
            _pin_irq_hdr_tab[line].hdr(_pin_irq_hdr_tab[line].args);
        }
    }
}

void EINT0_IRQHandler(void)
{
    clink_base_t level;
    level = clink_lockirq();
    _pin_irq_handler(0);
    clink_unlockirq(level);
}

void EINT1_IRQHandler(void)
{
    clink_base_t level;
    level = clink_lockirq();
    _pin_irq_handler(1);
    clink_unlockirq(level);
}

void EINT2_IRQHandler(void)
{
    clink_base_t level;
    level = clink_lockirq();
    _pin_irq_handler(2);
    clink_unlockirq(level);
}

void EINT3_IRQHandler(void)
{
    clink_base_t level;
    level = clink_lockirq();
    _pin_irq_handler(3);
    clink_unlockirq(level);
}

void EINT4_IRQHandler(void)
{
    clink_base_t level;
    level = clink_lockirq();
    _pin_irq_handler(4);
    clink_unlockirq(level);
}

void EINT9_5_IRQHandler(void)
{
    clink_base_t level;
    level = clink_lockirq();
    _pin_irq_handler(5);
    _pin_irq_handler(6);
    _pin_irq_handler(7);
    _pin_irq_handler(8);
    _pin_irq_handler(9);
    clink_unlockirq(level);
}

void EINT15_10_IRQHandler(void)
{
    clink_base_t level;
    level = clink_lockirq();
    _pin_irq_handler(10);
    _pin_irq_handler(11);
    _pin_irq_handler(12);
    _pin_irq_handler(13);
    _pin_irq_handler(14);
    _pin_irq_handler(15);
    clink_unlockirq(level);
}
#endif  // CLINK_USING_DEVICES_PIN_IRQ
#endif  // CLINK_USING_DEVICES_PIN
