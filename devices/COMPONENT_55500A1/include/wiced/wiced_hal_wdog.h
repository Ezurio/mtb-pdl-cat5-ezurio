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
* List of parameters and defined functions needed to utilize the
* watchdog.
*
*/

#ifndef __WICED_WDOG_RESET_H__
#define __WICED_WDOG_RESET_H__

#include "wiced.h"
#include "wiced_hal_gpio.h"

/**  \addtogroup WatchdogInterface Watchdog Interface
* \ingroup HardwareDrivers
* Defines a driver for the watchdog interface. This driver manages the
* hardware watchdog countdown timer. When enabled, the watchdog timer will generate
* an interrupt when the timer counts down to zero, then will reload the counter.
* If the counter counts down to zero again, the hardware performs a device reset.
* The lowest priority "idle" thread restarts the watchdog counter preiodically,
* and other operations that may keep the system busy call wiced_hal_wdog_restart to
* extend the watchdog countdown.
*/
/*! @{ */

/******************************************************************************
*** Function prototypes.
******************************************************************************/

///////////////////////////////////////////////////////////////////////////////
/// Execute a soft reset of the system.
///
/// \param none
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_wdog_reset_system(void);

#ifdef ARLO_SUPPORT
#ifndef TZ_ACTIVE
///////////////////////////////////////////////////////////////////////////////
/// \brief Function to check whether reset happened due to Watchdog timer expiry
///
/// \return TRUE - if reset is due to Watchdog, FALSE otherwise
///////////////////////////////////////////////////////////////////////////////
wiced_bool_t wiced_watchdog_get_reset_reason(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Function to configure gpio and its active level to be set on WDT expiry
///
/// \param [in] gpio Bluetooth GPIO to be asserted before watchdog reset(only WICED_GPIO_00 - WICED_GPIO_15 are valid).
/// \param [in] active_level WICED_GPIO_ACTIVE_LOW/WICED_GPIO_ACTIVE_HIGH
/// \return WICED_SUCCESS - if GPIO is configured sucessfully, else WICED_BADARG.
///////////////////////////////////////////////////////////////////////////////
wiced_result_t wiced_watchdog_configure_reset_gpio(wiced_bt_gpio_numbers_t gpio, wiced_bool_t active_level);

///////////////////////////////////////////////////////////////////////////////
/// \brief Function to add application required delay on WDT expiry after asserting HOST_WAKE/configured GPIO
/// and before triggering core-dump transfer
///
/// \param [in] delay_ms delay in ms (default delay is 0ms).
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_watchdog_configure_reset_delay(uint32_t delay_ms);
#endif  //#ifndef TZ_ACTIVE
#endif  //#ifdef ARLO_SUPPORT
#endif // __WICED_WDOG_RESET_H__
