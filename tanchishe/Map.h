#pragma once
#include <vector>
#include "Point.h"
class Map
{
public:
	Map()  // 将边框正方形压入队列
	{
		vec_map.emplace_back(Point(1, 1));
		vec_map.emplace_back(Point(2, 1));
		vec_map.emplace_back(Point(3, 1));
		vec_map.emplace_back(Point(4, 1));
		vec_map.emplace_back(Point(5, 1));
		vec_map.emplace_back(Point(6, 1));
		vec_map.emplace_back(Point(7, 1));
		vec_map.emplace_back(Point(8, 1));
		vec_map.emplace_back(Point(9, 1));
		vec_map.emplace_back(Point(10, 1));
		vec_map.emplace_back(Point(11, 1));
		vec_map.emplace_back(Point(12, 1));
		vec_map.emplace_back(Point(13, 1));
		vec_map.emplace_back(Point(14, 1));
		vec_map.emplace_back(Point(15, 1));
		vec_map.emplace_back(Point(16, 1));
		vec_map.emplace_back(Point(17, 1));
		vec_map.emplace_back(Point(18, 1));
		vec_map.emplace_back(Point(19, 1));
		vec_map.emplace_back(Point(20, 1));
		vec_map.emplace_back(Point(21, 1));
		vec_map.emplace_back(Point(22, 1));
		vec_map.emplace_back(Point(23, 1));
		vec_map.emplace_back(Point(24, 1));
		vec_map.emplace_back(Point(25, 1));
		vec_map.emplace_back(Point(26, 1));
		vec_map.emplace_back(Point(27, 1));
		vec_map.emplace_back(Point(28, 1));
		vec_map.emplace_back(Point(29, 1));
		vec_map.emplace_back(Point(30, 1));

		vec_map.emplace_back(Point(1, 2));
		vec_map.emplace_back(Point(30, 2));

		vec_map.emplace_back(Point(1, 3));
		vec_map.emplace_back(Point(30, 3));

		vec_map.emplace_back(Point(1, 4));
		vec_map.emplace_back(Point(30, 4));
		
		vec_map.emplace_back(Point(1, 5));
		vec_map.emplace_back(Point(30, 5));

		vec_map.emplace_back(Point(1, 6));
		vec_map.emplace_back(Point(30, 6));
	
		vec_map.emplace_back(Point(1, 7));
		vec_map.emplace_back(Point(30, 7));
	
		vec_map.emplace_back(Point(1, 8));
		vec_map.emplace_back(Point(30, 8));
	
		vec_map.emplace_back(Point(1, 9));
		vec_map.emplace_back(Point(30, 9));

		vec_map.emplace_back(Point(1, 10));
		vec_map.emplace_back(Point(30, 10));

		vec_map.emplace_back(Point(1, 11));
		vec_map.emplace_back(Point(30, 11));

		vec_map.emplace_back(Point(1, 12));
		vec_map.emplace_back(Point(30, 12));

		vec_map.emplace_back(Point(1, 13));
		vec_map.emplace_back(Point(30, 13));

		vec_map.emplace_back(Point(1, 14));
		vec_map.emplace_back(Point(30, 14));

		vec_map.emplace_back(Point(1, 15));
		vec_map.emplace_back(Point(30, 15));

		vec_map.emplace_back(Point(1, 16));
		vec_map.emplace_back(Point(30, 16));

		vec_map.emplace_back(Point(1, 17));
		vec_map.emplace_back(Point(30, 17));

		vec_map.emplace_back(Point(1, 18));
		vec_map.emplace_back(Point(30, 18));

		vec_map.emplace_back(Point(1, 19));
		vec_map.emplace_back(Point(30, 19));

		vec_map.emplace_back(Point(1, 20));
		vec_map.emplace_back(Point(30, 20));

		vec_map.emplace_back(Point(1, 21));
		vec_map.emplace_back(Point(30, 21));

		vec_map.emplace_back(Point(1, 22));
		vec_map.emplace_back(Point(30, 22));

		vec_map.emplace_back(Point(1, 23));
		vec_map.emplace_back(Point(30, 23));

		vec_map.emplace_back(Point(1, 24));
		vec_map.emplace_back(Point(30, 24));

		vec_map.emplace_back(Point(1, 25));
		vec_map.emplace_back(Point(30, 25));

		vec_map.emplace_back(Point(1, 26));
		vec_map.emplace_back(Point(30, 26));

		vec_map.emplace_back(Point(1, 27));
		vec_map.emplace_back(Point(30, 27));

		vec_map.emplace_back(Point(1, 28));
		vec_map.emplace_back(Point(30, 28));

		vec_map.emplace_back(Point(1, 29));
		vec_map.emplace_back(Point(30, 29));

		vec_map.emplace_back(Point(1, 30));
		vec_map.emplace_back(Point(2, 30));
		vec_map.emplace_back(Point(3, 30));
		vec_map.emplace_back(Point(4, 30));
		vec_map.emplace_back(Point(5, 30));
		vec_map.emplace_back(Point(6, 30));
		vec_map.emplace_back(Point(7, 30));
		vec_map.emplace_back(Point(8, 30));
		vec_map.emplace_back(Point(9, 30));
		vec_map.emplace_back(Point(10, 30));
		vec_map.emplace_back(Point(11, 30));
		vec_map.emplace_back(Point(12, 30));
		vec_map.emplace_back(Point(13, 30));
		vec_map.emplace_back(Point(14, 30));
		vec_map.emplace_back(Point(15, 30));
		vec_map.emplace_back(Point(16, 30));
		vec_map.emplace_back(Point(17, 30));
		vec_map.emplace_back(Point(18, 30));
		vec_map.emplace_back(Point(19, 30));
		vec_map.emplace_back(Point(20, 30));
		vec_map.emplace_back(Point(21, 30));
		vec_map.emplace_back(Point(22, 30));
		vec_map.emplace_back(Point(23, 30));
		vec_map.emplace_back(Point(24, 30));
		vec_map.emplace_back(Point(25, 30));
		vec_map.emplace_back(Point(26, 30));
		vec_map.emplace_back(Point(27, 30));
		vec_map.emplace_back(Point(28, 30));
		vec_map.emplace_back(Point(29, 30));
		vec_map.emplace_back(Point(30, 30));
	}
	void printmap(); // 绘制初始地图
private:
	std::vector<Point> vec_map;
};

