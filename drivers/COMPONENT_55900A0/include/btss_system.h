/***************************************************************************//**
* \file btss_system.h
*
* Provides API declarations of the BTSS System.
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

#ifndef __BTSS_SYSTEM_H__
#define __BTSS_SYSTEM_H__



#include "bt_types.h"

#if defined(__cplusplus)
extern "C" {
#endif

/**
* \addtogroup group_sysclk
* \{
* System Clock

* \defgroup group_sysclk_macros Macros
* \defgroup group_sysclk_function Functions
* \defgroup group_sysclk_data_structures Data Structures
* \} */
/** \} group_sysclk */

/**
* \addtogroup group_sysclk_data_structures
* \{
*/
/** \brief BTSS Sytem CPU clock request types */
 typedef enum
{
    BTSS_SYSTEM_CPU_CLK_REQ_NEED_UPTO,         /* Update CPU to match new (usually more) clock frequency requirement */
    BTSS_SYSTEM_CPU_CLK_REQ_RELEASE_FROM,      /* Release previously requeseted freqency requirement. */
    BTSS_SYSTEM_CPU_CLK_REQ_LOCK_TO_SPEED,     /* Lock to the specified cpu - should only be called by one client */
    BTSS_SYSTEM_CPU_CLK_REQ_UNLOCK_FROM_SPEED, /* Unlock the locked speed - should only be called by one client */
} BTSS_SYSTEM_CPU_CLK_REQ_t;

/** \brief BTSS Sytem CPU clock request supported frequencies */
typedef enum {
    BTSS_SYSTEM_CPU_CLK_48MHZ ,
    BTSS_SYSTEM_CPU_CLK_96MHZ ,
    BTSS_SYSTEM_CPU_CLK_192MHZ,  /* Max clock frequency request supported by H1CP */
} BTSS_SYSTEM_CPU_CLK_FREQ_t;

/** \brief BTSS Sytem Audio pll request types */
typedef enum {
    BTSS_SYSTEM_AUDIO_PLL_CLK_REQ_LOCK_TO_SPEED     = 0, /* Recommended to check against supported audio PLL frequences when Bluetooth Audio is used. */
    BTSS_SYSTEM_AUDIO_PLL_CLK_REQ_UNLOCK_TO_SPEED   = 1, /* Recommended to check against supported audio PLL frequences when Bluetooth Audio is used. */
    BTSS_SYSTEM_AUDIO_PLL_CLK_REQ_PPM_ADJUST        = 2, /* Adjusts audio PLL by requested ppm for audio synchronization use cases */
} BTSS_SYSTEM_AUDIO_PLL_REQ_t;

/** \brief BTSS Sytem Audio pll request - specific pll frequencies for audio use cases. */
typedef enum {
    BTSS_SYSTEM_AUDIO_PLL_FREQ_44_1KHZ_MCLK = 67737600u, /* PLL frequency for 44.1KHz sampling rate */
    BTSS_SYSTEM_AUDIO_PLL_FREQ_GENERIC_MCLK = 73728000u, /* PLL frequency for 48/32/16/8KHz sampling rate */
} BTSS_SYSTEM_AUDIO_PLL_FREQ_t;
/** \} group_sysclk_data_structures */

/**
* \addtogroup group_sysint
* \{
* System Interrupt(s)

* \defgroup group_sysint_macros Macros
* \defgroup group_sysint_function Functions
* \defgroup group_sysint_data_structures Data Structures
* \} */
/** \} group_sysint */

