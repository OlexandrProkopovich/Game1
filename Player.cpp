#include "Player.h"



void Player::Update(float time)
{
    if(!isDead){
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
}

void Player::Animation(float time, float CurentFrame)
{
    if(!isDead){
    int framesInTexture = 6;  // Замініть це значення на реальну кількість кадрів у вашій текстурі анімації
    if (dir == 0) {
        Hero_Sprite.setTexture(walkRight_Texture); Hero_Sprite.setScale(1.8, 1.8);
   
        if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; }
        Hero_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
    }
    else if (dir == 1) {
        Hero_Sprite.setTexture(walkLeft_Texture); Hero_Sprite.setScale(1.8, 1.8);
     
        if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; }
        Hero_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
    }
    else if (dir == 2) {
        Hero_Sprite.setTexture(downWalk_Texture); Hero_Sprite.setScale(1.8, 1.8);

        if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; }
        Hero_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
    }
    else if (dir == 3) {
        Hero_Sprite.setTexture(upWalk_Texture); Hero_Sprite.setScale(1.8, 1.8);
     
        if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; }
        Hero_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
    }
    else if (dir == 4) {
        Hero_Sprite.setTexture(Idle_Texture); Hero_Sprite.setScale(1.8, 1.8);

        if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; }
        Hero_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
    }
    }
}


void Player::AttackAnimation(float time, float CurentFrame) {
    if (isShooting && !isDead)
    {
        int framesInTexture = 5;  // Замініть це значення на реальну кількість кадрів у вашій текстурі анімації
        if (dir == 0) {
            Hero_Sprite.setTexture(righ_attack_Texture);  Hero_Sprite.setScale(1.8, 1.8);
         
            if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; }
            Hero_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
        }
        else if (dir == 1) {
            Hero_Sprite.setTexture(left_attack_Texture);  Hero_Sprite.setScale(1.8, 1.8);
           
            if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; }
            Hero_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
        }
        else if (dir == 2) {
            Hero_Sprite.setTexture(down_attack_Texture);  Hero_Sprite.setScale(1.8, 1.8);
            
            if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; }
            Hero_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
        }
        else if (dir == 3) {
            Hero_Sprite.setTexture(up_attack_Texture);  Hero_Sprite.setScale(1.8, 1.8);
        
            if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; }
            Hero_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
        }
        else if (dir == 4) {
            Hero_Sprite.setTexture(down_attack_Texture);  Hero_Sprite.setScale(1.8, 1.8);
 
            if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; }
            Hero_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
        }
    }
}


void Player::TakeDamageAnimation(float CurentFrame, float time) {
    if (TakeDamage && !isDead) {
        int framesInTexture = 4;
        if (dir == 0) {
            Hero_Sprite.setTexture(TakeDamage_Right_Texture); Hero_Sprite.setScale(1.8, 1.8);
            if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; TakeDamage = false; }
            Hero_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
        }
        else if (dir == 1) {
            Hero_Sprite.setTexture(TakeDamage_Left_Texture); Hero_Sprite.setScale(1.8, 1.8);
            if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; TakeDamage = false;
            }
            Hero_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
        }
        else if (dir == 3) {
            Hero_Sprite.setTexture(TakeDamage_Up_Texture); Hero_Sprite.setScale(1.8, 1.8);
            if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; TakeDamage = false;
            }
            Hero_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
        }
        else if (dir == 2) {
            Hero_Sprite.setTexture(TakeDamage_Down_Texture); Hero_Sprite.setScale(1.8, 1.8);
            if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; TakeDamage = false;
            }
            Hero_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
        }
        else if (dir == 4) {
            Hero_Sprite.setTexture(TakeDamage_Down_Texture);  Hero_Sprite.setScale(1.8, 1.8);
            if (CurentFrame >= framesInTexture) { CurentFrame -= framesInTexture; TakeDamage = false;
            }
            Hero_Sprite.setTextureRect(sf::IntRect(48 * static_cast<int>(CurentFrame), 0, 48, 48));
        }
    }
    else if (isDead)
    {
        Hero_Sprite.setTexture(Death_Texture);
    }
}

void Player::DeathAnimation(float CurentFrame) {
    const int framesInTexture = 8;

    if (isDead && !deathAnimationFinished)
    {
        speed = 0;
        Hero_Sprite.setTexture(Death_Texture);
        Hero_Sprite.setScale(1.8, 1.8);

        if (CurentFrame >= framesInTexture)
        {
            CurentFrame = framesInTexture - 0.01; // Незначний зсув для коректного виведення останнього кадру
            deathAnimationFinished = true;
        }

        const int frameIndex = static_cast<int>(CurentFrame);
        Hero_Sprite.setTextureRect(sf::IntRect(48 * frameIndex, 0, 48, 48));
    }
}

void Player::startAttack() {
	isShooting = true;
}

void Player::stopAttack() {
	isShooting = false;
}