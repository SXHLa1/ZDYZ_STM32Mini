#ifndef __USART_POLL_H
#define __USART_POLL_H
#include "sys.h"

#define TxPort  GPIOA
#define TxPin   GPIO_Pin_9
#define RxPort  GPIOA
#define RxPin   GPIO_Pin_10
#define BaudRate 9600


void Usart_Poll_Init(void);
void Usart_SendChar(USART_TypeDef* USARTx,  char data);
char Usart_GetChar(USART_TypeDef* USARTx);



#endif
