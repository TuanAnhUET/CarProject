#include "Menu.h"

Menu::Menu(RenderWindow* window)
{
    this->m_window = window;

    this->m_font.loadFromFile("Assets/Font/Blazed.ttf");

    this->m_title.setFont(this->m_font);
    this->m_notification.setFont(this->m_font);
    this->m_notification_2.setFont(this->m_font);

    this->m_title.setString("Car Racing");
    this->m_notification.setString("Play");
    this->m_notification_2.setString("Quit");

    this->m_title.setCharacterSize(100);
    this->m_title.setPosition(500, 80);
    this->m_title.setOrigin(395, 50);         // Lấy điểm chính giữa của Text làm tâm
    this->m_title.setFillColor(Color::Green);

    this->m_notification.setCharacterSize(50);
    this->m_notification.setOrigin(91, 23);
    this->m_notification.setPosition(500, 220); // Lấy điểm chính giữa của Text làm tâm
    this->m_notification.setFillColor(Color::Red);

    this->m_notification_2.setCharacterSize(50);
    this->m_notification_2.setOrigin(82, 22);
    this->m_notification_2.setPosition(500, 300); // Lấy điểm chính giữa của Text làm tâm
    this->m_notification_2.setFillColor(Color::Red);

    this->m_texture.loadFromFile("Assets/Texture/Background.jpg");

    this->m_background.setTexture(this->m_texture);

}

bool Menu::update()
{
    Vector2i mouse_position = Mouse::getPosition(*this->m_window);

    if (mouse_position.x >= 409 && mouse_position.x <= 591 && mouse_position.y >= 197 && mouse_position.y <= 243)
    {
        this->m_notification.setFillColor(Color::Yellow);

        if (Mouse::isButtonPressed(Mouse::Left))
            return true;
    }
    else
    {
        this->m_notification.setFillColor(Color::Red);
    }

    if (mouse_position.x >= 468 && mouse_position.x <= 582 && mouse_position.y >= 278 && mouse_position.y <= 322)
    {
        this->m_notification_2.setFillColor(Color::Yellow);

        if (Mouse::isButtonPressed(Mouse::Left))
            this->m_window->close();
    }
    else
    {
        this->m_notification_2.setFillColor(Color::Red);
    }

    return false;
}

void Menu::draw()
{
    this->m_window->draw(this->m_background);

    this->m_window->draw(this->m_title);

    this->m_window->draw(this->m_notification);

    this->m_window->draw(this->m_notification_2);
}
