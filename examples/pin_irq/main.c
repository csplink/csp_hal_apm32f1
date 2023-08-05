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
#define KEY1 CHAL_PIN_GET(A, 1)
#define KEY2 CHAL_PIN_GET(A, 0)

volatile clink_bool_t key1_irq_flag = CLINK_FALSE;
volatile clink_bool_t key2_irq_flag = CLINK_FALSE;

void key1_irq_callback(void *args)
{
    *(clink_bool_t *)args = CLINK_TRUE;
}

void key2_irq_callback(void *args)
{
    *(clink_bool_t *)args = CLINK_TRUE;
}

int main(void)
{
    clink_init_tick_1ms();

    chal_pin_register();

    clink_pin_mode(LED2, CLINK_PIN_MODE_OUTPUT_PP, CLINK_PIN_SPEED_LOW);
    clink_pin_mode(LED3, CLINK_PIN_MODE_OUTPUT_PP, CLINK_PIN_SPEED_LOW);

    clink_pin_write(LED2, CLINK_PIN_VALUE_HIGH);
    clink_pin_write(LED3, CLINK_PIN_VALUE_HIGH);

    clink_pin_attach_irq(KEY1, key1_irq_callback, (void *)&key1_irq_flag);
    clink_pin_attach_irq(KEY2, key2_irq_callback, (void *)&key2_irq_flag);

    clink_pin_irq_enable(KEY1, CLINK_PIN_IRQ_MODE_FALLING, CLINK_PIN_SPEED_LOW);
    clink_pin_irq_enable(KEY2, CLINK_PIN_IRQ_MODE_FALLING, CLINK_PIN_SPEED_LOW);

    while (1)
    {
        if (key1_irq_flag)
        {
            clink_delay_ms(50);
            key1_irq_flag = CLINK_FALSE;
            if (clink_pin_read(KEY1) == CLINK_PIN_VALUE_LOW)
            {
                clink_delay_ms(50);
                if (clink_pin_read(KEY1) == CLINK_PIN_VALUE_LOW)
                    clink_pin_toggle(LED2);
            }
        }

        if (key2_irq_flag)
        {
            clink_delay_ms(50);
            key2_irq_flag = CLINK_FALSE;
            if (clink_pin_read(KEY2) == CLINK_PIN_VALUE_LOW)
            {
                clink_delay_ms(50);
                if (clink_pin_read(KEY2) == CLINK_PIN_VALUE_LOW)
                    clink_pin_toggle(LED3);
            }
        }
    }
}
