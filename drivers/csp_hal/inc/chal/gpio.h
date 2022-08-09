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
 * 2022-07-27     xqyjlj       the first version
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

#define CHAL_GPIO_GET_PIN(PORTx, PIN) CHAL_GPIO##PORTx, CHAL_GPIO_PIN_##PIN

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

#define CHAL_GPIO_MODE_ANALOG         (0x00000000U)  // 模拟模式
#define CHAL_GPIO_MODE_FLOATING       (0x00000004U)  // 浮空模式
#define CHAL_GPIO_MODE_INPUT          (0x00000008U)  // 输入模式
#define CHAL_GPIO_MODE_OUTPUT         (0x00000001U)  // 输出模式
#define CHAL_GPIO_MODE_ALTERNATE      (0x00000009U)  // 复用模式

#define CHAL_GPIO_OUTPUT_PP           (0x00000000U)  // 推挽输出
#define CHAL_GPIO_OUTPUT_OD           (0x00000004U)  // 开漏输出

#define CHAL_GPIO_PULL_DOWN           (0x00000000U)  // 下拉
#define CHAL_GPIO_PULL_UP             (0x00000001U)  // 上拉

#define CHAL_GPIO_SPEED_10MHz         (0x1U)  // 10MHz
#define CHAL_GPIO_SPEED_20MHz         (0x2U)  // 20MHz
#define CHAL_GPIO_SPEED_50MHz         (0x3U)  // 50MHz

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

#define CHAL_GPIO_CLK_AFIO            RCM_APB2_PERIPH_AFIO
#define CHAL_GPIO_CLK_GPIOA           RCM_APB2_PERIPH_GPIOA
#define CHAL_GPIO_CLK_GPIOB           RCM_APB2_PERIPH_GPIOB
#define CHAL_GPIO_CLK_GPIOC           RCM_APB2_PERIPH_GPIOC
#define CHAL_GPIO_CLK_GPIOD           RCM_APB2_PERIPH_GPIOD
#define CHAL_GPIO_CLK_GPIOE           RCM_APB2_PERIPH_GPIOE
#define CHAL_GPIO_CLK_GPIOF           RCM_APB2_PERIPH_GPIOF
#define CHAL_GPIO_CLK_GPIOG           RCM_APB2_PERIPH_GPIOG

typedef struct
{
    rt_uint32_t pin;
    rt_uint32_t mode;
    rt_uint32_t speed;
    rt_uint32_t output;
    rt_uint32_t pull;
} chal_gpio_init_t;

/**
 * @brief   GPIO时钟使能
 *
 * @param   periphs 只能是以下值之一：
 *          @arg @ref CHAL_GPIO_CLK_AFIO
 *          @arg @ref CHAL_GPIO_CLK_GPIOA
 *          @arg @ref CHAL_GPIO_CLK_GPIOB
 *          @arg @ref CHAL_GPIO_CLK_GPIOC
 *          @arg @ref CHAL_GPIO_CLK_GPIOD
 *          @arg @ref CHAL_GPIO_CLK_GPIOE (*)
 *          @arg @ref CHAL_GPIO_CLK_GPIOF (*)
 *          @arg @ref CHAL_GPIO_CLK_GPIOG (*)
 *
 *          (*) 不是所有设备都有此定义
 * @return  void
 */
rt_inline void chal_gpio_enable_clk(rt_uint32_t periphs)
{
    __IO rt_uint32_t reg;
    CHAL_WRITE_BIT(RCM->APB2CLKEN, periphs);
    reg = CHAL_READ_BIT(RCM->APB2CLKEN, periphs);  // 延时一个时钟
    (void)reg;
}

/**
 * @brief   检查GPIO时钟是否使能
 *
 * @param   periphs 只能是以下值之一：
 *          @arg @ref CHAL_GPIO_CLK_AFIO
 *          @arg @ref CHAL_GPIO_CLK_GPIOA
 *          @arg @ref CHAL_GPIO_CLK_GPIOB
 *          @arg @ref CHAL_GPIO_CLK_GPIOC
 *          @arg @ref CHAL_GPIO_CLK_GPIOD
 *          @arg @ref CHAL_GPIO_CLK_GPIOE (*)
 *          @arg @ref CHAL_GPIO_CLK_GPIOF (*)
 *          @arg @ref CHAL_GPIO_CLK_GPIOG (*)
 *
 *          (*) 不是所有设备都有此定义
 * @return  rt_bool_t
 *          @arg @ref RT_TRUE
 *          @arg @ref RT_FALSE
 */
