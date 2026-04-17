/***************************************************************************//**
* \file btss_pinmux.h
*
* Provides API declarations of the BTSS pinmux driver.
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

#ifndef __BTSS_PINMUX_H__
#define __BTSS_PINMUX_H__

#include "cy_pdl_wrapper.h"

#if defined(__cplusplus)
extern "C" {
#endif

/*---------------------------------------------------------------
 *------------------PAD CONFIG REGISTER--------------------------
 * --------------------------------------------------------------
 * | S2 | IDB | SEL1 | SEL0 | SHYS | PDN | PUP | OEB
 * --------------------------------------------------------------
 * bit 0 - OEB - output enable
 * bit 1 - PUP - pull up
 * bit 2 - PDN - pull down
 * bit 3 - SHYS - sel hystersis
 * bit 4, 5, 7 - Driving current config 2ma to 16ma
 * bit 6 -  IDB - input disable
 * Note: LHL_GPIO pads has OEB control and no other controls.
 * --------------------------------------------------------------*/
typedef enum
{
    BTSS_PAD_CONFIG_OUTPUT_DISABLE_MASK    = 0x01,
    BTSS_PAD_CONFIG_PULL_UP_ENABLE_MASK    = 0x02,
    BTSS_PAD_CONFIG_PULL_DOWN_ENABLE_MASK  = 0x04,
    BTSS_PAD_CONFIG_HYSTERESIS_ENABLE_MASK = 0x08,
    BTSS_PAD_CONFIG_INPUT_DISABLE_MASK     = 0x40,
    BTSS_PAD_CONFIG_DRIVE_SEL_02MA_MASK    = 0x00,
    BTSS_PAD_CONFIG_DRIVE_SEL_04MA_MASK    = 0x10,
    BTSS_PAD_CONFIG_DRIVE_SEL_06MA_MASK    = 0x20,
    BTSS_PAD_CONFIG_DRIVE_SEL_08MA_MASK    = 0x30,
    BTSS_PAD_CONFIG_DRIVE_SEL_10MA_MASK    = 0x80,
    BTSS_PAD_CONFIG_DRIVE_SEL_12MA_MASK    = 0x90,
    BTSS_PAD_CONFIG_DRIVE_SEL_14MA_MASK    = 0xA0,
    BTSS_PAD_CONFIG_DRIVE_SEL_16MA_MASK    = 0xB0,
} BTSS_PAD_HW_CONFIG_t;

typedef enum
{
    PAD_BT_GPIO_00  = 0u,
    PAD_BT_GPIO_01  = 17u,
    PAD_BT_GPIO_02  = 1u,
    PAD_BT_GPIO_03  = 2u,
    PAD_BT_GPIO_04  = 3u,
    PAD_BT_GPIO_05  = 4u,
    PAD_BT_GPIO_06  = 5u,
    PAD_BT_GPIO_07  = 6u,
    PAD_BT_GPIO_08  = 7u,
    PAD_BT_GPIO_09  = 8u,
    PAD_BT_GPIO_10  = 9u,
    PAD_BT_GPIO_11  = 10u,
    PAD_BT_GPIO_12  = 11u,
    PAD_BT_GPIO_13  = 12u,
    PAD_BT_GPIO_14  = 13u,
    PAD_BT_GPIO_15  = 14u,
    PAD_BT_GPIO_16  = 15u,
    PAD_BT_GPIO_17  = 16u,
    PAD_BT_HOST_WAKE  = 17u,
    PAD_BT_UART_CTS_N  = 18u,
    PAD_BT_UART_RTS_N  = 19u,
    PAD_BT_UART_RXD  = 20u,
    PAD_BT_UART_TXD  = 21u,
    PAD_DMIC_CK  = 22u,
    PAD_DMIC_DQ  = 23u,
    PAD_LHL_GPIO_2  = 24u,
    PAD_LHL_GPIO_3  = 25u,
    PAD_LHL_GPIO_4  = 26u,
    PAD_LHL_GPIO_5  = 27u,
    PAD_LHL_GPIO_6  = 28u,
    PAD_LHL_GPIO_7  = 29u,
    PAD_LHL_GPIO_8  = 30u,
    PAD_LHL_GPIO_9  = 31u,
    PAD_TDM1_DI  = 32u,
    PAD_TDM1_DO  = 33u,
    PAD_TDM1_MCK  = 34u,
    PAD_TDM1_SCK  = 35u,
    PAD_TDM1_WS  = 36u,
    PAD_TDM2_CLK  = 37u,
    PAD_TDM2_IN  = 38u,
    PAD_TDM2_MCK  = 39u,
    PAD_TDM2_OUT  = 40u,
    PAD_TDM2_SYNC  = 41u,
    PAD_MAX_NUM  = 42u,
} BTSS_PAD_LIST_t;

