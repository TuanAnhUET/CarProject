#include "Player.h"

Player::Player(sf::RenderWindow* window) : m_countHeart(6)
{
    this->m_window = window;
    this->m_window->setMouseCursorVisible(false);
    this->m_texture_car.loadFromFile("Assets/Texture/Car_1.png");
    this->m_sprite_car.setRotation(90);
    this->m_texture_car.setSmooth(true);
    this->m_sprite_car.setTexture(this->m_texture_car);
    this->m_sprite_car.setOrigin(this->m_texture_car.getSize().x / 2, this->m_texture_car.getSize().y / 2);
    this->m_sprite_car.setPosition(50, 300);
    this->m_texture_heart.loadFromFile("Assets/Texture/Heart.png");
    this->m_texture_heart.setSmooth(true);
    this->m_sprite_heart.setTexture(this->m_texture_heart);

}

void Player::update()
{
    sf::Vector2f car_position = this->m_sprite_car.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        car_position.y += 5;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        car_position.y -= 5;
    if (car_position.y < 80)
        car_position.y = 80;
    if (car_position.y > 320)
        car_position.y = 320;
    this->m_sprite_car.setPosition(car_position.x, car_position.y);
}
void Player::draw()
{
    for (int i = 0; i < this->m_countHeart; i++)
    {
        this->m_sprite_heart.setPosition(5 + i * 15, 5);
        this->m_window->draw(this->m_sprite_heart);
    }
    this->m_window->draw(this->m_sprite_car);
}
int& Player::getCountHeart()
{
    return this->m_countHeart;
}

sf::Vector2f Player::getPosition()
{
    return this->m_sprite_car.getPosition();
}
