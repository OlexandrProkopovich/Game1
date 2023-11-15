#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "Bullet.h"
void RandomSpawn(float elapsedTime, const sf::RenderWindow& window, const Enemy& enemy, std::vector<Enemy>& enemies, sf::Clock& enemySpawnTimer) {
	int minSpawnInterval = 2000000;
	if (elapsedTime > minSpawnInterval)
	{
		int x = std::rand() % window.getSize().x;
		int y = std::rand() % window.getSize().y;


		Enemy newEnemy(enemy);
		newEnemy.Enemy_Sprite.setPosition(x, y);
		enemies.push_back(newEnemy);
		enemySpawnTimer.restart();
	}
}

void DrawEnemy(std::vector<Enemy>& enemies, sf::RenderWindow& window, float time, Player& player, float CurentFrame)
{
	for (size_t i = 0; i < enemies.size(); ++i)
	{
		enemies[i].EnemyUpdate(time, player);
		enemies[i].EnemyAnimation(CurentFrame, time);
		window.draw(enemies[i].Enemy_Sprite);
	}
}

void bullet_spawn(const Bullet& bullet, std::vector <Bullet>& bullets, float elapsedTime1, sf::Clock& attackcoldown_clocl)
{
	int AttackColdown = 1000000;
	if (elapsedTime1 > AttackColdown) {
		Bullet newBullet(bullet);
		bullets.push_back(newBullet);
		attackcoldown_clocl.restart();
	}
}

void bullet_update(float time, float CurentFrame, std::vector<Bullet>& bullets, const Enemy& enemy)
{
	for (size_t i = 0; i < bullets.size(); ++i)
	{
		
		bullets[i].BulletUpdate(time, enemy);
		bullets[i].BulletAnimation(time, CurentFrame);
	}
	
}

void buller_draw(sf::RenderWindow& window, std::vector<Bullet> bullets)
{
	for(size_t i = 0; i < bullets.size(); ++i){
		window.draw(bullets[i].Bullet_Sprite);
	}
}
struct Vector2D
{
	float x, y;
	Vector2D() = default;
	Vector2D(float _x, float _y) : x(_x), y(_y){}
	int Dot(const Vector2D& v1, const Vector2D& v2)
	{
		return (v1.x * v2.x + v1.y * v2.y);
	}
	Vector2D Cross(const Vector2D& v1, const Vector2D& v2)
	{
		return Vector2D(v1.x * v2.y - v2.x * v1.y,
			v1.x * v2.y - v2.x * v1.y);
	}
};