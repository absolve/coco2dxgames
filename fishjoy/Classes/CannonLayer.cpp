#include "CannonLayer.h"
#include "weapon.h"

bool    CannonLayer::init(){

	if(!Layer::init()){
		return  false;
	}


	//!�����̨
	auto    w1=Weapon::create();
	w1->setPosition(460,30);
	this->addChild(w1,1,1);

	return   true;
}












