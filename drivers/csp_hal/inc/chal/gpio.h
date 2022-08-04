/**
 * @file gpio.h
 * @author xqyjlj (xqyjlj@126.com)
 * @brief
 * @version 0.1
 * @date 2022-07-27
 *
 * @copyright Copyright (c) 2022-2022, xqyjlj
 *
 * @SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-07-27     xqyjlj      the first version
 *
 */

#ifndef __CHAL_GPIO_H__
#define __CHAL_GPIO_H__

#include <chal/hal.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(GPIOA)
#define CHAL_GPIOA GPIOA
#define PA0        CHAL_GPIO_GET_PIN(A, 0)
#define PA1        CHAL_GPIO_GET_PIN(A, 1)
#define PA2        CHAL_GPIO_GET_PIN(A, 2)
#define PA3        CHAL_GPIO_GET_PIN(A, 3)
#define PA4        CHAL_GPIO_GET_PIN(A, 4)
#define PA5        CHAL_GPIO_GET_PIN(A, 5)
#define PA6        CHAL_GPIO_GET_PIN(A, 6)
#define PA7        CHAL_GPIO_GET_PIN(A, 7)
#define PA8        CHAL_GPIO_GET_PIN(A, 8)
#define PA9        CHAL_GPIO_GET_PIN(A, 9)
#define PA10       CHAL_GPIO_GET_PIN(A, 10)
#define PA11       CHAL_GPIO_GET_PIN(A, 11)
#define PA12       CHAL_GPIO_GET_PIN(A, 12)
#define PA13       CHAL_GPIO_GET_PIN(A, 13)
#define PA14       CHAL_GPIO_GET_PIN(A, 14)
#define PA15       CHAL_GPIO_GET_PIN(A, 15)
#endif

#if defined(GPIOB)
#define CHAL_GPIOB GPIOB
#define PB0        CHAL_GPIO_GET_PIN(B, 0)
#define PB1        CHAL_GPIO_GET_PIN(B, 1)
#define PB2        CHAL_GPIO_GET_PIN(B, 2)
#define PB3        CHAL_GPIO_GET_PIN(B, 3)
#define PB4        CHAL_GPIO_GET_PIN(B, 4)
#define PB5        CHAL_GPIO_GET_PIN(B, 5)
#define PB6        CHAL_GPIO_GET_PIN(B, 6)
#define PB7        CHAL_GPIO_GET_PIN(B, 7)
#define PB8        CHAL_GPIO_GET_PIN(B, 8)
#define PB9        CHAL_GPIO_GET_PIN(B, 9)
#define PB10       CHAL_GPIO_GET_PIN(B, 10)
#define PB11       CHAL_GPIO_GET_PIN(B, 11)
#define PB12       CHAL_GPIO_GET_PIN(B, 12)
#define PB13       CHAL_GPIO_GET_PIN(B, 13)
#define PB14       CHAL_GPIO_GET_PIN(B, 14)
#define PB15       CHAL_GPIO_GET_PIN(B, 15)
#endif

#if defined(GPIOC)
#define CHAL_GPIOC GPIOC
#define PC0        CHAL_GPIO_GET_PIN(C, 0)
#define PC1        CHAL_GPIO_GET_PIN(C, 1)
#define PC2        CHAL_GPIO_GET_PIN(C, 2)
#define PC3        CHAL_GPIO_GET_PIN(C, 3)
#define PC4        CHAL_GPIO_GET_PIN(C, 4)
#define PC5        CHAL_GPIO_GET_PIN(C, 5)
#define PC6        CHAL_GPIO_GET_PIN(C, 6)
#define PC7        CHAL_GPIO_GET_PIN(C, 7)
#define PC8        CHAL_GPIO_GET_PIN(C, 8)
#define PC9        CHAL_GPIO_GET_PIN(C, 9)
#define PC10       CHAL_GPIO_GET_PIN(C, 10)
#define PC11       CHAL_GPIO_GET_PIN(C, 11)
#define PC12       CHAL_GPIO_GET_PIN(C, 12)
#define PC13       CHAL_GPIO_GET_PIN(C, 13)
#define PC14       CHAL_GPIO_GET_PIN(C, 14)
#define PC15       CHAL_GPIO_GET_PIN(C, 15)
#endif

