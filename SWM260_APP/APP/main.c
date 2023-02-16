#include "SWM260.h"

void SerialInit(void);

int main(void)
{
 	uint32_t i;
	
	/* ֻ����APP��REMAP����UserBoot��REMAP���ܻᵼ�·���UserBoot�Ĵ��뱻�ض���APP�Ĵ��� */
	FMC->REMAP = (1 << FMC_REMAP_ON_Pos) | ((0x8000 / 2048) << FMC_REMAP_OFFSET_Pos);
	__enable_irq();
	
	SystemInit();
	
	SerialInit();
 	
	GPIO_Init(GPIOA, PIN3, 0, 1, 0, 0);		// ���룬������
	GPIO_Init(GPIOA, PIN5, 1, 0, 0, 0);		// ���
	
	TIMR_Init(TIMR0, TIMR_MODE_TIMER, SystemCoreClock*1.5, 1);
	TIMR_Start(TIMR0);
	
 	while(1==1)
 	{
		printf("Running in App\r\n");
		
		for(i = 0; i < SystemCoreClock/4; i++) __NOP();
		
		
		if(GPIO_GetBit(GPIOA, PIN3) == 0)	// ��⵽�������£�����UserBoot
		{
			__disable_irq();
			
			WDT_Init(WDT, 0, 5);			// ͨ������WDT��λ��ת��UserBoot
			WDT_Start(WDT);
			while(1) __NOP();
		}
 	}
}


void TIMR0_Handler(void)
{
	TIMR_INTClr(TIMR0);
	
	GPIO_InvBit(GPIOA, PIN5);
}


void SerialInit(void)
{
	UART_InitStructure UART_initStruct;
	
	PORT_Init(PORTC, PIN13, PORTC_PIN13_UART0_TX, 0);	//GPIOC.13����ΪUART0 TXD
	PORT_Init(PORTC, PIN14, PORTC_PIN14_UART0_RX, 1);	//GPIOC.14����ΪUART0 RXD
 	
 	UART_initStruct.Baudrate = 57600;
	UART_initStruct.DataBits = UART_DATA_8BIT;
	UART_initStruct.Parity = UART_PARITY_NONE;
	UART_initStruct.StopBits = UART_STOP_1BIT;
	UART_initStruct.RXThresholdIEn = 0;
	UART_initStruct.TXThresholdIEn = 0;
	UART_initStruct.TimeoutIEn = 0;
 	UART_Init(UART0, &UART_initStruct);
	UART_Open(UART0);
}

/****************************************************************************************************************************************** 
* ��������: fputc()
* ����˵��: printf()ʹ�ô˺������ʵ�ʵĴ��ڴ�ӡ����
* ��    ��: int ch		Ҫ��ӡ���ַ�
*			FILE *f		�ļ����
* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
int fputc(int ch, FILE *f)
{
	UART_WriteByte(UART0, ch);
	
	while(UART_IsTXBusy(UART0));
 	
	return ch;
}
