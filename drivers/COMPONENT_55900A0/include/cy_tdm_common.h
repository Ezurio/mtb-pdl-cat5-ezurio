/***************************************************************************//**
* \file cy_tdm_common.h
*
* Provides API declarations of the TDM driver related to BTSS integration.
*
********************************************************************************
* \copyright
* Copyright 2022 Infineon Technologies
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#if !defined (_CY_TDM_COMMON_H)
#define _CY_TDM_COMMON_H

#include "cy_pdl_device.h"

#if defined (CY_IP_MXTDM)

#include "cy_tdm.h"
#ifndef CY_USING_HAL
#include "cy_pdl_wrapper.h"
#endif

#if defined(__cplusplus)
extern "C" {
#endif

/** \brief MXTDM - Interrupt Callback from IRQ Thread */
typedef void(*CY_TDM_IRQ_THREAD_CB_t)(UINT8 instance, BOOL8 rx_int);


/** \brief MXTDM - Chip Specific output control for CYW55513 */
typedef enum
{
    CY_TDM_SELECT_DEFAULT    = 0x00u, /**< Selects Tx fsync & sck as TDM fsync & sck */
    CY_TDM_SELECT_TX_OUTPUT  = 0x00u, /**< Selects Tx fsync & sck as TDM fsync & sck */
    CY_TDM_SELECT_RX_OUTPUT  = 0x01u, /**< Selects Rx fsync & sck as TDM fsync & sck */
} CY_TDM_OUTPUT_CONFIG_t;

/**
 * Function Cy_SCB_RegisterInterruptCallback
 *
 * Register interrupt callback for all SCB interrupts
 *
 * \param[in]    base          : MXTDM IP instance base address
 * \param[in]    irqCb         : Callback function
 *
 * \return       Result - Pass or Fail
 */
BOOL32 Cy_AudioTDM_RegisterInterruptCallback(TDM_STRUCT_Type *base, CY_TDM_IRQ_THREAD_CB_t irqCb);

/**
 * Function Cy_AudioTDM_EnableInterrupt
 *
 * Enable SCB interrupt and set IRQ callback. This callback gets
 * called from IRQ Thread and not from interrupt context.
 *
 * \param[in]    base          : MXTDM IP instance base address
 *
 * \return       Result - Pass or Fail
 */
void Cy_AudioTDM_EnableInterrupt    (TDM_STRUCT_Type *base);

/**
 * Function Cy_AudioTDM_DisableInterrupt
 *
 * Disable MXTDM interrupt
 *
 * \param[in]    base          : MXTDM IP base address
 *
 * \return       Result - Pass or Fail
 */
void Cy_AudioTDM_DisableInterrupt    (TDM_STRUCT_Type *base);

/**
 * Function Cy_AudioTDM_EnableOutput
 *
 * Configure TDM output for different routing modes.
 *
 * \param[in]    base          : MXTDM IP base address
 * \param[in]    config        : Refer CY_TDM_OUTPUT_CONFIG_t for options
 *
 * \return       Result - Pass or Fail
 */
void Cy_AudioTDM_EnableOutput(TDM_STRUCT_Type *base, CY_TDM_OUTPUT_CONFIG_t config);

/**
 * Function Cy_AudioTDM_EnableClock
 *
 * Enable system clock for TDM IP. Required for register read/write access.
 *
 * \param[in]    base          : MXTDM IP base address
 *
 * \return       None
 */
void Cy_AudioTDM_EnableClock(TDM_STRUCT_Type *base);

/**
 * Function Cy_AudioTDM_DisableClock
 *
 * Enable system clock for TDM IP. Required for register read/write access.
 *
 * \param[in]    base          : MXTDM IP base address
 *
 * \return       None
 */
void Cy_AudioTDM_DisableClock(TDM_STRUCT_Type *base);

#if defined(__cplusplus)
    }
#endif

#endif //CY_IP_MXTDM

#endif //_CY_TDM_COMMON_H
