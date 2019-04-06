#pragma once
#include "Point.h"
#include "Snake.h"

class Snake; // 短式声明

class Food
{
	friend class Snake;
public:
	Food() :count(0), m_x(0), m_y(0), m_bigx(0), m_bigy(0), m_bar(0), m_flash(false), m_bigflag(false) {}
	void drawfood(Snake& snake);
	void drawbigfood(Snake& snake);
	void bigfoodflash();
	bool getbigflag();
	int changebar();
private:
	int count;
	int m_x, m_y;     // 标准食物坐标
	int m_bigx, m_bigy; // 大食物坐标
	int m_bar;        // 限时食物进度条
	bool m_flash;     // 闪烁标记
	bool m_bigflag; 
};

