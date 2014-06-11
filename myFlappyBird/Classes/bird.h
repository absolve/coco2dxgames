#ifndef  __BIRD_H__
#define  __BIRD_H__

#include "cocos2d.h"
USING_NS_CC;

class  HelloWorld;

class bird
{
public:
	
	static  bird*   getInstance();
	static  void    destory();
	void	        createBird(float,float,HelloWorld *);
	virtual  ~bird(){}
	//!���º���
	void    update(float  dt);
	//!С�����
	void    fly(float);
	//!���÷��г��ٶ�
	void    setFlySpeed(float  s)  {flySpeed=s;}
	//!�Ƴ�С��
	void    removeBird();
	//!��ȡС���y����
	float   getYpos() ;
	//!����ֹͣ
	void    stopAni();
	//!��ȡС��ľ��δ�С
	Rect    getRect();




	CC_SYNTHESIZE(bool,isflying,flying)


private:

	bird();
	static  bird*   instance;
	//!������С����ָ��
	Sprite  *   pbird;
	//!���ٶ�
	float    aspeed;
	//!���г��ٶ�
	float    flySpeed;
	//!��ת�Ƕ�
	float    rotation;

};

#endif // !1