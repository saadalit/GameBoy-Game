#include"MainMenu.h"




MainMenu::MainMenu()
{
    cout << "Main Menu created..." << endl;
	font.loadFromFile("main_menu1.ttf");
    men = 0;
    window.create(VideoMode(800, 800), "GameBoy Menu");
    window.setFramerateLimit(60);

    

    music.openFromFile("main_menu_music.ogg");
    music.setPosition(0, 1, 10);
    music.setVolume(30);
    music.play();

    icon1.loadFromFile("images/icon.png");

    menuback.loadFromFile("images/menu_background.png");
    menus.setTexture(menuback);
    menus.setScale(1, 1);

    menu.setFont(font);
    menu.setString("GameBoy");
    menu.setCharacterSize(60);
    menu.setFillColor(Color::Black);
    menu.setPosition(200, 65);
    menu.setOutlineThickness(1);
    menu.setStyle(Text::Bold);

    Snake.setFont(font);
    Snake.setString("Snake Game");
    Snake.setCharacterSize(24);
    Snake.setFillColor(Color::Black);
    Snake.setPosition(200, 150);
    Snake.setCharacterSize(40);
    Snake.setOutlineThickness(1);

    Wordle.setFont(font);
    Wordle.setString("Wordle Game");
    Wordle.setCharacterSize(24);
    Wordle.setFillColor(Color::Black);
    Wordle.setPosition(200, 210);
    Wordle.setCharacterSize(40);
    Wordle.setOutlineThickness(1);

    Hangman.setFont(font);
    Hangman.setString("Hangman Game");
    Hangman.setCharacterSize(24);
    Hangman.setFillColor(Color::Black);
    Hangman.setPosition(200, 270);
    Hangman.setCharacterSize(40);
    Hangman.setOutlineThickness(1);

    playerInfo.setFont(font);
    playerInfo.setString("Player Info");
    playerInfo.setCharacterSize(24);
    playerInfo.setFillColor(Color::Black);
    playerInfo.setPosition(200, 330);
    playerInfo.setCharacterSize(40);
    playerInfo.setOutlineThickness(1);


    instructions.setFont(font);
    instructions.setString("Rules");
    instructions.setCharacterSize(24);
    instructions.setFillColor(Color::Black);
    instructions.setPosition(200, 390);
    instructions.setCharacterSize(40);
    instructions.setOutlineThickness(1);


    exit.setFont(font);
    exit.setString("Exit");
    exit.setCharacterSize(24);
    exit.setFillColor(Color::Black);
    exit.setPosition(200, 450);
    exit.setCharacterSize(40);
    exit.setOutlineThickness(1);



    note.setFont(font);
    note.setString("            Enjoy the game :)\n            Saad Shahid       23I-0630\n            Umer Naseer       23I-0663\n");
    note.setCharacterSize(20);
    note.setFillColor(Color::Black);
    note.setPosition(100, 700);
    note.setOutlineThickness(0.5);
}

void MainMenu::display_instructions()
{
    Text instructions;

    instructions.setFont(font);
    instructions.setCharacterSize(18);
    instructions.setFillColor(Color::White);
    instructions.setPosition(50, 50);
    instructions.setString("\t\t\t\t\t\t\tRules\n\n"
        "1. You can play any of the following three \n\tgames: Wordle, Hangman or SnakeGame.\n\n\n"
        "2. Try to score as high as possible.\n\n\n"
        "3.Press 'P' to pause the game at any time.\n\n\n"
        "4. Don't forget to have fun.\n\n\n"
        "5.Press 'Esc' to return to the main menu.");
    RenderWindow window(VideoMode(780, 780), "How to operate?", Style::Close);
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
        window.draw(menus);
        window.draw(instructions);
        window.display();
    }
}

