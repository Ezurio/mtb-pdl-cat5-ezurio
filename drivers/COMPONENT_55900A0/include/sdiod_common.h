//==================================================================================================
//                        THIS INFORMATION IS PROPRIETARY TO INFINEON
//--------------------------------------------------------------------------------------------------
//                               Copyright (c) 2022 Infineon Technologies.
//                                      ALL RIGHTS RESERVED
//==================================================================================================
//! \file
//!
//! SDIO CTSS Device Driver API
//
//==================================================================================================

#ifndef _SDIOD_COMMON_H_
#define _SDIOD_COMMON_H_

#ifdef CY_USING_HAL
#include <stdint.h>
#endif

//==================================================================================================
// Public Types
//==================================================================================================

//! SDIOD status code
typedef enum
{
    SDIOD_STATUS_SUCCESS,
    SDIOD_STATUS_ASYNC_IN_PROGRESS,
    SDIOD_STATUS_ASYNC_COMPLETED,
    SDIOD_STATUS_RX_MORE_DATA,
    SDIOD_STATUS_ERR_NOT_SUPPORTED,  /* Not supported error */
    SDIOD_STATUS_ERR_IO_NOT_READY,   /* IO not ready */
    SDIOD_STATUS_ERR_INVALID_PARAM,  /* The provided parameter is not valid */
    SDIOD_STATUS_ERR_OUT_OF_MEMORY,  /* Out of memory error */
    SDIOD_STATUS_ERR_BUSY,           /* Driver is busy */
    SDIOD_STATUS_ERR_TRANSPORT,      /* Hardware Bus error */
    SDIOD_STATUS_ERR_UNKNOWN,
    SDIOD_STATUS_ERR_HW_INIT_FAILED, /* SDIOD Hardware Init Failed */
} sdiod_status_t;

//! SDIOD event code
typedef enum
{
    SDIOD_EVENT_CODE_FIRST,
    SDIOD_EVENT_CODE_HOST_INFO = SDIOD_EVENT_CODE_FIRST,
    SDIOD_EVENT_CODE_RX_DONE,
    SDIOD_EVENT_CODE_TX_DONE,
    SDIOD_EVENT_CODE_RX_ERROR,
    SDIOD_EVENT_CODE_TX_ERROR,
    SDIOD_EVENT_CODE_BUS_ERROR,
    SDIOD_EVENT_CODE_MAX,
} sdiod_event_code_t;

//--------------------------------------------------
//! SDIOD Frame Format
//--------------------------------------------------
//! F2 basic frame header (Hardware Tag)
typedef struct
{
    UINT32 frame_len  : 16; // includes frame header itself
    UINT32 checksum   : 16;
} sdiod_f2_frame_hdr_t;

//! F2 Tx Frame Header = F2 basic frame header
typedef sdiod_f2_frame_hdr_t sdiod_f2_tx_frame_hdr_t;

//! F3 basic frame header (Type-A packet header)
typedef struct
{
    UINT32 pkt_len    : 24; // includes frame header itself
    UINT32 service_id : 8;
} sdiod_f3_frame_hdr_t;

//! F3 Tx frame header = F3 basic frame header
typedef sdiod_f3_frame_hdr_t sdiod_f3_tx_frame_hdr_t;

typedef union
{
    sdiod_f2_tx_frame_hdr_t tx_hdr_f2;
    sdiod_f3_tx_frame_hdr_t tx_hdr_f3;
} sdiod_tx_frame_hdr_t;

#define SDIOD_DMA_DESC_LEN                (16u)
#define NUMBER_OF_XMT_DESCS               (4u)
#define NUMBER_OF_RCV_DESCS               (2u)
//! DMA descriptor align
#define SDIOD_DMA_DESC_ALIGN              (0x10u)
#define SDIOD_DMA_DESCRIPTORS_BUFFER_SIZE (SDIOD_DMA_DESC_LEN * (NUMBER_OF_XMT_DESCS + NUMBER_OF_RCV_DESCS) \
                                           + SDIOD_DMA_DESC_ALIGN + sizeof(sdiod_tx_frame_hdr_t))
typedef struct
{
    BYTE dma_descs_data[SDIOD_DMA_DESCRIPTORS_BUFFER_SIZE];
} sdiod_dma_descs_buf_t;

//--------------------------------------------------
//! SDIOD RX frame format
//--------------------------------------------------
//! DMA Receive Frame Status Register length
#define SDIOD_DMA_RX_HDR_LEN  (4u)

//! F2 Rx frame header = local DMA header + F2 basic frame header
typedef struct
{
    UINT8 dma_rx_hdr[SDIOD_DMA_RX_HDR_LEN]; // Filled by local Rx DMA engine
    sdiod_f2_frame_hdr_t frame_hdr;
} sdiod_f2_rx_frame_hdr_t;

//! F3 Rx frame header = local DMA header + F3 basic frame header
typedef struct
{
    UINT8 dma_rx_hdr[SDIOD_DMA_RX_HDR_LEN]; // Filled by local Rx DMA engine
    sdiod_f3_frame_hdr_t frame_hdr;
} sdiod_f3_rx_frame_hdr_t;

//! SDIOD event callback function
typedef void (*sdiod_event_cb_t)(sdiod_event_code_t event_code, void *event_data);

#endif //_SDIOD_COMMON_H_
