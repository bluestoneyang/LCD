/**
  ******************************************************************************
  * @file lcd.c
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


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

#define SetBit_LCD(VAR,BIT_PIN)         ( (VAR) |= (uint8_t)(BIT_PIN))
#define ClrBit_LCD(VAR,BIT_PIN)         ( (VAR) &= (uint8_t)((uint8_t)((uint8_t)BIT_PIN)^(uint8_t)255) )

/* Private variables ---------------------------------------------------------*/ 
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

/**
  * @brief Example firmware main entry point.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
    
const char zero[] = {0x00,0xE0,0x10,0x08,0x08,0x10,0xE0,0x00,0x00,0x0F,0x10,0x20,0x20,0x10,0x0F,0x00};/*"0",0*/

const char one[] ={0x00,0x00,0x10,0x10,0xF8,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00};/*"1",1*/

const char two[] ={0x00,0x70,0x08,0x08,0x08,0x08,0xF0,0x00,0x00,0x30,0x28,0x24,0x22,0x21,0x30,0x00};/*"2",2*/

const char three[] ={0x00,0x30,0x08,0x08,0x08,0x88,0x70,0x00,0x00,0x18,0x20,0x21,0x21,0x22,0x1C,0x00};/*"3",3*/

const char four[] ={0x00,0x00,0x80,0x40,0x30,0xF8,0x00,0x00,0x00,0x06,0x05,0x24,0x24,0x3F,0x24,0x24};/*"4",4*/

const char five[] ={0x00,0xF8,0x88,0x88,0x88,0x08,0x08,0x00,0x00,0x19,0x20,0x20,0x20,0x11,0x0E,0x00};/*"5",5*/

const char six[] ={0x00,0xE0,0x10,0x88,0x88,0x90,0x00,0x00,0x00,0x0F,0x11,0x20,0x20,0x20,0x1F,0x00};/*"6",6*/

const char seven[] ={0x00,0x18,0x08,0x08,0x88,0x68,0x18,0x00,0x00,0x00,0x00,0x3E,0x01,0x00,0x00,0x00};/*"7",7*/

const char eight[] ={0x00,0x70,0x88,0x08,0x08,0x88,0x70,0x00,0x00,0x1C,0x22,0x21,0x21,0x22,0x1C,0x00};/*"8",8*/

const char nine[] ={0x00,0xF0,0x08,0x08,0x08,0x10,0xE0,0x00,0x00,0x01,0x12,0x22,0x22,0x11,0x0F,0x00};/*"9",9*/


