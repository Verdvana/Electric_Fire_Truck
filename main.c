#include "STC12C5A.h"    
#include "Cartest.h"
#include "gear.h"
#include "PWM.h"

#define BIT0  0x01
#define BIT1  0x02
#define BIT2  0x04
#define BIT3  0x08
#define BIT4  0x10

/////////////////////////////变量定义//////////////////////////////
sbit relay=P0^6;

sbit flame1=P1^0;	//从左到右 依次为1--5；
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

///////////左边循迹/////////////
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

volatile int BeepTime;	 //全局变量控制时间
volatile int Half_BeepTime;	 //全局变量控制时间

////////////////////////函数声明///////////////////////
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
	P1=0xff;   //电机使能部分
	 		
	Delayms(500); 		
	SetAngle(0);//舵机右转
	SetAngle(180);//舵机左转
	SetAngle(90);//舵机复位  安装校准

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


///////////////////////////////函数/////////////////////////////////

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
//	if(左前方有火)go()
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
		//调整入库//
		while(1);
	}
	back();
}

//////////////////////前进/////////////////////////////////////

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
////////////////////////////////后退//////////////////////////////

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

//////////////////////////////灭火/////////////////////////
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
//	if(左前方有火)go()
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
             设定蜂鸣器发声时间长度
------------------------------------------------*/
void Set_Beep( int Time)
{
	BeepTime=Time;//设定时间长度
	Half_BeepTime=	Time/4*3;
}

void delay(unsigned char a)
{	
	unsigned char i;
	for(i=0;i<a;i++);
}

void Initial_ET()//初始化外部中断  检测下降沿
{
	IT0=1;		   //负跳变触发中断0
	IT1=1;		   //正跳变触发中断1
	EX0=1;		   //允许外部中断0
	EX1=1;		   //允许外部中断1
	EA=1;
}
//********************************************************************************/
//                                   码盘延迟函数								 //
//                         根据码盘转过的个数来决定延迟的时间                    //
//********************************************************************************/
void Delay_Mapan(unsigned char number_of_ten)
{
	number_of_left=0;
 	number_of_right=0;  //3.3  3.2
 	Initial_ET();//初始化外部中断  检测下降沿  开启外部中断
  	while((number_of_left<=number_of_ten) && (number_of_right<=number_of_ten)); //延迟到转动一定角度 只要有一个到了就停
  	EX0=0;	        //关闭外部中断0
  	EX1=0;		   //关闭外部中断1
}

/*------------------------------------------------
             初始化定时器
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

//////////////////////////中断//////////////////////////////////

/*------------------------------------------------
                 外部中断0服务函数
------------------------------------------------*/
void Extern_IT0(void) interrupt 0
{ 
  	number_of_left++;
}
/*------------------------------------------------
                 外部中断1服务函数
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

	else if(Counter>0)   //响完了 该沉默了
	{
		TL0 = 0;                     //reload timer0 low byte
    	TH0 = 0xff;                //reload timer0 high byte 
		SPK=0;
	}
	else   {Counter=BeepTime; Half_Counter=Half_BeepTime;}
}
