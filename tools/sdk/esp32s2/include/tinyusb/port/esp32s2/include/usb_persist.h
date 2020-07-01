// Copyright 2020 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * USB Persistence API
 * */
typedef enum {
    REBOOT_NO_PERSIST,
    REBOOT_PERSIST,
    REBOOT_BOOTLOADER,
    REBOOT_BOOTLOADER_DFU,
    REBOOT_TYPE_MAX
} reboot_type_t;

/*
 * Init Persistence reboot system
 * */
void tinyusb_persist_init(void);

/*
 * Enable Persistence reboot
 * 
 * Note: Persistence should be enabled when ONLY CDC and DFU are being used
 * */
void tinyusb_persist_set_enable(bool enable);

/*
 * Set Reboot mode. Call before esp_reboot();
 * */
void tinyusb_persist_set_mode(reboot_type_t mode);

#ifdef __cplusplus
}
#endif