const char graphic0[]={
/*-- 调入了一幅图像：E:\work\图片收藏夹\JLX12864G-1016.bmp --*/
/*-- 宽度x 高度=128x64 --*/
0X00,0X00,0X00,0XE0,0XC0,0X00,0X00,0X00,0X00,0X00,0XC0,0XE0,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XE0,0X20,0X20,0X20,0X20,
0X20,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XE0,0X20,0X20,0X20,
0X20,0X20,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X40,0X20,0X20,0X20,0X20,
0XC0,0X00,0XC0,0X20,0X20,0X20,0X20,0XC0,0X00,0X00,0X00,0X00,0X00,0XC0,0X20,0X20,
0X20,0X20,0XC0,0X00,0XC0,0X20,0X20,0X20,0X20,0XC0,0X00,0XC0,0X20,0X20,0X20,0X20,
0XC0,0X00,0X00,0XE0,0X00,0X00,0X00,0X00,0X80,0X40,0X20,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X7F,0X00,0X03,0X1C,0X60,0X1C,0X03,0X00,0X7F,0X00,0X00,0X3E,0X41,
0X41,0X41,0X3E,0X00,0X00,0X3E,0X41,0X41,0X42,0X7F,0X00,0X00,0X3E,0X49,0X49,0X49,
0X2E,0X00,0X00,0X41,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0X04,0X04,0X04,0X04,
0X04,0X03,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0X02,0X02,0X02,
0X02,0X00,0X00,0X00,0X41,0X00,0X00,0X00,0X00,0X00,0X00,0X40,0X60,0X50,0X48,0X44,
0X43,0X00,0X3F,0X40,0X40,0X40,0X40,0X3F,0X00,0X00,0X40,0X00,0X00,0X3F,0X40,0X40,
0X40,0X40,0X3F,0X00,0X3F,0X40,0X40,0X40,0X40,0X3F,0X00,0X3F,0X40,0X40,0X40,0X40,
0X3F,0X00,0X00,0X7F,0X08,0X04,0X06,0X09,0X10,0X20,0X40,0X00,0X00,0X00,0X00,0X00,
0X00,0X80,0X80,0X80,0X80,0X80,0X80,0X80,0X00,0X80,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X80,0X80,0X80,0X80,0X00,0X00,0X00,0X80,0X80,0X80,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X80,0X80,0X80,0X80,0X80,0X00,0X00,0X80,
0X80,0X80,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X80,0X00,0X00,0X00,
0XC0,0X80,0X80,0X80,0X80,0X80,0X00,0X00,0XC0,0X00,0X00,0X40,0X80,0X00,0X00,0X00,
0X00,0X00,0XC0,0X00,0X00,0X00,0X00,0X00,0X80,0X80,0X80,0X80,0X00,0X00,0X00,0X00,
0X00,0XC0,0X00,0X00,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0XFF,0X00,0X00,0X00,0X00,0XFC,0X00,0X00,0XFC,0X08,0X04,0X04,
0XF8,0X08,0X04,0X04,0XF8,0X00,0X00,0XF8,0X24,0X24,0X24,0XB8,0X00,0X00,0X04,0X00,
0X00,0X00,0X00,0X00,0X00,0X8F,0X10,0X10,0X10,0X88,0X7F,0X00,0X8F,0X10,0X10,0X10,
0X88,0X7F,0X00,0X00,0X04,0X00,0X00,0X9C,0X0B,0X08,0X08,0X08,0XF0,0X00,0X8F,0X10,
0X10,0X10,0X88,0X7F,0X00,0X00,0X00,0X00,0X00,0X00,0XFC,0X03,0X00,0X18,0X0C,0XFF,
0X00,0X24,0X26,0XFD,0X26,0X2C,0X7F,0X00,0XFF,0X00,0X04,0X04,0XFC,0X01,0X00,0X84,
0X04,0X04,0XFF,0X04,0X04,0X04,0X04,0X00,0XFF,0X88,0X88,0XFF,0X02,0X0A,0X12,0X22,
0X02,0XFF,0X02,0X02,0X00,0X03,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X01,0X00,0X00,0X00,0X00,0X01,0X00,0X00,0X01,0X00,0X00,0X00,
0X01,0X00,0X00,0X00,0X01,0X00,0X00,0X00,0X01,0X01,0X01,0X00,0X00,0X00,0X01,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X01,0X01,0X00,0X00,0X00,0X00,0X01,0X01,0X01,
0X00,0X00,0X00,0X00,0X01,0X00,0X00,0X00,0X01,0X01,0X01,0X01,0X00,0X00,0X00,0X01,
0X01,0X01,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0X06,0X00,0X00,0X00,0X03,
0X00,0X02,0X02,0X03,0X01,0X01,0X02,0X02,0X03,0X00,0X00,0X00,0X03,0X01,0X01,0X00,
0X00,0X00,0X03,0X00,0X00,0X00,0X00,0X00,0X01,0X00,0X00,0X01,0X00,0X00,0X02,0X02,
0X02,0X03,0X00,0X00,0X00,0X06,0X01,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X80,0X40,0X40,0X40,0X80,0X00,0X00,0X00,0X00,0X80,0X40,0X40,0XC0,0X00,0X00,0X00,
0X00,0X80,0X40,0X40,0XC0,0X00,0X00,0X00,0X80,0X80,0X80,0X00,0X00,0X00,0X00,0X80,
0X80,0X80,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X02,0XFF,0X82,0X82,0X00,0X7C,0XD6,0X92,0X92,0X5C,0X00,0X00,0XFE,
0X04,0X02,0X02,0XFC,0X04,0X02,0X02,0X02,0XFC,0X00,0X00,0XFE,0X44,0X82,0X82,0XC6,
0X7C,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XC6,0XC6,0X00,0X00,0X00,0X00,0X00,0X00,
0X40,0X84,0X84,0XCC,0X7B,0X00,0X00,0X00,0X3F,0XC0,0X80,0X80,0X40,0X3F,0X00,0X00,
0X3F,0XC0,0X80,0X80,0X40,0X3F,0X00,0X00,0X03,0X04,0X03,0X00,0X00,0X7F,0XC1,0X80,
0X80,0X80,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X07,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00
};

void delay_us( unsigned int time)
{
   unsigned int x;
   for(x=time;x>0;x--)
   {
   asm("nop"); //一个asm("nop")函数经过示波器测试代表100ns
   asm("nop");
   asm("nop");
   asm("nop");
   asm("nop"); //一个asm("nop")函数经过示波器测试代表100ns
 }
}

void delay_ms(unsigned int time)
{
   unsigned int i;
   while(time--)
   {
   for(i=900;i>0;i--)
   delay_us(1);
   }
}

