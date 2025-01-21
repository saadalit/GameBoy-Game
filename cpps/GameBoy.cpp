#include "GameBoy.h"


void savePlayerName(const string& name)
{
    ofstream file("player_names.txt", ios::app);
    if (file.is_open()) {
        file << name << "\n";
        file.close();
    }
}

void GameBoy::enterPlayerName()
{
   
        font.loadFromFile("main_menu1.ttf");
        string playerName;
        Text namePrompt("Enter your name: ", font, 24);
        namePrompt.setPosition(50, 50);
        Text inputText("", font, 24);
        inputText.setPosition(50, 100);
        bool nameEntered = false;

        RenderWindow inputwindow(VideoMode(800, 800), "Input Window", Style::Close);


        while (inputwindow.isOpen()) {
            Event event;
            while (inputwindow.pollEvent(event)) {
                if (event.type == Event::Closed)
                    inputwindow.close();

                if (!nameEntered && event.type == Event::TextEntered)
                {
                    char entered = static_cast<char>(event.text.unicode);
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
                    {
                        savePlayerName(playerName);
                        nameEntered = true;
                    }

                    else if (entered == '\b' && !playerName.empty())
                    { // Backspace
                        playerName.pop_back();
                    }
                    else if (entered >= 32 && entered < 127) { // Valid ASCII
                        playerName += entered;
                    }
                    inputText.setString(playerName);
                    currPlayer.setName(playerName);

                }


            }
            inputwindow.clear();
            if (!nameEntered)
            {
                window.draw(namePrompt);
                window.draw(inputText);
            }
            else
            {
                return;
            }

            inputwindow.draw(namePrompt);
            inputwindow.draw(inputText);
            inputwindow.display();
        }
  

}

int GameBoy::setMenus()
{
    if (menu[0] != nullptr)
    {
		delete menu[0];
    }
    menu[0] = new MainMenu();
    menuCheck = menu[0]->display_menu(lead[0]);
    if (menuCheck == 1)
    {
        if (menu[1] != nullptr)
        {
            delete menu[1];
        }
        menu[1] = new SnakeGameMenu();
        snakeGameCheck = menu[1]->display_menu(lead[0]);
        wordleGameCheck = 1000;
        hangmanGameCheck = 1000;
        return 0;

        
    }
    else if (menuCheck == 2)
    {
        if (menu[2] != nullptr)
        {
            delete menu[2];
        }
        menu[2] = new WordleMenu();
        wordleGameCheck = menu[2]->display_menu(lead[1]);
        snakeGameCheck = 1000;
        hangmanGameCheck = 1000;
        return 0;

    }
    else if (menuCheck == 3)
    {
        if (menu[3] != nullptr)
        {
            delete menu[3];
        }
        menu[3] = new HangmanMenu();
        hangmanGameCheck = menu[3]->display_menu(lead[2]);
        snakeGameCheck = 1000;
        wordleGameCheck = 1000;
        return 0;
    }
	else if (menuCheck == 5)
	{
        showplayerInfo();
		return 0;
	}
    else
    {
        return 1;
    }
}

void GameBoy::resetState()
{
	menuCheck = 1000;
	snakeGameCheck = 1000;
	hangmanGameCheck = 1000;
	wordleGameCheck = 1000;

}

GameBoy::GameBoy()
{

    enterPlayerName();

    menuCheck = 1000;
	snakeGameCheck = 1000;
	hangmanGameCheck = 1000;
	wordleGameCheck = 1000;

    for (int i = 0; i < 3; i++)
    {
		if (lead[i] != nullptr)
			delete lead[i];
    }

    lead[0] = new Leaderboard1();
	lead[1] = new Leaderboard1();
	lead[2] = new Leaderboard1();

        //currentGame->setLeaderboard(lead);
        currentGame = nullptr;

}
GameBoy::~GameBoy()
{
   
}

