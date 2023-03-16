/**
 *****************************************************************************
 * @author      xqyjlj
 * @file        chal_gpio.c
 * @brief       csp hardware abstraction layer for gpio
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

void chal_gpio_config_init(chal_gpio_config_t *config)
{
    config->mode       = CHAL_GPIO_MODE_FLOATING;
    config->speed      = CHAL_GPIO_SPEED_10MHz;
    config->outputtype = CHAL_GPIO_OUTPUT_OD;
    config->pull       = CHAL_GPIO_PULL_DOWN;
}
