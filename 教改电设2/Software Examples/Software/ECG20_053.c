/////////////////////////////////////
//  Generated Initialization File  //
/////////////////////////////////////
/*****************************************************************
版本日志：
V05:
1、实现SPI配置，实现SPI的连续输出（中断方式）；V051
2、改为查询方式，写入与读出共用一个函数；V052
3、对nRF905进行设置，并通过Uart输出其状态：V053

V04:
1、P1.1输入的电压经过ADC后，以115200bps速率通过Uart0发送；
2、ADC以Vcc为参考电压，通过AD0BUSY启动

V03:
1、串行通信，速率：115200bps；8bit数据，1停止位，无奇偶校验；
2、每0.5秒钟发送一次数据；
3、编写发送字符串函数和发送数据函数；V031

V02:
1、取键值
2、Key1-4，分别控制Led1-4；

V01：
1、设置定时器中断
2、利用定时器实现流水灯

V00：
1、输入输出的设置
2、流水灯程序
*/

#include "compiler_defs.h"
#include "C8051F340_defs.h"
#include <stdio.h>				//标准输入输出库
#include "nRF905.h"

//变量类型标识的宏定义
#define Uchar unsigned char
#define Uint unsigned int
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long

#define SYSCLK       12000000          // SYSCLK frequency in Hz
#define	XFCN	6		//3		//5

#define SPI_CLOCK          250000      // Maximum SPI clock
#define  SPI_WRITE         0x04        // Send a byte from the Master to the
                                       // Slave
#define  SPI_READ          0x08        // Send a byte from the Slave to the
                                       // Master
#define  SPI_WRITE_BUFFER  0x10        // Send a series of bytes from the
                                       // Master to the Slave
#define  SPI_READ_BUFFER   0x20        // Send a series of bytes from the Slave
                                       // to the Master
#define  ERROR_OCCURRED    0x40        // Indicator for the Slave to tell the
                                       // Master an error occurred

#define MAX_BUFFER_SIZE 10


#define RF_CH			220								// RF射频通道 0~511	(工作频率 = 422.4MHz + RF_CH × 0.1MHz )
#define RF_DATA_WIDTH	32								// RF数据宽度 1~32byte

xdata uchar n95_RF_Addr[4]={0xBA,0xBB,0xBC,0xBD};		// TX,RX地址,可自行更改
xdata uchar n95_RX_Buff[RF_DATA_WIDTH];	//={1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2};	// 接收数据缓冲区
xdata uchar n95_TX_Buff[RF_DATA_WIDTH];	//={1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2};	// 发送数据缓冲区

xdata uchar  	n95_rxtx = 0;			// 工作模式 rx=0;tx=1;tx_rx=2;
xdata uchar  	n95_band = 0;			// 工作区间 0=433;1=915
xdata uint	 	n95_freq = 4330-4224;   // 工作频率 0~511 (默认433.0MHz)
xdata uchar  	n95_pwr = 3;			// 输出功率	0~3(10,6,-2,-10)

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

//-----------------------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------------------
uchar SPI_Data = 0xA5;
uchar SPI_Data_Array[MAX_BUFFER_SIZE] = {0};
bit Error_Flag = 0;
uchar Command = 0x00;

uint	Timer_Count;	//定时计数器
uchar	Timer_Count_2;	//定时计数器2
uchar	Led_State;		//LED显示状态

uchar	Key_value;		//键值

bit	Key1_press_flag;	//Key1按下标志
bit	Key2_press_flag;	//Key2按下标志
bit	Key3_press_flag;	//Key3按下标志
bit	Key4_press_flag;	//Key4按下标志

bit	Key1_back;			//按键的上一状态
bit	Key2_back;
bit	Key3_back;
bit	Key4_back;

ulong	Temp;
xdata uchar Uart_Send_Buff[32];
uchar Uart_Send_Count;

bdata uchar P4_IN;		//定义位可寻址变量

//接口定义
/*
sbit	Led1 = P4^4;
sbit	Led2 = P4^5;
sbit	Led3 = P4^6;
sbit	Led4 = P4^7;
*/

