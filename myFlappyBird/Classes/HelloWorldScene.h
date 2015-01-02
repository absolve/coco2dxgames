#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include <vector>
#include "state.h"

using namespace std;


//!��Ϸ��ʼ����

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
	//!���¿�ʼ�ص�����
	void restartCallBack(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	//!��ײ���
	void   checkCollision();

	//!����¼�
	bool   touchEvent(cocos2d::Touch *touch,cocos2d::Event * event);
	//!״̬�л�
	void   changeState(state<HelloWorld> *);
public:
	//���º���
	void    update(float  dt);
	//!�洢ˮ�ܵ�����
	vector<cocos2d::Sprite*> pipes;
	//!��Ϸ���е�ʱ��
	float    _time;
	//!��Ϸ����
	int    score;
	//!��Ϸ��߷�
	int    userScore;
	//!��Ϸ���
	int    gameGold;
	//!��Ϸ�����ַ���
	char     a[20];
	//!��Ϸ�������ַ���
	char     b[10];
	//!��Ϸ�����߷��ַ���
	char     c[10];
	//!��Ϸ��������ַ���
	char     d[10];
	//!��ȡ��Ϸ��߷���
	void     getUserScore();
	//!д����Ϸ��߷���
	void     setUserScore();
private:
	//!��Ϸ�еĵ�ǰ״̬
	state<HelloWorld> * currState;
};

#endif // __HELLOWORLD_SCENE_H__
