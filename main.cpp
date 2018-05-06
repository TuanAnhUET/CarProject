#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include "Game.h"
#include "Menu.h"

using namespace std;
using namespace sf;

const string PathImages = "Assets/Texture";

int main(int argc, char* argv[])
{

    RenderWindow window(VideoMode(1000, 400), "Car Racing by Tuan Anh", Style::Close);
    window.setFramerateLimit(60);

    // Chỉnh Icon cho window
    Image Icon;
    Icon.loadFromFile("Assets/Texture/Icon.png");
    window.setIcon(Icon.getSize().x, Icon.getSize().x, Icon.getPixelsPtr());

    Music music;
	music.openFromFile("Assets/Main.wav");
	music.setLoop(true);
	music.play();

    bool checkchoosewindow = true;
    // Game Loop
    srand(time(NULL));
    Menu menu(&window);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::LostFocus)
                checkchoosewindow = false;
            if (event.type == Event::GainedFocus)
                checkchoosewindow = true;
        }
        if (checkchoosewindow)
        {
            window.clear();
            if (menu.update())
                break;
            menu.draw();
            window.display();
        }
    }

    Game Game(&window);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::LostFocus)
                checkchoosewindow = false;
            if (event.type == Event::GainedFocus)
                checkchoosewindow = true;
        }
        if (checkchoosewindow)
        {
            window.clear();
            Game.draw();
            if (!Game.update())
            {
                window.close();
            }
            window.display();
        }
    }


    return EXIT_SUCCESS;
}
