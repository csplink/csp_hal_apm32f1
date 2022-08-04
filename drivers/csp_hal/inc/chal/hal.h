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
#include <rtthread.h>

#ifdef __cplusplus
extern "C" {
#endif

#define chal_write_bit(reg, bit)                 ((reg) |= (bit))
#define chal_clear_bit(reg, bit)                 ((reg) &= ~(bit))
#define chal_read_bit(reg, bit)                  ((reg) & (bit))
#define chal_write_reg(reg, val)                 ((reg) = (val))
#define chal_clear_reg(reg)                      ((reg) = (0x0))
#define chal_read_reg(reg)                       ((reg))
#define chal_modify_reg(reg, clearmask, setmask) chal_write_reg((reg), (((chal_read_reg(reg)) & (~(clearmask))) | (setmask)))
#define chal_position_val(val)                   (__CLZ(__RBIT(val)))

void chal_error_handler(char *s, int num);

#ifdef __cplusplus
}
#endif

#endif
