#include "Food.h"
#include "Tools.h"


void Food::drawfood(Snake& snake)
{
	// 随机生成坐标, 范围限制2-29,每5个正常食物出现1个限时食物
	while (true)
	{
		int tmp_x = rand() % 27 + 2;
		int tmp_y = rand() % 27 + 2;
		m_x = tmp_x;
		m_y = tmp_y;
		for (auto&Point : snake.list_snake)
		{
			if ((Point.GetX() == tmp_x && Point.GetY() == tmp_y) || tmp_x == m_bigx && tmp_y == m_bigy)
			{
				continue;
			}
		}

		setcursorposition(m_x, m_y);
		setcolor(13);
		cout << "★";
		++count;
		if (!(count % 5))
		{
			drawbigfood(snake);
		}
		break;
	}
}

void Food::drawbigfood(Snake& snake)
{
	setcursorposition(5, 0);
	setcolor(11);
	cout << "-----------------------------------------"; // 进度条
	m_bar = 42;
	while (true)
	{
		int tmp_x = rand() % 27 + 2;
		int tmp_y = rand() % 27 + 2;
		for (auto&Point : snake.list_snake)
		{
			if ((Point.GetX() == tmp_x && Point.GetY() == tmp_y) || tmp_x == m_x && tmp_y == m_y)
			{
				continue;
			}
		}

		m_bigx = tmp_x;
		m_bigy = tmp_y;
		setcursorposition(m_bigx, m_bigy);
		setcolor(18);
		cout << "■";
		m_flash = true;
		m_bigflag = true;
		break;
	}
}

void Food::bigfoodflash()
{
	setcursorposition(m_bigx, m_bigy);
	if (m_flash)
	{
		cout << "  ";
		m_flash = false;
	}
	else
	{
		cout << "■";
		m_flash = true;
	}

	setcursorposition(26, 0);
	setcolor(11);
	for (int i = 42; i >= m_bar; --i) // 进度条缩短
	{
		cout << "\b \b";
	}
	--m_bar;
	if (0 == m_bar)
	{
		setcursorposition(m_bigx, m_bigy);
		cout << "  ";
		m_bigflag = false;
		m_bigx = 0;
		m_bigy = 0;
	}
}

bool Food::getbigflag()
{
	return m_bigflag;
}