typedef enum
{
    FUNC_NONE  = 0u,
    FUNC_A_GPIO_0  = 1u,
    FUNC_A_GPIO_1  = 2u,
    FUNC_A_GPIO_2  = 3u,
    FUNC_A_GPIO_3  = 4u,
    FUNC_A_GPIO_4  = 5u,
    FUNC_A_GPIO_5  = 6u,
    FUNC_A_GPIO_6  = 7u,
    FUNC_A_GPIO_7  = 8u,
    FUNC_B_GPIO_0  = 9u,
    FUNC_B_GPIO_1  = 10u,
    FUNC_B_GPIO_2  = 11u,
    FUNC_B_GPIO_3  = 12u,
    FUNC_B_GPIO_4  = 13u,
    FUNC_B_GPIO_5  = 14u,
    FUNC_B_GPIO_6  = 15u,
    FUNC_B_GPIO_7  = 16u,
    FUNC_DMIC_CK  = 17u,
    FUNC_DMIC_DQ  = 18u,
    FUNC_GPIO_0  = 19u,
    FUNC_GPIO_1  = 20u,
    FUNC_GPIO_2  = 21u,
    FUNC_GPIO_3  = 22u,
    FUNC_GPIO_4  = 23u,
    FUNC_GPIO_5  = 24u,
    FUNC_GPIO_6  = 25u,
    FUNC_GPIO_7  = 26u,
    FUNC_I2S_MSCK  = 27u,
    FUNC_I2S_MSDO  = 28u,
    FUNC_I2S_MWS  = 29u,
    FUNC_I2S_SSCK  = 30u,
    FUNC_I2S_SSDI_MSDI  = 31u,
    FUNC_I2S_SSDO  = 32u,
    FUNC_I2S_SWS  = 33u,
    FUNC_PCM_IN  = 34u,
    FUNC_SCB0_SCL  = 35u,
    FUNC_SCB0_SDA  = 36u,
    FUNC_SCB0_SPI_CLK  = 37u,
    FUNC_SCB0_SPI_MISO  = 38u,
    FUNC_SCB0_SPI_MOSI  = 39u,
    FUNC_SCB0_SPI_SEL1  = 40u,
    FUNC_SCB0_SPI_SELECT0  = 41u,
    FUNC_SCB0_SPI_SELECT1  = 42u,
    FUNC_SCB0_SPI_SELECT2  = 43u,
    FUNC_SCB0_SPI_SELECT3  = 44u,
    FUNC_SCB0_UART_CTS  = 45u,
    FUNC_SCB0_UART_RTS  = 46u,
    FUNC_SCB0_UART_RXD  = 47u,
    FUNC_SCB0_UART_TXD  = 48u,
    FUNC_SCB1_SCL  = 49u,
    FUNC_SCB1_SDA  = 50u,
    FUNC_SCB1_SPI_CLK  = 51u,
    FUNC_SCB1_SPI_MISO  = 52u,
    FUNC_SCB1_SPI_MOSI  = 53u,
    FUNC_SCB1_SPI_SELECT0  = 54u,
    FUNC_SCB1_SPI_SELECT1  = 55u,
    FUNC_SCB1_SPI_SELECT2  = 56u,
    FUNC_SCB1_SPI_SELECT3  = 57u,
    FUNC_SCB1_UART_CTS  = 58u,
    FUNC_SCB1_UART_RTS  = 59u,
    FUNC_SCB1_UART_RXD  = 60u,
    FUNC_SCB1_UART_TXD  = 61u,
    FUNC_SCB2_SCL  = 62u,
    FUNC_SCB2_SDA  = 63u,
    FUNC_SCB2_SPI_CLK  = 64u,
    FUNC_SCB2_SPI_MISO  = 65u,
    FUNC_SCB2_SPI_MOSI  = 66u,
    FUNC_SCB2_SPI_SEL0  = 67u,
    FUNC_SCB2_SPI_SEL1  = 68u,
    FUNC_SCB2_SPI_SEL2  = 69u,
    FUNC_SCB2_SPI_SEL3  = 70u,
    FUNC_SCB2_UART_CTS  = 71u,
    FUNC_SCB2_UART_RTS  = 72u,
    FUNC_SCB2_UART_RXD  = 73u,
    FUNC_SCB2_UART_TXD  = 74u,
    FUNC_TCPWM_COMP_OUT_11  = 75u,
    FUNC_TCPWM_COMP_OUT_12  = 76u,
    FUNC_TCPWM_COMP_OUT_21  = 77u,
    FUNC_TCPWM_COMP_OUT_22  = 78u,
    FUNC_TCPWM_OUT_11  = 79u,
    FUNC_TCPWM_OUT_12  = 80u,
    FUNC_TCPWM_OUT_21  = 81u,
    FUNC_TCPWM_OUT_22  = 82u,
    FUNC_TCPWM_TR_ALL_1  = 83u,
    FUNC_TCPWM_TR_ALL_2  = 84u,
    FUNC_TCPWM_TR_ALL_3  = 85u,
    FUNC_TCPWM_TR_ALL_4  = 86u,
    FUNC_TCPWM_TR_ALL_5  = 87u,
    FUNC_TCPWM_TR_ALL_6  = 88u,
    FUNC_TCPWM_TR_ALL_7  = 89u,
    FUNC_TCPWM_TR_ALL_8  = 90u,
    FUNC_TDM1_DI  = 91u,
    FUNC_TDM1_DO  = 92u,
    FUNC_TDM1_MCK  = 93u,
    FUNC_TDM1_SCK  = 94u,
    FUNC_TDM1_WS  = 95u,
    FUNC_TDM2_DI  = 96u,
    FUNC_TDM2_DO  = 97u,
    FUNC_TDM2_MCK  = 98u,
    FUNC_TDM2_SCK  = 99u,
    FUNC_TDM2_WS  = 100u,
    FUNC_UART_CTS_N  = 101u,
    FUNC_UART_RTS_N  = 102u,
    FUNC_UART_RXD  = 103u,
    FUNC_UART_TXD  = 104u,
    FUNC_TCPWM_OUT_23  = 105u,
    FUNC_TCPWM_OUT_24  = 106u,
    FUNC_TCPWM_OUT_25  = 107u,
    FUNC_TCPWM_OUT_26  = 108u,
    FUNC_TCPWM_OUT_27  = 109u,
    FUNC_BTSS_LAST = FUNC_TCPWM_OUT_27,
    FUNC_UNAVAILABLE = 255u,
} BTSS_PINMUX_FUNC_LIST_t;

