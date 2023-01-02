/**
 *****************************************************************************
 * @author      xqyjlj
 * @file        gpio.h
 * @brief       header for chal_gpio.c
 *
 *****************************************************************************
 * @attention
 * Licensed under the Apache License, Version 2.0 (the "License");
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Copyright (C) 2022-2023 xqyjlj<xqyjlj@126.com>
 *
 *****************************************************************************
 * Change Logs:
 * Date           Author       Notes
 * ------------   ----------   -----------------------------------------------
 * 2023-01-02     xqyjlj       initial version
 */

#ifndef __CHAL_GPIO_H__
#define __CHAL_GPIO_H__

#include <chal/hal.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief CHAL_GPIO_GET_PIN(A, 0) = GPIOA, LL_GPIO_PIN_0
 */
#define CHAL_GPIO_GET_PIN(PORTx, PIN) GPIO##PORTx, LL_GPIO_PIN_##PIN

#if defined(GPIOA)
#define CHAL_PA0            CHAL_GPIO_GET_PIN(A, 0)
#define CHAL_PA1            CHAL_GPIO_GET_PIN(A, 1)
#define CHAL_PA2            CHAL_GPIO_GET_PIN(A, 2)
#define CHAL_PA3            CHAL_GPIO_GET_PIN(A, 3)
#define CHAL_PA4            CHAL_GPIO_GET_PIN(A, 4)
#define CHAL_PA5            CHAL_GPIO_GET_PIN(A, 5)
#define CHAL_PA6            CHAL_GPIO_GET_PIN(A, 6)
#define CHAL_PA7            CHAL_GPIO_GET_PIN(A, 7)
#define CHAL_PA8            CHAL_GPIO_GET_PIN(A, 8)
#define CHAL_PA9            CHAL_GPIO_GET_PIN(A, 9)
#define CHAL_PA10           CHAL_GPIO_GET_PIN(A, 10)
#define CHAL_PA11           CHAL_GPIO_GET_PIN(A, 11)
#define CHAL_PA12           CHAL_GPIO_GET_PIN(A, 12)
#define CHAL_PA13           CHAL_GPIO_GET_PIN(A, 13)
#define CHAL_PA14           CHAL_GPIO_GET_PIN(A, 14)
#define CHAL_PA15           CHAL_GPIO_GET_PIN(A, 15)
#define CHAL_GPIO_CLK_GPIOA LL_APB2_GRP1_PERIPH_GPIOA
#endif

#if defined(GPIOB)
#define CHAL_PB0            CHAL_GPIO_GET_PIN(B, 0)
#define CHAL_PB1            CHAL_GPIO_GET_PIN(B, 1)
#define CHAL_PB2            CHAL_GPIO_GET_PIN(B, 2)
#define CHAL_PB3            CHAL_GPIO_GET_PIN(B, 3)
#define CHAL_PB4            CHAL_GPIO_GET_PIN(B, 4)
#define CHAL_PB5            CHAL_GPIO_GET_PIN(B, 5)
#define CHAL_PB6            CHAL_GPIO_GET_PIN(B, 6)
#define CHAL_PB7            CHAL_GPIO_GET_PIN(B, 7)
#define CHAL_PB8            CHAL_GPIO_GET_PIN(B, 8)
#define CHAL_PB9            CHAL_GPIO_GET_PIN(B, 9)
#define CHAL_PB10           CHAL_GPIO_GET_PIN(B, 10)
#define CHAL_PB11           CHAL_GPIO_GET_PIN(B, 11)
#define CHAL_PB12           CHAL_GPIO_GET_PIN(B, 12)
#define CHAL_PB13           CHAL_GPIO_GET_PIN(B, 13)
#define CHAL_PB14           CHAL_GPIO_GET_PIN(B, 14)
#define CHAL_PB15           CHAL_GPIO_GET_PIN(B, 15)
#define CHAL_GPIO_CLK_GPIOB LL_APB2_GRP1_PERIPH_GPIOB
#endif