/**
* \addtogroup group_sysint_data_structures
* \{
*/
/** \brief BTSS Sytem Interrupt sources for Applications */
typedef enum {
    BTSS_SYSTEM_INTERRUPT_GPIO,
    BTSS_SYSTEM_INTERRUPT_A_GPIO,
    BTSS_SYSTEM_INTERRUPT_B_GPIO,
    BTSS_SYSTEM_INTERRUPT_T2_TIMER1,
    BTSS_SYSTEM_INTERRUPT_T2_TIMER2,
    BTSS_SYSTEM_INTERRUPT_SCB0,
    BTSS_SYSTEM_INTERRUPT_SCB1,
    BTSS_SYSTEM_INTERRUPT_SCB2,
    BTSS_SYSTEM_INTERRUPT_ADCCOMP,
    BTSS_SYSTEM_INTERRUPT_MXTDM0,
    BTSS_SYSTEM_INTERRUPT_MXTDM1,
    BTSS_SYSTEM_INTERRUPT_DMIC,
    BTSS_SYSTEM_INTERRUPT_TCPWM_G0_C0,
    BTSS_SYSTEM_INTERRUPT_TCPWM_G0_C1,
    BTSS_SYSTEM_INTERRUPT_TCPWM_G1_C0,
    BTSS_SYSTEM_INTERRUPT_TCPWM_G1_C1,
    BTSS_SYSTEM_INTERRUPT_TCPWM_G1_C2,
    BTSS_SYSTEM_INTERRUPT_TCPWM_G1_C3,
    BTSS_SYSTEM_INTERRUPT_TCPWM_G1_C4,
    BTSS_SYSTEM_INTERRUPT_TCPWM_G1_C5,
    BTSS_SYSTEM_INTERRUPT_TCPWM_G1_C6,
} BTSS_SYSTEM_INTERRUPT_t;
/** \} group_sysint_data_structures */

/** \brief BTSS Sytem - Random number request type */
typedef enum
{
    BTSS_SYSTEM_RANDOM_NUM_REQ_PRNG,   /* Pseudo-random number */
    BTSS_SYSTEM_RANDOM_NUM_REQ_TRNG,   /* True random number */
} BTSS_SYSTEM_RANDOM_NUM_REQ_t;

/**
* \addtogroup group_syspm
* \{
* System Power Management

* \defgroup group_syspm_macros Macros
* \defgroup group_syspm_function Functions
* \defgroup group_syspm_data_structures Data Structures
* \} */
/** \} group_syspm */

/**
* \addtogroup group_syspm_data_structures
* \{
*/
/** \brief BTSS System - Sleep configurations */
typedef enum
{
    BTSS_SYSTEM_SLEEP_MODE_DISABLE,         /**< Disable sleep mode */
    BTSS_SYSTEM_SLEEP_MODE_NO_TRANSPORT,    /**< To be used only when HCI UART transport is not connected to host */
    BTSS_SYSTEM_SLEEP_MODE_WITH_TRANSPORT   /**< This mode allows sleep when HCI UART transport is connected to host and uses device wake line to wake up*/
} BTSS_SYSTEM_SLEEP_CONFIG_t;

/** \brief BTSS System -  Active level for Wake through GPIO */
typedef enum
{
    BTSS_SYSTEM_SLEEP_WAKE_ACTIVE_LOW, /**< Active low interrupt wakes the chip/host */
    BTSS_SYSTEM_SLEEP_WAKE_ACTIVE_HIGH /**< Active high interrupt wakes the chip/host */
} BTSS_SYSTEM_SLEEP_ACTIVE_CONFIG_t;

/** \brief BTSS System - Sleep modes */
typedef enum
{
    //! sleep is not allowed
    BTSS_SYSTEM_PMU_SLEEP_NOT_ALLOWED = 0,
    //! sleep is not disabling any part of HW, just doing processor sleep
    BTSS_SYSTEM_PMU_SLEEP_WITH_XTAL_ON = 1,
    //! same as PMU_SLEEP_WITH_XTAL but XTAL is disabled
    BTSS_SYSTEM_PMU_SLEEP_WITH_XTAL_OFF = 2,
    //! Unused entry
    BTSS_SYSTEM_PMU_SLEEP_RESERVED = 3,
    //! PDS sleep is disabling part of HW during sleep but isolation is not enabled
    BTSS_SYSTEM_PMU_SLEEP_PDS = 4,
    //! EPDS sleep is disabling most of HW during sleep, RAM is powered ON, after sleep system reboots at wake up.
    BTSS_SYSTEM_PMU_SLEEP_EPDS = 5,
    //! Max sleep mode
    BTSS_SYSTEM_PMU_SLEEP_MAX = BTSS_SYSTEM_PMU_SLEEP_EPDS
} BTSS_SYSTEM_PMU_SLEEP_MODE_t;


