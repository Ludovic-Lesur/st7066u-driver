/*
 * st7066u_hw.h
 *
 *  Created on: 11 oct. 2024
 *      Author: Ludo
 */

#ifndef __ST7066U_HW_H__
#define __ST7066U_HW_H__

#ifndef ST7066U_DRIVER_DISABLE_FLAGS_FILE
#include "st7066u_driver_flags.h"
#endif
#include "st7066u.h"
#include "types.h"

#ifndef ST7066U_DRIVER_DISABLE

/*** ST7066U HW structures ***/

typedef enum {
    ST7066U_HW_GPIO_RS,
    ST7066U_HW_GPIO_RW,
    ST7066U_HW_GPIO_E,
    ST7066U_HW_GPIO_LAST
} ST7066_HW_gpio_t;

/*** ST7066U HW functions ***/

/*!******************************************************************
 * \fn ST7066U_status_t ST7066U_HW_init(void)
 * \brief Init ST7066U hardware interface.
 * \param[in]   none
 * \param[out]  none
 * \retval      Function execution status.
 *******************************************************************/
ST7066U_status_t ST7066U_HW_init(void);

/*!******************************************************************
 * \fn ST7066U_status_t ST7066U_HW_de_init(void)
 * \brief Release ST7066U hardware interface.
 * \param[in]   none
 * \param[out]  none
 * \retval      Function execution status.
 *******************************************************************/
ST7066U_status_t ST7066U_HW_de_init(void);

/*!******************************************************************
 * \fn ST7066U_status_t ST7066U_HW_gpio_write(ST7066_HW_gpio_t gpio, uint8_t state)
 * \brief Set ST7066U GPIO state.
 * \param[in]   gpio: GPIO to control.
 * \param[in]   state: 0 for logic low, 1 for logic high.
 * \param[out]  none
 * \retval      Function execution status.
 *******************************************************************/
ST7066U_status_t ST7066U_HW_gpio_write(ST7066_HW_gpio_t gpio, uint8_t state);

/*!******************************************************************
 * \fn ST7066U_status_t ST7066U_HW_gpio_make_pulse(ST7066_HW_gpio_t gpio, uint32_t pulse_duration_ns)
 * \brief Make a positive pulse on ST7066U GPIO.
 * \param[in]   gpio: GPIO to control.
 * \param[in]   pulse_duration_ns: Positive pulse duration in ns.
 * \param[out]  none
 * \retval      Function execution status.
 *******************************************************************/
ST7066U_status_t ST7066U_HW_gpio_make_pulse(ST7066_HW_gpio_t gpio, uint32_t pulse_duration_ns);

/*!******************************************************************
 * \fn ST7066U_status_t ST7066U_HW_data_bus_write(uint8_t data_bus_byte)
 * \brief Set ST7066U data bus pins.
 * \param[in]   data_bus_byte: Data bus pins byte defined as [DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0].
 * \param[out]  none
 * \retval      Function execution status.
 *******************************************************************/
ST7066U_status_t ST7066U_HW_data_bus_write(uint8_t data_bus_byte);

/*!******************************************************************
 * \fn ST7066U_status_t ST7066_HW_delay_milliseconds(uint32_t delay_ms)
 * \brief Delay function.
 * \param[in]   delay_ms: Delay to wait in ms.
 * \param[out]  none
 * \retval      Function execution status.
 *******************************************************************/
ST7066U_status_t ST7066U_HW_delay_milliseconds(uint32_t delay_ms);

#endif /* ST7066U_DRIVER_DISABLE */

#endif /* __ST7066U_HW_H__ */
