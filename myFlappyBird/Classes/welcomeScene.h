#ifndef __WELCOME_SCENE_H__
#define __WELCOME_SCENE_H__

#include "cocos2d.h"
//!��Ϸ��ӭ����

class welcomeScene: public cocos2d::Layer
{
public:	
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(welcomeScene);
public:
	void menuCloseCallback(cocos2d::Ref* pSender);
	//!��ʼ��Ϸ��ť
	void gameStartCallBack(cocos2d::Ref* pSender);
	//!������Ϸ����
	void gameOptionCallBack(cocos2d::Ref* pSender);
	//!����¼�
	bool   touchEvent(cocos2d::Touch *touch,cocos2d::Event * event);
};

#endif // !1