#if defined(GPIOD)
#define CHAL_GPIOD GPIOD
#define PD0        CHAL_GPIO_GET_PIN(D, 0)
#define PD1        CHAL_GPIO_GET_PIN(D, 1)
#define PD2        CHAL_GPIO_GET_PIN(D, 2)
#define PD3        CHAL_GPIO_GET_PIN(D, 3)
#define PD4        CHAL_GPIO_GET_PIN(D, 4)
#define PD5        CHAL_GPIO_GET_PIN(D, 5)
#define PD6        CHAL_GPIO_GET_PIN(D, 6)
#define PD7        CHAL_GPIO_GET_PIN(D, 7)
#define PD8        CHAL_GPIO_GET_PIN(D, 8)
#define PD9        CHAL_GPIO_GET_PIN(D, 9)
#define PD10       CHAL_GPIO_GET_PIN(D, 10)
#define PD11       CHAL_GPIO_GET_PIN(D, 11)
#define PD12       CHAL_GPIO_GET_PIN(D, 12)
#define PD13       CHAL_GPIO_GET_PIN(D, 13)
#define PD14       CHAL_GPIO_GET_PIN(D, 14)
#define PD15       CHAL_GPIO_GET_PIN(D, 15)
#endif

#if defined(GPIOE)
#define CHAL_GPIOE GPIOE
#define PE0        CHAL_GPIO_GET_PIN(E, 0)
#define PE1        CHAL_GPIO_GET_PIN(E, 1)
#define PE2        CHAL_GPIO_GET_PIN(E, 2)
#define PE3        CHAL_GPIO_GET_PIN(E, 3)
#define PE4        CHAL_GPIO_GET_PIN(E, 4)
#define PE5        CHAL_GPIO_GET_PIN(E, 5)
#define PE6        CHAL_GPIO_GET_PIN(E, 6)
#define PE7        CHAL_GPIO_GET_PIN(E, 7)
#define PE8        CHAL_GPIO_GET_PIN(E, 8)
#define PE9        CHAL_GPIO_GET_PIN(E, 9)
#define PE10       CHAL_GPIO_GET_PIN(E, 10)
#define PE11       CHAL_GPIO_GET_PIN(E, 11)
#define PE12       CHAL_GPIO_GET_PIN(E, 12)
#define PE13       CHAL_GPIO_GET_PIN(E, 13)
#define PE14       CHAL_GPIO_GET_PIN(E, 14)
#define PE15       CHAL_GPIO_GET_PIN(E, 15)
#endif

#if defined(GPIOF)
#define CHAL_GPIOF GPIOF
#define PF0        CHAL_GPIO_GET_PIN(F, 0)
#define PF1        CHAL_GPIO_GET_PIN(F, 1)
#define PF2        CHAL_GPIO_GET_PIN(F, 2)
#define PF3        CHAL_GPIO_GET_PIN(F, 3)
#define PF4        CHAL_GPIO_GET_PIN(F, 4)
#define PF5        CHAL_GPIO_GET_PIN(F, 5)
#define PF6        CHAL_GPIO_GET_PIN(F, 6)
#define PF7        CHAL_GPIO_GET_PIN(F, 7)
#define PF8        CHAL_GPIO_GET_PIN(F, 8)
#define PF9        CHAL_GPIO_GET_PIN(F, 9)
#define PF10       CHAL_GPIO_GET_PIN(F, 10)
#define PF11       CHAL_GPIO_GET_PIN(F, 11)
#define PF12       CHAL_GPIO_GET_PIN(F, 12)
#define PF13       CHAL_GPIO_GET_PIN(F, 13)
#define PF14       CHAL_GPIO_GET_PIN(F, 14)
#define PF15       CHAL_GPIO_GET_PIN(F, 15)
#endif

