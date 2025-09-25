/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */

/** @file
 *
 * AIROC Application pre init configuration Interface
 *
 * This is the configuration for below HCI firmware and applicable only when
 * application and firmware shares the processor resources.
 *
 * The configuration Interface allows application to configure below:
 *    1. ACL buffer configuration - Size and number of ACL buffers for controller ACL process.
 *    2. Dynamic memory configuration - Number of pools and each pool size and buffer count of the pool
 *    3. Application entry - Application function entry to be called once firmware initialized
 *    4. Number of LE connections - Max number of LE connections
 *    5. Maximum Frequency Support for H1CP
 *
 */

#pragma once

#include "wiced.h"

#define BLE_ACL_BUF_OVERHEAD                    12
#define BLE_ISO_BUF_OVERHEAD                    20
#define DEFAULT_APPLICATION_THREAD_STACK_SIZE   (896 * 4)

typedef void (*wiced_app_entry_fn_t)(void );

//Todo: Yogesh fix wiced_data_types.h to take care PACK for different compilers.
// John is planning to separate compiler related from brcm_fw_types.h so that AIROC can include separated defines.
#ifdef __ARMCC_VERSION
    #if __ARMCC_VERSION >= 6010050
        #ifndef STRUCT_PACKED
            #define STRUCT_PACKED           __unaligned struct __attribute__((packed))
        #endif
    #else
        #ifndef STRUCT_PACKED
            #define STRUCT_PACKED           __packed struct
        #endif
    #endif
#else
    #ifdef __GNUC__
        #define STRUCT_PACKED       struct __attribute__((packed))
    #endif
#endif

typedef STRUCT_PACKED
{
    //! Used to determine the size of the L2CAP segments contained in (downstream) ACL Data Packets.
    uint16_t host_claim_host_to_device_size;

    //! The size of buffers for host to device ACL traffic.
    uint16_t host_to_device_size;

    //! max size of the L2CAP segment contained in an upstream ACL data packet.
    uint16_t device_claim_device_to_host_size;

    //! The size of buffers for device to host ACL traffic = 4ByteAligned(device_claim_device_to_host_size + bufferOverhead)
    uint16_t device_to_host_size;

    //! The total number of HCI ACL Data Packets that can be stored in the data buffers of the Controller.
    uint8_t host_claim_host_to_device_count;

    //! The number of buffers for host to device ACL traffic.
    uint8_t host_to_device_count;

    //! The number of buffers for device to host ACL traffic.
    uint8_t device_to_host_count;
} wiced_bt_config_acl_pool_t;

typedef STRUCT_PACKED
{
    //! The size of buffers for host to device HCI ISO data packets
    //! (does not include the space for overheads).
    uint16_t host_claim_host_to_device_size;

    //! The size of buffers for host to device HCI ISO data packets
    //! (includes the space for overheads).
    uint16_t host_to_device_size;

    //! The size of buffers for device to host HCI ISO data packets
    //! (does not include the space for overheads).
    uint16_t device_claim_device_to_host_size;

    //! The size of buffers for device to host HCI ISO data packets
    //! (includes the space for overheads).
    uint16_t device_to_host_size;

    //! The number of buffers for host to device HCI ISO data packets.
    uint8_t host_to_device_count;

    //! The number of buffers for device to host HCI ISO data packets.
    uint8_t device_to_host_count;

    //! The size of buffers for saving ISO PDUs to be sent/received OTA
    //! (includes the space for overheads).
    uint16_t device_iso_pdu_size;

    //! The number of buffers used for saving ISO PDUs to be sent OTA.
    uint8_t device_tx_pdu_count;

    //! The number of buffers used for saving ISO PDUs received OTA.
    uint8_t device_rx_pdu_count;

    //! The size of ring buffer control block element used for saving info related to
    //! ISO PDUs to be sent/received OTA (includes the space for overheads).
    uint16_t device_iso_ring_buff_element_size;

    //!The maximum number of ring buffer control block elements used
    //! for saving info related to ISO PDUs to be sent/received OTA.
    uint8_t device_iso_ring_buff_element_count;

} wiced_bt_config_iso_pools_t;

