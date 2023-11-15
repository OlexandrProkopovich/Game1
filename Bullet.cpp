#include "Bullet.h"

void Bullet::SetBulletPosition(const Player& player) {
    Bullet_Sprite.setPosition(player.Hero_Sprite.getPosition().x + 24, player.Hero_Sprite.getPosition().y + 37);
}

void Bullet::BulletUpdate(float time, const Enemy& enemy)
{
    sf::Vector2f BulletPosition = Bullet_Sprite.getPosition();
    sf::Vector2f EnemyPosition = enemy.Enemy_Sprite.getPosition();

    direction = EnemyPosition - BulletPosition;

    sf::Vector2f normalizeDirection = direction / sqrt((direction.x * direction.x + direction.y * direction.y));

    float x = BulletPosition.x + time * speed * normalizeDirection.x;
    float y = BulletPosition.y + time * speed * normalizeDirection.y;

    Bullet_Sprite.setPosition(x, y);

	
}

void Bullet::BulletAnimation(float time, float CurentFrame) {
	if (direction.x > 0) {
		// Рух вправо
		// Використайте анімацію для руху вправо
		Bullet_Sprite.setTexture(bulletRight_Texture); 
		CurentFrame += time * 0.005;
		if (CurentFrame >= 3) { CurentFrame -= 3; }
		Bullet_Sprite.setTextureRect(sf::IntRect(32 * (int)CurentFrame, 0, 32, 17));
	}
	else if (direction.x < 0) {
		// Рух вліво
		// Використайте анімацію для руху вліво
		Bullet_Sprite.setTexture(bulletLeft_Texture);
		CurentFrame += time * 0.005;
		if (CurentFrame >= 3) { CurentFrame -= 3; }
		Bullet_Sprite.setTextureRect(sf::IntRect(32 * (int)CurentFrame, 0, 32, 17));
	}
	else if (direction.y > 0) {
		// Рух вниз
		// Використайте анімацію для руху вниз
		Bullet_Sprite.setTexture(bulletDown_Texture);
		CurentFrame += time * 0.005;
		if (CurentFrame >= 3) { CurentFrame -= 3; }
		Bullet_Sprite.setTextureRect(sf::IntRect(0, 32 * (int)CurentFrame, 17, 32));
	}
	else if (direction.y < 0) {
		// Рух вгору
		// Використайте анімацію для руху вгору
		Bullet_Sprite.setTexture(bulletUp_Texture);
		CurentFrame += time * 0.005;
		if (CurentFrame >= 3) { CurentFrame -= 3; }
		Bullet_Sprite.setTextureRect(sf::IntRect(0, 32 * (int)CurentFrame, 17, 32));
	}
}