/*------------------------------------------------*/
/* --- �꾧�Ƽ� STCMCU ---------------------------*/
/* --- Mobile: (86)13922805190 -------------------*/
/* --- Fax: 86-755-82944243 ----------------------*/
/* --- Tel: 86-755-82948412 ----------------------*/
/* --- Web: www.STCMCU.com -----------------------*/
/* ������: STC12C5AxxX   STC12LE5AxxX ------------*/
/* ------- STC12C5AxxCPP STC12LE5AxxCPP ----------*/
/* ------- STC12C5AxxAD  STC12LE5AxxAD  ----------*/
/* ------- STC12C5AxxS2  STC12LE5AxxS2  ----------*/
/* ------- IAP12C5Axx    IAP12LE5Axx    ----------*/
/* ------- IAP12C5AxxCPP IAP12LE5AxxCPP ----------*/
/* ------- IAP12C5AxxAD  IAP12LE5AxxAD  ----------*/
/* ------- IAP12C5AxxS2  IAP12LE5AxxS2  ----------*/
/*------------------------------------------------*/

#ifndef __STC12C5A_H__
#define __STC12C5A_H__

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sfr  PSW        =   0xd0;       //����״̬��            Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                CY      AC      F0      RS1     RS0     OV      F1      P
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

sbit CY         =   PSW^7;      //��λ��־
sbit AC         =   PSW^6;      //������λ��־
sbit F0         =   PSW^5;      //�û���־
sbit RS1        =   PSW^4;      //�Ĵ�����ѡ��λ1
sbit RS0        =   PSW^3;      //�Ĵ�����ѡ��λ0
sbit OV         =   PSW^2;      //�����־
sbit P          =   PSW^0;      //ACC��żУ��λ

/////////////////////////////////

sfr  ACC        =   0xe0;       //�ۼ���                Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

sbit ACC7       =   ACC^7;      //�ۼ�����7λ
sbit ACC6       =   ACC^6;      //�ۼ�����6λ
sbit ACC5       =   ACC^5;      //�ۼ�����5λ
sbit ACC4       =   ACC^4;      //�ۼ�����4λ
sbit ACC3       =   ACC^3;      //�ۼ�����3λ
sbit ACC2       =   ACC^2;      //�ۼ�����2λ
sbit ACC1       =   ACC^1;      //�ۼ�����1λ
sbit ACC0       =   ACC^0;      //�ۼ�����0λ

/////////////////////////////////

sfr  B          =   0xf0;       //B�Ĵ���               Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  SP         =   0x81;       //��ջָ��              Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0111      0       0       0       0       0       1       1       1

/////////////////////////////////

sfr  DPL        =   0x82;       //����ָ����ֽ�        Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  DPH        =   0x83;       //����ָ����ֽ�        Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sfr  PCON       =   0x87;       //��Դ���ƼĴ���        Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                SMOD    SMOD0   LVDF    POF     GF1     GF0     PD      IDL
                                //��ʼֵ=0011,0000      0       0       1       1       0       0       0       0

#define SMOD        0x80        //���ڲ����ʱ���λ,��1��ʹ�����ʿ�1��
#define SMOD0       0x40        //FE/SM0ѡ��λ,0:SCON.7ΪSM0 1:SCON.7ΪFE
#define LVDF        0x20        //��ѹ����ж�����λ,��Ӳ����1,���������0
#define POF         0x10        //�ϵ縴λ��־λ,�ϵ�ʱ��Ӳ����1,���������0
#define GF1         0x08        //ͨ�ñ�־λ1
#define GF0         0x04        //ͨ�ñ�־λ0
#define PD          0x02        //�������λ,д1����ʹMCU����PowerDownģʽ
#define IDL         0x01        //���п���λ,д1����ʹMCU����Idleģʽ

/////////////////////////////////

sfr  WAKE_CLKO  =   0x8f;       //���绽��/ʱ��������� Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����          PCAWAKEUP RXDPINIE T1PINIE T0PINIE LVD_WAKEUP BRTCLKO T1VLKO  T0CLKO
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

#define PCAWAKEUP   0x80        //����PCA��������/�½����жϻ��ѵ���MCU
#define RXD_PIN_IE  0x40        //����RXD(P3.0)�½�����λRI�ж�ʱ���ѵ���MCU(�������Ӧ�ж�)
#define T1_PIN_IE   0x20        //����T1(P3.5)�½�����λT1�ж�ʱ���ѵ���MCU(�������Ӧ�ж�)
#define T0_PIN_IE   0x10        //����T0(P3.4)�½�����λT0�ж�ʱ���ѵ���MCU(�������Ӧ�ж�)
#define LVD_WAKEUP  0x08        //����LVD(P4.6)�ĵ�ѹ����жϻ��ѵ���MCU(�������Ӧ�ж�)
#define BRTCLKOEN   0x04        //��P1.0�ŵ�BRTʱ���������,�����ʱ��Ƶ��Ϊ1/2����BRT�����
#define T1CLKOEN    0x02        //��P3.5�ŵĶ�ʱ��1ʱ���������,�����ʱ��Ƶ��Ϊ1/2����T1�����
#define T0CLKOEN    0x01        //��P3.4�ŵĶ�ʱ��0ʱ���������,�����ʱ��Ƶ��Ϊ1/2����T0�����

/////////////////////////////////

sfr  CLK_DIV    =   0x97;       //ʱ�ӷ�Ƶ�Ĵ���        Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                -       -       -       -       -       CLKS2   CLKS1   CLKS0
                                //��ʼֵ=xxxx,x000      x       x       x       x       x       0       0       0