typedef STRUCT_PACKED
{
    // The size of each block in this pool.
    uint16_t size;

    // The number of blocks in this pool.
    uint8_t count;

    // The number of blocks in this pool that are reserved for critical paths,
    // where firmware cannot recover from the state if it cannot allocate memory.
    uint8_t die_reserve;
} wiced_dynamic_memory_pool_entry_t;

typedef STRUCT_PACKED
{
#ifdef __GNUC__
    #ifdef CYW55560A0
        #if (DYNAMIC_MEMORY_NUM_POOLS != 5)
            #undef DYNAMIC_MEMORY_NUM_POOLS
            #define DYNAMIC_MEMORY_NUM_POOLS    5
        #endif

        #ifndef ULP_ENABLE
            #define ULP_ENABLE WICED_TRUE
        #endif
        #ifndef LE_ISOCH_CONN
            #define LE_ISOCH_CONN WICED_TRUE
        #endif
    #endif
#endif

#define MAX_DYNAMIC_MEMORY_NUM_POOLS (DYNAMIC_MEMORY_NUM_POOLS + 1)

    // Todo: Let me know whether we can remove below explanation or keep it. Concern is stating names like
    // .ags, .cgx. leads to in depth of explanation of what are those.

    // The number of pools that are to be created from the general pools.  The default value is
    // DEFAULT_FW_DYNAMIC_MEMORY_NUM_POOLS, but we reserve an extra pool control block, in case we need to add
    // a block size category from configuration data.  Unless we need to add a new block size
    // category pool, config data (.ags, .cgx) should probably just use DYNAMIC_MEMORY_NUM_POOLS
    // as a named value for this field.
    uint8_t num_pools;

    //$ DEFINE num_pools: DYNAMIC_MEMORY_NUM_POOLS

    // Info on the size, count, and blocks reserved for critical path allocation in each pool.
    wiced_dynamic_memory_pool_entry_t pools[MAX_DYNAMIC_MEMORY_NUM_POOLS];
} wiced_dynamic_memory_pools_cfg_t;

typedef STRUCT_PACKED
{
    wiced_bt_config_acl_pool_t          acl_config;             /* ACL configuration */

#if ULP_ENABLE
    wiced_bt_config_acl_pool_t          ble_acl_config;         /* LE ACL configuration */
#endif

    wiced_dynamic_memory_pools_cfg_t    dynamic_mem_config;     /* dynamic memory configuration */

    wiced_app_entry_fn_t                wiced_app_entry_fn;     /* AIROC application function entry */
    uint32_t                            app_thread_stack_size;  /* application thread stack size */

    /* AIROC app scatter load information*/
    void                                *app_iram_bss_begin;
    uint32_t                            app_iram_bss_length;
    void                                *app_iram_data_begin;
    uint32_t                            app_iram_data_length;
    void                                *app_irom_data_begin;

    uint8_t                             ble_con_max;            /* Max number LE connection */

    uint8_t                             ble_rl_max;          /* Max size LE resolving list */
#if defined(ULP_ENABLE) && defined(LE_ISOCH_CONN)
    /* LE ISO config */
    wiced_bt_config_iso_pools_t         iso_buf_cfg;
#endif

    /* BR Audio config */
    uint8_t                             enable_br_audio;
    void                                *p_br_audio_cfg;

    /* LPO source selection and max frequency enablement */
    uint8_t                              clock_config_sel_max_freq;
    //[0] - enable_max_freq, [1] - reserved, [3-2] - hfo_option_sel, [6-4] - lpo_src_sel, [7] - reserved
    //lpo_src_sel 1:-iLPO1, 2:-iLPO2, 3:-LHL_XTAL_IN, 4:-eLPO_IN
    //hfo_option_sel 0:Invalid, 1:XTAL, 2:TCXO, 3: Reserved
}wiced_pre_init_cfg_t;

void wiced_register_pre_init_cfg (const wiced_pre_init_cfg_t *p_cfg);