typedef enum
{
    PAD_LHL_IO_0 = PAD_MAX_NUM, //WL_DEV_WAKE
    PAD_LHL_IO_1, //BT_DEV_WAKE
    PAD_LHL_IO_2, //LHL_GPIO_2
    PAD_LHL_IO_3, //LHL_GPIO_3
    PAD_LHL_IO_4, //LHL_GPIO_4
    PAD_LHL_IO_5, //LHL_GPIO_5
    PAD_LHL_IO_6, //LHL_GPIO_6
    PAD_LHL_IO_7, //LHL_GPIO_7
    PAD_LHL_IO_8, //LHL_GPIO_8
    PAD_LHL_IO_9, //LHL_GPIO_9
    PAD_LHL_IO_10, //LPO_IN_OUT
    PAD_LHL_I_MIC, //I_MIC
    PAD_CTSS_MAX_NUM,
} CTSS_PAD_LIST_t;
typedef enum
{
    FUNC_LHL_IO_0 = FUNC_BTSS_LAST + 1,
    FUNC_LHL_IO_1,
    FUNC_LHL_IO_10,
    FUNC_LPO_OUT_LHL_IO_10,
    FUNC_LHL_IO_2_ADC_MUX_SEL,
    FUNC_LHL_IO_3_ADC_MUX_SEL,
    FUNC_LHL_IO_4_ADC_MUX_SEL,
    FUNC_LHL_IO_5_ADC_MUX_SEL,
    FUNC_LHL_IO_6_ADC_MUX_SEL,
    FUNC_LHL_IO_8_ADC_MUX_SEL,
    FUNC_LHL_IO_9_ADC_MUX_SEL,
    FUNC_LHL_I_MIC_ADC_MUX_SEL,
    FUNC_CTSS_LAST = FUNC_LHL_I_MIC_ADC_MUX_SEL,
} CTSS_PINMUX_FUNC_LIST_t;

