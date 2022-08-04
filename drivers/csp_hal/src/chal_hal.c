/**
 * @file chal_hal.c
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

#include <chal/clock.h>
#include <chal/hal.h>

RT_WEAK void csp_clock_init() {}

RT_WEAK void rt_hw_board_init()
{
#ifdef RT_USING_COMPONENTS_INIT
    rt_components_board_init();
#endif
}

void chal_error_handler(char *s, int num)
{
    rt_kprintf("error at function:%s, line number:%d \n", s, num);
    while (1) {
    }
}

#ifdef RT_DEBUG
/**
 * The RT_ASSERT function.
 *
 * @param ex the assertion condition string
 * @param func the function name when assertion.
 * @param line the file line number when assertion.
 */
RT_WEAK void rt_assert_handler(const char *ex_string, const char *func, rt_size_t line)
{
    rt_kprintf("(%s) assertion failed at function:%s, line number:%d \n", ex_string, func, line);
    while (1) {
    };
}
#endif /* RT_DEBUG */
