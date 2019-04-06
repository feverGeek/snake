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

// 开始
void Controller::startgame()
{
	start(); // 开始界面
	
	while (true)
	{
		select(); // 选择界面
		drawgame(); // 绘制游戏界面
		//TODO: 游戏循环 直到退出
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

// 开始游戏界面
void Controller::start()
{
	setwindowsize(41, 32);
	setcolor(2);
	hidecursor();

	// 开始动画
	Animation* act = new Animation;
	act->Action();
	delete act;

	setcursorposition(13, 26);
	cout << "Press any key to start...";
	setcursorposition(13, 27);
	cout << "按任意键继续...";

}

// 选择难度
void Controller::select()
{
	/* 初始化界面的选项 */
	setcolor(3);
	setcursorposition(13, 26);
	cout << "                                     ";
	setcursorposition(13, 27);
	cout << "                                     ";
	setcursorposition(6, 21);
	cout << "请选择游戏难度";
	setcursorposition(6, 22);
	cout << "(上下键选择,回车确认)";
	setcursorposition(27, 22);
	setbackground();// 第一个选项设置背景色以表示当前选中
	cout << "简单模式";
	setcursorposition(27, 24);
	setcolor(3);
	cout << "普通模式";
	setcursorposition(27, 26);
	cout << "困难模式";
	setcursorposition(27, 28);
	cout << "炼狱模式";
	setcursorposition(0, 31);

	level = 1;
	score = 0;
	// 上下方向键选择难度
	int ch;  // 记录键入值
	bool flag = false; // 记录是否犯下enter键
	while (ch = _getch())
	{
		switch (ch)
		{
		case 72:  // 上
			if (level)
			{
				switch (level)
				{
				case 2:
					setcursorposition(27, 22); // 给待选中项设置背景色
					setbackground();
					cout << "简单模式";

					setcursorposition(27, 24); // 将已选中的选项取消背景色
					setcolor(3);
					cout << "普通模式";
					--level;
					break;
				case 3:
					setcursorposition(27, 24); // 给待选中项设置背景色
					setbackground();
					cout << "普通模式";

					setcursorposition(27, 26); // 将已选中的选项取消背景色
					setcolor(3);
					cout << "困难模式";
					--level;
					break;
				case 4:
					setcursorposition(27, 26); // 给待选中项设置背景色
					setbackground();
					cout << "困难模式";

					setcursorposition(27, 28); // 将已选中的选项取消背景色
					setcolor(3);
					cout << "炼狱模式";
					--level;
					break;
				}
			}
			break;
		case 80:  // 下
			if (level < 4)
			{
				switch (level)
				{
				case 1:
					setcursorposition(27, 24); // 给待选中项设置背景色
					setbackground();
					cout << "普通模式";

					setcursorposition(27, 22); // 将已选中的选项取消背景色
					setcolor(3);
					cout << "简单模式";
					++level;
					break;
				case 2:
					setcursorposition(27, 26); // 给待选中项设置背景色
					setbackground();
					cout << "困难模式";

					setcursorposition(27, 24); // 将已选中的选项取消背景色
					setcolor(3);
					cout << "普通模式";
					++level;
					break;
				case 3:
					setcursorposition(27, 28); // 给待选中项设置背景色
					setbackground();
					cout << "炼狱模式";
					
					setcursorposition(27, 26); // 将已选中的选项取消背景色
					setcolor(3);
					cout << "困难模式";
					++level;	
					break;
				}
			}
			break;
		case 13:  // enter 
			flag = true;
			break;
		default:  // 其他按键不做作操作
			break;
		}

		if (flag) break;   // 输入enter键退出检查循环
	}

	switch (level)
	{
	case 1: // 简单模式
		speed = 135;
		break;
	case 2: // 普通模式
		speed = 100;
		break;
	case 3: // 困难模式
		speed = 60;
		break;
	case 4: // 炼狱模式
		speed = 30;
		break;
	}
}

// 画地图
void Controller::drawgame()
{
	system("cls");
	
	// 画地图 
	setcolor(3);
	Map* initMap = new Map;
	initMap->printmap();
	delete initMap;

	// 侧边栏
	setcolor(3);
	setcursorposition(33, 1);
	cout << "Greedy Snake";
	setcursorposition(34, 2);
	cout << "贪吃蛇";
	setcursorposition(31, 4);
	cout << "难度:";
	setcursorposition(36, 5);
	switch (level)
	{
	case 1:
		cout << "简单模式";
		break;
	case 2:
		cout << "普通模式";
		break;
	case 3:
		cout << "困难模式";
		break;
	case 4:
		cout << "炼狱模式";
		break;
	}
	setcursorposition(31, 7);
	cout << "得分:";
	setcursorposition(37, 8);
	cout << "     0";
	setcursorposition(34, 13);
	cout << " 方向键移动";
	setcursorposition(34, 15);
	cout << " ESC键暂停";
}

// 玩游戏
bool Controller::playgame()
{
	// 初始化蛇和食物 
	Snake* psnake = new Snake();
	Food* pfood = new Food();

	setcolor(6);
	psnake->printinitsnake();
	srand(time(0));
	pfood->drawfood(*psnake);

	//游戏循环 
	// 判断蛇是否撞到墙或是撞到自己
	while (!(psnake->overedge()) && !(psnake->eatitself()))
	{
		// 按键判断
		if (!(psnake->changedirection()))  // ESC键
		{
			menu();
		}

		// 蛇吃小食物
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
		
		// 蛇吃大食物
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
	//3.蛇死亡
	delete psnake;
	delete pfood;
	//if (gameover)
	//{

	//}
	return false;
}

// 更新分数
void Controller::updatescore()
{
	score += 5 * level;
	setcursorposition(37, 8);
	setcolor(11);
	//TODO: 限时食物
	cout << score;
}

// 暂停菜单
void Controller::menu()
{
	//TODO 1.绘制暂停菜单  2.选择 （1）继续 (2)暂停 （3）退出
	setcolor(11);
	setcursorposition(32, 19);
	cout << "菜单:";
	setcursorposition(34, 21);
	cout << "继续游戏";
	setcursorposition(34, 23);
	cout << "重新开始";
	setcursorposition(34, 25);
	cout << "退出游戏";

	//TODO 选择之后操作
}

int Controller::gameover()
{
	//TODO 调用游戏结束菜单
	setcolor(11);
	setcursorposition(10, 8);
	cout << "-----------------------------------------";  
	setcursorposition(10, 9);
	cout << "|         GameOver                       |";
	setcursorposition(10, 10);
	cout << "|                                        |";
	setcursorposition(10, 11);
	cout << "|       很遗憾,你挂了                    |";
	setcursorposition(10, 12);
	cout << "|                                        |";
	setcursorposition(10, 13);
	cout << "|        你的分数为:                     |";
	setcursorposition(24, 13);
	cout << score;
	setcursorposition(10, 14);
	cout << "|                                        |";
	setcursorposition(10, 15);
	cout << "|        是否再来一局?                   |";
	setcursorposition(10, 16);
	cout << "|                                        |";
	setcursorposition(10, 17);
	cout << "|                                        |";
	setcursorposition(10, 18);
	cout << "|   嗯,好的    不了,还是学习有意思        |";
	setcursorposition(10, 19);
	cout << "|                                        |";
	setcursorposition(10, 20);
	cout << "|                                        |";
	setcursorposition(10, 21);
	cout << "-----------------------------------------";  

	setcursorposition(12, 18);
	setbackground();
	cout << "嗯,好的";
	//TODO: 左右选择效果	
	int ch;
	int result = 1;
	bool flag = false;
	while (ch = _getch())
	{
		switch (ch)
		{
		case 75:   // 左
			if (result > 1)
			{
				setcursorposition(12, 18);
				setbackground();
				cout << "嗯,好的";
				setcursorposition(20, 18);
				cout << "不了,还是学习有意思";
				--result;
			}
			break;
		case 77:  // 右
			if (result < 2)
			{
				setcursorposition(12, 18);
				cout << "嗯,好的";
				setcursorposition(20, 18);
				setbackground();
				cout << "不了,还是学习有意思";
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

