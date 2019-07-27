/************������Ƴ���*****************/


#include "gear.h"
#include "STC12C5A.h"

#define uchar unsigned char 
#define uint unsigned int

volatile uint counter=0;  //��ʱ��ʹ��
uint standa=0;


/*���¶�������ܽ�*/ 

					 
sbit SinG1=  P0^4;


/***��ʼ��timer0***/



void Init_Timer1()
{
	TMOD|=0x01;	//ʹ�ö�ʱ��T0�Ĺ���ģʽ1 16λ������ �ۼӵ�65535���
    ET1=1;		//��ʱ��T0�����ж�
	EA=1;		//ȫ���ж�
	TH1=0xff;// 
	TL1=0x47;// /*���¶��������ֵ0.1ms*/
	
	TR1=1;		//��	
}	 


/*�趨����ĽǶ�*/ 					 

void SetAngle(unsigned char jiaodu) 
{
  unsigned char standa,con3;

  standa=jiaodu/9+5;	//���ǶȻ�Ϊ��ʱʱ�� 0.1ms�ı���
  con3=0;               //��¼���������� һ���������Ҫ����������ڶ������ת��ָ��λ��
  Init_Timer1();    	//��ʼ��ʱ

  while(con3<30)		//��ʮ������ ������Ե�ָ��λ��  �����Ը���
  {	  
	if(counter==standa)	 //�ߵ�ƽʱ�䵽 ����
	SinG1=0;
	
    if(counter==200)		  //���20ms һ���������ڽ���
	  {
		counter=0;
	    con3++;	               //��¼���������ʱ�� ������������Ϊ��׼
	    SinG1=1;			   //��ʼ�ߵ�ƽʱ��
	}
   }
  ET1=0;					   //���ʹ����� �رն�ʱ����ʹ��
  TR1=0;		//��	
}

/*��ʱ��1�����ƶ��1��2���������ΪP12�����Զ���*/ 


 void timer0(void) interrupt 3 using 1 
{
   	  	TH1=0xff; 	   /*��ʱ������184Ϊ0.1ms*/ 
		
        TL1=0x47;      /*���¶��������ֵ0x47+184���*/
		
   	 	counter++;	
} 


					



