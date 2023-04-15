#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"

 int main(void)
 {	
    //Stm32_Clock_Init();
    //Stm32_Clock_Init(9); 
    delay_init();
    led_init();
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

