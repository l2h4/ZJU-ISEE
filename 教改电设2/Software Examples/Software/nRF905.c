/*--------------------------------------------------------------------------------------
      ####            #####       ##        ##     ###      ############################  
  ############    ############    ####    #####   #####     ############################                      
 #####     ####   ####     ####   ####    ####   #######         ####                                        
 ####      ####   ####     ####    ####  ####    #######         ####                      
 ####      ####   ####     ####    ####  ####   #########        ####      ############# 
 ####      ####   ####     ####     ########    #### ####        ####      #############          
 ####      ####   ####     ####     ########   ####   ####       ####      ####                   
 ####      ####   ####     ####      ######    ####   ####       ####      ####                            
 ####      ####    ##########         ####    ####     ####      ####        ########### 
  ##        ##         ###             ##      ##       ###       ##            ########
  
				文件:	nRF905.c
				描述:	低于1GHz无线数传模块nRF905驱动程序
				编写:	NOVATE copyright 2012
				版本:	2012-04-01 V1.0
--------------------------------------------------------------------------------------*/

#include "STC89.H"
#include "Type.h"
#include "nRF905.h"

#define RF_CH			220								// RF射频通道 0~511	(工作频率 = 422.4MHz + RF_CH × 0.1MHz )
#define RF_DATA_WIDTH	32								// RF数据宽度 1~32byte

xdata uint8 n95_RF_Addr[4]={0xBA,0xBB,0xBC,0xBD};		// TX,RX地址,可自行更改
xdata uint8 n95_RX_Buff[RF_DATA_WIDTH]={1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2};	// 接收数据缓冲区
xdata uint8 n95_TX_Buff[RF_DATA_WIDTH]={1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2};	// 发送数据缓冲区


void delay_1us(void)
{
	uint8 i;
	for (i = 0;i < 10;i++) {}
}

// 函数: n95_Init_IO()
// 描述: 初始化nRF905引脚状态
// 参数: 无
void n95_Init_IO(void)
{
	nPin_CD = 1;										// CD    置低
	nPin_PWR_UP = 1;									// PWR_UP置高,nRF905进入上电模式
	nPin_TRX_CE = 0;									// TRX_CE置低,进入待机和SPI操作模式
	nPin_SCK = 0;            							// SCK   置低
}

// 函数: n1P_SPI_WR_Byte()
// 描述: 通过SPI写一个byte到nRF24L01+,同时从nRF24L01+读取一个byte
// 参数: byte 	待写入字节数据
//		 return 读取到的字节数据
uint8 n95_SPI_WR_Byte(uint8 byte)
{
	uint8 i;
   	for(i=0; i<8; i++){          						// 循环8次
   		nPin_MOSI = (byte & 0x80);  					// 将byte最高位输出到MOSI
//		delay_1us();
   		byte <<= 1;             						// 低一位移位到最高位
//		delay_1us();
   		nPin_SCK = 1;               					// 拉高SCK，nRF24L01从MOSI读入1位数据，同时从MISO输出1位数据
//		delay_1us();
   		byte |= nPin_MISO;       						// 读MISO到byte最低位
//		delay_1us();
   		nPin_SCK = 0;            						// SCK置低
   	}
    return(byte);           							// 返回读出的一字节
}

