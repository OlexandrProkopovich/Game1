#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <cstdlib>  
#include <ctime>    
#include <vector>
#include <list>
#include <sstream>
#include "Player.h"
#include "GameMenu.h"
#include "Interface.h"
#include "func.h"
#include "Enemy.h"

void Statistic() {
	sf::RenderWindow stat(sf::VideoMode(1024, 1024), "Player statistics");

	Interface background("images/background.png", 1024, 1024);
	sf::Text Titul;
	background.WorkText("font/Maestroc.otf", Titul, 140, 50, L"PLAYER STATISTICS", 150, sf::Color(237, 147, 0), 0, sf::Color::Black);
	while (stat.isOpen())
	{
		sf::Event event_stat;
		while (stat.pollEvent(event_stat))
		{
			if (event_stat.type == sf::Event::Closed) { stat.close(); }
			if (event_stat.type == sf::Event::KeyPressed)
			{
				if (event_stat.key.code == sf::Keyboard::Escape) { stat.close(); }
			}
		}
		stat.clear();
		stat.draw(background.background);
		stat.draw(Titul);
		stat.display();

	}
}

void GameStart()
{
	sf::RenderWindow Play(sf::VideoMode(1024, 1024), "TestSFML");
	std::srand(static_cast<unsigned>(std::time(nullptr)));
	float x, y;
	Player p1("images/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Down/Png/Idle.png", "images/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Right/Png/walk.png",
		"images/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Left/Png/walk.png", "images/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Up/Png/walk.png",
		"images/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Down/Png/walk.png", 900, 900, 48, 48, Play, "images/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Down/Png/down_attack.png",
		"images/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Up/Png/up_attack.png", "images/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Left/Png/left_attack.png",
		"images/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Foozle_2DC0011_Lucifer_Sorceress_Pixel_Art/Right/Png/right_attack.png");

	Enemy enemy1("images/Foozle_2DC0018_Lucifer_Skeleton_Grunt_Pixel_Art/Foozle_2DC0018_Lucifer_Skeleton_Grunt_Pixel_Art/Down/Png/Idle.png", "images/Foozle_2DC0018_Lucifer_Skeleton_Grunt_Pixel_Art/Foozle_2DC0018_Lucifer_Skeleton_Grunt_Pixel_Art/Right/Png/right_run.png",
		"images/Foozle_2DC0018_Lucifer_Skeleton_Grunt_Pixel_Art/Foozle_2DC0018_Lucifer_Skeleton_Grunt_Pixel_Art/Left/Png/left_run.png", "images/Foozle_2DC0018_Lucifer_Skeleton_Grunt_Pixel_Art/Foozle_2DC0018_Lucifer_Skeleton_Grunt_Pixel_Art/Up/Png/up_run.png",
		"images/Foozle_2DC0018_Lucifer_Skeleton_Grunt_Pixel_Art/Foozle_2DC0018_Lucifer_Skeleton_Grunt_Pixel_Art/Down/Png/down_run.png", 400, 400);
	std::vector<Enemy> enemies;
	
	Bullet fireBall("images/fire/Right.png", "images/fire/Left.png", "images/fire/Up.png", "images/fire/Down.png", 1);
	//fireBall.SetBulletPosition(p1);     // якщо треба одну кулю розкомітити

	std::vector<Bullet> bullets;
	

	Interface background("images/grass.png", 1024, 1024);

	sf::Text text;
	background.WorkText("font/Maestroc.otf", text, 17, 0, L"time in game: ", 50, sf::Color::Black, 0, sf::Color::Black);

	float CurentFrame = 0;
	sf::Clock clock;

	sf::Clock gameTimeClock_in_second;
	int gameTime_in_second = 0;

	sf::Clock enemySpawnTimer;
	
	sf::Clock AttackColdown;

	while (Play.isOpen())
	{
	
		float time = clock.getElapsedTime().asMicroseconds();          //час гри
		clock.restart();
		time /= 800;

		gameTime_in_second = gameTimeClock_in_second.getElapsedTime().asSeconds();  // час у грі(таймер)
		
		float elapsedTime = enemySpawnTimer.getElapsedTime().asMicroseconds(); // для часу спавну ворогів
		
		float elapsedTime1 = AttackColdown.getElapsedTime().asMicroseconds();	// для кулдауна атаки

		sf::Event event_play;
		while (Play.pollEvent(event_play))
		{
			if (event_play.type == sf::Event::Closed) { Play.close(); }
			if (event_play.type == sf::Event::KeyPressed)
			{
				if (event_play.key.code == sf::Keyboard::Escape) { Play.close(); std::cout << gameTime_in_second << std::endl; }
			}
		}

		p1.dir = 4;
		if (p1.dir == 4)
		{
			p1.Animation(time, CurentFrame);
		}  
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) {
			p1.dir = 1; p1.speed = 0.2;
			p1.Animation(time, CurentFrame);
		} 
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D))))
		{
			p1.dir = 0; p1.speed = 0.2;
			p1.Animation(time, CurentFrame);
		} 
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W))))
		{
			p1.dir = 3; p1.speed = 0.2;
			p1.Animation(time, CurentFrame);
		} 
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S))))
		{
			p1.dir = 2; p1.speed = 0.2;
			p1.Animation(time, CurentFrame);
		} 
		
		p1.Update(time);

		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			p1.startAttack();
			fireBall.SetBulletPosition(p1);								  // якщо багато куль треба то розкомітити
			bullet_spawn(fireBall, bullets, elapsedTime1, AttackColdown);                                //для багатьох куль оновити анімацію
			bullet_update(time, CurentFrame, bullets, enemy1);              //для багатьох куль оновити рух
			
			//fireBall.BulletAnimation(time, CurentFrame);                                //для одиночної кулі оновити анімацію
			//fireBall.BulletUpdate(time, enemy1);									   	//для одиночної кулі оновити рух
		}
		else {
			p1.stopAttack();
		}
		
		
		std::ostringstream gameTimeStringInSecond;
		gameTimeStringInSecond << gameTime_in_second;
		text.setString("Time in game: " + gameTimeStringInSecond.str());

		//RandomSpawn(elapsedTime, Play, enemy1, enemies, enemySpawnTimer);                //спавнер ворогів

		Play.clear();
		Play.draw(background.background);

		//DrawEnemy(enemies, Play, time, p1, CurentFrame);                                 //малювати ворогів
		         
		buller_draw(Play, bullets);                                                        //малювати пулі


	    Play.draw(enemy1.Enemy_Sprite);
		Play.draw(p1.Hero_Sprite);
		//Play.draw(fireBall.Bullet_Sprite);                                               //малювати одиночну пулю
		Play.draw(text);
		Play.display();
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 1024), "TestSFML");

	Interface background("images/background.png", 1024, 1024);

	sf::Text Titul;
	background.WorkText("font/Maestroc.otf", Titul, 260, 50, L"KURSACH", 200, sf::Color(237, 147, 0), 0, sf::Color::Black);

	std::vector<sf::String> name_button = { L"Нова гра", L"Результати", L"Вийти" };

	game::GameMenu mymenu(window, 500, 400, 100, 120, name_button);
	mymenu.setColorTextMenu(sf::Color(237, 147, 0), sf::Color::Red, sf::Color::Black);
	mymenu.AlignMenu(2);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) { window.close(); }
			if (event.type == sf::Event::KeyReleased)
			{
				
				if (event.key.code == sf::Keyboard::Up) { mymenu.MoveUp(); }
				if (event.key.code == sf::Keyboard::Down) { mymenu.MoveDown(); }
				if (event.key.code == sf::Keyboard::Return) 
				{
					switch (mymenu.getSelectedMenuNumber())
					{
					case 0: GameStart(); break;
					case 1: Statistic(); break;
					case 2: window.close(); break;
					}
				}
			}
		}
		window.clear();
		window.draw(background.background);
		window.draw(Titul);
		mymenu.draw();
		window.display();
	}
} 
