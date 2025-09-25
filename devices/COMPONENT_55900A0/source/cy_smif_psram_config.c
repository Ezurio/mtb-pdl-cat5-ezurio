/***************************************************************************//**
* \file cy_smif_psram_config.c
* \version 1.0
*
* This file specifies the structure for core and peripheral block HW base
* addresses, versions, and parameters.
*
********************************************************************************
* \copyright
* Copyright 2024 Cypress Semiconductor Corporation
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

#include "cy_pdl_wrapper.h"
#include "cy_smif_psram.h"
#include "cy_smif_psram_config.h"

#if USE_PSRAM

cy_smif_psram_device_cfg_t smifPsramConfig =
{
	.readIdCmd = PSRAM_READ_ID_CMD,
	.manufId = PSRAM_MANUFACTURE_ID_VALUE,
	.knownGoodDie = PSRAM_KGD_VALUE,
	.quadReadCmd = PSRAM_QUARD_READ_CMD,
	.quadWriteCmd = PSRAM_QUARD_WRITE_CMD,
	.resetEnableCmd = PSRAM_RESET_ENABLE_CMD,
	.resetCmd = PSRAM_RESET_CMD,
	.halfSleepEntryEnable = PSRAM_HALF_SLEEP_ENTRY_EN,
	.halfSleepEntryCmd = PSRAM_HALF_SLEEP_ENTRY_CMD,
	.smifParams.deSelectDelay = PSRAM_PARAM_DESELECT_DELAY,
	.smifParams.selectSetupDelay = PSRAM_PARAM_SELECT_SETUP_DELAY,
	.smifParams.selectHoldDelay = PSRAM_PARAM_SELECT_HOLD_DELAY,
	.smifParams.mergeEnable = PSRAM_PARAM_MERGE_ENABLE,
	.smifParams.mergeTimeout = PSRAM_PARAM_MERGE_TIMEOUT,
	.smifParams.totalTimeoutEnable = PSRAM_PARAM_TOTAL_TIMEOUT_ENABLE,
	.smifParams.totalTimeout = PSRAM_PARAM_TOTAL_TIMEOUT,
	.smifParams.baseLatency = PSRAM_PARAM_BASE_LATENCY,
	.smifParams.subPageSize = PSRAM_PARAM_SUBPAGE_SIZE,
	.smifParams.subPageNr = PSRAM_PARAM_SUBPAGE_NR,
	.smifParams.subSeqBoundEn = PSRAM_PARAM_SUBSEQ_BOUND_ENABLE,
	.smifParams.presentFirst = PSRAM_PARAM_PRESENT_FIRST,
};


#if defined (__ARMCC_VERSION)
extern char Image$$PSRAM$$Base[];
extern char Image$$PSRAM_DATA$$Base[];
extern int  Image$$PSRAM$$Length;
extern int  Image$$PSRAM_DATA$$Length;
/* pointer to data source within Skip Block config record */
/* note that for ARM toolchain there is a Skip Block for psram code and another for data */
uint8_t *app_psram_data_skip_block_source = (uint8_t *)0x87654321;
#elif defined(__GNUC__)
extern void* app_psram_begin;
extern void* app_psram_data_begin;
extern void* app_psram_end;
#endif
#define ROUND_UP(x,y) ((x+(y-1)) & ~(y-1))

/* pointer to data source within Skip Block config record */
uint8_t *app_psram_skip_block_source = (uint8_t *)0x12345678;

uint8_t thread_ap_smif_psram_Init(cy_smif_psram_device_cfg_t * psramCfg);
BOOL32 thread_ap_smif_psram_ConfigureMemoryRegions(cy_smif_psram_mem_params_t * cfg);

#endif /* USE_PSRAM */

__attribute__((section(".cy_ramfunc"))) void cy_smif_psram_config()
{
#if USE_PSRAM
#if defined (__ARMCC_VERSION)
    uint8_t *p_app_psram_begin = (uint8_t *)&Image$$PSRAM$$Base[0];
    uint8_t *p_app_psram_data_begin = (uint8_t *)&Image$$PSRAM_DATA$$Base[0];
    uint32_t app_psram_code_len = (uint32_t)&Image$$PSRAM$$Length;
    uint32_t app_psram_data_len = (uint32_t)&Image$$PSRAM_DATA$$Length;
    uint32_t app_psram_len = app_psram_code_len + app_psram_data_len;
#elif defined(__GNUC__)
    uint8_t *p_app_psram_begin = (uint8_t *)&app_psram_begin;
    uint8_t *p_app_psram_data_begin = (uint8_t *)&app_psram_data_begin;
    uint8_t *p_app_psram_end = (uint8_t *)&app_psram_end;
    uint32_t app_psram_code_len = p_app_psram_data_begin - p_app_psram_begin;
    uint32_t app_psram_data_len = p_app_psram_end - p_app_psram_data_begin;
    uint32_t app_psram_len = p_app_psram_end - p_app_psram_begin;
#endif

    cy_smif_psram_mem_params_t psramMemCfg ;

    if (app_psram_len > 0)
    {
        psramMemCfg.startCode = (uint32_t)p_app_psram_begin;
        psramMemCfg.lenCode = ROUND_UP(app_psram_code_len,32);
        psramMemCfg.startData = (uint32_t)p_app_psram_data_begin;
        psramMemCfg.lenData = ROUND_UP(app_psram_data_len,32);

        thread_ap_smif_psram_Init(&smifPsramConfig);
#ifdef ENABLE_MEMCPY
#if defined (__ARMCC_VERSION)
        memcpy(p_app_psram_begin, app_psram_skip_block_source, app_psram_code_len);
        memcpy(p_app_psram_data_begin, app_psram_data_skip_block_source, app_psram_data_len);
#elif defined(__GNUC__)
        memcpy(p_app_psram_begin, app_psram_skip_block_source, app_psram_len);
#endif
#endif /* ENABLE_MEMCPY */
        thread_ap_smif_psram_ConfigureMemoryRegions(&psramMemCfg);
    }
#endif /* USE_PSRAM */
}
/* [] END OF FILE */
