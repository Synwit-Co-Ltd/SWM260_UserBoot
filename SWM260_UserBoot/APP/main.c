#include "SWM260.h"

void SerialInit(void);
void JumpToApp(uint32_t addr);

int main(void)
{
 	uint32_t i, j;
	
	SystemInit();
	
	SerialInit();
 	
	GPIO_Init(GPIOA, PIN3, 0, 1, 0, 0);		// 输入，开上拉
	GPIO_Init(GPIOA, PIN5, 1, 0, 0, 0);		// 输出
	
	if(GPIO_GetBit(GPIOA, PIN3) == 0)		// 检测到特定信号（或者检测到APP程序不完整）
	{
		for(i = 0; i < 10; i++)				// 模拟UserBoot更新APP程序的过程
		{
			GPIO_InvBit(GPIOA, PIN5);
			
			printf("Running in UserBoot\r\n");
			
			for(j = 0; j < SystemCoreClock/24; j++) __NOP();
		}
	}
	else
	{
		printf("Running in UserBoot\r\n");
	}
	
	/* 跳转到APP前需要将UserBoot使用的外设关掉（复位）*/
	__disable_irq();
	GPIO_Init(GPIOA, PIN5, 0, 0, 0, 0);
	
	JumpToApp(0x8000);
	
 	while(1==1)
 	{
 	}
}


void JumpToApp(uint32_t addr)
{	
	uint32_t sp = *((volatile uint32_t *)(addr));
	uint32_t pc = *((volatile uint32_t *)(addr + 4));
	
	typedef void (*Func_void_void)(void);
	Func_void_void ResetHandler = (Func_void_void)pc;
	
	__set_MSP(sp);
	
	ResetHandler();
	
	while(1) __NOP();
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
