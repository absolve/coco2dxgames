#pragma once

#include "cocos2d.h"

class Bullet:public  cocos2d::Node
{
public:
	

	virtual bool init(); 
	//!�ڵ�����
	void   fly(float,float,float,float=1.5);
	//!�ڵ����н����ص�����
	void   over();
	CREATE_FUNC(Bullet);

private:
	bool   flyState;
};

