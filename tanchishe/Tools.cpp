#include "Tools.h"
#include <iostream>
#include <Windows.h>

// ���ô��ڴ�С
void setwindowsize(int x, int y) 
{
	system("title ̰����");  // ���ô��ڱ���
	char cmd[32];
	sprintf(cmd, "mode con cols=%d lines=%d", x * 2, y);
	system(cmd);
}

// ���ع��
void hidecursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

// ���ù������
void setcursorposition(const int x, const int y)
{
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

// �����ı���ɫ
void setcolor(int colorid)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorid);
}

// ���ñ�����ɫ
void setbackground()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
		FOREGROUND_BLUE | 
		BACKGROUND_BLUE |
		BACKGROUND_GREEN|
		BACKGROUND_RED);
}

