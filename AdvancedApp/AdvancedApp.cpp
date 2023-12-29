// AdvancedApp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <thread>
#include <future>

std::string promise_string(std::string str)
{
	for (int i = 0; i < 100; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		std::cout << "sleep" << std::endl;
	}
	std::string str1 = "the current function name is ";
	str1.append(__FUNCTION__);
	return str + str1;
}

int main()
{
	std::packaged_task<std::string(std::string)> pTask(promise_string);
	std::future<std::string> fu = pTask.get_future();

	std::thread tr(std::move(pTask),"测试 ");
	std::string strR = fu.get();
	std::cout << "the result is:" << strR.c_str() << std::endl;
	tr.join();
	system("pause");
}