#define FOSCD1      0x00        //ϵͳʱ��ΪFosc
#define FOSCD2      0x01        //ϵͳʱ��ΪFosc/2
#define FOSCD4      0x02        //ϵͳʱ��ΪFosc/4
#define FOSCD8      0x03        //ϵͳʱ��ΪFosc/8
#define FOSCD16     0x04        //ϵͳʱ��ΪFosc/16
#define FOSCD32     0x05        //ϵͳʱ��ΪFosc/32
#define FOSCD64     0x06        //ϵͳʱ��ΪFosc/64
#define FOSCD128    0x07        //ϵͳʱ��ΪFosc/128

/////////////////////////////////

sfr  BUS_SPEED  =   0xa1;       //���������ٶȿ�����    Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                -       -       ALES1   ALES0   -       RWS2    RWS1    RWS0
                                //��ʼֵ=xx10,x011      x       x       1       0       x       0       1       1

#define ALES1       0x20        //P0��ַ����ʱ��ͱ���ʱ�䵽ALE�źŵ��½��ص�ʱ����
#define ALES0       0x10        //ALES1/ALES0=0/0:1��ʱ�� 0/1:2��ʱ�� 1/0:3��ʱ�� 1/1:4��ʱ��

#define RWS2        0x04        //MOVXָ���ʱ����
#define RWS1        0x02        //RWS2/RWS1/RWS0=000:1��ʱ�� 001:2��ʱ�� 010:3��ʱ�� 011:4��ʱ��
#define RWS0        0x01        //               100:5��ʱ�� 101:6��ʱ�� 110:7��ʱ�� 111:8��ʱ��

/////////////////////////////////

sfr  WDT_CONTR  =   0xc1;       //���Ź���ʱ��������    Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����             WDT_FLAG   -       EN_WDT  CLR_WDT IDL_WDT PS2     PS1     PS0
                                //��ʼֵ=0x00,0000      0       x       0       0       0       0       0       0

#define WDT_FLAG    0x80        //���Ź���λ��־,�����Ź����������λ��,Ӳ���Զ���1,��Ҫ�������0
#define EN_WDT      0x20        //���ʹ�ܿ��Ź�,�򿪺���������ķ�ʽ�ر�
#define CLR_WDT     0x10        //�忴�Ź���ʱ��
#define IDLE_WDT    0x08        //IDLEģʽ��,���Ź���ʱ���Ƿ������ʱ

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sfr  AUXR       =   0x8e;       //�����Ĵ���            Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                T0x12   T1x12   UM0x6   BRTR    S2SMOD  BRTx12  EXTRAM  S1BRS
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

#define T0x12       0x80        //��ʱ��0ʱ�ӿ���,0:Fosc/12(��ͳ��12��Ƶ) 1:Fosc/1(1Tģʽ,����Ƶ,��12���ڴ�ͳ�ٶ�)
#define T1x12       0x40        //��ʱ��1ʱ�ӿ���,0:Fosc/12(��ͳ��12��Ƶ) 1:Fosc/1(1Tģʽ,����Ƶ,��12���ڴ�ͳ�ٶ�)
#define UR0x6       0x20        //����ģʽ0��ʱ�ӿ���,0:Fosc/12(��ͳ��12��Ƶ) 1:Fosc/2(2��Ƶ,,��6���ڴ�ͳ�ٶ�)
#define BRTR        0x10        //���������ʷ�������������λ,1:�������������ʷ����� 0:ֹͣ���������ʷ�����
#define S2SMOD      0x08        //����2�����ʱ���λ,��1��ʹ����2�Ĳ����ʿ�1��
#define BRTx12      0x04        //���������ʷ�����ʱ�ӿ���,0:Fosc/12(��ͳ��12��Ƶ) 1:Fosc/1(1Tģʽ,����Ƶ,��12���ڴ�ͳ�ٶ�)
#define EXTRAM      0x02        //�ڲ���չRAM����λ,0:�ڲ���չRAM��Ч 1:�����ڲ���չRAM
#define S1BRS       0x01        //����1�Ĳ����ʷ�����ѡ��λ,0:��ʱ��1 1:���������ʷ�����(ע�⴮��2ֻ�ܹ�ʹ�ö��������ʷ�����)

/////////////////////////////////

sfr  AUXR1      =   0xa2;       //�����Ĵ���1           Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                -       PCA_P4  SPI_P4  S2_P4   GF2     ADRJ    -       DPS
                                //��ʼֵ=x000,00x0      x       0       0       0       0       0       x       0

#define PCA_P4      0x40        //��PCA��ӳ�䵽P4��,0:ECI(P1.2)CEX0(P1.3)CEX1(P1.4) 1:ECI(P4.1)CEX0(P4.2)CEX1(P4.3)
#define SPI_P4      0x20        //��SPI��ӳ�䵽P4��,0:SCLK(P1.7)MISO(P1.6)MOSI(P1.5)SS(P1.4) 1:SCLK(P4.3)MISO(P4.2)MOSI(P4.1)SS(P4.0)
#define S2_P4       0x10        //������2ӳ�䵽P4��,0:RXD2(P1.2)TXD2(P1.3) 1:RXD2(P4.2)TXD2(P4.3)
#define GF2         0x08        //ͨ�ñ�־λ2
#define ADRJ        0x04        //ADC�������,0:{ADC_RES[9876,5432],ADC_RESL[----,--10]} 1:{ADC_RES[----,--98],ADC_RESL[7654,3210]}
#define DPS         0x01        //DPTR0/DPTR1ѡ��λ,0:DPTR0 1:DPTR1

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sfr  P0         =   0x80;       //I/O�˿�0              Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                P0.7    P0.6    P0.5    P0.4    P0.3    P0.2    P0.1    P0.0
                                //��ʼֵ=1111,1111      1       1       1       1       1       1       1       1

