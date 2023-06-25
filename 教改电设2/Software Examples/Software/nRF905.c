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
  
				�ļ�:	nRF905.c
				����:	����1GHz��������ģ��nRF905��������
				��д:	NOVATE copyright 2012
				�汾:	2012-04-01 V1.0
--------------------------------------------------------------------------------------*/

#include "STC89.H"
#include "Type.h"
#include "nRF905.h"

#define RF_CH			220								// RF��Ƶͨ�� 0~511	(����Ƶ�� = 422.4MHz + RF_CH �� 0.1MHz )
#define RF_DATA_WIDTH	32								// RF���ݿ�� 1~32byte

xdata uint8 n95_RF_Addr[4]={0xBA,0xBB,0xBC,0xBD};		// TX,RX��ַ,�����и���
xdata uint8 n95_RX_Buff[RF_DATA_WIDTH]={1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2};	// �������ݻ�����
xdata uint8 n95_TX_Buff[RF_DATA_WIDTH]={1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2};	// �������ݻ�����


void delay_1us(void)
{
	uint8 i;
	for (i = 0;i < 10;i++) {}
}

// ����: n95_Init_IO()
// ����: ��ʼ��nRF905����״̬
// ����: ��
void n95_Init_IO(void)
{
	nPin_CD = 1;										// CD    �õ�
	nPin_PWR_UP = 1;									// PWR_UP�ø�,nRF905�����ϵ�ģʽ
	nPin_TRX_CE = 0;									// TRX_CE�õ�,���������SPI����ģʽ
	nPin_SCK = 0;            							// SCK   �õ�
}

// ����: n1P_SPI_WR_Byte()
// ����: ͨ��SPIдһ��byte��nRF24L01+,ͬʱ��nRF24L01+��ȡһ��byte
// ����: byte 	��д���ֽ�����
//		 return ��ȡ�����ֽ�����
uint8 n95_SPI_WR_Byte(uint8 byte)
{
	uint8 i;
   	for(i=0; i<8; i++){          						// ѭ��8��
   		nPin_MOSI = (byte & 0x80);  					// ��byte���λ�����MOSI
//		delay_1us();
   		byte <<= 1;             						// ��һλ��λ�����λ
//		delay_1us();
   		nPin_SCK = 1;               					// ����SCK��nRF24L01��MOSI����1λ���ݣ�ͬʱ��MISO���1λ����
//		delay_1us();
   		byte |= nPin_MISO;       						// ��MISO��byte���λ
//		delay_1us();
   		nPin_SCK = 0;            						// SCK�õ�
   	}
    return(byte);           							// ���ض�����һ�ֽ�
}

// ����: n1P_Init_Dev()
// ����: ��ʼ��nRF905,������ת��Ϊ����״̬
// ����: ��
void n95_Init_Dev(uint8 band,uint16 freq,uint8 pwr)
{
	uint8 i=0;

	nPin_PWR_UP = 1;									// PWR_UP�ø�,nRF905�����ϵ�ģʽ	
	nPin_TRX_CE = 0;									// TRX_CE�õ�,���������SPI����ģʽ

	nPin_CSN = 0;										// CSN�õ�,   ����SPI����ģʽ
	n95_SPI_WR_Byte(nCMD_W_CONFIG);						// ��nRF905����"д���üĴ�������"
	n95_SPI_WR_Byte(freq & 0xFF);						// RFͨ��bit7:0
	n95_SPI_WR_Byte(nRCD_AUTO_RETRAN_disanble			// �����Զ��ط� 
				  | nRCD_RX_RED_PWR_disanble			// ���õ͹���RXģʽ
				  | (pwr<<2)							// �������Ϊ10dBm
				  | (band<<1)							// ����Ƶ������
				  | (freq>>8) );						// RFͨ��bit8
	n95_SPI_WR_Byte(nRCD_TX_AFW_4byte					// TX��ַ���Ϊ4byte
				  | nRCD_RX_AFW_4byte);					// RX��ַ���Ϊ4byte
	n95_SPI_WR_Byte(RF_DATA_WIDTH);						// RX���ݿ��
	n95_SPI_WR_Byte(RF_DATA_WIDTH);						// TX���ݿ��

	for(i=0; i<4; i++){
		n95_SPI_WR_Byte(n95_RF_Addr[i]);				// RX��ַ byte0~3
	}

	n95_SPI_WR_Byte(nRCD_CRC_MODE_16crc					// 16bitCRC
				  | nRCD_CRC_EN_enable					// ����CRC
				  |	nRCD_XOF_16MHz						// �ⲿ����Ƶ��Ϊ16MHz
				  |	nRCD_UP_CLK_EN_disanble				// �����ⲿʱ�����
				  | nRCD_UP_CLK_FREQ_4MHz);				// ʱ�����Ϊ4MHz
	nPin_CSN = 1;										// CSN�ø�,   �˳�SPI����ģʽ
	nPin_TX_EN = 0;										// TX_EN�õ� ,�������ģʽ
	nPin_TRX_CE = 1;									// TRX_CE�ø�,���빤��ģʽ
}

