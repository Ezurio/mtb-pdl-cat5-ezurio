/***************************************************************************//**
* \file btss_gpio.h
*
* Provides API declarations of the BTSS GPIO driver.
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

#ifndef __BTSS_GPIO_H__
#define __BTSS_GPIO_H__

#include "cy_pdl_wrapper.h"


#if defined(__cplusplus)
extern "C" {
#endif

/** \brief GPIO interrupt trigger */
 typedef enum
{
    BTSS_GPIO_TRIGGER_EDGE_RISING,
    BTSS_GPIO_TRIGGER_EDGE_FALLING,
    BTSS_GPIO_TRIGGER_EDGES_BOTH,
    BTSS_GPIO_TRIGGER_LEVEL_LOW,
    BTSS_GPIO_TRIGGER_LEVEL_HIGH
} BTSS_GPIO_INT_TRIGGER_TYPE_t;

/** \brief GPIO interrupt callback */
typedef void BTSS_GPIO_ISR_CALLBACK_t ( UINT8 pin );

/** \brief List of GPIOs */
typedef enum
{
    BTSS_GPIO_0    = 0u,
    BTSS_GPIO_1    = 1u,
    BTSS_GPIO_2    = 2u,
    BTSS_GPIO_3    = 3u,
    BTSS_GPIO_4    = 4u,
    BTSS_GPIO_5    = 5u,
    BTSS_GPIO_6    = 6u,
    BTSS_GPIO_7    = 7u,
    BTSS_A_GPIO_0  = 8u,
    BTSS_A_GPIO_1  = 9u,
    BTSS_A_GPIO_2  = 10u,
    BTSS_A_GPIO_3  = 11u,
    BTSS_A_GPIO_4  = 12u,
    BTSS_A_GPIO_5  = 13u,
    BTSS_A_GPIO_6  = 14u,
    BTSS_A_GPIO_7  = 15u,
    BTSS_B_GPIO_0  = 16u,
    BTSS_B_GPIO_1  = 17u,
    BTSS_B_GPIO_2  = 18u,
    BTSS_B_GPIO_3  = 19u,
    BTSS_B_GPIO_4  = 20u,
    BTSS_B_GPIO_5  = 21u,
    BTSS_B_GPIO_6  = 22u,
    BTSS_B_GPIO_7  = 23u,
    BTSS_GPIO_LAST = BTSS_B_GPIO_7,
} BTSS_GPIO_t;

/** \brief List of LHL IOs */
typedef enum
{
    CTSS_LHL_IO_0    = 0u, //WL_DEV_WAKE
    CTSS_LHL_IO_1    = 1u, //BT_DEV_WAKE
    CTSS_LHL_IO_2    = 2u, //LHL_GPIO_2
    CTSS_LHL_IO_3    = 3u, //LHL_GPIO_3
    CTSS_LHL_IO_4    = 4u, //LHL_GPIO_4
    CTSS_LHL_IO_5    = 5u, //LHL_GPIO_5
    CTSS_LHL_IO_6    = 6u, //LHL_GPIO_6
    CTSS_LHL_IO_7    = 7u, //LHL_GPIO_7
    CTSS_LHL_IO_8    = 8u, //LHL_GPIO_8
    CTSS_LHL_IO_9    = 9u, //LHL_GPIO_9
    CTSS_LHL_IO_10   = 10u, //LPO_OUT
} CTSS_LHL_IO_t;

/** \brief GPIO interrupt trigger */
typedef enum
{// de, ne, et
    CTSS_LHL_IO_TRIGGER_LEVEL_HIGH = 0x0,
    CTSS_LHL_IO_TRIGGER_EDGE_RISING = 0x1,
    CTSS_LHL_IO_TRIGGER_LEVEL_LOW = 0x2,
    CTSS_LHL_IO_TRIGGER_EDGE_FALLING = 0x3,
    CTSS_LHL_IO_TRIGGER_EDGES_BOTH = 0x5,
} CTSS_LHL_IO_INT_TRIGGER_TYPE_t;

/** \brief CTSS LHL IO interrupt callback */
typedef void CTSS_LHL_IO_ISR_CALLBACK_t (UINT8 ioPort);