#if defined(GPIOC)
#define CHAL_PC0            CHAL_GPIO_GET_PIN(C, 0)
#define CHAL_PC1            CHAL_GPIO_GET_PIN(C, 1)
#define CHAL_PC2            CHAL_GPIO_GET_PIN(C, 2)
#define CHAL_PC3            CHAL_GPIO_GET_PIN(C, 3)
#define CHAL_PC4            CHAL_GPIO_GET_PIN(C, 4)
#define CHAL_PC5            CHAL_GPIO_GET_PIN(C, 5)
#define CHAL_PC6            CHAL_GPIO_GET_PIN(C, 6)
#define CHAL_PC7            CHAL_GPIO_GET_PIN(C, 7)
#define CHAL_PC8            CHAL_GPIO_GET_PIN(C, 8)
#define CHAL_PC9            CHAL_GPIO_GET_PIN(C, 9)
#define CHAL_PC10           CHAL_GPIO_GET_PIN(C, 10)
#define CHAL_PC11           CHAL_GPIO_GET_PIN(C, 11)
#define CHAL_PC12           CHAL_GPIO_GET_PIN(C, 12)
#define CHAL_PC13           CHAL_GPIO_GET_PIN(C, 13)
#define CHAL_PC14           CHAL_GPIO_GET_PIN(C, 14)
#define CHAL_PC15           CHAL_GPIO_GET_PIN(C, 15)
#define CHAL_GPIO_CLK_GPIOC LL_APB2_GRP1_PERIPH_GPIOC
#endif

#if defined(GPIOD)
#define CHAL_PD0            CHAL_GPIO_GET_PIN(D, 0)
#define CHAL_PD1            CHAL_GPIO_GET_PIN(D, 1)
#define CHAL_PD2            CHAL_GPIO_GET_PIN(D, 2)
#define CHAL_PD3            CHAL_GPIO_GET_PIN(D, 3)
#define CHAL_PD4            CHAL_GPIO_GET_PIN(D, 4)
#define CHAL_PD5            CHAL_GPIO_GET_PIN(D, 5)
#define CHAL_PD6            CHAL_GPIO_GET_PIN(D, 6)
#define CHAL_PD7            CHAL_GPIO_GET_PIN(D, 7)
#define CHAL_PD8            CHAL_GPIO_GET_PIN(D, 8)
#define CHAL_PD9            CHAL_GPIO_GET_PIN(D, 9)
#define CHAL_PD10           CHAL_GPIO_GET_PIN(D, 10)
#define CHAL_PD11           CHAL_GPIO_GET_PIN(D, 11)
#define CHAL_PD12           CHAL_GPIO_GET_PIN(D, 12)
#define CHAL_PD13           CHAL_GPIO_GET_PIN(D, 13)
#define CHAL_PD14           CHAL_GPIO_GET_PIN(D, 14)
#define CHAL_PD15           CHAL_GPIO_GET_PIN(D, 15)
#define CHAL_GPIO_CLK_GPIOD LL_APB2_GRP1_PERIPH_GPIOD
#endif

#if defined(GPIOE)
#define CHAL_PE0            CHAL_GPIO_GET_PIN(E, 0)
#define CHAL_PE1            CHAL_GPIO_GET_PIN(E, 1)
#define CHAL_PE2            CHAL_GPIO_GET_PIN(E, 2)
#define CHAL_PE3            CHAL_GPIO_GET_PIN(E, 3)
#define CHAL_PE4            CHAL_GPIO_GET_PIN(E, 4)
#define CHAL_PE5            CHAL_GPIO_GET_PIN(E, 5)
#define CHAL_PE6            CHAL_GPIO_GET_PIN(E, 6)
#define CHAL_PE7            CHAL_GPIO_GET_PIN(E, 7)
#define CHAL_PE8            CHAL_GPIO_GET_PIN(E, 8)
#define CHAL_PE9            CHAL_GPIO_GET_PIN(E, 9)
#define CHAL_PE10           CHAL_GPIO_GET_PIN(E, 10)
#define CHAL_PE11           CHAL_GPIO_GET_PIN(E, 11)
#define CHAL_PE12           CHAL_GPIO_GET_PIN(E, 12)
#define CHAL_PE13           CHAL_GPIO_GET_PIN(E, 13)
#define CHAL_PE14           CHAL_GPIO_GET_PIN(E, 14)
#define CHAL_PE15           CHAL_GPIO_GET_PIN(E, 15)
#define CHAL_GPIO_CLK_GPIOE LL_APB2_GRP1_PERIPH_GPIOE
#endif

