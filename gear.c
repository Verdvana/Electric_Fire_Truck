/************舵机控制程序*****************/


#include "gear.h"
#include "STC12C5A.h"

#define uchar unsigned char 
#define uint unsigned int

volatile uint counter=0;  //定时器使用
uint standa=0;


/*以下定义输出管脚*/ 

					 
sbit SinG1=  P0^4;


/***初始化timer0***/



void Init_Timer1()
{
	TMOD|=0x01;	//使用定时器T0的工作模式1 16位计数器 累加到65535溢出
    ET1=1;		//定时器T0允许中断
	EA=1;		//全局中断
	TH1=0xff;// 
	TL1=0x47;// /*重新定义计数初值0.1ms*/
	
	TR1=1;		//打开	
}	 


/*设定舵机的角度*/ 					 

void SetAngle(unsigned char jiaodu) 
{
  unsigned char standa,con3;

  standa=jiaodu/9+5;	//将角度换为延时时间 0.1ms的倍数
  con3=0;               //记录脉冲周期数 一般情况下需要多个脉冲周期舵机才能转到指定位置
  Init_Timer1();    	//开始计时

  while(con3<30)		//三十个周期 舵机可以到指定位置  还可以更短
  {	  
	if(counter==standa)	 //高电平时间到 拉低
	SinG1=0;
	
    if(counter==200)		  //间隔20ms 一个脉冲周期结束
	  {
		counter=0;
	    con3++;	               //记录脉冲持续的时间 以他的周期数为标准
	    SinG1=1;			   //开始高电平时间
	}
   }
  ET1=0;					   //舵机使用完毕 关闭定时器的使能
  TR1=0;		//打开	
}

/*定时器1，控制舵机1和2，输出引脚为P12，可自定义*/ 


 void timer0(void) interrupt 3 using 1 
{
   	  	TH1=0xff; 	   /*计时器计数184为0.1ms*/ 
		
        TL1=0x47;      /*重新定义计数初值0x47+184溢出*/
		
   	 	counter++;	
} 


					



