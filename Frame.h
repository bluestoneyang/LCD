/**
  ******************************************************************************
  * @file led.h
  * @brief This file contains the main function for operations and actions. RUN
  * @author chengbo yang for ultrasonic operation
  * @version V1.0.0
  * @date 2-Jan-2017
  ******************************************************************************
  * include operaiton parameters management
  * THE PRESENT FIRMWARE WHICH IS FOR LED MANAGEMENT
  *
  ******************************************************************************
  */

#ifndef __FRAME_H
#define __FRAME_H

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define WORK_RUN  1
#define WORK_IDLE 2
#define WORK_TRAP 3
#define WORK_STOP 0
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/ 
/* Private function prototypes -----------------------------------------------*/

/*public variables------------------------------------------------------------*/
extern u8 work_status; //current status of device
extern u8 task_state;  // for state machine control
extern u8  mode;  //mode selected record
extern u16 temp;  //real time temperature 
extern u16 time_remain; //time remaining for running
extern u16 work_freq;  // frequency of running
extern u16 work_P;     // power selection record
extern u16 pulse_on;    // pulse on time
extern u16 pulse_off;   // pulse off time
extern u32 work_time;   // working time
extern u16 p_temp;     // temperature limit
extern u16 v_protect;  //voltage protection threshold
extern u16 soft_start; //soft startup time
/* Public functions ----------------------------------------------------------*/

void NVMRecall(void);
void NVMstore(u8 addr, u16 data);
void WorkState_check(void);


#endif  //__FRAME_H



  