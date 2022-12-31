/* header for main.c.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
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
 * Copyright (C) 2022-present xqyjlj<xqyjlj@126.com>
 *
 * @author      xqyjlj
 * @file        main.h
 *
 */

#include "chal/clock.h"
#include "chal/debug.h"
#include "chal/gpio.h"
#include "chal/power.h"

#define LED2 CHAL_PE6
#define LED3 CHAL_PE5

int main(void)
{
    chal_gpio_enable_clk(CHAL_GPIO_CLK_AFIO);
    chal_power_enable_clk();
    chal_debug_init(CHAL_DEBUG_PORT_SWJ_JTAGDISABLE);

    chal_clock_init();

    chal_gpio_enable_clk(CHAL_GPIO_CLK_GPIOA);
    chal_gpio_enable_clk(CHAL_GPIO_CLK_GPIOE);

    chal_gpio_set_level(LED2, CHAL_GPIO_LEVEL_HIGH);
    chal_gpio_set_level(LED3, CHAL_GPIO_LEVEL_LOW);

    chal_gpio_config_t config = {0};

    config.mode       = CHAL_GPIO_MODE_OUTPUT;
    config.speed      = CHAL_GPIO_SPEED_10MHz;
    config.outputtype = CHAL_GPIO_OUTPUT_PP;
    chal_gpio_init(LED2, &config);
    chal_gpio_init(LED3, &config);
    while (1) {
        chal_clock_mdelay(200);
        chal_gpio_toggle_pin(LED2);
        chal_clock_mdelay(200);
        chal_gpio_toggle_pin(LED3);
    }
}
