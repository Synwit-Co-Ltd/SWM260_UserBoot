#ifndef __SWM260_H__
#define __SWM260_H__

/*
 * ==========================================================================
 * ---------- Interrupt Number Definition -----------------------------------
 * ==========================================================================
 */
typedef enum IRQn
{
/******  Cortex-M0 Processor Exceptions Numbers **********************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                        */
  HardFault_IRQn	          = -13,	/*!< 3 Cortex-M0 Hard Fault Interrupt				 */
  SVCall_IRQn                 = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                  */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                  */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M0 System Tick Interrupt              */
  
/******  Cortex-M0 specific Interrupt Numbers ************************************************/
  UART0_IRQn               = 0,
  TIMR0_IRQn               = 1,
  SPI0_IRQn                = 2,
  UART1_IRQn               = 3,
  UART2_IRQn               = 4,
  TIMR1_IRQn               = 5,
  DMA_IRQn                 = 6,
  PWM0_IRQn                = 7,
  BTIMR0_IRQn              = 8,
  TIMR2_IRQn               = 9,
  TIMR3_IRQn               = 10,
  WDT_IRQn                 = 11,
  I2C4_IRQn                = 12,
  UART3_IRQn               = 13,
  ADC0_IRQn                = 14,
  BTIMR1_IRQn              = 15,
  GPIOA9_GPIOC6_IRQn       = 16,
  GPIOA6_GPIOC7_IRQn       = 17,
  GPIOA7_GPIOC8_IRQn       = 18,
  GPIOA8_GPIOC9_IRQn       = 19,
  GPIOA10_GPIOC10_IRQn     = 20,
  GPIOA13_GPIOC12_IRQn     = 21,
  GPIOA12_GPIOC13_IRQn     = 22,
  GPIOA11_GPIOC14_IRQn     = 23,
  XTALSTOPDET_GPIOC0_IRQn  = 24,
  BTIMR2_GPIOB12_IRQn      = 25,
  PWM1_GPIOA1_IRQn         = 26,
  PWM2_UART4_IRQn          = 27,
  BOD_PWMHALT_IRQn         = 28,
  PWM3_GPIOB_ACMP_IRQn     = 29,
  SPI1_HALL_GPIOD_IRQn     = 30,
  BTIMR3_RTC_IRQn          = 31,
} IRQn_Type;

/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

/* Configuration of the Cortex-M0 Processor and Core Peripherals */
#define __MPU_PRESENT		    0	   /*!< UART does not provide a MPU present or not	     */
#define __NVIC_PRIO_BITS		2	   /*!< UART Supports 2 Bits for the Priority Levels	 */
#define __Vendor_SysTickConfig  0	   /*!< Set to 1 if different SysTick Config is used	 */

#if   defined ( __CC_ARM )
  #pragma anon_unions
#endif

#include <stdio.h>
#include "core_cm0.h"				   /* Cortex-M0 processor and core peripherals		     */
#include "system_SWM260.h"


/******************************************************************************/
/*				Device Specific Peripheral registers structures			 */
/******************************************************************************/
typedef struct {
	__IO uint32_t CLKSEL;				    //Clock Select

	__IO uint32_t CLKDIVx_ON;				//[0] CLK_DIVxʱ��Դ����

	__IO uint32_t CLKEN0;					//Clock Enable
	
	__IO uint32_t CLKEN1;

	__IO uint32_t SLEEP;
	
		 uint32_t RESERVED[4];
	
	__IO uint32_t RSTSR;					//Reset Status
	
		 uint32_t RESERVED2[2];
	
	__IO uint32_t RTCWKCR;					//RTC Wakeup Control
	
	__IO uint32_t RTCWKSR;
	
		 uint32_t RESERVED3[18];
	
	__I  uint32_t CHIPID[4];
	
	__IO uint32_t BACKUP[4];				//Data Backup Register
	
		 uint32_t RESERVED4[12];
	
	__IO uint32_t PRNGCR;					//α��������ƼĴ���
	
	__IO uint32_t PRNGDL;					//α��������ݼĴ�����32λ
	
	__IO uint32_t PRNGDH;					//α��������ݼĴ�����32λ
	
		 uint32_t RESERVED5[9];
		 
	__IO uint32_t PAWKEN;				    //PORTA Wakeup Enable
	__IO uint32_t PBWKEN;
	__IO uint32_t PCWKEN;
	__IO uint32_t PDWKEN;
	
         uint32_t RESERVED6[8];

	__IO uint32_t PAWKSR;				    //PORTA Wakeup Status��д1����
	__IO uint32_t PBWKSR;
	__IO uint32_t PCWKSR;
	__IO uint32_t PDWKSR;

    //Analog Control: 0x400AA000
         uint32_t RESERVED7[(0x400AA000-0x4000013C)/4-1];
	
	__IO uint32_t HRCCR;					//High speed RC Control Register
		 uint32_t RESERVED8[3];
    
    __IO uint32_t BODCR;
	__IO uint32_t BODSR;
	
		 uint32_t RESERVED9[2];
	
	__IO uint32_t XTALCR;
	__IO uint32_t XTALSR;
	
		 uint32_t RESERVED10[6];
	
	__IO uint32_t PLLCR;
    __IO uint32_t PLLDIV;
		 uint32_t RESERVED11;
    __IO uint32_t PLLLOCK;                  //[0] 1 PLL������
	
    __IO uint32_t LRCCR;					//Low speed RC Control Register
    
         uint32_t RESERVED12[7];
	
	__IO uint32_t OPACR;					//OPA Control Register
	
		 uint32_t RESERVED13[3];
	
	__IO uint32_t ACMPCR;					//Analog Comparator Control Register
	__IO uint32_t ACMPSR;					//Analog Comparator Status Register
} SYS_TypeDef;


#define SYS_CLKSEL_SYS_Pos			0		//ϵͳʱ��ѡ��	1 HRC	0 CLK_DIVx
#define SYS_CLKSEL_SYS_Msk			(0x01 << SYS_CLKSEL_SYS_Pos)
#define SYS_CLKSEL_CLK_DIVx_Pos		1		//ѡ��CLK_DIVx  0 CLK_DIV1   1 CLK_DIV8
#define SYS_CLKSEL_CLK_DIVx_Msk		(0x01 << SYS_CLKSEL_CLK_DIVx_Pos)
#define SYS_CLKSEL_CLK_Pos			2		//Clock Source	0 LRC	1 PLL   2 XTAL_32K   3 XTAL   4 HRC
#define SYS_CLKSEL_CLK_Msk			(0x07 << SYS_CLKSEL_CLK_Pos)
#define SYS_CLKSEL_RTC_Pos			5		//RTCʱ��Դѡ��  0 LRC   1 XTAL_32K
#define SYS_CLKSEL_RTC_Msk			(0x01 << SYS_CLKSEL_RTC_Pos)
#define SYS_CLKSEL_WDT_Pos			12		//���Ź�ʱ��ѡ��  0 HRC   1 XTAL   2 LRC   3 XTAL_32K
#define SYS_CLKSEL_WDT_Msk			(0x03 << SYS_CLKSEL_WDT_Pos)
#define SYS_CLKSEL_RTCTRIM_Pos		14		//RTC Trim�ο�ʱ��  0 XTAL   1 XTAL/2   2 XTAL/4   3 XTAL/8
#define SYS_CLKSEL_RTCTRIM_Msk		(0x03 << SYS_CLKSEL_RTCTRIM_Pos)
#define SYS_CLKSEL_ADC_Pos			16		//ADCʱ��ѡ��  0 HRC   1 XTAL   4 HRC/4   5 XTAL/4   6 HRC/8   7 XTAL/8
#define SYS_CLKSEL_ADC_Msk			(0x07 << SYS_CLKSEL_ADC_Pos)

#define SYS_CLKDIV_ON_Pos           0
#define SYS_CLKDIV_ON_Msk           (0x01 << SYS_CLKDIV_ON_Pos)

#define SYS_CLKEN0_GPIOA_Pos		0
#define SYS_CLKEN0_GPIOA_Msk		(0x01 << SYS_CLKEN0_GPIOA_Pos)
#define SYS_CLKEN0_GPIOB_Pos		1
#define SYS_CLKEN0_GPIOB_Msk		(0x01 << SYS_CLKEN0_GPIOB_Pos)
#define SYS_CLKEN0_GPIOC_Pos		2
#define SYS_CLKEN0_GPIOC_Msk		(0x01 << SYS_CLKEN0_GPIOC_Pos)
#define SYS_CLKEN0_GPIOD_Pos		3
#define SYS_CLKEN0_GPIOD_Msk		(0x01 << SYS_CLKEN0_GPIOD_Pos)
#define SYS_CLKEN0_UART0_Pos		6
#define SYS_CLKEN0_UART0_Msk		(0x01 << SYS_CLKEN0_UART0_Pos)
#define SYS_CLKEN0_UART1_Pos		7
#define SYS_CLKEN0_UART1_Msk		(0x01 << SYS_CLKEN0_UART1_Pos)
#define SYS_CLKEN0_UART2_Pos		8
#define SYS_CLKEN0_UART2_Msk		(0x01 << SYS_CLKEN0_UART2_Pos)
#define SYS_CLKEN0_UART3_Pos		9
#define SYS_CLKEN0_UART3_Msk		(0x01 << SYS_CLKEN0_UART3_Pos)
#define SYS_CLKEN0_WDT_Pos			10
#define SYS_CLKEN0_WDT_Msk			(0x01 << SYS_CLKEN0_WDT_Pos)
#define SYS_CLKEN0_TIMR_Pos			11
#define SYS_CLKEN0_TIMR_Msk			(0x01 << SYS_CLKEN0_TIMR_Pos)
#define SYS_CLKEN0_PWM_Pos			12
#define SYS_CLKEN0_PWM_Msk			(0x01 << SYS_CLKEN0_PWM_Pos)
#define SYS_CLKEN0_SPI0_Pos			13
#define SYS_CLKEN0_SPI0_Msk			(0x01 << SYS_CLKEN0_SPI0_Pos)
#define SYS_CLKEN0_SPI1_Pos			14
#define SYS_CLKEN0_SPI1_Msk			(0x01 << SYS_CLKEN0_SPI1_Pos)
#define SYS_CLKEN0_ANAC_Pos			25		//ģ����Ƶ�Ԫʱ��ʹ��
#define SYS_CLKEN0_ANAC_Msk			(0x01 << SYS_CLKEN0_ANAC_Pos)
#define SYS_CLKEN0_ADC0_Pos			26
#define SYS_CLKEN0_ADC0_Msk			(0x01 << SYS_CLKEN0_ADC0_Pos)

#define SYS_CLKEN1_UART4_Pos		4
#define SYS_CLKEN1_UART4_Msk		(0x01 << SYS_CLKEN1_UART4_Pos)
#define SYS_CLKEN1_I2C4_Pos			10
#define SYS_CLKEN1_I2C4_Msk			(0x01 << SYS_CLKEN1_I2C4_Pos)
#define SYS_CLKEN1_RTC_Pos			19
#define SYS_CLKEN1_RTC_Msk			(0x01 << SYS_CLKEN1_RTC_Pos)
#define SYS_CLKEN1_BTIMR_Pos		22
#define SYS_CLKEN1_BTIMR_Msk		(0x01 << SYS_CLKEN1_BTIMR_Pos)

#define SYS_SLEEP_SLEEP_Pos			0		//����λ��1��ϵͳ������SLEEPģʽ
#define SYS_SLEEP_SLEEP_Msk			(0x01 << SYS_SLEEP_SLEEP_Pos)
#define SYS_SLEEP_STOP_Pos			1		//����λ��1��ϵͳ������STOP SLEEPģʽ
#define SYS_SLEEP_STOP_Msk			(0x01 << SYS_SLEEP_STOP_Pos)

#define SYS_RSTSR_POR_Pos			0		//1 ���ֹ�POR��λ��д1����
#define SYS_RSTSR_POR_Msk			(0x01 << SYS_RSTSR_POR_Pos)
#define SYS_RSTSR_WDT_Pos			1		//1 ���ֹ�WDT��λ��д1����
#define SYS_RSTSR_WDT_Msk			(0x01 << SYS_RSTSR_WDT_Pos)

#define SYS_RTCWKCR_EN_Pos			0		//RTC����ʹ��
#define SYS_RTCWKCR_EN_Msk			(0x01 << SYS_RTCWKCR_EN_Pos)

#define SYS_RTCWKSR_FLAG_Pos		0		//RTC���ѱ�־��д1����
#define SYS_RTCWKSR_FLAG_Msk		(0x01 << SYS_RTCWKSR_FLAG_Pos)

#define SYS_PRNGCR_CLR_Pos			0		//�������㣬���ٱ���һ��LRCʱ������
#define SYS_PRNGCR_CLR_Msk			(0x01 << SYS_PRNGCR_CLR_Pos)
#define SYS_PRNGCR_MODE_Pos			1		//0 �ر�   2 ���뿪��XTAL���ܹ���   3 ���迪��XTAL��ֻ�迪��HRC��LRC��
#define SYS_PRNGCR_MODE_Msk			(0x03 << SYS_PRNGCR_MODE_Pos)
#define SYS_PRNGCR_RDY_Pos			8		//1 ���Դ�PRNGDL��PRNGDH��ȡ����
#define SYS_PRNGCR_RDY_Msk			(0x01 << SYS_PRNGCR_RDY_Pos)

#define SYS_HRCCR_ON_Pos			0		//High speed RC ON
#define SYS_HRCCR_ON_Msk			(0x01 << SYS_HRCCR_ON_Pos)
#define SYS_HRCCR_DBL_Pos		    1		//Double Frequency	0 24MHz	  1 48MHz
#define SYS_HRCCR_DBL_Msk		    (0x01 << SYS_HRCCR_DBL_Pos)

#define SYS_BODCR_IE_Pos		    1		//Interrupt Enable
#define SYS_BODCR_IE_Msk		    (0x01 << SYS_BODCR_IE_Pos)
#define SYS_BODCR_RSTLVL_Pos		4		//BOD��λ��ƽ��0 2.0V   1 1.7V
#define SYS_BODCR_RSTLVL_Msk		(0x01 << SYS_BODCR_RSTLVL_Pos)
#define SYS_BODCR_INTLVL_Pos		5		//BOD�жϴ�����ƽ��0 2.7V   1 2.3V   2 2.0V 
#define SYS_BODCR_INTLVL_Msk		(0x03 << SYS_BODCR_INTLVL_Pos)

#define SYS_BODSR_IF_Pos			0		//�жϱ�־��д1����
#define SYS_BODSR_IF_Msk			(0x01 << SYS_BODSR_IF_Pos)

#define SYS_XTALCR_32KON_Pos		0		//XTAL_32K On
#define SYS_XTALCR_32KON_Msk		(0x01 << SYS_XTALCR_32KON_Pos)
#define SYS_XTALCR_ON_Pos			1		//XTAL On
#define SYS_XTALCR_ON_Msk			(0x01 << SYS_XTALCR_ON_Pos)
#define SYS_XTALCR_32KDET_Pos		4		//XTAL_32K Stop Detect
#define SYS_XTALCR_32KDET_Msk		(0x01 << SYS_XTALCR_32KDET_Pos)
#define SYS_XTALCR_DET_Pos			5		//XTAL Stop Detect
#define SYS_XTALCR_DET_Msk			(0x01 << SYS_XTALCR_DET_Pos)
#define SYS_XTALCR_32KDRV_Pos		8		//XTAL_32K ������������΢��Ƶ��
#define SYS_XTALCR_32KDRV_Msk		(0x0F << SYS_XTALCR_32KDRV_Pos)
#define SYS_XTALCR_DRV_Pos			16		//XTAL ������������΢��Ƶ��
#define SYS_XTALCR_DRV_Msk			(0x1F << SYS_XTALCR_DRV_Pos)

#define SYS_XTALSR_32KSTOP_Pos		0		//XTAL_32K Stop��д1����
#define SYS_XTALSR_32KSTOP_Msk		(0x01 << SYS_XTALSR_32KSTOP_Pos)
#define SYS_XTALSR_STOP_Pos			1		//XTAL Stop��д1����
#define SYS_XTALSR_STOP_Msk			(0x01 << SYS_XTALSR_STOP_Pos)

#define SYS_PLLCR_OUTEN_Pos		    0       //ֻ��LOCK������
#define SYS_PLLCR_OUTEN_Msk		    (0x01 << SYS_PLLCR_OUTEN_Pos)
#define SYS_PLLCR_INSEL_Pos		    1       //0 XTAL    1 HRC
#define SYS_PLLCR_INSEL_Msk		    (0x01 << SYS_PLLCR_INSEL_Pos)
#define SYS_PLLCR_OFF_Pos		    2
#define SYS_PLLCR_OFF_Msk		    (0x01 << SYS_PLLCR_OFF_Pos)
#define SYS_PLLCR_RST_Pos			3
#define SYS_PLLCR_RST_Msk			(0x01 << SYS_PLLCR_RST_Pos)

