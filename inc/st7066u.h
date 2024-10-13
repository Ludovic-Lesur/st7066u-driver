/*
 * st7066u.h
 *
 *  Created on: 11 oct. 2024
 *      Author: Ludo
 */

#ifndef __ST7066U_H__
#define __ST7066U_H__

#ifndef ST7066U_DRIVER_DISABLE_FLAGS_FILE
#include "st7066u_driver_flags.h"
#endif
#include "types.h"

/*** ST7066U structures ***/

/*!******************************************************************
 * \enum ST7066U_status_t
 * \brief ST7066U driver error codes.
 *******************************************************************/
typedef enum {
    // Driver errors.
    ST7066U_SUCCESS = 0,
    ST7066U_ERROR_NULL_PARAMETER,
    ST7066U_ERROR_ROW_OVERFLOW,
    ST7066U_ERROR_COLUMN_OVERFLOW,
    // Low level drivers errors.
    ST7066U_ERROR_BASE_GPIO = 0x0100,
    ST7066U_ERROR_BASE_DELAY = (ST7066U_ERROR_BASE_GPIO + ST7066U_DRIVER_GPIO_ERROR_BASE_LAST),
    // Last base value.
    ST7066U_ERROR_BASE_LAST = (ST7066U_ERROR_BASE_DELAY + ST7066U_DRIVER_DELAY_ERROR_BASE_LAST)
} ST7066U_status_t;

#ifndef ST7066U_DRIVER_DISABLE

/*** ST7066U functions ***/

/*!******************************************************************
 * \fn ST7066U_status_t ST7066U_init(void)
 * \brief Init ST7066U driver.
 * \param[in]   none
 * \param[out]  none
 * \retval      Function execution status.
 *******************************************************************/
ST7066U_status_t ST7066U_init(void);

/*!******************************************************************
 * \fn ST7066U_status_t ST7066U_de_init(void)
 * \brief Release ST7066U driver.
 * \param[in]   none
 * \param[out]  none
 * \retval      Function execution status.
 *******************************************************************/
ST7066U_status_t ST7066U_de_init(void);

/*!******************************************************************
 * \fn ST7066U_status_t ST7066U_clear(void)
 * \brief Clear LCD screen.
 * \param[in]   none
 * \param[out]  none
 * \retval      Function execution status.
 *******************************************************************/
ST7066U_status_t ST7066U_clear(void);

/*!******************************************************************
 * \fn ST7066U_status_t ST7066U_print_string(uint8_t row, uint8_t column, char_t* str)
 * \brief Print a string on LCD screen.
 * \param[in]   row: Row where to print.
 * \param[in]   column: Column where to print.
 * \param[in]   str: String to print.
 * \param[out]  none
 * \retval      Function execution status.
 *******************************************************************/
ST7066U_status_t ST7066U_print_string(uint8_t row, uint8_t column, char_t* str);

/*******************************************************************/
#define ST7066U_exit_error(base) { ERROR_check_exit(st7066u_status, ST7066U_SUCCESS, base) }

/*******************************************************************/
#define ST7066U_stack_error(base) { ERROR_check_stack(st7066u_status, ST7066U_SUCCESS, base) }

/*******************************************************************/
#define ST7066U_stack_exit_error(base, code) { ERROR_check_stack_exit(st7066u_status, ST7066U_SUCCESS, base, code) }

#endif /* ST7066U_DRIVER_DISABLE */

#endif /* __ST7066U_H__ */
