/**
  ******************************************************************************
  * @file t2pwm.h
  * @brief This file contains the function for pwm driver.
  * @author chengbo yang for ultrasonic operation
  * @version V1.0.0
  * @date 24-Dec-2016
  ******************************************************************************
  *
  * THE PRESENT FIRMWARE WHICH IS FOR LED MANAGEMENT
  *
  ******************************************************************************
  */

#ifndef __TIMER_H
#define __TIMER_H

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

#define T2_P_SCALER 1600 

/* Private variables ---------------------------------------------------------*/ 
typedef struct
{
  char ms_100;
  char second;
  char ms_20;
  char ms_10;
} t_flag;

/* Private function prototypes -----------------------------------------------*/

/*public variables------------------------------------------------------------*/
extern t_flag timer3_flag;
extern u16 timer_1s_count;
extern u16 timer_100ms_count;
extern u16 timer_20ms_count;
extern u16 timer1_count;
/* Public functions ----------------------------------------------------------*/

void InitTimer3(); // timer is tick 10ms
void InitTimer1(); // timer1 is frequency tracking

#endif  //__TIMER_H



  