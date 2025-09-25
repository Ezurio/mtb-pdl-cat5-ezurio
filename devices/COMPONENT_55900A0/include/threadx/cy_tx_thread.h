//==================================================================================================
//                        THIS INFORMATION IS PROPRIETARY TO BROADCOM CORP
//--------------------------------------------------------------------------------------------------
//                               Copyright (c) 2011 Broadcom Corp.
//                               Copyright (c) 2018 Cypress Semi.
//                                      ALL RIGHTS RESERVED
//==================================================================================================
//! \file
//!
//! Thread creation and management interface for the ThreadX RTOS.
//
//==================================================================================================

#ifndef _CY_TX_THREAD_H_
#define _CY_TX_THREAD_H_

#include "cy_pdl_wrapper.h"
#include "cy_device.h"
#include "cy_smif_psram.h"

/**
* \addtogroup group_wdt
* \{
* ARM Watchdog Timer

* \defgroup group_wdt_macros Macros
* \defgroup group_wdt_function Functions
* \defgroup group_wdt_data_structures Data Structures
* \} */
/** \} group_wdt */

/**
* \addtogroup group_wdt_macros
* \{
*/
//! Default watchdog timeout (in seconds)
#define DEFAULT_WATCHDOG_TIMEOUT_IN_SEC    (2u)
/** \} group_wdt_macros */

//! Disables interrupt according to prived mask for drivers only.
//! Does not allows for manipulation of other interrupts.
int thread_ap_DisableDriverInts(UINT64 mask);

//! Enables interrupt according to prived mask for drivers only.
//! Does not allows for manipulation of other interrupts.
int thread_ap_EnableDriverInts(UINT64 mask);

int thread_ap_ClearPendingDriverInts(UINT64 mask);

//! This function calls all SVCs.
//! There is no other entry point allowed for SVCs (with the exception of one ThreadX SVC.)
int thread_ap_CallSVC(void);

//! Sets baud rate for HCI UART.
void thread_ap_setUartbaudRate(UINT32 baud_rate);

//! Save desired baudrate when app tries to configure baudrate before uart transport is up.
void thread_ap_saveDesiredBaudRate(UINT32 baud_rate);

//! Sends message from MPAF to transport.
void thread_ap_transPutMsg(void *msg);

//! Set wake up source (limited to LHL GPIOs, Quadrature and Keyscan).
int thread_ap_SetMPAFwakeUpSource(UINT32 mask);

//! Allow devices to access a memory range in non-secure SRAM.
BOOL32 thread_ap_sec_hw_openDeviceAccess(SEC_HW_DEVICE_t device, UINT8 *address, UINT32 length, UINT32 index);

//! Allocates permanent memory.
void* thread_ap_memory_AllocatePermanent(UINT32 size_bytes);

//! @brief Allow devices to read the unique SoC-id
//! @param[out] ptr_buffer buffer that holds SoC-id
//! @param[in] len_buffer size of buffer (32 bytes)
//! @return TRUE on success, else FALSE
BOOL32 thread_ap_get_SoC_Id(uint8_t *ptr_buffer, uint32_t len_buffer);

#if NVRAM_SUPPORTED
UINT32 thread_ap_config_VS_Read (UINT16 vsID, UINT32 itemLength, UINT8 *payload);
UINT32 thread_ap_config_VS_Write (UINT16 vsID, UINT32 itemLength, UINT8 *payload);
BOOL32 thread_ap_config_VS_Delete (UINT16 vsId);
#endif

/**
* \addtogroup group_wdt_function
* \{
*/
//! This function is used to assist in performing a hard reset of the chip
//! using Watch Dog Timer.
//! This function does not take into consideration disabling interrupts,
//! hence it is the responsibility of the caller to ensure that all interrupts
//! are disabled before calling this API.
void thread_ap_watchdog_HardResetHelper(void);

//! This function sets the Watchdog timer value and restarts the watchdog.
//! As it restarts the WDT, this function can also be used to pet the WDT
//! from the application.
//! This API expects time_s variable to be an "integral" number of seconds, ie,
//! the Watchdog timer value should be set in increments of 1s.
//! Allowed values for the timer are 2s to 5s.
//! Any value less than 2s will cause the timer to be set to 2s.
//! Any value more than 5s will cause the timer to be set to 5s.
BOOL8 thread_ap_watchdog_ConfigureTime(UINT8 time_s);
/** \} group_wdt_function */

#ifdef SMIF_CY
BOOL8 thread_ap_cy_smif_flash_ReadMemory (UINT32 address, UINT8 *rxBuffer, UINT32 rxSize);
BOOL8 thread_ap_cy_smif_flash_WriteMemory(UINT32 address, UINT8 *txBuffer, UINT32 txSize);
BOOL8 thread_ap_cy_smif_flash_EraseMemory(UINT32 address, UINT32 length);
#endif

UINT32 thread_ap_rbg_rand(BOOL32 requires_high_quality_rng);

#if defined(SMIF_CY) && defined(TZ_ACTIVE) && defined(BCM55900)
BTSS_SYSTEM_NVRAM_OTA_ERR_t thread_ap_OTA_Initialize(BTSS_SYSTEM_NVRAM_OTA_HEADER_t *hdr, UINT32 size);
BTSS_SYSTEM_NVRAM_OTA_ERR_t thread_ap_OTA_EraseAltImageMemory(UINT32 address, UINT32 size);
BTSS_SYSTEM_NVRAM_OTA_ERR_t thread_ap_OTA_WriteAltImageMemory(UINT32 address, UINT8 * txBuffer, UINT32 txSize);
BTSS_SYSTEM_NVRAM_OTA_ERR_t thread_ap_OTA_SwitchToAltImage(void);
BTSS_SYSTEM_NVRAM_OTA_ERR_t thread_ap_OTA_Deinitialize(void);
#endif

//! This API configures the Serial Memory Interface (SMIF) to be able to
//! access the PSRAM device. This also sets up the initial settings of
//! Memory Protection Unit (MPU) for PSRAM address space. By default, the
//! MPU is setup to allow read-write to PSRAM. Execution from PSRAM is
//! not allowed till the code region is configured using thread_ap_smif_psram_ConfigureMemoryRegions.
BOOL8 thread_ap_smif_psram_Init(cy_smif_psram_device_cfg_t * cfg);

//! This API disables the Serial Memory Interface (SMIF) to the PSRAM device.
BOOL8 thread_ap_smif_psram_DeInit();

//! This function is used to setup the code and data regions in a PSRAM.
//! Execution from CODE area is allowed, while prevented from DATA area.
//! Start of addresses must be 32 byte alligned.
//! Lenght of sections must not exceed PSRAM size
//! Code and data start addresses must lie within the PSRAM address space
//! Code and data regions must not overlap.
BOOL32 thread_ap_smif_psram_ConfigureMemoryRegions(cy_smif_psram_mem_params_t * cfg);

#endif // _CY_TX_THREAD_H_
