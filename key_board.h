/**
  ******************************************************************************
  * @file lcd.h
  * @brief This file contains the main function for Key_board driver.
  * @author chengbo yang for ultrasonic operation
  * @version V1.0.0
  * @date 29-Dec-2016
  ******************************************************************************
  *
  * THE PRESENT FIRMWARE WHICH IS FOR KEY BOARD DRIVER.
  *
  ******************************************************************************
  */

#ifndef __KEYBOARD_H
#define __KEYBOARD_H

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"


/* Private typedef -----------------------------------------------------------*/
typedef struct
{
  u8 key_state;   // 0 off; 1 push; 2 on; 3 release
  u8 key_timeout; //long time pushing delay
  u8 key_count;   //on time count
  u8 key_check;   //averaging buffer
  
}key_status;
/* Private define ------------------------------------------------------------*/
#define KEY_OFF  0
#define KEY_PUSH 1
#define KEY_ON   2
#define KEY_RELEASE 3

/* Private macro -------------------------------------------------------------*/
#define KEY_GPIO     (GPIOD)
#define KEY_UP       (GPIO_PIN_2)
#define KEY_DOWN     (GPIO_PIN_3)
#define KEY_ON_OFF   (GPIO_PIN_5)
#define KEY_ENTER    (GPIO_PIN_6)
#define KEY_SET      (GPIO_PIN_7)


/* Private variables ---------------------------------------------------------*/ 

/* Private function prototypes -----------------------------------------------*/
void button_init(void);
void button_scan(void);  // maybe will send message to certain fraim view
void sendMsg2view(char B_num, char B_state);
/*public variables------------------------------------------------------------*/
extern key_status Key_board[];




#endif  //__KEYBOARD_H



  