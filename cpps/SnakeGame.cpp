#include "SnakeGame.h"

SnakeGame::SnakeGame(int diff) 
{
	name = "Snake Game";
	difficulty = diff;
    gameOver = false;
    score = 0;
	window.create(sf::VideoMode(grid.WIDTH * grid.CELL_SIZE, grid.HEIGHT * grid.CELL_SIZE), name);
	snakeTexture.loadFromFile("images/snake.png");
	foodTexture.loadFromFile("images/food.png");
	foodLenTexture.loadFromFile("images/foodLen.png");
	foodSpeedTexture.loadFromFile("images/foodSpeed.png");
	menuTexture.loadFromFile("images/snakegame.png");
	if (difficulty == 2)
	{
        horWall.loadFromFile("images/horizontalwall.png");
        verWall.loadFromFile("images/verticalwall.png");
    }
    if (difficulty==3)
    {
        horWall.loadFromFile("images/horizontalwall_hard.png");
        verWall.loadFromFile("images/verticalwall_hard.png");
    }
	
    //hardWall.loadFromFile("images/centerwall.png");

	horWallSprite[0].setTexture(horWall);
	horWallSprite[1].setTexture(horWall);
	verWallSprite[0].setTexture(verWall);
	verWallSprite[1].setTexture(verWall);
	//hardWallSprite.setTexture(hardWall);
    snakeSprite.setTexture(snakeTexture);
    foodSprite.setTexture(foodTexture);
	foodLenSprite.setTexture(foodLenTexture);
	foodSpeedSprite.setTexture(foodSpeedTexture);
    menuSprite.setTexture(menuTexture);
	font.loadFromFile("main_menu.ttf");

    

    

	foodEaten = 1;

    if (difficulty)
    {
        snake[0].x = 6;
		snake[0].y = 5;

        snake[1].x = 5;
		snake[1].y = 5;
		snake[2].x = 4;
		snake[2].y = 5;
	}
	
	for (int i = 3; i < 100; i++)
    {
        snake[i].x = -1;
		snake[i].y = -1;
	}

    spawnFood();

    srand(static_cast<unsigned>(time(nullptr)));
}

void SnakeGame::spawnFood() 
{
    if (foodEaten % 10 != 0)
    {
        if (difficulty == 1 || difficulty == 2)
        {
            do
            {
                food.x = rand() % grid.WIDTH;
                food.y = rand() % grid.HEIGHT;
            } while (food.x<2 || food.x>grid.WIDTH - 2 || food.y<2 || food.y > grid.HEIGHT - 2);
        }
        else
        {
            do
            {
                food.x = rand() % grid.WIDTH;
                food.y = rand() % grid.HEIGHT;
            } while (food.x<5 || food.x>grid.WIDTH - 5 || food.y<5 || food.y > grid.HEIGHT - 5);

        }
	}
	else
	{
        
		temp = rand() % 2;
        if (temp == 0)
        {
            if (difficulty == 1 || difficulty == 2)
            {
                do
                {
                    foodLen.x = rand() % grid.WIDTH;
                    foodLen.y = rand() % grid.HEIGHT;
                } while (foodLen.x<2 || foodLen.x>grid.WIDTH - 2 || foodLen.y<2 || foodLen.y > grid.HEIGHT - 2);
            }
            else
            {
                do
                {
                    foodLen.x = rand() % grid.WIDTH;
                    foodLen.y = rand() % grid.HEIGHT;
                } while (foodLen.x<5 || foodLen.x>grid.WIDTH - 5 || foodLen.y<5 || foodLen.y > grid.HEIGHT - 5);

            }
        }
        else
        {
            if (difficulty == 1 || difficulty == 2)
            {
                do
                {
                    foodSpeed.x = rand() % grid.WIDTH;
                    foodSpeed.y = rand() % grid.HEIGHT;
                } while (foodSpeed.x<2 || foodSpeed.x>grid.WIDTH - 2 || foodSpeed.y<2 || foodSpeed.y > grid.HEIGHT - 2);
            }
            else
            {
                do
                {
                    foodSpeed.x = rand() % grid.WIDTH;
                    foodSpeed.y = rand() % grid.HEIGHT;
                } while (foodSpeed.x<5 || foodSpeed.x>grid.WIDTH - 5 || foodSpeed.y<5 || foodSpeed.y > grid.HEIGHT - 5);

            }
        }
	}
}

