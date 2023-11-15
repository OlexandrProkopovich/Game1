#include "Player.h"



void Player::Update(float time)
{

	if (dir == 0) //right
	{ 
		dx = speed; dy = 0;
	}
	else
	if (dir == 1) // left
	{
		 dx = -speed; dy = 0;	
	}
	else
	if (dir == 2) // down
	{
		dx = 0; dy = speed;
	}
	else
	if (dir == 3) //up
	{
		 dx = 0; dy = -speed;
	}
	else
    if (dir == 4) //idle
	{
		dx = 0; dy = 0;				
	}

	float new_x = x + dx * time;
	float new_y = y + dy * time;


	if (new_x < -48)
		new_x = Play.getSize().x;
	else if (new_x > Play.getSize().x)
		new_x = -48;

	if (new_y < -48)
		new_y = Play.getSize().y;
	else if (new_y > Play.getSize().y)
		new_y = -48;

	x = new_x;
	y = new_y;

	Hero_Sprite.setPosition(x, y);

}

void Player::Animation(float time, float& CurentFrame)
{
	
	if (dir == 0) {
		Hero_Sprite.setTexture(walkRight_Texture); Hero_Sprite.setScale(1.8, 1.8);
		CurentFrame += time * 0.005;
		if (CurentFrame >= 3) { CurentFrame -= 3; }
		Hero_Sprite.setTextureRect(sf::IntRect(48 * (int)CurentFrame, 0, 48, 48));
		if (isShooting)
		{
			Hero_Sprite.setTexture(righ_attack_Texture);  Hero_Sprite.setScale(1.8, 1.8);
		}
	} else 
	if (dir == 1) {
		Hero_Sprite.setTexture(walkLeft_Texture); Hero_Sprite.setScale(1.8, 1.8);
		CurentFrame += time * 0.005;
		if (CurentFrame >= 3) { CurentFrame -= 3; }
		Hero_Sprite.setTextureRect(sf::IntRect(48 * (int)CurentFrame, 0, 48, 48));
		if (isShooting)
		{
				Hero_Sprite.setTexture(left_attack_Texture);  Hero_Sprite.setScale(1.8, 1.8);
		}
	} else
	if (dir == 2) {
		Hero_Sprite.setTexture(downWalk_Texture); Hero_Sprite.setScale(1.8, 1.8);
		CurentFrame += time * 0.005;
		if (CurentFrame >= 3) { CurentFrame -= 3; }
		Hero_Sprite.setTextureRect(sf::IntRect(48 * (int)CurentFrame, 0, 48, 48));
		if (isShooting)
		{
			Hero_Sprite.setTexture(down_attack_Texture);  Hero_Sprite.setScale(1.8, 1.8);
		}
	} else
	if (dir == 3) {
		Hero_Sprite.setTexture(upWalk_Texture); Hero_Sprite.setScale(1.8, 1.8);
		CurentFrame += time * 0.005;
		if (CurentFrame >= 3) { CurentFrame -= 3; }
		Hero_Sprite.setTextureRect(sf::IntRect(48 * (int)CurentFrame, 0, 48, 48));
		if (isShooting)
		{
			Hero_Sprite.setTexture(up_attack_Texture);  Hero_Sprite.setScale(1.8, 1.8);
		}
	} else
	if (dir == 4) {
		Hero_Sprite.setTexture(Idle_Texture); Hero_Sprite.setScale(1.8, 1.8); 
		CurentFrame += time * 0.005;
		if (CurentFrame >= 3) { CurentFrame -= 3; }
		Hero_Sprite.setTextureRect(sf::IntRect(48 * (int)CurentFrame, 0, 48, 48));
		if (isShooting)
		{
			Hero_Sprite.setTexture(down_attack_Texture);  Hero_Sprite.setScale(1.8, 1.8);
		}
	}
}

void Player::startAttack() {
	isShooting = true;
	std::cout << "isAttaking" << std::endl;
}

void Player::stopAttack() {
	isShooting = false;
	std::cout << "stopAttaking" << std::endl;
}