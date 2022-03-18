#include "canbus_util.h"

uint8_t *array_dup(uint8_t *src, uint16_t size) {
    uint8_t *result = calloc(sizeof (uint8_t), size);
    memcpy(result, src, size);
    return result;
}

uint8_t* make_voltage_frame(uint16_t batteryVoltage, uint16_t batteryCurrent,
        uint16_t batteryTemp) {
    uint16_t frame[] = {batteryVoltage, batteryCurrent, batteryTemp};
    return array_dup((uint8_t*) frame, sizeof (frame));
}