#if defined(GPIOG)
#define CHAL_GPIOG GPIOG
#define PG0        CHAL_GPIO_GET_PIN(G, 0)
#define PG1        CHAL_GPIO_GET_PIN(G, 1)
#define PG2        CHAL_GPIO_GET_PIN(G, 2)
#define PG3        CHAL_GPIO_GET_PIN(G, 3)
#define PG4        CHAL_GPIO_GET_PIN(G, 4)
#define PG5        CHAL_GPIO_GET_PIN(G, 5)
#define PG6        CHAL_GPIO_GET_PIN(G, 6)
#define PG7        CHAL_GPIO_GET_PIN(G, 7)
#define PG8        CHAL_GPIO_GET_PIN(G, 8)
#define PG9        CHAL_GPIO_GET_PIN(G, 9)
#define PG10       CHAL_GPIO_GET_PIN(G, 10)
#define PG11       CHAL_GPIO_GET_PIN(G, 11)
#define PG12       CHAL_GPIO_GET_PIN(G, 12)
#define PG13       CHAL_GPIO_GET_PIN(G, 13)
#define PG14       CHAL_GPIO_GET_PIN(G, 14)
#define PG15       CHAL_GPIO_GET_PIN(G, 15)
#endif

#define CHAL_GPIO_GET_PIN(PORTx, PIN) CHAL_GPIO##PORTx, CHAL_GPIO_PIN_##PIN, CHAL_GPIO_EINT##PIN##_IRQn

#define CHAL_GPIO_PIN_0               (0x00000101U)
#define CHAL_GPIO_PIN_1               (0x00000202U)
#define CHAL_GPIO_PIN_2               (0x00000404U)
#define CHAL_GPIO_PIN_3               (0x00000808U)
#define CHAL_GPIO_PIN_4               (0x00001010U)
#define CHAL_GPIO_PIN_5               (0x00002020U)
#define CHAL_GPIO_PIN_6               (0x00004040U)
#define CHAL_GPIO_PIN_7               (0x00008080U)
#define CHAL_GPIO_PIN_8               (0x04010001U)
#define CHAL_GPIO_PIN_9               (0x04020002U)
#define CHAL_GPIO_PIN_10              (0x04040004U)
#define CHAL_GPIO_PIN_11              (0x04080008U)
#define CHAL_GPIO_PIN_12              (0x04100010U)
#define CHAL_GPIO_PIN_13              (0x04200020U)
#define CHAL_GPIO_PIN_14              (0x04400040U)
#define CHAL_GPIO_PIN_15              (0x04800080U)
#define CHAL_GPIO_PIN_ALL             (0x04FFFFFFU)

#define CHAL_GPIO_PIN_RESET           (0U)
#define CHAL_GPIO_PIN_SET             (1U)

#define CHAL_GPIO_MODE_ANALOG         (0x00000000U)  // analog mode
#define CHAL_GPIO_MODE_FLOATING       (0x00000004U)  // floating mode
#define CHAL_GPIO_MODE_INPUT          (0x00000008U)  // input mode
#define CHAL_GPIO_MODE_OUTPUT         (0x00000001U)  // output mode
#define CHAL_GPIO_MODE_ALTERNATE      (0x00000009U)  // alternate mode

#define CHAL_GPIO_OUTPUT_PP           (0x00000000U)  // push-pull output mode
#define CHAL_GPIO_OUTPUT_OD           (0x00000004U)  // open-drain output mode

#define CHAL_GPIO_PULL_DOWN           (0x00000000U)  // pull down
#define CHAL_GPIO_PULL_UP             (0x00000001U)  // pull up

#define CHAL_GPIO_SPEED_10MHz         (0x1U)
#define CHAL_GPIO_SPEED_20MHz         (0x2U)
#define CHAL_GPIO_SPEED_50MHz         (0x3U)

#define CHAL_GPIO_EINT0_IRQn          EINT0_IRQn
#define CHAL_GPIO_EINT1_IRQn          EINT1_IRQn
#define CHAL_GPIO_EINT2_IRQn          EINT2_IRQn
#define CHAL_GPIO_EINT3_IRQn          EINT3_IRQn
#define CHAL_GPIO_EINT4_IRQn          EINT4_IRQn
#define CHAL_GPIO_EINT5_IRQn          EINT9_5_IRQn
#define CHAL_GPIO_EINT6_IRQn          EINT9_5_IRQn
#define CHAL_GPIO_EINT7_IRQn          EINT9_5_IRQn
#define CHAL_GPIO_EINT8_IRQn          EINT9_5_IRQn
#define CHAL_GPIO_EINT9_IRQn          EINT9_5_IRQn
#define CHAL_GPIO_EINT10_IRQn         EINT15_10_IRQn
#define CHAL_GPIO_EINT11_IRQn         EINT15_10_IRQn
#define CHAL_GPIO_EINT12_IRQn         EINT15_10_IRQn
#define CHAL_GPIO_EINT13_IRQn         EINT15_10_IRQn
#define CHAL_GPIO_EINT14_IRQn         EINT15_10_IRQn
#define CHAL_GPIO_EINT15_IRQn         EINT15_10_IRQn

