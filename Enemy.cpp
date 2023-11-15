#include "Enemy.h"

void Enemy::EnemyUpdate(float time, Player& player) {
	sf::Vector2f EnemyPosition = Enemy_Sprite.getPosition();
	sf::Vector2f HeroPosition = player.Hero_Sprite.getPosition();

	// ��������� ������ �������� �� ������ �� �����
	direction = HeroPosition - EnemyPosition;

	// ������������ ������ �������� (������� ���� ��������� ��������)
	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length > 0)
	{
		direction.x /= length;
		direction.y /= length;
	}

	// ���������� �������� ������
	speed = 0.1f; // ����� �� �������� �� ������ ��������

	// ��������� ���� ������� ������ �� ������� �����
	sf::Vector2f newPosition = EnemyPosition + direction * speed * time;
	Enemy_Sprite.setPosition(newPosition);
}

void Enemy::EnemyAnimation(float CurentFrame, float time) {
	if (direction.x > 0) {
		// ��� ������
		// ������������ ������� ��� ���� ������
		Enemy_Sprite.setTexture(walkRight_Texture); Enemy_Sprite.setScale(1.8, 1.8);
		CurentFrame += time * 0.005;
		if (CurentFrame >= 3) { CurentFrame -= 3; }
		Enemy_Sprite.setTextureRect(sf::IntRect(48 * (int)CurentFrame, 0, 48, 48));
	}
	else if (direction.x < 0) {
		// ��� ����
		// ������������ ������� ��� ���� ����
		Enemy_Sprite.setTexture(walkLeft_Texture); Enemy_Sprite.setScale(1.8, 1.8);
		CurentFrame += time * 0.005;
		if (CurentFrame >= 3) { CurentFrame -= 3; }
		Enemy_Sprite.setTextureRect(sf::IntRect(48 * (int)CurentFrame, 0, 48, 48));
	}
	else if (direction.y > 0) {
		// ��� ����
		// ������������ ������� ��� ���� ����
		Enemy_Sprite.setTexture(downWalk_Texture); Enemy_Sprite.setScale(1.8, 1.8);
		CurentFrame += time * 0.005;
		if (CurentFrame >= 3) { CurentFrame -= 3; }
		Enemy_Sprite.setTextureRect(sf::IntRect(48 * (int)CurentFrame, 0, 48, 48));
	}
	else if (direction.y < 0) {
		// ��� �����
		// ������������ ������� ��� ���� �����
		Enemy_Sprite.setTexture(upWalk_Texture); Enemy_Sprite.setScale(1.8, 1.8);
		CurentFrame += time * 0.005;
		if (CurentFrame >= 3) { CurentFrame -= 3; }
		Enemy_Sprite.setTextureRect(sf::IntRect(48 * (int)CurentFrame, 0, 48, 48));
	}
}