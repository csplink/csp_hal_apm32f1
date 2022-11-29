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
 * 2022-07-27     xqyjlj       the first version
 *
 */

#include <chal/gpio.h>

chal_status_t chal_gpio_deinit(GPIO_TypeDef *gpiox, uint32_t pinmask)
{
    CHAL_UNUSED(pinmask);

    chal_status_t status;
    ErrorStatus   ll_status;

    ll_status = LL_GPIO_DeInit(gpiox);

    if (ll_status != SUCCESS)
        status = CHAL_ERROR;
    else
        status = CHAL_OK;

    return status;
}

chal_status_t chal_gpio_init(GPIO_TypeDef *gpiox, uint32_t pinmask, chal_gpio_config_t *config)
{
    chal_status_t       status;
    ErrorStatus         ll_status;
    LL_GPIO_InitTypeDef gpio_initstruct;

    gpio_initstruct.Pin        = pinmask;
    gpio_initstruct.Mode       = config->mode;
    gpio_initstruct.Speed      = config->speed;
    gpio_initstruct.OutputType = config->outputtype;
    gpio_initstruct.Pull       = config->pull;

    ll_status = LL_GPIO_Init(gpiox, &gpio_initstruct);

    if (ll_status != SUCCESS)
        status = CHAL_ERROR;
    else
        status = CHAL_OK;

    return status;
}
