/**
  ******************************************************************************
  * @file led.c
  * @brief This file contains the main function for LED driver.
  * @author chengbo yang for ultrasonic operation
  * @version V1.0.0
  * @date 17-Dec-2016
  ******************************************************************************
  *
  * THE PRESENT FIRMWARE WHICH IS FOR LED management.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "led.h"


/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

#define SetBit_LED(VAR,BIT_PIN)         ( (VAR) |= (uint8_t)(BIT_PIN))
#define ClrBit_LED(VAR,BIT_PIN)         ( (VAR) &= (uint8_t)((uint8_t)((uint8_t)BIT_PIN)^(uint8_t)255) )

/* Private variables ---------------------------------------------------------*/ 
union {
  Led_status led_st;
  char led_value;
} led_track;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/
    
void Initial_Led()
{ 
  led_track.led_value = 0xff;
  led_track.led_st.led_start = 0;
  led_track.led_st.led_temp  = 0;
  led_track.led_st.led_error = 0;
  led_track.led_st.led_count = 0;
}
void led_management()
{
  led_track.led_st.led_start = 1;
  led_track.led_st.led_temp  = 1;
  led_track.led_st.led_error = 1;
}
void led_test(char num, char state)
{
  switch(num)
  {
  case 1:
    if(state > 0)
    SetBit_LED(LED_PORT->ODR,LED_START); 
    else
    ClrBit_LED(LED_PORT->ODR,LED_START); 
    break;
  case 2:
    if(state > 0)
    SetBit_LED(LED_PORT->ODR,LED_TEMP); 
    else
    ClrBit_LED(LED_PORT->ODR,LED_TEMP); 
    break;
  case 3:
    if(state > 0)
    SetBit_LED(LED_PORT->ODR,LED_ERROR); 
    else
    ClrBit_LED(LED_PORT->ODR,LED_ERROR);   
    break;
  default:
    break;
  }
  
}