#define SYS_PLLDIV_FBDIV_Pos		0       //PLL FeedBack��Ƶ�Ĵ���
											//VCO���Ƶ�� = PLL����ʱ�� / INDIV * 4 * FBDIV
											//PLL���Ƶ�� = PLL����ʱ�� / INDIV * 4 * FBDIV / OUTDIV = VCO���Ƶ�� / OUTDIV
#define SYS_PLLDIV_FBDIV_Msk		(0x1FF << SYS_PLLDIV_FBDIV_Pos)
#define SYS_PLLDIV_ADDIV_Pos		9       //ADCʱ�ӻ�����VCO�����Ƶ���ʱ�ӣ���ADDIV��Ƶ����ΪADC��ת��ʱ��
#define SYS_PLLDIV_ADDIV_Msk		(0x1F << SYS_PLLDIV_ADDIV_Pos)
#define SYS_PLLDIV_ADVCO_Pos		14		//0 VCO���16��Ƶ��ΪADCʱ�ӻ�    1 VCO�������32��Ƶ��ΪADCʱ�ӻ�    2 VCO�������64��Ƶ��ΪADCʱ�ӻ�
#define SYS_PLLDIV_ADVCO_Msk		(0x03 << SYS_PLLDIV_ADVCO_Pos)
#define SYS_PLLDIV_INDIV_Pos		16      //PLL ����Դʱ�ӷ�Ƶ
#define SYS_PLLDIV_INDIV_Msk		(0x1F << SYS_PLLDIV_INDIV_Pos)
#define SYS_PLLDIV_OUTDIV_Pos		24      //PLL �����Ƶ��0 8��Ƶ    1 4��Ƶ    0 2��Ƶ
#define SYS_PLLDIV_OUTDIV_Msk		(0x03 << SYS_PLLDIV_OUTDIV_Pos)

#define SYS_LRCCR_ON_Pos			0		//Low Speed RC On
#define SYS_LRCCR_ON_Msk			(0x01 << SYS_LRCCR_ON_Pos)

#define SYS_OPACR_OPA0ON_Pos		0		//OPA 0 ����
#define SYS_OPACR_OPA0ON_Msk		(0x01 << SYS_OPACR_OPA0ON_Pos)
#define SYS_OPACR_OPA1ON_Pos		1
#define SYS_OPACR_OPA1ON_Msk		(0x01 << SYS_OPACR_OPA1ON_Pos)

#define SYS_ACMPCR_CMP0ON_Pos		0		//CMP0 ����
#define SYS_ACMPCR_CMP0ON_Msk		(0x01 << SYS_ACMPCR_CMP0ON_Pos)
#define SYS_ACMPCR_CMP0HYS_Pos		3		//CMP0 ���Ϳ���
#define SYS_ACMPCR_CMP0HYS_Msk		(0x01 << SYS_ACMPCR_CMP0HYS_Pos)
#define SYS_ACMPCR_CMP0IE_Pos		6		//CMP0 �ж�ʹ��
#define SYS_ACMPCR_CMP0IE_Msk		(0x01 << SYS_ACMPCR_CMP0IE_Pos)

#define SYS_ACMPSR_CMP0OUT_Pos		0		//0 N > P   1 P > N
#define SYS_ACMPSR_CMP0OUT_Msk		(0x01 << SYS_ACMPSR_CMP0OUT_Pos)
#define SYS_ACMPSR_CMP0IF_Pos		3		//�жϱ�־��д1����
#define SYS_ACMPSR_CMP0IF_Msk		(0x01 << SYS_ACMPSR_CMP0IF_Pos)




typedef struct {
	__IO uint32_t PORTA_SEL0;
	
	__IO uint32_t PORTA_SEL1;
	
		 uint32_t RESERVED[2];
	
	__IO uint32_t PORTB_SEL0;
	
	__IO uint32_t PORTB_SEL1;
	
		 uint32_t RESERVED2[2];
    
    __IO uint32_t PORTC_SEL0;
	
	__IO uint32_t PORTC_SEL1;
	
		 uint32_t RESERVED3[2];
	
	__IO uint32_t PORTD_SEL0;
	
	__IO uint32_t PORTD_SEL1;
	
		 uint32_t RESERVED10[50];
	
    __IO uint32_t PORTA_PULLU;              //����ʹ��
    
         uint32_t RESERVED11[3];
    
	__IO uint32_t PORTB_PULLU;
    
         uint32_t RESERVED12[3];
		 
    __IO uint32_t PORTC_PULLU;
    
         uint32_t RESERVED13[3];
		 
	__IO uint32_t PORTD_PULLU;
        
         uint32_t RESERVED20[51];
    
    __IO uint32_t PORTA_PULLD;              //����ʹ��
    
         uint32_t RESERVED21[3];
	
	__IO uint32_t PORTB_PULLD;
    
         uint32_t RESERVED22[3];

    __IO uint32_t PORTC_PULLD;
    
         uint32_t RESERVED23[3];
	
	__IO uint32_t PORTD_PULLD;
    
         uint32_t RESERVED30[51];
    
    __IO uint32_t PORTA_INEN;               //����ʹ��
    
         uint32_t RESERVED31[3];
	
    __IO uint32_t PORTB_INEN;
    
         uint32_t RESERVED32[3];

    __IO uint32_t PORTC_INEN;
    
         uint32_t RESERVED33[3];
	
	__IO uint32_t PORTD_INEN;
        
         uint32_t RESERVED40[51];

	__IO uint32_t PORTA_OPEND;              //��©ʹ��
    
         uint32_t RESERVED41[3];
	
    __IO uint32_t PORTB_OPEND;
    
         uint32_t RESERVED42[3];

    __IO uint32_t PORTC_OPEND;
    
         uint32_t RESERVED43[3];
	
	__IO uint32_t PORTD_OPEND;	 
} PORT_TypeDef;




typedef struct {
	__IO uint32_t ODR;
#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7
#define PIN8    8
#define PIN9    9
#define PIN10   10
#define PIN11   11
#define PIN12   12
#define PIN13   13
#define PIN14   14
#define PIN15   15

	__IO uint32_t DIR;					    //0 ����	1 ���

	__IO uint32_t INTLVLTRG;				//Interrupt Level Trigger  1 ��ƽ�����ж�	0 ���ش����ж�

	__IO uint32_t INTBE;					//Both Edge����INTLVLTRG��Ϊ���ش����ж�ʱ����λ��1��ʾ�����غ��½��ض������жϣ���0ʱ����������INTRISEENѡ��

	__IO uint32_t INTRISEEN;				//Interrupt Rise Edge Enable   1 ������/�ߵ�ƽ�����ж�	0 �½���/�͵�ƽ�����ж�

	__IO uint32_t INTEN;					//1 �ж�ʹ��	0 �жϽ�ֹ

	__IO uint32_t INTRAWSTAT;			    //�жϼ�ⵥԪ�Ƿ��⵽�˴����жϵ����� 1 ��⵽���жϴ�������	0 û�м�⵽�жϴ�������

	__IO uint32_t INTSTAT;				    //INTSTAT.PIN0 = INTRAWSTAT.PIN0 & INTEN.PIN0

	__IO uint32_t INTCLR;				    //д1����жϱ�־��ֻ�Ա��ش����ж�����

	__IO uint32_t DMAEN;
	
		 uint32_t RESERVED[2];
	
	__IO uint32_t IDR;
	
		 uint32_t RESERVED2[3];
	
	__IO uint32_t DATAPIN0;					//PIN0���ŵ�DATA�Ĵ������������Ŷ�Ӧ����32λ�Ĵ���������ʵ��ԭ��д����
	__IO uint32_t DATAPIN1;
	__IO uint32_t DATAPIN2;
	__IO uint32_t DATAPIN3;
	__IO uint32_t DATAPIN4;
	__IO uint32_t DATAPIN5;
	__IO uint32_t DATAPIN6;
	__IO uint32_t DATAPIN7;
	__IO uint32_t DATAPIN8;
	__IO uint32_t DATAPIN9;
	__IO uint32_t DATAPIN10;
	__IO uint32_t DATAPIN11;
	__IO uint32_t DATAPIN12;
	__IO uint32_t DATAPIN13;
	__IO uint32_t DATAPIN14;
	__IO uint32_t DATAPIN15;
} GPIO_TypeDef;




typedef struct {
	__IO uint32_t LOAD;						//��ʱ������ֵ��ʹ�ܺ�ʱ���Ӵ���ֵ��ʼ���µݼ�����

	__I  uint32_t VALUE;					//��ʱ����ǰֵ��LDVAL-CVAL �ɼ������ʱʱ��

	union {
		__IO uint32_t CR;
		
		__IO uint32_t PREDIV;				//Ԥ��Ƶ
	};
	
	__IO uint32_t IE;
	
	__IO uint32_t IM;
	
	__IO uint32_t IF;
	
	__IO uint32_t HALT;						//[0] 1 ��ͣ����    0 �ָ�����
	
	__IO uint32_t OCCR;
	
	__IO uint32_t OCMAT0;
	__IO uint32_t OCMAT1;
	
	__IO uint32_t ICLOW;
	__IO uint32_t ICHIGH;
} TIMR_TypeDef;


#define TIMR_LOAD_LOAD_Pos			24		//����TIMR4-7������ֵֻ��24λ��Ĭ�������д��LOAD�Ĵ�����ֵ��TIMR������0���¼���LOADֵʱ��Ч�����дLOAD�Ĵ���ʱͬʱ��λ��λ����������LOADֵ���ص���������
#define TIMR_LOAD_LOAD_Msk			(0x01 << TIMR_LOAD_LOAD_Pos)

#define TIMR_CR_CLKSRC_Pos			0		//ʱ��Դ��  0 �ڲ�ϵͳʱ��	2 �ⲿ�����������
#define TIMR_CR_CLKSRC_Msk			(0x03 << TIMR_CR_CLKSRC_Pos)
#define TIMR_CR_MODE_Pos			2		//����ģʽ��0 ��ʱ��    1 ���벶��    2 ����Ƚ�
#define TIMR_CR_MODE_Msk			(0x03 << TIMR_CR_MODE_Pos)

#define TIMR_IE_TO_Pos				0		//Time out
#define TIMR_IE_TO_Msk				(0x01 << TIMR_IE_TO_Pos)
#define TIMR_IE_OC0_Pos				1		//����Ƚϣ���һ����ת��
#define TIMR_IE_OC0_Msk				(0x01 << TIMR_IE_OC0_Pos)
#define TIMR_IE_OC1_Pos				2		//����Ƚϣ��ڶ�����ת��
#define TIMR_IE_OC1_Msk				(0x01 << TIMR_IE_OC1_Pos)
#define TIMR_IE_ICR_Pos				3		//���벶���������ж�
#define TIMR_IE_ICR_Msk				(0x01 << TIMR_IE_ICR_Pos)
#define TIMR_IE_ICF_Pos				4		//���벶���½����ж�
#define TIMR_IE_ICF_Msk				(0x01 << TIMR_IE_ICF_Pos)

#define TIMR_IM_TO_Pos				0
#define TIMR_IM_TO_Msk				(0x01 << TIMR_IM_TO_Pos)
#define TIMR_IM_OC0_Pos				1
#define TIMR_IM_OC0_Msk				(0x01 << TIMR_IM_OC0_Pos)
#define TIMR_IM_OC1_Pos				2
#define TIMR_IM_OC1_Msk				(0x01 << TIMR_IM_OC1_Pos)
#define TIMR_IM_ICR_Pos				3
#define TIMR_IM_ICR_Msk				(0x01 << TIMR_IM_ICR_Pos)
#define TIMR_IM_ICF_Pos				4
#define TIMR_IM_ICF_Msk				(0x01 << TIMR_IM_ICF_Pos)

#define TIMR_IF_TO_Pos				0		//��ʱ�жϱ�־��д1����
#define TIMR_IF_TO_Msk				(0x01 << TIMR_IF_TO_Pos)
#define TIMR_IF_OC0_Pos				1
#define TIMR_IF_OC0_Msk				(0x01 << TIMR_IF_OC0_Pos)
#define TIMR_IF_OC1_Pos				2
#define TIMR_IF_OC1_Msk				(0x01 << TIMR_IF_OC1_Pos)
#define TIMR_IF_ICR_Pos				3
#define TIMR_IF_ICR_Msk				(0x01 << TIMR_IF_ICR_Pos)
#define TIMR_IF_ICF_Pos				4
#define TIMR_IF_ICF_Msk				(0x01 << TIMR_IF_ICF_Pos)

#define TIMR_OCCR_FORCELVL_Pos		0		//Force Levle��ǿ�������ƽ
#define TIMR_OCCR_FORCELVL_Msk		(0x01 << TIMR_OCCR_FORCELVL_Pos)
#define TIMR_OCCR_INITLVL_Pos		1		//Initial Level, ��ʼ�����ƽ
#define TIMR_OCCR_INITLVL_Msk		(0x01 << TIMR_OCCR_INITLVL_Pos)
#define TIMR_OCCR_FORCEEN_Pos		2		//Force Enable, ǿ�����ʹ��
#define TIMR_OCCR_FORCEEN_Msk		(0x01 << TIMR_OCCR_FORCEEN_Pos)


typedef struct {
	__IO uint32_t HALLIE;					//[0] HALL�ж�ʹ��
	
	__IO uint32_t HALLIM;					//[0] HALL�ж�����
	
	__IO uint32_t HALLIF;
	
	__IO uint32_t HALLMD;
	
	__IO uint32_t HALLV0;					//HALL�ź�0����ʱ������������ֵ
	
	__IO uint32_t HALLV1;
	
	__IO uint32_t HALLV2;
	
		 uint32_t RESERVED[9];
	
	__IO uint32_t EN;
} TIMRG_TypeDef;


#define TIMRG_HALLIF_IN0_Pos		0		//HALL�����ź�0�����жϱ�־
#define TIMRG_HALLIF_IN0_Msk		(0x01 << TIMRG_HALLIF_IN0_Pos)
#define TIMRG_HALLIF_IN1_Pos		1
#define TIMRG_HALLIF_IN1_Msk		(0x01 << TIMRG_HALLIF_IN1_Pos)
#define TIMRG_HALLIF_IN2_Pos		2
#define TIMRG_HALLIF_IN2_Msk		(0x01 << TIMRG_HALLIF_IN2_Pos)

#define TIMRG_HALLMD_IN0_Pos		0		//HALL�����ź�0ģʽ��0 ������   1 �����ش���   2 �½��ش���   3 ˫���ش���
#define TIMRG_HALLMD_IN0_Msk		(0x03 << TIMRG_HALLMD_IN0_Pos)
#define TIMRG_HALLMD_IN1_Pos		2
#define TIMRG_HALLMD_IN1_Msk		(0x03 << TIMRG_HALLMD_IN1_Pos)
#define TIMRG_HALLMD_IN2_Pos		4
#define TIMRG_HALLMD_IN2_Msk		(0x03 << TIMRG_HALLMD_IN2_Pos)

#define TIMRG_EN_TIMR0_Pos			0
#define TIMRG_EN_TIMR0_Msk			(0x01 << TIMRG_EN_TIMR0_Pos)
#define TIMRG_EN_TIMR1_Pos			1
#define TIMRG_EN_TIMR1_Msk			(0x01 << TIMRG_EN_TIMR1_Pos)
#define TIMRG_EN_TIMR2_Pos			2
#define TIMRG_EN_TIMR2_Msk			(0x01 << TIMRG_EN_TIMR2_Pos)
#define TIMRG_EN_TIMR3_Pos			3
#define TIMRG_EN_TIMR3_Msk			(0x01 << TIMRG_EN_TIMR3_Pos)




typedef struct {
	__IO uint32_t DATA;
	
	__IO uint32_t CTRL;
	
	__IO uint32_t BAUD;
	
	__IO uint32_t FIFO;
	
	__IO uint32_t LINCR;
	
	union {
		__IO uint32_t CTSCR;
		
		__IO uint32_t RTSCR;
	};
	
	__IO uint32_t CFG;
} UART_TypeDef;


#define UART_DATA_DATA_Pos			0
#define UART_DATA_DATA_Msk			(0x1FF << UART_DATA_DATA_Pos)
#define UART_DATA_VALID_Pos			9		//��DATA�ֶ�����Ч�Ľ�������ʱ����λӲ����1����ȡ���ݺ��Զ�����
#define UART_DATA_VALID_Msk			(0x01 << UART_DATA_VALID_Pos)
#define UART_DATA_PAERR_Pos			10		//Parity Error
#define UART_DATA_PAERR_Msk			(0x01 << UART_DATA_PAERR_Pos)