// ����: n1P_Turn_TX()
// ����: ͨ��nRF905��������,���ݷ��ͽ����󷵻ؽ���ģʽ
// ����: p �������ݴ�ŵ�ַ
void n95_Sendout(uint8 *p)
{
	uint8 i=0;
	nPin_PWR_UP = 1;									// PWR_UP�ø�,nRF905�����ϵ�ģʽ
	nPin_TRX_CE = 0;									// TRX_CE�õ�,���������SPI����ģʽ
	nPin_TX_EN = 1;										// TX_EN�ø� ,���뷢��ģʽ

	nPin_CSN = 0;										// CSN�õ�,   ����SPI����ģʽ
	n95_SPI_WR_Byte(nCMD_W_TX_ADDRESS);					// ��nRF905д��"дTX��ַ"ָ��
	for(i=0; i<4; i++){
		n95_SPI_WR_Byte(n95_RF_Addr[i]);				// д��TX��ַ byte0~3,ע��˴�Ӧ��"nRCD_TX_AFW"������һ��
	}
	nPin_CSN = 1;										// CSN�ø�,   �˳�SPI����ģʽ

	nPin_CSN = 0;										// CSN�õ�,   ����SPI����ģʽ
	n95_SPI_WR_Byte(nCMD_W_TX_PAYLOAD);					// ��nRF905д��"дTX����"ָ��
	for(i=0; i<RF_DATA_WIDTH; i++){
		n95_SPI_WR_Byte(p[i]);							// д�����������
	}
	nPin_CSN = 1;										// CSN�ø�,   �˳�SPI����ģʽ

	nPin_TRX_CE = 1;									// TRX_CE�ø�,���뷢��ģʽ
	while(nPin_DR == 0);								// �ȴ�DR�ø�,�������
	nPin_TX_EN = 0;										// TX_EN�õ� ,�������ģʽ
}

// ����: n1P_Check_DR()
// ����: ���nRF905�Ƿ���յ�����,����յ����ݽ����ݴ�����ջ�����,�����سɹ���־
// ����: p		�������ݴ�ŵ�ַ
//		 return ���ճɹ���־,Ϊ1ʱ�������ݽ��ճɹ�
uint8 n95_Check_DR(uint8 *p)
{	uint8 i=0;

	if(nPin_DR == 1){
		nPin_TRX_CE = 0;								// TRX_CE�õ�,�������ģʽ
		nPin_CSN = 0;									// CSN�õ�,   ����SPI����ģʽ

		n95_SPI_WR_Byte(nCMD_R_RX_PAYLOAD);				// ��nRF905д��"��ȡRXFIFO"ָ��

		for(i=0; i<RF_DATA_WIDTH; i++){
			p[i] = 	n95_SPI_WR_Byte(0);					// ��ȡ��������
		}

		nPin_CSN = 1;									// CSN�ø�,   �˳�SPI����ģʽ
		nPin_TRX_CE = 1;								// TRX_CE�ø�,���빤��ģʽ
		return(1);										// ���ؽ��ճɹ���־
	}
	return(0);											// ����δ���յ����ݱ�־
}
