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
 * Bluetooth Management (BTM) Application Programming Interface
 *
 * The BTM consists of several management entities:
 *      1. Device Control - controls the local device
 *      2. Device Discovery - manages inquiries, discover database
 *      3. ACL Channels - manages ACL connections (BR/EDR and LE)
 *      4. SCO Channels - manages SCO connections
 *      5. Security - manages all security functionality
 *      6. Power Management - manages park, sniff, hold, etc.
 *
 * AIROC Bluetooth Framework Functions
 */

#ifndef __WICED_BT_STACK_H__
#define __WICED_BT_STACK_H__

#include "wiced_bt_cfg.h"
#include "wiced_bt_dev.h"

/******************************************************
 *               Function Declarations
 ******************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************/
/**
 *
 * @ingroup     wiced_bt_cfg
 *
 * @{
 */
/****************************************************************************/

/**
 *
 * Initialize the Bluetooth controller and stack; register
 * callback for Bluetooth event notification.
 *
 * @param[in] p_bt_management_cback     : Callback for receiving Bluetooth management events
 * @param[in] p_bt_cfg_settings         : Bluetooth stack configuration #wiced_bt_cfg_settings_t
 *
 * @return   <b> WICED_BT_SUCCESS </b> : on success; \n
 *           <b> WICED_BT_FAILED  </b> : if an error occurred
 * @note This API must be called before using any Bluetooth functionality. \n
 * If p_bt_cfg_settings is null, stack uses default parameters defined in wiced_bt_cfg.h \n
 *     However, it is strongly recommended that applications define the configuration to appropriate values based on the application use case.
 */
wiced_result_t wiced_bt_stack_init(wiced_bt_management_cback_t *p_bt_management_cback,
                                    const wiced_bt_cfg_settings_t *p_bt_cfg_settings);

/**
 * This is a blocking call (returns after all de-initialisation procedures are complete)
 * It is recommended that the application disconnect any outstanding connections prior to invoking this function.
 *
 * @return  <b>  WICED_BT_SUCCESS </b> : on success; \n
 *          <b>  WICED_BT_ERROR   </b> : if an error occurred
 */
wiced_result_t wiced_bt_stack_deinit( void );

/**
* Initialize l2cap
*
* @return wiced_result_t
*/
wiced_result_t wiced_bt_l2c_module_init(void);

 /**
 * Initialize SMP.
 * Called by application to accept incoming pairing requests
 *
 * @result wiced_result_t
 */
wiced_result_t wiced_bt_smp_module_init(void);

/**
* Enable host based resolution
* This should be invoked in the BTM_ENABLED_EVT event
*/
wiced_result_t wiced_bt_init_resolution(void);


/**@} wicedbt_Framework */


#ifdef __cplusplus
}
#endif

#endif //__WICED_BT_STACK_H__
