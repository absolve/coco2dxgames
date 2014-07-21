#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "State.h"
class   PlayerLayer;
class   EnemyLayer;
class   GoodsLayer;



class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
	//!���º���
	void		update(float  dt);
	//!�Ӵ���ʼ�¼�
	bool        touchBegin(cocos2d::Touch *touch,cocos2d::Event * event);
	//!�϶��¼�
	void		touchMove(cocos2d::Touch *touch,cocos2d::Event * event);
	//!�Ӵ������¼�
	void		touchEnd(cocos2d::Touch *touch,cocos2d::Event * event);
	//״̬���л�
	void		changeState(state<HelloWorld>  *);
	//!���·�����ʾ
	void		updateScore();
	//!�������÷�
	void		updateLastScore();
	//!������߷�
	void		updateHighScore();
	//!���¿�ʼ�ص�����
	void        restartCallBack(cocos2d::Ref* pSender);
	//!��ʼ����Ϸ׷��÷ְ�
	void        initScoreLayer();
	//!�����û��߷�����
	void        saveHighScore();
	//!��ȡ��߷�����
	int         getHighScore();
	//!��������ͼ
	void        updateBackGround();
public:

	PlayerLayer   *		playerlayer;
	EnemyLayer	  *		enemylayer;
	GoodsLayer	  *		goodslayer;
	cocos2d::LayerColor	  *fscore;

	state<HelloWorld>  *currState;
	//!��Ϸ����
	int    scores;
	//!��߷�
	int    highScore;
	int    getHS()  {return highScore;}
	//!�����ַ���
	char   a[20];
	//!��߷����ַ���
	char   hs[20];
	void   setScore(int  s)  {scores=s;}
	int	   getScore(){return  scores;}
	void   scorePlus() {scores++;}
	//!��ȡ�Ӵ��ĳ�ʼ����
	cocos2d::Point      point;
	//!ƫ����x,y
	float				XOffset;
	float				YOffset;
	//!��Ϸ����
	cocos2d::Rect		gameWin;

};

#endif // __HELLOWORLD_SCENE_H__
