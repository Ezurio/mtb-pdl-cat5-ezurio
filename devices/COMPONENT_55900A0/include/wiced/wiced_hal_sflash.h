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
* Serial Flash interface driver.
*
*/

#pragma once

/**  \addtogroup SerialFlashInterfaceDriver Serial Flash Interface
* \ingroup HardwareDrivers
* Defines a driver for the Serial Flash interface. The driver is responsible
* for interfacing with a Serial Flash memory module via the second SPI bus,
* with its main purpose being data handling operations. For instance, any
* unused space (from the system partition) can be used for any purpose to
* store and access data. It is a handy way for an app to save information to
* non-volatile storage.
*
*
* The software driver supports SPI Flashes with the following parameters:
* 1. Address Width - 24 bit addressing
* 2. Data Rate is specific to the IoT chip:
*       CYW207x9 supports SPI data rate upto 24MHz
* 3. Supports JEDEC's CFI (Common Flash Interface) compatible SPI Flash chips from
*    Cypress Semiconductors, SST, STMicroelectronics, Atmel, MXIC, Adesto, Winbond.
*
* Similar to the I2C EEPROM Interface Driver, this driver includes checks to
* ensure safe data handling operation--it will not allow any write or erase
* operations to take place within active sections (i.e., sections that the
* system currently uses for boot, etc). Note that read operations are
* unrestricted. Please reference the Kit Guide or HW User Manual for your device
* for more information regarding these active sections, their importance, and
* what roles they play in the system.
*
*/
/*! @{ */

/******************************************************************************
*** Function prototypes.
******************************************************************************/

///////////////////////////////////////////////////////////////////////////////
/// Initialize the SPI lines and low-level Serial Flash Interface Driver.
/// Call this before performing any SF operations.
///
/// \param none
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_sflash_init(void);

///////////////////////////////////////////////////////////////////////////////
/// Returns the installed SF module size. The low-level Serial Flash Interface
/// Driver sends specific commands to the chip, which then reports its size.
///
/// Note that this function is a good way to make sure that the SF module
/// is installed and is communicating correctly with the system.
///
/// \param none
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
uint32_t wiced_hal_sflash_get_size(void);

///////////////////////////////////////////////////////////////////////////////
/// Load data from a certain location on the serial flash module into
/// memory. To have a better read performance, place the destination data
/// buffer at a word boundary.
///
/// \param addr - The starting source address on the serial flash.
/// \param len  - The number of bytes to read.
/// \param buf  - Pointer to destination data buffer.
///
/// \return The number of bytes read.
///////////////////////////////////////////////////////////////////////////////
uint32_t wiced_hal_sflash_read(uint32_t addr, uint32_t len, uint8_t *buf);

///////////////////////////////////////////////////////////////////////////////
/// Write data from memory to a certain location on the serial flash module.
///
/// (!) Please ensure that the address and (address + length) of data to be
/// written does not go beyond the size of the memory module. If they do,
/// the write operation will "wrap around" and start corrupting the starting
/// address of the memory (boot sector), rendering the device inoperable.
///
/// (!) Note that this function will not allow corruption of certain memory
/// locations, such as currently active sections (boot sectors) and sections
/// required for the proper function of the Bluetooth subsystem.
///
/// \param addr - The starting destination address on the serial flash.
/// \param len  - The number of bytes to write.
/// \param buf  - Pointer to source data buffer.
///
/// \return The number of bytes written.
///////////////////////////////////////////////////////////////////////////////
uint32_t wiced_hal_sflash_write(uint32_t addr, uint32_t len, uint8_t *buf);

///////////////////////////////////////////////////////////////////////////////
/// Erase len number of bytes from the serial flash. Depending on the starting
/// address and length, it calls sector or block erase to do the work.
///
/// (!) Please ensure that the address and (address + length) of data to be
/// written does not go beyond the size of the memory module. If they do,
/// the erase operation will "wrap around" and start erasing the starting
/// address of the memory (boot sector), rendering the device inoperable.
///
/// (!) Note that due to the nature of Serial Flash memory and the limitations
/// of sector and/or block boundaries, it is possible that the number of bytes
/// erased could be greater than len.
///
/// \param addr   - The starting erase address on the serial flash.
/// \param len    - The number of bytes to erase.
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_sflash_erase(uint32_t addr, uint32_t len);

/* @} */
