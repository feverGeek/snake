#pragma once
#include "Point.h"
#include "Snake.h"

class Snake; // ��ʽ����

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
	int m_x, m_y;     // ��׼ʳ������
	int m_bigx, m_bigy; // ��ʳ������
	int m_bar;        // ��ʱʳ�������
	bool m_flash;     // ��˸���
	bool m_bigflag; 
};

