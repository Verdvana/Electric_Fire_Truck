#ifndef __cartest_H__
#define __cartest_H__



void CarGo();
void CarBack();
void CarStop() ;
void CarTurnLeft();
void CarTurnRight();
void InitPwm();
void SetDACleft(unsigned char value) ;
void SetDACright(unsigned char value);
void SetSpeed(char dir,unsigned int value);   //////////dir 可以选择左或者右  speed 选择速度  speed>0 正向  speed<0 则反向 speed越大 转速绝对值越大 (-255~+255)
void Delayms(unsigned int n);
#endif
