#include "STC12C5A.h"    
#include "Cartest.h"
#include "gear.h"
#include "PWM.h"

#define BIT0  0x01
#define BIT1  0x02
#define BIT2  0x04
#define BIT3  0x08
#define BIT4  0x10

/////////////////////////////��������//////////////////////////////
sbit relay=P0^6;

sbit flame1=P1^0;	//������ ����Ϊ1--5��
sbit flame2=P1^1;
sbit flame3=P1^2;
sbit flame4=P1^5;
sbit flame5=P1^6;
sbit flame6=P1^7;
sbit SPK=P0^7;

sbit flameleft=P3^0;
//sbit flamefront=P3^1;

sbit sshead1=P2^7;
sbit sshead2=P2^6;
//sbit sshead3=P;
sbit sshead4=P2^5;
sbit sshead5=P2^4;
//sbit sstail1=P;
//sbit sstail2=P;
//sbit sstail3=P;
sbit sstail4=P0^0;
sbit sstail5=P0^1;

///////////���ѭ��/////////////
//sbit ssfront1=P
sbit ssfront2=P0^2;
sbit ssfront3=P0^3;
//sbit ssfront4=P
//sbit ssback1=P
sbit ssback2=P0^5;
sbit ssback3=P3^4;
//sbit ssback4=P

unsigned char isleft1=0,isright1=0,isleft2=0,isright2=0,flag1=0,flag2=0,flag3=0,extinguish=0;
char count0=1,count1=0,count2=0,count3=0;

volatile unsigned char number_of_left =0,Timer1_Over;
volatile unsigned char number_of_right =0;

volatile int BeepTime;	 //ȫ�ֱ�������ʱ��
volatile int Half_BeepTime;	 //ȫ�ֱ�������ʱ��

////////////////////////��������///////////////////////
void go();
void back();
void cargoline();
void goturnleft();
void carbackline();
void backturnright();
void cargolinemid();
void turnleftmid();
void searchleft();
void flame();
void delay(unsigned char a);
void Set_Beep( int Time);
void InitTimer();
void Delay_Mapan(unsigned char number_of_ten);
void Initial_ET();

/***********************************************************************/
void main (void)
{	 
	P1=0xff;   //���ʹ�ܲ���
	 		
	Delayms(500); 		
	SetAngle(0);//�����ת
	SetAngle(180);//�����ת
	SetAngle(90);//�����λ  ��װУ׼

	InitTimer();    
 	InitPwm();

	Set_Beep(6000);
//	delay(400);
 	while(1)
	{	
		go();						
	}
}
/////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////����/////////////////////////////////

void go()
{
	cargoline();
	if(sshead4==0&&flag1==0&&isleft1==0)flag1=1;
	if(flag1==1&&sshead4==1)count1++,flag1=0;
	
	if(sshead4==0&&flag2==0&&isleft1==1&&isleft2==0)flag2=1;
	if(flag2==1&&sshead4==1)count2++,flag2=0;
	
	if(sstail4==0&&flag3==0&&isleft2>0&&extinguish==0)flag3=1;
	if(flag3==1&&sstail4==1)count3++,flag3=0;
	
	if(count1==3&&isleft1==0)
	{		
		goturnleft();
		Delay_Mapan(8);
		isleft1=1;
	}
	if(flameleft==1&&isleft2==0)
	{		 
		searchleft();
		isleft2=1;
	}
	if(count2==5&&isleft2==0)
	{		
		goturnleft();
		Delay_Mapan(8);
		isleft2=2;
	}
	if(count3==3)back();
	if((P1&0xE7)>0)flame();
	go();
}