void SnakeGame::handleInput() 
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !(direction.x == 0 && direction.y == 1)) 
    {
        direction.x = 0;
        direction.y = -1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !(direction.x == 0 && direction.y == -1)) 
    {
        direction.x = 0;
        direction.y = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !(direction.x == 1 && direction.y == 0)) 
    {
        direction.x = -1;
        direction.y = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !(direction.x == -1 && direction.y == 0)) 
    {
        direction.x = 1;
        direction.y = 0;
    }
}

void SnakeGame::update() 
{
    
    for (int i = snakeLength - 1; i > 0; i--) 
    {
        snake[i] = snake[i - 1];
    }

    snake[0].x += direction.x;
    snake[0].y += direction.y;

 
    if (difficulty == 1)
    {
        if (snake[0].x < 0)
        {
            snake[0].x = grid.WIDTH - 1;
        }
        else if (snake[0].x >= grid.WIDTH)
        {
            snake[0].x = 0;
        }

        if (snake[0].y < 0)
        {
            snake[0].y = grid.HEIGHT - 1;
        }
        else if (snake[0].y >= grid.HEIGHT)
        {
            snake[0].y = 0;
        }
    }

	if (difficulty == 2)
    {
        if (snake[0].x < 0 || snake[0].x >= grid.WIDTH || snake[0].y < 0 || snake[0].y >= grid.HEIGHT)
        {
            hitWall.openFromFile("death-snake.ogg");
            hitWall.setPosition(0, 0, 0);
            hitWall.setVolume(100);
            hitWall.setLoop(0);
			hitWall.play();
			endGame(2);
		}
	}

    if (difficulty == 3)
    {
		if (snake[0].x < 3 || snake[0].x >= grid.WIDTH-3 || snake[0].y < 3 || snake[0].y >= grid.HEIGHT-3)
		{
            hitWall.openFromFile("death-snake.ogg");
            hitWall.setPosition(0, 0, 0);
            hitWall.setVolume(100);
            hitWall.setLoop(0);
            hitWall.play();
			endGame(2);
		}
		
    }

    for (int i = 1; i < snakeLength; i++) 
    {
        if (snake[0] == snake[i]) 
        {
            hitWall.openFromFile("death-snake.ogg");
            hitWall.setPosition(0, 0, 0);
            hitWall.setVolume(100);
            hitWall.setLoop(0);
            hitWall.play();
            endGame(1);
        }
    }

    if (snake[0] == food) 
    {
        eatFood.openFromFile("eat-food.ogg");

        eatFood.setPosition(0, 0, 0);
        eatFood.setVolume(100);
        eatFood.setLoop(0);
        eatFood.play();
        if (snakeLength < 100) 
        {
            snakeLength++;
			foodEaten++;
            score++;
			if (difficulty == 1)
            {
				easySpeed -= 5;
			}
			if (difficulty == 2)
			{
				mediumSpeed -= 5;
			}
            if (difficulty == 3)
            {
				hardSpeed -= 5;
            }
        }
        spawnFood();
    }
	else if (snake[0] == foodLen)
    {
        if (snakeLength < 100)
        {
            snakeLength += 3;
            foodEaten++;
            score += 5;
            if (difficulty == 1)
            {
                easySpeed -= 5;
            }
            if (difficulty == 2)
            {
                mediumSpeed -= 5;
            }
            if (difficulty == 3)
            {
                hardSpeed -= 5;
            }
        }
		spawnFood();
    }
    else if (snake[0] == foodSpeed)
    {
        if (snakeLength < 100)
        {
            snakeLength++;
            foodEaten++;
            score += 5;
            if (difficulty == 1)
            {
                easySpeed += 15;
            }
            if (difficulty == 2)
            {
                mediumSpeed += 15;
            }
            if (difficulty == 3)
            {
                hardSpeed += 15;
            }
        }
		spawnFood();
    }
}