rt_inline rt_bool_t chal_gpio_is_clk_enabled(rt_uint32_t periphs)
{
    return (CHAL_READ_BIT(RCM->APB2CLKEN, periphs) == periphs);
}

/**
 * @brief   GPIO时钟失能
 *
 * @param   periphs 只能是以下值之一：
 *          @arg @ref CHAL_GPIO_CLK_AFIO
 *          @arg @ref CHAL_GPIO_CLK_GPIOA
 *          @arg @ref CHAL_GPIO_CLK_GPIOB
 *          @arg @ref CHAL_GPIO_CLK_GPIOC
 *          @arg @ref CHAL_GPIO_CLK_GPIOD
 *          @arg @ref CHAL_GPIO_CLK_GPIOE (*)
 *          @arg @ref CHAL_GPIO_CLK_GPIOF (*)
 *          @arg @ref CHAL_GPIO_CLK_GPIOG (*)
 *
 *          (*) 不是所有设备都有此定义
 * @return  void
 */
rt_inline void chal_gpio_disable_clk(rt_uint32_t periphs)
{
    CHAL_CLEAR_BIT(RCM->APB2CLKEN, periphs);
}

/**
 * @brief   GPIO时钟强制置位
 *
 * @param   periphs 只能是以下值之一：
 *          @arg @ref CHAL_GPIO_CLK_AFIO
 *          @arg @ref CHAL_GPIO_CLK_GPIOA
 *          @arg @ref CHAL_GPIO_CLK_GPIOB
 *          @arg @ref CHAL_GPIO_CLK_GPIOC
 *          @arg @ref CHAL_GPIO_CLK_GPIOD
 *          @arg @ref CHAL_GPIO_CLK_GPIOE (*)
 *          @arg @ref CHAL_GPIO_CLK_GPIOF (*)
 *          @arg @ref CHAL_GPIO_CLK_GPIOG (*)
 *
 *          (*) 不是所有设备都有此定义
 * @return  void
 */
rt_inline void chal_gpio_force_set_clk(rt_uint32_t periphs)
{
    CHAL_WRITE_BIT(RCM->APB2CLKEN, periphs);
}

/**
 * @brief   GPIO时钟强制复位
 *
 * @param   periphs 只能是以下值之一：
 *          @arg @ref CHAL_GPIO_CLK_AFIO
 *          @arg @ref CHAL_GPIO_CLK_GPIOA
 *          @arg @ref CHAL_GPIO_CLK_GPIOB
 *          @arg @ref CHAL_GPIO_CLK_GPIOC
 *          @arg @ref CHAL_GPIO_CLK_GPIOD
 *          @arg @ref CHAL_GPIO_CLK_GPIOE (*)
 *          @arg @ref CHAL_GPIO_CLK_GPIOF (*)
 *          @arg @ref CHAL_GPIO_CLK_GPIOG (*)
 *
 *          (*) 不是所有设备都有此定义
 * @return  void
 */
rt_inline void chal_gpio_force_reset_clk(rt_uint32_t periphs)
{
    CHAL_CLEAR_BIT(RCM->APB2CLKEN, periphs);
}

/**
 * @brief   GPIO设置引脚模式
 *
 * @param   port GPIO端口，只能是以下值之一：
 *          @arg @ref CHAL_GPIOA
 *          @arg @ref CHAL_GPIOB
 *          @arg @ref CHAL_GPIOC
 *          @arg @ref CHAL_GPIOD
 *          @arg @ref CHAL_GPIOE (*)
 *          @arg @ref CHAL_GPIOF (*)
 *          @arg @ref CHAL_GPIOG (*)
 *
 *          (*) 不是所有设备都有此定义
 * @param   pin GPIO引脚号，只能是以下值之一：
 *          @arg @ref CHAL_GPIO_PIN_0
 *          @arg @ref CHAL_GPIO_PIN_1
 *          @arg @ref CHAL_GPIO_PIN_2
 *          @arg @ref CHAL_GPIO_PIN_3
 *          @arg @ref CHAL_GPIO_PIN_4
 *          @arg @ref CHAL_GPIO_PIN_5
 *          @arg @ref CHAL_GPIO_PIN_6
 *          @arg @ref CHAL_GPIO_PIN_7
 *          @arg @ref CHAL_GPIO_PIN_8
 *          @arg @ref CHAL_GPIO_PIN_9
 *          @arg @ref CHAL_GPIO_PIN_10
 *          @arg @ref CHAL_GPIO_PIN_11
 *          @arg @ref CHAL_GPIO_PIN_12
 *          @arg @ref CHAL_GPIO_PIN_13
 *          @arg @ref CHAL_GPIO_PIN_14
 *          @arg @ref CHAL_GPIO_PIN_15
 * @param   mode GPIO引脚模式，只能是以下值之一：
 *          @arg @ref CHAL_GPIO_MODE_ANALOG
 *          @arg @ref CHAL_GPIO_MODE_FLOATING
 *          @arg @ref CHAL_GPIO_MODE_INPUT
 *          @arg @ref CHAL_GPIO_MODE_OUTPUT
 *          @arg @ref CHAL_GPIO_MODE_ALTERNATE
 * @return  void
 */
