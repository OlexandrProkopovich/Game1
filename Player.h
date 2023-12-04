#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
public:
	float x, y, w, h, dx, dy, speed;
	bool isShooting = false;
	bool TakeDamage = false;
	bool TakeDamageEnd = false;
	bool isDead;
	bool deathAnimationFinished;
	int health = 20;
	int dir = 4;
	std::string Idle_String;
	std::string walkRight_String;
	std::string walkLeft_String;
	std::string upWalk_String;
	std::string downWalk_String;

	std::string down_attack_String;
	std::string up_attack_String;
	std::string left_attack_String;
	std::string righ_attack_String;


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

	std::string Death_String;
	sf::Image Death_Image;
	sf::Texture Death_Texture;

	sf::Sprite Hero_Sprite;

	sf::RenderWindow& Play;
	Player() = default;
	Player(std::string Idle_String, std::string walkRight_String, std::string walkLeft_String, std::string upWalk_String, std::string downWalk_String, float _speed,
		int X, int Y, float W, float H, sf::RenderWindow &Play, std::string _down_attack, std::string _up_attack, std::string _left_attack, std::string _righ_attack, std::string _TakeDamage_Right_String,
		std::string _TakeDamage_Left_String, std::string _TakeDamage_Up_String, std::string _TakeDamage_Down_String, std::string _Death_String): Play(Play),
		Idle_String(Idle_String), walkRight_String(walkRight_String), walkLeft_String(walkLeft_String), upWalk_String(upWalk_String),
		downWalk_String(downWalk_String), speed(_speed), x(X), y(Y), w(W), h(H), down_attack_String(_down_attack), up_attack_String(_up_attack), left_attack_String(_left_attack),
		righ_attack_String(_righ_attack), TakeDamage_Right_String(_TakeDamage_Right_String), TakeDamage_Left_String(_TakeDamage_Left_String),
		TakeDamage_Up_String(_TakeDamage_Up_String), TakeDamage_Down_String(_TakeDamage_Down_String), Death_String(_Death_String)
	{
		isDead = false;
		deathAnimationFinished = false;
		Death_Image.loadFromFile(Death_String);
		Death_Texture.loadFromImage(Death_Image);

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

		Hero_Sprite.setPosition(x, y);
	}
	
	void Update(float time);
	void Animation(float time, float CurentFrame);
	void AttackAnimation(float time, float CurentFrame);
	void TakeDamageAnimation(float CurentFrame, float time);
	void DeathAnimation(float CurentFrame);
	void startAttack();
	void stopAttack();
};

