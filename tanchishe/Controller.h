#pragma once
class Controller
{
public:
	Controller():level(1), score(0), speed(20) {};
	void startgame();// ��ʼ��Ϸ
	void start();    // ��ʼ����
	void select();   // ѡ���Ѷ�
	void drawgame(); // ����Ϸ��ͼ 
	bool playgame(); // ����Ϸ
	void updatescore();//���·���
	void menu();      // ��ͣ�˵�
	int gameover(); // ��Ϸ�����˵�
	//~Controller();
private:
	int level;
	int score;
	int speed;
};

