#include "Snake.h"
#include "Tools.h"
#include "Food.h"
#include <conio.h> 

void Snake::printinitsnake()
{
	for (auto& Point : list_snake)
	{
		Point.printCircular();
	}
}

void Snake::move()
{
	snakeadd();
	list_snake.front().clear();   // ����һ��β��
	list_snake.pop_front();  // ��β�͵�ջ
}

void Snake::snakeadd()
{
	switch (direction)
	{
	case UP:
		list_snake.emplace_back(Point(list_snake.back().GetX(), list_snake.back().GetY()-1));
		break;
	case DOWN:
		list_snake.emplace_back(Point(list_snake.back().GetX(), list_snake.back().GetY()+1));
		break;
	case LEFT:
		list_snake.emplace_back(Point(list_snake.back().GetX()-1, list_snake.back().GetY()));
		break;
	case RIGHT:
		list_snake.emplace_back(Point(list_snake.back().GetX()+1, list_snake.back().GetY()));
		break;
	}
	setcolor(14);
	list_snake.back().printCircular(); // ��ӡһ���µ�ͷ
}

// Խ�緵��true
bool Snake::overedge()
{
	return !(list_snake.back().GetX() < 30 &&
		list_snake.back().GetY() < 30 &&
		list_snake.back().GetX() > 1 &&
		list_snake.back().GetY() > 1);
}

// ײ�Լ�
bool Snake::eatitself()
{
	size_t count = 1;
	Point* head = new Point(list_snake.back().GetX(), list_snake.back().GetY());
	for (auto& point : list_snake)
	{
		if (!(point == *head))
		{
			count++;
		}
		else
		{
			break;
		}
	}
	delete head;
	if (count == list_snake.size())
	{
		return false;
	}

	return true;
}

// ��ת��
bool Snake::changedirection()
{
	char ch;
	if (_kbhit())
	{
		ch = _getch();
		switch (ch)
		{
		case -32:
			ch = _getch();
			switch (ch)
			{
			case 72: // ��
				if (direction != DOWN)
					direction = UP;
				break;
			case 80: // ��
				if (direction != UP)
					direction = DOWN;
				break;
			case 75: // ��
				if (direction != RIGHT)
					direction = LEFT;
				break;
			case 77: // ��
				if (direction != LEFT)
					direction = RIGHT;
				break;
			default:
				break;
			}
			return true;
		case 27: // ESC
			return false;
		default:
			return true;
		}
	}
	return true;
}

bool Snake::eatfood(const Food& food)
{
	if (list_snake.back().GetX() == food.m_x && list_snake.back().GetY() == food.m_y)
	{
		return true;
	}
	return false;
}

// �Դ�ʳ��
bool Snake::eatbigfood(Food& food)
{
	if (list_snake.back().GetX() == food.m_bigx && list_snake.back().GetY() == food.m_bigy)
	{
		food.m_bigflag = false;
		food.m_bigx = 0;
		food.m_bigy = 0;
		setcursorposition(1, 0);
		cout << "                                             ";
		return true;
	}
	return false;
}
