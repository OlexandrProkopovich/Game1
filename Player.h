#pragma once
#include <SFML/Graphics.hpp>
class PLayer
{
public:
	float x, y, w, h, dx, dy, speed = 0;
	int dir = 0;
	sf::String file;
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
	PLayer(sf::String F, int X, int Y, float W, float H) : file(F), x(X), y(Y), w(W), h(H) 
	{
		image.loadFromFile("image/" + file);
		image.createMaskFromColor(sf::Color(41, 33, 59));
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(w, h, w, h));
	}
	void Update(float time)
	{
		switch (dir)
		{
		case 0: dx = speed; dy = 0; break;
		case 1: dx = -speed; dy = 0; break;
		case 2: dx = 0; dy = speed; break;
		case 3: dx = 0; dy = -speed; break;
		}

		x += dx * time;
		y += dy * time;

		speed = 0;
		sprite.setPosition(x, y);
	}
};