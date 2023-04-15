#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"
#include "led.h"
#include "usart_poll.h"

 int main(void)
 {	

    char data;
    delay_init();
    led_init();
    Usart_Poll_Init();
    while(1)
    {   
    
        //led_set();
        data = Usart_GetChar(USART1);
        Usart_SendChar(USART1, data);
    }
 }