sbit	Key1 = P4_IN^3;
sbit	Key2 = P4_IN^2;
sbit	Key3 = P4_IN^1;
sbit	Key4 = P4_IN^0;

sbit	Ad_in  = P1^1;

sbit	Tx_en = P2^2;
sbit	Trx_ce = P2^3;
sbit	Pwr_up = P2^4;
sbit	CD_905 = P2^5;
sbit	AM_905 = P2^6;
sbit	DR_905 = P2^7;

bit		timer_flag;


//-----------------------------------------------------------------------------
// PCA0_Init
//-----------------------------------------------------------------------------
// Return Value : None
// Parameters   : None
// This function disables the watchdog timer.
//-----------------------------------------------------------------------------
void PCA0_Init (void)
{
   PCA0MD &= ~0x40;                    // Disable the Watchdog Timer
   PCA0MD = 0x00;
}

//-----------------------------------------------------------------------------
// Port_Init
//-----------------------------------------------------------------------------
// Peripheral specific initialization functions,
// Called from the Init_Device() function
void Port_IO_Init()
{
	P1MDIN    = 0xFC;
    P0MDOUT   = 0xD1;
    P1MDOUT   = 0xF8;
    P2MDOUT   = 0x1F;
    P3MDOUT   = 0xFF;
    P4MDOUT   = 0xF0;
    P0SKIP    = 0x0C;
    XBR0      = 0x03;
    XBR1      = 0x40;

	P4 &= 0x0f;
}

/*----------------------------
Initial Uart
----------------------------*/
void UartInit(void)		//115200bps@12MHz
{
	CKCON |=0X08;		//T1使用系统时钟
//	PCON &= 0x7F;		//波特率不倍速
	SCON0 = 0x10;		//8位数据，可变波特率
//	AUXR |= 0x40;		//定时器1时钟为Fosc，即1T
//	AUXR &= 0xFE;		//串口1选择定制器1位波特率发生器
	TMOD &= 0x0F;		//清定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装载方式
	TL1 = 0xCC;			//设定定时器初值
	TH1 = 0xCC;			//
	ET1 = 0;			//禁止定时器1中断
	TR1 = 1;			//启动定时器1
	ES0 = 0;
}

//-----------------------------------------------------------------------------
// ADC0_Init
//-----------------------------------------------------------------------------
//
// Return Value:  None
// Parameters:    None
//
// Configures ADC0 to make single-ended analog measurements on pin P1.1
//  
//-----------------------------------------------------------------------------

void ADC0_Init (void)
{
   ADC0CN = 0x00;                      // ADC0 disabled, normal tracking, 
                                       // conversion triggered on "ADC0BUSY" set
   REF0CN = 0x08;                      // disable on-chip VREF and buffer
   AMX0P = 0x13;                       // ADC0 positive input = P1.1
   AMX0N = 0x1F;                       // ADC0 negative input = GND
                                       // i.e., single ended mode
   ADC0CF = ((SYSCLK/3000000)-1)<<3;   // set SAR clock to 3MHz
   ADC0CF &= ~0x04;                    // right-justify results 
   EIE1 |= 0x08;                       // enable ADC0 conversion complete int.
   AD0EN = 1;                          // enable ADC0
}


//-----------------------------------------------------------------------------
// Timer0_Init
//-----------------------------------------------------------------------------
// Return Value : None
// Parameters   : None
// T0设为16bit定时器，溢出时间1ms
//
//-----------------------------------------------------------------------------
void Timer0_Init (void)
{
//   OSCICN = 0x83;                      // Set the internal oscillator to
                                       // 12 MHz
   //T0,模式设定
   TR0 = 0; 	   //停止计数
   ET0 = 1; 	   //允许中断
   PT0 = 1; 	   //高优先级中断
   TMOD = 0x01;    //#00000,0001,16位定时模式
   
   TH0 = 0;
   TL0 = 0;
   TR0 = 1; 	   //开始运行
}

