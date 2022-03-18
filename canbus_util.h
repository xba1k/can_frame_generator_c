#ifndef CANBUS_UTIL_H
#define CANBUS_UTIL_H

#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/param.h>

#define SI_CHARGE_PARAMS_FRAME 0x351
#define SI_VOLTAGE_FRAME 0x356
#define SI_SOC_FRAME 0x355
#define SI_ID_FRAME 0x35F
#define SI_NAME_FRAME 0x35E
#define SI_FAULT_FRAME 0x35A

#define MAX_DATA_LEN 8

#ifdef __cplusplus
extern "C" {
#endif

uint8_t *make_voltage_frame(uint16_t batteryVoltage, uint16_t batteryCurrent, uint16_t batteryTemp);
uint8_t *make_name_frame(char *name);

#ifdef __cplusplus
}
#endif

#endif /* CANBUS_UTIL_H */

