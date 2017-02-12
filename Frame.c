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
#include "Frame.h"
#include "lcd.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
  u8 work_status; //current status of device
  u8 task_state;  // for state machine control
  u8  mode;  //mode selected record
  u16 temp;  //real time temperature 
  u16 time_remain; //time remaining for running
  u16 work_freq;  // frequency of running
  u16 work_P;     // power selection record
  u16 pulse_on;    // pulse on time
  u16 pulse_off;   // pulse off time
  u32 work_time;   // working time
  u16 p_temp;     // temperature limit
  u16 v_protect;  //voltage protection threshold
  u16 soft_start; //soft startup time

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/
    
void NVMRecall(void)
{
    /* GPIOC Peripheral Configuration */
/*  delay_ms(50);
  FLASH_DeInit();
  FLASH_Unlock(FLASH_MEMTYPE_DATA);  
  FLASH_ProgramByte(0x4004,0x45);
  delay_ms(50);
  test = FLASH_ReadByte(0x4004);
  delay_ms(50);
*/ 
}
void NVMstore16(u8 addr, u16 data)
{ 
  u8 temp_data;
  FLASH_DeInit();  
  FLASH_Unlock(FLASH_MEMTYPE_DATA); 
  temp_data = data & 0x00FF;
  FLASH_ProgramByte(addr,temp_data);
  delay_ms(5);
  temp_data = data>>8;
  FLASH_ProgramByte(addr,temp_data);

}
void NVMstore32(u8 addr, u32 data)
{ 
  FLASH_DeInit();  
  FLASH_Unlock(FLASH_MEMTYPE_DATA);
  FLASH_ProgramWord(addr,data);
}
void WorkState_check(void)
{
}


