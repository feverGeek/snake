#pragma once
class Controller
{
public:
	Controller():level(1), score(0), speed(20) {};
	void startgame();// 开始游戏
	void start();    // 开始界面
	void select();   // 选择难度
	void drawgame(); // 画游戏地图 
	bool playgame(); // 玩游戏
	void updatescore();//更新分数
	void menu();      // 暂停菜单
	int gameover(); // 游戏结束菜单
	//~Controller();
private:
	int level;
	int score;
	int speed;
};

