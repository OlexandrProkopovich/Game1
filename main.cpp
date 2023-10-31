#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "TestSFML");
	//__________________________________________________________подгрузка изображений_____________________________________________________________________________
	sf::Image MainHeroIdle;
	MainHeroIdle.loadFromFile("images/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Down/Png/Idle.png");
	
	sf::Image MainHeroRightWalk;
	MainHeroRightWalk.loadFromFile("images/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Right/Png/walk.png");
	
	sf::Image MainHeroLeftWalk;
	MainHeroLeftWalk.loadFromFile("images/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Left/Png/walk.png");
	
	sf::Image MainHeroUpWalk;
	MainHeroUpWalk.loadFromFile("images/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Up/Png/walk.png");
	
	sf::Image MainHeroDownWalk;
	MainHeroDownWalk.loadFromFile("images/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Down/Png/walk.png");
	//______________________________________________________________________________________________________________________________________________________________
	//_________________________________________________________СОЗДАНИЕ ТЕКСТРУ____________________________________________________________________________-
	
	sf::Texture MainHeroIdleTexture;
	MainHeroIdleTexture.loadFromImage(MainHeroIdle);

	sf::Texture MainHeroRightWalkTexture;
	MainHeroRightWalkTexture.loadFromImage(MainHeroRightWalk);

	sf::Texture MainHeroLeftWalkTexture;
	MainHeroLeftWalkTexture.loadFromImage(MainHeroLeftWalk);

	sf::Texture MainHeroUpWalkTexture;
	MainHeroUpWalkTexture.loadFromImage(MainHeroUpWalk);

	sf::Texture MainHeroDownWalkTexture;
	MainHeroDownWalkTexture.loadFromImage(MainHeroDownWalk);
	//______________________________________________________________________________________________________________________________________________________________________
	//____________________________________________________________СОЗДАНИЕ СПРАЙТОВ_________________________________________________________________________________________

	sf::Sprite MainHero;
	MainHero.setTexture(MainHeroIdleTexture);
	MainHero.setScale(1.8, 1.8);

	//________________________________________________________________________________________________________________________________________________________________________

	float CurentFrame = 0;
	sf::Clock clock;

	sf::Clock fpsClock;
	int frameCount = 0;
	float fpsTimer = 0;

	while (window.isOpen())
	{
		
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart(); 
		time /= 1000;
		//std::cout << time << "\n";
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		MainHero.setTexture(MainHeroIdleTexture);
		CurentFrame += time * 0.005; //переменная для текущого кадра
		if (CurentFrame >= 3) { CurentFrame -= 3; }
		MainHero.setTextureRect(sf::IntRect(48 * (int)CurentFrame, 0, 48, 48));

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) {
			CurentFrame += time * 0.005;
			MainHero.setTexture(MainHeroLeftWalkTexture);
			if (CurentFrame >= 3) { CurentFrame -= 3; }
			MainHero.move(-0.2 * time, 0);
			MainHero.setTextureRect(sf::IntRect(48 * (int)CurentFrame, 0, 48, 48));
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) 
		{ 
			CurentFrame += time * 0.005;
			MainHero.setTexture(MainHeroRightWalkTexture);
			if (CurentFrame >= 3) { CurentFrame -= 3; }
			MainHero.move(0.2 * time, 0);
			MainHero.setTextureRect(sf::IntRect(48 * (int)CurentFrame, 0, 48, 48));
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))) 
		{
			CurentFrame += time * 0.005;
			MainHero.setTexture(MainHeroUpWalkTexture);
			if (CurentFrame >= 3) { CurentFrame -= 3; }
			MainHero.move(0, -0.2 * time);
			MainHero.setTextureRect(sf::IntRect(48 * (int)CurentFrame, 0, 48, 48));
		}
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) 
		{
			CurentFrame += time * 0.005;
			MainHero.setTexture(MainHeroDownWalkTexture);
			if (CurentFrame >= 3) { CurentFrame -= 3; }
			MainHero.move(0, 0.2 * time);
			MainHero.setTextureRect(sf::IntRect(48 * (int)CurentFrame, 0, 48, 48));
		}
		
		int FPS = fpsClock.getElapsedTime().asSeconds();
		if (FPS != fpsTimer)
		{
			std::cout << "FPS: " << frameCount << std::endl;
			frameCount = 0;
			fpsTimer = FPS;
		}

		window.clear(sf::Color::Black);
		window.draw(MainHero);
		window.display();

		frameCount++;
	}
} // 61 x 100