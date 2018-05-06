#ifndef THREAT_H
#define THREAT_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <cstdlib>
#include <time.h>

class threat
{
private:
    sf::RenderWindow* m_window;
    sf::Sprite          m_sprite;
public:
    threat(sf::RenderWindow* window, sf::Texture& texture);
    void        update();
    void        draw();
    sf::Vector2f   getPosition();

};

#endif // THREAT_H
