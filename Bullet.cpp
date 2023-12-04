#include "Bullet.h"
#include "Player.h"
void Bullet::SetBulletPosition(const Player& player) {
	Bullet_Sprite.setPosition(player.Hero_Sprite.getPosition().x + 24, player.Hero_Sprite.getPosition().y + 37);
}


void Bullet::BulletUpdate(float time, const Enemy& enemy)
{
    sf::Vector2f BulletPosition = Bullet_Sprite.getPosition();
    sf::Vector2f EnemyPosition = enemy.Enemy_Sprite.getPosition();
    EnemyPosition.x += 28;
    EnemyPosition.y += 39;

    direction = EnemyPosition - BulletPosition;

    sf::Vector2f normalizeDirection = direction / sqrt((direction.x * direction.x + direction.y * direction.y));

    float x = BulletPosition.x + time * speed * normalizeDirection.x;
    float y = BulletPosition.y + time * speed * normalizeDirection.y;

    Bullet_Sprite.setPosition(x, y);
}


float Bullet::getDistance(const sf::Vector2f& v1, const sf::Vector2f& v2)
{
	// Функція для обчислення відстані між двома точками
	float dx = v2.x - v1.x;
	float dy = v2.y - v1.y;
	return std::sqrt(dx * dx + dy * dy);
}

void Bullet::BulletUpdate_array(float time, const std::vector<Enemy>& enemies)
{
    sf::Vector2f BulletPosition = Bullet_Sprite.getPosition();
    const Enemy* nearestEnemy = &enemies[0];
    float min_distance = std::numeric_limits<float>::max();

    for (auto& enemy : enemies)
    {
        float current_distance = getDistance(BulletPosition, enemy.Enemy_Sprite.getPosition());
        if (current_distance < min_distance)
        {
            nearestEnemy = &enemy;
            min_distance = current_distance;
        }
    }
    sf::Vector2f nearestEnemyPosition = nearestEnemy->Enemy_Sprite.getPosition();
	nearestEnemyPosition.x += 28;
	nearestEnemyPosition.y += 39;

    direction = nearestEnemyPosition - BulletPosition;
    sf::Vector2f normalizeDirection = direction / std::sqrt((direction.x * direction.x + direction.y * direction.y));
    // Обчислюємо нову позицію пулі з використанням кроку
    float x = BulletPosition.x + time * speed * normalizeDirection.x;
    float y = BulletPosition.y + time * speed * normalizeDirection.y;

    Bullet_Sprite.setPosition(x, y);

}


void Bullet::BulletAnimation(float time, float CurentFrame) {
	if (direction.x > 0) {
		// Ðóõ âïðàâî
		// Âèêîðèñòàéòå àí³ìàö³þ äëÿ ðóõó âïðàâî
		Bullet_Sprite.setTexture(bulletRight_Texture);
		CurentFrame += time * 0.005;
		if (CurentFrame >= 3) { CurentFrame -= 3; }
		Bullet_Sprite.setTextureRect(sf::IntRect(32 * (int)CurentFrame, 0, 32, 17));
	}
	else if (direction.x < 0) {
		// Ðóõ âë³âî
		// Âèêîðèñòàéòå àí³ìàö³þ äëÿ ðóõó âë³âî
		Bullet_Sprite.setTexture(bulletLeft_Texture);
		CurentFrame += time * 0.005;
		if (CurentFrame >= 3) { CurentFrame -= 3; }
		Bullet_Sprite.setTextureRect(sf::IntRect(32 * (int)CurentFrame, 0, 32, 17));
	}
	else if (direction.y > 0) {
		// Ðóõ âíèç
		// Âèêîðèñòàéòå àí³ìàö³þ äëÿ ðóõó âíèç
		Bullet_Sprite.setTexture(bulletDown_Texture);
		CurentFrame += time * 0.005;
		if (CurentFrame >= 3) { CurentFrame -= 3; }
		Bullet_Sprite.setTextureRect(sf::IntRect(0, 32 * (int)CurentFrame, 17, 32));
	}
	else if (direction.y < 0) {
		// Ðóõ âãîðó
		// Âèêîðèñòàéòå àí³ìàö³þ äëÿ ðóõó âãîðó
		Bullet_Sprite.setTexture(bulletUp_Texture);
		CurentFrame += time * 0.005;
		if (CurentFrame >= 3) { CurentFrame -= 3; }
		Bullet_Sprite.setTextureRect(sf::IntRect(0, 32 * (int)CurentFrame, 17, 32));
	}
}