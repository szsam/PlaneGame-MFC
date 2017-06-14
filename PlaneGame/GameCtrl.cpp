#include "stdafx.h"

#include "GameCtrl.h"
#include <ctime>
#include <string>



GameCtrl::GameCtrl() : 
	height(CLIENT_HEIGHT), width(CLIENT_WIDTH), 
	player(PLAYER_X, PLAYER_Y, PLAYER_HEIGHT, PLAYER_WIDTH, PLAYER_SPEED),
	score(0)
{
	Bullet::init_image();
	PlaneEnemy::init_image();
}

void GameCtrl::init()
{
	//dis.drawBackground();
	//player.draw(dis);
	blist.clear();
	elist.clear();

	score = 0;

	srand((unsigned)time(NULL));

}

void GameCtrl::playerMove(Dir d)
{
	player.set_dir(d);
	player.move(height, width);
}

void GameCtrl::shoot()
{
	// 子弹从飞机头部发出
	blist.emplace_back(player.pos.x + player.width / 2 - BULLET_WIDTH / 2,
		player.pos.y - BULLET_HEIGHT, BULLET_HEIGHT, BULLET_WIDTH, BULLET_SPEED);
}

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

void GameCtrl::drawBullets(CDC *pDC)
{
	for (auto &b : blist)
	{
		b.draw(pDC);
	}
}

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

void GameCtrl::addEnemy()
{
	int x = random(0, width - ENEMY_WIDTH);
	elist.emplace_back(x, 0, ENEMY_HEIGHT, ENEMY_WIDTH, ENEMY_SPEED);
}

void GameCtrl::drawEnemies(CDC *pDC)
{
	for (auto &e : elist)
	{
		e.draw(pDC);
	}
}

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


bool GameCtrl::gameOver()
{
	for (auto &e : elist)
	{
		if (isConflict(player, e))
		{
			return true;
		}
	}
	return false;
}

void GameCtrl::printScore(CDC *pDC)
{
	CString str;
	str.Format(_T("%d"), score);
	pDC->TextOut(0, 0, str);
}
//
//void GameCtrl::pause()
//{
//	dis.print(61, 2, "暂停中...");
//
//	while (_getch() != 'p')
//		continue;
//
//	dis.print(61, 2, "         ");
//}
//
//void GameCtrl::waitStart()
//{
//	dis.print(52, 2, "按p键开始游戏");
//
//	while (_getch() != 'p')
//		continue;
//
//	dis.print(52, 2, "            ");
//}
//
//void GameCtrl::printGameOver()
//{
//	dis.print(52, 2, "Game Over!");
//}
//
//void GameCtrl::playerMove(Dir d, int h, int w)
//{
//	player.set_dir(d);
//	player.move(h, w);
//}

//int main()
//{
//	GameCtrl gameCtrl;
//
//	gameCtrl.init();
//	gameCtrl.waitStart();
//	gameCtrl.mainLoop();
//	gameCtrl.printGameOver();
//
//	// Sleep(1000);
//
//}