void back()
{
//	if(��ǰ���л�)go()
	carbackline();
	if(sstail4==0&&flag3==0&&isright1==0)flag3=1;
	if(flag3==1&&sstail4==1)count3--,flag3=0;

	if(sstail4==0&&flag2==0&&isright1==1&&isright2==0)flag2=1;
	if(flag2==1&&sstail4==1)count2--,flag2=0;

	if(sshead4==0&&flag1==0&&isright2==1&&count1>0)flag1=1;
	if(flag1==1&&sshead4==1)count1--,flag1=0;
	
	if(count3==0&&isright1==0&&isleft2==1)
	{		
		backturnright();
		Delay_Mapan(8);
		isright1=1;
	}
	if(count2==0&&isright2==0&&isleft1==1)
	{		
		backturnright();
		Delay_Mapan(8);
		isright2=1;
	}	
	if(count1==0)
	{		
		CarStop();
		//�������//
		while(1);
	}
	back();
}

//////////////////////ǰ��/////////////////////////////////////

void cargoline()
{
	if(ssfront3==0&&sshead5==1)
	{
		SetSpeed(LEFT,30);
      	SetSpeed(RIGHT,250);
		CarTurnRight();	
	}
	if(ssfront2==1)
	{
		SetSpeed(LEFT,250);
      	SetSpeed(RIGHT,30);
		CarTurnLeft();
	}
	else 
	{
		SetSpeed(LEFT,40);
     	SetSpeed(RIGHT,40);
    	CarGo(); 
	}			
}

void goturnleft()
{
	SetSpeed(LEFT,30);
    SetSpeed(RIGHT,250);
	CarGo();
}
/*
void goturnright()
{
	SetSpeed(LEFT,250);
    SetSpeed(RIGHT,30);
	CarGo();
}
*/
////////////////////////////////����//////////////////////////////

void carbackline()
{
	if(ssback3==0&&sstail5==1)
	{
		SetSpeed(LEFT,30);
      	SetSpeed(RIGHT,250);
		CarTurnLeft();	
	}
	if(ssback2==1)
	{
		SetSpeed(LEFT,250);
      	SetSpeed(RIGHT,30);
		CarTurnRight();
	}
	else 
	{
		SetSpeed(LEFT,40);
     	SetSpeed(RIGHT,40);
    	CarGo(); 
	}			
}
/*
void backturnleft()
{
	SetSpeed(LEFT,250);
    SetSpeed(RIGHT,30);
	CarBack();
}
*/
void backturnright()
{
	SetSpeed(LEFT,30);
    SetSpeed(RIGHT,250);
	CarBack();
}
////////////////////////////////////////////////////////////////////

void cargolinemid()
{
	if(sshead4==0&&sshead1==1)
	{
		SetSpeed(LEFT,30);
      	SetSpeed(RIGHT,250);
		CarTurnRight();	
	}
	if(sshead2==1&&sshead5==1)
	{
		SetSpeed(LEFT,250);
      	SetSpeed(RIGHT,30);
		CarTurnLeft();
	}
	else 
	{
		SetSpeed(LEFT,40);
     	SetSpeed(RIGHT,40);
    	CarGo(); 
	}			
}
void turnleftmid()
{
	SetSpeed(LEFT,60);
    SetSpeed(RIGHT,150);
	CarTurnLeft();
}
//////////////////////////////////////////////////////
void searchleft()
{
	if(count2==2)
	{
		while(sshead4==1)					  /////////
		{
			cargoline();
		}
		if (sshead4==0)
		{
			turnleftmid();
			Delay_Mapan(8);
		}
		while(count3<3)		 
		{	
			cargolinemid();
			if(sstail4==0)count3++;
			if((P1&0x2F)>0)flame();
		}
	}
	if (count2==3||count2==4)
	{
		while(sshead4==1)
		{
			carbackline();
		} 
		if (sshead4==0)
		{
			goturnleft();
			Delay_Mapan(8);
		}
		while(count3<3)		
		{	
			cargoline();
			if(sstail4==0)count3++;
			if((P1&0xE7)>0)flame();
		}
	}
}

