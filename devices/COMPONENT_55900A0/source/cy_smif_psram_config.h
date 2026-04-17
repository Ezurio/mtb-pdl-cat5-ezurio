/*******************************************************************************
* File Name: cy_smif_psram_config.h
*
* Description:
* Provides declarations of the SMIF-device configuration.
*
********************************************************************************
* Copyright 2024 Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
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
********************************************************************************/

#ifndef CY_SMIF_PSRAM_CONFIG_H
#define CY_SMIF_PSRAM_CONFIG_H

#ifndef PSRAM_QUARD_READ_CMD
#define PSRAM_QUARD_READ_CMD                        0xEB
#endif /* PSRAM_QUARD_READ_CMD */

#ifndef PSRAM_QUARD_WRITE_CMD
#define PSRAM_QUARD_WRITE_CMD                       0x38
#endif /* PSRAM_QUARD_WRITE_CMD */

#ifndef PSRAM_ENTER_QUARD_MODE_CMD
#define PSRAM_ENTER_QUARD_MODE_CMD                  0x35
#endif /* PSRAM_ENTER_QUARD_MODE_CMD */

#ifndef PSRAM_EXIT_QUARD_MODE_CMD
#define PSRAM_EXIT_QUARD_MODE_CMD                   0xF5
#endif /* PSRAM_EXIT_QUARD_MODE_CMD */

#ifndef PSRAM_RESET_ENABLE_CMD
#define PSRAM_RESET_ENABLE_CMD                      0x66
#endif /* PSRAM_RESET_ENABLE_CMD */

#ifndef PSRAM_RESET_CMD
#define PSRAM_RESET_CMD                             0x99
#endif /* PSRAM_RESET_CMD */

#ifndef PSRAM_READ_ID_CMD
#define PSRAM_READ_ID_CMD                           0x9F
#endif /* PSRAM_READ_ID_CMD */

#ifndef PSRAM_KGD_VALUE
#define PSRAM_KGD_VALUE                             0x5D
#endif /* PSRAM_READ_ID_CMD */

#ifndef PSRAM_MANUFACTURE_ID_VALUE
#define PSRAM_MANUFACTURE_ID_VALUE                  0x0D
#endif /* PSRAM_MANUFACTURE_ID_VALUE */

#ifndef PSRAM_HALF_SLEEP_ENTRY_CMD
#define PSRAM_HALF_SLEEP_ENTRY_CMD                  0xC0
#endif /* PSRAM_HALF_SLEEP_ENTRY_CMD */

#ifndef PSRAM_HALF_SLEEP_ENTRY_EN
#define PSRAM_HALF_SLEEP_ENTRY_EN                   0x0
#endif /* PSRAM_HALF_SLEEP_ENTRY_EN */


#ifndef PSRAM_PARAM_SELECT_SETUP_DELAY
#define PSRAM_PARAM_SELECT_SETUP_DELAY              0x0
#endif /* PSRAM_PARAM_SELECT_SETUP_DELAY */

#ifndef PSRAM_PARAM_SELECT_HOLD_DELAY
#define PSRAM_PARAM_SELECT_HOLD_DELAY               0x1
#endif /* PSRAM_PARAM_SELECT_HOLD_DELAY */

#ifndef PSRAM_PARAM_DESELECT_DELAY
#define PSRAM_PARAM_DESELECT_DELAY                  0x0
#endif /* PSRAM_PARAM_DESELECT_DELAY */

#ifndef PSRAM_PARAM_MERGE_ENABLE
#define PSRAM_PARAM_MERGE_ENABLE                    0x0
#endif /* PSRAM_PARAM_MERGE_ENABLE */

#ifndef PSRAM_PARAM_MERGE_TIMEOUT
#define PSRAM_PARAM_MERGE_TIMEOUT                   0x0
#endif /* PSRAM_PARAM_MERGE_TIMEOUT */

#ifndef PSRAM_PARAM_TOTAL_TIMEOUT_ENABLE
#define PSRAM_PARAM_TOTAL_TIMEOUT_ENABLE            0x0
#endif /* PSRAM_PARAM_TOTAL_TIMEOUT_ENABLE */

#ifndef PSRAM_PARAM_TOTAL_TIMEOUT
#define PSRAM_PARAM_TOTAL_TIMEOUT                   0x0
#endif /* PSRAM_PARAM_TOTAL_TIMEOUT */

#ifndef PSRAM_PARAM_BASE_LATENCY
#define PSRAM_PARAM_BASE_LATENCY                    0x0
#endif /* PSRAM_PARAM_BASE_LATENCY */

#ifndef PSRAM_PARAM_SUBPAGE_SIZE
#define PSRAM_PARAM_SUBPAGE_SIZE                    0x0
#endif /* PSRAM_PARAM_SUBPAGE_SIZE */

#ifndef PSRAM_PARAM_SUBPAGE_NR
#define PSRAM_PARAM_SUBPAGE_NR                      0x1
#endif /* PSRAM_PARAM_SUBPAGE_NR */

#ifndef PSRAM_PARAM_SUBSEQ_BOUND_ENABLE
#define PSRAM_PARAM_SUBSEQ_BOUND_ENABLE             0x0
#endif /* PSRAM_PARAM_SUBSEQ_BOUND_ENABLE */

#ifndef PSRAM_PARAM_PRESENT_FIRST
#define PSRAM_PARAM_PRESENT_FIRST                   0x0
#endif /* PSRAM_PARAM_PRESENT_FIRST */

#ifndef PSRAM_PARAM_HALFSLEEP_EXIT_SETUPTIME_150US
#define PSRAM_PARAM_HALFSLEEP_EXIT_SETUPTIME_150US  0x96
#endif /* PSRAM_PARAM_HALFSLEEP_EXIT_SETUPTIME_150US */

#endif /*CY_SMIF_PSRAM_CONFIG_H*/
