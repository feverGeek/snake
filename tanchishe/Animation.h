#pragma once
#include <deque>
#include <vector>
#include "Point.h"
class Animation
{
public:
	Animation() :speed(35)
	{
		// 蛇
		de_startSnake.emplace_back(Point(0, 14));
		de_startSnake.emplace_back(Point(1, 14));
		de_startSnake.emplace_back(Point(2, 15));
		de_startSnake.emplace_back(Point(3, 16));
		de_startSnake.emplace_back(Point(4, 17));
		de_startSnake.emplace_back(Point(5, 18));
		de_startSnake.emplace_back(Point(6, 17));
		de_startSnake.emplace_back(Point(7, 16));
		de_startSnake.emplace_back(Point(8, 15));
		de_startSnake.emplace_back(Point(9, 14));
		
		// 文字
		vec_startText.emplace_back(Point(-26, 14)); // S
		vec_startText.emplace_back(Point(-25, 14)); 
		vec_startText.emplace_back(Point(-27, 15)); 
		vec_startText.emplace_back(Point(-26, 16)); 
		vec_startText.emplace_back(Point(-25, 17)); 
		vec_startText.emplace_back(Point(-27, 18)); 
		vec_startText.emplace_back(Point(-26, 18)); 

		vec_startText.emplace_back(Point(-23, 14)); // N
		vec_startText.emplace_back(Point(-23, 15)); 
		vec_startText.emplace_back(Point(-23, 16)); 
		vec_startText.emplace_back(Point(-23, 17)); 
		vec_startText.emplace_back(Point(-23, 18)); 
		vec_startText.emplace_back(Point(-22, 15)); 
		vec_startText.emplace_back(Point(-21, 16)); 
		vec_startText.emplace_back(Point(-20, 17)); 
		vec_startText.emplace_back(Point(-19, 14)); 
		vec_startText.emplace_back(Point(-19, 15)); 
		vec_startText.emplace_back(Point(-19, 16)); 
		vec_startText.emplace_back(Point(-19, 17)); 
		vec_startText.emplace_back(Point(-19, 18)); 

		vec_startText.emplace_back(Point(-17, 18)); // A
		vec_startText.emplace_back(Point(-16, 17)); 
		vec_startText.emplace_back(Point(-15, 16)); 
		vec_startText.emplace_back(Point(-14, 15)); 
		vec_startText.emplace_back(Point(-14, 16)); 
		vec_startText.emplace_back(Point(-13, 14)); 
		vec_startText.emplace_back(Point(-13, 16)); 
		vec_startText.emplace_back(Point(-12, 15)); 
		vec_startText.emplace_back(Point(-12, 16)); 
		vec_startText.emplace_back(Point(-11, 16)); 
		vec_startText.emplace_back(Point(-10, 17)); 
		vec_startText.emplace_back(Point(-9, 18)); 

		vec_startText.emplace_back(Point(-7, 14)); // K
		vec_startText.emplace_back(Point(-7, 15)); 
		vec_startText.emplace_back(Point(-7, 16)); 
		vec_startText.emplace_back(Point(-7, 17)); 
		vec_startText.emplace_back(Point(-7, 18)); 
		vec_startText.emplace_back(Point(-6, 16)); 
		vec_startText.emplace_back(Point(-5, 15)); 
		vec_startText.emplace_back(Point(-5, 17)); 
		vec_startText.emplace_back(Point(-4, 14)); 
		vec_startText.emplace_back(Point(-4, 18)); 

		vec_startText.emplace_back(Point(-2, 14)); // E
		vec_startText.emplace_back(Point(-2, 15)); 
		vec_startText.emplace_back(Point(-2, 16)); 
		vec_startText.emplace_back(Point(-2, 17)); 
		vec_startText.emplace_back(Point(-2, 18)); 
		vec_startText.emplace_back(Point(-1, 14)); 
		vec_startText.emplace_back(Point(-1, 16)); 
		vec_startText.emplace_back(Point(-1, 18)); 
		vec_startText.emplace_back(Point(0, 14)); 
		vec_startText.emplace_back(Point(0, 16)); 
		vec_startText.emplace_back(Point(0, 18)); 
	}

	void printtext();
	void cleartext();
	void Action();
private:
	std::deque<Point> de_startSnake;    //开始动画中的蛇
	std::vector<Point> vec_startText;	// 开始动画中的字
	int speed; // 动画速度
};

