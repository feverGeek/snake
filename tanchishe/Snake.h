#pragma once
#include "Point.h"
#include "Food.h"
#include <list>

class Snake
{
	friend class Food;
public:
	enum Direction{UP, DOWN, LEFT, RIGHT};
	Snake()
	{
		list_snake.emplace_back(14, 8);
		list_snake.emplace_back(15, 8);
		list_snake.emplace_back(16, 8);
		direction = DOWN;
	}
	void printinitsnake();
	void move();
	void snakeadd();  // ������
	bool overedge();
	bool eatitself();
	bool changedirection();
	bool eatfood(const Food&);
	bool eatbigfood(Food&);
private:
	std::list<Point> list_snake;  // ��
	Direction direction;     // ��ǰ����
};