/** \brief List of WLSS IOs */
typedef enum
{
    WLSS_IO_GPIO_0 = 11, //Interrupt and Wake capable
    WLSS_IO_GPIO_2 = 13, //Interrupt and Wake capable
    WLSS_IO_GPIO_3 = 14, //Interrupt and Wake capable
    WLSS_IO_GPIO_4 = 15, //Interrupt and Wake capable
    WLSS_IO_GPIO_5 = 5,  //Interrupt and Wake capable
    WLSS_IO_GPIO_6 = 6,  //Interrupt and Wake capable
    WLSS_IO_SDIO_CMD = 0,//Interrupt and Wake capable
    WLSS_IO_SDIO_DATA_0 = 1,
    WLSS_IO_SDIO_DATA_1 = 2,
    WLSS_IO_SDIO_DATA_2 = 3,
    WLSS_IO_SDIO_DATA_3 = 4,
    WLSS_IO_RFSW_CTRL_6 = 8,
    WLSS_IO_RFSW_CTRL_7 = 9,
} WLSS_IO_t;

/** \brief WLSS IO interrupt trigger */
typedef enum
{
    WLSS_IO_INT_TRIGGER_LEVEL_HIGH = 0x000,
    WLSS_IO_INT_TRIGGER_EDGE_RISING = 0x001,
    WLSS_IO_INT_TRIGGER_LEVEL_LOW = 0x002,
    WLSS_IO_INT_TRIGGER_EDGE_FALLING = 0x003,
    WLSS_IO_INT_TRIGGER_EDGE_BOTH = 0x005,
} WLSS_IO_INT_TRIGGER_TYPE_t;


/** \brief WLSS IO wake trigger DEPRECATED*/
typedef enum
{
    WLSS_IO_WAKE_TRIGGER_LEVEL_HIGH = 0x000,
    WLSS_IO_WAKE_TRIGGER_EDGE_RISING = 0x001,
    WLSS_IO_WAKE_TRIGGER_LEVEL_LOW = 0x002,
    WLSS_IO_WAKE_TRIGGER_EDGE_FALLING = 0x003,
    WLSS_IO_WAKE_TRIGGER_EDGE_BOTH = 0x005,
} WLSS_IO_WAKE_TRIGGER_TYPE_t;

/** \brief WLSS IO interrupt callback */
typedef void WLSS_IO_ISR_CALLBACK_t (UINT8 io);

/** \brief List of GPIO Ports */
typedef enum
{
    BTSS_GPIO_PORT_0 = 0u, /* BTSS_GPIO_0 to BTSS_GPIO_7 IOs */
    BTSS_GPIO_PORT_1 = 1u, /* BTSS_A_GPIO_0 to BTSS_A_GPIO_0 IOs */
    BTSS_GPIO_PORT_2 = 2u, /* BTSS_B_GPIO_0 to BTSS_B_GPIO_0 IOs */
    BTSS_GPIO_PORT_LAST = BTSS_GPIO_PORT_2,
} BTSS_GPIO_PORT_t;

/**
 * Function btss_gpio_getNumGPIOs
 *
 *  Get Total Number of inputs and outputs
 *
 * \param                      : none
 *
 * \return       Number of GPIO pins present in chip
 */
UINT32 btss_gpio_getNumGPIOs( void );

/**
 * Function btss_gpio_setDirection
 *
 * Set the direction for the GPIO.
 *
 * \param[in]    gpio          : gpio pin number
 * \param[in]    dir           : Direction Output (1) or Input (o)
 *
 * \return       none
 */
void btss_gpio_setDirection ( BTSS_GPIO_t gpio, BOOL8 output );

/**
 * Function btss_gpio_write
 *
 * Sets the state of the gpio when used as an output under firmware control
 *
 * \param[in]    gpio          : gpio pin number
 * \param[in]    value         : Value high (1) or low (o)
 *
 * \return       none
 */
void btss_gpio_write( BTSS_GPIO_t gpio, BOOL32 value );

/**
 * Function btss_gpio_toggle
 *
 * Toggle the state of the gpio when used as an output under firmware control
 *
 * \param[in]    gpio          : gpio pin number
 * \param[in]    value         : Value high (1) or low (o)
 *
 * \return       none
 */
void btss_gpio_toggle( BTSS_GPIO_t gpio );


