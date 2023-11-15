#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
class Enemy {
public:
	float x, y, speed = 0;
	bool isAttacking = false;
	int health = 10;

	sf::Vector2f direction;

	std::string Idle_String;
	std::string walkRight_String;
	std::string walkLeft_String;
	std::string upWalk_String;
	std::string downWalk_String;

	/*std::string down_attack_String;
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
	*/
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
		int X, int Y) : 
		Idle_String(_Idle_String), walkRight_String(_walkRight_String), walkLeft_String(_walkLeft_String), upWalk_String(_upWalk_String),
		downWalk_String(_downWalk_String), x(X), y(Y)
	{
		Idle_Image.loadFromFile(Idle_String);
		walkRight_Image.loadFromFile(walkRight_String);
		walkLeft_Image.loadFromFile(walkLeft_String);
		upWalk_Image.loadFromFile(upWalk_String);
		downWalk_Image.loadFromFile(downWalk_String);
		/*
		down_attack_Image.loadFromFile(down_attack_String);
		up_attack_Image.loadFromFile(up_attack_String);
		left_attack_Image.loadFromFile(left_attack_String);
		righ_attack_Image.loadFromFile(righ_attack_String);

		down_attack_Texture.loadFromImage(down_attack_Image);
		up_attack_Texture.loadFromImage(up_attack_Image);
		left_attack_Texture.loadFromImage(left_attack_Image);
		righ_attack_Texture.loadFromImage(righ_attack_Image);
		*/
		
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
	void EnemyAnimation(float CurentFrame, float time);
};


