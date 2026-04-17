/*
 * (c) 2019-2026, Infineon Technologies AG, or an affiliate of Infineon
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
 *  \addtogroup timer Timer Management Services
 *  \ingroup HardwareDrivers
 *
 *  @{
 *
 * Defines the interfaces for Timer Management Services
 */

#ifndef _WICED_TIMER_H_
#define _WICED_TIMER_H_

#include "wiced_result.h"

typedef void *wiced_timer_callback_arg_t;                  /**< Timer callback argument type */
typedef wiced_timer_callback_arg_t WICED_TIMER_PARAM_TYPE; /**< To avoid recompiling older apps */
typedef wiced_timer_callback_arg_t TIMER_PARAM_TYPE;       /**< To avoid recompiling older apps */

/**
 * Function prototype for the timer call back.
 * @param[in]    cb_params      :Timer callback function
 */
typedef void (wiced_timer_callback_t)(wiced_timer_callback_arg_t cb_params);

/** Timer structure.
 *
 *  NOTE: this structure is used internally by the AIROC stack. Applications MUST NOT
 *        modify any of the elements of this structure.
 *
 *        Timer control block memory MUST be peristant from when the timer is initialized,
 *        using wiced_init_timer(), till it is de-initialized, using wiced_deinit_timer().
 */
typedef struct _wiced_timer_t
{
    struct _wiced_timer_t       *p_next;   /**< internal, next pointer to \ref wiced_timer_t */
    wiced_timer_callback_t      *p_cback;  /**< internal, the callback function */
    wiced_timer_callback_arg_t  cb_arg;    /**< internal, the callback argument */
    uint32_t                    pi;        /**< internal, timer flags */
    uint64_t                    tt;        /**< internal, timer timeout */
} wiced_timer_t;

/**
 * Defines the AIROC timer types. These timers are system tick driven and a
 * systick is 1 millisecond.So the minimum timer resolution supported is
 * 1 millisecond
 */
typedef enum
{
    WICED_MILLI_SECONDS_TIMER, /**< Single shot milliseconds timer */
    WICED_SECONDS_TIMER,       /**< Single shot seconds timer */
    WICED_MILLI_SECONDS_PERIODIC_TIMER, /**< Periodic milliseconds timer */
    WICED_SECONDS_PERIODIC_TIMER, /**< Periodic seconds timer */
} wiced_timer_type_e;

#ifdef __cplusplus
extern "C"
{
#endif

/**  Initializes the timer
 *
 *@param[in]    p_timer         :Pointer to the timer structure
 *@param[in]    p_timer_cb      :Timer callback function to be invoked on timer expiry
 *@param[in]    cb_arg          :Parameter to be passed to the timer callback function which
 *                               gets invoked on timer expiry,if any
 *@param[in]    timer_type      :Shows if the timer is milliseconds or seconds, and if periodic or not
 *
 * @return   wiced_result_t
 */
wiced_result_t wiced_init_timer (wiced_timer_t* p_timer, wiced_timer_callback_t *p_timer_cb,
                                 wiced_timer_callback_arg_t cb_arg, wiced_timer_type_e timer_type);

/** Starts a timer
 * @note: Starting an already running timer restarts the timer timeout
 *
 * @param[in] p_timer :Pointer to the timer structure
 * @param[in] timeout : The units of the timeout parameter is set as per the timer_type set in #wiced_init_timer\n
 *            timeout is in milliseconds if timer_type is #WICED_MILLI_SECONDS_TIMER or #WICED_MILLI_SECONDS_PERIODIC_TIMER,\n
 *            timeout is in seconds if timer_type is #WICED_SECONDS_TIMER or #WICED_SECONDS_PERIODIC_TIMER,
 *
 * @return       wiced_result_t
 */
wiced_result_t wiced_start_timer (wiced_timer_t* p_timer,uint32_t timeout);

/** Stops a timer
 *
 * @param[in]    p_timer      :Pointer to the timer structure
 *
 * @return       wiced_result_t
 */
wiced_result_t wiced_stop_timer (wiced_timer_t *p_timer);

/**  Checks if a timer is in use
*
*@param[in]    p_timer                  :Pointer to the timer structure
*
* @return   TRUE if the timer is in use and FALSE if the timer is not in use
*/
wiced_bool_t wiced_is_timer_in_use (wiced_timer_t *p_timer);

/** Deinitialize a timer instance and stops the timer if it is running
 *
 * @param[in]    p_timer                :Pointer to the timer
 *
 * @return       wiced_result_t
 */
wiced_result_t wiced_deinit_timer (wiced_timer_t* p_timer);

/** @} */
#ifdef __cplusplus
}
#endif

#endif // _WICED_TIMER_H_
