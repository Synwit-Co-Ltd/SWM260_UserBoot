/****************************************************************************************************************************************** 
* �ļ�����: SWM260_port.c
* ����˵��:	SWM260��Ƭ���Ķ˿����Ź���ѡ��⺯��
* ����֧��:	http://www.synwit.com.cn/e/tool/gbook/?bid=1
* ע������:
* �汾����: V1.0.0		2016��1��30��
* ������¼: 
*
*
*******************************************************************************************************************************************
* @attention
*
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS WITH CODING INFORMATION 
* REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME. AS A RESULT, SYNWIT SHALL NOT BE HELD LIABLE 
* FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT 
* OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION CONTAINED HEREIN IN CONN-
* -ECTION WITH THEIR PRODUCTS.
*
* COPYRIGHT 2012 Synwit Technology 
*******************************************************************************************************************************************/
#include "SWM260.h"
#include "SWM260_port.h"


/****************************************************************************************************************************************** 
* ��������: PORT_Init()
* ����˵��:	�˿����Ź���ѡ�񣬿��õĹ��ܼ�"SWM260_port.h"�ļ�
* ��    ��: uint32_t PORTx	   		ָ��PORT�˿ڣ���Чֵ����PORTA��PORTB��PORTC��PORTD
*			uint32_t n		   		ָ��PORT���ţ���Чֵ����PIN0��PIN1��PIN2��... ... PIN14��PIN15
*			uint32_t func	   		ָ���˿�����Ҫ�趨�Ĺ��ܣ����ȡֵ��"SWM260_port.h"�ļ�
*			uint32_t digit_in_en   	��������ʹ��
* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
void PORT_Init(uint32_t PORTx, uint32_t n, uint32_t func, uint32_t digit_in_en)
{
	switch((uint32_t)PORTx)
	{
		case ((uint32_t)PORTA):
			if(n < PIN8)
			{
				PORT->PORTA_SEL0 &= ~(0x0F << (n*4));
				PORT->PORTA_SEL0 |=  (func << (n*4));
			}
			else
			{
				PORT->PORTA_SEL1 &= ~(0x0F << ((n-8)*4));
				PORT->PORTA_SEL1 |=  (func << ((n-8)*4));
			}
			
			if(digit_in_en)  PORT->PORTA_INEN |=  (1 << n);
			else             PORT->PORTA_INEN &= ~(1 << n);
			break;
			
		case ((uint32_t)PORTB):
			if(n < PIN8)
			{
				PORT->PORTB_SEL0 &= ~(0x0F << (n*4));
				PORT->PORTB_SEL0 |=  (func << (n*4));
			}
			else
			{
				PORT->PORTB_SEL1 &= ~(0x0F << ((n-8)*4));
				PORT->PORTB_SEL1 |=  (func << ((n-8)*4));
			}
			
			if(digit_in_en)  PORT->PORTB_INEN |=  (1 << n);
			else             PORT->PORTB_INEN &= ~(1 << n);
			break;
		
		case ((uint32_t)PORTC):
			if(n < PIN8)
			{
				PORT->PORTC_SEL0 &= ~(0x0F << (n*4));
				PORT->PORTC_SEL0 |=  (func << (n*4));
			}
			else
			{
				PORT->PORTC_SEL1 &= ~(0x0F << ((n-8)*4));
				PORT->PORTC_SEL1 |=  (func << ((n-8)*4));
			}
			
			if(digit_in_en)  PORT->PORTC_INEN |=  (1 << n);
			else             PORT->PORTC_INEN &= ~(1 << n);
			break;
			
		case ((uint32_t)PORTD):
			if(n < PIN8)
			{
				PORT->PORTD_SEL0 &= ~(0x0F << (n*4));
				PORT->PORTD_SEL0 |=  (func << (n*4));
			}
			else
			{
				PORT->PORTD_SEL1 &= ~(0x0F << ((n-8)*4));
				PORT->PORTD_SEL1 |=  (func << ((n-8)*4));
			}
			
			if(digit_in_en)  PORT->PORTD_INEN |=  (1 << n);
			else             PORT->PORTD_INEN &= ~(1 << n);
			break;
	}
}
