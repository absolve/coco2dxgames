#ifndef   __PLAYER_LAYER_H__
#define   __PLAYER_LAYER_H__

#include "cocos2d.h"

//!��Ҳ�,��ҿɿ��Ƶķɻ�

enum  bulletStyle
{
	_bullet1=1,
	_bullet2
};

class PlayerLayer:public  cocos2d::Layer
{
public:
	
	virtual  bool   init();

	CREATE_FUNC(PlayerLayer);
	//!��ȡ��Ҿ���
	cocos2d::Node*   getPlayer();
	//!�ӵ��ļ���
	cocos2d::Vector<cocos2d::Sprite*> bullets;
	//!����ӵ�
	void     shoot();
	//!�ӵ�����
	bulletStyle   bstyle;
	void		  setBulletStyle(bulletStyle bs){bstyle=bs;}
	//!����ʱ��
	void     update(float);
	//!������ҷɻ�λ��
	void	 setPlanePos(float,float);
	//!��ȡ�ɻ��ľ���
	cocos2d::Rect     getPlaneRect();

private:
	float	time;
	float   delayTime;

};

#endif