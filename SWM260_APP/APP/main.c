#include "SWM260.h"

void SerialInit(void);

int main(void)
{
 	uint32_t i;
	
	/* 只能在APP中REMAP，在UserBoot中REMAP可能会导致访问UserBoot的代码被重定向到APP的代码 */
	FMC->REMAP = (1 << FMC_REMAP_ON_Pos) | ((0x8000 / 2048) << FMC_REMAP_OFFSET_Pos);
	__enable_irq();
	
	SystemInit();
	
	SerialInit();
 	
	GPIO_Init(GPIOA, PIN3, 0, 1, 0, 0);		// 输入，开上拉
	GPIO_Init(GPIOA, PIN5, 1, 0, 0, 0);		// 输出
	
	TIMR_Init(TIMR0, TIMR_MODE_TIMER, SystemCoreClock*1.5, 1);
	TIMR_Start(TIMR0);
	
 	while(1==1)
 	{
		printf("Running in App\r\n");
		
		for(i = 0; i < SystemCoreClock/4; i++) __NOP();
		
		
		if(GPIO_GetBit(GPIOA, PIN3) == 0)	// 检测到按键按下，跳到UserBoot
		{
			__disable_irq();
			
			WDT_Init(WDT, 0, 5);			// 通过触发WDT复位跳转到UserBoot
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
	
	PORT_Init(PORTC, PIN13, PORTC_PIN13_UART0_TX, 0);	//GPIOC.13配置为UART0 TXD
	PORT_Init(PORTC, PIN14, PORTC_PIN14_UART0_RX, 1);	//GPIOC.14配置为UART0 RXD
 	
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
* 函数名称: fputc()
* 功能说明: printf()使用此函数完成实际的串口打印动作
* 输    入: int ch		要打印的字符
*			FILE *f		文件句柄
* 输    出: 无
* 注意事项: 无
******************************************************************************************************************************************/
int fputc(int ch, FILE *f)
{
	UART_WriteByte(UART0, ch);
	
	while(UART_IsTXBusy(UART0));
 	
	return ch;
}
