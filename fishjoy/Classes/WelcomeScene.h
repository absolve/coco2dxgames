#ifndef  __WELCOME_SCENCE_H__
#define  __WELCOME_SCENCE_H__

#include "cocos2d.h"

class WelcomeScence:public cocos2d::Layer
{
public:
	

	static    cocos2d::Scene*   createScene();

	virtual   bool   init();
	CREATE_FUNC(WelcomeScence);
	//!��ʼ��ť�ص�����
	void      startButtonCallBack(cocos2d::Ref* pSender);
	//!�����л���ť
	void      selectButtonCallBack(cocos2d::Ref* pSender);
	//!�رհ�ť
	void menuCloseCallback(cocos2d::Ref* pSender);

};

#endif