/** \brief BTSS System - wake sources */
typedef enum
{
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_UART_RTS_N = 1,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_UART_CTS_N = 3,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_UART_RXD = 5,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_0 = 7,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_HOST_WAKE = 9,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_2 = 11,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_3 = 13,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_4 = 15,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_5 = 17,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_6 = 19,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_7 = 21,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_19 = 23,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_18 = 25,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_16 = 27,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_17 = 29,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_8 = 32,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_9 = 34,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_10 = 36,
    BTSS_SYSTEM_PMU_WAKE_SRC_BT_GPIO_11 = 38,
    BTSS_SYSTEM_PMU_WAKE_SRC_TDM2_MCK = 70,
    BTSS_SYSTEM_PMU_WAKE_SRC_DMIC_DQ = 74,
    BTSS_SYSTEM_PMU_WAKE_SRC_DMIC_CK = 76,
    BTSS_SYSTEM_PMU_WAKE_SRC_TDM1_DO = 78,
    BTSS_SYSTEM_PMU_WAKE_SRC_TDM1_DI = 80,
    BTSS_SYSTEM_PMU_WAKE_SRC_TDM1_MCK = 82,
    BTSS_SYSTEM_PMU_WAKE_SRC_TDM1_SCK = 84,
    BTSS_SYSTEM_PMU_WAKE_SRC_TDM1_WS = 86,
    BTSS_SYSTEM_PMU_WAKE_SRC_TDM2_CLK = 88,
    BTSS_SYSTEM_PMU_WAKE_SRC_TDM2_SYNC = 90,
    BTSS_SYSTEM_PMU_WAKE_SRC_TDM2_IN = 92,
    BTSS_SYSTEM_PMU_WAKE_SRC_TDM2_OUT = 94,
    BTSS_SYSTEM_PMU_WAKE_SRC_LHL_GPIO_2 = 96,
    BTSS_SYSTEM_PMU_WAKE_SRC_LHL_GPIO_3 = 98,
    BTSS_SYSTEM_PMU_WAKE_SRC_LHL_GPIO_4 = 100,
    BTSS_SYSTEM_PMU_WAKE_SRC_LHL_GPIO_5 = 102,
    BTSS_SYSTEM_PMU_WAKE_SRC_LHL_GPIO_6 = 104,
    BTSS_SYSTEM_PMU_WAKE_SRC_LHL_GPIO_7 = 106,
    BTSS_SYSTEM_PMU_WAKE_SRC_LHL_GPIO_8 = 108,
    BTSS_SYSTEM_PMU_WAKE_SRC_LHL_GPIO_9 = 110,
} BTSS_SYSTEM_SLEEP_PMU_WAKE_SRC_t;

/** \brief CTSS System - Wake sources */
typedef enum
{
    CTSS_SYSTEM_PMU_WAKE_SRC_LHL_IO = 1024,
    CTSS_SYSTEM_PMU_WAKE_SRC_ADCCOMP_LPCOMP_1 = 1027,
    CTSS_SYSTEM_PMU_WAKE_SRC_ADCCOMP_LPCOMP_2 = 1028,
} CTSS_SYSTEM_SLEEP_PMU_WAKE_SRC_t;

/** \brief WLSS System - Wake sources */
typedef enum
{
    WLSS_SYSTEM_PMU_WAKE_SRC_WLIO = 4096,
} WLSS_SYSTEM_SLEEP_PMU_WAKE_SRC_t;

