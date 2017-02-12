/**
  ******************************************************************************
  * @file main.c
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

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "lcd.h"
#include "led.h"
#include "t2pwm.h"
#include "timer.h"
#include "key_board.h"
#include "Display.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
#define ADC_PORT  GPIOB
#define PV_ADC_PIN GPIO_PIN_0
#define PW_ADC_PIN GPIO_PIN_1
#define TP_ADC_PIN GPIO_PIN_2

/* Private variables ---------------------------------------------------------*/ 
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void ADC_Init(void);
void GPIO_init_t(void);
/* Public functions ----------------------------------------------------------*/

/**
  * @brief Example firmware main entry point.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
char test;

void main(void)
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
  disableInterrupts();
  CLK_ClockSwitchCmd(ENABLE);
  CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_HSE, DISABLE, CLK_CURRENTCLOCKSTATE_ENABLE);
  
  GPIO_init_t();

  
  //ADC init and configure
  ADC_Init(); 
  
  delay_ms(50);
  Initial_Lcd(); 
  button_init(); // initalize button status
  clear_screen();  
  disp_grap(graphic0);
//  disp_num(1,4,one);
//  disp_num(9,4,two);

  
  Initial_pwm();
  InitTimer3();
  InitTimer1();
  enableInterrupts();
  Pwm_open();
 
  while (1)
  {
    
    
    if(timer3_flag.ms_20 == 1)
    {
      timer3_flag.ms_10 = 0;
      timer3_flag.ms_20 = 0;
      ADC1_ClearFlag(ADC1_FLAG_EOC);
      ADC1_StartConversion();
    
      button_scan();
      Display_check();
    }
  }
}


void ADC_Init(void)
{
   // 配置ADC相关引脚
  
    GPIO_Init(ADC_PORT, PV_ADC_PIN , GPIO_MODE_IN_FL_NO_IT); 
    GPIO_Init(ADC_PORT, PW_ADC_PIN , GPIO_MODE_IN_FL_NO_IT); 
    GPIO_Init(ADC_PORT, TP_ADC_PIN , GPIO_MODE_IN_FL_NO_IT); 
  // 复位ADC1
    ADC1_DeInit();
    
    ADC1_ScanModeCmd(ENABLE);   //设置为扫描模式，这样配置之后就是单次扫描模式了
    ADC1_DataBufferCmd(ENABLE);   //这里配置的是开启数据缓冲区，可以把单次转换的数据放里面，等到每次接受之后取出来
    // 配置ADC1
    ADC1_Init(ADC1_CONVERSIONMODE_SINGLE, ADC1_CHANNEL_2, ADC1_PRESSEL_FCPU_D8, 
              ADC1_EXTTRIG_TIM, DISABLE, ADC1_ALIGN_RIGHT, 
                      ADC1_SCHMITTTRIG_CHANNEL1, DISABLE);
    ADC1_SchmittTriggerConfig(ADC1_SCHMITTTRIG_CHANNEL0, DISABLE);
    ADC1_SchmittTriggerConfig(ADC1_SCHMITTTRIG_CHANNEL2, DISABLE);
    

    
    ///@ 从ADC上电到开始ADC转换要间隔7us
    // 连续转换模式
 //   ADC1_ScanModeCmd(ENABLE);      

    // Start ADC Conversion
    ADC1_StartConversion();
}
void GPIO_init_t(void)
{
  //LCD GPIO init  GPIOB pin_1 -pin_5
  GPIO_Init(LCD_PORT, LCD_CS,GPIO_MODE_OUT_PP_HIGH_FAST);
  GPIO_Init(LCD_PORT, LCD_RESET, GPIO_MODE_OUT_PP_HIGH_FAST);
  GPIO_Init(LCD_PORT, LCD_RS, GPIO_MODE_OUT_PP_HIGH_FAST);
  GPIO_Init(LCD_PORT, LCD_SDA, GPIO_MODE_OUT_PP_HIGH_FAST);
  GPIO_Init(LCD_PORT, LCD_SCK, GPIO_MODE_OUT_PP_HIGH_FAST);
  
  //LED GPIO init  GPIOB pin_4 -pin_6
  GPIO_Init(LED_PORT , LED_START , GPIO_MODE_OUT_PP_HIGH_FAST);
  GPIO_Init(LED_PORT , LED_TEMP , GPIO_MODE_OUT_PP_HIGH_FAST);
  GPIO_Init(LED_PORT , LED_ERROR , GPIO_MODE_OUT_PP_HIGH_FAST);
  
  //Button_GPIO init GPIOD pin 2 3 5 6 7 
  GPIO_Init(KEY_GPIO, KEY_UP , GPIO_MODE_IN_FL_NO_IT);
  GPIO_Init(KEY_GPIO, KEY_DOWN , GPIO_MODE_IN_FL_NO_IT);
  GPIO_Init(KEY_GPIO, KEY_ON_OFF , GPIO_MODE_IN_FL_NO_IT);
  GPIO_Init(KEY_GPIO, KEY_ENTER , GPIO_MODE_IN_FL_NO_IT);
  GPIO_Init(KEY_GPIO, KEY_SET , GPIO_MODE_IN_FL_NO_IT);
}
#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  * where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval 
  * None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
