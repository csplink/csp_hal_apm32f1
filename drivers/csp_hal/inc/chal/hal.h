/**
 * @file hal.h
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

#ifndef __CHAL_HAL_H__
#define __CHAL_HAL_H__

#include <apm32f10x.h>
#include <apm32f10x_gpio.h>
#include <apm32f10x_rcm.h>
#include <rtthread.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CHAL_WRITE_BIT(REG, BIT)                 ((REG) |= (BIT))
#define CHAL_CLEAR_BIT(REG, BIT)                 ((REG) &= ~(BIT))
#define CHAL_READ_BIT(REG, BIT)                  ((REG) & (BIT))
#define CHAL_WRITE_REG(REG, VAL)                 ((REG) = (VAL))
#define CHAL_CLEAR_REG(REG)                      ((REG) = (0X0))
#define CHAL_READ_REG(REG)                       ((REG))
#define CHAL_MODIFY_REG(REG, CLEARMASK, SETMASK) CHAL_WRITE_REG((REG), (((CHAL_READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))
#define CHAL_POSITION_VAL(VAL)                   (__CLZ(__RBIT(VAL)))

void chal_error_handler(char *s, int num);

#ifdef __cplusplus
}
#endif

#endif
