################################################################################
# \file pdl-cat5.mk
#
# \brief
# Add pdl file paths to build environment.
#
################################################################################
# \copyright
# Copyright 2021-2022 Cypress Semiconductor Corporation (an Infineon company) or
# an affiliate of Cypress Semiconductor Corporation
#
# SPDX-License-Identifier: Apache-2.0
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
################################################################################

ifeq ($(WHICHFILE),true)
$(info Processing $(lastword $(MAKEFILE_LIST)))
endif

#
# Patch variables
#
CY_PDL_ROOT=$(SEARCH_mtb-pdl-cat5)

$(info DEVICE_COMPONENTS are $(DEVICE_COMPONENTS))

# Derive Chip-Name from Device Components
ifeq ($(filter 55900A0,$(DEVICE_COMPONENTS)), 55900A0)
    CHIP_NAME=55900A0
else ifeq ($(filter 55500,$(DEVICE_COMPONENTS)), 55500)
    CHIP_NAME=55500A1
else
    $(error Unknown Device Component reference: $(DEVICE_COMPONENTS))
endif

CHIP_PATCH_DIR_ANT=wlbga_iPA_dLNA_ANT0
ifeq ($(CHIP_NAME), $(filter $(CHIP_NAME), 55500A1 55900A0))
    ifeq ($(CHIP_ANT_SEL),SLNA_ANT0)
        CHIP_PATCH_DIR_ANT=wlbga_iPA_sLNA_ANT0
    else ifeq ($(CHIP_ANT_SEL),DLNA_BTANT)
        CHIP_PATCH_DIR_ANT=wlbga_iPA_dLNA_BTANT
    else
        CHIP_ANT_SEL=DLNA_ANT0
    endif
else
    CHIP_ANT_SEL=DLNA_ANT0
endif

ifeq ($(DIRECT_LOAD),0)
    $(info Build $(CHIP_NAME) for flash patch using $(CHIP_ANT_SEL))
    ifeq ($(CHIP_NAME),55900A0)
        ifeq ($(MEMORY_LAYOUT_SEL), f8_p2)
            FLASH_PATCH=flash_f8_p2
        else
            FLASH_PATCH=flash
        endif
    else
        FLASH_PATCH=flash
    endif
    CY_CORE_PATCH_DIR=$(CY_PDL_ROOT)/devices/COMPONENT_$(CHIP_NAME)/$(FLASH_PATCH)_patches/$(CHIP_PATCH_DIR_ANT)/$(LIFE_CYCLE_STATE)
    CY_CORE_PATCH=$(CY_CORE_PATCH_DIR)/patch.elf
    ifeq ($(CHIP_NAME),55900A0)
        ifeq (,$(filter NETXSECURE_WPA3,$(COMPONENTS)))
            CY_CORE_PATCH_SYMBOLS=$(CY_CORE_PATCH_DIR)/COMPONENT_NETXSECURE_ROM/patch.sym
        else
            CY_CORE_PATCH_SYMBOLS=$(CY_CORE_PATCH_DIR)/COMPONENT_NETXSECURE_WPA3/patch.sym
        endif
    endif
    CY_CORE_PATCH_CERT=$(CY_CORE_PATCH_DIR)/patch_cert.hex
    CY_CORE_PATCH_SEC=$(CY_CORE_PATCH_DIR)/patch_sec.bin
    CY_CORE_PATCH_SEC_XIP_MDH=$(CY_CORE_PATCH_DIR)/patch_full_mdh.bin
    CY_CORE_PATCH_FW=$(CY_CORE_PATCH_DIR)/patch_fw.bin
    CY_CORE_PATCH_DEFS=$(CY_PDL_ROOT)/devices/COMPONENT_$(CHIP_NAME)/source/platforms/$(CHIP_NAME).cflag
    #
    # Variables for pre-build and post-build processing
    #
    CY_CORE_PLATFORM_PATH=$(CY_PDL_ROOT)/devices/COMPONENT_$(CHIP_NAME)/source/platforms
    CY_CORE_HDF=$(CY_CORE_PLATFORM_PATH)/configdef$(CHIP_NAME).hdf
    CY_CORE_HCI_ID=$(CY_CORE_PLATFORM_PATH)/IDFILE.txt
    CY_CORE_CGSLIST+=$(CY_CORE_PLATFORM_PATH)/platform.cgs
    CY_CORE_BTP=$(CY_CORE_PLATFORM_PATH)/flash.btp
    #  CY_CORE_MINIDRIVER=$(CY_CORE_PLATFORM_PATH)/$(LIFE_CYCLE_STATE)_chiperase_flashpatch_loader.hex
    #  CY_CORE_MINIDRIVER=$(CY_CORE_PLATFORM_PATH)/$(LIFE_CYCLE_STATE)_sectorerase_flashpatch_loader.hex
    # Edge-protect-tools requires LCS:SM version of minidriver based on below override flag.
    ifeq ($(POST_BUILD_SECURE_IMAGE),1)
        CY_CORE_MINIDRIVER=$(CY_CORE_PLATFORM_PATH)/SM_sectorerase_flashpatch_loader.hex
    else
        CY_CORE_MINIDRIVER=$(CY_CORE_PLATFORM_PATH)/$(LIFE_CYCLE_STATE)_sectorerase_flashpatch_loader.hex
    endif

