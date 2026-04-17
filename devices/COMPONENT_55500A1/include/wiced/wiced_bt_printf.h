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
 * This file provided functionality to provide debug traces
 *
 */


#pragma once

#include <stdarg.h>
#include <string.h>
#include "wiced.h"
#include "wiced_bt_types.h"
#include "wiced_bt_printf.h"

#ifndef WICEDX_WIN          /* In windows, this pulls in a lot of files that cause compile errors */
    #ifdef COMPONENT_MW_BTSDK_INCLUDE
    #include "wiced_hal_puart.h"
    #endif
#endif

//#define WICED_BT_TRACE_ENABLE
#ifdef WICED_BT_TRACE_ENABLE
#define WICED_SHIM_TRACE_ENABLE
#endif

/** Debug UARTs. Used when calling wiced_set_debug_uart.*/
typedef enum
{
    WICED_ROUTE_DEBUG_NONE  =  0x00, /**< No traces */
    WICED_ROUTE_DEBUG_TO_WICED_UART, /**< send debug strings in formatted AIROC HCI messages over HCI UART to ClientControl or MCU */
    WICED_ROUTE_DEBUG_TO_HCI_UART,   /**< send debug strings as plain text to HCI UART, used by default if wiced_set_debug_uart() not called */
    WICED_ROUTE_DEBUG_TO_DBG_UART,   /**< Deprecated */
    WICED_ROUTE_DEBUG_TO_PUART       /**< send debug strings as plain text to the peripheral uart (PUART) */
}wiced_debug_uart_types_t;

#ifdef WICED_SHIM_TRACE_ENABLE
#define WICED_SHIM_TRACE(...)        BTU_trace_debug(__VA_ARGS__)
#else
#define WICED_SHIM_TRACE(...)
#endif

void wiced_bt_trace_enable(void);

/**
 * Function         wiced_set_debug_uart
 *
 * To specify the UART to be used for the debug traces
 *
 * @param[in]      uart        : UART to be used
 *
 * @return          void
 *
 */
void wiced_set_debug_uart ( wiced_debug_uart_types_t uart );

/* @} */

extern void wiced_print_trace(char* p_trace_buf, int trace_buf_len, wiced_bt_trace_type_t trace_type);
extern void wiced_bt_trace_array( const char *string, const uint8_t* array, const uint16_t len );
extern void wiced_trace_array( const uint8_t* p_array, uint16_t len);
extern wiced_debug_uart_types_t wiced_get_debug_uart ( void );


extern void BTU_trace_debug(const char* p_fmt, ...);

extern void BTU_trace_error(const char* p_fmt, ...);

#define wiced_printf(p1,p2,...)  BTU_trace_debug(__VA_ARGS__)

extern int BTU_sprintf(char *buf, const char *fmt, ...);
