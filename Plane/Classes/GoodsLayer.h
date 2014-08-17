#ifndef  __GOODS_LAYER_H__
#define  __GOODS_LAYER_H__

#include "cocos2d.h"

class GoodsLayer:public  cocos2d::Layer
{
public:
	
	virtual    bool    init();
	CREATE_FUNC(GoodsLayer);

public:

	//!ը���Ƿ�����
	bool      explosion;
	bool      getIsEexplosion(){return  explosion;}
	void	  setExplosion(bool  e){explosion=e;}
	//!��ը�ص�����
	void      explosionCallBack(cocos2d::Ref* pSender);
	//!��������
	void      createBulletOrBmob();
	//!���º���
	//void      updateTime(float);
	//!�����ӵ�����
	void      changeBulletStyle();
	//!��ȡ��������
	//int       getFlag()  {return flag;}
	//!��ȡ�ӵ�����
	//cocos2d::Sprite*   getDBullet() {return  dBullet;}
	////!��ȡը������
	//cocos2d::Sprite*   getBomb() {return bomb;}
	//!���鶯�������Ļص�����
	//void      CallBack();

private:

	//!�ӵ�����
	//cocos2d::Sprite*   dBullet;
	////!ը������
	//cocos2d::Sprite*   bomb;
	//!ÿ�����߳��ֵ�ʱ��
	//float     time;
	//float     delayTime;
	////!��������0����ը��1�����ӵ�
	//int       flag;


};

#endif