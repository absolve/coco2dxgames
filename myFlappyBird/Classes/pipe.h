#ifndef   __PIPE_H__
#define   __PIPE_H__

#include "CCSprite.h"

USING_NS_CC;

class  HelloWorld;
//!����ˮ����

class pipe 
{
public:
		 static  pipe*   getInstance() ;
		 static  void    destroy();

		 //!����һ��ˮ��
		 //!������ˮ��
	     void createPipeTop(float,float,HelloWorld*);
		 //!������ˮ��
		 void createPipeBottom(float,float,HelloWorld*);

private:
		   pipe(){ time=3.5f;   }
		   static   pipe*  instance;
		   //!ˮ���ƶ���ʱ��
		   float    time;
};

#endif