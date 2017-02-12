/**
  ******************************************************************************
  * @file led.h
  * @brief This file contains the main function for HMI screens and actions.
  * @author chengbo yang for ultrasonic operation
  * @version V1.0.0
  * @date 31-Dec-2016
  ******************************************************************************
  * there is no buffer; can be modified to buffer HMI change
  * THE PRESENT FIRMWARE WHICH IS FOR LED MANAGEMENT
  *
  ******************************************************************************
  */

#ifndef __DISPLAY_H
#define __DISPLAY_H

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

#define MAIN_S        0
#define SET_S         1
#define MODE_SET_S    2
#define TIME_SET_S    3
#define SET_POINT_S   4

/* Private variables ---------------------------------------------------------*/ 
typedef struct 
{
  u8 cur_page;
  u8 cur_pos;
  u8 init_need;
  u8 invert_need;
   
} HMI_status;

/* Private function prototypes -----------------------------------------------*/

/*public variables------------------------------------------------------------*/
extern char Button_trigger;  // to indicate which key is involved
extern char trigger_type; // to indicate which type of this trigger, 1: push 2:hold on; 3 release
extern char fouse_point; // current focus point position
/* Public functions ----------------------------------------------------------*/

void Initial_Display();
void Display_check();
void Display_page0(u8 init_f);
void Display_page1(u8 init_f);
void Display_page2(u8 init_f);
void Display_page3(u8 init_f);
void Display_page4(u8 init_f);
void Init_page0();
void Init_page1();
void Init_page2();
void Init_page3();
void Init_page4();
void ColorInv_p(u8 row, u8 col);
void ColorInv_n(char * data);

#endif  //__DISPLAY_H



  