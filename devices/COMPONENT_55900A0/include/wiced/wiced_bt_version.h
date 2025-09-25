/*
 * $ Copyright 2021-YEAR Cypress Semiconductor $
 */


#ifndef __WICED_BT_VERSION_H__
#define __WICED_BT_VERSION_H__


#define WICED_BTSTACK_VERSION_MAJOR    4      /**< Stack Major version */
#define WICED_BTSTACK_VERSION_MINOR    1      /**< Stack Minor version */
#define WICED_BTSTACK_VERSION_PATCH    1      /**< Stack Patch version */

/** Building the btstack version */
#define BTSTACK_VERSION_BUILD(major, minor, patch) ((((major)&0xff) << 24) | (((minor)&0xff) << 16) | ((patch)&0xffff))
/** Stack version macro for use in BTSDK*/
#define BTSTACK_VERSION                                                                                                \
    BTSTACK_VERSION_BUILD(WICED_BTSTACK_VERSION_MAJOR, WICED_BTSTACK_VERSION_MINOR, WICED_BTSTACK_VERSION_PATCH)
/** Stack version macro for use in BTSDK, backward compatibility */
#define BTSTACK_VER BTSTACK_VERSION


#endif //__WICED_BT_VERSION_H__