else

    $(info Build $(CHIP_NAME) for RAM patch using $(CHIP_ANT_SEL))
    CY_CORE_PATCH_DIR=$(CY_PDL_ROOT)/devices/COMPONENT_$(CHIP_NAME)/patches/$(CHIP_PATCH_DIR_ANT)/$(LIFE_CYCLE_STATE)
    CY_CORE_PATCH=$(CY_CORE_PATCH_DIR)/patch.elf
    ifeq ($(CHIP_NAME),55900A0)
        ifeq (,$(filter NETXSECURE_WPA3,$(COMPONENTS)))
            CY_CORE_PATCH_SYMBOLS=$(CY_CORE_PATCH_DIR)/COMPONENT_NETXSECURE_ROM/patch.sym
        else
            CY_CORE_PATCH_SYMBOLS=$(CY_CORE_PATCH_DIR)/COMPONENT_NETXSECURE_WPA3/patch.sym
        endif
    endif
    CY_CORE_PATCH_CERT=$(CY_CORE_PATCH_DIR)/patch_cert.hex
    CY_CORE_PATCH_SEC=$(CY_CORE_PATCH_DIR)/patch_sec.bin
    CY_CORE_PATCH_SEC_HEX=$(CY_CORE_PATCH_DIR)/patch_sec.hex
    CY_CORE_PATCH_SEC_XIP_MDH=$(CY_CORE_PATCH_DIR)/patch_sec_xip.mdh
    CY_CORE_PATCH_FW=$(CY_CORE_PATCH_DIR)/patch_fw.bin
    CY_CORE_PATCH_DEFS=$(CY_PDL_ROOT)/devices/COMPONENT_$(CHIP_NAME)/source/platforms/$(CHIP_NAME).cflag
    #
    # Variables for pre-build and post-build processing
    #
    CY_CORE_PLATFORM_PATH=$(CY_PDL_ROOT)/devices/COMPONENT_$(CHIP_NAME)/source/platforms
    CY_CORE_HDF=$(CY_CORE_PLATFORM_PATH)/configdef$(CHIP_NAME).hdf
    CY_CORE_HCI_ID=$(CY_CORE_PLATFORM_PATH)/IDFILE.txt
    CY_CORE_CGSLIST+=$(CY_CORE_PLATFORM_PATH)/platform.cgs
    CY_CORE_BTP=$(CY_CORE_PLATFORM_PATH)/ram.btp
    ifeq ($(DIRECT_LOAD),2)
        CY_CORE_MINIDRIVER=$(CY_CORE_PLATFORM_PATH)/$(LIFE_CYCLE_STATE)_hci_psram_loader.hex
    endif

endif

CY_CORE_LD_DEFS+=NUM_PATCH_ENTRIES=0

define extract_btp_file_value
$(patsubst $1=%,%,$(filter $1%,$2))
endef

# these make targets do not need this data and don't work if importing an app
# that has not yet run make getlibs, so skip it
ifeq ($(filter import_deps getlibs get_app_info,$(MAKECMDGOALS)),)

# split up btp file into "x=y" text
CY_BT_FILE_TEXT:=$(shell cat -e $(CY_CORE_BTP))
CY_BT_FILE_TEXT:=$(subst $(MTB__SPACE),,$(CY_BT_FILE_TEXT))
CY_BT_FILE_TEXT:=$(subst ^M,,$(CY_BT_FILE_TEXT))
CY_BT_FILE_TEXT:=$(patsubst %$(MTB__NEWLINE),% ,$(CY_BT_FILE_TEXT))
CY_BT_FILE_TEXT:=$(subst $$,$(MTB__SPACE),$(CY_BT_FILE_TEXT))

ifeq ($(CY_BT_FILE_TEXT),)
$(error Failed to parse BTP variables from file: $(CY_CORE_BTP))
endif

SS_LOCATION = $(call extract_btp_file_value,DLConfigSSLocation,$(CY_BT_FILE_TEXT))
VS_LOCATION = $(call extract_btp_file_value,DLConfigVSLocation,$(CY_BT_FILE_TEXT))
VS_LENGTH = $(call extract_btp_file_value,DLConfigVSLength,$(CY_BT_FILE_TEXT))
DS_LOCATION = $(call extract_btp_file_value,ConfigDSLocation,$(CY_BT_FILE_TEXT))

PLATFORM_DIRECT_LOAD_BASE_ADDR = $(SS_LOCATION)

endif # end filter import_deps getlibs get_app_info