rt_inline void chal_gpio_set_mode(GPIO_T *port, rt_uint32_t pin, rt_uint32_t mode)
{
    register rt_uint32_t *reg = (rt_uint32_t *)((rt_uint32_t)((rt_uint32_t)(&port->CFGLOW) + (pin >> 24)));
    CHAL_MODIFY_REG(*reg, ((0x0FU) << (CHAL_POSITION_VAL(pin) * 4U)), (mode << (CHAL_POSITION_VAL(pin) * 4U)));
}

/**
 * @brief   GPIO获取引脚模式
 *
 * @param   port GPIO端口，只能是以下值之一：
 *          @arg @ref CHAL_GPIOA
 *          @arg @ref CHAL_GPIOB
 *          @arg @ref CHAL_GPIOC
 *          @arg @ref CHAL_GPIOD
 *          @arg @ref CHAL_GPIOE (*)
 *          @arg @ref CHAL_GPIOF (*)
 *          @arg @ref CHAL_GPIOG (*)
 *
 *          (*) 不是所有设备都有此定义
 * @param   pin GPIO引脚号，只能是以下值之一：
 *          @arg @ref CHAL_GPIO_PIN_0
 *          @arg @ref CHAL_GPIO_PIN_1
 *          @arg @ref CHAL_GPIO_PIN_2
 *          @arg @ref CHAL_GPIO_PIN_3
 *          @arg @ref CHAL_GPIO_PIN_4
 *          @arg @ref CHAL_GPIO_PIN_5
 *          @arg @ref CHAL_GPIO_PIN_6
 *          @arg @ref CHAL_GPIO_PIN_7
 *          @arg @ref CHAL_GPIO_PIN_8
 *          @arg @ref CHAL_GPIO_PIN_9
 *          @arg @ref CHAL_GPIO_PIN_10
 *          @arg @ref CHAL_GPIO_PIN_11
 *          @arg @ref CHAL_GPIO_PIN_12
 *          @arg @ref CHAL_GPIO_PIN_13
 *          @arg @ref CHAL_GPIO_PIN_14
 *          @arg @ref CHAL_GPIO_PIN_15
 * @return  GPIO引脚模式，只能是以下值之一：
 *          @arg @ref CHAL_GPIO_MODE_ANALOG
 *          @arg @ref CHAL_GPIO_MODE_FLOATING
 *          @arg @ref CHAL_GPIO_MODE_INPUT
 *          @arg @ref CHAL_GPIO_MODE_OUTPUT
 *          @arg @ref CHAL_GPIO_MODE_ALTERNATE
 */
rt_inline rt_uint32_t chal_gpio_get_mode(GPIO_T *port, rt_uint32_t pin)
{
    register rt_uint32_t *reg = (rt_uint32_t *)((rt_uint32_t)((rt_uint32_t)(&port->CFGLOW) + (pin >> 24)));
    return (CHAL_READ_BIT(*reg, ((0x0FU) << (CHAL_POSITION_VAL(pin) * 4U))) >> (CHAL_POSITION_VAL(pin) * 4U));
}