//-----------------------------------------------------------------------------
// SPI0_Init
//-----------------------------------------------------------------------------
// Return Value : None
// Parameters   : None
// Configures SPI0 to use 4-wire Single Master mode. The SPI timing is
// configured for Mode 0,0 (data centered on first edge of clock phase and
// SCK line low in idle state).
//-----------------------------------------------------------------------------
void SPI0_Init()
{
   SPI0CFG   = 0x40;                   // Enable the SPI as a Master
                                       // CKPHA = '0', CKPOL = '0'
   SPI0CN    = 0x0D;                   // 4-wire Single Master, SPI enabled
   // SPI clock frequency equation from the datasheet
   SPI0CKR   = (SYSCLK/(2*SPI_CLOCK))-1;
   ESPI0 = 0;                          // Disable SPI interrupts
}										//采用查询方式？

//-----------------------------------------------------------------------------
// System_Init
//-----------------------------------------------------------------------------
// Initialization function for device,
// Call Init_Device() from your main program
void Init_Device(void)
{
	PCA0_Init();			//disables the watchdog timer
	Port_IO_Init();
	OSCICN = (0x80 | 0x03);	//设置内部时钟
	Timer0_Init();
	ADC0_Init();
	UartInit();				//Uart0 初始化
	SPI0_Init();

    EA = 1;					//开启全局中断允许
}


//-----------------------------------------------------------------------------
/********************延时函数************************/
//-----------------------------------------------------------------------------
//延时y ms
void	Delay(uint y)
{
	uint	x;
	while (y--)
	{
		x = 862;
		while (x--);
	}
}


//-----------------------------------------------------------------------------
/********************* 键盘扫描函数************************/
//-----------------------------------------------------------------------------
void	Key_Scan()
{
	P4_IN = P4;
	
	if (!Key1)			//键扫描1，检测下降沿
	{
		if(Key1_back)
		{
			Key1_press_flag = 1;
		}
	}

	if (!Key2)			//键扫描2
	{
		if(Key2_back)
		{
			Key2_press_flag = 1;
		}
	}

	if (!Key3)			//键扫描3
	{
		if(Key3_back)
		{
			Key3_press_flag = 1;
		}
	}

	if (!Key4)			//键扫描4
	{
		if(Key4_back)
		{
			Key4_press_flag = 1;
		}
	}

	Key1_back = Key1;
	Key2_back = Key2;
	Key3_back = Key3;
	Key4_back = Key4;
}

//-----------------------------------------------------------------------------
/********************* Timer0中断函数************************/
//-----------------------------------------------------------------------------
void timer0_int (void) interrupt 1
{
	TH0 = 0xfc;
	TL0 = 0x18;			//1ms定时中断

	Key_Scan();
//	Run_treat();

	++Timer_Count;
	if (Timer_Count > 500)
	{
		Timer_Count = 0;
		timer_flag = 1;
//		LED1_INVERT;
	}

}

//-----------------------------------------------------------------------------
// ADC0_ISR
//-----------------------------------------------------------------------------
// 
// This ISR averages 2048 samples then prints the result to the terminal.  The 
// ISR is called after each ADC conversion which is triggered by Timer2.
//
//-----------------------------------------------------------------------------
void ADC0_ISR (void) interrupt 10
{
   unsigned long result=0;
   unsigned long mV;           // Measured voltage in mV

   AD0INT = 0;                 // Clear ADC0 conv. complete flag
	result = ADC0;
	// The 10-bit ADC value is averaged across 2048 measurements.  
	// The measured voltage applied to P1.1 is then:
	//                           Vref (mV)
	//   measurement (mV) =   --------------- * result (bits) 
	//                       (2^10)-1 (bits)
	Temp =  result * 3300 / 1023;   
	//   printf("P1.1 voltage: %ld mV\n",mV);
}


//-----------------------------------------------------------------------------
// SPI_ISR
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void SPI_ISR (void) interrupt 6
{
   if (SPIF)
   {
//   		SPIF = 0;
//	  NSSMD0 = 1;			   // Release the slave (not expecting
//							   // data back)
   	}

}

