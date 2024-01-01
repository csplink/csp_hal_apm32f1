/**< add user code begin header */
/**
 * ****************************************************************************
 *  @author      csplink coder: geehy.csp_hal_apm32f1(v0.0.1)
 *  @file        gpio.h
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
#include "apm32f10x.h"
#include "apm32f10x_gpio.h"
#include "apm32f10x_eint.h"
#include "apm32f10x_misc.h"
#include "apm32f10x_rcm.h"
/**< add user code begin includes */

/**> add user code end includes */

/* typedef -------------------------------------------------------------------*/
/**< add user code begin typedef */

/**> add user code end typedef */

/* define --------------------------------------------------------------------*/
#define LED3_PORT GPIOE
#define LED3_PIN GPIO_PIN_5
#define LED2_PORT GPIOE
#define LED2_PIN GPIO_PIN_6
/**< add user code begin define */

/**> add user code end define */

/* macro ---------------------------------------------------------------------*/
/**< add user code begin macro */

/**> add user code end macro */

/* extern variables ----------------------------------------------------------*/
/**< add user code begin extern variables */

/**> add user code end extern variables */

/* functions prototypes ------------------------------------------------------*/

/**
 * @brief configure gpio
 */
void csplink_gpio_init(void);
/**< add user code begin functions prototypes */

/**> add user code end functions prototypes */

/**< add user code begin 0 */

/**> add user code end 0 */
