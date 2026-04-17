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
* Embedded Flash interface driver.
*
*/

#ifndef _WICED_HAL_EFLASH_H_
#define _WICED_HAL_EFLASH_H_

/**  \addtogroup EmbeddedFlashInterfaceDriver Embedded Flash Interface
* \ingroup HardwareDrivers
* Defines a driver for the Serial Flash interface.
* @{
*/

/**
 * Function         wiced_hal_eflash_init
 *
 * Intializes the embedded flash
 *
 * @return     : wiced_result_t
 */
wiced_result_t wiced_hal_eflash_init( void );

/**
 * Function         wiced_hal_eflash_read
 *
 * Reads the data from eflash
 *
 * @param[in]    offset           :start offset of eflash from which data to be read, offset should be word aligned
 * @param[in]    p_buffer        :Pointer to the buffer to which data is to be read, buffer should be word aligned
 * @param[in]    length           :length of data in byte's to be read.
 *
 * @return     : wiced_result_t
 */
wiced_result_t wiced_hal_eflash_read( uint32_t offset, uint8_t* p_buffer, uint32_t length );

/**
 * Function         wiced_hal_eflash_write
 *
 * Writes the data to eflash.Interrupts will be locked for the duration of the write. And only writes to an already
 * erased location is valid.
 *
 * @param[in]    offset           :start offset of eflash to be written, offset should be word aligned
 * @param[in]    p_buffer        :Pointer to the buffer from which data will be written, buffer should be byte, half-word, or word aligned.
 * @param[in]    length           :length of data in byte's to be written, length should be word aligned
 *
 * @return     : wiced_result_t
 */
wiced_result_t wiced_hal_eflash_write( uint32_t offset, uint8_t* p_buffer, uint32_t length );

/**
 * Function         wiced_hal_eflash_erase
 *
 * Erase the eflash. Erase is performed page-wise. eflash page size is 0x1000 bytes.
 * eflash page count is 0x100.
 *
 * @param[in]    offset           :start offset of eflash page to be erased.
 * @param[in]    length           :length of data in byte's to be erased, erase performed page-wise.
 *
 * @return     : wiced_result_t
 */
wiced_result_t wiced_hal_eflash_erase( uint32_t offset, uint32_t length );

/**
 * Function         wiced_hal_eflash_erase_whole
 *
 * Erase the whole eflash
 *
 * @return     : wiced_result_t
 */
wiced_result_t wiced_hal_eflash_erase_whole( void );

/**
 * Function         wiced_hal_eflash_get_size
 *
 * Gets the sizeof the eflash
 *
 * @return     : eflash size
 */
uint32_t wiced_hal_eflash_get_size( void );

/* @} */

#endif // _WICED_HAL_EFLASH_H_