#define UART_CTRL_TXIDLE_Pos		0		//TX IDLE: 0 ���ڷ�������	1 ����״̬��û�����ݷ���
#define UART_CTRL_TXIDLE_Msk		(0x01 << UART_CTRL_TXIDLE_Pos)
#define UART_CTRL_TXFF_Pos		    1		//TX FIFO Full
#define UART_CTRL_TXFF_Msk		    (0x01 << UART_CTRL_TXFF_Pos)
#define UART_CTRL_TXIE_Pos			2		//TX �ж�ʹ��: 1 TX FF �����������趨����ʱ�����ж�
#define UART_CTRL_TXIE_Msk			(0x01 << UART_CTRL_TXIE_Pos)
#define UART_CTRL_RXNE_Pos			3		//RX FIFO Not Empty
#define UART_CTRL_RXNE_Msk			(0x01 << UART_CTRL_RXNE_Pos)
#define UART_CTRL_RXIE_Pos			4		//RX �ж�ʹ��: 1 RX FF �����ݴﵽ�趨����ʱ�����ж�
#define UART_CTRL_RXIE_Msk			(0x01 << UART_CTRL_RXIE_Pos)
#define UART_CTRL_RXOV_Pos			5		//RX FIFO Overflow��д1����
#define UART_CTRL_RXOV_Msk			(0x01 << UART_CTRL_RXOV_Pos)
#define UART_CTRL_TXDOIE_Pos		6		//TX Done �ж�ʹ�ܣ�ȫ�����ݷ�����ɣ����ڲ�û�д����͵�����
#define UART_CTRL_TXDOIE_Msk		(0x01 << UART_CTRL_TXDOIE_Pos)
#define UART_CTRL_EN_Pos			9
#define UART_CTRL_EN_Msk			(0x01 << UART_CTRL_EN_Pos)
#define UART_CTRL_LOOP_Pos			10
#define UART_CTRL_LOOP_Msk			(0x01 << UART_CTRL_LOOP_Pos)
#define UART_CTRL_BAUDEN_Pos		13		//����д1
#define UART_CTRL_BAUDEN_Msk		(0x01 << UART_CTRL_BAUDEN_Pos)
#define UART_CTRL_TOIE_Pos			14		//TimeOut �ж�ʹ�ܣ����յ��ϸ��ַ��󣬳��� TOTIME/BAUDRAUD ��û�н��յ��µ�����
#define UART_CTRL_TOIE_Msk			(0x01 << UART_CTRL_TOIE_Pos)
#define UART_CTRL_BRKDET_Pos		15		//LIN Break Detect����⵽LIN Break����RX���ϼ�⵽����11λ�͵�ƽ
#define UART_CTRL_BRKDET_Msk		(0x01 << UART_CTRL_BRKDET_Pos)
#define UART_CTRL_BRKIE_Pos			16		//LIN Break Detect �ж�ʹ��
#define UART_CTRL_BRKIE_Msk			(0x01 << UART_CTRL_BRKIE_Pos)
#define UART_CTRL_GENBRK_Pos		17		//Generate LIN Break������LIN Break
#define UART_CTRL_GENBRK_Msk		(0x01 << UART_CTRL_GENBRK_Pos)
#define UART_CTRL_DATA9b_Pos		18		//1 9λ����λ    0 8λ����λ
#define UART_CTRL_DATA9b_Msk		(0x01 << UART_CTRL_DATA9b_Pos)
#define UART_CTRL_PARITY_Pos		19		//000 ��У��    001 ��У��   011 żУ��   101 �̶�Ϊ1    111 �̶�Ϊ0
#define UART_CTRL_PARITY_Msk		(0x07 << UART_CTRL_PARITY_Pos)
#define UART_CTRL_STOP2b_Pos		22		//1 2λֹͣλ    0 1λֹͣλ
#define UART_CTRL_STOP2b_Msk		(0x03 << UART_CTRL_STOP2b_Pos)
#define UART_CTRL_TOTIME_Pos		24		//TimeOut ʱ�� = TOTIME/(BAUDRAUD/10) ��
//#define UART_CTRL_TOTIME_Msk		(0xFF << UART_CTRL_TOTIME_Pos)	���������棺 integer operation result is out of range
#define UART_CTRL_TOTIME_Msk		((uint32_t)0xFF << UART_CTRL_TOTIME_Pos)

#define UART_BAUD_BAUD_Pos			0		//���ڲ����� = SYS_Freq/16/BAUD - 1
#define UART_BAUD_BAUD_Msk			(0x3FFF << UART_BAUD_BAUD_Pos)
#define UART_BAUD_TXD_Pos			14		//ͨ����λ��ֱ�Ӷ�ȡ����TXD�����ϵĵ�ƽ
#define UART_BAUD_TXD_Msk			(0x01 << UART_BAUD_TXD_Pos)
#define UART_BAUD_RXD_Pos			15		//ͨ����λ��ֱ�Ӷ�ȡ����RXD�����ϵĵ�ƽ
#define UART_BAUD_RXD_Msk			(0x01 << UART_BAUD_RXD_Pos)
#define UART_BAUD_RXTOIF_Pos		16		//����&��ʱ���жϱ�־ = RXIF | TOIF
#define UART_BAUD_RXTOIF_Msk		(0x01 << UART_BAUD_RXTOIF_Pos)
#define UART_BAUD_TXIF_Pos			17		//�����жϱ�־ = TXTHRF & TXIE
#define UART_BAUD_TXIF_Msk			(0x01 << UART_BAUD_TXIF_Pos)
#define UART_BAUD_BRKIF_Pos			18		//LIN Break Detect �жϱ�־����⵽LIN Breakʱ��BRKIE=1����λ��Ӳ����λ
#define UART_BAUD_BRKIF_Msk			(0x01 << UART_BAUD_BRKIF_Pos)
#define UART_BAUD_RXTHRF_Pos		19		//RX FIFO Threshold Flag��RX FIFO�����ݴﵽ�趨������RXLVL >= RXTHR��ʱӲ����1
#define UART_BAUD_RXTHRF_Msk		(0x01 << UART_BAUD_RXTHRF_Pos)
#define UART_BAUD_TXTHRF_Pos		20		//TX FIFO Threshold Flag��TX FIFO�����������趨������TXLVL <= TXTHR��ʱӲ����1
#define UART_BAUD_TXTHRF_Msk		(0x01 << UART_BAUD_TXTHRF_Pos)
#define UART_BAUD_TOIF_Pos			21		//TimeOut �жϱ�־������ TOTIME/BAUDRAUD ��û�н��յ��µ�����ʱ��TOIE=1����λ��Ӳ����λ
#define UART_BAUD_TOIF_Msk			(0x01 << UART_BAUD_TOIF_Pos)
#define UART_BAUD_RXIF_Pos			22		//�����жϱ�־ = RXTHRF & RXIE
#define UART_BAUD_RXIF_Msk			(0x01 << UART_BAUD_RXIF_Pos)
#define UART_BAUD_ABREN_Pos			23		//Auto Baudrate Enable��д1�����Զ�������У׼����ɺ��Զ�����
#define UART_BAUD_ABREN_Msk			(0x01 << UART_BAUD_ABREN_Pos)
#define UART_BAUD_ABRBIT_Pos		24		//Auto Baudrate Bit�����ڼ��㲨���ʵļ��λ����0 1λ��ͨ������ʼλ           ������㲨���ʣ�Ҫ���Ͷ˷���0xFF
											//                                             1 2λ��ͨ������ʼλ��1λ����λ������㲨���ʣ�Ҫ���Ͷ˷���0xFE
											//                                             1 4λ��ͨ������ʼλ��3λ����λ������㲨���ʣ�Ҫ���Ͷ˷���0xF8
											//                                             1 8λ��ͨ������ʼλ��7λ����λ������㲨���ʣ�Ҫ���Ͷ˷���0x80
#define UART_BAUD_ABRBIT_Msk		(0x03 << UART_BAUD_ABRBIT_Pos)
#define UART_BAUD_ABRERR_Pos		26		//Auto Baudrate Error��0 �Զ�������У׼�ɹ�     1 �Զ�������У׼ʧ��
#define UART_BAUD_ABRERR_Msk		(0x01 << UART_BAUD_ABRERR_Pos)
#define UART_BAUD_TXDOIF_Pos		27		//TX Done �жϱ�־��ȫ�����ݷ�����ɣ����ڲ�û�д����͵�����
#define UART_BAUD_TXDOIF_Msk		(0x01 << UART_BAUD_TXDOIF_Pos)

#define UART_FIFO_RXLVL_Pos			0		//RX FIFO Level��RX FIFO ���ַ�����
#define UART_FIFO_RXLVL_Msk			(0xFF << UART_FIFO_RXLVL_Pos)
#define UART_FIFO_TXLVL_Pos			8		//TX FIFO Level��TX FIFO ���ַ�����
#define UART_FIFO_TXLVL_Msk			(0xFF << UART_FIFO_TXLVL_Pos)
#define UART_FIFO_RXTHR_Pos			16		//RX FIFO Threshold��RX�жϴ������ޣ��ж�ʹ��ʱ RXLVL >= RXTHR ����RX�ж�
#define UART_FIFO_RXTHR_Msk			(0xFF << UART_FIFO_RXTHR_Pos)
#define UART_FIFO_TXTHR_Pos			24		//TX FIFO Threshold��TX�жϴ������ޣ��ж�ʹ��ʱ TXLVL <= TXTHR ����TX�ж�
//#define UART_FIFO_TXTHR_Msk			(0xFF << UART_FIFO_TXTHR_Pos)	���������棺 integer operation result is out of range
#define UART_FIFO_TXTHR_Msk			((uint32_t)0xFF << UART_FIFO_TXTHR_Pos)

#define UART_LINCR_BRKDETIE_Pos		0		//��⵽LIN Break�ж�ʹ��
#define UART_LINCR_BRKDETIE_Msk		(0x01 << UART_LINCR_BRKDETIE_Pos)
#define UART_LINCR_BRKDETIF_Pos		1		//��⵽LIN Break�ж�״̬
#define UART_LINCR_BRKDETIF_Msk		(0x01 << UART_LINCR_BRKDETIF_Pos)
#define UART_LINCR_GENBRKIE_Pos		2		//����LIN Break����ж�ʹ��
#define UART_LINCR_GENBRKIE_Msk		(0x01 << UART_LINCR_GENBRKIE_Pos)
#define UART_LINCR_GENBRKIF_Pos		3		//����LIN Break����ж�״̬
#define UART_LINCR_GENBRKIF_Msk		(0x01 << UART_LINCR_GENBRKIF_Pos)
#define UART_LINCR_GENBRK_Pos		4		//����LIN Break����������Զ�����
#define UART_LINCR_GENBRK_Msk		(0x01 << UART_LINCR_GENBRK_Pos)

#define UART_CTSCR_EN_Pos			0		//CTS����ʹ��
#define UART_CTSCR_EN_Msk			(0x01 << UART_CTSCR_EN_Pos)
#define UART_CTSCR_POL_Pos			2		//CTS�źż��ԣ�0 ����Ч��CTS����Ϊ�ͱ�ʾ���Է�������
#define UART_CTSCR_POL_Msk			(0x01 << UART_CTSCR_POL_Pos)
#define UART_CTSCR_STAT_Pos			7		//CTS�źŵĵ�ǰ״̬
#define UART_CTSCR_STAT_Msk			(0x01 << UART_CTSCR_STAT_Pos)

#define UART_RTSCR_EN_Pos			1		//RTS����ʹ��
#define UART_RTSCR_EN_Msk			(0x01 << UART_RTSCR_EN_Pos)
#define UART_RTSCR_POL_Pos			3		//RTS�źż���    0 ����Ч��RTS����Ϊ�ͱ�ʾ���Խ�������
#define UART_RTSCR_POL_Msk			(0x01 << UART_RTSCR_POL_Pos)
#define UART_RTSCR_THR_Pos			4		//RTS���صĴ�����ֵ    0 1�ֽ�    1 2�ֽ�    2 4�ֽ�    3 6�ֽ�
#define UART_RTSCR_THR_Msk			(0x07 << UART_RTSCR_THR_Pos)
#define UART_RTSCR_STAT_Pos			8		//RTS�źŵĵ�ǰ״̬
#define UART_RTSCR_STAT_Msk			(0x01 << UART_RTSCR_STAT_Pos)

#define UART_CFG_INV_Pos			0		//���շ��͵�ƽ��ת
#define UART_CFG_INV_Msk			(0x01 << UART_CFG_INV_Pos)
#define UART_CFG_MSBF_Pos			1		//���շ���MSB First
#define UART_CFG_MSBF_Msk			(0x01 << UART_CFG_MSBF_Pos)
#define UART_CFG_BRKTXLEN_Pos		2
#define UART_CFG_BRKTXLEN_Msk		(0x0F << UART_CFG_BRKTXLEN_Pos)
#define UART_CFG_BRKRXLEN_Pos		6
#define UART_CFG_BRKRXLEN_Msk		(0x0F << UART_CFG_BRKRXLEN_Pos)




typedef struct {
	__IO uint32_t CTRL;

	__IO uint32_t DATA;

	__IO uint32_t STAT;

	__IO uint32_t IE;

	__IO uint32_t IF;
} SPI_TypeDef;


#define SPI_CTRL_CLKDIV_Pos			0		//Clock Divider, SPI����ʱ�� = SYS_Freq/pow(2, CLKDIV+2)
#define SPI_CTRL_CLKDIV_Msk			(0x07 << SPI_CTRL_CLKDIV_Pos)
#define SPI_CTRL_EN_Pos				3
#define SPI_CTRL_EN_Msk				(0x01 << SPI_CTRL_EN_Pos)
#define SPI_CTRL_SIZE_Pos			4		//Data Size Select, ȡֵ3--15����ʾ4--16λ
#define SPI_CTRL_SIZE_Msk			(0x0F << SPI_CTRL_SIZE_Pos)
#define SPI_CTRL_CPHA_Pos			8		//0 ��SCLK�ĵ�һ�������ز�������	1 ��SCLK�ĵڶ��������ز�������
#define SPI_CTRL_CPHA_Msk			(0x01 << SPI_CTRL_CPHA_Pos)
#define SPI_CTRL_CPOL_Pos			9		//0 ����״̬��SCLKΪ�͵�ƽ		  1 ����״̬��SCLKΪ�ߵ�ƽ
#define SPI_CTRL_CPOL_Msk			(0x01 << SPI_CTRL_CPOL_Pos)
#define SPI_CTRL_FFS_Pos			10		//Frame Format Select, 0 SPI	1 TI SSI	2 I2S	3 SPI Flash
#define SPI_CTRL_FFS_Msk			(0x03 << SPI_CTRL_FFS_Pos)
#define SPI_CTRL_MSTR_Pos			12		//Master, 1 ��ģʽ	0 ��ģʽ
#define SPI_CTRL_MSTR_Msk			(0x01 << SPI_CTRL_MSTR_Pos)
#define SPI_CTRL_FAST_Pos			13		//1 SPI����ʱ�� = SYS_Freq/2    0 SPI����ʱ����SPI->CTRL.CLKDIV����
#define SPI_CTRL_FAST_Msk			(0x01 << SPI_CTRL_FAST_Pos)
#define SPI_CTRL_DMATXEN_Pos		14		//1 ͨ��DMAдFIFO    0 ͨ��MCUдFIFO
#define SPI_CTRL_DMATXEN_Msk		(0x01 << SPI_CTRL_DMATXEN_Pos)
#define SPI_CTRL_DMARXEN_Pos		15		//1 ͨ��DMA��FIFO    0 ͨ��MCU��FIFO
#define SPI_CTRL_DMARXEN_Msk		(0x01 << SPI_CTRL_DMARXEN_Pos)
#define SPI_CTRL_FILTE_Pos			16		//1 ��SPI�����źŽ���ȥ������    0 ��SPI�����źŲ�����ȥ������
#define SPI_CTRL_FILTE_Msk			(0x01 << SPI_CTRL_FILTE_Pos)
#define SPI_CTRL_SSN_H_Pos			17		//0 ���������SSNʼ��Ϊ0    	 1 ���������ÿ�ַ�֮��ὫSSN���߰��SCLK����
#define SPI_CTRL_SSN_H_Msk			(0x01 << SPI_CTRL_SSN_H_Pos)
#define SPI_CTRL_RFTHR_Pos			18		//RX FIFO Threshold��0 ����FIFO��������1������   ...   7 ����FIFO��������8������
#define SPI_CTRL_RFTHR_Msk			(0x07 << SPI_CTRL_RFTHR_Pos)
#define SPI_CTRL_TFTHR_Pos			21		//TX FIFO Threshold��0 ����FIFO��������0������   ...   7 ����FIFO��������7������
#define SPI_CTRL_TFTHR_Msk			(0x07 << SPI_CTRL_TFTHR_Pos)
#define SPI_CTRL_RFCLR_Pos			24		//RX FIFO Clear
#define SPI_CTRL_RFCLR_Msk			(0x01 << SPI_CTRL_RFCLR_Pos)
#define SPI_CTRL_TFCLR_Pos			25		//TX FIFO Clear
#define SPI_CTRL_TFCLR_Msk			(0x01 << SPI_CTRL_TFCLR_Pos)
#define SPI_CTRL_LSBF_Pos			28		//LSB Fisrt
#define SPI_CTRL_LSBF_Msk			(0x01 << SPI_CTRL_LSBF_Pos)