#if defined(GPIOF)
#define CHAL_PF0            CHAL_GPIO_GET_PIN(F, 0)
#define CHAL_PF1            CHAL_GPIO_GET_PIN(F, 1)
#define CHAL_PF2            CHAL_GPIO_GET_PIN(F, 2)
#define CHAL_PF3            CHAL_GPIO_GET_PIN(F, 3)
#define CHAL_PF4            CHAL_GPIO_GET_PIN(F, 4)
#define CHAL_PF5            CHAL_GPIO_GET_PIN(F, 5)
#define CHAL_PF6            CHAL_GPIO_GET_PIN(F, 6)
#define CHAL_PF7            CHAL_GPIO_GET_PIN(F, 7)
#define CHAL_PF8            CHAL_GPIO_GET_PIN(F, 8)
#define CHAL_PF9            CHAL_GPIO_GET_PIN(F, 9)
#define CHAL_PF10           CHAL_GPIO_GET_PIN(F, 10)
#define CHAL_PF11           CHAL_GPIO_GET_PIN(F, 11)
#define CHAL_PF12           CHAL_GPIO_GET_PIN(F, 12)
#define CHAL_PF13           CHAL_GPIO_GET_PIN(F, 13)
#define CHAL_PF14           CHAL_GPIO_GET_PIN(F, 14)
#define CHAL_PF15           CHAL_GPIO_GET_PIN(F, 15)
#define CHAL_GPIO_CLK_GPIOF LL_APB2_GRP1_PERIPH_GPIOF
#endif

#if defined(GPIOG)
#define CHAL_PG0            CHAL_GPIO_GET_PIN(G, 0)
#define CHAL_PG1            CHAL_GPIO_GET_PIN(G, 1)
#define CHAL_PG2            CHAL_GPIO_GET_PIN(G, 2)
#define CHAL_PG3            CHAL_GPIO_GET_PIN(G, 3)
#define CHAL_PG4            CHAL_GPIO_GET_PIN(G, 4)
#define CHAL_PG5            CHAL_GPIO_GET_PIN(G, 5)
#define CHAL_PG6            CHAL_GPIO_GET_PIN(G, 6)
#define CHAL_PG7            CHAL_GPIO_GET_PIN(G, 7)
#define CHAL_PG8            CHAL_GPIO_GET_PIN(G, 8)
#define CHAL_PG9            CHAL_GPIO_GET_PIN(G, 9)
#define CHAL_PG10           CHAL_GPIO_GET_PIN(G, 10)
#define CHAL_PG11           CHAL_GPIO_GET_PIN(G, 11)
#define CHAL_PG12           CHAL_GPIO_GET_PIN(G, 12)
#define CHAL_PG13           CHAL_GPIO_GET_PIN(G, 13)
#define CHAL_PG14           CHAL_GPIO_GET_PIN(G, 14)
#define CHAL_PG15           CHAL_GPIO_GET_PIN(G, 15)
#define CHAL_GPIO_CLK_GPIOG LL_APB2_GRP1_PERIPH_GPIOG
#endif

#define CHAL_GPIO_CLK_AFIO LL_APB2_GRP1_PERIPH_AFIO

/**
 * @brief GPIO level low and high enumeration
 */
typedef enum
{
    CHAL_GPIO_LEVEL_LOW = 0u, /* low level*/
    CHAL_GPIO_LEVEL_HIGH      /* high level*/
} chal_gpio_level_t;

/**
 * @brief GPIO mode enumeration
 */
