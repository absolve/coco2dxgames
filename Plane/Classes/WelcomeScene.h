#ifndef __WELCOME_SCENE_H__
#define __WELCOME_SCENE_H__

#include "cocos2d.h"

class WelcomeScene:public  cocos2d::Layer
{
public:
	
	static cocos2d::Scene* createScene();
	//!��ʼ������
	virtual bool  init();
	CREATE_FUNC(WelcomeScene);
	//!��ʱ������
	void    update(float  dt);
	//!�˵��ص�����
	void    nextSceneCallBack(cocos2d::Ref* pSender);
	//!�˳���ť�ص��¼�
	void    closeCallBack(cocos2d::Ref* pSender);



};

#endif