#define SPI_STAT_WTC_Pos			0		//Word Transmit Complete��ÿ�������һ����������Ӳ����1�����д1����
#define SPI_STAT_WTC_Msk			(0x01 << SPI_STAT_WTC_Pos)
#define SPI_STAT_TFE_Pos			1		//����FIFO Empty
#define SPI_STAT_TFE_Msk			(0x01 << SPI_STAT_TFE_Pos)
#define SPI_STAT_TFNF_Pos			2		//����FIFO Not Full
#define SPI_STAT_TFNF_Msk			(0x01 << SPI_STAT_TFNF_Pos)
#define SPI_STAT_RFNE_Pos			3		//����FIFO Not Empty
#define SPI_STAT_RFNE_Msk			(0x01 << SPI_STAT_RFNE_Pos)
#define SPI_STAT_RFF_Pos			4		//����FIFO Full
#define SPI_STAT_RFF_Msk			(0x01 << SPI_STAT_RFF_Pos)
#define SPI_STAT_RFOV_Pos			5		//����FIFO Overflow
#define SPI_STAT_RFOV_Msk			(0x01 << SPI_STAT_RFOV_Pos)
#define SPI_STAT_TFLVL_Pos			6		//����FIFO�����ݸ����� 0 TFNF=0ʱ��ʾFIFO����8�����ݣ�TFNF=1ʱ��ʾFIFO����0������	1--7 FIFO����1--7������
#define SPI_STAT_TFLVL_Msk			(0x07 << SPI_STAT_TFLVL_Pos)
#define SPI_STAT_RFLVL_Pos			9		//����FIFO�����ݸ����� 0 RFF =1ʱ��ʾFIFO����8�����ݣ�RFF =0ʱ��ʾFIFO����0������	1--7 FIFO����1--7������
#define SPI_STAT_RFLVL_Msk			(0x07 << SPI_STAT_RFLVL_Pos)
#define SPI_STAT_BUSY_Pos			15
#define SPI_STAT_BUSY_Msk			(0x01 << SPI_STAT_BUSY_Pos)

#define SPI_IE_RFOV_Pos				0
#define SPI_IE_RFOV_Msk				(0x01 << SPI_IE_RFOV_Pos)
#define SPI_IE_RFF_Pos				1
#define SPI_IE_RFF_Msk				(0x01 << SPI_IE_RFF_Pos)
#define SPI_IE_RFHF_Pos				2
#define SPI_IE_RFHF_Msk				(0x01 << SPI_IE_RFHF_Pos)
#define SPI_IE_TFE_Pos				3
#define SPI_IE_TFE_Msk				(0x01 << SPI_IE_TFE_Pos)
#define SPI_IE_TFHF_Pos				4		//����FIFO�����ݸ�������4
#define SPI_IE_TFHF_Msk				(0x01 << SPI_IE_TFHF_Pos)
#define SPI_IE_RFTHR_Pos			5		//����FIFO�����ݸ�������CTRL.RFTHR�趨ֵ�ж�ʹ��
#define SPI_IE_RFTHR_Msk			(0x01 << SPI_IE_RFTHR_Pos)
#define SPI_IE_TFTHR_Pos			6		//����FIFO�����ݸ���С��CTRL.TFTHR�趨ֵ�ж�ʹ��
#define SPI_IE_TFTHR_Msk			(0x01 << SPI_IE_TFTHR_Pos)
#define SPI_IE_WTC_Pos				8		//Word Transmit Complete
#define SPI_IE_WTC_Msk				(0x01 << SPI_IE_WTC_Pos)
#define SPI_IE_FTC_Pos				9		//Frame Transmit Complete
#define SPI_IE_FTC_Msk				(0x01 << SPI_IE_FTC_Pos)

#define SPI_IF_RFOV_Pos				0		//д1����
#define SPI_IF_RFOV_Msk				(0x01 << SPI_IF_RFOV_Pos)
#define SPI_IF_RFF_Pos				1		//д1����
#define SPI_IF_RFF_Msk				(0x01 << SPI_IF_RFF_Pos)
#define SPI_IF_RFHF_Pos				2		//д1����
#define SPI_IF_RFHF_Msk				(0x01 << SPI_IF_RFHF_Pos)
#define SPI_IF_TFE_Pos				3		//д1����
#define SPI_IF_TFE_Msk				(0x01 << SPI_IF_TFE_Pos)
#define SPI_IF_TFHF_Pos				4		//д1����
#define SPI_IF_TFHF_Msk				(0x01 << SPI_IF_TFHF_Pos)
#define SPI_IF_RFTHR_Pos			5		//д1����
#define SPI_IF_RFTHR_Msk			(0x01 << SPI_IF_RFTHR_Pos)
#define SPI_IF_TFTHR_Pos			6		//д1����
#define SPI_IF_TFTHR_Msk			(0x01 << SPI_IF_TFTHR_Pos)
#define SPI_IF_WTC_Pos				8		//Word Transmit Complete��ÿ�������һ����������Ӳ����1
#define SPI_IF_WTC_Msk				(0x01 << SPI_IF_WTC_Pos)
#define SPI_IF_FTC_Pos				9		//Frame Transmit Complete��WTC��λʱ��TX FIFO�ǿյģ���FTC��λ
#define SPI_IF_FTC_Msk				(0x01 << SPI_IF_FTC_Pos)




typedef struct {
	__IO uint32_t CLKDIV;				   	//[15:0] �뽫�ڲ�����Ƶ�ʷֵ�SCLƵ�ʵ�5������CLKDIV = SYS_Freq/5/SCL_Freq - 1

	__IO uint32_t MSTCR;

	__IO uint32_t MSTDAT;

	__IO uint32_t MSTCMD;
	
	     uint32_t RESERVED[4];
	
	__IO uint32_t SLVCR;
	
	__IO uint32_t SLVIF;
	
	__IO uint32_t SLVTX;
	
	__IO uint32_t SLVRX;
	
	__IO uint32_t SLVAM;					//Slave Address Mask
} I2C_TypeDef;


#define I2C_MSTCR_IE_Pos			6
#define I2C_MSTCR_IE_Msk			(0x01 << I2C_MSTCR_IE_Pos)
#define I2C_MSTCR_EN_Pos			7
#define I2C_MSTCR_EN_Msk			(0x01 << I2C_MSTCR_EN_Pos)

#define I2C_MSTCMD_IF_Pos			0		//1 �еȴ�������жϣ�д1����	����������´�λӲ����λ��1��һ���ֽڴ������  2�����߷���Ȩ��ʧ
#define I2C_MSTCMD_IF_Msk			(0x01 << I2C_MSTCMD_IF_Pos)
#define I2C_MSTCMD_TIP_Pos			1		//Transmission In Process
#define I2C_MSTCMD_TIP_Msk			(0x01 << I2C_MSTCMD_TIP_Pos)
#define I2C_MSTCMD_ACK_Pos			3		//����ģʽ�£�0 ���Ͷ˷���ACK	1 ���Ͷ˷���NACK
#define I2C_MSTCMD_ACK_Msk			(0x01 << I2C_MSTCMD_ACK_Pos)
#define I2C_MSTCMD_WR_Pos			4		//	  ��Slaveд����ʱ������һλд1���Զ�����
#define I2C_MSTCMD_WR_Msk			(0x01 << I2C_MSTCMD_WR_Pos)
#define I2C_MSTCMD_RD_Pos			5		//д����Slave������ʱ������һλд1���Զ�����	������I2Cģ��ʧȥ���ߵķ���ȨʱӲ����1
#define I2C_MSTCMD_RD_Msk			(0x01 << I2C_MSTCMD_RD_Pos)
#define I2C_MSTCMD_BUSY_Pos			6		//��������⵽START֮����һλ��1������⵽STOP֮����һλ��0
#define I2C_MSTCMD_BUSY_Msk			(0x01 << I2C_MSTCMD_BUSY_Pos)
#define I2C_MSTCMD_STO_Pos			6		//д������STOP���Զ�����
#define I2C_MSTCMD_STO_Msk			(0x01 << I2C_MSTCMD_STO_Pos)
#define I2C_MSTCMD_RXACK_Pos		7		//�������յ���Slave��ACKλ��0 �յ�ACK	1 �յ�NACK
#define I2C_MSTCMD_RXACK_Msk		(0x01 << I2C_MSTCMD_RXACK_Pos)
#define I2C_MSTCMD_STA_Pos			7		//д������START���Զ�����
#define I2C_MSTCMD_STA_Msk			(0x01 << I2C_MSTCMD_STA_Pos)

#define I2C_SLVCR_IM_RXEND_Pos		0		//��������жϽ�ֹ
#define I2C_SLVCR_IM_RXEND_Msk		(0x01 << I2C_SLVCR_IM_RXEND_Pos)
#define I2C_SLVCR_IM_TXEND_Pos		1		//��������жϽ�ֹ
#define I2C_SLVCR_IM_TXEND_Msk		(0x01 << I2C_SLVCR_IM_TXEND_Pos)
#define I2C_SLVCR_IM_STADET_Pos		2		//��⵽��ʼ�жϽ�ֹ
#define I2C_SLVCR_IM_STADET_Msk		(0x01 << I2C_SLVCR_IM_STADET_Pos)
#define I2C_SLVCR_IM_STODET_Pos		3		//��⵽ֹͣ�жϽ�ֹ
#define I2C_SLVCR_IM_STODET_Msk		(0x01 << I2C_SLVCR_IM_STODET_Pos)
#define I2C_SLVCR_IM_RDREQ_Pos		4		//���յ��������жϽ�ֹ
#define I2C_SLVCR_IM_RDREQ_Msk		(0x01 << I2C_SLVCR_IM_RDREQ_Pos)
#define I2C_SLVCR_IM_WRREQ_Pos		5		//���յ�д�����жϽ�ֹ
#define I2C_SLVCR_IM_WRREQ_Msk		(0x01 << I2C_SLVCR_IM_WRREQ_Pos)
#define I2C_SLVCR_ADDR7b_Pos		16		//1 7λ��ַģʽ    0 10λ��ַģʽ
#define I2C_SLVCR_ADDR7b_Msk		(0x01 << I2C_SLVCR_ADDR7b_Pos)
#define I2C_SLVCR_ACK_Pos			17		//1 Ӧ��ACK    0 Ӧ��NACK
#define I2C_SLVCR_ACK_Msk			(0x01 << I2C_SLVCR_ACK_Pos)
#define I2C_SLVCR_SLAVE_Pos			18		//1 �ӻ�ģʽ   0 ����ģʽ
#define I2C_SLVCR_SLAVE_Msk			(0x01 << I2C_SLVCR_SLAVE_Pos)
#define I2C_SLVCR_DEBOUNCE_Pos		19		//ȥ����ʹ��
#define I2C_SLVCR_DEBOUNCE_Msk		(0x01 << I2C_SLVCR_DEBOUNCE_Pos)
#define I2C_SLVCR_ADDR_Pos			20		//�ӻ���ַ
#define I2C_SLVCR_ADDR_Msk			(0x3FF << I2C_SLVCR_ADDR_Pos)

#define I2C_SLVIF_RXEND_Pos			0		//��������жϱ�־��д1����
#define I2C_SLVIF_RXEND_Msk			(0x01 << I2C_SLVIF_RXEND_Pos)
#define I2C_SLVIF_TXEND_Pos			1		//��������жϱ�־��д1����
#define I2C_SLVIF_TXEND_Msk			(0x01 << I2C_SLVIF_TXEND_Pos)
#define I2C_SLVIF_STADET_Pos		2		//��⵽��ʼ�жϱ�־��д1����
#define I2C_SLVIF_STADET_Msk		(0x01 << I2C_SLVIF_STADET_Pos)
#define I2C_SLVIF_STODET_Pos		3		//��⵽ֹͣ�жϱ�־��д1����
#define I2C_SLVIF_STODET_Msk		(0x01 << I2C_SLVIF_STODET_Pos)
#define I2C_SLVIF_RDREQ_Pos			4		//���յ��������жϱ�־
#define I2C_SLVIF_RDREQ_Msk			(0x01 << I2C_SLVIF_RDREQ_Pos)
#define I2C_SLVIF_WRREQ_Pos			5		//���յ�д�����жϱ�־
#define I2C_SLVIF_WRREQ_Msk			(0x01 << I2C_SLVIF_WRREQ_Pos)
#define I2C_SLVIF_ACTIVE_Pos		6		//slave ��Ч
#define I2C_SLVIF_ACTIVE_Msk		(0x01 << I2C_SLVIF_ACTIVE_Pos)




typedef struct {
	__IO uint32_t CTRL;
	
	__IO uint32_t START;
	
	__IO uint32_t IE;
	
	__IO uint32_t IF;
	
	struct {
		__IO uint32_t STAT;
		
		__IO uint32_t DATA;
		
			 uint32_t RESERVED[2];
	} CH[8];
	
	__IO uint32_t FIFOSR;
	
	__IO uint32_t FIFODR;
	
		 uint32_t RESERVED[2];
	
	__IO uint32_t CTRL2;
	
	__IO uint32_t CTRL3;
	
		 uint32_t RESERVED2[2];
    
	__IO uint32_t TRIG;						//��Ӧλ��1������Ӧͨ������ADC���ܱ�����
	
		 uint32_t RESERVED3[16];
	
	__IO uint32_t CALIBSET;
	
	__IO uint32_t CALIBEN;
} ADC_TypeDef;


#define ADC_CTRL_CH0_Pos			0		//ͨ��ѡ��
#define ADC_CTRL_CH0_Msk			(0x01 << ADC_CTRL_CH0_Pos)
#define ADC_CTRL_CH1_Pos			1
#define ADC_CTRL_CH1_Msk			(0x01 << ADC_CTRL_CH1_Pos)
#define ADC_CTRL_CH2_Pos			2
#define ADC_CTRL_CH2_Msk			(0x01 << ADC_CTRL_CH2_Pos)
#define ADC_CTRL_CH3_Pos			3
#define ADC_CTRL_CH3_Msk			(0x01 << ADC_CTRL_CH3_Pos)
#define ADC_CTRL_CH4_Pos			4
#define ADC_CTRL_CH4_Msk			(0x01 << ADC_CTRL_CH4_Pos)
#define ADC_CTRL_CH5_Pos			5
#define ADC_CTRL_CH5_Msk			(0x01 << ADC_CTRL_CH5_Pos)
#define ADC_CTRL_CH6_Pos			6
#define ADC_CTRL_CH6_Msk			(0x01 << ADC_CTRL_CH6_Pos)
#define ADC_CTRL_CH7_Pos			7
#define ADC_CTRL_CH7_Msk			(0x01 << ADC_CTRL_CH7_Pos)
#define ADC_CTRL_AVG_Pos			8		//0 1�β���	  1 2�β���ȡƽ��ֵ	  3 4�β���ȡƽ��ֵ	  7 8�β���ȡƽ��ֵ	  15 16�β���ȡƽ��ֵ
#define ADC_CTRL_AVG_Msk			(0x0F << ADC_CTRL_AVG_Pos)
#define ADC_CTRL_EN_Pos				12
#define ADC_CTRL_EN_Msk				(0x01 << ADC_CTRL_EN_Pos)
#define ADC_CTRL_CONT_Pos			13		//Continuous conversion��ֻ���������ģʽ����Ч��0 ����ת����ת����ɺ�STARTλ�Զ����ֹͣת��
#define ADC_CTRL_CONT_Msk			(0x01 << ADC_CTRL_CONT_Pos)							//   1 ����ת����������һֱ������ת����ֱ��������STARTλ
#define ADC_CTRL_TRIG_Pos			14		//ת��������ʽ��0 �������ת��	  1 PWM����   2 TIMR2   3 TIMR3    4 PIN
#define ADC_CTRL_TRIG_Msk			(0x07 << ADC_CTRL_TRIG_Pos)
#define ADC_CTRL_DMAEN_Pos			17
#define ADC_CTRL_DMAEN_Msk			(0x01 << ADC_CTRL_DMAEN_Pos)
#define ADC_CTRL_RES2FIFO_Pos		18		//0 ת������洢ͨ�����ݼĴ���   1 ת���������FIFO��DMAʱ����ѡ��ģʽ
#define ADC_CTRL_RES2FIFO_Msk		(0x01 << ADC_CTRL_RES2FIFO_Pos)
#define ADC_CTRL_FIFOCLR_Pos		19
#define ADC_CTRL_FIFOCLR_Msk		(0x01 << ADC_CTRL_FIFOCLR_Pos)
#define ADC_CTRL_RESET_Pos			20
#define ADC_CTRL_RESET_Msk			(0x01 << ADC_CTRL_RESET_Pos)


