#include "threat.h"

threat::threat(sf::RenderWindow* window, sf::Texture& texture)
{
    this->m_window = window;
    this->m_sprite.setTexture(texture);
    this->m_sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    this->m_sprite.setRotation(-90);

    int y = rand() % 250 + 70;
    int x = 1000;
    this->m_sprite.setPosition(x, y);
}

void threat::update()
{
    this->m_sprite.move(-5, 0);
}

void threat::draw()
{
    this->m_window->draw(this->m_sprite);
}

sf::Vector2f threat::getPosition()
{
    return this->m_sprite.getPosition();
}
