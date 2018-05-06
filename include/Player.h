#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <string>

class Player
{
private:

    sf::RenderWindow*   m_window;
    sf::Texture         m_texture_car;;
    sf::Sprite          m_sprite_car;
    sf::Texture         m_texture_heart;
    sf::Sprite          m_sprite_heart;
    int                 m_countHeart;

public:
    Player(sf::RenderWindow* window);
    void   update();
    void   draw();
    int&   getCountHeart();
    sf::Vector2f   getPosition();
};

#endif // PLAYER_H
