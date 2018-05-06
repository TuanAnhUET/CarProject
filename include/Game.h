#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include "threat.h"
#include "Player.h"
#include <list>

class Game
{
private:
    sf::RenderWindow*        m_window;

    sf::Texture              m_texture_threat_1;
    sf::Texture              m_texture_threat_2;
    sf::Texture              m_texture_threat_3;
    sf::Texture              m_texture_Road;
    sf::Sprite               m_sprite_Road;

    Player*                  m_player;
    std::list<threat>        m_threat;
    sf::Clock                m_clock;
    sf::Time                 m_time;

    unsigned int             m_score;

    sf::Font                 m_font;
    sf::Text                 m_text;

public:
    Game(sf::RenderWindow* window);
    bool        update();
    void        draw();

};

#endif // GAME_H