// 函数: n1P_Init_Dev()
// 描述: 初始化nRF905,并将其转换为接收状态
// 参数: 无
void n95_Init_Dev(uint8 band,uint16 freq,uint8 pwr)
{
	uint8 i=0;

	nPin_PWR_UP = 1;									// PWR_UP置高,nRF905进入上电模式	
	nPin_TRX_CE = 0;									// TRX_CE置低,进入待机和SPI操作模式

	nPin_CSN = 0;										// CSN置低,   进入SPI操作模式
	n95_SPI_WR_Byte(nCMD_W_CONFIG);						// 向nRF905发送"写配置寄存器命令"
	n95_SPI_WR_Byte(freq & 0xFF);						// RF通道bit7:0
	n95_SPI_WR_Byte(nRCD_AUTO_RETRAN_disanble			// 禁用自动重发 
				  | nRCD_RX_RED_PWR_disanble			// 禁用低功耗RX模式
				  | (pwr<<2)							// 输出功率为10dBm
				  | (band<<1)							// 工作频段设置
				  | (freq>>8) );						// RF通道bit8
	n95_SPI_WR_Byte(nRCD_TX_AFW_4byte					// TX地址宽度为4byte
				  | nRCD_RX_AFW_4byte);					// RX地址宽度为4byte
	n95_SPI_WR_Byte(RF_DATA_WIDTH);						// RX数据宽度
	n95_SPI_WR_Byte(RF_DATA_WIDTH);						// TX数据宽度

	for(i=0; i<4; i++){
		n95_SPI_WR_Byte(n95_RF_Addr[i]);				// RX地址 byte0~3
	}

	n95_SPI_WR_Byte(nRCD_CRC_MODE_16crc					// 16bitCRC
				  | nRCD_CRC_EN_enable					// 启用CRC
				  |	nRCD_XOF_16MHz						// 外部晶振频率为16MHz
				  |	nRCD_UP_CLK_EN_disanble				// 禁用外部时钟输出
				  | nRCD_UP_CLK_FREQ_4MHz);				// 时钟输出为4MHz
	nPin_CSN = 1;										// CSN置高,   退出SPI操作模式
	nPin_TX_EN = 0;										// TX_EN置低 ,进入接收模式
	nPin_TRX_CE = 1;									// TRX_CE置高,进入工作模式
}

// 函数: n1P_Turn_TX()
// 描述: 通过nRF905发送数据,数据发送结束后返回接收模式
// 参数: p 发送数据存放地址
void n95_Sendout(uint8 *p)
{
	uint8 i=0;
	nPin_PWR_UP = 1;									// PWR_UP置高,nRF905进入上电模式
	nPin_TRX_CE = 0;									// TRX_CE置低,进入待机和SPI操作模式
	nPin_TX_EN = 1;										// TX_EN置高 ,进入发送模式

	nPin_CSN = 0;										// CSN置低,   进入SPI操作模式
	n95_SPI_WR_Byte(nCMD_W_TX_ADDRESS);					// 向nRF905写入"写TX地址"指令
	for(i=0; i<4; i++){
		n95_SPI_WR_Byte(n95_RF_Addr[i]);				// 写入TX地址 byte0~3,注意此处应与"nRCD_TX_AFW"的配置一致
	}
	nPin_CSN = 1;										// CSN置高,   退出SPI操作模式

	nPin_CSN = 0;										// CSN置低,   进入SPI操作模式
	n95_SPI_WR_Byte(nCMD_W_TX_PAYLOAD);					// 向nRF905写入"写TX数据"指令
	for(i=0; i<RF_DATA_WIDTH; i++){
		n95_SPI_WR_Byte(p[i]);							// 写入待发送数据
	}
	nPin_CSN = 1;										// CSN置高,   退出SPI操作模式

	nPin_TRX_CE = 1;									// TRX_CE置高,进入发送模式
	while(nPin_DR == 0);								// 等待DR置高,发送完成
	nPin_TX_EN = 0;										// TX_EN置低 ,进入接收模式
}

// 函数: n1P_Check_DR()
// 描述: 检查nRF905是否接收到数据,如接收到数据将数据存入接收缓冲区,并返回成功标志
// 参数: p		接收数据存放地址
//		 return 接收成功标志,为1时表明数据接收成功
uint8 n95_Check_DR(uint8 *p)
{	uint8 i=0;

	if(nPin_DR == 1){
		nPin_TRX_CE = 0;								// TRX_CE置低,进入待机模式
		nPin_CSN = 0;									// CSN置低,   进入SPI操作模式

		n95_SPI_WR_Byte(nCMD_R_RX_PAYLOAD);				// 向nRF905写入"读取RXFIFO"指令

		for(i=0; i<RF_DATA_WIDTH; i++){
			p[i] = 	n95_SPI_WR_Byte(0);					// 读取接收数据
		}

		nPin_CSN = 1;									// CSN置高,   退出SPI操作模式
		nPin_TRX_CE = 1;								// TRX_CE置高,进入工作模式
		return(1);										// 返回接收成功标志
	}
	return(0);											// 返回未接收到数据标志
}
