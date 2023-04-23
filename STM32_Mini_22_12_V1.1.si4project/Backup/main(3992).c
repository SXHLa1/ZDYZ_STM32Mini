#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"
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
    delay_init(); //��ʱ������ʼ��
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //�����жϷ��� 
    uart_init(9600); //���ڳ�ʼ��Ϊ 9600
    led_init(); //��ʼ���� LED ���ӵ�Ӳ���ӿ�
    while(1)
    {
      if(USART_RX_STA&0x8000)
      { 
        len=USART_RX_STA&0x3fff;//�õ��˴ν��յ������ݳ���
        printf("\r\n �����͵���ϢΪ:\r\n");
        for(t=0;t<len;t++)
        {
            USART1->DR=USART_RX_BUF[t];
            while((USART1->SR&0X40)==0);//�ȴ����ͽ���
        }
        printf("\r\n\r\n");//���뻻��
        USART_RX_STA=0;
      }
      else
      {
        times++;
        if(times%5000==0)
        {
            printf("\r\nALIENTEK MiniSTM32 ������ ����ʵ��\r\n");
            printf("����ԭ��@ALIENTEK\r\n\r\n\r\n");
        }
        if(times%200==0)printf("����������,�Իس�������\r\n"); 
        if(times%30==0)LED0=!LED0;//��˸ LED,��ʾϵͳ��������.
        delay_ms(10); 
      }
    }
 }

