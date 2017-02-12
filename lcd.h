/**
  ******************************************************************************
  * @file lcd.h
  * @brief This file contains the main function for LCD driver.
  * @author chengbo yang for ultrasonic operation
  * @version V1.0.0
  * @date 17-Dec-2016
  ******************************************************************************
  *
  * THE PRESENT FIRMWARE WHICH IS FOR first transplantation version of 12864G-1016-PN,COG.
  *
  ******************************************************************************
  */

#ifndef __LCD_H
#define __LCD_H

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

#define LCD_PORT   (GPIOB)
#define LCD_CS     (GPIO_PIN_5)
#define LCD_RESET  (GPIO_PIN_4)
#define LCD_RS     (GPIO_PIN_3)
#define LCD_SDA    (GPIO_PIN_6)
#define LCD_SCK    (GPIO_PIN_7)

/* Private variables ---------------------------------------------------------*/ 
typedef struct 
{
  char bit0 : 1;
  char bit1 : 1;
  char bit2 : 1;
  char bit3 : 1;
  char bit4 : 1;
  char bit5 : 1;
  char bit6 : 1;
  char bit7 : 1;
} Bit_type;

/* Private function prototypes -----------------------------------------------*/

/*public variables------------------------------------------------------------*/
extern const char graphic0[];
extern const char zero[];
extern const char one[];
extern const char two[];
extern const char three[];
extern const char four[];
extern const char five[];
extern const char six[];
extern const char seven[];
extern const char eight[];
extern const char nine[];
/* Public functions ----------------------------------------------------------*/
void disp_grap(char const  *dp);
void disp_invert(char const *dp, u8 col, u8 row, u8 width, u8 heigh);
void disp_normal(char const *dp, u8 col, u8 row, u8 width, u8 heigh);
void disp_num(char col, char page, char const *dp);
void Initial_Lcd();
void clear_screen();
void waitkey();
void transfer_command(u8 data1);
void transfer_data(u8 data1);
void delay_us( unsigned int time);
void delay_ms(unsigned int time);


#endif  //__LCD_H



  