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

#pragma once

/* Include the actual RTOS definitions for:
 * - wiced_timed_event_t
 * - timed_event_handler_t
 */
#include "wiced_result.h"
#include "wiced_bt_dev.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    WICED_RTOS_DEFER_TO_MPAF_THREAD,
    WICED_RTOS_DEFER_TO_LM_THREAD,
    WICED_RTOS_MAX_DEFER_THREADS_SUPPORTED
}wiced_defer_context_t;

/******************************************************
 *                 Type Definitions
 ******************************************************/

/******************************************************
 *             Structures
 ******************************************************/

/** Defer execution of callback function to a different thread (currently only App and LM threads are supported)
 *
 * @param new_thread_context : thread context to which the execution is being defered to
 * @param func               : Callback function to be invoked from the thread context chosen above
 * @param data               : Data to be given to the above function
 *
 * @return    WICED_SUCCESS : on success.
 * @return    WICED_BADARG   : if an invalid arg is received
 */
wiced_result_t wiced_rtos_defer_execution(wiced_defer_context_t new_thread_context, void (*func)(void *), void *data);

/** @} */


#ifdef __cplusplus
} /*extern "C" */
#endif
