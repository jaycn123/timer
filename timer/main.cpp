// timer.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "timer.h"
#include <iostream>

#define CHECKTIMER TimerManager::GetInstancePtr()->checkTimer()

struct A
{
	void fun1()
	{
		std::cout << "fun1 : " << m_count-- << std::endl;
	}
	int32_t m_count = 100;

	void onTimer()
	{
		std::cout << "onTimer : "  << std::endl;
	}
	void onTimer2()
	{
		std::cout << "onTimer2333 : "  << std::endl;
	}
};
int main()
{
	A a;
	TimerManager::GetInstancePtr()->addTimer(NowTime + 1,std::bind(&A::onTimer, &a),0,3,3);

	TimerManager::GetInstancePtr()->addTimer(NowTime + 2, std::bind(&A::onTimer2, &a), 0, 5, 3);

	while (1)
	{
		CHECKTIMER;
	}

	return 0;
}

