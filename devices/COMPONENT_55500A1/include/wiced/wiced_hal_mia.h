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
* List of parameters and defined functions needed to access the
* Multiple Interface Adapter (MIA) driver.
*
*/

#ifndef __WICED_MIA_H__
#define __WICED_MIA_H__

#include "wiced_data_types.h"

/**  \addtogroup MIADriver Multiple Interface Adapter (MIA)
* \ingroup HardwareDrivers
* @{
*
* Defines a Multiple Interface Adapter (MIA) driver to facilitate interfacing
* with various components of the hardware
* The MIA driver controls aspects such as GPIO pin muxing, interrupt
* managment, and timing.
*
* Use this driver to enable and disable interrupts, along with managing
* hardware events (such as PUART RX). There are many possibilities--please
* look over the following API functions to see what can be done.
*/

/******************************************************************************
*** Function prototypes and defines.
******************************************************************************/

///////////////////////////////////////////////////////////////////////////////
/// Initializes the MIA driver and its private values. Also programs all
/// relevant GPIOs to be ready for use. This must be invoked before
/// accessing any MIA driver services, typically at boot.
/// This is independent of other drivers and must be one of the first to
/// be initialized.
///
/// \param none
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_mia_init(void);


///////////////////////////////////////////////////////////////////////////////
/// Determines and returns if the reason for the last reset was from Power
/// On (Power On Reset).
///
/// \param none
///
/// \return reason - 1 if reset was caused by Power On Reset, 0 otherwise.
///////////////////////////////////////////////////////////////////////////////
uint32_t wiced_hal_mia_is_reset_reason_por(void);


///////////////////////////////////////////////////////////////////////////////
/// Enable or disable all MIA-based interrupts.
///
/// \param enable - 1 to enable interrupts, 0 to disable interrupts.
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_mia_enable_mia_interrupt(uint32_t enable);


///////////////////////////////////////////////////////////////////////////////
/// Enable or disable all LHL-based interrupts.
///
/// \param enable - 1 to enable interrupts, 0 to disable interrupts.
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_mia_enable_lhl_interrupt(uint32_t enable);


///////////////////////////////////////////////////////////////////////////////
/// Get the MIA interrupt state.  This state may not be the
/// actual hardware MIA interrupt setting, since the interrupt
/// context interrupt handler will disable the MIA interrupt
/// without updating the state variable, which is a good thing
/// since it makes it easy to restore the correct hardware
/// setting from this state variable when done handling the
/// serialized interrupt by calling wiced_hal_mia_restoreMiaInterruptState().
///
/// \return 1 if MIA interrupts should be enabled, 0 if MIA interrupts should
/// be disabled.
///////////////////////////////////////////////////////////////////////////////
uint32_t wiced_hal_mia_get_mia_interrupt_state(void);


///////////////////////////////////////////////////////////////////////////////
/// Get the LHL interrupt state.  This state may not be the
/// actual hardware LHL interrupt setting, since the interrupt
/// context interrupt handler will disable the LHL interrupt
/// without updating the state variable, which is a good thing
/// since it makes it easy to restore the correct hardware
/// setting from this state variable when done handling the
/// serialized interrupt by calling wiced_hal_restoreLhlInterruptSetting().
///
/// \return 1 if lhl interrupts should be enabled, 0 if lhl interrupts should
/// be disabled.
///////////////////////////////////////////////////////////////////////////////
uint32_t wiced_hal_mia_get_lhl_interrupt_state(void);


///////////////////////////////////////////////////////////////////////////////
/// Restore the possibly overridden MIA interrupt setting to
/// that of the MIA interrupt state.  See wiced_hal_getMiaInterruptState()
/// for more details.
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_mia_restore_mia_interrupt_state(void);


///////////////////////////////////////////////////////////////////////////////
/// Restore the possibly overridden LHL interrupt setting to
/// that of the LHL interrupt state.  See wiced_hal_getLhlInterruptState()
/// for more details.
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_mia_restore_lhl_interrupt_state(void);


/* @} */

#endif // __WICED_MIA_H__
