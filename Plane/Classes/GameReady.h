#ifndef  __GAME_READY_H__
#define  __GAME_READY_H__

#include "State.h"
class    HelloWorld;

//!��Ϸ׼������״̬

class GameReady:public  state<HelloWorld>
{
public:
	
		static  GameReady*   getInstance();
		static  void         destory();
		virtual   ~GameReady(){}

		virtual void   enter(HelloWorld *);
		virtual void   execute(HelloWorld*);
		virtual void   exit(HelloWorld *);
		virtual void   handleEvent(HelloWorld *);


private:

	static  GameReady*  singleton;
	GameReady(){}

};

#endif