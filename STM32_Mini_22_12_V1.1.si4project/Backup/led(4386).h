#ifndef __LED_H
#define __LED_H

#include"sys.h"

#define LED0_PORT GPIOA
#define LED0_PIN  GPIO_Pin_8

#define LED1_PORT GPIOD
#define LED1_PIN  GPIO_Pin_2

void led_init();  //led初始�?
void led_set();


#endif