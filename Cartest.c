#include "STC12C5A.h"
#include "Cartest.h"



#define LEFT 1
#define RIGHT 0

/********左边电机*************/


sbit IN1=P2^0;   //电机驱动L298N 在硬件上连着P20--P23   但是PWM0的输出是P1 PWM0
sbit IN2=P2^1;	
/********右边电机*************/

sbit IN3=P2^2;
sbit IN4=P2^3;


/*************小车前进*******************/


void CarGo()
{ 
IN1=0;
IN2=1;
IN3=0;
IN4=1;
}


/*************小车后退*******************/

void CarBack()
{ 
IN1=1;
IN2=0;
IN3=1;
IN4=0;
}


/****************小车停止*************************/

void CarStop()
{ 
IN1=1;
IN2=1;
IN3=1;
IN4=1;
}

/*******************小车右转**********************************/

void CarTurnRight()
{ 
IN1=0;
IN2=1;
IN3=1;
IN4=0;
}


/*******************小车左转**********************************/

void CarTurnLeft()
{ 
IN1=1;
IN2=0;
IN3=0;
IN4=1;
}


/*******************小车单轮左转**********************************
void CarLittleLeft()
{ 
IN1=1;
IN2=1;
IN3=0;
IN4=1;

}
*******************小车单轮右转*********************************

void CarLittleRight()
{ 
IN1=0;
IN2=1;
IN3=1;
IN4=1;
}
*/





/**************初始化PWM波***************/
void InitPwm()
{  

  
	CCON = 0;                       //Initial PCA control register
                                    //PCA timer stop running
                                    //Clear CF flag
                                    //Clear all module interrupt flag
    CL = 0;                         //Reset PCA base timer
    CH = 0;
    CMOD = 0x00;                    //Set PCA timer clock source as Fosc/2
                                    //Disable PCA timer overflow interrupt
    CCAP0H = CCAP0L = 0xfE;         //PWM0 port output 50% duty cycle square wave
    CCAPM0 = 0x42;                  //PCA module-0 work in 8-bit PWM mode and no PCA interrupt

    CCAP1H = CCAP1L = 0xfE;         //PWM1 port output 0% duty cycle square wave
      //   PCAPWM1 = 0x03;
    CCAPM1 = 0x42;                  //PCA module-1 work in 8-bit PWM mode and no PCA interrupt

    CR = 1;                         //PCA timer start run

}


/*******速度设置函数************/
/**************值越高PWM占空比越低********************/


void SetSpeed(char dir,unsigned int value)
{    
  if(dir==LEFT) 
{   

  CCAP0H = CCAP0L = value;   

}   
  if(dir==RIGHT) 
{
  CCAP1H = CCAP1L = value;   
}   
 
}

/******延时程序*********/
void Delayms(unsigned int n)
{   
while(n--)
{  
	unsigned char i, j;

	i = 22;
	j = 128;
	do
	{
		while (--j);
	} while (--i);
}
}