sbit P07        =   P0^7;       //I/O��P0.7
sbit P06        =   P0^6;       //I/O��P0.6
sbit P05        =   P0^5;       //I/O��P0.5
sbit P04        =   P0^4;       //I/O��P0.4
sbit P03        =   P0^3;       //I/O��P0.3
sbit P02        =   P0^2;       //I/O��P0.2
sbit P01        =   P0^1;       //I/O��P0.1
sbit P00        =   P0^0;       //I/O��P0.0

/////////////////////////////////

sfr  P1         =   0x90;       //I/O�˿�0              Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                P1.7    P1.6    P1.5    P1.4    P1.3    P1.2    P1.1    P1.0
                                //��ʼֵ=1111,1111      1       1       1       1       1       1       1       1

sbit P17        =   P1^7;       //I/O��P1.7
sbit P16        =   P1^6;       //I/O��P1.6
sbit P15        =   P1^5;       //I/O��P1.5
sbit P14        =   P1^4;       //I/O��P1.4
sbit P13        =   P1^3;       //I/O��P1.3
sbit P12        =   P1^2;       //I/O��P1.2
sbit P11        =   P1^1;       //I/O��P1.1
sbit P10        =   P1^0;       //I/O��P1.0

sbit ADCIN7     =   P1^7;       //ADCͨ��7��ģ���ź������
sbit ADCIN6     =   P1^6;       //ADCͨ��6��ģ���ź������
sbit ADCIN5     =   P1^5;       //ADCͨ��5��ģ���ź������
sbit ADCIN4     =   P1^4;       //ADCͨ��4��ģ���ź������
sbit ADCIN3     =   P1^3;       //ADCͨ��3��ģ���ź������
sbit ADCIN2     =   P1^2;       //ADCͨ��2��ģ���ź������
sbit ADCIN1     =   P1^1;       //ADCͨ��1��ģ���ź������
sbit ADCIN0     =   P1^0;       //ADCͨ��0��ģ���ź������

sbit SPISCLK    =   P1^7;       //SPI���ߵ�ʱ�ӽ�
sbit SPIMISO    =   P1^6;       //SPI���ߵ����������
sbit SPIMOSI    =   P1^5;       //SPI���ߵ�����ӳ���
sbit SPISS      =   P1^4;       //SPI���ߵĴӻ�ѡ���

sbit CEX1       =   P1^4;       //�Ƚ�/����/PWM1�ⲿ����
sbit CEX0       =   P1^3;       //�Ƚ�/����/PWM0�ⲿ����
sbit ECI        =   P1^2;       //�Ƚ�/����/PWMģ����ⲿʱ�������(���ֵΪFosc/2)

sbit TXD2       =   P1^3;       //����2���������
sbit RXD2       =   P1^2;       //����2���������

sbit BRTCLKO    =   P1^0;       //BRTʱ��������������

/////////////////////////////////

sfr  P2         =   0xa0;       //I/O�˿�2              Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                P2.7    P2.6    P2.5    P2.4    P2.3    P2.2    P2.1    P2.0
                                //��ʼֵ=1111,1111      1       1       1       1       1       1       1       1

sbit P27        =   P2^7;       //I/O��P2.7
sbit P26        =   P2^6;       //I/O��P2.6
sbit P25        =   P2^5;       //I/O��P2.5
sbit P24        =   P2^4;       //I/O��P2.4
sbit P23        =   P2^3;       //I/O��P2.3
sbit P22        =   P2^2;       //I/O��P2.2
sbit P21        =   P2^1;       //I/O��P2.1
sbit P20        =   P2^0;       //I/O��P2.0

/////////////////////////////////

sfr  P3         =   0xb0;       //I/O�˿�3              Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                P3.7    P3.6    P3.5    P3.4    P3.3    P3.2    P3.1    P3.0
                                //��ʼֵ=1111,1111      1       1       1       1       1       1       1       1

sbit P37        =   P3^7;       //I/O��P3.7
sbit P36        =   P3^6;       //I/O��P3.6
sbit P35        =   P3^5;       //I/O��P3.5
sbit P34        =   P3^4;       //I/O��P3.4
sbit P33        =   P3^3;       //I/O��P3.3
sbit P32        =   P3^2;       //I/O��P3.2
sbit P31        =   P3^1;       //I/O��P3.1
sbit P30        =   P3^0;       //I/O��P3.0

sbit RXD        =   P3^0;       //����1�����ݽ��տ�
sbit TXD        =   P3^1;       //����1�����ݷ��Ϳ�
sbit INT0       =   P3^2;       //�ⲿ�ж�0���ź������
sbit INT1       =   P3^3;       //�ⲿ�ж�1���ź������
sbit T0         =   P3^4;       //��ʱ��0���ⲿ�ź������
sbit T1         =   P3^5;       //��ʱ��1���ⲿ�ź������
sbit WR         =   P3^6;       //�ⲿ���ݴ洢����д�ź�
sbit RD         =   P3^7;       //�ⲿ���ݴ洢���Ķ��ź�

sbit T0CLKO     =   P3^4;       //��ʱ��0��ʱ��������������
sbit T1CLKO     =   P3^5;       //��ʱ��1��ʱ��������������

/////////////////////////////////

sfr  P4         =   0xc0;       //I/O�˿�4              Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                P4.7    P4.6    P4.5    P4.4    P4.3    P4.2    P4.1    P4.0
                                //��ʼֵ=1111,1111      1       1       1       1       1       1       1       1

sbit P47        =   P4^7;       //I/O��P4.7
sbit P46        =   P4^6;       //I/O��P4.6
sbit P45        =   P4^5;       //I/O��P4.5
sbit P44        =   P4^4;       //I/O��P4.4
sbit P43        =   P4^3;       //I/O��P4.3
sbit P42        =   P4^2;       //I/O��P4.2
sbit P41        =   P4^1;       //I/O��P4.1
sbit P40        =   P4^0;       //I/O��P4.0

sbit RST        =   P4^7;       //��λ��,��ͨ�����������
sbit EX_LVD     =   P4^6;       //�ⲿ��ѹ�������

sbit P4SPISCLK  =   P4^3;       //SPI���ߵ�ʱ�ӽ�
sbit P4SPIMISO  =   P4^2;       //SPI���ߵ����������
sbit P4SPIMOSI  =   P4^1;       //SPI���ߵ�����ӳ���
sbit P4SPISS    =   P4^0;       //SPI���ߵĴӻ�ѡ���

sbit P4CEX1     =   P4^3;       //�Ƚ�/����/PWM1�ⲿ����
sbit P4CEX0     =   P4^2;       //�Ƚ�/����/PWM0�ⲿ����
sbit P4ECI      =   P4^1;       //�Ƚ�/����/PWMģ����ⲿʱ�������(���ֵΪFosc/2)

sbit P4TXD2     =   P4^3;       //����2���������
sbit P4RXD2     =   P4^2;       //����2���������

/////////////////////////////////

sfr  P5         =   0xc8;       //I/O�˿�5              Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                -       -       -       -       P5.3    P5.2    P5.1    P5.0
                                //��ʼֵ=xxxx,1111      x       x       x       x       1       1       1       1

sbit P53        =   P5^3;       //I/O��P5.3
sbit P52        =   P5^2;       //I/O��P5.2
sbit P51        =   P5^1;       //I/O��P5.1
sbit P50        =   P5^0;       //I/O��P5.0

/////////////////////////////////

sfr  P1M1       =   0x91;       //I/O��1ģʽ������1     Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��/ʼֵ=0000,0000     0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  P1M0       =   0x92;       //I/O��1ģʽ������0     Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  P0M1       =   0x93;       //I/O��0ģʽ������1     Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  P0M0       =   0x94;       //I/O��0ģʽ������0     Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  P2M1       =   0x95;       //I/O��2ģʽ������1     Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  P2M0       =   0x96;       //I/O��2ģʽ������0     Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  P3M1       =   0xb1;       //I/O��3ģʽ������1     Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��/ʼֵ=0000,0000     0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  P3M0       =   0xb2;       //I/O��3ģʽ������0     Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  P4M1       =   0xb3;       //I/O��4ģʽ������1     Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  P4M0       =   0xb4;       //I/O��4ģʽ������0     Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  P5M1       =   0xc9;       //I/O��5ģʽ������1     Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=xxxx,0000      x       x       x       x       0       0       0       0

/////////////////////////////////

sfr  P5M0       =   0xca;       //I/O��5ģʽ������0     Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=xxxx,0000      x       x       x       x       0       0       0       0

/////////////////////////////////

// PxM1 PxM0
//  0    0     ׼˫���
//  0    1     ǿ�������
//  1    0     ��������̬
//  1    1     ��©���

/////////////////////////////////

sfr  P1ASF      =   0x9d;       //P1��ģ�⹦�ܿ���λ    Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                P17ASF  P16ASF  P15ASF  P14ASF  P13ASF  P12ASF  P11ASF  P10ASF
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

#define P17ASF      0x80        //P1.7��ΪADC�����
#define P16ASF      0x40        //P1.7��ΪADC�����
#define P15ASF      0x20        //P1.7��ΪADC�����
#define P14ASF      0x10        //P1.7��ΪADC�����
#define P13ASF      0x08        //P1.7��ΪADC�����
#define P12ASF      0x04        //P1.7��ΪADC�����
#define P11ASF      0x02        //P1.7��ΪADC�����
#define P10ASF      0x01        //P1.7��ΪADC�����

/////////////////////////////////

sfr  P4SW       =   0xbb;       //P4�ڵĹ��ܿ���        Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                -    LVD_P4.6 ALE_P4.5 NA_P4.4  -       -       -       -
                                //��ʼֵ=x000,xxxx      x       0       0       0       x       x       x       x

#define P46EN       0x40        //��ͳ��EA�� 0:ΪLVD���ź������ 1:ΪP4.6
#define P45EN       0x20        //��ͳ��ALE�� 0:��ΪALE 1:ΪP4.5
#define P44EN       0x10        //��ͳ��PSEN�� 0:���κι��� 1:ΪP4.4

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sfr  IE         =   0xa8;       //�ж�ʹ�ܼĴ���        Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                EA      ELVD    EADC    ES      ET1     EX1     ET0     EX0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

