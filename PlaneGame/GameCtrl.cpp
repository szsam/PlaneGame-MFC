#include "stdafx.h"

#include "GameCtrl.h"
#include <ctime>
#include <string>


GameCtrl::GameCtrl() : 
	height(CLIENT_HEIGHT), width(CLIENT_WIDTH), 
	player(PLAYER_X, PLAYER_Y, PLAYER_HEIGHT, PLAYER_WIDTH, PLAYER_SPEED),
	score(0)
{
	Bullet::initImage();
	PlaneEnemy::initImage();
}

void GameCtrl::init()
{
	blist.clear();
	elist.clear();

	score = 0;

	srand((unsigned)time(NULL));

}

// 玩家移动
void GameCtrl::playerMove(Dir d)
{
	player.setDir(d);
	player.move(height, width);
}

void GameCtrl::shoot()
{
	// 子弹从飞机头部发出
	blist.emplace_back(player.pos.x + player.width / 2 - BULLET_WIDTH / 2,
		player.pos.y - BULLET_HEIGHT, BULLET_HEIGHT, BULLET_WIDTH, BULLET_SPEED);
}

// 更新子弹的位置，若越界，则将其移除
void GameCtrl::updateBullets()
{
	auto it = blist.begin();
	while (it != blist.end())
	{
		if (it->move(height, width))
			++it;
		else
			it = blist.erase(it);
	}
}

// 更新敌机的位置，若越界，则将其移除
void GameCtrl::updateEnemies()
{
	auto it = elist.begin();
	while (it != elist.end())
	{
		if (it->move(height, width))
			++it;
		else
			it = elist.erase(it);
	}
}

// 在画面上部的某一位置随机生成一架敌机
void GameCtrl::addEnemy()
{
	int x = random(0, width - ENEMY_WIDTH);
	elist.emplace_back(x, 0, ENEMY_HEIGHT, ENEMY_WIDTH, ENEMY_SPEED, 2);
}

// 检测是否有子弹击中敌机
void GameCtrl::bulletHitPlane()
{
	for (auto itBullet = blist.begin(); itBullet != blist.end(); ++itBullet)
	{
		for (auto itEnemy = elist.begin(); itEnemy != elist.end(); ++itEnemy)
		{
			if (isConflict(*itBullet, *itEnemy))
			{
				// 子弹击中敌机
				++score;
				itBullet = blist.erase(itBullet);
				if (!itEnemy->decreaseHP())
					itEnemy = elist.erase(itEnemy);
				return;
			}
		}
	}
}

// 检测两个矩形是否发生碰撞
bool GameCtrl::isConflict(const GameObject &rect1, const GameObject &rect2) const
{
	return	rect1.pos.x < rect2.pos.x + rect2.width &&
		rect1.pos.x + rect1.width > rect2.pos.x &&
		rect1.pos.y < rect2.pos.y + rect2.height &&
		rect1.height + rect1.pos.y > rect2.pos.y;
}

// 判断游戏是否结束
bool GameCtrl::gameOver()
{
	for (auto &e : elist)
	{
		// 有敌机和玩家碰撞
		if (isConflict(player, e))
		{
			return true;
		}
	}
	return false;
}