//////////////////////////////���/////////////////////////
void flame()
{	
	extinguish++;
	CarStop();
	Set_Beep(1000);
	delay(3000);
	relay=1;

	SetAngle(180);
	delay(200);
	SetAngle(170);
	delay(200);
	SetAngle(160);
	delay(200);
	SetAngle(150);
	delay(200);
	SetAngle(140);
	delay(200);
	SetAngle(130);
	delay(200);
	SetAngle(110);
	delay(200);
	SetAngle(100);
	delay(200);
	SetAngle(90);
	delay(200);
	SetAngle(80);
	delay(200);
	SetAngle(70);
	delay(200);
	SetAngle(60);
	delay(200);
	SetAngle(50);
	delay(200);
	SetAngle(40);
	delay(200);
	SetAngle(30);
	delay(200);
	SetAngle(20);
	delay(200);
	SetAngle(10);
	delay(200);
	SetAngle(0);
	delay(200);
	SetAngle(90);

	relay=0;
	Set_Beep(6000);
//	delay(400);
//	if(��ǰ���л�)go()
	back();	
}

/*
void gear(char n)
{
	SetAngle(30*n+20);
	delay(200);
	SetAngle(30*n+10);
	delay(200);
	SetAngle(30*n);
	delay(200);
	SetAngle(30*n-10);
	delay(200);
	SetAngle(30*n-20);
	delay(200);
	SetAngle(90);
}
*/		

/*------------------------------------------------
             �趨����������ʱ�䳤��
------------------------------------------------*/
void Set_Beep( int Time)
{
	BeepTime=Time;//�趨ʱ�䳤��
	Half_BeepTime=	Time/4*3;
}

void delay(unsigned char a)
{	
	unsigned char i;
	for(i=0;i<a;i++);
}

void Initial_ET()//��ʼ���ⲿ�ж�  ����½���
{
	IT0=1;		   //�����䴥���ж�0
	IT1=1;		   //�����䴥���ж�1
	EX0=1;		   //�����ⲿ�ж�0
	EX1=1;		   //�����ⲿ�ж�1
	EA=1;
}
//********************************************************************************/
//                                   �����ӳٺ���								 //
//                         ��������ת���ĸ����������ӳٵ�ʱ��                    //
//********************************************************************************/
void Delay_Mapan(unsigned char number_of_ten)
{
	number_of_left=0;
 	number_of_right=0;  //3.3  3.2
 	Initial_ET();//��ʼ���ⲿ�ж�  ����½���  �����ⲿ�ж�
  	while((number_of_left<=number_of_ten) && (number_of_right<=number_of_ten)); //�ӳٵ�ת��һ���Ƕ� ֻҪ��һ�����˾�ͣ
  	EX0=0;	        //�ر��ⲿ�ж�0
  	EX1=0;		   //�ر��ⲿ�ж�1
}

/*------------------------------------------------
             ��ʼ����ʱ��
------------------------------------------------*/

void InitTimer()
{
	TMOD = 0x01;                    //set timer0 as mode1 (16-bit)
    TL0 = 0;                     	//initial timer0 low byte
    TH0 = 0xff;               	 	//initial timer0 high byte
    TR0 = 1;              			 //timer0 not start running
    ET0 = 1;                        //enable timer0 interrupt
    EA  = 1;                         //open global interrupt switch
}

//////////////////////////�ж�//////////////////////////////////

/*------------------------------------------------
                 �ⲿ�ж�0������
------------------------------------------------*/
void Extern_IT0(void) interrupt 0
{ 
  	number_of_left++;
}
/*------------------------------------------------
                 �ⲿ�ж�1������
------------------------------------------------*/
void Extern_IT1(void) interrupt 2
{ 
  	number_of_right++;
}


void tm0_isr() interrupt 1 using 1
{

   	static int Counter=0,Half_Counter;

 	Counter--;
	if(Counter>Half_Counter)
	{
		TL0 = 0;                     //reload timer0 low byte
    	TH0 = 0xff;                //reload timer0 high byte
		SPK=!SPK;
	}

	else if(Counter>0)   //������ �ó�Ĭ��
	{
		TL0 = 0;                     //reload timer0 low byte
    	TH0 = 0xff;                //reload timer0 high byte 
		SPK=0;
	}
	else   {Counter=BeepTime; Half_Counter=Half_BeepTime;}
}
