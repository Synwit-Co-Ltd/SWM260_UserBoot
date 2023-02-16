/****************************************************************************************************************************************** 
* �ļ�����:	SWM260_flash.c
* ����˵��:	ʹ��оƬ��IAP���ܽ�Ƭ��Flashģ���EEPROM���������ݣ�����󲻶�ʧ
* ����֧��:	http://www.synwit.com.cn/e/tool/gbook/?bid=1
* ע������:
* �汾����: V1.0.0		2016��1��30��
* ������¼: 
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
#include "SWM260_flash.h"


/****************************************************************************************************************************************** 
* ��������:	FLASH_Erase()
* ����˵��:	FLASH����������ÿ������2K�ֽ�
* ��    ��: uint32_t addr		Ҫ���������ĵ�ַ������2K���룬��addr%2048 == 0
* ��    ��: uint32_t			FLASH_RES_OK��FLASH_RES_TO��FLASH_RES_ERR
* ע������: ��
******************************************************************************************************************************************/
#if defined ( __ICCARM__ )
__ramfunc
#endif
uint32_t FLASH_Erase(uint32_t addr)
{
	if(addr >= 128*1024) return FLASH_RES_ERR;
	
	FMC->ERASE = (1u << FMC_ERASE_REQ_Pos) | ((addr >> 11) << FMC_ERASE_PAGE_Pos);
	while(FMC->STAT & FMC_STAT_ERASEBUSY_Msk) __NOP();
	
	return FLASH_RES_OK;
}


/****************************************************************************************************************************************** 
* ��������:	FLASH_Write()
* ����˵��:	FLASH����д��
* ��    ��: uint32_t addr		����Ҫд�뵽Flash�еĵ�ַ���ֶ���
*			uint32_t buff[]		Ҫд��Flash�е�����
*			uint32_t cnt		Ҫд�����ݵĸ���������Ϊ��λ�����512
* ��    ��: uint32_t			FLASH_RES_OK��FLASH_RES_TO��FLASH_RES_ERR
* ע������: Ҫд������ݱ���ȫ����ͬһҳ�ڣ�ÿҳ2K����addr/2048 == (addr+cnt*4)/2048
******************************************************************************************************************************************/
#if defined ( __ICCARM__ )
__ramfunc
#endif
uint32_t FLASH_Write(uint32_t addr, uint32_t buff[], uint32_t cnt)
{	
	uint32_t i;
	
	if((addr+cnt*4) >= 128*1024) return FLASH_RES_ERR;
	
	if(addr/2048 != (addr+cnt*4)/2048) return FLASH_RES_ERR;	// ��ҳ
	
	FMC->ADDR = (1u << FMC_ADDR_WREN_Pos) | (addr << FMC_ADDR_ADDR_Pos);
	for(i = 0; i < cnt; i++)
	{
		FMC->DATA = buff[i];
		while(FMC->ADDR & FMC_ADDR_BUSY_Msk) __NOP();
	}
	while(FMC->STAT & FMC_STAT_PROGBUSY_Msk) __NOP();
	
	FMC->ADDR = 0;
	
	return FLASH_RES_OK;
}