typedef enum
{
    CTSS_PAD_INPUT_PDN = 0x200,
    CTSS_PAD_INPUT_PUP = 0x400,
    CTSS_PAD_INPUT_MASK = 0x600,
    CTSS_PAD_INPUT_DISABLED = 0x600,
} CTSS_PAD_INCONFIG_t;

typedef enum
{
    CTSS_PAD_OUTPUT_DISABLED = 0x08,
    CTSS_PAD_OUTPUT_ENABLED = 0x28,
    CTSS_PAD_OUTPUT_MASK = 0x28,
} CTSS_PAD_OUTCONFIG_t;

typedef enum
{
    WLSS_PAD_INPUT_PDN = 0x10,
    WLSS_PAD_INPUT_PUP = 0x08,
    WLSS_PAD_INPUT_MASK = 0x19,
    WLSS_PAD_INPUT_DISABLED = 0x00,
    WLSS_PAD_INPUT_ENABLED = 0x01,
}WLSS_PAD_INCONFIG_t;

typedef enum
{
    WLSS_PAD_OUTPUT_DISABLED = 0x00,
    WLSS_PAD_OUTPUT_ENABLED = 0x02,
    WLSS_PAD_OUTPUT_MASK = 0x02
}WLSS_PAD_OUTCONFIG_t;

typedef enum{
    PAD_WL_GPIO_0 = PAD_CTSS_MAX_NUM,
    PAD_WL_GPIO_2,
    PAD_WL_GPIO_3,
    PAD_WL_GPIO_4,
    PAD_WL_GPIO_5,
    PAD_WL_GPIO_6,
    PAD_SDIO_CLK,
    PAD_SDIO_CMD,
    PAD_SDIO_DATA_0,
    PAD_SDIO_DATA_1,
    PAD_SDIO_DATA_2,
    PAD_SDIO_DATA_3,
    PAD_RFSW_CTRL_0,
    PAD_RFSW_CTRL_1,
    PAD_RFSW_CTRL_2,
    PAD_RFSW_CTRL_3,
    PAD_RFSW_CTRL_4,
    PAD_RFSW_CTRL_5,
    PAD_RFSW_CTRL_6,
    PAD_RFSW_CTRL_7,
    PAD_WLSS_MAX_NUM,
}WLSS_PAD_LIST_t;

