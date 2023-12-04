#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;

const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

const int numSmallBoxes = 2; // Set the number of small boxes

class Box
{
public:
    RectangleShape shape;
    int direction; // Direction of movement for the box

    // Default constructor
    Box()
        : direction(0) // Set a default direction (you can adjust as needed)
    {
        // Set default properties or leave them uninitialized as needed
    }

    // Parameterized constructor
    Box(float x, float y, float width, float height, int initialDirection)
        : direction(initialDirection)
    {
        shape.setSize(Vector2f(width, height));
        shape.setPosition(x, y);
        shape.setFillColor(Color::Red); // Adjust the color as needed
    }

    void move(float speed, float offsetY)
    {
        shape.move(speed * direction, offsetY);
    }
};


class Game
{
public:
    Sprite background; // Game background sprite
    Texture bg_texture;
    Box smallBoxes[numSmallBoxes]; // Declare the array here
    int direction = 1; // Variable to store the direction of movement

    Game()
    {
        bg_texture.loadFromFile("img/background.jpg");
        background.setTexture(bg_texture);
        background.setScale(2, 1.5);
        initializeSmallBoxes();
    }

    void initializeSmallBoxes()
    {
        // Add code here to initialize small boxes as needed
        smallBoxes[0] = Box(200.f, 300.f, 30.f, 30.f, 1); // Initial direction is 1 (right)
        smallBoxes[1] = Box(400.f, 500.f, 30.f, 30.f, -1); // Initial direction is -1 (left)
    }

    void start_game()
    {
        srand(time(0));
        RenderWindow window(VideoMode(780, 780), title);
        Clock clock;
        float timer = 0;

        while (window.isOpen())
        {
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;

            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                    window.close();
            }

            window.clear(Color::Black);
            window.draw(background);

            // Move and draw small boxes
            for (int i = 0; i < numSmallBoxes; ++i)
            {
                float speed = 2.0f;
                smallBoxes[i].move(speed, 0.0f);

                if (smallBoxes[i].shape.getPosition().x + smallBoxes[i].shape.getSize().x > window.getSize().x ||
                    smallBoxes[i].shape.getPosition().x < 0)
                {
                    smallBoxes[i].direction = -smallBoxes[i].direction;
                }

                window.draw(smallBoxes[i].shape);
            }

            window.display();
        }
    }
};
