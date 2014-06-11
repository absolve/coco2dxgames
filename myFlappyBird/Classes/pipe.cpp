#include "pipe.h"
#include "HelloWorldScene.h"

pipe*  pipe::instance=NULL;

pipe*  pipe::getInstance(){

	if(instance==NULL){
		instance =new pipe();
	}
	return  instance;

}

void   pipe::destroy(){

	if(instance!=NULL){
		delete  instance;
	}
}

void pipe::createPipeTop(float x,float y,HelloWorld *s){

	//!ˮ�ܵ��ϰ벿��
	auto   pipetop =Sprite::create("images/pipe.png");
	pipetop->setAnchorPoint(Point(0,0));
	pipetop->setPosition(x,y);
	pipetop->setScaleX(2.2);
	pipetop->setScaleY(2.2);
	//�����������ж�С���Ƿ�ɹ�һ��ˮ��
	int    i=1992;
	pipetop->setUserData((void*)i);

	//!ˮ�ܵ�ͷ��
	auto   pipe1=Sprite::create("images/pipetop.png");
	pipe1->setAnchorPoint(Point(0,0));
	pipe1->setScaleX(2.3);
	pipe1->setScaleY(2.3);

	auto  rect=pipe1->getBoundingBox();
	pipe1->setPosition(x-3,y-rect.getMaxY());

	s->addChild(pipetop,1);
	s->addChild(pipe1,1);


	//!��Ӷ���
	auto   move=MoveTo::create(time,Point(-60,y));
	pipetop->runAction(move);
	pipe1->runAction(MoveTo::create(time,Point(-60-3,y-rect.getMaxY())));


	//!��ˮ�ܵ�����������ӵ�������
	s->pipes.push_back(pipetop);
	s->pipes.push_back(pipe1);

	//!������ϵ�ˮ��
	createPipeBottom(x,y-rect.getMaxY()-100,s);

}

void pipe::createPipeBottom(float  x,float y,HelloWorld * s){

	auto   pipebottom =Sprite::create("images/pipe.png");
	pipebottom->setAnchorPoint(Point(0,0));
	pipebottom->setScaleX(2.2);
	pipebottom->setScaleY(2.2);


	auto   pipe1= Sprite::create("images/pipetop.png");
	pipe1->setAnchorPoint(Point(0,0));
	pipe1->setScaleX(2.3);
	pipe1->setScaleY(2.3);

	auto  rect=pipe1->getBoundingBox();
	pipe1->setPosition(x-3,y-rect.getMaxY());

	auto  rect1=pipebottom->getBoundingBox();

	pipebottom->setPosition(x,y-rect.getMaxY()-rect1.getMaxY());


	//!��Ӷ���
	auto   move =MoveTo::create(time,Point(-60,y-rect.getMaxY()-rect1.getMaxY()));
	pipebottom->runAction(move);
	pipe1->runAction(MoveTo::create(time,Point(-60-3,pipe1->getPositionY())));

	//!��ˮ�ܵ�����������ӵ�������
	s->pipes.push_back(pipebottom);
	s->pipes.push_back(pipe1);



	s->addChild(pipebottom,1);
	s->addChild(pipe1,1);

}








