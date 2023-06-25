/*--------------------------------------------------------------------------------------
	�ļ�:	nRF905.h
	����:	����1GHz��������ģ��nRF905��������ͷ�ļ�
	��д:	NOVATE copyright 2011
	�汾:	2011-08-24 V1.0
--------------------------------------------------------------------------------------*/

#ifndef _NRF905_DEF_
#define _NRF905_DEF_

// SPI�ܽŶ���	Define SPI pins
sbit nPin_TX_EN	 = P2^2;	// TX/RXѡ�� (MCU output)
sbit nPin_TRX_CE = P2^3;	// TX/RXʹ�� (MCU output)
sbit nPin_PWR_UP = P2^4;	// оƬ�ϵ�  (MCU output)
sbit nPin_CD	 = P2^5;	// �ز����  (MCU input)
sbit nPin_AM	 = P2^6;	// ��ַƥ��  (MCU input)
sbit nPin_DR	 = P2^7;	// TX/RX��� (MCU input)
sbit nPin_MISO	 = P0^1;	// �������  (MCU input)
sbit nPin_MOSI	 = P0^6;	// ��������  (MCU output)
sbit nPin_SCK	 = P0^0;	// ʱ������  (MCU output)
//sbit nPin_CSN	 = P0^7;	// оƬѡ��  (MCU output)
#define nPin_CSN NSSMD0		//����Ƭѡ�ź�


// �û����� 
//extern xdata uchar n95_RF_Addr[];		// TX,RX��ַ,�����и���
//extern xdata uchar n95_RX_Buff[];		// �������ݻ�����
//extern xdata uchar n95_TX_Buff[];		// �������ݻ�����
// �û�����
//void n95_Init_IO(void);
//void n95_Init_Dev(uchar,uint,uchar);
//void n95_Sendout(uchar*);
//uchar n95_Check_DR(uchar*);

// SPI������ SPI Commands
#define nCMD_W_CONFIG			0x00	// д���üĴ���
#define nCMD_R_CONFIG 			0x10	// д���üĴ���
#define nCMD_W_TX_PAYLOAD 		0x20	// дTXFIFO
#define nCMD_R_TX_PAYLOAD 		0x21	// ��TXFIFO
#define nCMD_W_TX_ADDRESS 		0x22	// дTX��ַ
#define nCMD_R_TX_ADDRESS 		0x23	// ��TX��ַ
#define nCMD_R_RX_PAYLOAD 		0x24	// ��RXFIFO
#define nCMD_CHANNEL_CONFIG 	0x80	// Ƶ������

// �Ĵ�������
// byte1
#define nRCD_AUTO_RETRAN_disanble			0<<5	// �����Զ��ط�
#define nRCD_AUTO_RETRAN_enanble			1<<5	// �����Զ��ط�

#define nRCD_RX_RED_PWR_disanble			0<<4	// ���õ͹���RXģʽ
#define nRCD_RX_RED_PWR_enanble				1<<4	// ���õ͹���RXģʽ

#define nRCD_PA_PWR_n10dBm			(0<<3)|(0<<2)	// �������Ϊ-10dBm
#define nRCD_PA_PWR_n2dBm			(0<<3)|(1<<2)	// �������Ϊ-2dBm
#define nRCD_PA_PWR_6dBm			(1<<3)|(0<<2)	// �������Ϊ6dBm
#define nRCD_PA_PWR_10dBm			(1<<3)|(1<<2)	// �������Ϊ10dBm

#define nRCD_HFREQ_PLL_433MHz				0<<1	// ������433Ƶ��
#define nRCD_HFREQ_PLL_868_915MHz			1<<1	// ������868,915Ƶ��

// byte2
#define nRCD_TX_AFW_1byte	 (0<<6)|(0<<5)|(1<<4)	// TX��ַ���Ϊ1byte
#define nRCD_TX_AFW_2byte	 (0<<6)|(1<<5)|(0<<4)	// TX��ַ���Ϊ2byte
#define nRCD_TX_AFW_3byte	 (0<<6)|(1<<5)|(1<<4)	// TX��ַ���Ϊ3byte
#define nRCD_TX_AFW_4byte	 (1<<6)|(0<<5)|(0<<4)	// TX��ַ���Ϊ4byte

#define nRCD_RX_AFW_1byte	 	  (0<<2)|(0<<1)|1	// RX��ַ���Ϊ1byte
#define nRCD_RX_AFW_2byte	 	  (0<<2)|(1<<1)|0	// RX��ַ���Ϊ2byte
#define nRCD_RX_AFW_3byte	 	  (0<<2)|(1<<1)|1	// RX��ַ���Ϊ3byte
#define nRCD_RX_AFW_4byte	 	  (1<<2)|(0<<1)|0	// RX��ַ���Ϊ4byte

// byte9
#define nRCD_CRC_MODE_8crc					0<<7	// 8bitCRC
#define nRCD_CRC_MODE_16crc					1<<7	// 16bitCRC

#define nRCD_CRC_EN_disable					0<<6	// ����CRC
#define nRCD_CRC_EN_enable					1<<6	// ����CRC

#define nRCD_XOF_4MHz	 	 (0<<5)|(0<<4)|(0<<3)	// �ⲿ����Ƶ��Ϊ4MHz
#define nRCD_XOF_8MHz	 	 (0<<5)|(0<<4)|(1<<3)	// �ⲿ����Ƶ��Ϊ8MHz
#define nRCD_XOF_12MHz	 	 (0<<5)|(1<<4)|(0<<3)	// �ⲿ����Ƶ��Ϊ12MHz
#define nRCD_XOF_16MHz	 	 (0<<5)|(1<<4)|(1<<3)	// �ⲿ����Ƶ��Ϊ16MHz
#define nRCD_XOF_20MHz	 	 (1<<5)|(0<<4)|(0<<3)	// �ⲿ����Ƶ��Ϊ20MHz

#define nRCD_UP_CLK_EN_disanble				0<<2	// �����ⲿʱ�����
#define nRCD_UP_CLK_EN_enable				1<<2	// �����ⲿʱ�����

#define nRCD_UP_CLK_FREQ_4MHz			(0<<1)|0	// ʱ�����Ϊ4MHz
#define nRCD_UP_CLK_FREQ_2MHz			(0<<1)|1	// ʱ�����Ϊ2MHz
#define nRCD_UP_CLK_FREQ_1MHz			(1<<1)|0	// ʱ�����Ϊ1MHz
#define nRCD_UP_CLK_FREQ_500kHz			(1<<1)|1	// ʱ�����Ϊ500kHz

#endif