sbit EA         =   IE^7;       //���жϿ���
sbit ELVD       =   IE^6;       //LVD�ж�ʹ��λ
sbit EADC       =   IE^5;       //ADC�ж�ʹ��λ
sbit ES         =   IE^4;       //�����ж�ʹ��λ
sbit ET1        =   IE^3;       //��ʱ��1�ж�ʹ��λ
sbit EX1        =   IE^2;       //�ⲿ�ж�1�ж�ʹ��λ
sbit ET0        =   IE^1;       //��ʱ��0�ж�ʹ��λ
sbit EX0        =   IE^0;       //�ⲿ�ж�0�ж�ʹ��λ

/////////////////////////////////

sfr  IE2        =   0xaf;       //�ж�ʹ�ܼĴ���2       Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                -       -       -       -       -       -       ESPI    ES2
                                //��ʼֵ=xxxx,xx00      x       x       x       x       x       x       0       0

#define ESPI        0x02        //SPI�ж�ʹ��λ
#define ES2         0x01        //����2�ж�ʹ��λ

/////////////////////////////////

#define X0_INTNO    0           //�ⲿ�ж�0�жϺ�,��ڵ�ַΪ0003H
#define T0_INTNO    1           //��ʱ��0�жϺ�,��ڵ�ַΪ000BH
#define X1_INTNO    2           //�ⲿ�ж�1�жϺ�,��ڵ�ַΪ0013H
#define T1_INTNO    3           //��ʱ��1�жϺ�,��ڵ�ַΪ001BH
#define UART_INTNO  4           //�����жϺ�,��ڵ�ַΪ0023H
#define ADC_INTNO   5           //ADC�жϺ�,��ڵ�ַΪ002BH
#define LVD_INTNO   6           //LVD�жϺ�,��ڵ�ַΪ0033H
#define UART2_INTNO 8           //����2�жϺ�,��ڵ�ַΪ0043H
#define SPI_INTNO   9           //SPI�жϺ�,��ڵ�ַΪ004BH

/////////////////////////////////

sfr  IP2        =   0xb5;       //�ж����ȼ��Ĵ���2     Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                -       -       -       -       -       -       PSPI    PS2
                                //��ʼֵ=xxxx,xx00      x       x       x       x       x       x       0       0

#define PSPI        0x02        //SPI�ж����ȼ����Ƶ�λ
#define PS2         0x01        //����2�ж����ȼ����Ƶ�λ

/////////////////////////////////

sfr  IP2H       =   0xb6;       //�ж����ȼ��Ĵ���2��λ Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                -       -       -       -       -       -       PSPIH   PS2H
                                //��ʼֵ=xxxx,xx00      x       x       x       x       x       x       0       0

#define PSPIH       0x02        //SPI�ж����ȼ����Ƹ�λ
#define PS2H        0x01        //����2�ж����ȼ����Ƹ�λ

/////////////////////////////////

sfr  IPH        =   0xb7;       //�ж����ȼ��Ĵ�����λ  Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                PPCAH   PLVDH   PADCH   PSH     PT1H    PX1H    PT0H    PX0H
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

#define PPCAH       0x80        //PCA�ж����ȼ����Ƹ�λ
#define PLVDH       0x40        //LVD�ж����ȼ����Ƹ�λ
#define PADCH       0x20        //ADC�ж����ȼ����Ƹ�λ
#define PSH         0x10        //�����ж����ȼ����Ƹ�λ
#define PT1H        0x08        //��ʱ��1�ж����ȼ����Ƹ�λ
#define PX1H        0x04        //�ⲿ�ж�1�ж����ȼ����Ƹ�λ
#define PT0H        0x02        //��ʱ��0�ж����ȼ����Ƹ�λ
#define PX0H        0x01        //�ⲿ�ж�0�ж����ȼ����Ƹ�λ

/////////////////////////////////

sfr  IP         =   0xb8;       //�ж����ȼ��Ĵ���      Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                PPCA    PLVD    PADC    PS      PT1     PX1     PT0     PX0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

sbit PPCA       =   IP^7;       //PCA�ж����ȼ����Ƶ�λ
sbit PLVD       =   IP^6;       //LVD�ж����ȼ����Ƶ�λ
sbit PADC       =   IP^5;       //ADC�ж����ȼ����Ƶ�λ
sbit PS         =   IP^4;       //�����ж����ȼ����Ƶ�λ
sbit PT1        =   IP^3;       //��ʱ��1�ж����ȼ����Ƶ�λ
sbit PX1        =   IP^2;       //�ⲿ�ж�1�ж����ȼ����Ƶ�λ
sbit PT0        =   IP^1;       //��ʱ��0�ж����ȼ����Ƶ�λ
sbit PX0        =   IP^0;       //�ⲿ�ж�0�ж����ȼ����Ƶ�λ

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sfr  TCON       =   0x88;       //��ʱ��0/1���ƼĴ���   Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                TF1     TR1     TF0     TR0     IE1     IT1     IE0     IT0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

sbit TF1        = TCON^7;       //��ʱ��1�����־,��Ӳ����1,���������0�������жϴ��������ɺ���Ӳ���Զ���0
sbit TR1        = TCON^6;       //��ʱ��1����������λ,1:������ʱ�� 0:ֹͣ��ʱ��
sbit TF0        = TCON^5;       //��ʱ��0�����־,��Ӳ����1,���������0�������жϴ��������ɺ���Ӳ���Զ���0
sbit TR0        = TCON^4;       //��ʱ��0����������λ,1:������ʱ�� 0:ֹͣ��ʱ��
sbit IE1        = TCON^3;       //�ⲿ�ж�1���ж�����λ,��Ӳ����1,���������0�������жϴ��������ɺ���Ӳ���Զ���0
sbit IT1        = TCON^2;       //�ⲿ�ж�1�Ĵ�������,0:�͵�ƽ�����ⲿ�ж� 1:�½��ش����ⲿ�ж�
sbit IE0        = TCON^1;       //�ⲿ�ж�0���ж�����λ,��Ӳ����1,���������0�������жϴ��������ɺ���Ӳ���Զ���0
sbit IT0        = TCON^0;       //�ⲿ�ж�0�Ĵ�������,0:�͵�ƽ�����ⲿ�ж� 1:�½��ش����ⲿ�ж�

