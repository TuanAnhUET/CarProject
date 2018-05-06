#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Menu
{
private:
    RenderWindow*         m_window;
    Font                  m_font;

    Text                  m_title;

    Text                  m_notification;
    Text                  m_notification_2;

    Texture               m_texture;
    Sprite                m_background;

public:
    Menu(RenderWindow* window);

    bool        update();
    void        draw();



};
