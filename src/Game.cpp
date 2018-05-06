#include "Game.h"

Game::Game(sf::RenderWindow*window) : m_score(0)
{
    this->m_window = window;
    this->m_player = new Player(this->m_window);

    this->m_texture_threat_1.loadFromFile("Assets/Texture/Car_3.png");
    this->m_texture_threat_1.setSmooth(true);

    this->m_texture_threat_2.loadFromFile("Assets/Texture/Car_2.png");
    this->m_texture_threat_2.setSmooth(true);

    this->m_texture_threat_3.loadFromFile("Assets/Texture/Car_4.png");
    this->m_texture_threat_3.setSmooth(true);

    this->m_texture_Road.loadFromFile("Assets/Texture/Background.png");
    this->m_texture_Road.setSmooth(true);
    this->m_sprite_Road.setTexture(this->m_texture_Road);


    this->m_font.loadFromFile("Assets/Font/Font.ttf");

    this->m_text.setFont(this->m_font);
    this->m_text.setString("Score : ");
    this->m_text.setCharacterSize(20);
    this->m_text.setPosition(900, 0);
    this->m_text.setFillColor(sf::Color::Red);

}
bool Game::update()
{
    this->m_player->update();
    if (this->m_threat.size() > 0)
    {
        for (std::list<threat>::iterator it = this->m_threat.begin(); it != this->m_threat.end(); it++)
        {
            it->update();
        }

        int x = abs(this->m_player->getPosition().x - this->m_threat.begin()->getPosition().x);

        int y = abs(this->m_player->getPosition().y - this->m_threat.begin()->getPosition().y);
        if (x <= 100 && y <= 50)
        {
            this->m_threat.pop_front();
            this->m_score += 10;
        }
        if (this->m_threat.size() > 0 && this->m_threat.begin()->getPosition().x <= 0)
        {
            this->m_threat.pop_front();
            this->m_player->getCountHeart()--;
        }
    }
    this->m_time = m_clock.getElapsedTime();


    if (this->m_time.asSeconds() > 0.5)
    {
        switch (rand() % 3)
        {
        case 0:
            this->m_threat.push_back(threat(this->m_window, this->m_texture_threat_1));
            break;
        case 1:
            this->m_threat.push_back(threat(this->m_window, this->m_texture_threat_2));
            break;
        case 2:
            this->m_threat.push_back(threat(this->m_window, this->m_texture_threat_3));
            break;
        }

        this->m_clock.restart();
    }

    char Point[10];
    sprintf(Point, "%d", this->m_score);
    std::string temp_1 = std::string(Point);

    this->m_text.setString("Score: " + temp_1);


    if (this->m_player->getCountHeart() >= 0)
        return true;
    else
    {
        char Point[10];
        sprintf(Point, "%d", this->m_score);
        std::string String = "Score : " + std::string(Point);
        if (MessageBox(NULL, String.c_str(), "Game Over", MB_OK) == IDOK)
            return false;
    }


}

void Game::draw()
{
    this->m_window->draw(this->m_sprite_Road);
    this->m_player->draw();

    if (this->m_threat.size() > 0)
    {
        for (std::list<threat>::iterator it = this->m_threat.begin(); it != this->m_threat.end(); it++)
        {
            it->draw();
        }
    }
    this->m_window->draw(this->m_text);
}