#define ADC_START_GO_Pos			0		//�������ģʽ�£�д1����ADC������ת�����ڵ���ģʽ��ת����ɺ�Ӳ���Զ����㣬��ɨ��ģʽ�±������д0ֹͣADCת��
#define ADC_START_GO_Msk			(0x01 << ADC_START_GO_Pos)
#define ADC_START_BUSY_Pos			4
#define ADC_START_BUSY_Msk			(0x01 << ADC_START_BUSY_Pos)

#define ADC_IE_CH0EOC_Pos			0		//End Of Convertion
#define ADC_IE_CH0EOC_Msk			(0x01 << ADC_IE_CH0EOC_Pos)
#define ADC_IE_CH0OVF_Pos			1		//Overflow
#define ADC_IE_CH0OVF_Msk			(0x01 << ADC_IE_CH0OVF_Pos)
#define ADC_IE_CH1EOC_Pos			2
#define ADC_IE_CH1EOC_Msk			(0x01 << ADC_IE_CH1EOC_Pos)
#define ADC_IE_CH1OVF_Pos			3
#define ADC_IE_CH1OVF_Msk			(0x01 << ADC_IE_CH1OVF_Pos)
#define ADC_IE_CH2EOC_Pos			4
#define ADC_IE_CH2EOC_Msk			(0x01 << ADC_IE_CH2EOC_Pos)
#define ADC_IE_CH2OVF_Pos			5
#define ADC_IE_CH2OVF_Msk			(0x01 << ADC_IE_CH2OVF_Pos)
#define ADC_IE_CH3EOC_Pos			6
#define ADC_IE_CH3EOC_Msk			(0x01 << ADC_IE_CH3EOC_Pos)
#define ADC_IE_CH3OVF_Pos			7
#define ADC_IE_CH3OVF_Msk			(0x01 << ADC_IE_CH3OVF_Pos)
#define ADC_IE_CH4EOC_Pos			8
#define ADC_IE_CH4EOC_Msk			(0x01 << ADC_IE_CH4EOC_Pos)
#define ADC_IE_CH4OVF_Pos			9
#define ADC_IE_CH4OVF_Msk			(0x01 << ADC_IE_CH4OVF_Pos)
#define ADC_IE_CH5EOC_Pos			10
#define ADC_IE_CH5EOC_Msk			(0x01 << ADC_IE_CH5EOC_Pos)
#define ADC_IE_CH5OVF_Pos			11
#define ADC_IE_CH5OVF_Msk			(0x01 << ADC_IE_CH5OVF_Pos)
#define ADC_IE_CH6EOC_Pos			12
#define ADC_IE_CH6EOC_Msk			(0x01 << ADC_IE_CH6EOC_Pos)
#define ADC_IE_CH6OVF_Pos			13
#define ADC_IE_CH6OVF_Msk			(0x01 << ADC_IE_CH6OVF_Pos)
#define ADC_IE_CH7EOC_Pos			14
#define ADC_IE_CH7EOC_Msk			(0x01 << ADC_IE_CH7EOC_Pos)
#define ADC_IE_CH7OVF_Pos			15
#define ADC_IE_CH7OVF_Msk			(0x01 << ADC_IE_CH7OVF_Pos)
#define ADC_IE_FIFOOV_Pos			16		//FIFO Overflow
#define ADC_IE_FIFOOV_Msk			(0x01 << ADC_IE_FIFOOV_Pos)
#define ADC_IE_FIFOHF_Pos			17		//FIFO Half Full
#define ADC_IE_FIFOHF_Msk			(0x01 << ADC_IE_FIFOHF_Pos)
#define ADC_IE_FIFOFULL_Pos			18		//FIFO Full
#define ADC_IE_FIFOFULL_Msk			(0x01 << ADC_IE_FIFOFULL_Pos)

#define ADC_IF_CH0EOC_Pos			0		//д1����
#define ADC_IF_CH0EOC_Msk			(0x01 << ADC_IF_CH0EOC_Pos)
#define ADC_IF_CH0OVF_Pos			1		//д1����
#define ADC_IF_CH0OVF_Msk			(0x01 << ADC_IF_CH0OVF_Pos)
#define ADC_IF_CH1EOC_Pos			2
#define ADC_IF_CH1EOC_Msk			(0x01 << ADC_IF_CH1EOC_Pos)
#define ADC_IF_CH1OVF_Pos			3
#define ADC_IF_CH1OVF_Msk			(0x01 << ADC_IF_CH1OVF_Pos)
#define ADC_IF_CH2EOC_Pos			4
#define ADC_IF_CH2EOC_Msk			(0x01 << ADC_IF_CH2EOC_Pos)
#define ADC_IF_CH2OVF_Pos			5
#define ADC_IF_CH2OVF_Msk			(0x01 << ADC_IF_CH2OVF_Pos)
#define ADC_IF_CH3EOC_Pos			6
#define ADC_IF_CH3EOC_Msk			(0x01 << ADC_IF_CH3EOC_Pos)
#define ADC_IF_CH3OVF_Pos			7
#define ADC_IF_CH3OVF_Msk			(0x01 << ADC_IF_CH3OVF_Pos)
#define ADC_IF_CH4EOC_Pos			8
#define ADC_IF_CH4EOC_Msk			(0x01 << ADC_IF_CH4EOC_Pos)
#define ADC_IF_CH4OVF_Pos			9
#define ADC_IF_CH4OVF_Msk			(0x01 << ADC_IF_CH4OVF_Pos)
#define ADC_IF_CH5EOC_Pos			10
#define ADC_IF_CH5EOC_Msk			(0x01 << ADC_IF_CH5EOC_Pos)
#define ADC_IF_CH5OVF_Pos			11
#define ADC_IF_CH5OVF_Msk			(0x01 << ADC_IF_CH5OVF_Pos)
#define ADC_IF_CH6EOC_Pos			12
#define ADC_IF_CH6EOC_Msk			(0x01 << ADC_IF_CH6EOC_Pos)
#define ADC_IF_CH6OVF_Pos			13
#define ADC_IF_CH6OVF_Msk			(0x01 << ADC_IF_CH6OVF_Pos)
#define ADC_IF_CH7EOC_Pos			14
#define ADC_IF_CH7EOC_Msk			(0x01 << ADC_IF_CH7EOC_Pos)
#define ADC_IF_CH7OVF_Pos			15
#define ADC_IF_CH7OVF_Msk			(0x01 << ADC_IF_CH7OVF_Pos)
#define ADC_IF_FIFOOV_Pos			16		//FIFO Overflow
#define ADC_IF_FIFOOV_Msk			(0x01 << ADC_IF_FIFOOV_Pos)
#define ADC_IF_FIFOHF_Pos			17		//FIFO Half Full
#define ADC_IF_FIFOHF_Msk			(0x01 << ADC_IF_FIFOHF_Pos)
#define ADC_IF_FIFOFULL_Pos			18		//FIFO Full
#define ADC_IF_FIFOFULL_Msk			(0x01 << ADC_IF_FIFOFULL_Pos)

#define ADC_STAT_EOC_Pos			0		//д1����
#define ADC_STAT_EOC_Msk			(0x01 << ADC_STAT_EOC_Pos)
#define ADC_STAT_OVF_Pos			1		//�����ݼĴ������
#define ADC_STAT_OVF_Msk			(0x01 << ADC_STAT_OVF_Pos)

#define ADC_DATA_VAL_Pos			0
#define ADC_DATA_VAL_Msk			(0xFFF<< ADC_DATA_VAL_Pos)
#define ADC_DATA_NUM_Pos			12
#define ADC_DATA_NUM_Msk			(0x07 << ADC_DATA_NUM_Pos)

#define ADC_FIFOSR_OV_Pos			0
#define ADC_FIFOSR_OV_Msk			(0x01 << ADC_FIFOSR_OV_Pos)
#define ADC_FIFOSR_HF_Pos			1
#define ADC_FIFOSR_HF_Msk			(0x01 << ADC_FIFOSR_HF_Pos)
#define ADC_FIFOSR_FULL_Pos			2		//FIFO Full
#define ADC_FIFOSR_FULL_Msk			(0x01 << ADC_FIFOSR_FULL_Pos)
#define ADC_FIFOSR_EMPTY_Pos		3		//FIFO Empty
#define ADC_FIFOSR_EMPTY_Msk		(0x01 << ADC_FIFOSR_EMPTY_Pos)

#define ADC_FIFDR_VAL_Pos			0
#define ADC_FIFDR_VAL_Msk			(0xFFF<< ADC_FIFDR_VAL_Pos)
#define ADC_FIFDR_NUM_Pos			12
#define ADC_FIFDR_NUM_Msk			(0x07 << ADC_FIFDR_NUM_Pos)

#define ADC_CTRL2_ADJH_Pos			8
#define ADC_CTRL2_ADJH_Msk			(0xFF << ADC_CTRL2_ADJH_Pos)
#define ADC_CTRL2_ADJL_Pos			16
#define ADC_CTRL2_ADJL_Msk			(0x0F << ADC_CTRL2_ADJL_Pos)

#define ADC_CTRL3_EXTREF_Pos		1		//0 �ڲ�REFP   3 �ⲿREFP
#define ADC_CTRL3_EXTREF_Msk		(0x03 << ADC_CTRL3_EXTREF_Pos)
#define ADC_CTRL3_CLKDIV_Pos		24		//1 1��Ƶ   2 2��Ƶ ...
#define ADC_CTRL3_CLKDIV_Msk		(0x1F << ADC_CTRL3_CLKDIV_Pos)

#define ADC_CALIBSET_OFFSET_Pos		0
#define ADC_CALIBSET_OFFSET_Msk		(0x1FF<< ADC_CALIBSET_OFFSET_Pos)
#define ADC_CALIBSET_K_Pos			16
#define ADC_CALIBSET_K_Msk			(0x1FF<< ADC_CALIBSET_K_Pos)

#define ADC_CALIBEN_OFFSET_Pos		0
#define ADC_CALIBEN_OFFSET_Msk		(0x01 << ADC_CALIBEN_OFFSET_Pos)
#define ADC_CALIBEN_K_Pos			1
#define ADC_CALIBEN_K_Msk			(0x01 << ADC_CALIBEN_K_Pos)




typedef struct {
	__IO uint32_t MODE;                     //0 ��ͨģʽ��A��B��·����������
											//5 ���׶Գƻ���ģʽ��A��B��·������������A��B������ӷ����������
	
	__IO uint32_t PERA;                     //[15:0] ����
	
	__IO uint32_t HIGHA;                    //[16:1] �ߵ�ƽ����ʱ��    [0] �Ƿ񽫸ߵ�ƽ���½����Ƴٰ��ʱ������
	
	__IO uint32_t DZA;                      //[9:0] ���������������Ƴ�ʱ��������С��HIGHA
	
	__IO uint32_t PERB;
	
	__IO uint32_t HIGHB;
	
	__IO uint32_t DZB;
	
	__IO uint32_t OUTCR;
	
	__IO uint32_t ADTRGA0;					//A· ADC Trigger Enable
    __IO uint32_t ADTRGA1;
	
	__IO uint32_t BRKEN;					//Brake Enable
	
	__IO uint32_t VALUEA;					//��ǰ����ֵ
	__IO uint32_t VALUEB;
	
	__IO uint32_t ADTRGB0;
    __IO uint32_t ADTRGB1;
} PWM_TypeDef;


#define PWM_OUTCR_INIA_Pos			0		//1 ����Ӹߵ�ƽ��ʼ
#define PWM_OUTCR_INIA_Msk			(0x01 << PWM_OUTCR_INIA_Pos)
#define PWM_OUTCR_INIB_Pos			1		
#define PWM_OUTCR_INIB_Msk			(0x01 << PWM_OUTCR_INIB_Pos)
#define PWM_OUTCR_INVB_Pos			2		//1 B·�����������
#define PWM_OUTCR_INVB_Msk			(0x01 << PWM_OUTCR_INVB_Pos)
#define PWM_OUTCR_INVA_Pos			3
#define PWM_OUTCR_INVA_Msk			(0x01 << PWM_OUTCR_INVA_Pos)
#define PWM_OUTCR_IDLEA_Pos			4		//1 ����ʱ����ߵ�ƽ
#define PWM_OUTCR_IDLEA_Msk			(0x01 << PWM_OUTCR_IDLEA_Pos)
#define PWM_OUTCR_IDLEB_Pos			5
#define PWM_OUTCR_IDLEB_Msk			(0x01 << PWM_OUTCR_IDLEB_Pos)

#define PWM_ADTRG_MATCH_Pos			0		
#define PWM_ADTRG_MATCH_Msk			(0xFFFF << PWM_ADTRG_MATCH_Pos)
#define PWM_ADTRG_EN_Pos		    28		
#define PWM_ADTRG_EN_Msk		    (0x01 << PWM_ADTRG_EN_Pos)

#define PWM_BRKEN_EN_Pos			0
#define PWM_BRKEN_EN_Msk			(0x01 << PWM_BRKEN_EN_Pos)
#define PWM_BRKEN_S0_Pos			1		//ɲ���ź�0ʹ��
#define PWM_BRKEN_S0_Msk			(0x01 << PWM_BRKEN_S0_Pos)
#define PWM_BRKEN_S1_Pos			2		//ɲ���ź�1ʹ��
#define PWM_BRKEN_S1_Msk			(0x01 << PWM_BRKEN_S1_Pos)
#define PWM_BRKEN_S2_Pos			3		//ɲ���ź�2ʹ��
#define PWM_BRKEN_S2_Msk			(0x01 << PWM_BRKEN_S2_Pos)
#define PWM_BRKEN_OUT_Pos			4		//ɲ��ʱPWM�����ƽ
#define PWM_BRKEN_OUT_Msk			(0x01 << PWM_BRKEN_OUT_Pos)


typedef struct {
	__IO uint32_t CLKDIV;					//[2:0] 0--7 ʱ�ӷ�Ƶ2��CLKDIV�η�
	
	__IO uint32_t FORCEO;					//Force Output
    
    __IO uint32_t BRKCR;					//Brake Control
    __IO uint32_t BRKIE;
    __I  uint32_t BRKIF;
    __IO uint32_t BRKIM;
    __IO uint32_t BRKIRS;
	
    __IO uint32_t IE;
    
	__IO uint32_t CHEN;
	
	__IO uint32_t IM;
    
	__IO uint32_t NCIRS;
    
	__IO uint32_t HEIRS;
    
	__I  uint32_t NCIF;
    
	__I  uint32_t HEIF;
	
	__IO uint32_t HCIE;						//�������ж�ʹ��
	
	__IO uint32_t HCIM;
	
	__IO uint32_t HCIRS;					//�ж�ԭʼ״̬��д1����
	
	__I  uint32_t HCIF;
} PWMG_TypeDef;


#define PWMG_FORCEO_PWM0_Pos		0		//0 PWM0�������   1 PWM0ǿ�����Ϊ�̶���ƽ�������ƽֵ��FORCEO.LVL0����
#define PWMG_FORCEO_PWM0_Msk		(0x01 << PWMG_FORCEO_PWM0_Pos)
#define PWMG_FORCEO_PWM1_Pos		1		
#define PWMG_FORCEO_PWM1_Msk		(0x01 << PWMG_FORCEO_PWM1_Pos)
#define PWMG_FORCEO_PWM2_Pos		2		
#define PWMG_FORCEO_PWM2_Msk		(0x01 << PWMG_FORCEO_PWM2_Pos)
#define PWMG_FORCEO_PWM3_Pos		3		
#define PWMG_FORCEO_PWM3_Msk		(0x01 << PWMG_FORCEO_PWM3_Pos)
#define PWMG_FORCEO_LVL0_Pos		16		//0 ǿ�����Ϊ�͵�ƽ��INVΪ0ʱ��   1 ǿ�����Ϊ�ߵ�ƽ��INVΪ0ʱ��
#define PWMG_FORCEO_LVL0_Msk		(0x01 << PWMG_FORCEO_LVL0_Pos)
#define PWMG_FORCEO_LVL1_Pos		17		
#define PWMG_FORCEO_LVL1_Msk		(0x01 << PWMG_FORCEO_LVL1_Pos)
#define PWMG_FORCEO_LVL2_Pos		18		
#define PWMG_FORCEO_LVL2_Msk		(0x01 << PWMG_FORCEO_LVL2_Pos)
#define PWMG_FORCEO_LVL3_Pos		19		
#define PWMG_FORCEO_LVL3_Msk		(0x01 << PWMG_FORCEO_LVL3_Pos)