typedef struct
{
    rt_uint32_t pin;
    rt_uint32_t mode;
    rt_uint32_t speed;
    rt_uint32_t output_type;
    rt_uint32_t pull;
} chal_gpio_init_t;

rt_inline void chal_gpio_set_mode(GPIO_T *port, rt_uint32_t pin, rt_uint32_t eint, rt_uint32_t mode)
{
    register rt_uint32_t *reg = (rt_uint32_t *)((rt_uint32_t)((rt_uint32_t)(&port->CFGLOW) + (pin >> 24)));
    chal_modify_reg(*reg, ((0x0FU) << (chal_position_val(pin) * 4U)), (mode << (chal_position_val(pin) * 4U)));
}

rt_inline rt_uint32_t chal_gpio_get_mode(GPIO_T *port, rt_uint32_t pin, rt_uint32_t eint)
{
    register rt_uint32_t *reg = (rt_uint32_t *)((rt_uint32_t)((rt_uint32_t)(&port->CFGLOW) + (pin >> 24)));
    return (chal_read_bit(*reg, ((0x0FU) << (chal_position_val(pin) * 4U))) >> (chal_position_val(pin) * 4U));
}

rt_inline void chal_gpio_set_speed(GPIO_T *port, rt_uint32_t pin, rt_uint32_t eint, rt_uint32_t speed)
{
    register rt_uint32_t *reg = (rt_uint32_t *)((rt_uint32_t)((rt_uint32_t)(&port->CFGLOW) + (pin >> 24)));
    chal_modify_reg(*reg, ((0x03U) << (chal_position_val(pin) * 4U)), (speed << (chal_position_val(pin) * 4U)));
}

rt_inline rt_uint32_t chal_gpio_get_speed(GPIO_T *port, rt_uint32_t pin, rt_uint32_t eint)
{
    register rt_uint32_t *reg = (rt_uint32_t *)((rt_uint32_t)((rt_uint32_t)(&port->CFGLOW) + (pin >> 24)));
    return (chal_read_bit(*reg, ((0x03U) << (chal_position_val(pin) * 4U))) >> (chal_position_val(pin) * 4U));
}

rt_inline void chal_gpio_set_output_type(GPIO_T *port, rt_uint32_t pin, rt_uint32_t eint, rt_uint32_t output_type)
{
    register rt_uint32_t *reg = (rt_uint32_t *)((rt_uint32_t)((rt_uint32_t)(&port->CFGLOW) + (pin >> 24)));
    chal_modify_reg(*reg, ((0x04U) << (chal_position_val(pin) * 4U)), (output_type << (chal_position_val(pin) * 4U)));
}

rt_inline rt_uint32_t chal_gpio_get_output_type(GPIO_T *port, rt_uint32_t pin, rt_uint32_t eint)
{
    register rt_uint32_t *reg = (rt_uint32_t *)((rt_uint32_t)((rt_uint32_t)(&port->CFGLOW) + (pin >> 24)));
    return (chal_read_bit(*reg, ((0x04U) << (chal_position_val(pin) * 4U))) >> (chal_position_val(pin) * 4U));
}

rt_inline void chal_gpio_set_pull(GPIO_T *port, rt_uint32_t pin, rt_uint32_t eint, rt_uint32_t pull)
{
    chal_modify_reg(port->ODATA, (pin >> (8U)), pull << (chal_position_val(pin >> (8U))));
}

rt_inline rt_uint32_t chal_gpio_get_pull(GPIO_T *port, rt_uint32_t pin, rt_uint32_t eint)
{
    return (chal_read_bit(port->ODATA, ((0x01U) << (chal_position_val(pin >> (8U))))) >> (chal_position_val(pin >> (8U))));
}

#ifdef __cplusplus
}
#endif

#endif