/**
 * @brief   GPIO设置引脚速度
 *
 * @param   port GPIO端口，只能是以下值之一：
 *          @arg @ref CHAL_GPIOA
 *          @arg @ref CHAL_GPIOB
 *          @arg @ref CHAL_GPIOC
 *          @arg @ref CHAL_GPIOD
 *          @arg @ref CHAL_GPIOE (*)
 *          @arg @ref CHAL_GPIOF (*)
 *          @arg @ref CHAL_GPIOG (*)
 *
 *          (*) 不是所有设备都有此定义
 * @param   pin GPIO引脚号，只能是以下值之一：
 *          @arg @ref CHAL_GPIO_PIN_0
 *          @arg @ref CHAL_GPIO_PIN_1
 *          @arg @ref CHAL_GPIO_PIN_2
 *          @arg @ref CHAL_GPIO_PIN_3
 *          @arg @ref CHAL_GPIO_PIN_4
 *          @arg @ref CHAL_GPIO_PIN_5
 *          @arg @ref CHAL_GPIO_PIN_6
 *          @arg @ref CHAL_GPIO_PIN_7
 *          @arg @ref CHAL_GPIO_PIN_8
 *          @arg @ref CHAL_GPIO_PIN_9
 *          @arg @ref CHAL_GPIO_PIN_10
 *          @arg @ref CHAL_GPIO_PIN_11
 *          @arg @ref CHAL_GPIO_PIN_12
 *          @arg @ref CHAL_GPIO_PIN_13
 *          @arg @ref CHAL_GPIO_PIN_14
 *          @arg @ref CHAL_GPIO_PIN_15
 * @param   speed GPIO引脚速度，只能是以下值之一：
 *          @arg @ref CHAL_GPIO_SPEED_10MHz
 *          @arg @ref CHAL_GPIO_SPEED_20MHz
 *          @arg @ref CHAL_GPIO_SPEED_50MHz
 * @return  void
 */
rt_inline void chal_gpio_set_speed(GPIO_T *port, rt_uint32_t pin, rt_uint32_t speed)
{
    register rt_uint32_t *reg = (rt_uint32_t *)((rt_uint32_t)((rt_uint32_t)(&port->CFGLOW) + (pin >> 24)));
    CHAL_MODIFY_REG(*reg, ((0x03U) << (CHAL_POSITION_VAL(pin) * 4U)), (speed << (CHAL_POSITION_VAL(pin) * 4U)));
}

/**
 * @brief   GPIO获取引脚速度
 *
 * @param   port GPIO端口，只能是以下值之一：
 *          @arg @ref CHAL_GPIOA
 *          @arg @ref CHAL_GPIOB
 *          @arg @ref CHAL_GPIOC
 *          @arg @ref CHAL_GPIOD
 *          @arg @ref CHAL_GPIOE (*)
 *          @arg @ref CHAL_GPIOF (*)
 *          @arg @ref CHAL_GPIOG (*)
 *
 *          (*) 不是所有设备都有此定义
 * @param   pin GPIO引脚号，只能是以下值之一：
 *          @arg @ref CHAL_GPIO_PIN_0
 *          @arg @ref CHAL_GPIO_PIN_1
 *          @arg @ref CHAL_GPIO_PIN_2
 *          @arg @ref CHAL_GPIO_PIN_3
 *          @arg @ref CHAL_GPIO_PIN_4
 *          @arg @ref CHAL_GPIO_PIN_5
 *          @arg @ref CHAL_GPIO_PIN_6
 *          @arg @ref CHAL_GPIO_PIN_7
 *          @arg @ref CHAL_GPIO_PIN_8
 *          @arg @ref CHAL_GPIO_PIN_9
 *          @arg @ref CHAL_GPIO_PIN_10
 *          @arg @ref CHAL_GPIO_PIN_11
 *          @arg @ref CHAL_GPIO_PIN_12
 *          @arg @ref CHAL_GPIO_PIN_13
 *          @arg @ref CHAL_GPIO_PIN_14
 *          @arg @ref CHAL_GPIO_PIN_15
 * @return  GPIO引脚速度，只能是以下值之一：
 *          @arg @ref CHAL_GPIO_SPEED_10MHz
 *          @arg @ref CHAL_GPIO_SPEED_20MHz
 *          @arg @ref CHAL_GPIO_SPEED_50MHz
 */
rt_inline rt_uint32_t chal_gpio_get_speed(GPIO_T *port, rt_uint32_t pin)
{
    register rt_uint32_t *reg = (rt_uint32_t *)((rt_uint32_t)((rt_uint32_t)(&port->CFGLOW) + (pin >> 24)));
    return (CHAL_READ_BIT(*reg, ((0x03U) << (CHAL_POSITION_VAL(pin) * 4U))) >> (CHAL_POSITION_VAL(pin) * 4U));
}