#define PWMG_BRKCR_STOPCNT_Pos		0       //1 ɲ��ʱ��PWM���������㣬ֹͣ����    0 ɲ��ʱ��PWM�������������� 
#define PWMG_BRKCR_STOPCNT_Msk		(0x01 << PWMG_BRKCR_STOPCNT_Pos)
#define PWMG_BRKCR_S0STATE_Pos		3		//ɲ���ź�0��ǰ״̬
#define PWMG_BRKCR_S0STATE_Msk		(0x01 << PWMG_BRKCR_S0STATE_Pos)
#define PWMG_BRKCR_S1STATE_Pos		4
#define PWMG_BRKCR_S1STATE_Msk		(0x01 << PWMG_BRKCR_S1STATE_Pos)
#define PWMG_BRKCR_S2STATE_Pos		5
#define PWMG_BRKCR_S2STATE_Msk		(0x01 << PWMG_BRKCR_S2STATE_Pos)
#define PWMG_BRKCR_S0STCLR_Pos		6		//ɲ���ź�0״̬���
#define PWMG_BRKCR_S0STCLR_Msk		(0x01 << PWMG_BRKCR_S0STCLR_Pos)
#define PWMG_BRKCR_S1STCLR_Pos		7
#define PWMG_BRKCR_S1STCLR_Msk		(0x01 << PWMG_BRKCR_S1STCLR_Pos)
#define PWMG_BRKCR_S2STCLR_Pos		8
#define PWMG_BRKCR_S2STCLR_Msk		(0x01 << PWMG_BRKCR_S2STCLR_Pos)
#define PWMG_BRKCR_S0INPOL_Pos		9		//ɲ���ź�0������Ч���ԣ�0 �͵�ƽ��Ч   1 �ߵ�ƽ��Ч
#define PWMG_BRKCR_S0INPOL_Msk		(0x01 << PWMG_BRKCR_S0INPOL_Pos)
#define PWMG_BRKCR_S1INPOL_Pos		10		
#define PWMG_BRKCR_S1INPOL_Msk		(0x01 << PWMG_BRKCR_S1INPOL_Pos)
#define PWMG_BRKCR_S2INPOL_Pos		11		
#define PWMG_BRKCR_S2INPOL_Msk		(0x01 << PWMG_BRKCR_S2INPOL_Pos)

#define PWMG_BRKIE_S0_Pos			0		//ɲ���ź�0�ж�ʹ��
#define PWMG_BRKIE_S0_Msk			(0x01 << PWMG_BRKIE_S0_Pos)
#define PWMG_BRKIE_S1_Pos			1
#define PWMG_BRKIE_S1_Msk			(0x01 << PWMG_BRKIE_S1_Pos)
#define PWMG_BRKIE_S2_Pos			2
#define PWMG_BRKIE_S2_Msk			(0x01 << PWMG_BRKIE_S2_Pos)

#define PWMG_BRKIF_S0_Pos			0
#define PWMG_BRKIF_S0_Msk			(0x01 << PWMG_BRKIF_S0_Pos)
#define PWMG_BRKIF_S1_Pos			1
#define PWMG_BRKIF_S1_Msk			(0x01 << PWMG_BRKIF_S1_Pos)
#define PWMG_BRKIF_S2_Pos			2
#define PWMG_BRKIF_S2_Msk			(0x01 << PWMG_BRKIF_S2_Pos)

#define PWMG_BRKIM_S0_Pos			0
#define PWMG_BRKIM_S0_Msk			(0x01 << PWMG_BRKIM_S0_Pos)
#define PWMG_BRKIM_S1_Pos			1
#define PWMG_BRKIM_S1_Msk			(0x01 << PWMG_BRKIM_S1_Pos)
#define PWMG_BRKIM_S2_Pos			2
#define PWMG_BRKIM_S2_Msk			(0x01 << PWMG_BRKIM_S2_Pos)

#define PWMG_BRKIRS_S0_Pos			0		//Raw State, д1����
#define PWMG_BRKIRS_S0_Msk			(0x01 << PWMG_BRKIRS_S0_Pos)
#define PWMG_BRKIRS_S1_Pos			1
#define PWMG_BRKIRS_S1_Msk			(0x01 << PWMG_BRKIRS_S1_Pos)
#define PWMG_BRKIRS_S2_Pos			2
#define PWMG_BRKIRS_S2_Msk			(0x01 << PWMG_BRKIRS_S2_Pos)

#define PWMG_IE_NC0A_Pos			0		//New Cycle		
#define PWMG_IE_NC0A_Msk			(0x01 << PWMG_IE_NC0A_Pos)
#define PWMG_IE_NC0B_Pos			1		
#define PWMG_IE_NC0B_Msk			(0x01 << PWMG_IE_NC0B_Pos)
#define PWMG_IE_NC1A_Pos			2		
#define PWMG_IE_NC1A_Msk			(0x01 << PWMG_IE_NC1A_Pos)
#define PWMG_IE_NC1B_Pos			3		
#define PWMG_IE_NC1B_Msk			(0x01 << PWMG_IE_NC1B_Pos)
#define PWMG_IE_NC2A_Pos			4		
#define PWMG_IE_NC2A_Msk			(0x01 << PWMG_IE_NC2A_Pos)
#define PWMG_IE_NC2B_Pos			5		
#define PWMG_IE_NC2B_Msk			(0x01 << PWMG_IE_NC2B_Pos)
#define PWMG_IE_NC3A_Pos			6		
#define PWMG_IE_NC3A_Msk			(0x01 << PWMG_IE_NC3A_Pos)
#define PWMG_IE_NC3B_Pos			7		
#define PWMG_IE_NC3B_Msk			(0x01 << PWMG_IE_NC3B_Pos)
#define PWMG_IE_HE0A_Pos			16		//High Level End
#define PWMG_IE_HE0A_Msk			(0x01 << PWMG_IE_HE0A_Pos)
#define PWMG_IE_HE0B_Pos			17		
#define PWMG_IE_HE0B_Msk			(0x01 << PWMG_IE_HE0B_Pos)
#define PWMG_IE_HE1A_Pos			18		
#define PWMG_IE_HE1A_Msk			(0x01 << PWMG_IE_HE1A_Pos)
#define PWMG_IE_HE1B_Pos			19		
#define PWMG_IE_HE1B_Msk			(0x01 << PWMG_IE_HE1B_Pos)
#define PWMG_IE_HE2A_Pos			20		
#define PWMG_IE_HE2A_Msk			(0x01 << PWMG_IE_HE2A_Pos)
#define PWMG_IE_HE2B_Pos			21		
#define PWMG_IE_HE2B_Msk			(0x01 << PWMG_IE_HE2B_Pos)
#define PWMG_IE_HE3A_Pos			22		
#define PWMG_IE_HE3A_Msk			(0x01 << PWMG_IE_HE3A_Pos)
#define PWMG_IE_HE3B_Pos			23		
#define PWMG_IE_HE3B_Msk			(0x01 << PWMG_IE_HE3B_Pos)

#define PWMG_CHEN_PWM0A_Pos		    0		
#define PWMG_CHEN_PWM0A_Msk		    (0x01 << PWMG_CHEN_PWM0A_Pos)
#define PWMG_CHEN_PWM1A_Pos		    1		
#define PWMG_CHEN_PWM1A_Msk		    (0x01 << PWMG_CHEN_PWM1A_Pos)
#define PWMG_CHEN_PWM2A_Pos		    2		
#define PWMG_CHEN_PWM2A_Msk		    (0x01 << PWMG_CHEN_PWM2A_Pos)
#define PWMG_CHEN_PWM3A_Pos		    3		
#define PWMG_CHEN_PWM3A_Msk		    (0x01 << PWMG_CHEN_PWM3A_Pos)
#define PWMG_CHEN_PWM0B_Pos		    8		
#define PWMG_CHEN_PWM0B_Msk		    (0x01 << PWMG_CHEN_PWM0B_Pos)
#define PWMG_CHEN_PWM1B_Pos		    9		
#define PWMG_CHEN_PWM1B_Msk		    (0x01 << PWMG_CHEN_PWM1B_Pos)
#define PWMG_CHEN_PWM2B_Pos		    10		
#define PWMG_CHEN_PWM2B_Msk		    (0x01 << PWMG_CHEN_PWM2B_Pos)
#define PWMG_CHEN_PWM3B_Pos		    11		
#define PWMG_CHEN_PWM3B_Msk		    (0x01 << PWMG_CHEN_PWM3B_Pos)

#define PWMG_IM_NC0A_Pos			0		
#define PWMG_IM_NC0A_Msk			(0x01 << PWMG_IM_NC0A_Pos)
#define PWMG_IM_NC0B_Pos			1		
#define PWMG_IM_NC0B_Msk			(0x01 << PWMG_IM_NC0B_Pos)
#define PWMG_IM_NC1A_Pos			2		
#define PWMG_IM_NC1A_Msk			(0x01 << PWMG_IM_NC1A_Pos)
#define PWMG_IM_NC1B_Pos			3		
#define PWMG_IM_NC1B_Msk			(0x01 << PWMG_IM_NC1B_Pos)
#define PWMG_IM_NC2A_Pos			4		
#define PWMG_IM_NC2A_Msk			(0x01 << PWMG_IM_NC2A_Pos)
#define PWMG_IM_NC2B_Pos			5		
#define PWMG_IM_NC2B_Msk			(0x01 << PWMG_IM_NC2B_Pos)
#define PWMG_IM_NC3A_Pos			6		
#define PWMG_IM_NC3A_Msk			(0x01 << PWMG_IM_NC3A_Pos)
#define PWMG_IM_NC3B_Pos			7		
#define PWMG_IM_NC3B_Msk			(0x01 << PWMG_IM_NC3B_Pos)
#define PWMG_IM_HE0A_Pos			16		
#define PWMG_IM_HE0A_Msk			(0x01 << PWMG_IM_HE0A_Pos)
#define PWMG_IM_HE0B_Pos			17		
#define PWMG_IM_HE0B_Msk			(0x01 << PWMG_IM_HE0B_Pos)
#define PWMG_IM_HE1A_Pos			18		
#define PWMG_IM_HE1A_Msk			(0x01 << PWMG_IM_HE1A_Pos)
#define PWMG_IM_HE1B_Pos			19		
#define PWMG_IM_HE1B_Msk			(0x01 << PWMG_IM_HE1B_Pos)
#define PWMG_IM_HE2A_Pos			20		
#define PWMG_IM_HE2A_Msk			(0x01 << PWMG_IM_HE2A_Pos)
#define PWMG_IM_HE2B_Pos			21		
#define PWMG_IM_HE2B_Msk			(0x01 << PWMG_IM_HE2B_Pos)
#define PWMG_IM_HE3A_Pos			22		
#define PWMG_IM_HE3A_Msk			(0x01 << PWMG_IM_HE3A_Pos)
#define PWMG_IM_HE3B_Pos			23		
#define PWMG_IM_HE3B_Msk			(0x01 << PWMG_IM_HE3B_Pos)

#define PWMG_NCIRS_PWM0A_Pos		0       //PWM0A New Cycle Interrupt Raw State��д1����
#define PWMG_NCIRS_PWM0A_Msk		(0x01 << PWMG_NCIRS_PWM0A_Pos)
#define PWMG_NCIRS_PWM0B_Pos		1
#define PWMG_NCIRS_PWM0B_Msk		(0x01 << PWMG_NCIRS_PWM0B_Pos)
#define PWMG_NCIRS_PWM1A_Pos		2
#define PWMG_NCIRS_PWM1A_Msk		(0x01 << PWMG_NCIRS_PWM1A_Pos)
#define PWMG_NCIRS_PWM1B_Pos		3
#define PWMG_NCIRS_PWM1B_Msk		(0x01 << PWMG_NCIRS_PWM1B_Pos)
#define PWMG_NCIRS_PWM2A_Pos		4
#define PWMG_NCIRS_PWM2A_Msk		(0x01 << PWMG_NCIRS_PWM2A_Pos)
#define PWMG_NCIRS_PWM2B_Pos		5
#define PWMG_NCIRS_PWM2B_Msk		(0x01 << PWMG_NCIRS_PWM2B_Pos)
#define PWMG_NCIRS_PWM3A_Pos		6
#define PWMG_NCIRS_PWM3A_Msk		(0x01 << PWMG_NCIRS_PWM3A_Pos)
#define PWMG_NCIRS_PWM3B_Pos		7
#define PWMG_NCIRS_PWM3B_Msk		(0x01 << PWMG_NCIRS_PWM3B_Pos)

#define PWMG_HEIRS_PWM0A_Pos		0       //PWM0A High Level End Interrupt Raw State��д1����
#define PWMG_HEIRS_PWM0A_Msk		(0x01 << PWMG_HEIRS_PWM0A_Pos)
#define PWMG_HEIRS_PWM0B_Pos		1
#define PWMG_HEIRS_PWM0B_Msk		(0x01 << PWMG_HEIRS_PWM0B_Pos)
#define PWMG_HEIRS_PWM1A_Pos		2
#define PWMG_HEIRS_PWM1A_Msk		(0x01 << PWMG_HEIRS_PWM1A_Pos)
#define PWMG_HEIRS_PWM1B_Pos		3
#define PWMG_HEIRS_PWM1B_Msk		(0x01 << PWMG_HEIRS_PWM1B_Pos)
#define PWMG_HEIRS_PWM2A_Pos		4
#define PWMG_HEIRS_PWM2A_Msk		(0x01 << PWMG_HEIRS_PWM2A_Pos)
#define PWMG_HEIRS_PWM2B_Pos		5
#define PWMG_HEIRS_PWM2B_Msk		(0x01 << PWMG_HEIRS_PWM2B_Pos)
#define PWMG_HEIRS_PWM3A_Pos		6
#define PWMG_HEIRS_PWM3A_Msk		(0x01 << PWMG_HEIRS_PWM3A_Pos)
#define PWMG_HEIRS_PWM3B_Pos		7
#define PWMG_HEIRS_PWM3B_Msk		(0x01 << PWMG_HEIRS_PWM3B_Pos)

#define PWMG_NCIF_PWM0A_Pos			0      
#define PWMG_NCIF_PWM0A_Msk			(0x01 << PWMG_NCIF_PWM0A_Pos)
#define PWMG_NCIF_PWM0B_Pos			1
#define PWMG_NCIF_PWM0B_Msk			(0x01 << PWMG_NCIF_PWM0B_Pos)
#define PWMG_NCIF_PWM1A_Pos			2
#define PWMG_NCIF_PWM1A_Msk			(0x01 << PWMG_NCIF_PWM1A_Pos)
#define PWMG_NCIF_PWM1B_Pos			3
#define PWMG_NCIF_PWM1B_Msk			(0x01 << PWMG_NCIF_PWM1B_Pos)
#define PWMG_NCIF_PWM2A_Pos			4
#define PWMG_NCIF_PWM2A_Msk			(0x01 << PWMG_NCIF_PWM2A_Pos)
#define PWMG_NCIF_PWM2B_Pos			5
#define PWMG_NCIF_PWM2B_Msk			(0x01 << PWMG_NCIF_PWM2B_Pos)
#define PWMG_NCIF_PWM3A_Pos			6
#define PWMG_NCIF_PWM3A_Msk			(0x01 << PWMG_NCIF_PWM3A_Pos)
#define PWMG_NCIF_PWM3B_Pos			7
#define PWMG_NCIF_PWM3B_Msk			(0x01 << PWMG_NCIF_PWM3B_Pos)

#define PWMG_HEIF_PWM0A_Pos			0       
#define PWMG_HEIF_PWM0A_Msk			(0x01 << PWMG_HEIF_PWM0A_Pos)
#define PWMG_HEIF_PWM0B_Pos			1
#define PWMG_HEIF_PWM0B_Msk			(0x01 << PWMG_HEIF_PWM0B_Pos)
#define PWMG_HEIF_PWM1A_Pos			2
#define PWMG_HEIF_PWM1A_Msk			(0x01 << PWMG_HEIF_PWM1A_Pos)
#define PWMG_HEIF_PWM1B_Pos			3
#define PWMG_HEIF_PWM1B_Msk			(0x01 << PWMG_HEIF_PWM1B_Pos)
#define PWMG_HEIF_PWM2A_Pos			4
#define PWMG_HEIF_PWM2A_Msk			(0x01 << PWMG_HEIF_PWM2A_Pos)
#define PWMG_HEIF_PWM2B_Pos			5
#define PWMG_HEIF_PWM2B_Msk			(0x01 << PWMG_HEIF_PWM2B_Pos)
#define PWMG_HEIF_PWM3A_Pos			6
#define PWMG_HEIF_PWM3A_Msk			(0x01 << PWMG_HEIF_PWM3A_Pos)
#define PWMG_HEIF_PWM3B_Pos			7
#define PWMG_HEIF_PWM3B_Msk			(0x01 << PWMG_HEIF_PWM3B_Pos)