void disp_grap(char const *dp)
{
    int i,j;
    for(i=0;i<8;i++)
    {
        ClrBit_LCD(LCD_PORT->ODR, LCD_CS); //cs1=0;
        transfer_command(0xb0+i); /*页地址*/
        transfer_command(0x10); /*列地址高4 位*/
        transfer_command(0x00); /*列地址低4 位*/
        for(j=0;j<128;j++)
        {
        transfer_data(*dp); //(*dp);
        dp++;
        }
     }
}
void disp_invert(char const *dp, u8 col, u8 row,  u8 width, u8 heigh)
{
    int i,j;
    for(i = row;i<(heigh + row);i++)
    {
        ClrBit_LCD(LCD_PORT->ODR, LCD_CS); //cs1=0;
        transfer_command(0xb0+i); /*页地址*/
        transfer_command(0x10 + (col>>4)); /*列地址高4 位*/
        transfer_command(0x00 + (col & 0x0f)); /*列地址低4 位*/

        for(j = col;j< (width + col);j++)
        {
        transfer_data(~dp[j + i* 128]); //(*dp);
        
        }
     }
}
void disp_normal(char const *dp, u8 col, u8 row, u8 width, u8 heigh)
{
   int i,j;
    for(i = row;i<(heigh + row);i++)
    {
        ClrBit_LCD(LCD_PORT->ODR, LCD_CS); //cs1=0;
        transfer_command(0xb0+i); /*页地址*/
        transfer_command(0x10 + (col>>4)); /*列地址高4 位*/
        transfer_command(0x00 + (col & 0x0f)); /*列地址低4 位*/

        for(j = col;j< (width + col);j++)
        {
        transfer_data(dp[j + i* 128]); //(*dp);
        
        }
     }
}
void disp_num(char col, char page, char const *dp)
{
  int i,j;
    for(i=0;i<2;i++)
    {
        ClrBit_LCD(LCD_PORT->ODR, LCD_CS); //cs1=0;
        transfer_command(0xb0+ page + i); /*页地址*/
        transfer_command(0x10 + (col>>4)); /*列地址高4 位*/
        transfer_command(0x00 + (col & 0x0f)); /*列地址低4 位*/
        for(j=0;j<8;j++)
        {
        transfer_data(*dp);
        dp++;
        }
     }

}
void Initial_Lcd()
{
   
    ClrBit_LCD(LCD_PORT->ODR, LCD_RESET);
    //reset=0; //Reset the chip when reset=0
    delay_us(6);
    SetBit_LCD(LCD_PORT->ODR, LCD_RESET);
    // reset=1;
    delay_ms(10);
    
    transfer_command(0xe2); /*软复位*/
    transfer_command(0x2c); /*升压步聚1*/
    delay_us(60);
    transfer_command(0x2e); /*升压步聚2*/
    delay_us(60);
    transfer_command(0x2f); /*升压步聚3*/
    delay_us(60);
    transfer_command(0x23); /*粗调对比度，可设置范围20～27*/
    transfer_command(0x81); /*微调对比度*/
    transfer_command(0x1f); /*微调对比度的值，可设置范围0～63*/
    transfer_command(0xa2); /*1/9 偏压比（bias）*/  //0xa1
    transfer_command(0xc8); /*行扫描顺序：从上到下*/
    transfer_command(0xa0); /*列扫描顺序：从左到右*/
    transfer_command(0x40); /*起始行：从第一行开始*/
    transfer_command(0xaf); /*开显示*/  
}
void clear_screen()
{
    unsigned char i,j;
    for(i=0;i<9;i++)
    {
      ClrBit_LCD(LCD_PORT->ODR, LCD_CS);
      transfer_command(0xb0+i);
      transfer_command(0x10);
      transfer_command(0x00);
      for(j=0;j<132;j++)
      {
      transfer_data(0x0f);
      }
    }
}
void waitkey()
{
}
void transfer_command(u8 data1)
{
    char i;
    ClrBit_LCD(LCD_PORT->ODR, LCD_CS);
  //  delay_us(1);
    ClrBit_LCD(LCD_PORT->ODR, LCD_RS);  
  //  delay_us(1);
      
  //  cs1=0;
  //  rs=0;
    
    for(i=0;i<8;i++)
    {
      ClrBit_LCD(LCD_PORT->ODR, LCD_SCK);  
      delay_us(1);
      //sclk=0;
      
      if(data1&0x80) 
        SetBit_LCD(LCD_PORT->ODR, LCD_SDA);   //sid=0
      else 
        ClrBit_LCD(LCD_PORT->ODR, LCD_SDA);
        //sid=0;
      delay_us(1);
      SetBit_LCD(LCD_PORT->ODR, LCD_SCK);
      //sclk=1;
      delay_us(1);      
      data1 <<= 1;
    }

}
void transfer_data(u8 data1)
{
      char i;
    ClrBit_LCD(LCD_PORT->ODR, LCD_CS);
    delay_us(1);
    SetBit_LCD(LCD_PORT->ODR, LCD_RS);  
    delay_us(1);
      
  //  cs1=0;
  //  rs=1;
    
    for(i=0;i<8;i++)
    {
      ClrBit_LCD(LCD_PORT->ODR, LCD_SCK);      
      //sclk=0;
      delay_us(1);
      if(data1&0x80) 
        SetBit_LCD(LCD_PORT->ODR, LCD_SDA);   //sid=0
      else 
        ClrBit_LCD(LCD_PORT->ODR, LCD_SDA);
      //sid=0; 
      delay_us(1);
        
      SetBit_LCD(LCD_PORT->ODR, LCD_SCK);
      //sclk=1;  
      delay_us(1);  
      data1 <<= 1;
    }
}



