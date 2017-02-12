/**
  ******************************************************************************
  * @file led.h
  * @brief This file contains the main function for LED driver.
  * @author chengbo yang for ultrasonic operation
  * @version V1.0.0
  * @date 24-Dec-2016
  ******************************************************************************
  *
  * THE PRESENT FIRMWARE WHICH IS FOR LED MANAGEMENT
  *
  ******************************************************************************
  */

#ifndef __LED_H
#define __LED_H

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

#define LED_PORT   (GPIOA)
#define LED_START     (GPIO_PIN_4)
#define LED_TEMP      (GPIO_PIN_5)
#define LED_ERROR     (GPIO_PIN_6)


#define SetBit_LCD(VAR,BIT_PIN)         ( (VAR) |= (uint8_t)(BIT_PIN))
#define ClrBit_LCD(VAR,BIT_PIN)         ( (VAR) &= (uint8_t)((uint8_t)((uint8_t)BIT_PIN)^(uint8_t)255) )

/* Private variables ---------------------------------------------------------*/ 
typedef struct 
{
  char led_start : 1;
  char led_temp  : 1;
  char led_error : 1;
  char led_count : 5;
} Led_status;

/* Private function prototypes -----------------------------------------------*/

/*public variables------------------------------------------------------------*/

/* Public functions ----------------------------------------------------------*/

void Initial_Led();
void led_management();
void led_test(char num, char state);
#endif  //__LED_H



  