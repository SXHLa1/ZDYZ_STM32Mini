#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"
#include "led.h"


 int main(void)
 {	
 
    delay_init();
    led_init();
    while(1)
    {   
        led_set();
    }
 }

