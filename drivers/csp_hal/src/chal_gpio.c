/**
 * @file chal_gpio.c
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

#include <chal/gpio.h>

#if defined(CHAL_GPIOA) || defined(CHAL_GPIOB) || defined(CHAL_GPIOC) || defined(CHAL_GPIOD) || defined(CHAL_GPIOE) ||                     \
    defined(CHAL_GPIOF) || defined(CHAL_GPIOG)

#define CHAL_GPIO_IS_INSTANCE(V)                                                                                                           \
    (((V) == CHAL_GPIOA) || ((V) == CHAL_GPIOB) || ((V) == CHAL_GPIOC) || ((V) == CHAL_GPIOD) || ((V) == CHAL_GPIOE) ||                    \
     ((V) == CHAL_GPIOF) || ((V) == CHAL_GPIOG))
#define CHAL_GPIO_IS_PIN(V) ((((V)&CHAL_GPIO_PIN_ALL) != 0u) && (((V) & (~CHAL_GPIO_PIN_ALL)) == 0u))
#define CHAL_GPIO_IS_MODE(V)                                                                                                               \
    (((V) == CHAL_GPIO_MODE_ANALOG) || ((V) == CHAL_GPIO_MODE_FLOATING) || ((V) == CHAL_GPIO_MODE_INPUT) ||                                \
     ((V) == CHAL_GPIO_MODE_OUTPUT) || ((V) == CHAL_GPIO_MODE_ALTERNATE))
#define CHAL_GPIO_IS_SPEED(V)  (((V) == CHAL_GPIO_SPEED_10MHz) || ((V) == CHAL_GPIO_SPEED_20MHz) || ((V) == CHAL_GPIO_SPEED_50MHz))
#define CHAL_GPIO_IS_OUTPUT(V) (((V) == CHAL_GPIO_OUTPUT_PP) || ((V) == CHAL_GPIO_OUTPUT_OD))
#define CHAL_GPIO_IS_PULL(V)   (((V) == CHAL_GPIO_PULL_DOWN) || ((V) == CHAL_GPIO_PULL_UP))

rt_err_t chal_gpio_deinit(GPIO_T *port)
{
    rt_err_t status = RT_EOK;

    /* Check the parameters */
    RT_ASSERT(CHAL_GPIO_IS_INSTANCE(port));

    /* Force and Release reset on clock of port Port */
    if (port == CHAL_GPIOA) {
        chal_gpio_force_set_clk(CHAL_GPIO_CLK_GPIOA);
        chal_gpio_force_reset_clk(CHAL_GPIO_CLK_GPIOA);
    }
    else if (port == CHAL_GPIOB) {
        chal_gpio_force_set_clk(CHAL_GPIO_CLK_GPIOB);
        chal_gpio_force_reset_clk(CHAL_GPIO_CLK_GPIOB);
    }
    else if (port == CHAL_GPIOC) {
        chal_gpio_force_set_clk(CHAL_GPIO_CLK_GPIOC);
        chal_gpio_force_reset_clk(CHAL_GPIO_CLK_GPIOC);
    }
    else if (port == CHAL_GPIOD) {
        chal_gpio_force_set_clk(CHAL_GPIO_CLK_GPIOD);
        chal_gpio_force_reset_clk(CHAL_GPIO_CLK_GPIOD);
    }
#if defined(CHAL_GPIOE)
    else if (port == CHAL_GPIOE) {
        chal_gpio_force_set_clk(CHAL_GPIO_CLK_GPIOE);
        chal_gpio_force_reset_clk(CHAL_GPIO_CLK_GPIOE);
    }
#endif
#if defined(CHAL_GPIOF)
    else if (port == CHAL_GPIOF) {
        chal_gpio_force_set_clk(CHAL_GPIO_CLK_GPIOF);
        chal_gpio_force_reset_clk(CHAL_GPIO_CLK_GPIOF);
    }
#endif
#if defined(CHAL_GPIOG)
    else if (port == CHAL_GPIOG) {
        chal_gpio_force_set_clk(CHAL_GPIO_CLK_GPIOG);
        chal_gpio_force_reset_clk(CHAL_GPIO_CLK_GPIOG);
    }
#endif
    else {
        status = RT_ERROR;
    }

    return (status);
}

rt_err_t chal_gpio_init(GPIO_T *port, rt_uint32_t pin, chal_gpio_init_t *init)
{
    rt_uint32_t pinmask, pinpos, currentpin;

    RT_ASSERT(CHAL_GPIO_IS_INSTANCE(port));
    RT_ASSERT(CHAL_GPIO_IS_PIN(init->pin));

    pinmask = ((init->pin) << 8) >> 16;
    pinpos  = CHAL_POSITION_VAL(pinmask);

    while ((pinmask >> pinpos) != 0u) {
        if ((pinmask & (1u << pinpos)) != 0u) {
            if (pinpos < 8) {
                currentpin = (0x00000101uL << pinpos);
            }
            else {
                currentpin = ((0x00010001u << (pinpos - 8)) | 0x04000000u);
            }

            if (init->mode == CHAL_GPIO_MODE_INPUT) {
                RT_ASSERT(CHAL_GPIO_IS_PULL(init->pull));
                chal_gpio_set_pull(port, currentpin, init->pull);
            }

            RT_ASSERT(CHAL_GPIO_IS_MODE(init->mode));

            chal_gpio_set_mode(port, currentpin, init->mode);

            if ((init->mode == CHAL_GPIO_MODE_OUTPUT) || (init->mode == CHAL_GPIO_MODE_ALTERNATE)) {
                RT_ASSERT(CHAL_GPIO_IS_SPEED(init->speed));
                RT_ASSERT(CHAL_GPIO_IS_OUTPUT(init->output));

                chal_gpio_set_speed(port, currentpin, init->speed);
                chal_gpio_set_output(port, currentpin, init->output);
            }
        }
        pinpos++;
    }
    return (RT_EOK);
}

void chal_gpio_init_init(chal_gpio_init_t *init)
{
    init->pin    = CHAL_GPIO_PIN_ALL;
    init->mode   = CHAL_GPIO_MODE_FLOATING;
    init->speed  = CHAL_GPIO_SPEED_10MHz;
    init->output = CHAL_GPIO_OUTPUT_OD;
    init->pull   = CHAL_GPIO_PULL_DOWN;
}

#endif
