/*
 * (c) 2021-2026, Infineon Technologies AG, or an affiliate of Infineon
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

#include "wiced_bt_types.h"
#include "wiced_result.h"
#include "hcidefs.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 *
 * Verify if the given bd_addr matches with the local bd_addr
 *
 * @param[in]      bd_addr    :  remote bd address
 *
 * @return         TRUE if bd_addr is same as local_bd_addr,FALSE otherwise
 *
 */
wiced_bool_t wiced_bt_dev_bdaddr_is_local(wiced_bt_device_address_t bd_addr);

/**
*
* Compare two BD address
*
* @param[in]      bd_addr_1    :  bd address
* @param[in]      bd_addr_2    :  bd address to be compared with bd_addr_1
*
* Returns         TRUE if both bd_addr are same,
*                 FALSE if different
*
*/
wiced_bool_t wiced_bt_dev_bdaddr_is_same(wiced_bt_device_address_t bd_addr_1, wiced_bt_device_address_t bd_addr_2);

/**
* Is controller address resolution enabled
*
*
* Returns         TRUE if enabled
*
*/
wiced_bool_t wiced_bt_dev_is_address_resolution_enabled(void);

/**
* Is device privacy supported
*
*
* Returns         TRUE if supported
*
*/
wiced_bool_t wiced_bt_dev_is_privacy_supported(void);

/**
*  This function turns OFF/ON SMP over BR/EDR (i.e. link keys crosspairing SC BR/EDR->SC LE) for the remote device.
*  If mode is set to TRUE then the crosspairing will not happen.
*
* @param[in]  mode :  Set to TRUE to disable support for smp on br.
*
* Returns void
*
*/
void wiced_bt_dev_set_no_smp_on_br(wiced_bool_t mode);
