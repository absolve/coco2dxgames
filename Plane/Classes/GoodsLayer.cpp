#include "GoodsLayer.h"


USING_NS_CC;

bool   GoodsLayer::init(){

	if(!Layer::init()){
		return  false;
	}

	//!���ը����ť
	auto    bomb1=Sprite::createWithSpriteFrameName("bomb.png");
	auto    bomb2=Sprite::createWithSpriteFrameName("bomb.png");
	auto    bombItem=MenuItemSprite::create(bomb1,bomb2,CC_CALLBACK_1(GoodsLayer::explosionCallBack,this));
	bombItem->setPosition(20,400);
	auto    menu=Menu::create(bombItem,NULL);
	//!ը������Ĭ����Ϊ�ر�
	menu->setVisible(false);
	menu->setPosition(Point::ZERO);

	this->addChild(menu,1,1);

	//!���������Ʒ
	//bomb=Sprite::createWithSpriteFrameName("box01.png");
	//bomb->setVisible(false);
	//dBullet=Sprite::createWithSpriteFrameName("box02.png");
	//dBullet->setVisible(false);
	//this->addChild(bomb,1);
	//this->addChild(dBullet,1);
	////!������Ʒ�ı�־
	//flag=0;

	//explosion=false;
	////!��ʼ��ʱ��,������һ�����߳��ֵ�ʱ��100s
	//time=0;
	//delayTime=100;

	return   true;
}


void   GoodsLayer::explosionCallBack(Ref* pSender){

	auto   menu=this->getChildByTag(1);
	menu->setVisible(false);
	setExplosion(true);

}

void   GoodsLayer::changeBulletStyle(){


}

//void   GoodsLayer::updateTime(float dt){
//		time+=dt;
//		if(time>=delayTime){
//			int  i=rand()%100;
//			if(i<=60){
//				//!����һ���ӵ���Ʒ
//				flag=1;
//				dBullet->setPosition(20+rand()%440,840);
//				auto   move1=MoveTo::create(1.5,Point(dBullet->getPositionX(),-40));
//				auto   smove=Sequence::create(move1,
//								CallFunc::create(this,callfunc_selector(GoodsLayer::CallBack)),NULL);
//				dBullet->runAction(smove);
//				dBullet->setVisible(true);
//			}else{
//				//!����һ��ը����Ʒ
//				flag=0;
//				bomb->setPosition(20+rand()%440,840);
//
//
//			}
//		}
//}

//void   GoodsLayer::CallBack(){
//
//	if(flag==1){
//		dBullet->removeAllChildren();
//		dBullet->setVisible(false);
//	}else{
//		bomb->removeAllChildren();
//		bomb->setVisible(false);
//	}
//
//}