typedef enum
{
    BTSS_SYSTEM_NVRAM_OTA_ERR_NONE                          = 0x00,
    BTSS_SYSTEM_NVRAM_OTA_ERR_ADDR_OUT_OF_RANGE             = 0x01,
    BTSS_SYSTEM_NVRAM_OTA_ERR_CRYPTO_FAILED                 = 0x02,
    BTSS_SYSTEM_NVRAM_OTA_ERR_FLASH_WRITE_FAILED            = 0x03,
    BTSS_SYSTEM_NVRAM_OTA_ERR_FLASH_ERASE_FAILED            = 0x04,
    BTSS_SYSTEM_NVRAM_OTA_ERR_BUFFER_NOT_ALLOCATED          = 0x05,
    BTSS_SYSTEM_NVRAM_OTA_ERR_CRYPTO_INVALID_KEY            = 0x06,
    BTSS_SYSTEM_NVRAM_OTA_ERR_CERT_VALIDATION_FAILED        = 0x07,
    BTSS_SYSTEM_NVRAM_OTA_ERR_NO_ACCESS                     = 0x08,
    BTSS_SYSTEM_NVRAM_OTA_ERR_INVALID_MDH_SIZE              = 0x09,
} BTSS_SYSTEM_NVRAM_OTA_ERR_t;

/** Header fields for OTA upgrade feature */
typedef struct
{
    UINT32 address;
    UINT32 length;
    UINT32 flags;
} BTSS_SYSTEM_NVRAM_OTA_HEADER_t;

/** Sleep configuration parameters */
typedef struct
{
    BTSS_SYSTEM_SLEEP_CONFIG_t                  sleep_config;             /**< Requested sleep mode */

    /* host_wake_mode, device_wake_mode are applicable only
    in case of BTSS_SYSTEM_SLEEP_MODE_TRANSPORT. For BTSS_SYSTEM_SLEEP_MODE_NO_TRANSPORT
    use case, application should configure other wake sources wake pin using
    btss_system_setSleepWakeSource API*/
    BTSS_SYSTEM_SLEEP_ACTIVE_CONFIG_t                  host_wake_mode;         /**< Active level for host wake */
    BTSS_SYSTEM_SLEEP_ACTIVE_CONFIG_t                  device_wake_mode;       /**< Active level for device wake */
} BTSS_SYSTEM_SLEEP_PARAMS_t;

/** \brief Flash power down mode control methods */
typedef enum
{
    BTSS_SYSTEM_FLASH_POWER_DOWN_CMD_DISALLOW = 0, /* Disallow deep power down command to flash */
    BTSS_SYSTEM_FLASH_POWER_DOWN_CMD_ALLOW_APP_CONTROL = 1, /* Allow deep power down command to flash by application */
    BTSS_SYSTEM_FLASH_POWER_DOWN_CMD_ALLOW_BT_CONTROL = 2, /* Allow deep power down command to flash by BT */
} BTSS_SYSTEM_FLASH_POWER_DOWN_CMD_t;

/** \brief PSRAM Low Power mode control methods */
typedef enum
{
    BTSS_SYSTEM_PSRAM_LOW_POWER_DISALLOW = 0,           /* Disallow Low Power mode request to PSRAM */
    BTSS_SYSTEM_PSRAM_LOW_POWER_ALLOW_APP_CONTROL = 1,  /* Allow Low Power mode request to PSRAM by Application */
    BTSS_SYSTEM_PSRAM_LOW_POWER_ALLOW_BTSS_CONTROL = 2, /* Allow Low Power mode request to PSRAM by BTSS */
} BTSS_SYSTEM_PSRAM_LPM_CONTROL_t;

/** \brief Pre-Sleep Callback from PMU thread */
typedef BTSS_SYSTEM_PMU_SLEEP_MODE_t(*BTSS_SYSTEM_PRE_SLEEP_CB_t)(BTSS_SYSTEM_PMU_SLEEP_MODE_t sleep_mode, UINT32 sleep_time_in_lpo_cycles);
/** \brief Post-Sleep Callback from PMU thread */
typedef void(*BTSS_SYSTEM_POST_SLEEP_CB_t)(BTSS_SYSTEM_PMU_SLEEP_MODE_t sleep_mode);
/** \} group_syspm_data_structures */

/**
* \addtogroup group_sysclk_function
* \{
*/

/**
 * Function btss_system_cpuclockRequest
 *
 * Requests change in CPU clock frequency
 *
 * \param[in]    req           : Request type
 * \param[in]    freq          : Desired Frequency
 *
 * \return       Result - Pass or Fail
 */
BOOL32 btss_system_clockRequestForCpu(BTSS_SYSTEM_CPU_CLK_REQ_t req, BTSS_SYSTEM_CPU_CLK_FREQ_t freq);