#define PWMG_HCIE_PWM0A_Pos			0
#define PWMG_HCIE_PWM0A_Msk			(0x01 << PWMG_HCIE_PWM0A_Pos)
#define PWMG_HCIE_PWM0B_Pos			1
#define PWMG_HCIE_PWM0B_Msk			(0x01 << PWMG_HCIE_PWM0B_Pos)
#define PWMG_HCIE_PWM1A_Pos			2
#define PWMG_HCIE_PWM1A_Msk			(0x01 << PWMG_HCIE_PWM1A_Pos)
#define PWMG_HCIE_PWM1B_Pos			3
#define PWMG_HCIE_PWM1B_Msk			(0x01 << PWMG_HCIE_PWM1B_Pos)
#define PWMG_HCIE_PWM2A_Pos			4
#define PWMG_HCIE_PWM2A_Msk			(0x01 << PWMG_HCIE_PWM2A_Pos)
#define PWMG_HCIE_PWM2B_Pos			5
#define PWMG_HCIE_PWM2B_Msk			(0x01 << PWMG_HCIE_PWM2B_Pos)
#define PWMG_HCIE_PWM3A_Pos			6
#define PWMG_HCIE_PWM3A_Msk			(0x01 << PWMG_HCIE_PWM3A_Pos)
#define PWMG_HCIE_PWM3B_Pos			7
#define PWMG_HCIE_PWM3B_Msk			(0x01 << PWMG_HCIE_PWM3B_Pos)

#define PWMG_HCIM_PWM0A_Pos			0      
#define PWMG_HCIM_PWM0A_Msk			(0x01 << PWMG_HCIM_PWM0A_Pos)
#define PWMG_HCIM_PWM0B_Pos			1
#define PWMG_HCIM_PWM0B_Msk			(0x01 << PWMG_HCIM_PWM0B_Pos)
#define PWMG_HCIM_PWM1A_Pos			2
#define PWMG_HCIM_PWM1A_Msk			(0x01 << PWMG_HCIM_PWM1A_Pos)
#define PWMG_HCIM_PWM1B_Pos			3
#define PWMG_HCIM_PWM1B_Msk			(0x01 << PWMG_HCIM_PWM1B_Pos)
#define PWMG_HCIM_PWM2A_Pos			4
#define PWMG_HCIM_PWM2A_Msk			(0x01 << PWMG_HCIM_PWM2A_Pos)
#define PWMG_HCIM_PWM2B_Pos			5
#define PWMG_HCIM_PWM2B_Msk			(0x01 << PWMG_HCIM_PWM2B_Pos)
#define PWMG_HCIM_PWM3A_Pos			6
#define PWMG_HCIM_PWM3A_Msk			(0x01 << PWMG_HCIM_PWM3A_Pos)
#define PWMG_HCIM_PWM3B_Pos			7
#define PWMG_HCIM_PWM3B_Msk			(0x01 << PWMG_HCIM_PWM3B_Pos)

#define PWMG_HCIRS_PWM0A_Pos		0       //д1����
#define PWMG_HCIRS_PWM0A_Msk		(0x01 << PWMG_HCIRS_PWM0A_Pos)
#define PWMG_HCIRS_PWM0B_Pos		1
#define PWMG_HCIRS_PWM0B_Msk		(0x01 << PWMG_HCIRS_PWM0B_Pos)
#define PWMG_HCIRS_PWM1A_Pos		2
#define PWMG_HCIRS_PWM1A_Msk		(0x01 << PWMG_HCIRS_PWM1A_Pos)
#define PWMG_HCIRS_PWM1B_Pos		3
#define PWMG_HCIRS_PWM1B_Msk		(0x01 << PWMG_HCIRS_PWM1B_Pos)
#define PWMG_HCIRS_PWM2A_Pos		4
#define PWMG_HCIRS_PWM2A_Msk		(0x01 << PWMG_HCIRS_PWM2A_Pos)
#define PWMG_HCIRS_PWM2B_Pos		5
#define PWMG_HCIRS_PWM2B_Msk		(0x01 << PWMG_HCIRS_PWM2B_Pos)
#define PWMG_HCIRS_PWM3A_Pos		6
#define PWMG_HCIRS_PWM3A_Msk		(0x01 << PWMG_HCIRS_PWM3A_Pos)
#define PWMG_HCIRS_PWM3B_Pos		7
#define PWMG_HCIRS_PWM3B_Msk		(0x01 << PWMG_HCIRS_PWM3B_Pos)

#define PWMG_HCIF_PWM0A_Pos			0      
#define PWMG_HCIF_PWM0A_Msk			(0x01 << PWMG_HCIF_PWM0A_Pos)
#define PWMG_HCIF_PWM0B_Pos			1
#define PWMG_HCIF_PWM0B_Msk			(0x01 << PWMG_HCIF_PWM0B_Pos)
#define PWMG_HCIF_PWM1A_Pos			2
#define PWMG_HCIF_PWM1A_Msk			(0x01 << PWMG_HCIF_PWM1A_Pos)
#define PWMG_HCIF_PWM1B_Pos			3
#define PWMG_HCIF_PWM1B_Msk			(0x01 << PWMG_HCIF_PWM1B_Pos)
#define PWMG_HCIF_PWM2A_Pos			4
#define PWMG_HCIF_PWM2A_Msk			(0x01 << PWMG_HCIF_PWM2A_Pos)
#define PWMG_HCIF_PWM2B_Pos			5
#define PWMG_HCIF_PWM2B_Msk			(0x01 << PWMG_HCIF_PWM2B_Pos)
#define PWMG_HCIF_PWM3A_Pos			6
#define PWMG_HCIF_PWM3A_Msk			(0x01 << PWMG_HCIF_PWM3A_Pos)
#define PWMG_HCIF_PWM3B_Pos			7
#define PWMG_HCIF_PWM3B_Msk			(0x01 << PWMG_HCIF_PWM3B_Pos)




typedef struct {
	__IO uint32_t EN;                       //[0] ENABLE
    
	__IO uint32_t IE;                       //ֻ��Ϊ1ʱ��IF[CHx]��DMA�������ʱ���ܱ�Ϊ1������һֱ������0
    
	__IO uint32_t IM;                       //��Ϊ1ʱ����ʹIF[CHx]Ϊ1��dma_intҲ������˱�1
    
	__IO uint32_t IF;                       //д1����
	
	__IO uint32_t DSTSGIE;					//ֻ��Scatter Gatherģʽ��ʹ��
	
	__IO uint32_t DSTSGIM;					//ֻ��Scatter Gatherģʽ��ʹ��
	
	__IO uint32_t DSTSGIF;					//ֻ��Scatter Gatherģʽ��ʹ��
	
	__IO uint32_t SRCSGIE;					//ֻ��Scatter Gatherģʽ��ʹ��
	
	__IO uint32_t SRCSGIM;					//ֻ��Scatter Gatherģʽ��ʹ��
	
	__IO uint32_t SRCSGIF;					//ֻ��Scatter Gatherģʽ��ʹ��
	
		 uint32_t RESERVED[5];
	
	__IO uint32_t PRI;						//���ȼ���1 �����ȼ�    0 �����ȼ�
	
	struct {
		__IO uint32_t CR;
		
		__IO uint32_t AM;                   //Adress Mode
		
		__IO uint32_t DST;
		
		__IO uint32_t DSTSGADDR1;			//ֻ��Scatter Gatherģʽ��ʹ��
		
		__IO uint32_t DSTSGADDR2;			//ֻ��Scatter Gatherģʽ��ʹ��
		
		__IO uint32_t DSTSGADDR3;			//ֻ��Scatter Gatherģʽ��ʹ��
		
		__IO uint32_t MUX;
		
		__IO uint32_t SRC;
		
		__IO uint32_t SRCSGADDR1;			//ֻ��Scatter Gatherģʽ��ʹ��
		
		__IO uint32_t SRCSGADDR2;			//ֻ��Scatter Gatherģʽ��ʹ��
		
		__IO uint32_t SRCSGADDR3;			//ֻ��Scatter Gatherģʽ��ʹ��
		
		__I  uint32_t SR;
		
			 uint32_t RESERVED[4];
	} CH[4];
} DMA_TypeDef;


#define DMA_IE_CH0_Pos			    0		
#define DMA_IE_CH0_Msk			    (0x01 << DMA_IE_CH0_Pos)
#define DMA_IE_CH1_Pos			    1		
#define DMA_IE_CH1_Msk			    (0x01 << DMA_IE_CH1_Pos)
#define DMA_IE_CH2_Pos			    2		
#define DMA_IE_CH2_Msk			    (0x01 << DMA_IE_CH2_Pos)
#define DMA_IE_CH3_Pos			    3		
#define DMA_IE_CH3_Msk			    (0x01 << DMA_IE_CH3_Pos)

#define DMA_IM_CH0_Pos			    0		
#define DMA_IM_CH0_Msk			    (0x01 << DMA_IM_CH0_Pos)
#define DMA_IM_CH1_Pos			    1		
#define DMA_IM_CH1_Msk			    (0x01 << DMA_IM_CH1_Pos)
#define DMA_IM_CH2_Pos			    2		
#define DMA_IM_CH2_Msk			    (0x01 << DMA_IM_CH2_Pos)
#define DMA_IM_CH3_Pos			    3		
#define DMA_IM_CH3_Msk			    (0x01 << DMA_IM_CH3_Pos)

#define DMA_IF_CH0_Pos			    0		
#define DMA_IF_CH0_Msk			    (0x01 << DMA_IF_CH0_Pos)
#define DMA_IF_CH1_Pos			    1		
#define DMA_IF_CH1_Msk			    (0x01 << DMA_IF_CH1_Pos)
#define DMA_IF_CH2_Pos			    2		
#define DMA_IF_CH2_Msk			    (0x01 << DMA_IF_CH2_Pos)
#define DMA_IF_CH3_Pos			    3		
#define DMA_IF_CH3_Msk			    (0x01 << DMA_IF_CH3_Pos)

#define DMA_CR_LEN_Pos				0       //��ͨ�����䵥λ����
#define DMA_CR_LEN_Msk				(0xFFF << DMA_CR_LEN_Pos)
#define DMA_CR_RXEN_Pos				16		//����������䣬���䷽��ΪSRC-->DST
#define DMA_CR_RXEN_Msk				(0x01 << DMA_CR_RXEN_Pos)
#define DMA_CR_TXEN_Pos				17		//����������䣬���䷽��ΪDST-->SRC
#define DMA_CR_TXEN_Msk				(0x01 << DMA_CR_TXEN_Pos)
#define DMA_CR_AUTORE_Pos			18      //Auto Restart, ͨ���ڴ�����ɺ��Ƿ��Զ���������
#define DMA_CR_AUTORE_Msk			(0x01 << DMA_CR_AUTORE_Pos)

#define DMA_AM_DSTAM_Pos			0       //Address Mode	0 ��ַ�̶�    1 ��ַ����    2 scatter gatherģʽ
#define DMA_AM_DSTAM_Msk			(0x03 << DMA_AM_DSTAM_Pos)
#define DMA_AM_DSTBIT_Pos			2		//����λ��0 �ֽ�    1 ����    2 ��
#define DMA_AM_DSTBIT_Msk			(0x03 << DMA_AM_DSTBIT_Pos)
#define DMA_AM_DSTBURST_Pos			4		//�������ͣ�0 Single    1 Burst��Inc4��
#define DMA_AM_DSTBURST_Msk			(0x01 << DMA_AM_DSTBURST_Pos)
#define DMA_AM_SRCAM_Pos			8
#define DMA_AM_SRCAM_Msk			(0x03 << DMA_AM_SRCAM_Pos)
#define DMA_AM_SRCBIT_Pos			10
#define DMA_AM_SRCBIT_Msk			(0x03 << DMA_AM_SRCBIT_Pos)
#define DMA_AM_SRCBURST_Pos			12
#define DMA_AM_SRCBURST_Msk			(0x01 << DMA_AM_SRCBURST_Pos)

#define DMA_MUX_M0TRGSRC_Pos		0		//M0��Ӳ������Դ
#define DMA_MUX_M0TRGSRC_Msk		(0x03 << DMA_MUX_M0TRGSRC_Pos)
#define DMA_MUX_M0TRGEN_Pos			2		//M0��Ӳ������Դʹ��
#define DMA_MUX_M0TRGEN_Msk			(0x01 << DMA_MUX_M0TRGEN_Pos)
#define DMA_MUX_M1TRGSRC_Pos		8		//M1��Ӳ������Դ
#define DMA_MUX_M1TRGSRC_Msk		(0x03 << DMA_MUX_M1TRGSRC_Pos)
#define DMA_MUX_M1TRGEN_Pos			10		//M1��Ӳ������Դʹ��
#define DMA_MUX_M1TRGEN_Msk			(0x01 << DMA_MUX_M1TRGEN_Pos)

#define DMA_SR_DSTLEN_Pos			0		//ʣ�ഫ����
#define DMA_SR_DSTLEN_Msk			(0x1FFF<<DMA_SR_DSTLEN_Pos)
#define DMA_SR_DSTERR_Pos			13		//�������ô���
#define DMA_SR_DSTERR_Msk			(0x01 << DMA_SR_DSTERR_Pos)
#define DMA_SR_SRCLEN_Pos			16
#define DMA_SR_SRCLEN_Msk			(0x1FFF<<DMA_SR_SRCLEN_Pos)
#define DMA_SR_SRCERR_Pos			29
#define DMA_SR_SRCERR_Msk			(0x01 << DMA_SR_SRCERR_Pos)




typedef struct {
	__IO uint32_t DATA;
	
	__IO uint32_t ADDR;
	
	__IO uint32_t ERASE;
	
	__IO uint32_t REMAP;
	
	__IO uint32_t CFG0;
	
	__IO uint32_t CFG1;
	
	__IO uint32_t CFG2;
	
	     uint32_t RESERVED;
	
	__IO uint32_t STAT;
} FMC_TypeDef;


#define FMC_ADDR_ADDR_Pos			0
#define FMC_ADDR_ADDR_Msk			(0xFFFF << FMC_ADDR_ADDR_Pos)
#define FMC_ADDR_BUSY_Pos			30		//0 ����д����һ������
#define FMC_ADDR_BUSY_Msk			(0x01 << FMC_ADDR_BUSY_Pos)
#define FMC_ADDR_WREN_Pos			31
#define FMC_ADDR_WREN_Msk			(0x01u<< FMC_ADDR_WREN_Pos)

#define FMC_ERASE_PAGE_Pos			10
#define FMC_ERASE_PAGE_Msk			(0x3F << FMC_ERASE_PAGE_Pos)
#define FMC_ERASE_CHIP_Pos			16		//1 ��Ƭ����
#define FMC_ERASE_CHIP_Msk			(0x01 << FMC_ERASE_CHIP_Pos)
#define FMC_ERASE_REQ_Pos			31
#define FMC_ERASE_REQ_Msk			(0x01u<< FMC_ERASE_REQ_Pos)

#define FMC_REMAP_ON_Pos			0
#define FMC_REMAP_ON_Msk			(0x01 << FMC_REMAP_ON_Pos)
#define FMC_REMAP_OFFSET_Pos		1		//��0x000-0x800��2K��ַ�ķ���ӳ�䵽2K*OFFSET-2K*(OFFSET+1)��ַ��
#define FMC_REMAP_OFFSET_Msk		(0x3F << FMC_REMAP_OFFSET_Pos)

#define FMC_CFG0_1US_Pos			4		//1us��Ӧ���ٸ�ʱ�����ڣ�0��ʾ1������
#define FMC_CFG0_1US_Msk			(0x7F << FMC_CFG0_1US_Pos)
#define FMC_CFG0_CLK_Pos			16		//��ǰʱ�ӷ�Χ��0 25~50MHz   1 <25MHz   2 50~75MHz  3 75~100MHz
#define FMC_CFG0_CLK_Msk			(0x03 << FMC_CFG0_CLK_Pos)