void GameBoy::start()
{
    if ((menuCheck != 4 || snakeGameCheck != 0 && hangmanGameCheck != 0 || wordleGameCheck != 0))
    {

        if (menuCheck == 1)
        {
            


            if (snakeGameCheck == 1)
            {
                //easy version
                if (currentGame != nullptr)
                    delete currentGame;
                currentGame = new SnakeGame(1);
                currentGame->startGame();
                cout << "Test...." << endl;
                currPlayer.setHighScore(currentGame->getScore(), 0);
                lead[0]->loadLeaderboard(0);
                lead[0]->updateScore(&currPlayer, currPlayer.getHighScore(0), 0);
                lead[0]->saveLeaderboard(0);

            }
            else if (snakeGameCheck == 2)
            {
                //medium version
                if (currentGame != nullptr)
                    delete currentGame;
                currentGame = new SnakeGame(2);
                currentGame->startGame();
                currPlayer.setHighScore(currentGame->getScore(), 0);
                lead[0]->loadLeaderboard(0);
                lead[0]->updateScore(&currPlayer, currPlayer.getHighScore(0), 0);
                lead[0]->saveLeaderboard(0);

            }
            else if (snakeGameCheck == 3)
            {
                //hard version
                if (currentGame != nullptr)
                    delete currentGame;
                currentGame = new SnakeGame(3);
                currentGame->startGame();
                currPlayer.setHighScore(currentGame->getScore(), 0);
                lead[0]->loadLeaderboard(0);
                lead[0]->updateScore(&currPlayer, currPlayer.getHighScore(0), 0);
                lead[0]->saveLeaderboard(0);

            }

        }

        if (menuCheck == 2)
        {
            
            

            if (wordleGameCheck == 1)
            {
                //timed version
                if (currentGame != nullptr)
                    delete currentGame;
				currentGame = new WordleGame(1);
				currentGame->startGame();
                currPlayer.setHighScore(currentGame->getScore(), 1);
                lead[1]->loadLeaderboard(1);
                lead[1]->updateScore(&currPlayer, currPlayer.getHighScore(1), 1);
                lead[1]->saveLeaderboard(1);

            }
            else if (wordleGameCheck == 2)
            {
                //untimed version
                if (currentGame != nullptr)
                    delete currentGame;
				currentGame = new WordleGame(2);
				currentGame->startGame();
                currPlayer.setHighScore(currentGame->getScore(), 1);
                lead[1]->loadLeaderboard(1);
                lead[1]->updateScore(&currPlayer, currPlayer.getHighScore(1), 1);
                lead[1]->saveLeaderboard(1);

            }
            else if (wordleGameCheck == 3)
            {
                //category 1 version
                if (currentGame != nullptr)
                    delete currentGame;
				currentGame = new WordleGame(3);
				currentGame->startGame();
                currPlayer.setHighScore(currentGame->getScore(), 1);
                lead[1]->loadLeaderboard(1);
                lead[1]->updateScore(&currPlayer, currPlayer.getHighScore(1), 1);
                lead[1]->saveLeaderboard(1);

            }
            else if (wordleGameCheck == 4)
            {
                //category 2 version
                if (currentGame != nullptr)
                    delete currentGame;
				currentGame = new WordleGame(4);
				currentGame->startGame();
                currPlayer.setHighScore(currentGame->getScore(), 1);
                lead[1]->loadLeaderboard(1);
                lead[1]->updateScore(&currPlayer, currPlayer.getHighScore(1), 1);
                lead[1]->saveLeaderboard(1);

            }
            else if (wordleGameCheck == 5)
            {
                // category 3 version
                if (currentGame != nullptr)
                    delete currentGame;
				currentGame = new WordleGame(5);
				currentGame->startGame();
                currPlayer.setHighScore(currentGame->getScore(), 1);
                lead[1]->loadLeaderboard(1);
                lead[1]->updateScore(&currPlayer, currPlayer.getHighScore(1), 1);
                lead[1]->saveLeaderboard(1);

            }
        }

        if (menuCheck == 3)
        {
          
            lead[2]->loadLeaderboard(2);
            lead[2]->updateScore(&currPlayer, currPlayer.getHighScore(2), 2);
            lead[2]->saveLeaderboard(2);

            if (hangmanGameCheck == 1)
            {


                if (currentGame != nullptr)
                    delete currentGame;
                currentGame = new HangmanGame(1);
                currentGame->startGame();
                currPlayer.setHighScore(currentGame->getScore(), 2);
                lead[2]->loadLeaderboard(2);
                lead[2]->updateScore(&currPlayer, currPlayer.getHighScore(2), 2);
                lead[2]->saveLeaderboard(2);



            }
            else if (hangmanGameCheck == 2)
            {
                if (currentGame != nullptr)
                    delete currentGame;
                currentGame = new HangmanGame(2);
                currentGame->startGame();
                currPlayer.setHighScore(currentGame->getScore(), 2);
                lead[2]->loadLeaderboard(2);
                lead[2]->updateScore(&currPlayer, currPlayer.getHighScore(2), 2);
                lead[2]->saveLeaderboard(2);

            }
            else if (hangmanGameCheck == 3)
            {
                if (currentGame != nullptr)
                    delete currentGame;
                currentGame = new HangmanGame(3);
                currentGame->startGame();
                currPlayer.setHighScore(currentGame->getScore(), 2);
                lead[2]->loadLeaderboard(2);
                lead[2]->updateScore(&currPlayer, currPlayer.getHighScore(2), 2);
                lead[2]->saveLeaderboard(2);


            }
            else if (hangmanGameCheck == 4)
            {
                if (currentGame != nullptr)
                    delete currentGame;
                currentGame = new HangmanGame(4);
                currentGame->startGame();
                currPlayer.setHighScore(currentGame->getScore(), 2);
                lead[2]->loadLeaderboard(2);
                lead[2]->updateScore(&currPlayer, currPlayer.getHighScore(2), 2);
                lead[2]->saveLeaderboard(2);

            }
            else if (hangmanGameCheck == 5)
            {
                if (currentGame != nullptr)
                    delete currentGame;
                currentGame = new HangmanGame(5);
                currentGame->startGame();
                currPlayer.setHighScore(currentGame->getScore(), 2);
                lead[2]->loadLeaderboard(2);
                lead[2]->updateScore(&currPlayer, currPlayer.getHighScore(2), 2);
                lead[2]->saveLeaderboard(2);

            }
        }
    }
	else
	{
		shutDown();
	}
}

void GameBoy::shutDown()
{
	window.close();
	
}

void GameBoy::showplayerInfo()
{
    Text playerInfo;

    playerInfo.setFont(font);
    playerInfo.setCharacterSize(30);
    playerInfo.setFillColor(Color::White);
    playerInfo.setPosition(50, 50);
    playerInfo.setString("Player name:"+currPlayer.getName()+"\n\n\nSnake Game High Score:"+to_string(currPlayer.getHighScore(0))+"\n\n\nWordle High Score:"+to_string(currPlayer.getHighScore(1)) + "\n\n\nHangman High Score:" + to_string(currPlayer.getHighScore(2)));
    RenderWindow window(VideoMode(780, 780), "Player Info", Style::Close);
    while (window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
            {
                window.close();
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape) || Keyboard::isKeyPressed(Keyboard::Num4))
        {
            return;
        }

        window.clear();
        window.draw(playerInfo);
        window.display();
    }
}