int MainMenu::display_menu(Leaderboard1* lead)
{
    men = 1;
    int check = 0;
    while (window.isOpen()) 
    {
        Event e;

        while (window.pollEvent(e)) 
        {

            if (e.type == Event::Closed)
            {
                window.close();
            }

            if (check == 0)
            {
                Snake.setFillColor(sf::Color::White);
                check++;
            }
            if (e.type == sf::Event::KeyPressed)
            {
                if (e.key.code == (Keyboard::Down))
                {
                    men++;
                    if (men == 1)
                    {
                        Snake.setFillColor(sf::Color::White);
                        Wordle.setFillColor(sf::Color::Black);
                        Hangman.setFillColor(sf::Color::Black);
						playerInfo.setFillColor(sf::Color::Black);
                        instructions.setFillColor(sf::Color::Black);
                        exit.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                    }
                    else if (men == 2)
                    {
                        Snake.setFillColor(sf::Color::Black);
                        Wordle.setFillColor(sf::Color::White);
                        Hangman.setFillColor(sf::Color::Black);
						playerInfo.setFillColor(sf::Color::Black);
                        instructions.setFillColor(sf::Color::Black);
                        exit.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();

                    }
                    else if (men == 3)
                    {
                        Snake.setFillColor(sf::Color::Black);
                        Wordle.setFillColor(sf::Color::Black);
                        Hangman.setFillColor(sf::Color::White);
						playerInfo.setFillColor(sf::Color::Black);
                        instructions.setFillColor(sf::Color::Black);
                        exit.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                    }
                    else if (men == 4)
                    {
                        Snake.setFillColor(sf::Color::Black);
                        Wordle.setFillColor(sf::Color::Black);
                        Hangman.setFillColor(sf::Color::Black);
						playerInfo.setFillColor(sf::Color::White);
                        instructions.setFillColor(sf::Color::Black);
                        exit.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();

                    }
                    else if (men == 5)
                    {
                        Snake.setFillColor(sf::Color::Black);
                        Wordle.setFillColor(sf::Color::Black);
                        Hangman.setFillColor(sf::Color::Black);
						playerInfo.setFillColor(sf::Color::Black);
                        instructions.setFillColor(sf::Color::White);
                        exit.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                    }
                    else if (men == 6)
                    {
                        Snake.setFillColor(sf::Color::Black);
                        Wordle.setFillColor(sf::Color::Black);
                        Hangman.setFillColor(sf::Color::Black);
                        playerInfo.setFillColor(sf::Color::Black);
                        instructions.setFillColor(sf::Color::Black);
                        exit.setFillColor(sf::Color::White);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                    }
                    else if (men > 6)
                    {
                        Snake.setFillColor(sf::Color::White);
                        Wordle.setFillColor(sf::Color::Black);
                        Hangman.setFillColor(sf::Color::Black);
                        instructions.setFillColor(sf::Color::Black);
                        exit.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                        men = 1;
                    }


                }
                else if (e.key.code == (Keyboard::Up))
                {


                    men--;
                    if (men == 1)
                    {
                        Snake.setFillColor(sf::Color::White);
                        Wordle.setFillColor(sf::Color::Black);
                        Hangman.setFillColor(sf::Color::Black);
						playerInfo.setFillColor(sf::Color::Black);
                        instructions.setFillColor(sf::Color::Black);
                        exit.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                    }
                    else if (men == 2)
                    {
                        Snake.setFillColor(sf::Color::Black);
                        Wordle.setFillColor(sf::Color::White);
                        Hangman.setFillColor(sf::Color::Black);
						playerInfo.setFillColor(sf::Color::Black);
                        instructions.setFillColor(sf::Color::Black);
                        exit.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();

                    }
                    else if (men == 3)
                    {
                        Snake.setFillColor(sf::Color::Black);
                        Wordle.setFillColor(sf::Color::Black);
                        Hangman.setFillColor(sf::Color::White);
						playerInfo.setFillColor(sf::Color::Black);
                        instructions.setFillColor(sf::Color::Black);
                        exit.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                    }
                    else if (men == 4)
                    {
                        Snake.setFillColor(sf::Color::Black);
                        Wordle.setFillColor(sf::Color::Black);
                        Hangman.setFillColor(sf::Color::Black);
						playerInfo.setFillColor(sf::Color::White);
                        instructions.setFillColor(sf::Color::Black);
                        exit.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();

                    }
                    else if (men == 5)
                    {
                        Snake.setFillColor(sf::Color::Black);
                        Wordle.setFillColor(sf::Color::Black);
                        Hangman.setFillColor(sf::Color::Black);
						playerInfo.setFillColor(sf::Color::Black);
                        instructions.setFillColor(sf::Color::White);
                        exit.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                    }
					else if (men == 6)
					{
						Snake.setFillColor(sf::Color::Black);
						Wordle.setFillColor(sf::Color::Black);
						Hangman.setFillColor(sf::Color::Black);
						playerInfo.setFillColor(sf::Color::Black);
						instructions.setFillColor(sf::Color::Black);
						exit.setFillColor(sf::Color::White);
						click.openFromFile("click.ogg");
						click.setPosition(0, 0, 0);
						click.setVolume(100);
						click.setLoop(0);
						click.play();
					}
                    else if (men < 1)
                    {
                        Snake.setFillColor(sf::Color::Black);
                        Wordle.setFillColor(sf::Color::Black);
                        Hangman.setFillColor(sf::Color::Black);
                        instructions.setFillColor(sf::Color::Black);
                        exit.setFillColor(sf::Color::White);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                        men = 5;
                    }

                }
            }
            if (e.key.code == (Keyboard::Enter))
            {



                Color a, b, c, d, e,f;
                a = Snake.getFillColor();
                b = Wordle.getFillColor();
                c = Hangman.getFillColor();
                d = instructions.getFillColor();
                e = exit.getFillColor();
				f = playerInfo.getFillColor();
                if (a == Color::White)
                {
                    window.close();
                    music.stop();
                    return 1;

                }
                else if (b == Color::White)
                {
                    window.close();
                    music.stop();
                    return 2;
                }
                else if (c == Color::White)
                {
                    window.close();
                    music.stop();
                    return 3;

                }
                else if (d == Color::White)
                {
                    display_instructions();
                }
                else if (e == Color::White)
                {
                    window.close();
                    music.stop();
					return 4;
                }
                else if (f == Color::White)
                {
                    music.stop();
                    return 5;
                }
            }
        }
        window.clear(Color::Green);
        window.draw(menus);
        window.draw(menu);
        window.draw(Snake);
		window.draw(Wordle);
		window.draw(Hangman);
		window.draw(playerInfo);
        window.draw(instructions);
        window.draw(exit);
        window.draw(note);
        window.setIcon(32, 32, icon1.getPixelsPtr());


        window.display();
    }

 
}

