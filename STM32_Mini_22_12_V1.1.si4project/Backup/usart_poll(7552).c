#include "usart_poll.h"
#include "sys.h"


void Usart_Poll_Init()
{
    GPIO_InitTypeDef GPIO_InitStruct;
    USART_InitTypeDef USART_InitStruct;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_USART1, ENABLE);
    //Usart_TX端口配置
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStruct.GPIO_Pin = TxPin;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(TxPort, &GPIO_InitStruct);
    //Usart_RX端口配置
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStruct.GPIO_Pin = RxPin;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(RxPort, &GPIO_InitStruct);
    //Usart 参数初始化
    USART_InitStruct.USART_BaudRate = 9600;
    USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStruct.USART_Mode = USART_Mode_Rx|USART_Mode_Tx;
    USART_InitStruct.USART_Parity = USART_Parity_No;
    USART_InitStruct.USART_StopBits = USART_StopBits_1;
    USART_InitStruct.USART_WordLength = USART_WordLength_8b;
    USART_Init(USART1, &USART_InitStruct);
    USART_Cmd(USART1, ENABLE);
}

void Usart_SendChar(USART_TypeDef* USARTx,  char data)
{
    while(!USART_GetFlagStatus(USARTx, USART_FLAG_TXE));
    USART_SendData(USARTx, data);
}
char Usart_GetChar(USART_TypeDef* USARTx)
{
    char data;
    while(!USART_GetFlagStatus(USARTx, USART_FLAG_RXNE));
    data = (char)(USART_ReceiveData(USARTx)&0xff);
    return data;
    
}

