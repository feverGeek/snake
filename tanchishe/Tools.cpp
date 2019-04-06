#include "Tools.h"
#include <iostream>
#include <Windows.h>

// 设置窗口大小
void setwindowsize(int x, int y) 
{
	system("title 贪吃蛇");  // 设置窗口标题
	char cmd[32];
	sprintf(cmd, "mode con cols=%d lines=%d", x * 2, y);
	system(cmd);
}

// 隐藏光标
void hidecursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

// 设置光标坐标
void setcursorposition(const int x, const int y)
{
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

// 设置文本颜色
void setcolor(int colorid)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorid);
}

// 设置背景颜色
void setbackground()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
		FOREGROUND_BLUE | 
		BACKGROUND_BLUE |
		BACKGROUND_GREEN|
		BACKGROUND_RED);
}

