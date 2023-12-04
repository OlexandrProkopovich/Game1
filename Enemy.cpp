#include "Enemy.h"

void Enemy::EnemyUpdate(float time, Player& player) {
	sf::Vector2f EnemyPosition = Enemy_Sprite.getPosition();
	sf::Vector2f HeroPosition = player.Hero_Sprite.getPosition();

	direction = HeroPosition - EnemyPosition;

	float distance = std::sqrt(std::pow(HeroPosition.x - EnemyPosition.x, 2) + std::pow(HeroPosition.y - EnemyPosition.y, 2));
	if (distance <= 75)
	{
		startAttack = true;
	}
	else
	{
		startAttack = false;

	}

	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length > 0)
	{
		direction.x /= length;
		direction.y /= length;
	}

	sf::Vector2f newPosition = EnemyPosition + direction * speed * time;
	Enemy_Sprite.setPosition(newPosition);

}

void Enemy::EnemyAnimation(float CurentFrame, float time) {
	int framesInTexture = 6;
	if(!isDead){
		if (direction.x > 0) {
			Enemy_Sprite.setTexture(walkRight_Texture); Enemy_Sprite.setScale(1.8, 1.8);
			if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; }
			Enemy_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
		}
		else if (direction.x < 0) {
			Enemy_Sprite.setTexture(walkLeft_Texture); Enemy_Sprite.setScale(1.8, 1.8);
			if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; }
			Enemy_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
		}
		else if (direction.y > 0) {
			Enemy_Sprite.setTexture(downWalk_Texture); Enemy_Sprite.setScale(1.8, 1.8);
			if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; }
			Enemy_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
		}
		else if (direction.y < 0) {
			Enemy_Sprite.setTexture(upWalk_Texture); Enemy_Sprite.setScale(1.8, 1.8);
			if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; }
			Enemy_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
		}
	}
	else if(isDead)
	{
		Enemy_Sprite.setTexture(Death_Texture);
	}
}

void Enemy::TakeDamageAnimation(float CurentFrame, float time) {
	if (TakeDamage && !isDead) {
		int framesInTexture = 4;
		if (direction.x > 0) {
			Enemy_Sprite.setTexture(TakeDamage_Right_Texture); Enemy_Sprite.setScale(1.8, 1.8);
			if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; TakeDamage = false; }
			Enemy_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
		}
		else if (direction.x < 0) {
			Enemy_Sprite.setTexture(TakeDamage_Left_Texture); Enemy_Sprite.setScale(1.8, 1.8);
			if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; TakeDamage = false; }
			Enemy_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
		}
		else if (direction.y > 0) {
			Enemy_Sprite.setTexture(TakeDamage_Up_Texture); Enemy_Sprite.setScale(1.8, 1.8);
			if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; TakeDamage = false; }
			Enemy_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
		}
		else if (direction.y < 0) {
			Enemy_Sprite.setTexture(TakeDamage_Down_Texture); Enemy_Sprite.setScale(1.8, 1.8);
			if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; TakeDamage = false; }
			Enemy_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
		}
	}
	else if (isDead)
	{
		Enemy_Sprite.setTexture(Death_Texture);
	}
}

void Enemy::DeathAnimation(float CurentFrame, float time)
{
	const int framesInTexture = 8;

	if (isDead && !deathAnimationFinished)
	{
		speed = 0;
		Enemy_Sprite.setTexture(Death_Texture);
		Enemy_Sprite.setScale(1.8, 1.8);

		if (CurentFrame >= framesInTexture)
		{
			CurentFrame = framesInTexture - 0.01; // Незначний зсув для коректного виведення останнього кадру
			deathAnimationFinished = true;
		}

		const int frameIndex = static_cast<int>(CurentFrame);
		Enemy_Sprite.setTextureRect(sf::IntRect(48 * frameIndex, 0, 48, 48));
	}
}
void Enemy::EnemyTakeDamage()
{
	TakeDamage = true;
	health -= 4;
}

void Enemy::AttackAnimation(float CurentFrame, Player& p1)
{
	if (startAttack)
	{
		int framesInTexture = 8;
		if (direction.x > 0) {
			Enemy_Sprite.setTexture(righ_attack_Texture); Enemy_Sprite.setScale(1.8, 1.8);
			if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; p1.health -= 4; p1.TakeDamage = true;}
			Enemy_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
		}
		else if (direction.x < 0) {
			Enemy_Sprite.setTexture(left_attack_Texture); Enemy_Sprite.setScale(1.8, 1.8);
			if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; p1.health -= 4; p1.TakeDamage = true; }
			Enemy_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
		}
		else if (direction.y > 0) {
			
			Enemy_Sprite.setTexture(up_attack_Texture); Enemy_Sprite.setScale(1.8, 1.8);
			if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; p1.health -= 4;  p1.TakeDamage = true;}
			Enemy_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
		}
		else if (direction.y < 0) {
		
			Enemy_Sprite.setTexture(down_attack_Texture); Enemy_Sprite.setScale(1.8, 1.8);
			if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; p1.health -= 4; p1.TakeDamage = true;}
			Enemy_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
		}
	}
}