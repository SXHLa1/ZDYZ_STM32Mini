#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"
 void Delay(u32 count)
 {
  u32 i=0;
  for(;i<count;i++);

 }




 int main(void)
 {	
    //Stm32_Clock_Init();
    //Stm32_Clock_Init(9); 
    delay_init();


      
    GPIO_InitTypeDef  GPIO_InitStructure;
 	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOD, ENABLE);	 //使能PA,PD端口时钟
	
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;				 //LED0-->PA.8 端口配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
    GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA.8
    GPIO_SetBits(GPIOA,GPIO_Pin_8);						 //PA.8 输出高-红灯亮

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;	    		 //LED1-->PD.2 端口配置, 推挽输出
    GPIO_Init(GPIOD, &GPIO_InitStructure);	  				 //推挽输出 ，IO口速度为50MHz
    GPIO_SetBits(GPIOD,GPIO_Pin_2); 						 //PD.2 输出高-绿灯亮

    while(1)
    {
        GPIO_ResetBits(GPIOA,GPIO_Pin_8);
        GPIO_SetBits(GPIOD,GPIO_Pin_2);
        delay_ms(1000);
        GPIO_SetBits(GPIOA,GPIO_Pin_8);
        GPIO_ResetBits(GPIOD,GPIO_Pin_2);
        delay_ms(1000);
    }
 }

