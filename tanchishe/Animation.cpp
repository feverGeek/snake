#include "Animation.h"
#include <Windows.h>

void Animation::printtext()
{
	for (auto& Point : vec_startText)
	{
		if (Point.GetX() >= 0)
			Point.printRect();
	}
}

void Animation::cleartext()
{
	for (auto& Point : vec_startText)  // 遍历所有点
	{
		if (Point.GetX() >= 0)
			Point.clear(); // 清除一个点
		Point.move(Point.GetX() + 1, Point.GetY()); // 把点移动一个
	}

}

void Animation::Action()
{
	// 先把完整的蛇打印出来
	for (auto&Point:de_startSnake)
	{
		Point.printRect();
		Sleep(speed);
	}

	// 蛇头从左往右移动
	for (int i = 10; i != 40; ++i)
	{
		int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);
		de_startSnake.emplace_back(Point(i, j));
		de_startSnake.back().printRect();
		de_startSnake.front().clear();
		de_startSnake.pop_front();
		Sleep(speed);
	}

	// 当蛇还没消失或文字没移动到指定位置 
	while (!de_startSnake.empty() || vec_startText.back().GetX() < 33)
	{
		if(!de_startSnake.empty())  // 如果蛇还没有消失，继续移动
		{
			de_startSnake.front().clear();
			de_startSnake.pop_front();
		}
		cleartext();  // 清除已有文字
		printtext();  // 绘制更新位置后的文字
		Sleep(speed);
	}
}
