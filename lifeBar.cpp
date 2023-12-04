#include "lifeBar.h"


void lifeBar::Update_LifeBar(const Player& p1)
{
	if (p1.health > 15)
	{
		
		LifeBar.setTextureRect(sf::IntRect(156, 0, 64, 12));
	}
	else if (p1.health > 10 && p1.health <= 15)
	{
		
		LifeBar.setTextureRect(sf::IntRect(156, 79, 64, 12));
	}
	else if (p1.health > 5 && p1.health <= 10)
	{
		
		LifeBar.setTextureRect(sf::IntRect(156, 158, 64, 12));
	}
	else if (p1.health >= 1 && p1.health <= 5)
	{
		
		LifeBar.setTextureRect(sf::IntRect(156, 237, 64, 12));
	}
	else if (p1.health <= 0)
	{

		LifeBar.setTextureRect(sf::IntRect(156, 316, 64, 12));
	}
}