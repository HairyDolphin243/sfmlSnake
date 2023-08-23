//
// Created by nickobelic1999 on 31/07/2023.
//

#pragma once

#include "SFML/Graphics.hpp"

#include <list>
#include <random>

#include "Engine.hpp"
#include "Food.hpp"

#define BOX_SIZE 32

namespace CoreGame
{
    class Random
    {
        /* A utility class that will be used to generate random numbers */
        std::random_device rd;
        std::mt19937 gen;
    public:

        Random() { gen.seed(rd()); }

        int getRandomInt(int l, int u)
        {
            std::uniform_int_distribution<int> dist(l, u);
            return dist(gen);
        }

    };

    class Snake
    {
        /*
        This class represents the snake.
        It is represented as a Vector of sf::RectangleShape objects.
        */
    public:

        void drawSnake();
        bool died();
        bool ateFood(CoreGame::Food *fd);
        void updateSpeed(float speed);
        void moveSnake(sf::Vector2<int> direction);

        sf::Vector2f getNextFoodLocation();

        Snake(sf::RenderWindow *);

    private:
        sf::RenderWindow *screen;
        Random rand;

        /* Used to determine whether or not to increment length of snake */
        bool updateLength;

        /* The rate of movement of snake */
        float movementScale;

        /* Snake parameters */
        int snake_length;
        std::list<sf::Vector2<int> > snake_direction_list;
        sf::Vector2<int> lastDirection;
        std::vector<sf::RectangleShape> body;

        /* Load from options */
        sf::Color colorBody;
        sf::Color colorHead;
    };
}

