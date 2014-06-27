#include "WelcomeScene.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Scene*  WelcomeScence::createScene(){

	auto   scene =Scene::create();
	auto   layer =WelcomeScence::create();
	scene->addChild(layer);

	return  scene;
}


bool    WelcomeScence::init(){

	if(!Layer::init()){
		return false;
	}

	
	//!�����Ϸlogo
	auto   logo=Sprite::create("images/logo.png");
	logo->setPosition(480,440);
	this->addChild(logo,1);

	//!�������ϵͳ
	auto    fires=ParticleFire::create();
	auto    texture=Director::getInstance()->getTextureCache();
	fires->setTexture(texture->addImage("hole_stencil.png"));
	fires->setPosition(480,380);

	this->addChild(fires,1);

	auto    snow=ParticleSnow::create();
	snow->setTexture(texture->addImage("stars.png"));
	snow->setPosition(480,540);
	this->addChild(snow,2);

	//!��Ϸ��ʼ�˵���ť
	auto  startButton1=Sprite::create("UI_GameStart_01.png");
	auto  startButton2=Sprite::create("UI_GameStart_02.png");
	auto  startButton=MenuItemSprite::create(startButton1,startButton2,
		CC_CALLBACK_1(WelcomeScence::startButtonCallBack,this));
	
	auto  sprite1=Sprite::create("images/UI_Game_01.png");
	sprite1->setScale(0.7);
	sprite1->setAnchorPoint(Point(-0.5,-0.7));
	startButton->addChild(sprite1,1);

	//!��Ϸ����ѡ��ť
	auto  selectButton1=Sprite::create("UI_SceneChange_01.png");
	auto  selectButton2=Sprite::create("UI_SceneChange_02.png");
	auto  selectButton=MenuItemSprite::create(selectButton1,selectButton2,
		CC_CALLBACK_1(WelcomeScence::selectButtonCallBack,this));
	
	auto  sprite2=Sprite::create("images/UI_Game_02.png");
	sprite2->setScale(0.7);
	sprite2->setAnchorPoint(Point(-0.18,-0.2));
	selectButton->addChild(sprite2,1);

	//!��ӹرհ�ť
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(WelcomeScence::menuCloseCallback, this));
	auto  menu1=Menu::create(closeItem,NULL);
	menu1->setPosition(940,20);
	this->addChild(menu1,3);

	//!��Ӳ˵���
	auto  menu =Menu::create(startButton,selectButton,NULL);
	menu->setPosition(480,200);
	menu->alignItemsVerticallyWithPadding(2);
	this->addChild(menu,2);

	//!��ӱ���
	auto   bd=Sprite::create("background.png");
	bd->setPosition(480,270);
	this->addChild(bd);

	return   true;
}

void   WelcomeScence::startButtonCallBack(Ref* pSender){

	/*log("hello");*/
	Director::getInstance()->replaceScene(TransitionFade::create(1.0,
		HelloWorld::createScene()));

}

void   WelcomeScence::selectButtonCallBack(Ref* pSender){

	/*log("hello");*/
}

void WelcomeScence::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}