/**
 * Function btss_system_clockGetCpuFreq
 *
 * Get current CPU frequency.
 *
 * \return       CPU frequency
 */
BTSS_SYSTEM_CPU_CLK_FREQ_t btss_system_clockGetCpuFreq(void);

/**
 * Function btss_system_getRpuBaseClock
 *
 * Get RPU base frequency. This goes as input clock to all peripherals.
 *
 * \return       RPU frequency
 */
UINT32 btss_system_getRpuBaseClock(void);

/**
 * Function btss_system_clockRequestForAudioPll
 *
 * Requests change in Audio PLL frequency.
 * Recommended to consider Bluetooth Audio requirements when changing Audio PLL base frequency.
 *
 * \param[in]    req           : Request type
 * \param[in]    freq          : Desired Frequency
 *
 * \return       Result - Pass or Fail
 */
BOOL32 btss_system_clockRequestForAudioPll(BTSS_SYSTEM_AUDIO_PLL_REQ_t req, UINT32 freq);

/**
 * Function btss_system_clockGetAudioPllFreq
 *
 * Get Audio PLL Frequency.
 *
 * \return       freq - Audio PLL Frequency
 */
UINT32 btss_system_clockGetAudioPllFreq(void);

/**
 * Function btss_system_getSystemTimeMicroseconds
 *
 * Get current system up time in microseconds
 *
 * \return       System time in us
 */
UINT64 btss_system_getSystemTimeMicroseconds(void);

/** \} group_sysclk_function */

/**
 * Function btss_system_getRandomNumber
 *
 * Get random number
 *
 * \param[in]    req  : Request type - PRNG or TRNG
 *
 * \return       Random number
 */
UINT32 btss_system_getRandomNumber( BTSS_SYSTEM_RANDOM_NUM_REQ_t req );

/**
* \addtogroup group_syspm_function
* \{
*/
/**
 * Function btss_system_forceSystemReset
 *
 * Forces system reset
 *
 * \return       none
 */
void btss_system_forceSystemReset(void);
/** \} group_syspm_function */

/**
* \addtogroup group_sysint_function
* \{
*/
/**
 * Function btss_system_intEnable
 *
 * Enable interrupt for peripheral
 *
 * \param[in]    interrupt       : interrupt source
 *
 * \return       Status
 */
BOOL32 btss_system_intEnable(BTSS_SYSTEM_INTERRUPT_t interrupt);

/**
 * Function btss_system_intDisable
 *
 * Disable interrupt for peripheral
 *
 * \param[in]    interrupt       : interrupt source
 *
 * \return       Status
 */
BOOL32 btss_system_intDisable(BTSS_SYSTEM_INTERRUPT_t interrupt);

/**
 * Function btss_system_intClearPending
 *
 * Clear pending interrupts for peripheral
 *
 * \param[in]    interrupt       : interrupt source
 *
 * \return       Status
 */
BOOL32 btss_system_intClearPending(BTSS_SYSTEM_INTERRUPT_t interrupt);

/**
 * Function btss_system_enterCriticalSection
 *
 * Enter critical section
 *
 * \return       Current interrupt state
 */
UINT32 btss_system_enterCriticalSection(void);

/**
 * Function btss_system_exitCriticalSection
 *
 * Clear pending interrupts for peripheral
 *
 * \param[in]    interrupt_state       : Interrupt state returned
 *                                       in btss_system_enterCriticalSection
 *
 * \return       None
 */
void btss_system_exitCriticalSection(UINT32 interrupt_state);
/** \} group_sysint_function */

/**
* \addtogroup group_syspm_function
* \{
*/

/**
 * Function btss_system_sleepInit
 *
 * Initializes sleep feature with Application callbacks.
 *
 * \param[in]    preSleepCb       : Callback before sleep entry. Returns allowed sleep mode.
 * \param[in]    postSleepCb      : Callback after wake up from sleep.
 *
 * \return       TRUE/FALSE as Status
 */
