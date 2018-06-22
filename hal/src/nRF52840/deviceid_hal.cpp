/*
 * Copyright (c) 2018 Particle Industries, Inc.  All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#include "deviceid_hal.h"
#include <stddef.h>
#include "nrf52840.h"
#include <string.h>
#include <sys/param.h>

#define NORDIC_DEVICE_PREFIX        0x68ce0fe0

// 32 bit prefix and 64 bit unique device identifier
static const unsigned device_id_len = 12;

unsigned HAL_device_ID(uint8_t* dest, unsigned destLen)
{
    uint32_t device_id[3] = {NORDIC_DEVICE_PREFIX, NRF_FICR->DEVICEID[0], NRF_FICR->DEVICEID[1]};

    if (dest!=NULL && destLen>0)
        memcpy(dest, (char*)device_id, MIN(destLen, device_id_len));
    return device_id_len;
}

unsigned HAL_Platform_ID()
{
    return PLATFORM_ID;
}

int HAL_Get_Device_Identifier(const char** name, char* buf, size_t buflen, unsigned index, void* reserved)
{
    return -1;
}