//-----------------------------------------------------------------------------
/******************** 按键处理 **************************/
//-----------------------------------------------------------------------------
void	Key_treat()
{
	if (Key1_press_flag)
	{
		LED1_INVERT;
		Key1_press_flag = 0;
	}

	if (Key2_press_flag)
	{
		LED2_INVERT;
		Key2_press_flag = 0;
	}

	if (Key3_press_flag)
	{
		LED3_INVERT;
		Key3_press_flag = 0;
	}

	if (Key4_press_flag)
	{
		LED4_INVERT;
		Key4_press_flag = 0;
	}

}

//-----------------------------------------------------------------------------
void SendUchar(char Data)
{
	Uart_Send_Buff[0] = (Data / 10 % 10) +0x30;
	Uart_Send_Buff[1] = (Data %10) +0x30;
//	Uart1_tx_len = 2;
	for (Uart_Send_Count=0;Uart_Send_Count<2;Uart_Send_Count++)
	{
	SBUF0 = Uart_Send_Buff[Uart_Send_Count];
	while(TI0 ==0){}
	TI0 = 0;
	}
}


void SendUint(uint Data)
{
	Uart_Send_Buff[0] = (Data / 1000 % 10) +0x30;
	Uart_Send_Buff[1] = (Data / 100 % 10) +0x30;
	Uart_Send_Buff[2] = (Data / 10 % 10) +0x30;
	Uart_Send_Buff[3] = (Data %10) +0x30;
//	Uart1_tx_len = 4;
	for (Uart_Send_Count=0;Uart_Send_Count<4;Uart_Send_Count++)
	{
	SBUF0 = Uart_Send_Buff[Uart_Send_Count];
	while(TI0 ==0){}
	TI0 = 0;
	}
}

/*----------------------------
Send a string to UART
Input: s (address of string)
Output:None
----------------------------*/
void SendString(char *s)
{
	uchar	i=0;
	while (*s)
		{
		Uart_Send_Buff[i++] = *s++;
		}
//	Uart1_tx_len = i;
	for (Uart_Send_Count=0;Uart_Send_Count<i;Uart_Send_Count++)
	{
	SBUF0 = Uart_Send_Buff[Uart_Send_Count];
	while(TI0 ==0){}
	TI0 = 0;
	}
}

//-----------------------------------------------------------------------------
// SPI_Byte_Write_Read
//-----------------------------------------------------------------------------
// Return Value : SPI0DAT
// Parameters   : Send_Byte
//-----------------------------------------------------------------------------
uchar SPI_Byte_Write_Read (uchar Send_Byte)
{
	while (!NSSMD0);			// Wait until the SPI is free, in case
								// it's already busy
	NSSMD0 = 0;
	SPI0DAT = Send_Byte;

	while(!SPIF);
	SPIF = 0;
	NSSMD0 = 1;					// Release the slave (not expecting
	return (SPI0DAT);			//readout
}


//-----------------------------------------------------------------------------
// 函数: n95_Init_IO()
//-----------------------------------------------------------------------------
// 描述: 初始化nRF905引脚状态
// 参数: 无
void n95_Init_IO(void)
{
	nPin_CD = 1;					// CD    置高
	nPin_PWR_UP = 1;				// PWR_UP置高,nRF905进入上电模式
	nPin_TRX_CE = 0;				// TRX_CE置低,进入待机和SPI操作模式
//	nPin_SCK = 0;            		// SCK   置低
}

