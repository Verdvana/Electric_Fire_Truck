#ifndef _PWM_H_
#define _PWM_H_
#include "STC12C5A.h"


typedef enum 
{     
LEFT,
RIGHT
};
void CarGo();
void CarBack();
void CarStop();
void CarTurnLeft();
void CarTurnRight();
void InitPwm();
void SetSpeed(char dir,unsigned int value);
void Delayms(unsigned int n);


#endif