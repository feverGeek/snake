#include "Point.h"
#include "Tools.h"

void Point::printRect()
{
	setcursorposition(m_x, m_y);
	cout << "¡ö";
}

void Point::printCircular()
{
	setcursorposition(m_x, m_y);
	cout << "¡ñ";
}

void Point::clear()
{
	setcursorposition(m_x, m_y);
	cout << " ";
}

void Point::move(const int x, const int y)
{
	m_x = x;
	m_y = y;
}