//-----------------------------------------------------------------------------
// 函数: n1P_Init_Dev()
//-----------------------------------------------------------------------------
// 描述: 初始化nRF905,并将其转换为接收状态
// 参数: 无
void n95_Init_Dev(uchar band,uint freq,uchar pwr)
{
	uchar i = 0;
	
	nPin_PWR_UP = 1;									// PWR_UP置高,nRF905进入上电模式	
	nPin_TRX_CE = 0;									// TRX_CE置低,进入待机和SPI操作模式
	nPin_CSN = 0;										// CSN置低,   进入SPI操作模式
	SPI_Byte_Write_Read(nCMD_W_CONFIG);					// 向nRF905发送"写配置寄存器命令"
	SPI_Byte_Write_Read(freq & 0xFF);					// RF通道bit7:0
	SPI_Byte_Write_Read(nRCD_AUTO_RETRAN_disanble		// 禁用自动重发 
				  | nRCD_RX_RED_PWR_disanble			// 禁用低功耗RX模式
				  | (pwr<<2)							// 输出功率为10dBm
				  | (band<<1)							// 工作频段设置
				  | (freq>>8) );						// RF通道bit8
	SPI_Byte_Write_Read(nRCD_TX_AFW_4byte				// TX地址宽度为4byte
				  | nRCD_RX_AFW_4byte);					// RX地址宽度为4byte
	SPI_Byte_Write_Read(RF_DATA_WIDTH);					// RX数据宽度
	SPI_Byte_Write_Read(RF_DATA_WIDTH);					// TX数据宽度

	for(i=0; i<4; i++){
		SPI_Byte_Write_Read(n95_RF_Addr[i]);			// RX地址 byte0~3
	}

	SPI_Byte_Write_Read(nRCD_CRC_MODE_16crc				// 16bitCRC
				  | nRCD_CRC_EN_enable					// 启用CRC
				  |	nRCD_XOF_16MHz						// 外部晶振频率为16MHz
				  |	nRCD_UP_CLK_EN_disanble				// 禁用外部时钟输出
				  | nRCD_UP_CLK_FREQ_4MHz);				// 时钟输出为4MHz
				  
	nPin_CSN = 1;										// CSN置高,   退出SPI操作模式
	nPin_TX_EN = 0;										// TX_EN置低 ,进入接收模式
	nPin_TRX_CE = 1;									// TRX_CE置高,进入工作模式
}

//-----------------------------------------------------------------------------
// 函数: UartSend_RF_Set()
//-----------------------------------------------------------------------------
// 描述: 将nRF905的工作频率,发射功率等信息进行显示
void UartSend_RF_Set(void)
{
	//0123456789012345
	//RF905 422.2MHz ?
	//R000      -10dBm
	
	uint freq=0;
	uchar pwr=0;
	
	SendString("RF905, Freq: ");
	freq = (4224 + n95_freq) * (1 + n95_band);
	SendUint(freq/10);
	SendString(".");
	SendUchar((freq%10)*10);
	SendString("MHz,");

	if(n95_rxtx ==0){
		SendString(" Mod: R ,");}
	else	{
		SendString(" Mod: T ,");}

	// 发射功率转换
	switch(n95_pwr){
		case 0:{	// -10
			SendString("Power:-10dBm\n");
		}break;
		case 1:{	// -2
			SendString("Power: -2dBm\n");
		}break;
		case 2:{	// 6
			SendString("Power:  6dBm\n");
		}break;
		case 3:{	// 10
			SendString("Power: 10dBm\n");
		}break;
	}

}


/********************主函数**************************/
void main(void)
{
	Init_Device();
	n95_Init_IO();
	n95_Init_Dev(n95_band, n95_freq, n95_pwr);
	UartSend_RF_Set();
	
	//测试SPI接口
//	Pwr_up = 1; 	//掉电模式，允许SPI编程
//	Trx_ce = 0;
//	Tx_en = 0;
	
	while(1)
	{

		if (NSSMD0 == 1)
			{
			//SPI_Data = 0x0f;
			SPI_Byte_Write_Read(0xf0);
			}

		Key_treat();
		if (timer_flag)
			{
			AD0BUSY = 1;					//开始ADC转换
			while(AD0BUSY) {}
			//SendString("Voltage:");
			//SendUint(Temp);
			//SendString("mV\n");
//			printf("P1.1 voltage: %ld mV\n",Temp);
			timer_flag =0;
			}


	}
}
