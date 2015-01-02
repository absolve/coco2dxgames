#include "gameEnd.h"
#include "HelloWorldScene.h"
#include "gameReady.h"
#include "bird.h"

gameEnd*  gameEnd::instance=NULL;


gameEnd*  gameEnd::getInstance(){
	if(instance==NULL){
		instance =new gameEnd;
		return  instance;
	}
	return   instance;
}

void     gameEnd::destroy(){
	if(instance!=NULL){
		delete  instance;
		instance=NULL;
	}
}

void   gameEnd::enter(HelloWorld * s){
	auto   fadein =FadeIn::create(0.8f);
	bird::getInstance()->stopAni();
	//!��ʾ��Ϸ����ͼƬ
	auto   s1= dynamic_cast<cocos2d::Sprite*>(s->getChildByTag(3));
	s1->setVisible(true);
	s1->runAction(fadein);
	//!��ʾ��Ϸ�������
	auto   s2= dynamic_cast<cocos2d::Sprite*>(s->getChildByTag(4));
	s2->setVisible(true);
	s2->runAction(fadein->clone());

	auto   m4= dynamic_cast<Menu*>(s->getChildByTag(40));
	//!��ʾ��ť
	auto   m1= dynamic_cast<MenuItemImage*>(m4->getChildByTag(1992));
	m1->setVisible(true);

	//!���ط�����ʾ
	auto   label=dynamic_cast<LabelTTF*> (s->getChildByTag(10));
	label->setVisible(false);

	//!��ʾ������
	auto   label1=dynamic_cast<LabelTTF*>(s->getChildByTag(100));
	sprintf(s->b,"%d",s->score);
	label1->setString(s->b);
	label1->setVisible(true);

	//!��ʾ�����߷ַ���
	auto   label2=dynamic_cast<LabelTTF*>(s->getChildByTag(101));
	label2->setVisible(true);

	if(s->score>s->userScore){
		s->setUserScore();
		auto   ns=dynamic_cast<Sprite*>(label1->getChildByTag(1));
		ns->setVisible(true);
		sprintf(s->c,"%d",s->userScore);
		label2->setString(s->c);
	}
	//!ֹͣ���е�ˮ�ܵĶ���
	for(auto i=s->pipes.begin();i!=s->pipes.end();++i){
		(*i)->stopAllActions();
	}
}

void  gameEnd::execute(HelloWorld* ){

	auto   delay =Director::getInstance()->getDeltaTime();
	auto   ypos=bird::getInstance()->getYpos();
	if(ypos>=160){
		bird::getInstance()->update(delay);
	}
}

void   gameEnd::exit(HelloWorld * s){

	//!���С��
	bird::getInstance()->removeBird();

	//!������Ϸ����ͼƬ
	auto   s1= dynamic_cast<cocos2d::Sprite*>(s->getChildByTag(3));
	s1->setVisible(false);
	s1->removeAllChildren();
	s1->setOpacity(0.0f);

	//!������Ϸ������
	auto   s2= dynamic_cast<cocos2d::Sprite*>(s->getChildByTag(4));
	s2->setVisible(false);
	s2->removeAllChildren();
	s2->setOpacity(0.0f);

	//!���ذ�ť
	auto   m4= dynamic_cast<Menu*>(s->getChildByTag(40));
	auto   m1= dynamic_cast<MenuItemImage*>(m4->getChildByTag(1992));
	m1->setVisible(false);

	//!����������
	auto   label1=dynamic_cast<LabelTTF*>(s->getChildByTag(100));
	label1->setVisible(false);
	
	//!������Ϸ��߷ֱ�־
	auto   ns=dynamic_cast<Sprite*>(label1->getChildByTag(1));
	ns->setVisible(false);

	//!���������߷ַ���
	auto   label2=dynamic_cast<LabelTTF*>(s->getChildByTag(101));
	label2->setVisible(false);

	//!����Ϸ�������뵽��Ϸ���
	auto   gold=dynamic_cast<LabelTTF*>(s->getChildByTag(25));
	s->gameGold+=s->score;
	sprintf(s->d,"%d",s->gameGold);
	gold->setString(s->d);

	//!�������
	s->score=0;
	sprintf(s->a,"scores:%d",s->score);
	auto  label=dynamic_cast<LabelTTF*>(s->getChildByTag(10));
	label->setString(s->a);
	label->setVisible(true);
	//!������е�ˮ��
	for(auto  i=s->pipes.begin();i!=s->pipes.end();++i){
		(*i)->removeFromParent();
	}
	s->pipes.clear();
	//!�ӳ�ˮ�ܳ���ʱ��
	s->_time=-1.0f;
}

void   gameEnd::handleEvent(HelloWorld *){
}







