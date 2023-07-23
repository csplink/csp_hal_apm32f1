/*
 * ****************************************************************************
 *  @author      xqyjlj
 *  @file        object.c
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
 *  Copyright (C) 2006-2023 RT-Thread Development Team
 *  Copyright (C) 2023-2023 xqyjlj<xqyjlj@126.com>
 *
 * ****************************************************************************
 *  Change Logs:
 *  Date           Author       Notes
 *  ------------   ----------   -----------------------------------------------
 *  2023-07-23     xqyjlj       copy from RT-Thread
 *  2023-07-23     xqyjlj       initial version
 */

#include <clink/debug.h>
#include <clink/device.h>

clink_err_t clink_device_register(clink_device_t dev, const char *name, uint16_t flags)
{
    if (dev == CLINK_NULL)
        return -CLINK_ERROR;

    if (clink_device_find(name) != CLINK_NULL)
        return -CLINK_ERROR;

    clink_object_init(&(dev->parent), Clink_Object_Class_Device, name);
    dev->flag      = flags;
    dev->ref_count = 0;
    dev->open_flag = 0;

    return CLINK_EOK;
}

clink_err_t clink_device_unregister(clink_device_t dev)
{
    /* parameter check */
    CLINK_ASSERT(dev != CLINK_NULL);
    CLINK_ASSERT(clink_object_get_type(&dev->parent) == Clink_Object_Class_Device);

    clink_object_detach(&(dev->parent));

    return CLINK_EOK;
}

clink_device_t clink_device_find(const char *name)
{
    return (clink_device_t)clink_object_find(name, Clink_Object_Class_Device);
}

clink_err_t clink_device_init(clink_device_t dev)
{
    clink_err_t result = CLINK_EOK;

    CLINK_ASSERT(dev != CLINK_NULL);

    if (dev->ops->init != CLINK_NULL)
    {
        if (!(dev->flag & CLINK_DEVICE_FLAG_ACTIVATED))
        {
            result = dev->ops->init(dev);
            if (result == CLINK_EOK)
            {
                dev->flag |= CLINK_DEVICE_FLAG_ACTIVATED;
            }
        }
    }

    return result;
}

clink_err_t clink_device_open(clink_device_t dev, int oflag)
{
    clink_err_t result = CLINK_EOK;

    /* parameter check */
    CLINK_ASSERT(dev != CLINK_NULL);
    CLINK_ASSERT(clink_object_get_type(&dev->parent) == Clink_Object_Class_Device);

    /* if device is not initialized, initialize it. */
    if (!(dev->flag & CLINK_DEVICE_FLAG_ACTIVATED))
    {
        if (dev->ops->init != CLINK_NULL)
        {
            result = dev->ops->init(dev);
            if (result != CLINK_EOK)
            {
                return result;
            }
        }

        dev->flag |= CLINK_DEVICE_FLAG_ACTIVATED;
    }

    /* device is a stand alone device and opened */
    if ((dev->flag & CLINK_DEVICE_FLAG_STANDALONE) && (dev->open_flag & CLINK_DEVICE_OFLAG_OPEN))
    {
        return -CLINK_EBUSY;
    }

    /* device is not opened or opened by other oflag, call device_open interface */
    if (!(dev->open_flag & CLINK_DEVICE_OFLAG_OPEN) ||
        ((dev->open_flag & CLINK_DEVICE_OFLAG_MASK) != (oflag & CLINK_DEVICE_OFLAG_MASK)))
    {
        if (dev->ops->open != CLINK_NULL)
        {
            result = dev->ops->open(dev, oflag);
        }
        else
        {
            /* set open flag */
            dev->open_flag = (oflag & CLINK_DEVICE_OFLAG_MASK);
        }
    }

    /* set open flag */
    if (result == CLINK_EOK || result == -CLINK_ENOSYS)
    {
        dev->open_flag |= CLINK_DEVICE_OFLAG_OPEN;

        dev->ref_count++;
        /* don't let bad things happen silently. If you are bitten by this assert, please set the ref_count to a bigger
         * type. */
        CLINK_ASSERT(dev->ref_count != 0);
    }

    return result;
}

clink_err_t clink_device_close(clink_device_t dev)
{
    clink_err_t result = CLINK_EOK;

    /* parameter check */
    CLINK_ASSERT(dev != CLINK_NULL);
    CLINK_ASSERT(clink_object_get_type(&dev->parent) == Clink_Object_Class_Device);

    if (dev->ref_count == 0)
        return -CLINK_ERROR;

    dev->ref_count--;

    if (dev->ref_count != 0)
        return CLINK_EOK;

    if (dev->ops->close != CLINK_NULL)
    {
        result = dev->ops->close(dev);
    }

    /* set open flag */
    if (result == CLINK_EOK || result == -CLINK_ENOSYS)
        dev->open_flag = CLINK_DEVICE_OFLAG_CLOSE;

    return result;
}

ssize_t clink_device_read(clink_device_t dev, off_t pos, void *buffer, size_t size)
{
    /* parameter check */
    CLINK_ASSERT(dev != CLINK_NULL);
    CLINK_ASSERT(clink_object_get_type(&dev->parent) == Clink_Object_Class_Device);

    if (dev->ref_count == 0)
    {
        return -CLINK_ERROR;
    }

    if (dev->ops->read != CLINK_NULL)
    {
        return dev->ops->read(dev, pos, buffer, size);
    }

    return -CLINK_ENOSYS;
}

ssize_t clink_device_write(clink_device_t dev, off_t pos, const void *buffer, size_t size)
{
    /* parameter check */
    CLINK_ASSERT(dev != CLINK_NULL);
    CLINK_ASSERT(clink_object_get_type(&dev->parent) == Clink_Object_Class_Device);

    if (dev->ref_count == 0)
    {
        return -CLINK_ERROR;
    }

    if (dev->ops->write != CLINK_NULL)
    {
        return dev->ops->write(dev, pos, buffer, size);
    }

    return -CLINK_ENOSYS;
}

clink_err_t clink_device_control(clink_device_t dev, int cmd, void *arg)
{
    /* parameter check */
    CLINK_ASSERT(dev != CLINK_NULL);
    CLINK_ASSERT(clink_object_get_type(&dev->parent) == Clink_Object_Class_Device);

    if (dev->ops->control != CLINK_NULL)
    {
        return dev->ops->control(dev, cmd, arg);
    }

    return -CLINK_ENOSYS;
}

clink_err_t clink_device_set_rx_indicate(clink_device_t dev, clink_err_t (*rx_ind)(clink_device_t dev, size_t size))
{
    /* parameter check */
    CLINK_ASSERT(dev != CLINK_NULL);
    CLINK_ASSERT(clink_object_get_type(&dev->parent) == Clink_Object_Class_Device);

    dev->rx_indicate = rx_ind;

    return CLINK_EOK;
}

clink_err_t clink_device_set_tx_complete(clink_device_t dev, clink_err_t (*tx_done)(clink_device_t dev, void *buffer))
{
    /* parameter check */
    CLINK_ASSERT(dev != CLINK_NULL);
    CLINK_ASSERT(clink_object_get_type(&dev->parent) == Clink_Object_Class_Device);

    dev->tx_complete = tx_done;

    return CLINK_EOK;
}
