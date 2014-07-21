#ifndef __ENEMY_LAYER_H__
#define __ENEMY_LAYER_H__

#include "cocos2d.h"



class EnemyLayer:public  cocos2d::Layer
{
public:
	
	virtual   bool  init();
	CREATE_FUNC(EnemyLayer);

	//!�����������͵ĵ���
	void     createEnemy();
	
	//!���ӿ�ʼʱ��
	void     setTime(float t){startTime=t;}
	float    getTime(){return startTime;}
	void	 addTime(float t) {startTime+=t;}
	bool     onTime() { if(startTime>delayTime) return true;
							else return false;}

public:
	//!�������͵ĵ�������
	cocos2d::Vector<cocos2d::Sprite*> enemyNum;
	static   std::string enemyStyle[3];
	//!�Ѿ������ĵл�������
	cocos2d::Vector<cocos2d::Sprite*>deadEnemy;

private:

	//!ʱ���ӳ�
	float    delayTime;
	//!��ʼʱ��
	float    startTime;

};

#endif