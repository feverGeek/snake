#include <Windows.h>
#include "Controller.h"
#include "Tools.h"
#include <iostream>
#include <conio.h>
#include "Animation.h"
#include "Map.h"
#include "Snake.h"
#include "Food.h"
#include "time.h"

using namespace std;

// ��ʼ
void Controller::startgame()
{
	start(); // ��ʼ����
	
	while (true)
	{
		select(); // ѡ�����
		drawgame(); // ������Ϸ����
		//TODO: ��Ϸѭ�� ֱ���˳�
		if (playgame())
		{
			system("cls");
			continue;
		}
		break;
		system("pause");
		/*break;*/
	}
}

// ��ʼ��Ϸ����
void Controller::start()
{
	setwindowsize(41, 32);
	setcolor(2);
	hidecursor();

	// ��ʼ����
	Animation* act = new Animation;
	act->Action();
	delete act;

	setcursorposition(13, 26);
	cout << "Press any key to start...";
	setcursorposition(13, 27);
	cout << "�����������...";

}

// ѡ���Ѷ�
void Controller::select()
{
	/* ��ʼ�������ѡ�� */
	setcolor(3);
	setcursorposition(13, 26);
	cout << "                                     ";
	setcursorposition(13, 27);
	cout << "                                     ";
	setcursorposition(6, 21);
	cout << "��ѡ����Ϸ�Ѷ�";
	setcursorposition(6, 22);
	cout << "(���¼�ѡ��,�س�ȷ��)";
	setcursorposition(27, 22);
	setbackground();// ��һ��ѡ�����ñ���ɫ�Ա�ʾ��ǰѡ��
	cout << "��ģʽ";
	setcursorposition(27, 24);
	setcolor(3);
	cout << "��ͨģʽ";
	setcursorposition(27, 26);
	cout << "����ģʽ";
	setcursorposition(27, 28);
	cout << "����ģʽ";
	setcursorposition(0, 31);

	level = 1;
	score = 0;
	// ���·����ѡ���Ѷ�
	int ch;  // ��¼����ֵ
	bool flag = false; // ��¼�Ƿ���enter��
	while (ch = _getch())
	{
		switch (ch)
		{
		case 72:  // ��
			if (level)
			{
				switch (level)
				{
				case 2:
					setcursorposition(27, 22); // ����ѡ�������ñ���ɫ
					setbackground();
					cout << "��ģʽ";

					setcursorposition(27, 24); // ����ѡ�е�ѡ��ȡ������ɫ
					setcolor(3);
					cout << "��ͨģʽ";
					--level;
					break;
				case 3:
					setcursorposition(27, 24); // ����ѡ�������ñ���ɫ
					setbackground();
					cout << "��ͨģʽ";

					setcursorposition(27, 26); // ����ѡ�е�ѡ��ȡ������ɫ
					setcolor(3);
					cout << "����ģʽ";
					--level;
					break;
				case 4:
					setcursorposition(27, 26); // ����ѡ�������ñ���ɫ
					setbackground();
					cout << "����ģʽ";

					setcursorposition(27, 28); // ����ѡ�е�ѡ��ȡ������ɫ
					setcolor(3);
					cout << "����ģʽ";
					--level;
					break;
				}
			}
			break;
		case 80:  // ��
			if (level < 4)
			{
				switch (level)
				{
				case 1:
					setcursorposition(27, 24); // ����ѡ�������ñ���ɫ
					setbackground();
					cout << "��ͨģʽ";

					setcursorposition(27, 22); // ����ѡ�е�ѡ��ȡ������ɫ
					setcolor(3);
					cout << "��ģʽ";
					++level;
					break;
				case 2:
					setcursorposition(27, 26); // ����ѡ�������ñ���ɫ
					setbackground();
					cout << "����ģʽ";

					setcursorposition(27, 24); // ����ѡ�е�ѡ��ȡ������ɫ
					setcolor(3);
					cout << "��ͨģʽ";
					++level;
					break;
				case 3:
					setcursorposition(27, 28); // ����ѡ�������ñ���ɫ
					setbackground();
					cout << "����ģʽ";
					
					setcursorposition(27, 26); // ����ѡ�е�ѡ��ȡ������ɫ
					setcolor(3);
					cout << "����ģʽ";
					++level;	
					break;
				}
			}
			break;
		case 13:  // enter 
			flag = true;
			break;
		default:  // ������������������
			break;
		}

		if (flag) break;   // ����enter���˳����ѭ��
	}

	switch (level)
	{
	case 1: // ��ģʽ
		speed = 135;
		break;
	case 2: // ��ͨģʽ
		speed = 100;
		break;
	case 3: // ����ģʽ
		speed = 60;
		break;
	case 4: // ����ģʽ
		speed = 30;
		break;
	}
}

