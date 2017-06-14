#pragma once
#include "PlanePlayer.h"

#include "Bullet.h"
#include "PlaneEnemy.h"
#include <list>

class GameCtrl
{
public:
	GameCtrl();
	void init();
	//void mainLoop();
	//void waitStart();
	//void printGameOver();

	void playerMove(Dir d);
	void drawPlayer(CDC *pDC) { player.draw(pDC); }

	void updateBullets();
	void drawBullets(CDC *);

	void shoot();

	void updateEnemies();
	void addEnemy();
	void drawEnemies(CDC *);

	void bulletHitPlane();

	bool gameOver();

	void printScore(CDC *);

	int getHeight() { return height; }
	int getWidth() { return width;  }
private:
	PlanePlayer player;
	std::list<Bullet> blist;
	std::list<PlaneEnemy> elist;
	int score;
	int height;	//�ͻ����߶�
	int width;	//�ͻ������

	//void keyboard();
	//void drawBackground();
	
	bool isConflict(const GameObject &, const GameObject &) const;

	

	//void pause();


	//// mainLoopѭ����ִ�е�ʱ����
	//static const int SLEEP_INTERVAL = 50;
	//// ˢ�µл�λ�õ�ʱ����
	//static const int ENEMY_INTERVAL = 200;	
	//// ����һ�ܵл���ʱ����
	//static const int ADD_ENEMY_INTERVAL = 500;

	static const int CLIENT_HEIGHT = 800;
	static const int CLIENT_WIDTH = 600;

	static const int PLAYER_HEIGHT = 120;
	static const int PLAYER_WIDTH = 100;
	static const int PLAYER_X = 100;
	static const int PLAYER_Y = 600;
	static const int PLAYER_SPEED = 30;

	static const int BULLET_HEIGHT = 28;
	static const int BULLET_WIDTH = 12;
	static const int BULLET_SPEED = 60;

	static const int ENEMY_HEIGHT = 50;
	static const int ENEMY_WIDTH = 50;
	static const int ENEMY_SPEED = 3;
};