#include "gameStart.h"
#include "HelloWorldScene.h"
#include "PlayerLayer.h"
#include "EnemyLayer.h"
#include "GameOver.h"
#include "GoodsLayer.h"

USING_NS_CC;

GameStart*   GameStart::singleton=NULL;

GameStart*   GameStart::getInstance(){

		if(singleton==NULL){

			singleton=new GameStart;
		}
		return  singleton;
}

void        GameStart::destory(){

		if(singleton!=NULL){
			delete  singleton;
			singleton=NULL;
		}
		
}

void		GameStart::enter(HelloWorld *s){


}

void		GameStart::execute(HelloWorld* s){

	//!���������Ļ���ӵ�
	auto    layer=s->playerlayer;
	for(auto  i=layer->bullets.begin();i!=layer->bullets.end();){
			if((*i)->getPositionY()>810){
				(*i)->removeFromParent();
				i=layer->bullets.erase(i);
			}else{

				i++;
			}
	}
	//!���������Ļ�ĵл�
	auto    layer1=s->enemylayer;
	for(auto i=layer1->enemyNum.begin();i!=layer1->enemyNum.end();){
		if((*i)->getPositionY()<-15){
			(*i)->removeFromParent();
			i=layer1->enemyNum.erase(i);
		}else{
			i++;
		}
	}
	//!��������ֵ������������л�
	for(auto  i=layer1->deadEnemy.begin();i!=layer1->deadEnemy.end();){
			auto  life=(int)(*i)->getUserData();
			if(life<0){
				(*i)->removeFromParent();
				i=layer1->deadEnemy.erase(i);
			}else{
				i++;
			}
	}
	//!��������ͼƬ
	s->updateBackGround();
	////
	layer1->addTime(Director::getInstance()->getDeltaTime());
	//!��ӵл�
	if(layer1->onTime()){
		layer1->createEnemy();
		layer1->setTime(0);
	}

	//!���ը���Ƿ�����
	auto   goodslayer=s->goodslayer;
	if(goodslayer->getIsEexplosion()){
		//!�������б�����ĵл�����
		int score1=0;
		for(auto i=layer1->enemyNum.begin();i!=layer1->enemyNum.end();){
					auto  point1=(*i)->getPositionY();
					if(point1<800){
						int  life=(int)(*i)->getUserData();
						score1+=life;
						//!���������л���ʧʱ��
						life=50;
						(*i)->setUserData((void*)life);
						(*i)->stopAllActions();
						(*i)->getChildByTag(1)->setVisible(true);
						//!�������ĵл��ŵ�����������
						layer1->deadEnemy.pushBack(*i);
						i=layer1->enemyNum.erase(i);
					}else{
						i++;
					}
		}
		score1+=s->getScore();
		s->setScore(score1);
		goodslayer->setExplosion(false);
	}

	//!����ӵ�
	layer->update(Director::getInstance()->getDeltaTime());
	/////////////////////////////////////////////////////
	////////////////////////////////////////////////////
	//!��ײ���
	//���ж�����Ƿ���л���ײ
	auto     es=layer1->enemyNum;
	for(auto  i=es.begin();i!=es.end();++i){
		  auto  rect1=(*i)->getBoundingBox();
		  auto  rect2=layer->getPlaneRect();
		  if(rect1.intersectsRect(rect2)){
			  //!��ת����Ϸ����״̬
			  layer->getPlayer()->getChildByTag(1)->setVisible(true);
			  s->changeState(GameOver::getInstance());
			  return;
		  }

	}
	//!�ӵ���л�����ײ���
	for(auto  i=layer1->enemyNum.begin();i!=layer1->enemyNum.end();++i){
		for(auto y=layer->bullets.begin();y!=layer->bullets.end();){
				auto   rect1=(*i)->getBoundingBox();
				auto   rect2=(*y)->getBoundingBox();
				int    life=(int)(*i)->getUserData();
				if(rect1.intersectsRect(rect2)){
					(*y)->removeFromParent();
					y=layer->bullets.erase(y);
					life--;
					(*i)->setUserData((void*)life);
					s->scorePlus();
					s->updateScore();
				}else{
					y++;
				}

		}
	}
	//!������ֵΪ0�ĵл���ӵ������б���
	for(auto i=layer1->enemyNum.begin();i!=layer1->enemyNum.end();){
			int   life=(int)(*i)->getUserData();
			if(life<=0){
				life=50;
				(*i)->stopAllActions();
				(*i)->setUserData((void*)life);
				(*i)->getChildByTag(1)->setVisible(true);
				layer1->deadEnemy.pushBack(*i);
				i=layer1->enemyNum.erase(i);
			}else{
				i++;
			}
	}
	//!�������������ĵл�����
	for (auto i=layer1->deadEnemy.begin();i!=layer1->deadEnemy.end();++i){
				int  life=(int)(*i)->getUserData();
				life--;
				(*i)->setUserData((void*)life);
	}
}

void		GameStart::exit(HelloWorld * s){

	  //!��ͣ��Ҳ�Ķ�ʱ��,ֹͣ���еĵл�����,���ص�ǰ����
	  auto   player=s->playerlayer;
	  //!������е��ӵ�
	  for(auto i=player->bullets.begin();i!=player->bullets.end();++i){
		  (*i)->pauseSchedulerAndActions();
	  }
	  //!ֹͣ�ɻ��Ķ���
	  auto  s1=player->getPlayer();
	  s1->pauseSchedulerAndActions();
	  auto	 enemy=s->enemylayer;
	  for(auto  i=enemy->enemyNum.begin();i!=enemy->enemyNum.end();++i){
			(*i)->pauseSchedulerAndActions();
	  }
	  for(auto  i=enemy->deadEnemy.begin();i!=enemy->deadEnemy.end();++i){
			(*i)->removeFromParent();	
	  }
	  enemy->deadEnemy.clear();

}

void		GameStart::handleEvent(HelloWorld * s){

		auto   playerlayer1=s->playerlayer;
		auto   sprite=playerlayer1->getPlayer();
		auto   playerSprite=dynamic_cast<Sprite*>(sprite);
		//!��ȡ���겢�ж��Ƿ񳬳���Ļ
		auto   point1=playerSprite->getPosition();

		if(point1.x+s->XOffset<0 || point1.x+s->XOffset>480 
			|| point1.y+s->YOffset<0 || point1.y+s->YOffset>800){
				return;
		}
		point1.x+=s->XOffset;
		point1.y+=s->YOffset;
		playerSprite->setPosition(point1);

}