// ����ͼ
void Controller::drawgame()
{
	system("cls");
	
	// ����ͼ 
	setcolor(3);
	Map* initMap = new Map;
	initMap->printmap();
	delete initMap;

	// �����
	setcolor(3);
	setcursorposition(33, 1);
	cout << "Greedy Snake";
	setcursorposition(34, 2);
	cout << "̰����";
	setcursorposition(31, 4);
	cout << "�Ѷ�:";
	setcursorposition(36, 5);
	switch (level)
	{
	case 1:
		cout << "��ģʽ";
		break;
	case 2:
		cout << "��ͨģʽ";
		break;
	case 3:
		cout << "����ģʽ";
		break;
	case 4:
		cout << "����ģʽ";
		break;
	}
	setcursorposition(31, 7);
	cout << "�÷�:";
	setcursorposition(37, 8);
	cout << "     0";
	setcursorposition(34, 13);
	cout << " ������ƶ�";
	setcursorposition(34, 15);
	cout << " ESC����ͣ";
}

// ����Ϸ
bool Controller::playgame()
{
	// ��ʼ���ߺ�ʳ�� 
	Snake* psnake = new Snake();
	Food* pfood = new Food();

	setcolor(6);
	psnake->printinitsnake();
	srand(time(0));
	pfood->drawfood(*psnake);

	//��Ϸѭ�� 
	// �ж����Ƿ�ײ��ǽ����ײ���Լ�
	while (!(psnake->overedge()) && !(psnake->eatitself()))
	{
		// �����ж�
		if (!(psnake->changedirection()))  // ESC��
		{
			menu();
		}

		// �߳�Сʳ��
		if (psnake->eatfood(*pfood))
		{
			psnake->snakeadd();
			updatescore();
			pfood->drawfood(*psnake);
		}
		else
		{
			psnake->move();
		}
		
		// �߳Դ�ʳ��
		if (psnake->eatbigfood(*pfood))
		{
			psnake->snakeadd();
			updatescore();
		}

		if (pfood->getbigflag())
		{
			pfood->bigfoodflash();
		}
		Sleep(speed);
	}
	//3.������
	delete psnake;
	delete pfood;
	//if (gameover)
	//{

	//}
	return false;
}

// ���·���
void Controller::updatescore()
{
	score += 5 * level;
	setcursorposition(37, 8);
	setcolor(11);
	//TODO: ��ʱʳ��
	cout << score;
}

// ��ͣ�˵�
void Controller::menu()
{
	//TODO 1.������ͣ�˵�  2.ѡ�� ��1������ (2)��ͣ ��3���˳�
	setcolor(11);
	setcursorposition(32, 19);
	cout << "�˵�:";
	setcursorposition(34, 21);
	cout << "������Ϸ";
	setcursorposition(34, 23);
	cout << "���¿�ʼ";
	setcursorposition(34, 25);
	cout << "�˳���Ϸ";

	//TODO ѡ��֮�����
}

int Controller::gameover()
{
	//TODO ������Ϸ�����˵�
	setcolor(11);
	setcursorposition(10, 8);
	cout << "-----------------------------------------";  
	setcursorposition(10, 9);
	cout << "|         GameOver                       |";
	setcursorposition(10, 10);
	cout << "|                                        |";
	setcursorposition(10, 11);
	cout << "|       ���ź�,�����                    |";
	setcursorposition(10, 12);
	cout << "|                                        |";
	setcursorposition(10, 13);
	cout << "|        ��ķ���Ϊ:                     |";
	setcursorposition(24, 13);
	cout << score;
	setcursorposition(10, 14);
	cout << "|                                        |";
	setcursorposition(10, 15);
	cout << "|        �Ƿ�����һ��?                   |";
	setcursorposition(10, 16);
	cout << "|                                        |";
	setcursorposition(10, 17);
	cout << "|                                        |";
	setcursorposition(10, 18);
	cout << "|   ��,�õ�    ����,����ѧϰ����˼        |";
	setcursorposition(10, 19);
	cout << "|                                        |";
	setcursorposition(10, 20);
	cout << "|                                        |";
	setcursorposition(10, 21);
	cout << "-----------------------------------------";  

	setcursorposition(12, 18);
	setbackground();
	cout << "��,�õ�";
	//TODO: ����ѡ��Ч��	
	int ch;
	int result = 1;
	bool flag = false;
	while (ch = _getch())
	{
		switch (ch)
		{
		case 75:   // ��
			if (result > 1)
			{
				setcursorposition(12, 18);
				setbackground();
				cout << "��,�õ�";
				setcursorposition(20, 18);
				cout << "����,����ѧϰ����˼";
				--result;
			}
			break;
		case 77:  // ��
			if (result < 2)
			{
				setcursorposition(12, 18);
				cout << "��,�õ�";
				setcursorposition(20, 18);
				setbackground();
				cout << "����,����ѧϰ����˼";
				++result;
			}
			break;
		case 13: // enter
			flag = true;
			break;
		default:
			break;
		}
		if (flag)
			break;

		return result;
	}
	return 0;
}

