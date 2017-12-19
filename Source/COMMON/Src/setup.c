#include "header.h"
#include "setup.h"
#include <stdint.h>

static struct tag *params;
#if 0
void MemoryInit(void)
{	
	/* Enable the FSMC Clock */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC, ENABLE);
	
	/* Configure FSMC Bank1 NOR/SRAM2 */
  NOR_Init();
	/* Configure FSMC Bank1 NOR/SRAM3 */
  SRAM_Init();
	/* Configure FSMC Bank2 NAND1 */
	//NAND_Init();
}
#endif

int isBootFromNorFlash(void)
{
	volatile int *p = (volatile int *)0;
	int val;

  val = *p;
  *p = 0x12345678;

  if(*p == 0x12345678)
	{
		/* 写成功，Nand启动 */
		*p = val;
		return 0;
	}
	else
	{
		return 1;
	}
}

void CopyCodeToSram(unsigned char *src, unsigned char *dest, unsigned int len)
{
	int i = 0;
	
	/* 如果是NOR启动 */
	if(isBootFromNorFlash())
	{
		while(i < len)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else
	{
		//nand_read();
	}
}

int mystrlen(char *str)
{
	int i = 0;
	
	while(str[i]) 
		i++;
	
	return i;
}

void mystrcpy(char *dest, char *src)
{
	while((*dest++ = *src++) != '\0');
}

void myputc(char ch)
{
	USART_SendData(USART1, ch);

  /* Loop until the end of transmission */
  while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
  {}
}

void myputs(char *str)
{
	int i = 0;
	
	while(str[i])
	{
		myputc(str[i]);
		i++;
	}
}

void puthex(unsigned int val)
{
	int i,j;
	
	myputs("0x");
	
	for(i = 0; i < 8; i++)
	{
		j = (val >> ((7-i)*4)) & 0xf;
		if((j >= 0) && (j <= 9))
			myputc('0'+j);
		else
			myputc('A'+j - 0xa);
	}
}


void setup_start_tag(void)
{
	params = (struct tag *) (((uint32_t)TagStartAddress));

	params->hdr.tag = ATAG_CORE;
	params->hdr.size = tag_size (tag_core);

	params->u.core.flags = 0;
	params->u.core.pagesize = 0;
	params->u.core.rootdev = 0;

	params = tag_next (params);
}

void setup_memory_tags(void)
{

	params->hdr.tag = ATAG_MEM;
	params->hdr.size = tag_size (tag_mem32);
	params->u.mem.start = MemStart;
	params->u.mem.size = MemSize;

	params = tag_next (params);

}

void setup_commandline_tag(char *cmdline)
{
	int len = mystrlen(cmdline) + 1;

	params->hdr.tag = ATAG_CMDLINE;
	params->hdr.size =
		(sizeof (struct tag_header) + len + 3) >> 2; //向4取整

	mystrcpy (params->u.cmdline.cmdline, cmdline);

	params = tag_next (params);
}

void setup_end_tag(void)
{
	params->hdr.tag = ATAG_NONE;
	params->hdr.size = 0;
}




