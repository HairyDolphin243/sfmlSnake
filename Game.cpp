//
// Created by nickobelic1999 on 2/08/2023.
//

#include "Game.hpp"

CoreGame::GameController::GameController(sf::RenderWindow *w) : snake(w)
{
    screen          = w;
    score           = 0;
    loopInvarient   = true;
}


void CoreGame::GameController::start()
{
    loadResources();
    gameLoop();
}

void CoreGame::GameController::gameLoop()
{

    sf::Vector2<int> direction(-1,0);
    scale = 5;
    Food *food = new Food(screen,snake.getNextFoodLocation());
    while(loopInvarient)
    {
        setupScene();
        food->drawFood();
        sf::Event event;
        while(screen->pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Up)
                {
                    direction.y = -1;
                    direction.x = 0;
                } else if (event.key.code == sf::Keyboard::Down) {
                    direction.y = 1;
                    direction.x = 0;
                }
                else if (event.key.code == sf::Keyboard::Left) {
                    direction.x = -1;
                    direction.y = 0;
                }
                else if (event.key.code == sf::Keyboard::Right) {
                    direction.x = 1;
                    direction.y = 0;
                }
            }
            if (event.type == sf::Event::Closed) {
                exit(0);
            }
        } //event loop
        snake.moveSnake(direction);
        if (snake.died()) {
            //game Over
            gameOver();

            submitScore("test.txt");

            //This is where the score needs to be saved
            //1 - Ask for Username
            //2 - Check for Username in json file
            //3 - Check score
            //4 - If score < than current score, update top score
            //5 - Order file from Highest-Lowest
            //6 - Write new file back out.

        }
        if (snake.ateFood(food))
        {
            //Updates Score
            score++;
            // Increase Snake Speed
            snake.updateSpeed(0.1);
            // Removes old food from screen and replaces it with new food
            delete food;
            food = new Food(screen, snake.getNextFoodLocation());
        }
        screen->display();
        screen->setFramerateLimit(60);
    }

}

void CoreGame::GameController::setupScene()
{
    screen->clear();
    snake.drawSnake();
}

void CoreGame::GameController::submitScore(const std::string& file)
{
    highscores.open(file, std::ios::out);

    if (!highscores)
    {
        std::cerr<< "Unable to create highscores file!/n";
    };

    else
    {
        std::cout << "Created highscores file/n"

        //Entered Info into the highscore list
        highscores << "This is a test";

        highscores.close();
    }
}

void CoreGame::GameController::gameOver()
{

    loopInvarient = false;
}

bool CoreGame::checkCollision(const sf::RectangleShape& a, const sf::RectangleShape& b)
{
    return a.getGlobalBounds().intersects( b.getGlobalBounds() );

}

sf::RectangleShape CoreGame::getRectangleAt(sf::Vector2f location, sf::Color color)
{
    sf::RectangleShape box;
    box.setSize(sf::Vector2f(BOX_SIZE,BOX_SIZE));
    box.setPosition(location);
    box.setFillColor(color);
    return box;

}

void CoreGame::GameController::loadResources()
{
    //TODO
}

__attribute__((unused)) sf::Font* CoreGame::GameController::getFont(Fonts font)
{
    return &fontList[font];
}
