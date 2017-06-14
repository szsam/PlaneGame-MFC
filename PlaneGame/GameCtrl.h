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

	void playerMove(Dir d);

	void updateBullets();

	void shoot();

	void updateEnemies();
	void addEnemy();

	void bulletHitPlane();

	bool gameOver();

	int getHeight() { return height; }
	int getWidth() { return width;  }
	const std::list<Bullet> &getBulletList() const { return blist; }
	const std::list<PlaneEnemy> &getEnemyList() const { return elist; }
	const PlanePlayer &getPlanePlayer() const { return player; }
	int getScore() const { return score; }

private:
	PlanePlayer player;
	std::list<Bullet> blist;
	std::list<PlaneEnemy> elist;
	int score;
	int height;	//客户区高度
	int width;	//客户区宽度
	
	bool isConflict(const GameObject &, const GameObject &) const;

	//// mainLoop循环体执行的时间间隔
	//static const int SLEEP_INTERVAL = 50;
	//// 刷新敌机位置的时间间隔
	//static const int ENEMY_INTERVAL = 200;	
	//// 增加一架敌机的时间间隔
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