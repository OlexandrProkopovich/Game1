#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
public:
	float x, y, w, h, dx, dy, speed = 0;
	bool isShooting = false;
	int health = 100;
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

	sf::Sprite Hero_Sprite;

	sf::RenderWindow& Play;
	Player() = default;
	Player(std::string Idle_String, std::string walkRight_String, std::string walkLeft_String, std::string upWalk_String, std::string downWalk_String,
		int X, int Y, float W, float H, sf::RenderWindow &Play, std::string _down_attack, std::string _up_attack, std::string _left_attack, std::string _righ_attack): Play(Play), 
		Idle_String(Idle_String), walkRight_String(walkRight_String), walkLeft_String(walkLeft_String), upWalk_String(upWalk_String),
		downWalk_String(downWalk_String), x(X), y(Y), w(W), h(H), down_attack_String(_down_attack), up_attack_String(_up_attack), left_attack_String(_left_attack),
		righ_attack_String(_righ_attack)
	{
		Idle_Image.loadFromFile(Idle_String);
		walkRight_Image.loadFromFile(walkRight_String);
		walkLeft_Image.loadFromFile(walkLeft_String);
		upWalk_Image.loadFromFile(upWalk_String);
		downWalk_Image.loadFromFile(downWalk_String);

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
	void Animation(float time, float& CurentFrame);
	void startAttack();
	void stopAttack();
};

