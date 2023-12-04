#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
class Enemy {
public:
	float x, y, speed;
	bool isAttacking = false;
	bool TakeDamage = false;
	bool isDead;
	bool deathAnimationFinished;
	bool deleteEnemy = false;
	bool startAttack = false;
	int health = 12;

	sf::Vector2f direction;

	std::string Idle_String;
	std::string walkRight_String;
	std::string walkLeft_String;
	std::string upWalk_String;
	std::string downWalk_String;

	std::string TakeDamage_Right_String;
	std::string TakeDamage_Left_String;
	std::string TakeDamage_Up_String;
	std::string TakeDamage_Down_String;

	sf::Image TakeDamage_Right_Image;
	sf::Image TakeDamage_Left_Image;
	sf::Image TakeDamage_Up_Image;
	sf::Image TakeDamage_Down_Image;

	sf::Texture TakeDamage_Right_Texture;
	sf::Texture TakeDamage_Left_Texture;
	sf::Texture TakeDamage_Up_Texture;
	sf::Texture TakeDamage_Down_Texture;

	std::string Death_String;
	sf::Image Death_Image;
	sf::Texture Death_Texture;

	std::string down_attack_String;
	std::string up_attack_String;
	std::string left_attack_String;
	std::string righ_attack_String;

	sf::Image down_attack_Image;
	sf::Image up_attack_Image;
	sf::Image left_attack_Image;
	sf::Image righ_attack_Image;

	sf::Texture down_attack_Texture;
	sf::Texture up_attack_Texture;
	sf::Texture left_attack_Texture;
	sf::Texture righ_attack_Texture;
	

	sf::Image Idle_Image;
	sf::Image walkRight_Image;
	sf::Image walkLeft_Image;
	sf::Image upWalk_Image;
	sf::Image downWalk_Image;

	sf::Texture Idle_Texture;
	sf::Texture walkRight_Texture;
	sf::Texture walkLeft_Texture;
	sf::Texture upWalk_Texture;
	sf::Texture downWalk_Texture;

	sf::Sprite Enemy_Sprite;
	Enemy(const std::string _Idle_String, const std::string _walkRight_String, const std::string _walkLeft_String, const std::string _upWalk_String, const std::string _downWalk_String,
		std::string _TakeDamage_Right_String, std::string _TakeDamage_Left_String, std::string _TakeDamage_Up_String, std::string _TakeDamage_Down_String, std::string _Death_String,
		std::string _righ_attack_String, std::string _left_attack_String, std::string _up_attack_String, std::string _down_attack_String, int X, int Y, float _speed) :
		Idle_String(_Idle_String), walkRight_String(_walkRight_String), walkLeft_String(_walkLeft_String), upWalk_String(_upWalk_String),
		downWalk_String(_downWalk_String), TakeDamage_Right_String(_TakeDamage_Right_String), TakeDamage_Left_String(_TakeDamage_Left_String), 
		TakeDamage_Up_String(_TakeDamage_Up_String), TakeDamage_Down_String(_TakeDamage_Down_String), Death_String(_Death_String), righ_attack_String(_righ_attack_String), 
		left_attack_String(_left_attack_String), up_attack_String(_up_attack_String), down_attack_String(_down_attack_String), x(X), y(Y), speed(_speed)
	{
		isDead = false;
		deathAnimationFinished = false;
		Idle_Image.loadFromFile(Idle_String);
		walkRight_Image.loadFromFile(walkRight_String);
		walkLeft_Image.loadFromFile(walkLeft_String);
		upWalk_Image.loadFromFile(upWalk_String);
		downWalk_Image.loadFromFile(downWalk_String);

		TakeDamage_Right_Image.loadFromFile(TakeDamage_Right_String);
		TakeDamage_Left_Image.loadFromFile(TakeDamage_Left_String);
		TakeDamage_Up_Image.loadFromFile(TakeDamage_Up_String);
		TakeDamage_Down_Image.loadFromFile(TakeDamage_Down_String);

		TakeDamage_Right_Texture.loadFromImage(TakeDamage_Right_Image);
		TakeDamage_Left_Texture.loadFromImage(TakeDamage_Left_Image);
		TakeDamage_Up_Texture.loadFromImage(TakeDamage_Up_Image);
		TakeDamage_Down_Texture.loadFromImage(TakeDamage_Down_Image);

		Death_Image.loadFromFile(Death_String);
		Death_Texture.loadFromImage(Death_Image);
		
		down_attack_Image.loadFromFile(down_attack_String);
		up_attack_Image.loadFromFile(up_attack_String);
		left_attack_Image.loadFromFile(left_attack_String);
		righ_attack_Image.loadFromFile(righ_attack_String);

		down_attack_Texture.loadFromImage(down_attack_Image);
		up_attack_Texture.loadFromImage(up_attack_Image);
		left_attack_Texture.loadFromImage(left_attack_Image);
		righ_attack_Texture.loadFromImage(righ_attack_Image);
		

		Idle_Texture.loadFromImage(Idle_Image);
		walkRight_Texture.loadFromImage(walkRight_Image);
		walkLeft_Texture.loadFromImage(walkLeft_Image);
		upWalk_Texture.loadFromImage(upWalk_Image);
		downWalk_Texture.loadFromImage(downWalk_Image);

		Enemy_Sprite.setTexture(Idle_Texture);
		Enemy_Sprite.setScale(1.9, 1.9);

		Enemy_Sprite.setTextureRect(sf::IntRect(0, 0, 48, 48));
		Enemy_Sprite.setPosition(x, y);
	}

	void EnemyUpdate(float time, Player& player);
	void EnemyTakeDamage();
	void EnemyAnimation(float CurentFrame, float time);
	void TakeDamageAnimation(float CurentFrame, float time);
	void DeathAnimation(float CurentFrame, float time);
	void AttackAnimation(float CurentFrame, Player& p1);
};