void SnakeGame::startGame()
{
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
            while (true)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) 
                {
                    break;
                }
            }
        }


        handleInput();
        if (difficulty == 1)
        {
            if (clock.getElapsedTime().asMilliseconds() > easySpeed)
            {
                update();
                clock.restart();
            }
        }
        if (difficulty == 2)
        {
            if (clock.getElapsedTime().asMilliseconds() > mediumSpeed)
            {
                update();
                clock.restart();
            }
        }
		if (difficulty == 3)
		{
			if (clock.getElapsedTime().asMilliseconds() > hardSpeed)
			{
				update();
				clock.restart();
			}
		}
        renderGame();
    }
    if (gameOver)
    {
        return;
    }
}

void SnakeGame::renderGame() 
{
    window.clear();

    window.draw(menuSprite);

	scoreText.setString("Score: " + to_string(score));
	scoreText.setCharacterSize(30);
	scoreText.setFont(font);
	scoreText.setFillColor(sf::Color::White);
	if (difficulty == 3)
	{ 
		scoreText.setPosition(98, 98);
    }
    else
    {
        scoreText.setPosition(12, 12);
    }

    if (difficulty == 2)
    {
		horWallSprite[0].setPosition(0, 0);
		horWallSprite[1].setPosition(0, 790);
		verWallSprite[0].setPosition(0, 0);
		verWallSprite[1].setPosition(790, 0);
    }

	if (difficulty == 3)
	{
		horWallSprite[0].setPosition(0, 0);
		horWallSprite[1].setPosition(0, 704);
		verWallSprite[0].setPosition(0, 0);
		verWallSprite[1].setPosition(704, 0);
		//hardWallSprite.setPosition(256, 480);
	}
	
    if (foodEaten % 10 != 0)
    {
        foodSprite.setPosition(food.x * 32, food.y * 32);
        window.draw(foodSprite);
    }
    else
    {
		if (temp == 0)
		{
			foodLenSprite.setPosition(foodLen.x * 32, foodLen.y * 32);
			window.draw(foodLenSprite);
		}
		else
		{
			foodSpeedSprite.setPosition(foodSpeed.x * 32, foodSpeed.y * 32);
			window.draw(foodSpeedSprite);
		}
    }

    for (int i = 0; i < snakeLength; i++)
    {
        snakeSprite.setPosition(snake[i].x * 32, snake[i].y * 32);
        window.draw(snakeSprite);
    }

	window.draw(scoreText);
    if (difficulty == 2)
    {
		window.draw(horWallSprite[0]);
		window.draw(horWallSprite[1]);
		window.draw(verWallSprite[0]);
		window.draw(verWallSprite[1]);

    }

    if (difficulty == 3)
    {
        window.draw(horWallSprite[0]);
        window.draw(horWallSprite[1]);
        window.draw(verWallSprite[0]);
        window.draw(verWallSprite[1]);
		//window.draw(hardWallSprite);
    }

    window.display();
}




void SnakeGame::endGame(int temp)
{
    gameOver = true;
	gameOverText.setString("Score: " + to_string(score));
	gameOverText.setCharacterSize(30);
	gameOverText.setFont(font);
	gameOverText.setFillColor(sf::Color::White);
	gameOverText.setPosition(250, 600);
    if (temp == 1)
    {
        menuTexture.loadFromFile("images/snake_bit.png");
        menuSprite.setTexture(menuTexture);
        window.clear();
        window.draw(menuSprite);
    }
	else if (temp == 2)
    {
		menuTexture.loadFromFile("images/snake_wall.png");
		menuSprite.setTexture(menuTexture);
		window.clear();
		window.draw(menuSprite);
	}
	window.draw(gameOverText);
	window.display();
	sf::sleep(sf::seconds(2));
	window.close();
}

int SnakeGame::getScore()
{
	return score;
}
