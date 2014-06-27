#ifndef __PANE_LAYER_H__
#define __PANE_LAYER_H__

#include "cocos2d.h"

class PaneLayer:public  cocos2d::Layer
{
public:
	
	virtual   bool    init();
	CREATE_FUNC(PaneLayer);
	//!��ͣ��ť�ص�����
	void    pauseButtonCallBack(cocos2d::Ref* pSender);
	//!������ť�ص�����
	void    cameraButtonCallBack(cocos2d::Ref* pSender);
	//!���ְ�ť�ص�����
	void    musicButtonCallBack(cocos2d::Ref* pSender);
	//!��̨�ȼ����ٻص�����
	void    cannondecCallBack(cocos2d::Ref* pSender);
	//!��̨�ȼ����ӻص�����
	void    cannonaddCallBack(cocos2d::Ref* pSender);


};

#endif