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
	for (auto& Point : vec_startText)  // �������е�
	{
		if (Point.GetX() >= 0)
			Point.clear(); // ���һ����
		Point.move(Point.GetX() + 1, Point.GetY()); // �ѵ��ƶ�һ��
	}

}

void Animation::Action()
{
	// �Ȱ��������ߴ�ӡ����
	for (auto&Point:de_startSnake)
	{
		Point.printRect();
		Sleep(speed);
	}

	// ��ͷ���������ƶ�
	for (int i = 10; i != 40; ++i)
	{
		int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);
		de_startSnake.emplace_back(Point(i, j));
		de_startSnake.back().printRect();
		de_startSnake.front().clear();
		de_startSnake.pop_front();
		Sleep(speed);
	}

	// ���߻�û��ʧ������û�ƶ���ָ��λ�� 
	while (!de_startSnake.empty() || vec_startText.back().GetX() < 33)
	{
		if(!de_startSnake.empty())  // ����߻�û����ʧ�������ƶ�
		{
			de_startSnake.front().clear();
			de_startSnake.pop_front();
		}
		cleartext();  // �����������
		printtext();  // ���Ƹ���λ�ú������
		Sleep(speed);
	}
}
