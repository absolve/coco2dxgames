#include "GameReady.h"
#include "HelloWorldScene.h"
#include "gameStart.h"
#include "PlayerLayer.h"
#include "EnemyLayer.h"

USING_NS_CC;
GameReady*  GameReady::singleton=NULL;

GameReady*  GameReady::getInstance(){

	if(singleton==NULL){
		singleton =new GameReady;
	}
	return singleton;
}

void        GameReady::destory()
{
	if(singleton!=NULL){
		delete   singleton;
		singleton=NULL;
	}

}

void       GameReady::enter(HelloWorld *s){

	//!��ʾһ��׼���ַ�
	auto    s1=s->getChildByTag(9);
	s1->setVisible(true);
	//!�ָ���ҵĶ���
	auto    player=s->playerlayer;
	auto    plane=player->getPlayer();
	plane->setPosition(240,100);
	plane->resumeSchedulerAndActions();
	plane->getChildByTag(1)->setVisible(false);
	auto    enemy=s->enemylayer;
	//!������еĵл�
	for(auto  i=enemy->enemyNum.begin();i!=enemy->enemyNum.end();++i){
			(*i)->removeFromParent();
	}
	enemy->enemyNum.clear();
	//!������е��ӵ�
	for(auto  i=player->bullets.begin();i!=player->bullets.end();++i){
			(*i)->removeFromParent();
	}
	player->bullets.clear();

}

void	   GameReady::execute(HelloWorld*){


}

void       GameReady::exit(HelloWorld *s){
	auto    s1=s->getChildByTag(9);
	s1->setVisible(false);

}

void	   GameReady::handleEvent(HelloWorld *s){

	s->changeState(GameStart::getInstance());
}



