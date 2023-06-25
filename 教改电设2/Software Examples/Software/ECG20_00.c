/////////////////////////////////////
//  Generated Initialization File  //
/////////////////////////////////////
/*****************************************************************
�汾��־��
V00��
1���������������
2����ʱ������
3����ˮ�Ƴ���
*/

#include "compiler_defs.h"
#include "C8051F340_defs.h"

//�������ͱ�ʶ�ĺ궨��
#define Uchar unsigned char
#define Uint unsigned int
#define uchar unsigned char
#define uint unsigned int

uint	Timer_Count;	//��ʱ������
uchar	Timer_Count_2;	//��ʱ������2
uchar	Led_State;		//LED��ʾ״̬


//�ӿڶ���
/*
sbit	Led1 = P4^4;
sbit	Led2 = P4^5;
sbit	Led3 = P4^6;
sbit	Led4 = P4^7;

sbit	Key1 = P4^3;
sbit	Key2 = P4^4;
sbit	Key3 = P4^1;
sbit	Key3 = P4^0;
*/

#define	XFCN	6		//3		//5

#define LED1_ON P4 |= 0x10
#define LED2_ON P4 |= 0x20
#define LED3_ON P4 |= 0x40
#define LED4_ON P4 |= 0x80

#define LED1_OFF P4 &= ~0x10
#define LED2_OFF P4 &= ~0x20
#define LED3_OFF P4 &= ~0x40
#define LED4_OFF P4 &= ~0x80

#define LED1_INVERT P4 ^= 0x10
#define LED2_INVERT P4 ^= 0x20
#define LED3_INVERT P4 ^= 0x40
#define LED4_INVERT P4 ^= 0x80

sbit	Ad_in	= P1^0;

bit		timer_flag;

//-----------------------------------------------------------------------------
// Port_Init
//-----------------------------------------------------------------------------
// Peripheral specific initialization functions,
// Called from the Init_Device() function
void Port_IO_Init()
{
    // P0.0  -  SCK  (SPI0), Push-Pull,  Digital
    // P0.1  -  MISO (SPI0), Open-Drain, Digital
    // P0.2  -  Skipped,     Open-Drain, Digital
    // P0.3  -  Skipped,     Open-Drain, Digital
    // P0.4  -  TX0 (UART0), Push-Pull,  Digital
    // P0.5  -  RX0 (UART0), Open-Drain, Digital
    // P0.6  -  MOSI (SPI0), Push-Pull,  Digital
    // P0.7  -  NSS  (SPI0), Push-Pull,  Digital

    // P1.0  -  Unassigned,  Open-Drain, Analog
    // P1.1  -  Unassigned,  Open-Drain, Digital
    // P1.2  -  Unassigned,  Open-Drain, Digital
    // P1.3  -  Unassigned,  Push-Pull,  Digital
    // P1.4  -  Unassigned,  Push-Pull,  Digital
    // P1.5  -  Unassigned,  Push-Pull,  Digital
    // P1.6  -  Unassigned,  Push-Pull,  Digital
    // P1.7  -  Unassigned,  Push-Pull,  Digital

    // P2.0  -  Unassigned,  Push-Pull,  Digital
    // P2.1  -  Unassigned,  Push-Pull,  Digital
    // P2.2  -  Unassigned,  Push-Pull,  Digital
    // P2.3  -  Unassigned,  Push-Pull,  Digital
    // P2.4  -  Unassigned,  Push-Pull,  Digital
    // P2.5  -  Unassigned,  Open-Drain, Digital
    // P2.6  -  Unassigned,  Open-Drain, Digital
    // P2.7  -  Unassigned,  Open-Drain, Digital

    // P3.0  -  Unassigned,  Push-Pull,  Digital
    // P3.1  -  Unassigned,  Push-Pull,  Digital
    // P3.2  -  Unassigned,  Push-Pull,  Digital
    // P3.3  -  Unassigned,  Push-Pull,  Digital
    // P3.4  -  Unassigned,  Push-Pull,  Digital
    // P3.5  -  Unassigned,  Push-Pull,  Digital
    // P3.6  -  Unassigned,  Push-Pull,  Digital
    // P3.7  -  Unassigned,  Push-Pull,  Digital

    P1MDIN    = 0xFE;
    P0MDOUT   = 0xD1;
    P1MDOUT   = 0xF8;
    P2MDOUT   = 0x1F;
    P3MDOUT   = 0xFF;
    P4MDOUT   = 0xF0;
    P0SKIP    = 0x0C;
    XBR0      = 0x03;
    XBR1      = 0x40;
}

//-----------------------------------------------------------------------------
// SYSCLK_Init
//-----------------------------------------------------------------------------
// Initialization function for device,
// Call Init_Device() from your main program
void Init_Device(void)
{
    Port_IO_Init();
	OSCICN = (0x80 | 0x03);
}


/********************��ʱ����************************/
//��ʱy ms
void	Delay(uint y)
{
	uint	x;
	while (y--)
	{
		x = 862;
		while (x--);
	}
}



/********************������**************************/
void main(void)
{
	PCA0MD &= ~0x40;			// WDTE = 0 (clear watchdog timer enable)

	Init_Device();				//����оƬ�˿�

	P4 &= 0x0f;

	while(1)
	{
		Delay(500);
//		LED1_INVERT;			//��˸
		Led_State++;
		Led_State &= 0x03;		//�޶���ֵ��Χ
		P4 &= 0x0f;				//Ϩ�����е�
		switch (Led_State)
			{
			case 0:
				LED1_ON;
				break;
			case 1:
				LED2_ON;
				break;
			case 2:
				LED3_ON;
				break;
			case 3:
				LED4_ON;
				break;
			default:
				break;
			}
		
	}


}
