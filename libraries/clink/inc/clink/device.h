/*
 * ****************************************************************************
 *  @author      xqyjlj
 *  @file        device.h
 *  @brief
 *
 * ****************************************************************************
 *  @attention
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  You may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  Copyright (C) 2006-2022 RT-Thread Development Team
 *  Copyright (C) 2023-2023 xqyjlj<xqyjlj@126.com>
 *
 * ****************************************************************************
 *  Change Logs:
 *  Date           Author       Notes
 *  ------------   ----------   -----------------------------------------------
 *  2023-07-19     xqyjlj       copy from RT-Thread
 *  2023-07-19     xqyjlj       initial version
 */

#ifndef __CLINK_DEVICE_H__
#define __CLINK_DEVICE_H__

#include <clink/def.h>
#include <clink/object.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup device
 */

/**@{*/

/**
 * device flags definitions
 */
#define CLINK_DEVICE_FLAG_DEACTIVATE 0x000 /**< device is not not initialized */

#define CLINK_DEVICE_FLAG_RDONLY     0x001 /**< read only */
#define CLINK_DEVICE_FLAG_WRONLY     0x002 /**< write only */
#define CLINK_DEVICE_FLAG_RDWR       0x003 /**< read and write */

#define CLINK_DEVICE_FLAG_REMOVABLE  0x004 /**< removable device */
#define CLINK_DEVICE_FLAG_STANDALONE 0x008 /**< standalone device */
#define CLINK_DEVICE_FLAG_ACTIVATED  0x010 /**< device is activated */
#define CLINK_DEVICE_FLAG_SUSPENDED  0x020 /**< device is suspended */
#define CLINK_DEVICE_FLAG_STREAM     0x040 /**< stream mode */

#define CLINK_DEVICE_FLAG_INT_RX     0x100 /**< INT mode on Rx */
#define CLINK_DEVICE_FLAG_DMA_RX     0x200 /**< DMA mode on Rx */
#define CLINK_DEVICE_FLAG_INT_TX     0x400 /**< INT mode on Tx */
#define CLINK_DEVICE_FLAG_DMA_TX     0x800 /**< DMA mode on Tx */

#define CLINK_DEVICE_OFLAG_CLOSE     0x000 /**< device is closed */
#define CLINK_DEVICE_OFLAG_RDONLY    0x001 /**< read only access */
#define CLINK_DEVICE_OFLAG_WRONLY    0x002 /**< write only access */
#define CLINK_DEVICE_OFLAG_RDWR      0x003 /**< read and write */
#define CLINK_DEVICE_OFLAG_OPEN      0x008 /**< device is opened */
#define CLINK_DEVICE_OFLAG_MASK      0xf0f /**< mask of open flag */

typedef struct clink_device *clink_device_t;

struct clink_device_ops
{
    /* common device interface */
    clink_err_t (*init)(clink_device_t dev);
    clink_err_t (*open)(clink_device_t dev, int oflag);
    clink_err_t (*close)(clink_device_t dev);
    ssize_t (*read)(clink_device_t dev, off_t pos, void *buffer, size_t size);
    ssize_t (*write)(clink_device_t dev, off_t pos, const void *buffer, size_t size);
    clink_err_t (*control)(clink_device_t dev, int cmd, void *args);
};

/**
 * device (I/O) class type
 */
enum clink_device_class_type
{
    Clink_Device_Class_Char = 0, /**< character device */
    Clink_Device_Class_Pin,      /**< Pin device */
    Clink_Device_Class_Unknown   /**< unknown device */
};

/**
 * device structure
 */
struct clink_device
{
    struct clink_object            parent;    /**< inherit from object */
    enum clink_device_class_type   type;      /**< device type */
    uint16_t                       flag;      /**< device flag */
    uint16_t                       open_flag; /**< device open flag */
    uint8_t                        ref_count; /**< reference count */
    const struct clink_device_ops *ops;
    clink_err_t (*rx_indicate)(clink_device_t dev, size_t size);
    clink_err_t (*tx_complete)(clink_device_t dev, void *buffer);
    void *user_data; /**< device private data */
};

/**
 * @brief This function registers a device driver with a specified name.
 * @param dev is the pointer of device driver structure.
 * @param name is the device driver's name.
 * @param flags is the capabilities flag of device.
 * @return the error code, CLINK_EOK on initialization successfully.
 */
clink_err_t clink_device_register(clink_device_t dev, const char *name, uint16_t flags);

/**
 * @brief This function removes a previously registered device driver.
 * @param dev is the pointer of device driver structure.
 * @return the error code, CLINK_EOK on successfully.
 */
clink_err_t clink_device_unregister(clink_device_t dev);

/**
 * @brief This function finds a device driver by specified name.
 * @param name is the device driver's name.
 * @return the registered device driver on successful, or CLINK_NULL on failure.
 */
clink_device_t clink_device_find(const char *name);

/**
 * @brief This function will initialize the specified device.
 * @param dev is the pointer of device driver structure.
 * @return the result, CLINK_EOK on successfully.
 */
clink_err_t clink_device_init(clink_device_t dev);

/**
 * @brief This function will open a device.
 * @param dev is the pointer of device driver structure.
 * @param oflag is the flags for device open.
 * @return the result, CLINK_EOK on successfully.
 */
clink_err_t clink_device_open(clink_device_t dev, int oflag);

/**
 * @brief This function will close a device.
 * @param dev is the pointer of device driver structure.
 * @return the result, CLINK_EOK on successfully.
 */
clink_err_t clink_device_close(clink_device_t dev);

/**
 * @brief This function will read some data from a device.
 * @param dev is the pointer of device driver structure.
 * @param pos is the position when reading.
 * @param buffer is a data buffer to save the read data.
 * @param size is the size of buffer.
 * @return the actually read size on successful, otherwise 0 will be returned.
 *
 * @note the unit of size/pos is a block for block device.
 */
ssize_t clink_device_read(clink_device_t dev, off_t pos, void *buffer, size_t size);

/**
 * @brief This function will write some data to a device.
 * @param dev is the pointer of device driver structure.
 * @param pos is the position when writing.
 * @param buffer is the data buffer to be written to device.
 * @param size is the size of buffer.
 * @return the actually written size on successful, otherwise 0 will be returned.
 *
 * @note the unit of size/pos is a block for block device.
 */
ssize_t clink_device_write(clink_device_t dev, off_t pos, const void *buffer, size_t size);

/**
 * @brief This function will perform a variety of control functions on devices.
 * @param dev is the pointer of device driver structure.
 * @param cmd is the command sent to device.
 * @param arg is the argument of command.
 * @return the result, -CLINK_ENOSYS for failed.
 */
clink_err_t clink_device_control(clink_device_t dev, int cmd, void *arg);

/**
 * @brief This function will set the reception indication callback function. This callback function is invoked when this
 *        device receives data.
 * @param dev is the pointer of device driver structure.
 * @param rx_ind is the indication callback function.
 * @return CLINK_EOK
 */
clink_err_t clink_device_set_rx_indicate(clink_device_t dev, clink_err_t (*rx_ind)(clink_device_t dev, size_t size));

/**
 * @brief This function will set a callback function. The callback function will be called when device has written data
 *        to physical hardware.
 * @param dev is the pointer of device driver structure.
 * @param tx_done is the indication callback function.
 * @return CLINK_EOK
 */
clink_err_t clink_device_set_tx_complete(clink_device_t dev, clink_err_t (*tx_done)(clink_device_t dev, void *buffer));

/**@}*/

#ifdef __cplusplus
}
#endif

#endif
