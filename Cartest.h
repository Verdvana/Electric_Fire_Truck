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
void SetSpeed(char dir,unsigned int value);   //////////dir ����ѡ���������  speed ѡ���ٶ�  speed>0 ����  speed<0 ���� speedԽ�� ת�پ���ֵԽ�� (-255~+255)
void Delayms(unsigned int n);
#endif