typedef enum
{
    FUNC_WL_GPIO_0_GCI_GPIO_11 = FUNC_CTSS_LAST + 1,
    FUNC_WL_GPIO_0_GPIO = FUNC_WL_GPIO_0_GCI_GPIO_11,
    FUNC_WL_GPIO_2_GCI_GPIO_13,
    FUNC_WL_GPIO_2_GPIO = FUNC_WL_GPIO_2_GCI_GPIO_13,
    FUNC_WL_GPIO_3_GCI_GPIO_14,
    FUNC_WL_GPIO_3_GPIO = FUNC_WL_GPIO_3_GCI_GPIO_14,
    FUNC_WL_GPIO_4_GCI_GPIO_15,
    FUNC_WL_GPIO_4_GPIO = FUNC_WL_GPIO_4_GCI_GPIO_15,
    FUNC_WL_GPIO_5_GCI_GPIO_5,
    FUNC_WL_GPIO_5_GPIO = FUNC_WL_GPIO_5_GCI_GPIO_5,
    FUNC_WL_GPIO_6_GCI_GPIO_6,
    FUNC_WL_GPIO_6_GPIO = FUNC_WL_GPIO_6_GCI_GPIO_6,
    FUNC_SDIO_CLK,
    FUNC_SDIO_CLK_TRISTATE,
    FUNC_SDIO_CMD,
    FUNC_SDIO_CMD_GCI_GPIO_0,
    FUNC_SDIO_CMD_GPIO = FUNC_SDIO_CMD_GCI_GPIO_0,
    FUNC_SDIO_CMD_TRISTATE,
    FUNC_SDIO_DATA_0,
    FUNC_SDIO_DATA_0_GCI_GPIO_1,
    FUNC_SDIO_DATA_0_GPIO = FUNC_SDIO_DATA_0_GCI_GPIO_1,
    FUNC_SDIO_DATA_0_TRISTATE,
    FUNC_SDIO_DATA_1,
    FUNC_SDIO_DATA_1_GCI_GPIO_2,
    FUNC_SDIO_DATA_1_GPIO = FUNC_SDIO_DATA_1_GCI_GPIO_2,
    FUNC_SDIO_DATA_1_TRISTATE,
    FUNC_SDIO_DATA_2,
    FUNC_SDIO_DATA_2_GCI_GPIO_3,
    FUNC_SDIO_DATA_2_GPIO = FUNC_SDIO_DATA_2_GCI_GPIO_3,
    FUNC_SDIO_DATA_2_TRISTATE,
    FUNC_SDIO_DATA_3,
    FUNC_SDIO_DATA_3_GCI_GPIO_4,
    FUNC_SDIO_DATA_3_GPIO = FUNC_SDIO_DATA_3_GCI_GPIO_4,
    FUNC_SDIO_DATA_3_TRISTATE,
    FUNC_RFSW_CTRL_0,
    FUNC_RFSW_CTRL_1,
    FUNC_RFSW_CTRL_2,
    FUNC_RFSW_CTRL_3,
    FUNC_RFSW_CTRL_4,
    FUNC_RFSW_CTRL_5,
    FUNC_RFSW_CTRL_6,
    FUNC_RFSW_CTRL_6_GCI_GPIO_7,
    FUNC_RFSW_CTRL_6_GPIO = FUNC_RFSW_CTRL_6_GCI_GPIO_7,
    FUNC_RFSW_CTRL_7,
    FUNC_RFSW_CTRL_7_GCI_GPIO_8,
    FUNC_RFSW_CTRL_7_GPIO = FUNC_RFSW_CTRL_7_GCI_GPIO_8,
    FUNC_WL_GPIO_2_POWERON_DEFAULT,
    FUNC_WL_GPIO_3_POWERON_DEFAULT,
    FUNC_WL_GPIO_4_POWERON_DEFAULT,
    FUNC_WL_GPIO_5_POWERON_DEFAULT,
    FUNC_WL_GPIO_6_POWERON_DEFAULT,
    FUNC_SDIO_CMD_POWERON_DEFAULT,
    FUNC_SDIO_DATA_0_POWERON_DEFAULT,
    FUNC_SDIO_DATA_1_POWERON_DEFAULT,
    FUNC_SDIO_DATA_2_POWERON_DEFAULT,
    FUNC_SDIO_DATA_3_POWERON_DEFAULT,
    FUNC_RFSW_CTRL_6_POWERON_DEFAULT,
    FUNC_RFSW_CTRL_7_POWERON_DEFAULT,
    FUNC_WLSS_LAST = FUNC_RFSW_CTRL_7_POWERON_DEFAULT,
}WLSS_PINMUX_FUNC_LIST_t;

/**
 * Function ctss_pad_configParamInit
 *
 * Get the integrated pad configuration value for a ctss pad
 *
 * \param[in]    inConfig               : input configuration
 * \param[in]    outConfig              : output configuration
 *
 * \return       integrated configuration value
 */