BOOL32 btss_system_sleepInit(BTSS_SYSTEM_PRE_SLEEP_CB_t preSleepCb, BTSS_SYSTEM_POST_SLEEP_CB_t postSleepCb);

/**
 * Function btss_system_sleepInit
 *
 * Enables sleep feature.
 *
 * \param[in]    params       : Sleep configuration parameters.
 *
 * \return       TRUE/FALSE as Status
 */
BOOL32 btss_system_sleepEnable(BTSS_SYSTEM_SLEEP_PARAMS_t *params);

/**
 * Function btss_system_sleepAllowMode
 *
 * Allows application to set the maximum sleep allowed to enter
 *
 * \param[in]    sleepMode       : Maximum allowed sleep mode.
 *
 * \return       TRUE/FALSE as Status
 */
BOOL32 btss_system_sleepAllowMode(BTSS_SYSTEM_PMU_SLEEP_MODE_t sleepMode);

/**
 * Function btss_system_sleepEnableWakeSource
 *
 * Enables wake source for sleep.
 *
 * \param[in]    wakeSource       : Wake source
 * \param[in]    activeState      : Level to trigger wake signal (High/Low)
 *
 * \return       TRUE/FALSE as Status
 */
BOOL32 btss_system_sleepEnableWakeSource(BTSS_SYSTEM_SLEEP_PMU_WAKE_SRC_t wakeSource, BTSS_SYSTEM_SLEEP_ACTIVE_CONFIG_t activeState);

/**
 * Function btss_system_sleepDisableWakeSource
 *
 * Disables wake source for sleep.
 *
 * \param[in]    wakeSource       : Wake source
 *
 * \return       TRUE/FALSE as Status
 */
BOOL32 btss_system_sleepDisableWakeSource(BTSS_SYSTEM_SLEEP_PMU_WAKE_SRC_t wakeSource);

/**
 * Function ctss_system_sleepEnableWakeSource
 *
 * Enables wake source for sleep.
 *
 * \param[in]    wakeSource       : Wake source
 *
 * \return       TRUE/FALSE as Status
 */
BOOL32 ctss_system_sleepEnableWakeSource(CTSS_SYSTEM_SLEEP_PMU_WAKE_SRC_t wakeSource);

/**
 * Function ctss_system_sleepDisableWakeSource
 *
 * Disables wake source for sleep.
 *
 * \param[in]    wakeSource       : Wake source
 *
 * \return       TRUE/FALSE as Status
 */
BOOL32 ctss_system_sleepDisableWakeSource(CTSS_SYSTEM_SLEEP_PMU_WAKE_SRC_t wakeSource);

/**
 * Function wlss_system_sleepEnableWakeSource
 *
 * Enables wake source for sleep.
 *
 * \param[in]    wakeSource       : Wake source
 *
 * \return       TRUE/FALSE as Status
 */
BOOL32 wlss_system_sleepEnableWakeSource(WLSS_SYSTEM_SLEEP_PMU_WAKE_SRC_t wakeSource);

/**
 * Function wlss_system_sleepDisableWakeSource
 *
 * Disables wake source for sleep.
 *
 * \param[in]    wakeSource       : Wake source
 *
 * \return       TRUE/FALSE as Status
 */
BOOL32 wlss_system_sleepDisableWakeSource(WLSS_SYSTEM_SLEEP_PMU_WAKE_SRC_t wakeSource);

/**
 * Function btss_system_disableSleepAndPause
 *
 * Disables LPM sleep and ARM pause modes
 *
 * \param[in]    none
 *
 * \return       disable request count : UINT32
 */
UINT32 btss_system_disableSleepAndPause(void);

/**
 * Function btss_system_enableSleepAndPause
 *
 * Enables LPM sleep and ARM pause modes
 *
 * \param[in]    none
 *
 * \return       disable request count : UINT32
 */
UINT32 btss_system_enableSleepAndPause(void);

/**
 * Function btss_system_getSleepAndPauseDisabledCount
 *
 * Returns the pause disabled count, could be useful for adding diagnostics.
 *
 * \param[in]    none
 *
 * \return       disable request count : UINT32
 */
UINT32 btss_system_getSleepAndPauseDisabledCount(void);

