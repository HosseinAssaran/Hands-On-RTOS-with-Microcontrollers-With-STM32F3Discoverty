/**
 * LED implementation for Red, Green, and Blue discrete LED's on
 * Nucleo-F767ZI
 */

#include <F3Discovery_GPIO.h>
#include <stm32f3xx_hal.h>

void GreenOn ( void ) {HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_SET);}
void GreenOff ( void ) {HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_RESET);}
LED GreenLed = { GreenOn, GreenOff };

void BlueOn ( void ) {HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_SET);}
void BlueOff ( void ) {HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET);}
LED BlueLed = { BlueOn, BlueOff };

void RedOn ( void ) {HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET);}
void RedOff ( void ) {HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET);}
LED RedLed = { RedOn, RedOff };

uint_fast8_t ReadPushButton( void ){ return HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);}
