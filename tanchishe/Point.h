#pragma once
class Point
{
public:
	Point() :m_x(0), m_y(0) {};
	Point(const int x, const int y) :m_x(x), m_y(y) {};
	void printRect();
	void printCircular();
	void clear();
	void move(const int x, const int y);
	bool operator==(const Point& point)
	{
		return (point.m_x == m_x && point.m_y == m_y);
	}
	int GetX() { return m_x; }
	int GetY() { return m_y; }
private:
	int m_x, m_y;
};