/**
 * Function btss_gpio_read
 *
 *  Reads the state of one GPIO and returns that state in bit 0 of the return value
 *
 * \param[in]    gpioNum       : gpio number
 *
 * \return       Pin status - 1 High, 0 Low
 */
UINT32 btss_gpio_read( BTSS_GPIO_t gpio );

/**
 * Function btss_gpio_readPort
 *
 * Reads the state of all GPIOs in the entire gpio block/port
 *
 * \param[in]    gpioBlockNum  : port number
 *
 * \return       none
 */
UINT8 btss_gpio_readPort( BTSS_GPIO_PORT_t port );

/**
 * Function btss_gpio_enableInterrupt
 *
 * Enables/Disables the interrupt for a GPIO
 *
 * \param[in]    gpio          : gpio pin number
 * \param[in]    enable        : TRUE - Enable or FALSE- Disable
 *
 * \return       none
 */
void btss_gpio_enableInterrupt ( BTSS_GPIO_t gpio, BOOL32 enable );

/**
 * Function btss_gpio_configInterrupt
 *
 * Configure interrupt mode for GPIO pin
 *
 * \param[in]    gpio          : gpio pin number
 * \param[in]    trigger       : interrupt source
 *
 * \return       none
 */
void btss_gpio_configInterrupt( BTSS_GPIO_t gpio, BTSS_GPIO_INT_TRIGGER_TYPE_t trigger );

/**
 * Function btss_gpio_registerInterruptCallback
 *
 * Register/Unregister GPIO interrupt callback
 *
 * \param[in]    gpio          : gpio pin number
 * \param[in]    callback      : callback called on interrupt from driver thread
 *
 * \return       none
 */
void btss_gpio_registerInterruptCallback( BTSS_GPIO_t gpio, BTSS_GPIO_ISR_CALLBACK_t* callback );


/**
 * Function ctss_lhl_ioSetDirection
 *
 * Set IO direction for specified pad
 *
 * \param[in]    pad               : pad to be configured
 * \param[in]    outputEnable      : TRUE : OutputEnabled
 *
 * \return       none
 */
void ctss_lhl_ioSetDirection(CTSS_LHL_IO_t ioPPort, BOOL32 outputEnable);

/**
 * Function ctss_lhl_ioSet
 *
 * Set output state to specified pad
 *
 * \param[in]    pad               : pad to be set
 * \param[in]    state             : TRUE : High
 *
 * \return       none
 */
void ctss_lhl_ioSet(CTSS_LHL_IO_t ioPPort, BOOL32 ioState);

/**
 * Function ctss_lhl_ioGet
 *
 * Get input status of specified pad
 *
 * \param[in]    pad               : pad to be get
 *
 * \return       TRUE : High, FALSE : Low
 */
BOOL32 ctss_lhl_ioGet(CTSS_LHL_IO_t ioPort);

/**
 * Function ctss_lhl_io_getOutState
 *
 * Get output status of specified pad
 *
 * \param[in]    ioPort               : pad to be get
 *
 * \return       TRUE : High, FALSE : Low
 */
BOOL32 ctss_lhl_io_getOutState(CTSS_LHL_IO_t ioPort);

/**
 * Function ctss_lhl_io_toggle
 *
 * Toggles status of specified pad
 *
 * \param[in]    ioPort               : pad to be get
 *
 * \return       none
 */
void ctss_lhl_io_toggle(CTSS_LHL_IO_t ioPort);

/**
 * Function ctss_lhl_io_configInterrupt
 *
 * Configure interrupt trigger of specified pad
 *
 * \param[in]    ioPort               : pad to be get
 * \param[in]    trigger
 *
 * \return       none
 */
void ctss_lhl_io_configInterrupt(CTSS_LHL_IO_t ioPort, CTSS_LHL_IO_INT_TRIGGER_TYPE_t trigger);

/**
 * Function ctss_lhl_io_registerInterruptCallback
 *
 * Configure interrupt trigger of specified pad
 *
 * \param[in]    ioPort               : pad to be get
 * \param[in]    cbk
 *
 * \return       none
 */
void ctss_lhl_io_registerInterruptCallback(CTSS_LHL_IO_t lhl_io, CTSS_LHL_IO_ISR_CALLBACK_t* cbk);