UINT16 ctss_pad_configParamInit(CTSS_PAD_INCONFIG_t inConfig, CTSS_PAD_OUTCONFIG_t outConfig);

/**
 * Function ctss_pad_configure
 *
 * Configure a ctss pad for required functionality
 *
 * \param[in]    pad               : pad to be configured
 * \param[in]    func              : function to be assigned
 * \param[in]    config            : pad configuration value
 *
 * \return       TRUE : Success, FALSE : Failed
 */
BOOL32 ctss_pad_configure(CTSS_PAD_LIST_t pad, CTSS_PINMUX_FUNC_LIST_t func, UINT16 config);

/**
 * Function btss_pad_configure
 *
 * Assign a HW function to the GPIO pad and configure its HW parameters.
 *
 * \param[in]    pad               : btss gpio pad number
 * \param[in]    func              : New functionality
 * \param[in]    pad_config        : hw parameters
 *
 * \return       0 - FAILED, 1 - SUCCESS
 */
BOOL32 btss_pad_configure(BTSS_PAD_LIST_t pad, BTSS_PINMUX_FUNC_LIST_t func, UINT8 pad_config);

/**
 * Function btss_pad_assign_function
 *
 * Assign a HW function to the GPIO pad.
 *
 * \param[in]    pad               : btss gpio pad number
 * \param[in]    func              : New functionality
 *
 * \return       0 - FAILED, 1 - SUCCESS
 */
BOOL32 btss_pad_assignFunction (BTSS_PAD_LIST_t pad, BTSS_PINMUX_FUNC_LIST_t func);

/**
 * Function wlss_pad_configParamInit
 *
 * Get the integrated pad configuration value for a wlss pad
 *
 * \param[in]    inConfig               : input configuration
 * \param[in]    outConfig              : output configuration
 *
 * \return       integrated configuration value
 */
UINT16 wlss_pad_configParamInit(WLSS_PAD_INCONFIG_t inConfig, WLSS_PAD_OUTCONFIG_t outConfig);

/**
 * Function wlss_pad_configure
 *
 * Configure a wlss pad for required functionality
 *
 * \param[in]    pad               : pad to be configured
 * \param[in]    func              : function to be assigned
 * \param[in]    config            : pad configuration value
 *
 * \return       TRUE : Success, FALSE : Failed
 */
BOOL32 wlss_pad_configure(WLSS_PAD_LIST_t pad, WLSS_PINMUX_FUNC_LIST_t func, UINT16 config);

/**
 * Function btss_pad_getFunction
 *
 * HW function specific to a GPIO pad to satisfy certain HAL use cases.
 *
 * \param[in]    pad               : BTSS_PAD_LIST_t
 *
 * \return      FUNC_NONE when error,
 * \return      BTSS_PINMUX_FUNC_LIST_t (defined in btss_pinmux.h) when SUCCESS
 */
BTSS_PINMUX_FUNC_LIST_t btss_pad_getFunction(BTSS_PAD_LIST_t pad);


/**
 * Function btss_pad_set_hw_config
 *
 * To set hardware pad configuration like GPIO_INPUT_DISABLE, GPIO_OUTPUT_ENABLE, GPIO_PULL_UP etc.
 *
 * \param[in]    pad               : btss gpio pad number
 * \param[in]    pad_config        : hw parameters
 *
 * \return       0 - FAILED, 1 - SUCCESS
 */
BOOL32 btss_pad_setHwConfig(BTSS_PAD_LIST_t pad, UINT8 pad_config);

/**
 * Function btss_pad_get_hw_config
 *
 * To get hardware pad configuration like GPIO_INPUT_DISABLE, GPIO_OUTPUT_ENABLE, GPIO_PULL_UP etc.
 *
 * \param[in]    pad               : btss gpio pad number
 * \param[out]   pad_config        : hw parameters
 *
 * \return       0 - FAILED, 1 - SUCCESS
 */
BOOL32 btss_pad_getHwConfig(BTSS_PAD_LIST_t pad, UINT8 *pad_config);

#if defined(__cplusplus)
}
#endif

#endif //__BTSS_PINMUX_H__

/* [] END OF FILE */
