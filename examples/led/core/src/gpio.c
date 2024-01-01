/**< add user code begin header */
/**
 * ****************************************************************************
 *  @author      csplink coder: geehy.csp_hal_apm32f1(v0.0.1)
 *  @file        gpio.c
 *  @brief       this file provides code for the gpio initialization
 *
 * ****************************************************************************
 *  @attention
 *
 *  Copyright (C) 2023 csplink software.
 *  All rights reserved.
 *
 * ****************************************************************************
 */
/**> add user code end header */

/* includes ------------------------------------------------------------------*/
#include "csplink/gpio.h"
/**< add user code begin includes */

/**> add user code end includes */

/* typedef -------------------------------------------------------------------*/
/**< add user code begin typedef */

/**> add user code end typedef */

/* define --------------------------------------------------------------------*/
/**< add user code begin define */

/**> add user code end define */

/* macro ---------------------------------------------------------------------*/
/**< add user code begin macro */

/**> add user code end macro */

/* variables -----------------------------------------------------------------*/
/**< add user code begin variables */

/**> add user code end variables */

/* functions prototypes ------------------------------------------------------*/
/**< add user code begin functions prototypes */

/**> add user code end functions prototypes */

/**< add user code begin 0 */

/**> add user code end 0 */

void csplink_gpio_init(void)
{
    GPIO_Config_T config = {0};

    /* enable the GPIOE ports clock */
    RCM_EnableAPB2PeriphClock(RCM_APB2_PERIPH_GPIOE);

    /* configure the LED3_PORT(GPIOE), LED3_PIN(GPIO_PIN_5) */
    GPIO_WriteBitValue(LED3_PORT, LED3_PIN, BIT_SET);

    config.pin = LED3_PIN;
    config.mode = GPIO_MODE_OUT_PP;
    config.speed = GPIO_SPEED_10MHz;
    GPIO_Config(LED3_PORT, &config);

    /* configure the LED2_PORT(GPIOE), LED2_PIN(GPIO_PIN_6) */
    GPIO_WriteBitValue(LED2_PORT, LED2_PIN, BIT_RESET);

    config.pin = LED2_PIN;
    config.mode = GPIO_MODE_OUT_PP;
    config.speed = GPIO_SPEED_10MHz;
    GPIO_Config(LED2_PORT, &config);
}
/**< add user code begin 1 */

/**> add user code end 1 */
