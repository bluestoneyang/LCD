/**
  ******************************************************************************
  * @file led.c
  * @brief This file contains the main function for Button scanning driver.
  * @author chengbo yang for ultrasonic operation
  * @version V1.0.0
  * @date 29-Dec-2016
  ******************************************************************************
  *
  * THE PRESENT FIRMWARE WHICH IS FOR Button scanner management.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "key_board.h"
#include "Display.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define K_ON 1
#define K_OFF 0
/* Private macro -------------------------------------------------------------*/

//#define SetBit_LED(VAR,BIT_PIN)         ( (VAR) |= (uint8_t)(BIT_PIN))
//#define ClrBit_LED(VAR,BIT_PIN)         ( (VAR) &= (uint8_t)((uint8_t)((uint8_t)BIT_PIN)^(uint8_t)255) )

/* Private variables ---------------------------------------------------------*/ 
BitStatus testbb;
key_status Key_board[5] ;
const uint8_t Key_Pin[5] = {KEY_UP, KEY_DOWN, KEY_ON_OFF, KEY_ENTER, KEY_SET};

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/
    
void button_init(void)
{
  for(int i = 0; i< 5; i++)
  {
    Key_board[i].key_check = 0;
    Key_board[i].key_count = 0;
    Key_board[i].key_state = 0;
    Key_board[i].key_timeout = 100;
  }
}
void button_scan(void)  // maybe will send message to certain fraim view
{
   BitStatus bit_b;
   u8 j , num;
   for(int i = 0; i < 5; i++)
   {
     num = 0;
     bit_b = GPIO_ReadInputPin(KEY_GPIO, Key_Pin[i]);
   //  testbb = GPIO_ReadInputPin(KEY_GPIO, Key_Pin[i]);
     Key_board[i].key_check = Key_board[i].key_check << 1 ;
     Key_board[i].key_check += (bit_b == RESET);
       for(j = 0; j <8; j++)
       {
         num += ((Key_board[i].key_check >> j) & (0x01));
       }
         if (num >= 7)
         {
           switch(Key_board[i].key_state)
           {
           case KEY_OFF:
             Key_board[i].key_state = KEY_PUSH;
             sendMsg2view( i+1 , KEY_PUSH);
             break;
           case KEY_PUSH:
             Key_board[i].key_state = KEY_ON;            
             break;
           case KEY_ON:
             if(Key_board[i].key_count++ >= Key_board[i].key_timeout)
             {
               Key_board[i].key_count = Key_board[i].key_timeout - 20;
               sendMsg2view( i+1 , KEY_PUSH); //long time hold on
             }
            //   send_message( continue operation)
             break;
           case KEY_RELEASE:
             Key_board[i].key_state = KEY_PUSH;
             sendMsg2view( i+1 , KEY_PUSH);
       //      if(Key_board[i].key_count++ >= Key_board[i].key_timeout)
       //        Key_board[i].key_state = KEY_OFF;
             break;
           default:
             Key_board[i].key_state = KEY_OFF ;
             Key_board[i].key_count = 0;
             break;
           }
           
         }
         else if(num <= 1)
         {
           switch(Key_board[i].key_state)
           {
           case KEY_OFF:             
             break;
           case KEY_PUSH:
             Key_board[i].key_state = KEY_RELEASE;
             break;
           case KEY_ON:
             Key_board[i].key_state = KEY_RELEASE;
             break;
           case KEY_RELEASE:
             Key_board[i].key_state = KEY_OFF;
             break;
           default:
             Key_board[i].key_state = KEY_OFF ;
             Key_board[i].key_count = 0;
             break;
           }
         }
         else
         {
         }
       }
     
         

}
//send message to view task
void sendMsg2view(char B_num, char B_state)
{
  Button_trigger = B_num; 
  trigger_type  = B_state; 
}