/**
 * @brief   GPIO设置引脚输出模式
 *
 * @param   port GPIO端口，只能是以下值之一：
 *          @arg @ref CHAL_GPIOA
 *          @arg @ref CHAL_GPIOB
 *          @arg @ref CHAL_GPIOC
 *          @arg @ref CHAL_GPIOD
 *          @arg @ref CHAL_GPIOE (*)
 *          @arg @ref CHAL_GPIOF (*)
 *          @arg @ref CHAL_GPIOG (*)
 *
 *          (*) 不是所有设备都有此定义
 * @param   pin GPIO引脚号，只能是以下值之一：
 *          @arg @ref CHAL_GPIO_PIN_0
 *          @arg @ref CHAL_GPIO_PIN_1
 *          @arg @ref CHAL_GPIO_PIN_2
 *          @arg @ref CHAL_GPIO_PIN_3
 *          @arg @ref CHAL_GPIO_PIN_4
 *          @arg @ref CHAL_GPIO_PIN_5
 *          @arg @ref CHAL_GPIO_PIN_6
 *          @arg @ref CHAL_GPIO_PIN_7
 *          @arg @ref CHAL_GPIO_PIN_8
 *          @arg @ref CHAL_GPIO_PIN_9
 *          @arg @ref CHAL_GPIO_PIN_10
 *          @arg @ref CHAL_GPIO_PIN_11
 *          @arg @ref CHAL_GPIO_PIN_12
 *          @arg @ref CHAL_GPIO_PIN_13
 *          @arg @ref CHAL_GPIO_PIN_14
 *          @arg @ref CHAL_GPIO_PIN_15
 * @param   output GPIO引脚输出模式，只能是以下值之一：
 *          @arg @ref CHAL_GPIO_OUTPUT_PUSHPULL
 *          @arg @ref CHAL_GPIO_OUTPUT_OPENDRAIN
 * @return  void
 */
rt_inline void chal_gpio_set_output(GPIO_T *port, rt_uint32_t pin, rt_uint32_t output)
{
    register rt_uint32_t *reg = (rt_uint32_t *)((rt_uint32_t)((rt_uint32_t)(&port->CFGLOW) + (pin >> 24)));
    CHAL_MODIFY_REG(*reg, ((0x04U) << (CHAL_POSITION_VAL(pin) * 4U)), (output << (CHAL_POSITION_VAL(pin) * 4U)));
}

/**
 * @brief   GPIO获取引脚输出模式
 *
 * @param   port GPIO端口，只能是以下值之一：
 *          @arg @ref CHAL_GPIOA
 *          @arg @ref CHAL_GPIOB
 *          @arg @ref CHAL_GPIOC
 *          @arg @ref CHAL_GPIOD
 *          @arg @ref CHAL_GPIOE (*)
 *          @arg @ref CHAL_GPIOF (*)
 *          @arg @ref CHAL_GPIOG (*)
 *
 *          (*) 不是所有设备都有此定义
 * @param   pin GPIO引脚号，只能是以下值之一：
 *          @arg @ref CHAL_GPIO_PIN_0
 *          @arg @ref CHAL_GPIO_PIN_1
 *          @arg @ref CHAL_GPIO_PIN_2
 *          @arg @ref CHAL_GPIO_PIN_3
 *          @arg @ref CHAL_GPIO_PIN_4
 *          @arg @ref CHAL_GPIO_PIN_5
 *          @arg @ref CHAL_GPIO_PIN_6
 *          @arg @ref CHAL_GPIO_PIN_7
 *          @arg @ref CHAL_GPIO_PIN_8
 *          @arg @ref CHAL_GPIO_PIN_9
 *          @arg @ref CHAL_GPIO_PIN_10
 *          @arg @ref CHAL_GPIO_PIN_11
 *          @arg @ref CHAL_GPIO_PIN_12
 *          @arg @ref CHAL_GPIO_PIN_13
 *          @arg @ref CHAL_GPIO_PIN_14
 *          @arg @ref CHAL_GPIO_PIN_15
 * @return  GPIO引脚输出模式，只能是以下值之一：
 *          @arg @ref CHAL_GPIO_OUTPUT_PUSHPULL
 *          @arg @ref CHAL_GPIO_OUTPUT_OPENDRAIN
 */
