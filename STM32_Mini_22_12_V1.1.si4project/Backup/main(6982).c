#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "led.h"
#include "usart_poll.h"

 int main(void)
 {	

//    char data;
//    delay_init();
//    led_init();
//    Usart_Poll_Init();
//    while(1)
//    {   
//    
//        //led_set();
//        data = Usart_GetChar(USART1);
//        Usart_SendChar(USART1, data);
//    }

    
    u8 t;
    u8 len;
    u16 times=0; 
    delay_init(); //延时函数初始化
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置中断分组 
    uart_init(9600); //串口初始化为 9600
    led_init(); //初始化与 LED 连接的硬件接口
    while(1)
    {
      if(USART_RX_STA&0x8000)
      { 
        len=USART_RX_STA&0x3fff;//得到此次接收到的数据长度
        printf("\r\n 您发送的消息为:\r\n");
        for(t=0;t<len;t++)
        {
            USART1->DR=USART_RX_BUF[t];
            while((USART1->SR&0X40)==0);//等待发送结束
        }
        printf("\r\n\r\n");//插入换行
        USART_RX_STA=0;
      }
      else
      {
        times++;
        if(times%5000==0)
        {
            printf("\r\nALIENTEK MiniSTM32 开发板 串口实验\r\n");
            printf("正点原子@ALIENTEK\r\n\r\n\r\n");
        }
        if(times%200==0)printf("请输入数据,以回车键结束\r\n"); 
        //if(times%30==0)LED0=!LED0;//闪烁 LED,提示系统正在运行.
        delay_ms(10); 
      }
    }
 }

