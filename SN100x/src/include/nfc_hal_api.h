/******************************************************************************
 *
 *  Copyright (C) 2012-2014 Broadcom Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at:
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ******************************************************************************/
/******************************************************************************
 *
 *  The original Work has been changed by NXP.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  Copyright 2020 NXP
 *
 ******************************************************************************/
/******************************************************************************
 *
 *  NFC Hardware Abstraction Layer API
 *
 ******************************************************************************/
#ifndef NFC_HAL_API_H
#define NFC_HAL_API_H
#include <hardware/nfc.h>
#include "data_types.h"
#include "nfc_hal_target.h"
#if (NXP_EXTNS == TRUE)
#include <vendor/nxp/hardware/nfc/2.0/types.h>
namespace vendor {
namespace nxp {
namespace hardware {
namespace nfc {
namespace V2_0 {
struct INqNfc;
} } } } }
#endif

enum NfcHalStatus : uint8_t {
    HAL_NFC_STATUS_RESTART = 0x30,
    HAL_NFC_HCI_NV_RESET = 0x40,
};

enum NfcHalFwUpdateStatus : uint8_t {
    HAL_NFC_FW_UPDATE_INVALID = 0x00,
    HAL_NFC_FW_UPDATE_START,
    HAL_NFC_FW_UPDATE_SCUCCESS,
    HAL_NFC_FW_UPDATE_FAILED,
};

typedef uint8_t tHAL_NFC_STATUS;
typedef void(tHAL_NFC_STATUS_CBACK)(tHAL_NFC_STATUS status);
typedef void(tHAL_NFC_CBACK)(uint8_t event, tHAL_NFC_STATUS status);
typedef void(tHAL_NFC_DATA_CBACK)(uint16_t data_len, uint8_t* p_data);

/*******************************************************************************
** tHAL_NFC_ENTRY HAL entry-point lookup table
*******************************************************************************/

typedef void(tHAL_API_INITIALIZE)(void);
typedef void(tHAL_API_TERMINATE)(void);
typedef void(tHAL_API_OPEN)(tHAL_NFC_CBACK* p_hal_cback,
                            tHAL_NFC_DATA_CBACK* p_data_cback);
typedef void(tHAL_API_CLOSE)(void);
typedef void(tHAL_API_CORE_INITIALIZED)(uint16_t data_len,
                                        uint8_t* p_core_init_rsp_params);
typedef void(tHAL_API_WRITE)(uint16_t data_len, uint8_t* p_data);
typedef bool(tHAL_API_PREDISCOVER)(void);
typedef void(tHAL_API_CONTROL_GRANTED)(void);
typedef void(tHAL_API_POWER_CYCLE)(void);
typedef uint8_t(tHAL_API_GET_MAX_NFCEE)(void);
#if (NXP_EXTNS == TRUE)
typedef int(tHAL_API_IOCTL)(long arg, void* p_data);
typedef int(tHAL_API_GET_FW_DWNLD_FLAG)(uint8_t* fwDnldRequest);
#endif
typedef bool(tHAL_API_SET_NXP_TRANSIT_CONFIG)(char* strval);

typedef struct {
  tHAL_API_INITIALIZE* initialize;
  tHAL_API_TERMINATE* terminate;
  tHAL_API_OPEN* open;
  tHAL_API_CLOSE* close;
  tHAL_API_CORE_INITIALIZED* core_initialized;
  tHAL_API_WRITE* write;
  tHAL_API_PREDISCOVER* prediscover;
  tHAL_API_CONTROL_GRANTED* control_granted;
  tHAL_API_POWER_CYCLE* power_cycle;
  tHAL_API_GET_MAX_NFCEE* get_max_ee;
#if (NXP_EXTNS == TRUE)
  tHAL_API_IOCTL* ioctl;
  tHAL_API_GET_FW_DWNLD_FLAG* check_fw_dwnld_flag;
#endif
  tHAL_API_SET_NXP_TRANSIT_CONFIG* set_transit_config;

} tHAL_NFC_ENTRY;

/*******************************************************************************
** HAL API Function Prototypes
*******************************************************************************/

#endif /* NFC_HAL_API_H  */
