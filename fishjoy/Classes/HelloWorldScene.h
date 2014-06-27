#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"


class    PaneLayer;
class    CannonLayer;
class    MenuLayer;

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	//!�¼�����
	bool     touchEvent(cocos2d::Touch *touch,cocos2d::Event * event);
	//!���º���
	void     update(float  dt);
	//!��ͣ��ť�ص�����
	void     pauseCallBack(cocos2d::Ref* pSender);

public:
	MenuLayer*   getMenuLayer(){return  menulayer;}
	PaneLayer*   getPaneLayer(){return  panelayer;}
	CannonLayer* getCannonLayer() {return  cannonlayer;}

private:

	MenuLayer*     menulayer;
	PaneLayer *    panelayer;
	CannonLayer*   cannonlayer;
};

#endif // __HELLOWORLD_SCENE_H__