#define FMC_CFG1_TERASE_Pos			0		//terase����Ҫ�����ms
#define FMC_CFG1_TERASE_Msk			(0x1F << FMC_CFG1_TERASE_Pos)
#define FMC_CFG1_TNVH1_Pos			5
#define FMC_CFG1_TNVH1_Msk			(0x7F << FMC_CFG1_TNVH1_Pos)
#define FMC_CFG1_TRCV_Pos			12
#define FMC_CFG1_TRCV_Msk			(0x03 << FMC_CFG1_TRCV_Pos)
#define FMC_CFG1_TNVH_Pos			14
#define FMC_CFG1_TNVH_Msk			(0x07 << FMC_CFG1_TNVH_Pos)
#define FMC_CFG1_TPROG_Pos			17
#define FMC_CFG1_TPROG_Msk			(0x3F << FMC_CFG1_TPROG_Pos)
#define FMC_CFG1_TPGS_Pos			23
#define FMC_CFG1_TPGS_Msk			(0x0F << FMC_CFG1_TPGS_Pos)
#define FMC_CFG1_TNVS_Pos			27
#define FMC_CFG1_TNVS_Msk			(0x07 << FMC_CFG1_TNVS_Pos)

#define FMC_STAT_ERASEBUSY_Pos		0
#define FMC_STAT_ERASEBUSY_Msk		(0x01 << FMC_STAT_ERASEBUSY_Pos)
#define FMC_STAT_PROGBUSY_Pos		1
#define FMC_STAT_PROGBUSY_Msk		(0x01 << FMC_STAT_PROGBUSY_Pos)
#define FMC_STAT_READBUSY_Pos		2
#define FMC_STAT_READBUSY_Msk		(0x01 << FMC_STAT_READBUSY_Pos)
#define FMC_STAT_PROGDONE_Pos		3
#define FMC_STAT_PROGDONE_Msk		(0x01 << FMC_STAT_PROGDONE_Pos)
#define FMC_STAT_ERASEDONE_Pos		4
#define FMC_STAT_ERASEDONE_Msk		(0x01 << FMC_STAT_ERASEDONE_Pos)




typedef struct {
    __IO uint32_t MINSEC;                   //�������
    
    __IO uint32_t DATHUR;                   //��ʱ����
    
    __IO uint32_t MONDAY;                   //���ܼ���
    
    __IO uint32_t YEAR;                     //[11:0] �������֧��1901-2199
    
    __IO uint32_t MINSECAL;                 //������������
    
    __IO uint32_t DAYHURAL;                 //��ʱ��������
    
    __IO uint32_t LOAD;
    
    __IO uint32_t IE;
    
    __IO uint32_t IF;                       //д1����
    
    __IO uint32_t EN;                       //[0] 1 RTCʹ��
    
    __IO uint32_t CFGABLE;                  //[0] 1 RTC������
    
    __IO uint32_t TRIM;                     //ʱ�ӵ���
    
    __IO uint32_t TRIMM;                    //ʱ��΢����
	
		 uint32_t RESERVED[11];
	
	__IO uint32_t CALIBCNT;
	
	__IO uint32_t CALIBEN;
	
	__IO uint32_t CALIBSR;
} RTC_TypeDef;


#define RTC_MINSEC_SEC_Pos			0       //�������ȡֵ0--59
#define RTC_MINSEC_SEC_Msk		    (0x3F << RTC_MINSEC_SEC_Pos)
#define RTC_MINSEC_MIN_Pos			6       //���Ӽ�����ȡֵ0--59
#define RTC_MINSEC_MIN_Msk		    (0x3F << RTC_MINSEC_MIN_Pos)

#define RTC_DATHUR_HOUR_Pos			0       //Сʱ������ȡֵ0--23
#define RTC_DATHUR_HOUR_Msk		    (0x1F << RTC_DATHUR_HOUR_Pos)
#define RTC_DATHUR_DATE_Pos			5       //date of month��ȡֵ1--31
#define RTC_DATHUR_DATE_Msk		    (0x1F << RTC_DATHUR_DATE_Pos)

#define RTC_MONDAY_DAY_Pos			0       //day of week��ȡֵ0--6
#define RTC_MONDAY_DAY_Msk		    (0x07 << RTC_MONDAY_DAY_Pos)
#define RTC_MONDAY_MON_Pos			3       //�·ݼ�����ȡֵ1--12
#define RTC_MONDAY_MON_Msk		    (0x0F << RTC_MONDAY_MON_Pos)

#define RTC_MINSECAL_SEC_Pos		0       //����������
#define RTC_MINSECAL_SEC_Msk		(0x3F << RTC_MINSECAL_SEC_Pos)
#define RTC_MINSECAL_MIN_Pos	    6       //���ӷ�������
#define RTC_MINSECAL_MIN_Msk		(0x3F << RTC_MINSECAL_MIN_Pos)

#define RTC_DAYHURAL_HOUR_Pos		0       //����Сʱ����
#define RTC_DAYHURAL_HOUR_Msk		(0x1F << RTC_DAYHURAL_HOUR_Pos)
#define RTC_DAYHURAL_SUN_Pos		5       //����������Ч
#define RTC_DAYHURAL_SUN_Msk		(0x01 << RTC_DAYHURAL_SUN_Pos)
#define RTC_DAYHURAL_MON_Pos		6       //��һ������Ч
#define RTC_DAYHURAL_MON_Msk		(0x01 << RTC_DAYHURAL_MON_Pos)
#define RTC_DAYHURAL_TUE_Pos		7       //�ܶ�������Ч
#define RTC_DAYHURAL_TUE_Msk		(0x01 << RTC_DAYHURAL_TUE_Pos)
#define RTC_DAYHURAL_WED_Pos		8       //����������Ч
#define RTC_DAYHURAL_WED_Msk		(0x01 << RTC_DAYHURAL_WED_Pos)
#define RTC_DAYHURAL_THU_Pos		9       //����������Ч
#define RTC_DAYHURAL_THU_Msk		(0x01 << RTC_DAYHURAL_THU_Pos)
#define RTC_DAYHURAL_FRI_Pos		10      //����������Ч
#define RTC_DAYHURAL_FRI_Msk		(0x01 << RTC_DAYHURAL_FRI_Pos)
#define RTC_DAYHURAL_SAT_Pos		11      //����������Ч
#define RTC_DAYHURAL_SAT_Msk		(0x01 << RTC_DAYHURAL_SAT_Pos)

#define RTC_LOAD_TIME_Pos			0		//��ʱ�䡢��ʱ��У׼��ؼĴ����е�ֵ���ص�RTCʱ����
#define RTC_LOAD_TIME_Msk			(0x01 << RTC_LOAD_TIME_Pos)
#define RTC_LOAD_ALARM_Pos			1		//��������ؼĴ����е�ֵ���ص�RTCʱ����
#define RTC_LOAD_ALARM_Msk			(0x01 << RTC_LOAD_ALARM_Pos)

#define RTC_IE_SEC_Pos		        0       //���ж�ʹ��
#define RTC_IE_SEC_Msk		        (0x01 << RTC_IE_SEC_Pos)
#define RTC_IE_MIN_Pos		        1
#define RTC_IE_MIN_Msk		        (0x01 << RTC_IE_MIN_Pos)
#define RTC_IE_HOUR_Pos		        2
#define RTC_IE_HOUR_Msk		        (0x01 << RTC_IE_HOUR_Pos)
#define RTC_IE_DATE_Pos		        3
#define RTC_IE_DATE_Msk		        (0x01 << RTC_IE_DATE_Pos)
#define RTC_IE_ALARM_Pos		    4
#define RTC_IE_ALARM_Msk		    (0x01 << RTC_IE_ALARM_Pos)
#define RTC_IE_TRIM_Pos				5		//У׼����ж�ʹ��
#define RTC_IE_TRIM_Msk				(0x01 << RTC_IE_TRIM_Pos)
#define RTC_IE_HSEC_Pos				6		//�����ж�ʹ��
#define RTC_IE_HSEC_Msk				(0x01 << RTC_IE_HSEC_Pos)
#define RTC_IE_QSEC_Pos				7		//�ķ�֮һ���ж�ʹ��
#define RTC_IE_QSEC_Msk				(0x01 << RTC_IE_QSEC_Pos)

#define RTC_IF_SEC_Pos		        0       //д1����
#define RTC_IF_SEC_Msk		        (0x01 << RTC_IF_SEC_Pos)
#define RTC_IF_MIN_Pos		        1
#define RTC_IF_MIN_Msk		        (0x01 << RTC_IF_MIN_Pos)
#define RTC_IF_HOUR_Pos		        2
#define RTC_IF_HOUR_Msk		        (0x01 << RTC_IF_HOUR_Pos)
#define RTC_IF_DATE_Pos		        3
#define RTC_IF_DATE_Msk		        (0x01 << RTC_IF_DATE_Pos)
#define RTC_IF_ALARM_Pos		    4
#define RTC_IF_ALARM_Msk		    (0x01 << RTC_IF_ALARM_Pos)
#define RTC_IF_TRIM_Pos				5
#define RTC_IF_TRIM_Msk				(0x01 << RTC_IF_TRIM_Pos)
#define RTC_IF_HSEC_Pos				6
#define RTC_IF_HSEC_Msk				(0x01 << RTC_IF_HSEC_Pos)
#define RTC_IF_QSEC_Pos				7
#define RTC_IF_QSEC_Msk				(0x01 << RTC_IF_QSEC_Pos)

#define RTC_TRIM_ADJ_Pos		    0       //���ڵ���BASECNT�ļ������ڣ�Ĭ��Ϊ32768�����DECΪ1����������ڵ���Ϊ32768-ADJ���������Ϊ32768+ADJ
#define RTC_TRIM_ADJ_Msk		    (0xFF << RTC_TRIM_ADJ_Pos)
#define RTC_TRIM_DEC_Pos		    8
#define RTC_TRIM_DEC_Msk		    (0x01 << RTC_TRIM_DEC_Pos)

#define RTC_TRIMM_CYCLE_Pos		    0       //���ڼ�������΢�������INCΪ1�����n���������ڵ���Ϊ(32768��ADJ)+1,�������Ϊ(32768��ADJ)-1
                                            //cycles=0ʱ��������΢������cycles=1����nΪ2��cycles=7����nΪ8���Դ�����
#define RTC_TRIMM_CYCLE_Msk		    (0x07 << RTC_TRIMM_CYCLE_Pos)
#define RTC_TRIMM_INC_Pos		    3
#define RTC_TRIMM_INC_Msk		    (0x01 << RTC_TRIMM_INC_Pos)




typedef struct {
	__IO uint32_t RSTVAL;					//��������������ֵʱ������λ
	
	__IO uint32_t INTVAL;					//��������������ֵʱ�����ж�
	
	__IO uint32_t CR;
	
	__IO uint32_t IF;						//[0] �жϱ�־��д1����
	
	__IO uint32_t FEED;						//д0x55ι��
} WDT_TypeDef;


#define WDT_CR_EN_Pos				0
#define WDT_CR_EN_Msk				(0x01 << WDT_CR_EN_Pos)
#define WDT_CR_RSTEN_Pos			1
#define WDT_CR_RSTEN_Msk			(0x01 << WDT_CR_RSTEN_Pos)
#define WDT_CR_INTEN_Pos			2
#define WDT_CR_INTEN_Msk			(0x01 << WDT_CR_INTEN_Pos)
#define WDT_CR_LOCK_Pos				3
#define WDT_CR_LOCK_Msk				(0x01 << WDT_CR_LOCK_Pos)



/******************************************************************************/
/*						 Peripheral memory map							  */
/******************************************************************************/
#define RAM_BASE		   	0x20000000
#define AHB_BASE			0x40000000
#define APB1_BASE		 	0x40040000
#define APB2_BASE			0x400A0000


/* AHB Peripheral memory map */
#define SYS_BASE			(AHB_BASE + 0x00000)

#define DMA_BASE			(AHB_BASE + 0x00800)


/* APB1 Peripheral memory map */
#define GPIOA_BASE			(APB1_BASE + 0x0000)
#define GPIOB_BASE			(APB1_BASE + 0x0800)
#define GPIOC_BASE			(APB1_BASE + 0x1000)
#define GPIOD_BASE			(APB1_BASE + 0x1800)

#define UART0_BASE			(APB1_BASE + 0x2000)
#define UART1_BASE			(APB1_BASE + 0x2800)
#define UART2_BASE			(APB1_BASE + 0x3000)
#define UART3_BASE			(APB1_BASE + 0x3800)

#define SPI0_BASE			(APB1_BASE + 0x4000)
#define SPI1_BASE           (APB1_BASE + 0x4800)

#define I2C4_BASE			(APB1_BASE + 0x5000)

#define PWM0_BASE			(APB1_BASE + 0x6000)
#define PWM1_BASE			(APB1_BASE + 0x6040)
#define PWM2_BASE			(APB1_BASE + 0x6080)
#define PWM3_BASE			(APB1_BASE + 0x60C0)
#define PWMG_BASE			(APB1_BASE + 0x6200)

#define TIMR0_BASE			(APB1_BASE + 0x6800)
#define TIMR1_BASE			(APB1_BASE + 0x6840)
#define TIMR2_BASE			(APB1_BASE + 0x6880)
#define TIMR3_BASE			(APB1_BASE + 0x68C0)
#define TIMRG_BASE			(APB1_BASE + 0x6C00)

#define BTIMR0_BASE			(APB1_BASE + 0x8800)
#define BTIMR1_BASE			(APB1_BASE + 0x8840)
#define BTIMR2_BASE			(APB1_BASE + 0x8880)
#define BTIMR3_BASE			(APB1_BASE + 0x88C0)
#define BTIMRG_BASE			(APB1_BASE + 0x8C00)

#define ADC0_BASE			(APB1_BASE + 0x9000)

#define FMC_BASE			(APB1_BASE + 0xA000)		//Flash Memory Controller

#define RTC_BASE			(APB1_BASE + 0xB800)


/* APB2 Peripheral memory map */
#define PORT_BASE			(APB2_BASE + 0x0000)

#define WDT_BASE			(APB2_BASE + 0x0800)

#define UART4_BASE			(APB2_BASE + 0x3000)



/******************************************************************************/
/*						 Peripheral declaration							 */
/******************************************************************************/
#define SYS					((SYS_TypeDef  *) SYS_BASE)

#define PORT				((PORT_TypeDef *) PORT_BASE)

#define GPIOA				((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB				((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC				((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD				((GPIO_TypeDef *) GPIOD_BASE)

#define TIMR0				((TIMR_TypeDef *) TIMR0_BASE)
#define TIMR1				((TIMR_TypeDef *) TIMR1_BASE)
#define TIMR2				((TIMR_TypeDef *) TIMR2_BASE)
#define TIMR3				((TIMR_TypeDef *) TIMR3_BASE)
#define TIMRG				((TIMRG_TypeDef*) TIMRG_BASE)

#define BTIMR0				((TIMR_TypeDef *) BTIMR0_BASE)
#define BTIMR1				((TIMR_TypeDef *) BTIMR1_BASE)
#define BTIMR2				((TIMR_TypeDef *) BTIMR2_BASE)
#define BTIMR3				((TIMR_TypeDef *) BTIMR3_BASE)
#define BTIMRG				((TIMRG_TypeDef*) BTIMRG_BASE)

#define UART0				((UART_TypeDef *) UART0_BASE)
#define UART1				((UART_TypeDef *) UART1_BASE)
#define UART2				((UART_TypeDef *) UART2_BASE)
#define UART3   			((UART_TypeDef *) UART3_BASE)
#define UART4   			((UART_TypeDef *) UART4_BASE)

#define SPI0				((SPI_TypeDef  *) SPI0_BASE)
#define SPI1				((SPI_TypeDef  *) SPI1_BASE)

#define I2C4				((I2C_TypeDef  *) I2C4_BASE)

#define ADC0 				((ADC_TypeDef  *) ADC0_BASE)

#define PWM0				((PWM_TypeDef  *) PWM0_BASE)
#define PWM1				((PWM_TypeDef  *) PWM1_BASE)
#define PWM2				((PWM_TypeDef  *) PWM2_BASE)
#define PWM3				((PWM_TypeDef  *) PWM3_BASE)
#define PWMG				((PWMG_TypeDef *) PWMG_BASE)

#define DMA 				((DMA_TypeDef  *) DMA_BASE)

#define FMC					((FMC_TypeDef  *) FMC_BASE)

#define RTC					((RTC_TypeDef  *) RTC_BASE)

#define WDT					((WDT_TypeDef  *) WDT_BASE)


#include "SWM260_port.h"
#include "SWM260_gpio.h"
#include "SWM260_exti.h"
#include "SWM260_timr.h"
#include "SWM260_uart.h"
#include "SWM260_spi.h"
#include "SWM260_i2c.h"
#include "SWM260_pwm.h"
#include "SWM260_adc.h"
#include "SWM260_dma.h"
#include "SWM260_rtc.h"
#include "SWM260_wdt.h"
#include "SWM260_flash.h"
#include "SWM260_sleep.h"


#endif //__SWM260_H__
