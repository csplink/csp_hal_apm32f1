/**
 *****************************************************************************
 * @author      xqyjlj
 * @file        main.c
 * @brief       main program body
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
 * 2023-08-04     xqyjlj       initial version
 */
#include <chal.h>
#include <chal/pin.h>

#define LED2 CHAL_PIN_GET(E, 6)
#define LED3 CHAL_PIN_GET(E, 5)

int main(void)
{
    clink_init_tick_1ms();

    chal_pin_register();

    clink_pin_mode(LED2, CLINK_PIN_MODE_OUTPUT_PP, CLINK_PIN_SPEED_LOW);
    clink_pin_mode(LED3, CLINK_PIN_MODE_OUTPUT_PP, CLINK_PIN_SPEED_LOW);

    clink_pin_write(LED2, CLINK_PIN_VALUE_HIGH);
    clink_pin_write(LED3, CLINK_PIN_VALUE_LOW);

    while (1)
    {
        clink_delay_ms(500);
        clink_pin_toggle(LED2);
        clink_pin_toggle(LED3);
    }
}