/**
 * Function btss_smif_flash_isPowerDownCmdAllowed
 *
 * Returns TRUE if the deep power down command to flash is allowed.
 *
 * \param[in]    none
 *
 * \return       BTSS_SYSTEM_FLASH_POWER_DOWN_CMD_t
 */
BTSS_SYSTEM_FLASH_POWER_DOWN_CMD_t btss_smif_flash_isPowerDownCmdAllowed(void);

/**
 * Function btss_smif_flash_allowPowerDownCmd
 *
 * mask/unmasks the power down cmd as per request, returns TRUE if the deep power down command to flash is allowed.
 *
 * \param[in]    BTSS_SYSTEM_FLASH_POWER_DOWN_CMD_t
 *
 * \return       TRUE/FALSE  : BOOL32
 */
BTSS_SYSTEM_FLASH_POWER_DOWN_CMD_t btss_smif_flash_allowPowerDownCmd(BTSS_SYSTEM_FLASH_POWER_DOWN_CMD_t allowed);

/**
 * Function btss_smif_flash_deepPowerDown
 *
 * Returns TRUE if the deep power down command to flash is acknowledged.
 *
 * \param[in]    none
 *
 * \return       TRUE/FALSE  : BOOL32
 */
BOOL32 btss_smif_flash_deepPowerDown(void);

/**
 * Function btss_smif_flash_releasePowerDown
 *
 * Returns TRUE if the release power down command to flash is acknowledged.
 *
 * \param[in]    none
 *
 * \return       TRUE/FALSE  : BOOL32
 */
BOOL32 btss_smif_flash_releasePowerDown(void);

/**
 * Function btss_system_overrideBtSleepInhibition(BOOL32 sleepAllowed)
 *
 * BT sleep is inhibited with iLPO sources, this function can override the inhibition
 *
 * \param[in]    sleepAllowed : BOOL32
 *
 * \return       none
 */
void btss_system_overrideBtSleepInhibition(BOOL32 sleepAllowed);

/**
 * Function btss_system_isBtSleepAllowed(void)
 *
 * Returns TRUE if the BT sleep is allowed
 *
 * \param[in]    none
 *
 * \return       TRUE/FALSE : BOOL32
 */
BOOL32 btss_system_isBtSleepAllowed(void);

/**
 * Function btss_smif_psram_isLowPowerAllowed
 *
 * Returns controlling PSRAM Low Power mode is allowed or not.
 *
 * \param[in]    none
 *
 * \return       BTSS_SYSTEM_PSRAM_LPM_CONTROL_t
 */
BTSS_SYSTEM_PSRAM_LPM_CONTROL_t btss_smif_psram_isLowPowerAllowed(void);

/**
 * Function btss_smif_psram_allowLowPowerMode
 *
 * enable/disable the Low Power mode as per request, returns controlling PSRAM Low Power mode is allowed or not.
 *
 * \param[in]    BTSS_SYSTEM_PSRAM_LPM_CONTROL_t
 *
 * \return       BTSS_SYSTEM_PSRAM_LPM_CONTROL_t
 */
BTSS_SYSTEM_PSRAM_LPM_CONTROL_t btss_smif_psram_allowLowPowerMode(BTSS_SYSTEM_PSRAM_LPM_CONTROL_t allowed);

/**
 * Function btss_smif_psram_enterLowPowerMode
 *
 * Returns TRUE if the operation of entering Low Power mode to PSRAM is acknowledged.
 *
 * \param[in]    none
 *
 * \return       TRUE/FALSE  : BOOL32
 */
BOOL32 btss_smif_psram_enterLowPowerMode(void);

/**
 * Function btss_smif_psram_exitLowPowerMode
 *
 * Returns TRUE if the operation of exiting Low Power mode to PSRAM is acknowledged.
 *
 * \param[in]    none
 *
 * \return       TRUE/FALSE  : BOOL32
 */
BOOL32 btss_smif_psram_exitLowPowerMode(void);
/** \} group_syspm_function */

#include "bt_types.h"

#if defined(__cplusplus)
}
#endif

#endif //__BTSS_SYSTEM_H__

/* [] END OF FILE */