/////////////////////////////////

sfr  TMOD       =   0x89;       //��ʱ��0/1ģʽ�Ĵ���   Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                GATE    C/T#    M1      M0      GATE    C/T#    M1      M0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

#define GATE1       0x80        //��ʱ��1��������λ,0:TR1Ϊ1ʱ������ʱ��1 1:TR1Ϊ1��INT1Ϊ�ߵ�ƽʱ��������ʱ��1
#define C_T1        0x40        //��ʱ��/������ѡ��λ,0:��ʱ��(ʱ��ԴΪ�ڲ�ʱ��) 1:������(ʱ��ԴΪT1���ŵ��ⲿʱ��)
#define T1_M0       0x00        //��ʱ��1����ģʽ0:13λ��ʱ��
#define T1_M1       0x10        //��ʱ��1����ģʽ1:16λ��ʱ��
#define T1_M2       0x20        //��ʱ��1����ģʽ2:8λ�Զ����ض�ʱ��
#define T1_M3       0x30        //��ʱ��1����ģʽ3:��ʱ��1ֹͣ
#define GATE0       0x08        //��ʱ��1��������λ,0:TR0Ϊ1ʱ������ʱ��1 1:TR0Ϊ1��INT0Ϊ�ߵ�ƽʱ��������ʱ��0
#define C_T0        0x04        //��ʱ��/������ѡ��λ,0:��ʱ��(ʱ��ԴΪ�ڲ�ʱ��) 1:������(ʱ��ԴΪT0���ŵ��ⲿʱ��)
#define T0_M0       0x00        //��ʱ��0����ģʽ0:13λ��ʱ��
#define T0_M1       0x01        //��ʱ��0����ģʽ1:16λ��ʱ��
#define T0_M2       0x02        //��ʱ��0����ģʽ2:8λ�Զ����ض�ʱ��
#define T0_M3       0x03        //��ʱ��0����ģʽ3:TL0��TH0Ϊ�������8λ��ʱ��

/////////////////////////////////

sfr  TL0        = 0x8a;         //��ʱ��0�ĵ�8λ����ֵ  Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  TL1        = 0x8b;         //��ʱ��1�ĵ�8λ����ֵ  Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  TH0        = 0x8c;         //��ʱ��0�ĸ�8λ����ֵ  Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  TH1        = 0x8d;         //��ʱ��1�ĸ�8λ����ֵ  Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sfr  SCON       =   0x98;       //���ڿ��ƼĴ���        Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                SM0/FE  SM1     SM2     REN     TB8     RB8     TI      Ri
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

sbit FE         =   SCON^7;     //֡������λ,������ģ���ڽ�������ʱû�м�⵽��ȷ��ֹͣλʱ,FE��Ӳ����1,��Ҫ���������0(��SMOD0Ϊ1ʱ,FE��Ч)
sbit SM0        =   SCON^7;     //����ģʽ����λ
sbit SM1        =   SCON^6;     //SM0/SM1=0/0:��λ�Ĵ��� 0/1:8λ�ɱ䲨���� 1/0:9λ�̶������� 1/1:9λ�ɱ䲨����
sbit SM2        =   SCON^5;     //�Զ���ַʶ��ʹ��λ
sbit REN        =   SCON^4;     //ʹ�ܴ��ڽ���ģ��
sbit TB8        =   SCON^3;     //���͵ĵ�9λ����
sbit RB8        =   SCON^2;     //���յĵ�9λ����
sbit TI         =   SCON^1;     //��������жϱ�־
sbit RI         =   SCON^0;     //��������жϱ�־

/////////////////////////////////

sfr  SBUF       =   0x99;       //���ڽ���/��������     Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=xxxx,xxxx      x       x       x       x       x       x       x       x

/////////////////////////////////

sfr  S2CON      =   0x9a;       //����2���ƼĴ���       Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                SM0/FE  SM1     SM2     REN     TB8     RB8     TI      Ri
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

#define S2SM0       0x80        //����2ģʽ����λ
#define S2SM1       0x40        //SM0/SM1=0/0:��λ�Ĵ��� 0/1:8λ�ɱ䲨���� 1/0:9λ�̶������� 1/1:9λ�ɱ䲨����
#define S2SM2       0x20        //�Զ���ַʶ��ʹ��λ
#define S2REN       0x10        //ʹ�ܴ���2����ģ��
#define S2TB8       0x08        //���͵ĵ�9λ����
#define S2RB8       0x04        //���յĵ�9λ����
#define S2TI        0x02        //��������жϱ�־
#define S2RI        0x01        //��������жϱ�־

/////////////////////////////////

sfr  S2BUF      =   0x9b;       //����2����/��������    Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=xxxx,xxxx      x       x       x       x       x       x       x       x

/////////////////////////////////

