/*
 * st7066u_hw.c
 *
 *  Created on: 11 oct. 2024
 *      Author: Ludo
 */

#include "st7066u_hw.h"

#ifndef ST7066U_DRIVER_DISABLE_FLAGS_FILE
#include "st7066u_driver_flags.h"
#endif
#include "st7066u.h"
#include "types.h"

#ifndef ST7066U_DRIVER_DISABLE

/*******************************************************************/
ST7066U_status_t __attribute__((weak)) ST7066U_HW_init(void) {
    // Local variables.
    ST7066U_status_t status = ST7066U_SUCCESS;
    /* To be implemented */
    return status;
}

/*******************************************************************/
ST7066U_status_t __attribute__((weak)) ST7066U_HW_de_init(void) {
    // Local variables.
    ST7066U_status_t status = ST7066U_SUCCESS;
    /* To be implemented */
    return status;
}

/*******************************************************************/
ST7066U_status_t __attribute__((weak)) ST7066U_HW_gpio_write(ST7066_HW_gpio_t gpio, uint8_t state) {
    // Local variables.
    ST7066U_status_t status = ST7066U_SUCCESS;
    /* To be implemented */
    UNUSED(gpio);
    UNUSED(state);
    return status;
}

/*******************************************************************/
ST7066U_status_t __attribute__((weak)) ST7066U_HW_gpio_make_pulse(ST7066_HW_gpio_t gpio, uint32_t pulse_duration_ns) {
    // Local variables.
    ST7066U_status_t status = ST7066U_SUCCESS;
    /* To be implemented */
    UNUSED(gpio);
    UNUSED(pulse_duration_ns);
    return status;
}

/*******************************************************************/
ST7066U_status_t __attribute__((weak)) ST7066U_HW_data_bus_write(uint8_t data_bus_byte) {
    // Local variables.
    ST7066U_status_t status = ST7066U_SUCCESS;
    /* To be implemented */
    UNUSED(data_bus_byte);
    return status;
}

/*******************************************************************/
ST7066U_status_t __attribute__((weak)) ST7066U_HW_delay_milliseconds(uint32_t delay_ms) {
    // Local variables.
    ST7066U_status_t status = ST7066U_SUCCESS;
    /* To be implemented */
    UNUSED(delay_ms);
    return status;
}

#endif /* ST7066U_DRIVER_DISABLE */