rt_inline rt_uint32_t chal_gpio_get_output(GPIO_T *port, rt_uint32_t pin)
{
    register rt_uint32_t *reg = (rt_uint32_t *)((rt_uint32_t)((rt_uint32_t)(&port->CFGLOW) + (pin >> 24)));
    return (CHAL_READ_BIT(*reg, ((0x04U) << (CHAL_POSITION_VAL(pin) * 4U))) >> (CHAL_POSITION_VAL(pin) * 4U));
}

rt_inline void chal_gpio_set_pull(GPIO_T *port, rt_uint32_t pin, rt_uint32_t pull)
{
    CHAL_MODIFY_REG(port->ODATA, (pin >> (8U)), pull << (CHAL_POSITION_VAL(pin >> (8U))));
}

rt_inline rt_uint32_t chal_gpio_get_pull(GPIO_T *port, rt_uint32_t pin)
{
    return (CHAL_READ_BIT(port->ODATA, ((0x01U) << (CHAL_POSITION_VAL(pin >> (8U))))) >> (CHAL_POSITION_VAL(pin >> (8U))));
}

rt_inline void chal_gpio_lock_pin(GPIO_T *port, rt_uint32_t pin)
{
    __IO rt_uint32_t temp;
    CHAL_WRITE_REG(port->LOCK, (0x00010000U) | ((pin >> (8U)) & 0x0000FFFFU));
    CHAL_WRITE_REG(port->LOCK, ((pin >> (8U)) & 0x0000FFFFU));
    CHAL_WRITE_REG(port->LOCK, (0x00010000U) | ((pin >> (8U)) & 0x0000FFFFU));
    temp = CHAL_READ_REG(port->LOCK);
    (void)temp;
}

rt_inline rt_uint32_t chal_gpio_is_pin_locked(GPIO_T *port, rt_uint32_t pin)
{
    return (CHAL_READ_BIT(port->LOCK, ((pin >> (8U)) & 0x0000FFFFU)) == ((pin >> (8U)) & 0x0000FFFFU));
}

rt_inline rt_uint32_t chal_gpio_is_anypin_locked(GPIO_T *port)
{
    return (CHAL_READ_BIT(port->LOCK, (0x00010000U)) == ((0x00010000U)));
}

rt_inline rt_uint32_t chal_gpio_read_input_port(GPIO_T *port)
{
    return (CHAL_READ_REG(port->IDATA));
}

rt_inline rt_uint32_t chal_gpio_is_input_pin_set(GPIO_T *port, rt_uint32_t pin)
{
    return (CHAL_READ_BIT(port->IDATA, (pin >> (8U)) & 0x0000FFFFU) == ((pin >> (8U)) & 0x0000FFFFU));
}

rt_inline void chal_gpio_write_output_port(GPIO_T *port, rt_uint32_t pin)
{
    CHAL_WRITE_REG(port->ODATA, pin);
}

rt_inline rt_uint32_t chal_gpio_read_output_port(GPIO_T *port)
{
    return (rt_uint32_t)(CHAL_READ_REG(port->ODATA));
}

rt_inline rt_uint32_t chal_gpio_is_output_pin_set(GPIO_T *port, rt_uint32_t pin)
{
    return (CHAL_READ_BIT(port->ODATA, (pin >> (8U)) & 0x0000FFFFU) == ((pin >> (8U)) & 0x0000FFFFU));
}

rt_inline void chal_gpio_set_output_pin(GPIO_T *port, rt_uint32_t pin)
{
    CHAL_WRITE_REG(port->BSC, (pin >> (8U)) & 0x0000FFFFU);
}

rt_inline void chal_gpio_reset_output_pin(GPIO_T *port, rt_uint32_t pin)
{
    CHAL_WRITE_REG(port->BC, (pin >> (8U)) & 0x0000FFFFU);
}

rt_inline void chal_gpio_toggle_pin(GPIO_T *port, rt_uint32_t pin)
{
    rt_uint32_t odr     = CHAL_READ_REG(port->ODATA);
    rt_uint32_t pinmask = ((pin >> (8U)) & 0x0000FFFFU);
    CHAL_WRITE_REG(port->BSC, ((odr & pinmask) << 16u) | (~odr & pinmask));
}

rt_err_t chal_gpio_deinit(GPIO_T *port);
rt_err_t chal_gpio_init(GPIO_T *port, rt_uint32_t pin, chal_gpio_init_t *init);
void     chal_gpio_init_init(chal_gpio_init_t *init);

#ifdef __cplusplus
}
#endif

#endif
