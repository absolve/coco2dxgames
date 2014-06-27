#ifndef  __WEAPON_H__
#define  __WEAPON_H__

#include "cocos2d.h"
#include <vector>

//!��̨�ȼ�
enum  _cannon{
	cannon_1=1,
	cannon_2,
	cannon_3,cannon_4,cannon_5,cannon_6,cannon_7,cannon_8
};
//!�ڵ������
enum  _range{
	range_1=1,
	range_2,range_3,range_4,range_5,range_6,range_7
};
//!�ڵ���������
enum  _hit{
	hit_1=10,
	hit_2=15,hit_3=20,hit_4=25,hit_5=30,hit_6=40,
	hit_7=50
};

class   Bullet;

class Weapon:public  cocos2d::Node
{
public:

	//!��ʼ������
	virtual bool init(); 

	//!ӵ��8�в�ͬ����̨
	_cannon   currCannon;
	//!ÿ����̨�����и���
	_range    currRange;
	//!ÿ����̨�����
	_hit	  currHit;
	//!�л���̨
	void      change(int);
	//!��׼
	void      shoot(float,float);

	//!�ڵ�
	Bullet*   b1;

	//!����
	cocos2d::Vector<cocos2d::Sprite *>fishnets;

	//!��������
	void      addFishNet(float,float);

	//!fishnet��������ʱ��
	float    lifetime;
	//!��ײ���
	void      checkColloisn(cocos2d::Sprite*);

	//!���º���
	void      update();
	


	CREATE_FUNC(Weapon);
};

#endif
