#pragma once

class  HelloWorld;

//!����helloworld���ڴ��ַ

class Control
{
public:


	static   Control*   getInstance();
	static   void       destroy();
	void     init(HelloWorld*);
	HelloWorld*   getScene(){return  ower;}

	~Control(){}
private:

	Control(){}
	static   Control*   instance;
	HelloWorld   *  ower;
};

