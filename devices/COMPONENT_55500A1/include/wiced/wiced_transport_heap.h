/*
 * (c) 2016-2026, Infineon Technologies AG, or an affiliate of Infineon
 * Technologies AG. All rights reserved.
 * This software, associated documentation and materials ("Software") is
 * owned by Infineon Technologies AG or one of its affiliates ("Infineon")
 * and is protected by and subject to worldwide patent protection, worldwide
 * copyright laws, and international treaty provisions. Therefore, you may use
 * this Software only as provided in the license agreement accompanying the
 * software package from which you obtained this Software. If no license
 * agreement applies, then any use, reproduction, modification, translation, or
 * compilation of this Software is prohibited without the express written
 * permission of Infineon.
 *
 * Disclaimer: UNLESS OTHERWISE EXPRESSLY AGREED WITH INFINEON, THIS SOFTWARE
 * IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING, BUT NOT LIMITED TO, ALL WARRANTIES OF NON-INFRINGEMENT OF
 * THIRD-PARTY RIGHTS AND IMPLIED WARRANTIES SUCH AS WARRANTIES OF FITNESS FOR A
 * SPECIFIC USE/PURPOSE OR MERCHANTABILITY.
 * Infineon reserves the right to make changes to the Software without notice.
 * You are responsible for properly designing, programming, and testing the
 * functionality and safety of your intended application of the Software, as
 * well as complying with any legal requirements related to its use. Infineon
 * does not guarantee that the Software will be free from intrusion, data theft
 * or loss, or other breaches ("Security Breaches"), and Infineon shall have
 * no liability arising out of any Security Breaches. Unless otherwise
 * explicitly approved by Infineon, the Software may not be used in any
 * application where a failure of the Product or any consequences of the use
 * thereof can reasonably be expected to result in personal injury.
 */

/** @file
 *
 * API Defines the transport utilities using dynamic memory allocation for sending/receiving the data.
 */
#pragma once

#include <stdint.h>
#include <stdlib.h>
#include "wiced_data_types.h"
#include "wiced_result.h"

/*
*  Define structure to configure dynamic heap for transport
*/
typedef struct wiced_transport_heap_cfg_s
{
    /*Data heap size requirement of application, this heap will be used for data tx and Rx*/
    uint32_t      data_heap_size;

    /*Data heap size requirement of application, this heap will be used for logging hci trace*/
    uint32_t      hci_trace_heap_size;

    /*Data heap size requirement of application, this heap will be used for logging debug trace*/
    uint32_t      debug_trace_heap_size;
}wiced_transport_heap_cfg_t;

/**
* Function         wiced_trans_create_heap
*
*                  Creates dynamic memory area. Application reserves an area for dynamic
*                  variable memory allocations with this call. Application can now allocate
*                  variable sized buffers.
*
* @param[in]       Size of heap to be allocated and related configuration defined by config
*
* @return          wiced_result_t
*/
wiced_result_t wiced_trans_create_heap (wiced_transport_heap_cfg_t * heap_config);

/**
* Function         wiced_trans_malloc_data
*
*                  Allocates memory from the transport data heap
*
* @param[in]       Size of heap to be allocated and heap type
*
* @return          void
*/
void * wiced_trans_malloc_data(uint32_t length);

/**
* Function         wiced_trans_malloc_hci_trace
*
*                  Allocates memory from the transport hci trace heap
*
* @param[in]       Size of heap to be allocated and heap type
*
* @return          void
*/
void* wiced_trans_malloc_hci_trace(uint32_t length);

/**
* Function         wiced_trans_malloc_debug
*
*                  Allocates memory from the transport debug heap
*
* @param[in]       Size of heap to be allocated and heap type
*
* @return          void
*/
void* wiced_trans_malloc_debug(uint32_t length);


/**
* Function         wiced_trans_free
*
*                  Frees memory from the heap specified by type
*
* @param[in]       pointer to the heap memory.
*
* @return          void
*/
void wiced_trans_free (void *pBuf);
