#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
class Bullet {
public:
    float speed = 0;
    float x, y;

    sf::Vector2f direction;

    std::string bullet_Right;
    std::string bullet_Left;
    std::string bullet_Up;
    std::string bullet_Down;

    sf::Image bulletRight_image;
    sf::Image bulletLeft_image;
    sf::Image bulletUp_image;
    sf::Image bulletDown_image;

    sf::Texture bulletRight_Texture;
    sf::Texture bulletLeft_Texture;
    sf::Texture bulletUp_Texture;
    sf::Texture bulletDown_Texture;

    sf::Sprite Bullet_Sprite;


    Bullet(std::string _bullet_Right, std::string _bullet_Left, std::string _bullet_Up, std::string _bullet_Down, float _speed) : bullet_Right(_bullet_Right), bullet_Left(_bullet_Left),
        bullet_Up(_bullet_Up), bullet_Down(_bullet_Down), speed(_speed)
    {
        bulletRight_image.loadFromFile(bullet_Right);
        bulletLeft_image.loadFromFile(bullet_Left);
        bulletUp_image.loadFromFile(bullet_Up);
        bulletDown_image.loadFromFile(bullet_Down);

        bulletRight_Texture.loadFromImage(bulletRight_image);
        bulletLeft_Texture.loadFromImage(bulletLeft_image);
        bulletUp_Texture.loadFromImage(bulletUp_image);
        bulletDown_Texture.loadFromImage(bulletDown_image);

        Bullet_Sprite.setTexture(bulletDown_Texture);
        Bullet_Sprite.setPosition(x, y);
    }

    void SetBulletPosition(const Player& player);

    void BulletUpdate(float time, const Enemy& enemies);

    void BulletUpdate_array(float time, const std::vector<Enemy>& enemies);

    float getDistance(const sf::Vector2f& v1, const sf::Vector2f& v2);

    void BulletAnimation(float time, float CurentFrame);
};