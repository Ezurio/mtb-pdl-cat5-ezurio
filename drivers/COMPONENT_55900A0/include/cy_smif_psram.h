/*******************************************************************************
*
* THIS INFORMATION IS PROPRIETARY TO INFINEON TECHNOLOGIES
*
* ------------------------------------------------------------------------------
*
* Copyright (c) 2022 Infineon Technologies
*
*          ALL RIGHTS RESERVED
*
********************************************************************************
*
* File Name: cy_smif_psram.h
*
*******************************************************************************/
#ifndef _CY_SMIF_PSRAM_H_
#define _CY_SMIF_PSRAM_H_

/**
*
* This structure specifies SMIF parameters for PSRAM device
*
*/
typedef struct
{
    UINT8 deSelectDelay;          /* SMIF DESELECT_DELAY (0 to 7): Specifies the minimum duration of SPI deselection ("spi_select_out[]" is high/'1') in between SPI transfers */
    UINT8 selectSetupDelay;       /* SMIF SELECT_SETUP_DELAY (0 to 3): Specifies the duration between "spi_select_out[]" activating (going low) to the first "spi_clk_out" rising edge */
    UINT8 selectHoldDelay;        /* SMIF SELECT_HOLD_DELAY (0 to 3)(default:1): Specifies the duration between the last "spi_clk_out" falling edge and "spi_select_out[]" deactivating (going high) */
    UINT8 mergeEnable;            /* SMIF MERGE_EN: Continuous transfer merge enable. 0 to disable, 1 to enable */
    UINT8 mergeTimeout;           /* SMIF MERGE_TIMEOUT (0 to 4): Continuous transfer merge timeout in clk_mem cycles. This limits the standby time of the memory interface */
    UINT8 totalTimeoutEnable;     /* SMIF TOTAL_TIMEOUT_EN: Total transfer timeout enable. 0 to disable, 1 to enable */
    UINT16 totalTimeout;          /* SMIF TOTAL_TIMEOUT: Total transfer timeout in clk_mem cycles. 0x00 to 0x7FFF */
    UINT8 baseLatency;            /* SMIF SIZE5 (0 to 31): Number of base latency cycles (minus 1) */
    UINT8 subPageSize;            /* SMIF SUB_PAGE_SIZE (0 to 4): corresponds to (16 to 128 bytes): Specifies the size of a memory sub page */
    UINT8 subPageNr;              /* SMIF SUB_PAGE_NR (0 to 4)(default:1): corresponds to (1x to 8x  SUB_PAGE_SIZE): Specifies the number of sub pages per page. */
    UINT8 subSeqBoundEn;          /* SMIF SUBSEQ_BOUND_EN: Enable subsequent page boundary latency cycles. 0 to disable, 1 to enable */
    UINT8 presentFirst;           /* SMIF PRESENT: Presence of first page boundary latency cycles. 0- not present, 1- present */
    UINT16 halfSleepExitSetupTime;/* SMIF HALFSLEEP_EXIT_SETUP_TIME: Half Sleep Exit CE# low to CLK setup time */
} cy_smif_psram_cfg_params_t;

/**
*
* This structure specifies configuration of PSRAM device
*
*/
typedef struct
{
    UINT8 readIdCmd;              /* PSRAM read ID, as per APS6404L- 0x9F */
    UINT8 manufId;                /* Manufacture ID,  as per APS6404L- 0x0D */
    UINT8 knownGoodDie;           /* Known good die value, as per APS6404L- 0x5D */
    UINT8 quadReadCmd;            /* Memory read command in Quad mode, as per APS6404L- 0xEB */
    UINT8 quadWriteCmd;           /* Memory write command in Quad mode, as per APS6404L- 0x38 */
    UINT8 resetEnableCmd;         /* Reset enable command, as per APS6404L- 0x66 */
    UINT8 resetCmd;               /* Reset command, as per APS6404L- 0x99 */
    UINT8 halfSleepEntryEnable;   /* Half sleep entry enable, 0x01 to enable; 0x00 to disable */
    UINT8 halfSleepEntryCmd;      /* Half sleep entry command, as per APS6404L- 0xC0 */
    cy_smif_psram_cfg_params_t smifParams;
} cy_smif_psram_device_cfg_t;

/**
*
* This structure specifies boundaries text and data section of PSRAM device
* Note: The addresses as well as lenghts must be 32 byte aligned.
*/
typedef struct
{
    UINT32 startCode;           /* Start of code section */
    UINT32 lenCode;             /* Length of code section */
    UINT32 startData;           /* Start of data section */
    UINT32 lenData;             /* Length of data section */
} cy_smif_psram_mem_params_t;

/**
* Result codes for PSRAM deinitialization operation.
*/
typedef enum
{
    CY_SMIF_PSRAM_DEINIT_SUCCESS = 0,         /* PSRAM deinitialization completed successfully */
    CY_SMIF_PSRAM_DEINIT_ERR_FLASH_DETECTED,  /* Deinitialization failed: FLASH device detected on pads */
    CY_SMIF_PSRAM_DEINIT_ERR_DEINIT_DEVICE,   /* Deinitialization failed: Error during PSRAM device deinitialization */
} cy_smif_psram_deinit_result_t;

#endif //_CY_SMIF_PSRAM_H_
