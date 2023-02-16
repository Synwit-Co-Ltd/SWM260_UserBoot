#ifndef __SWM260_SPI_H__
#define __SWM260_SPI_H__

typedef struct {
	uint8_t  FrameFormat;	//֡��ʽ��SPI_FORMAT_SPI��SPI_FORMAT_TI_SSI
	uint8_t  SampleEdge;	//��SPI֡��ʽ�£�ѡ�����ݲ������أ�SPI_FIRST_EDGE��SPI_SECOND_EDGE
	uint8_t  IdleLevel;		//��SPI֡��ʽ�£�ѡ�����ʱ�������ݴ���ʱ��ʱ���ߵĵ�ƽ��SPI_LOW_LEVEL��SPI_HIGH_LEVEL
	uint8_t  WordSize;		//�ֳ���, ��Чֵ4-16
	uint8_t  Master;		//1 ����ģʽ    0 �ӻ�ģʽ
	uint8_t  clkDiv;		//SPI_CLK = SYS_CLK / clkDiv����Чֵ��SPI_CLKDIV_4��SPI_CLKDIV_8��... ... ��SPI_CLKDIV_512
	
	uint8_t  RXThreshold;	//ȡֵ1--8
	uint8_t  RXThresholdIEn;//��RX FIFO�����ݸ��� >= RXThresholdʱ�����ж�
	
	uint8_t  TXThreshold;	//ȡֵ0--7
	uint8_t  TXThresholdIEn;//��TX FIFO�����ݸ��� <= TXThresholdʱ�����ж�
	
	uint8_t  TXCompleteIEn;	//����FIFO���ҷ�����λ�Ĵ������ж�ʹ��
} SPI_InitStructure;

#define SPI_FORMAT_SPI			0		//Motorola SPI ��ʽ
#define SPI_FORMAT_TI_SSI		1		//TI SSI ��ʽ
#define SPI_FORMAT_I2S			2

#define SPI_FIRST_EDGE			0		//��һ��ʱ���ؿ�ʼ����
#define SPI_SECOND_EDGE			1		//�ڶ���ʱ���ؿ�ʼ����

#define SPI_LOW_LEVEL			0		//����ʱʱ���߱��ֵ͵�ƽ
#define SPI_HIGH_LEVEL			1		//����ʱʱ���߱��ָߵ�ƽ

#define SPI_CLKDIV_4			0
#define SPI_CLKDIV_8			1
#define SPI_CLKDIV_16			2
#define SPI_CLKDIV_32			3
#define SPI_CLKDIV_64			4
#define SPI_CLKDIV_128			5
#define SPI_CLKDIV_256			6
#define SPI_CLKDIV_512			7


void SPI_Init(SPI_TypeDef * SPIx, SPI_InitStructure * initStruct);		//SPI��ʼ��
void SPI_Open(SPI_TypeDef * SPIx);										//SPI�򿪣������շ�
void SPI_Close(SPI_TypeDef * SPIx);										//SPI�رգ���ֹ�շ�

uint32_t SPI_Read(SPI_TypeDef * SPIx);
void SPI_Write(SPI_TypeDef * SPIx, uint32_t data);
void SPI_WriteWithWait(SPI_TypeDef * SPIx, uint32_t data);
uint32_t SPI_ReadWrite(SPI_TypeDef * SPIx, uint32_t data);

uint32_t SPI_IsRXEmpty(SPI_TypeDef * SPIx);				//����FIFO�Ƿ�գ������������Լ���SPI_Read()
uint32_t SPI_IsTXFull(SPI_TypeDef * SPIx);				//����FIFO�Ƿ����������������Լ���SPI_Write()
uint32_t SPI_IsTXEmpty(SPI_TypeDef * SPIx);				//����FIFO�Ƿ��


void SPI_INTRXHalfFullEn(SPI_TypeDef * SPIx);
void SPI_INTRXHalfFullDis(SPI_TypeDef * SPIx);
void SPI_INTRXHalfFullClr(SPI_TypeDef * SPIx);
uint32_t SPI_INTRXHalfFullStat(SPI_TypeDef * SPIx);
void SPI_INTRXFullEn(SPI_TypeDef * SPIx);
void SPI_INTRXFullDis(SPI_TypeDef * SPIx);
void SPI_INTRXFullClr(SPI_TypeDef * SPIx);
uint32_t SPI_INTRXFullStat(SPI_TypeDef * SPIx);
void SPI_INTRXOverflowEn(SPI_TypeDef * SPIx);
void SPI_INTRXOverflowDis(SPI_TypeDef * SPIx);
void SPI_INTRXOverflowClr(SPI_TypeDef * SPIx);
uint32_t SPI_INTRXOverflowStat(SPI_TypeDef * SPIx);

void SPI_INTTXEmptyEn(SPI_TypeDef * SPIx);
void SPI_INTTXEmptyDis(SPI_TypeDef * SPIx);
void SPI_INTTXEmptyClr(SPI_TypeDef * SPIx);
uint32_t SPI_INTTXEmptyStat(SPI_TypeDef * SPIx);
void SPI_INTTXCompleteEn(SPI_TypeDef * SPIx);
void SPI_INTTXCompleteDis(SPI_TypeDef * SPIx);
void SPI_INTTXCompleteClr(SPI_TypeDef * SPIx);
uint32_t SPI_INTTXCompleteStat(SPI_TypeDef * SPIx);

void SPI_INTRXThresholdEn(SPI_TypeDef * SPIx);
void SPI_INTRXThresholdDis(SPI_TypeDef * SPIx);
void SPI_INTRXThresholdClr(SPI_TypeDef * SPIx);
uint32_t SPI_INTRXThresholdStat(SPI_TypeDef * SPIx);
void SPI_INTTXThresholdEn(SPI_TypeDef * SPIx);
void SPI_INTTXThresholdDis(SPI_TypeDef * SPIx);
void SPI_INTTXThresholdClr(SPI_TypeDef * SPIx);
uint32_t SPI_INTTXThresholdStat(SPI_TypeDef * SPIx);


#endif //__SWM260_SPI_H__