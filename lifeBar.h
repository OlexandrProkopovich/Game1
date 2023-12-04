#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Player.h"
class lifeBar
{
public:
	float x_pos, y_pos;
	std::string life_bar;
	sf::Image life_bar_image;
	sf::Texture life_bar_texture;
	/*std::string three_quarters_bar;
	std::string half_bar;
	std::string one_quarter_bar;
	std::string empty_bar;

	sf::Image full_bar_image;
	sf::Image three_quarters_bar_image;
	sf::Image half_bar_image;
	sf::Image one_quarter_bar_image;
	sf::Image empty_bar_image;

	sf::Texture full_bar_texture;
	sf::Texture three_quarters_texture;
	sf::Texture half_bartexture;
	sf::Texture one_quarter_bartexture;
	sf::Texture empty_bartexture;
	*/
	sf::Sprite LifeBar;

	lifeBar(float _x_pos, float _y_pos, std::string _life_bar) : x_pos(_x_pos), y_pos(_y_pos), life_bar(_life_bar)
	{
		life_bar_image.loadFromFile(life_bar);
		life_bar_texture.loadFromImage(life_bar_image);

		LifeBar.setTexture(life_bar_texture); LifeBar.setScale(3, 3);
		LifeBar.setPosition(x_pos, y_pos);
	}

	void Update_LifeBar(const Player& p1);
};