typedef enum
{
    CHAL_GPIO_MODE_ANALOG    = LL_GPIO_MODE_ANALOG,   /* analog mode */
    CHAL_GPIO_MODE_FLOATING  = LL_GPIO_MODE_FLOATING, /* floating mode */
    CHAL_GPIO_MODE_INPUT     = LL_GPIO_MODE_INPUT,    /* input mode */
    CHAL_GPIO_MODE_OUTPUT    = LL_GPIO_MODE_OUTPUT,   /* general purpose output mode */
    CHAL_GPIO_MODE_ALTERNATE = LL_GPIO_MODE_ALTERNATE /* alternate function mode */
} chal_gpio_mode_t;

/**
 * @brief GPIO speed enumeration
 */
typedef enum
{
    CHAL_GPIO_SPEED_10MHz = LL_GPIO_SPEED_FREQ_LOW,    /* output mode, max speed 10 MHz */
    CHAL_GPIO_SPEED_20MHz = LL_GPIO_SPEED_FREQ_MEDIUM, /* output mode, max speed 20 MHz */
    CHAL_GPIO_SPEED_50MHz = LL_GPIO_SPEED_FREQ_HIGH    /* output mode, max speed 50 MHz */
} chal_gpio_speed_t;

/**
 * @brief GPIO output type enumeration
 */
typedef enum
{
    CHAL_GPIO_OUTPUT_PP = LL_GPIO_OUTPUT_PUSHPULL, /* open-drain as output type */
    CHAL_GPIO_OUTPUT_OD = LL_GPIO_OUTPUT_OPENDRAIN /* push-pull as output type */
} chal_gpio_output_type_t;

/**
 * @brief GPIO pull enumeration
 */
typedef enum
{
    CHAL_GPIO_PULL_DOWN = LL_GPIO_PULL_DOWN, /* I/O pull down */
    CHAL_GPIO_PULL_UP   = LL_GPIO_PULL_UP    /* I/O pull up */
} chal_gpio_pull_t;

/**
 * @brief GPIO init structure definition
 */
typedef struct
{
    chal_gpio_mode_t        mode;
    chal_gpio_speed_t       speed;
    chal_gpio_output_type_t outputtype;
    chal_gpio_pull_t        pull;
} chal_gpio_config_t;

__chal_inline void chal_gpio_enable_clk(uint32_t periphs)
{
    LL_APB2_GRP1_EnableClock(periphs);
}

__chal_inline uint32_t chal_gpio_is_clk_enabled(uint32_t periphs)
{
    return LL_APB2_GRP1_IsEnabledClock(periphs);
}

__chal_inline void chal_gpio_disable_clk(uint32_t periphs)
{
    LL_APB2_GRP1_DisableClock(periphs);
}

__chal_inline void chal_gpio_set_level(GPIO_TypeDef *gpiox, uint32_t pinmask, chal_gpio_level_t level)
{
    if (level != CHAL_GPIO_LEVEL_LOW)
        LL_GPIO_SetOutputPin(gpiox, pinmask);
    else
        LL_GPIO_ResetOutputPin(gpiox, pinmask);
}

__chal_inline chal_gpio_level_t chal_gpio_get_level(GPIO_TypeDef *gpiox, uint32_t pinmask)
{
    chal_gpio_level_t bitstatus;

    if (LL_GPIO_IsInputPinSet(gpiox, pinmask) != (uint32_t)CHAL_GPIO_LEVEL_LOW) {
        bitstatus = CHAL_GPIO_LEVEL_HIGH;
    }
    else {
        bitstatus = CHAL_GPIO_LEVEL_LOW;
    }
    return bitstatus;
}

__chal_inline void chal_gpio_toggle_pin(GPIO_TypeDef *gpiox, uint32_t pinmask)
{
    LL_GPIO_TogglePin(gpiox, pinmask);
}

chal_status_t chal_gpio_deinit(GPIO_TypeDef *gpiox, uint32_t pinmask);
chal_status_t chal_gpio_init(GPIO_TypeDef *gpiox, uint32_t pinmask, chal_gpio_config_t *config);

#ifdef __cplusplus
}
#endif

#endif