sfr  SADDR      =   0xa9;       //�����豸�ӵ�ַ�Ĵ���  Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  SADEN      =   0xb9;       //�����豸�ӵ�ַ����λ  Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  BRT        =   0x9c;       //���������ʷ���������ֵBit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sfr  ADC_CONTR  =   0xbc;       //ADC���ƼĴ���         Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����            ADC_POWER  SPEED1 SPEED0 ADC_FLAG ADC_START CHS2    CHS1    CHS0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

#define ADC_POWER   0x80        //ADCģ���Դ����λ
#define ADC_SPEEDLL 0x00        //ÿ��ת����Ҫ420��ʱ������
#define ADC_SPEEDL  0x20        //ÿ��ת����Ҫ280��ʱ������
#define ADC_SPEEDH  0x40        //ÿ��ת����Ҫ140��ʱ������
#define ADC_SPEEDHH 0x60        //ÿ��ת����Ҫ70��ʱ������
#define ADC_FLAG    0x10        //ADCת����ɱ�־
#define ADC_START   0x08        //ADC��ʼת������λ
#define ADC_CHS2    0x04        //ADCͨ��ѡ��λ2
#define ADC_CHS1    0x02        //ADCͨ��ѡ��λ1
#define ADC_CHS0    0x01        //ADCͨ��ѡ��λ0

/////////////////////////////////

sfr  ADC_RES    =   0xbd;       //ADC������ֽ�         Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  ADC_RESL   =   0xbe;       //ADC������ֽ�         Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sfr  IAP_DATA   =   0xc2;       //IAP���ݼĴ���         Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=1111,1111      1       1       1       1       1       1       1       1

/////////////////////////////////

sfr  IAP_ADDRH  =   0xc3;       //IAP��ַ��λ�Ĵ���     Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  IAP_ADDRL  =   0xc4;       //IAP��ַ��λ�Ĵ���     Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  IAP_CMD    =   0xc5;       //IAP����Ĵ���         Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=xxxx,xx00      x       x       x       x       x       x       0       0

#define IAP_IDLE    0x00        //IAP��������
#define IAP_READ    0x01        //IAP���ֽ���������
#define IAP_PROGRAM 0x02        //IAP�ֽڱ������
#define IAP_ERASE   0x03        //IAP������������(ÿ����512�ֽ�))

/////////////////////////////////

sfr  IAP_TRIG   =   0xc6;       //IAP������Ĵ���     Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=xxxx,xxxx      x       x       x       x       x       x       x       x

#define IAP_TRIG0   0x5a        //IAP���ܴ�������1
#define IAP_TRIG1   0xa5        //IAP���ܴ�������2

/////////////////////////////////

sfr  IAP_CONTR  =   0xc7;       //IAP���ƼĴ���         Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                IAPEN   SWBS    SWRST   CMD_FAIL -      WT2     WT1     WT0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

#define IAPEN       0x80        //IAPʹ�ܿ���
#define SWBS        0x40        //������ѡ��,0:���û�AP���� 1:��ISP����
#define SWRST       0x20        //���������λ
#define CMD_FAIL    0x10        //IAP����ʧ�ܱ�־

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sfr  SPSTAT     =   0xcd;       //SPI״̬�Ĵ���         Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                SPIF    WCOL    -       -       -       -       -       -
                                //��ʼֵ=11xx,xxxx      1       1       x       x       x       x       x       x

#define SPIF        0x80        //SPI������ɱ�־,��SPI�ж�ʹ��ʱ�ᴥ��SPI�ж�����,��Ҫ��������λд"1"����0
#define WCOL        0x40        //SPIд��ͻ��־,��Ҫ��������λд"1"����0

/////////////////////////////////

sfr  SPCTL      =   0xce;       //SPI���ƼĴ���         Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                SSIG    SPEN    DORD    MSTR    CPOL    CPHA    SPR1    SPR0
                                //��ʼֵ=0000,0100      0       0       0       0       0       1       0       0

#define SSIG        0x80        //SS����λ,1:��MSTRȷ����/�� 0:��SS��ȷ����/��
#define SPEN        0x40        //SPIģ��ʹ��λ
#define DORD        0x20        //SPI����˳��,1:LSB(����/�����λ) 0:MSB(����/�����λ)
#define MSTR        0x10        //��/��ģʽѡ��λ
#define CPOL        0x08        //SPIʱ�Ӽ���
#define CPHA        0x04        //SPI��λѡ��
#define SPSPEEDHH   0x00        //�����ٶ�,CPU_CLK/4
#define SPSPEEDH    0x01        //�����ٶ�,CPU_CLK/16
#define SPSPEEDL    0x02        //�����ٶ�,CPU_CLK/64
#define SPSPEEDLL   0x03        //�����ٶ�,CPU_CLK/128

/////////////////////////////////

sfr  SPDAT      =   0xcf;       //SPI���ݼĴ���         Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sfr  CCON       =   0xd8;       //PCA���ƼĴ���         Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                CF      CR      -       -       -       -       CCF1    CCF0
                                //��ʼֵ=00xx,xx00      0       0       x       x       x       x       0       0

sbit CF         =   CCON^7;     //PCA�����������־,��PCA�ж�ʹ��ʱ�ᴥ��PCA�ж�����,��Ҫ�������0
sbit CR         =   CCON^6;     //PCA��������������λ,д"1"������������
sbit CCF1       =   CCON^1;     //PCAģ��1�жϱ�־,��Ҫ�������0
sbit CCF0       =   CCON^0;     //PCAģ��0�жϱ�־,��Ҫ�������0

/////////////////////////////////