/**
 * Function ctss_lhl_io_enableInterrupt
 *
 * Configure interrupt trigger of specified pad
 *
 * \param[in]    ioPort               : pad to be get
 * \param[in]    enable
 *
 * \return       none
 */
void ctss_lhl_io_enableInterrupt(CTSS_LHL_IO_t ioPort, BOOL32 enable);

/**
 * Function ctss_lhl_io_enable_lhlInterrupt
 *
 * Configure interrupt trigger of specified pad
 *
 * \param[in]    ioPort               : pad to be get
 * \param[in]    enable
 *
 * \return       none
 */
void ctss_lhl_io_enable_lhlInterrupt(BOOL32 enable);


/**
 * Function wlss_io_setDirection
 *
 * Set IO direction for specified io
 *
 * \param[in]    io                : io to be configured
 * \param[in]    outputEnable      : TRUE : OutputEnabled
 *
 * \return       none
 */
void wlss_io_setDirection(WLSS_IO_t io, BOOL32 outputEnable);

/**
 * Function wlss_io_set
 *
 * Set output state to specified io
 *
 * \param[in]    io                : io to be set
 * \param[in]    state             : TRUE : High
 *
 * \return       none
 */
void wlss_io_set(WLSS_IO_t io, BOOL32 ioState);

/**
 * Function wlss_io_get
 *
 * Get input status of specified io
 *
 * \param[in]    io                : io to be get
 *
 * \return       TRUE : High, FALSE : Low
 */
BOOL32 wlss_io_get(WLSS_IO_t io);

/**
 * Function wlss_io_getOutState
 *
 * Get output status of specified io
 *
 * \param[in]    io                 : io to be get
 *
 * \return       TRUE : High, FALSE : Low
 */
BOOL32 wlss_io_getOutState(WLSS_IO_t io);

/**
 * Function wlss_io_toggle
 *
 * Toggles status of specified io
 *
 * \param[in]    io               : io to be toggled
 *
 * \return       none
 */
void wlss_io_toggle(WLSS_IO_t io);

/**
 * Function wlss_io_configInterrupt
 *
 * Configure interrupt trigger of specified pad
 *
 * \param[in]    io               : pad to be configured for interrupt
 * \param[in]    trigger          : Interrupt trigger selection
 *
 * \return       none
 */
void wlss_io_configInterrupt(WLSS_IO_t io, WLSS_IO_INT_TRIGGER_TYPE_t trigger);

/**
 * Function wlss_io_registerInterruptCallback
 *
 * Register the interrupt handler/callback for an io
 *
 * \param[in]    io               : io to be associated
 * \param[in]    cbk              : the callback function
 *
 * \return       none
 */
void wlss_io_registerInterruptCallback(WLSS_IO_t io, WLSS_IO_ISR_CALLBACK_t* cbk);

/**
 * Function wlss_io_enableInterrupt
 *
 * Enable interrupt from configured IOs
 *
 * \param[in]    io               : io to be associated
 * \param[in]    enable
 *
 * \return       none
 */
void wlss_io_enableInterrupt(WLSS_IO_t io, BOOL32 enable);

/**
 * Function wlss_io_enableGCIInterrupt
 *
 * Enable global/GCI interrupt
 *
 * \param[in]    enable
 *
 * \return       none
 */
void wlss_io_enableGCIInterrupt(BOOL32 enable);

/**
 * Function wlss_io_configWake DEPRECATED
 *
 * Configure wake trigger for an io (WLSS_IO_GPIO_0 .. 6 and WLSS_IO_SDIO_CMD)
 *
 * \param[in]    io               : io to be configured for wake
 * \param[in]    trigger          : wake trigger selection
 *
 * \return       none
 */
void wlss_io_configWake(WLSS_IO_t io, WLSS_IO_WAKE_TRIGGER_TYPE_t trigger);

/**
 * Function wlss_io_enableWake
 *
 * Enable wake from configured IOs (WLSS_IO_GPIO_0 .. 6 and WLSS_IO_SDIO_CMD)
 *
 * \param[in]    io               : io to be configured for wake
 * \param[in]    enable
 *
 * \return       none
 */
void wlss_io_enableWake(WLSS_IO_t io, BOOL32 enable);

#if defined(__cplusplus)
}
#endif

#endif //__BTSS_GPIO_H__

/* [] END OF FILE */
