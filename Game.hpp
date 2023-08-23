//
// Created by nickobelic1999 on 2/08/2023.
//

#pragma once

#include "Snake.hpp"
#include "Food.hpp"

#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>

namespace CoreGame
{
    /*
    GameController is the central interface of the game.
    This class will monitor the working of game:
    *	Movement of snake
    *	Checking collisions
    *	When to play sound etc
    */


    const std::string MenuStrings[5] =
    {
        "Game Over!",
        "Do you wish to continue?",
        "Yes",
        "No",
        "Exit"
    }; //menu strings

    enum MenuText
    {
        GameOver,
        Continue,
        Yes,
        No,
        Exit,
    }; //menuText

    enum Fonts
    {};

    class GameController
    {
    public:

        void start();

        __attribute__((unused)) sf::Font* getFont(Fonts font);


        explicit GameController(sf::RenderWindow* w);

    private:

        //Main game loop
        void gameLoop();

        //Setup scene
        void setupScene();

        //Writes New Score to Scoring File
        void submitScore(const std::string& file);

        // Game over
        void gameOver();

        //load resources
        void loadResources();

        float                   scale;
        int                     score;
        bool                    loopInvarient;

        Snake                   snake;
        sf::RenderWindow*       screen;
        sf::Font                fontList[3];

        std::fstream highscores;
    };

}