sfr  CMOD       =   0xd9;       //PCAģʽ�Ĵ���         Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                CIDL    -       -       -       CPS2    CPS1    CPS0    ECF
                                //��ʼֵ=0xxx,0000      0       x       x       x       0       0       0       0

#define CIDL        0x80        //��ʱ�����п��п���,0:����ģʽ��PCA�������� 1:����ģʽ��PCAֹͣ����
#define PCACLK0     0x00        //Fosc/12
#define PCACLK1     0x02        //Fosc/2
#define PCACLK2     0x04        //��ʱ��0�������
#define PCACLK3     0x06        //ECI�ⲿʱ��
#define PCACLK4     0x08        //Fosc/1
#define PCACLK5     0x0a        //Fosc/4
#define PCACLK6     0x0c        //Fosc/6
#define PCACLK7     0x0e        //Fosc/8
#define ECF         0x01        //PCA����������ж�����λ

/////////////////////////////////

sfr  CCAPM0     =   0xda;       //PCAģ��0ģʽ�Ĵ���    Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                -       ECOM0   CAPP0   CAPN0   MAT0    TOG0    PWM0    ECCF0
                                //��ʼֵ=x000,0000      x       0       0       0       0       0       0       0

#define PCA0_ECOM   0x40        //ʹ�ܱȽ���0
#define PCA0_CAPP   0x20        //ʹ��PCAģ��0�������ز���
#define PCA0_CAPN   0x10        //ʹ��PCAģ��0���½��ز���
#define PCA0_MAT    0x08        //ƥ��ʹ��,��PCA�ļ���ֵ��ģ��0�趨��ֵ��ƥ��ʱ,��CCON.CCF0
#define PCA0_TOG    0x04        //��ת����λ,��PCA�ļ���ֵ��ģ��0�趨��ֵ��ƥ��ʱ,��תCEX0�ĵ�ƽ
#define PCA0_PWM    0x02        //�������ģʽ,ʹ��CEX0Ϊ������������
#define PCA0_ECCF   0x01        //ʹ��CCF0�ж�

/////////////////////////////////

sfr  CCAPM1     =   0xdb;       //PCAģ��1ģʽ�Ĵ���    Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                -       ECOM1   CAPP1   CAPN1   MAT1    TOG1    PWM1    ECCF1
                                //��ʼֵ=x000,0000      x       0       0       0       0       0       0       0

#define PCA1_ECOM   0x40        //ʹ�ܱȽ���1
#define PCA1_CAPP   0x20        //ʹ��PCAģ��1�������ز���
#define PCA1_CAPN   0x10        //ʹ��PCAģ��1���½��ز���
#define PCA1_MAT    0x08        //ƥ��ʹ��,��PCA�ļ���ֵ��ģ��1�趨��ֵ��ƥ��ʱ,��CCON.CCF1
#define PCA1_TOG    0x04        //��ת����λ,��PCA�ļ���ֵ��ģ��1�趨��ֵ��ƥ��ʱ,��תCEX1�ĵ�ƽ
#define PCA1_PWM    0x02        //�������ģʽ,ʹ��CEX1Ϊ������������
#define PCA1_ECCF   0x01        //ʹ��CCF1�ж�

/////////////////////////////////

//CCAPM0   -   ECOM CAPP CAPN MAT  TOG  PWM  CCF
// 00H     0    0    0    0    0    0    0    0     �޲���,����״̬
// 42H     0    1    0    0    0    0    1    0     8λPWM���,���ж�
// 63H     0    1    1    0    0    0    1    1     8λPWM���,����CEX0�������ж�
// 53H     0    1    0    1    0    0    1    1     8λPWM���,����CEX0�½����ж�
// 73H     0    1    1    1    0    0    1    1     8λPWM���,����CEX0�����ж�
// 20H     0    x    1    0    0    0    0    0     16λ����ģʽ,CEX0�����ش�������
// 10H     0    x    0    1    0    0    0    0     16λ����ģʽ,CEX0�½��ش�������
// 30H     0    x    1    1    0    0    0    0     16λ����ģʽ,CEX0���䴥������
// 48H     0    1    0    0    1    0    0    0     16λ�����ʱ��
// 4CH     0    1    0    0    1    1    0    0     16λ�����������

/////////////////////////////////

sfr  CL         =   0xe9;       //PCA��������8λ        Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  CH         =   0xf9;       //PCA��������8λ        Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  CCAP0L     =   0xea;       //PCAģ��0�Ĵ�����8λ   Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  CCAP1L     =   0xeb;       //PCAģ��1�Ĵ�����8λ   Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  CCAP0H     =   0xfa;       //PCAģ��0�Ĵ�����8λ   Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  CCAP1H     =   0xfb;       //PCAģ��1�Ĵ�����8λ   Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //��ʼֵ=0000,0000      0       0       0       0       0       0       0       0

/////////////////////////////////

sfr  PCA_PWM0   =   0xf2;       //PCA0ģʽPWM�����Ĵ��� Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                -       -       -       -       -       -       EPC0H   EPC0L
                                //��ʼֵ=xxxx,xx00      x       x       x       x       x       x       0       0

/////////////////////////////////

sfr  PCA_PWM1   =   0xf3;       //PCA1ģʽPWM�����Ĵ��� Bit7    Bit6    Bit5    Bit4    Bit3    Bit2    Bit1    Bit0
                                //λ����                -       -       -       -       -       -       EPC1H   EPC1L
                                //��ʼֵ=xxxx,xx00      x       x       x       x       x       x       0       0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
sfr PCAPWM0     =   0xf2;
sfr PCAPWM1     =   0xf3;
#endif
