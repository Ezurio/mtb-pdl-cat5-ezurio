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
/****************************************************************************
**
** Name:         wiced_data_types.h
**
** Description:  AIROC data types header file for VS2010 projects
**
** Copyright (c) Cypress Semiconductor
**
******************************************************************************/

#ifndef WICED_DATA_TYPES_H
#define WICED_DATA_TYPES_H

#include <stdint.h>
#include <string.h>

/**
 *  @ingroup     gentypes
 *
 *  @{
 */

#ifndef WICED_FALSE
#define WICED_FALSE 0   /**< AIROC false */
#endif // !WICED_FALSE
#ifndef WICED_TRUE
#define WICED_TRUE  1   /**< AIROC true */
#endif // !WICED_TRUE

#ifndef FALSE
#define FALSE 0         /**< false */
#endif

#ifndef TRUE
#define TRUE  1         /**< true */
#endif

#ifdef __ARM__
#define WICED_BT_STRUCT_PACKED  __packed() struct               /**< packed structure */
#define WICED_BT_UNION_PACKED  __packed() union                 /**< packed union */
#elif defined(TOOLCHAIN_gnu) || defined(COMPILER_GNU)
#define WICED_BT_STRUCT_PACKED struct __attribute__((packed))   /**< packed structure */
#define WICED_BT_UNION_PACKED  union  __attribute__((packed))   /**< packed union */
#else
#define WICED_BT_STRUCT_PACKED  struct                          /**< packed structure */
#define WICED_BT_UNION_PACKED   union                           /**< packed union */
#endif

/** Surpress Warnings */
#define WICED_SUPPRESS_WARNINGS(m) if((m)){;}

/* Suppress unused variable warning */
#ifndef UNUSED_VARIABLE
/** Unused Variable */
#define UNUSED_VARIABLE(x) /*@-noeffect@*/ ( (void)(x) ) /*@+noeffect@*/
#endif

/* To prevent complier to optimize with LDM and STM instructions */
#define WICED_MEMCPY(a, b, c)       memcpy((void*)(a), (const void*)(b), c)     /**< AIROC Memory copy*/
#define WICED_MEMSET(a, b, c)       memset((void*)(a), b, c)                    /**< AIROC Memory set */
#define WICED_MEMMOVE(a, b, c)      memmove((void*)(a), (const void*)(b), c)    /**< AIROC Memory move*/
#define WICED_MEMCMP(a, b, c)       memcmp((void*)(a), (const void*)(b), c)     /**< AIROC Memory compare*/

/** AIROC Boolean */
typedef unsigned int   wiced_bool_t;

/** Function prototypes to lock and unlock (typically using a mutex). The context
** pointer may be NULL, depending on implementation.
*/
typedef struct {
    void* p_lock_context;                           /**< lock context pointer */
    void (*pf_lock_func)(void * p_lock_context);    /**< Lock function pointer */
    void (*pf_unlock_func)(void * p_lock_context);  /**< Unlock function pointer */
}wiced_bt_lock_t;

 /**
  * Exception callback :
  *
  * Called by stack in case of unhandled exceptions and critical errors.
  *
  * @param[in] code    : Exception code
  * @param[in] msg     : Exception string
  * @param[in] p_tr    : Pointer to the data (based on the exception)
  *
  * @return void
  */
typedef void (*pf_wiced_exception)(uint16_t code, char* msg, void* ptr);
/**@} gentypes */
#endif
