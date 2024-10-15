/*
 * st7066u.c
 *
 *  Created on: 11 oct. 2024
 *      Author: Ludo
 */

#include "st7066u.h"

#ifndef ST7066U_DRIVER_DISABLE_FLAGS_FILE
#include "st7066u_driver_flags.h"
#endif
#include "st7066u_hw.h"
#include "string.h"
#include "types.h"

#ifndef ST7066U_DRIVER_DISABLE

/*** ST7066U local macros ***/

#define ST7066U_ENABLE_PULSE_DURATION_NS    50000

/*** ST7066U local structures ***/

/*******************************************************************/
typedef enum {
    ST7066U_ACCESS_TYPE_COMMAND = 0,
    ST7066U_ACCESS_TYPE_DATA,
    ST7066U_ACCESS_TYPE_LAST
} ST7066U_access_type_t;

/*** ST7066U local functions ***/

/*******************************************************************/
static ST7066U_status_t _ST7066U_write(ST7066U_access_type_t type, uint8_t data) {
    // Local variables.
    ST7066U_status_t status = ST7066U_SUCCESS;
    // Set data bus.
    status = ST7066U_HW_data_bus_write(data);
    if (status != ST7066U_SUCCESS) goto errors;
    // Select command or data.
    status = ST7066U_HW_gpio_write(ST7066U_HW_GPIO_RS, type);
    if (status != ST7066U_SUCCESS) goto errors;
    // Latch write access.
    status = ST7066U_HW_gpio_make_pulse(ST7066U_HW_GPIO_E, ST7066U_ENABLE_PULSE_DURATION_NS);
    if (status != ST7066U_SUCCESS) goto errors;
errors:
    return status;
}

/*** ST7066U functions ***/

/*******************************************************************/
ST7066U_status_t ST7066U_init(void) {
    // Local variables.
    ST7066U_status_t status = ST7066U_SUCCESS;
    // Init hardware interface.
    status = ST7066U_HW_init();
    if (status != ST7066U_SUCCESS) goto errors;
    // Put all GPIOs in output low.
    status = ST7066U_HW_gpio_write(ST7066U_HW_GPIO_RS, 0);
    if (status != ST7066U_SUCCESS) goto errors;
    status = ST7066U_HW_gpio_write(ST7066U_HW_GPIO_RW, 0);
    if (status != ST7066U_SUCCESS) goto errors;
    status = ST7066U_HW_gpio_write(ST7066U_HW_GPIO_E, 0);
    if (status != ST7066U_SUCCESS) goto errors;
    // Initialization sequence.
    status = ST7066U_HW_delay_milliseconds(100);
    if (status != ST7066U_SUCCESS) goto errors;
    status = _ST7066U_write(ST7066U_ACCESS_TYPE_COMMAND, 0x30);
    if (status != ST7066U_SUCCESS) goto errors;
    status = ST7066U_HW_delay_milliseconds(30);
    if (status != ST7066U_SUCCESS) goto errors;
    status = _ST7066U_write(ST7066U_ACCESS_TYPE_COMMAND, 0x30);
    if (status != ST7066U_SUCCESS) goto errors;
    status = ST7066U_HW_delay_milliseconds(10);
    if (status != ST7066U_SUCCESS) goto errors;
    status = _ST7066U_write(ST7066U_ACCESS_TYPE_COMMAND, 0x30);
    if (status != ST7066U_SUCCESS) goto errors;
    status = ST7066U_HW_delay_milliseconds(10);
    if (status != ST7066U_SUCCESS) goto errors;
    // LCD configuration.
    status = _ST7066U_write(ST7066U_ACCESS_TYPE_COMMAND, 0x38); // 8-bits / 2 lines mode.
    if (status != ST7066U_SUCCESS) goto errors;
    status = _ST7066U_write(ST7066U_ACCESS_TYPE_COMMAND, 0x08); // Display off.
    if (status != ST7066U_SUCCESS) goto errors;
    status = _ST7066U_write(ST7066U_ACCESS_TYPE_COMMAND, 0x0C); // Display on.
    if (status != ST7066U_SUCCESS) goto errors;
    // Clear screen.
    status = ST7066U_clear();
    if (status != ST7066U_SUCCESS) goto errors;
errors:
    return status;
}

/*******************************************************************/
ST7066U_status_t ST7066U_de_init(void) {
    // Local variables.
    ST7066U_status_t status = ST7066U_SUCCESS;
    // Put all GPIOs in output low.
    status = ST7066U_HW_gpio_write(ST7066U_HW_GPIO_RS, 0);
    if (status != ST7066U_SUCCESS) goto errors;
    status = ST7066U_HW_gpio_write(ST7066U_HW_GPIO_RW, 0);
    if (status != ST7066U_SUCCESS) goto errors;
    status = ST7066U_HW_gpio_write(ST7066U_HW_GPIO_E, 0);
    if (status != ST7066U_SUCCESS) goto errors;
    // Release hardware interface.
    status = ST7066U_HW_de_init();
    if (status != ST7066U_SUCCESS) goto errors;
errors:
    return status;
}

/*******************************************************************/
ST7066U_status_t ST7066U_clear(void) {
    // Local variables.
    ST7066U_status_t status = ST7066U_SUCCESS;
    // Clear command.
    status = _ST7066U_write(ST7066U_ACCESS_TYPE_COMMAND, 0x01);
    if (status != ST7066U_SUCCESS) goto errors;
    status = ST7066U_HW_delay_milliseconds(2);
    if (status != ST7066U_SUCCESS) goto errors;
errors:
    return status;
}

/*******************************************************************/
ST7066U_status_t ST7066U_print_string(uint8_t row, uint8_t column, char_t* str) {
    // Local variables.
    ST7066U_status_t status = ST7066U_SUCCESS;
    uint8_t column_idx = column;
    uint8_t char_idx = 0;
    // Check parameters.
    if (str == NULL) {
        status = ST7066U_ERROR_NULL_PARAMETER;
        goto errors;
    }
    if (row >= ST7066U_DRIVER_SCREEN_HEIGHT) {
        status = ST7066U_ERROR_ROW_OVERFLOW;
        goto errors;
    }
    if (column >= ST7066U_DRIVER_SCREEN_WIDTH) {
        status = ST7066U_ERROR_COLUMN_OVERFLOW;
        goto errors;
    }
    // Set position.
    status = _ST7066U_write(ST7066U_ACCESS_TYPE_COMMAND, (((row * 0x40) + column) + 0x80));
    if (status != ST7066U_SUCCESS) goto errors;
    // Loop until string is printed or screen edge is reached.
    while ((column_idx < ST7066U_DRIVER_SCREEN_WIDTH) && (str[char_idx] != STRING_CHAR_NULL)) {
        // Write character.
        status = _ST7066U_write(ST7066U_ACCESS_TYPE_DATA, str[char_idx]);
        if (status != ST7066U_SUCCESS) goto errors;
        // Increment indexes.
        char_idx++;
        column_idx++;
    }
errors:
    return status;
}

#endif /* ST7066U_DRIVER_DISABLE */
