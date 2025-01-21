#include"SnakeGameMenu.h"

SnakeGameMenu::SnakeGameMenu()
{
    cout << "Snake Menu Made..." << endl;
    men = 0;
    menHor=3;
    

    font.loadFromFile("SnakeGameMenu.ttf");

    music.openFromFile("snakemenu_music.ogg");
    music.setPosition(0, 1, 10);
    music.setVolume(30);
    music.setLoop(true);
    music.play();

    icon1.loadFromFile("images/snake_icon.png");

    menuback.loadFromFile("images/SnakeMenu_Bg.png");
    menus.setTexture(menuback);
    menus.setScale(1, 1);

    menu.setFont(font);
    menu.setString("Snake Game");
    menu.setCharacterSize(60);
    menu.setFillColor(Color::Black);
    menu.setPosition(275, 65);
    menu.setOutlineThickness(2);
    menu.setStyle(Text::Bold);

    Easy.setFont(font);
    Easy.setString("Easy");
    Easy.setCharacterSize(30);
    Easy.setFillColor(Color::Black);
    Easy.setPosition(125, 175);
    Easy.setOutlineThickness(2);

    Medium.setFont(font);
    Medium.setString("Medium");
    Medium.setCharacterSize(30);
    Medium.setFillColor(Color::Black);
    Medium.setPosition(275, 175);
    Medium.setOutlineThickness(2);

    Hard.setFont(font);
    Hard.setString("Hard");
    Hard.setCharacterSize(30);
    Hard.setFillColor(Color::Black);
    Hard.setPosition(425, 175);
    Hard.setOutlineThickness(2);

	Leaderboard.setFont(font);
	Leaderboard.setString("Leaderboard");
	Leaderboard.setCharacterSize(30);
	Leaderboard.setFillColor(Color::Black);
	Leaderboard.setPosition(275, 240);
	Leaderboard.setOutlineThickness(2);

    instructions.setFont(font);
    instructions.setString("Rules");
    instructions.setCharacterSize(30);
    instructions.setFillColor(Color::Black);
    instructions.setPosition(275, 340);
    instructions.setOutlineThickness(2);


    exit.setFont(font);
    exit.setString("Exit");
    exit.setCharacterSize(30);
    exit.setFillColor(Color::Black);
    exit.setPosition(275, 440);
    exit.setOutlineThickness(2);

}

void SnakeGameMenu::display_instructions()
{
    Text instructions;

    instructions.setFont(font);
    instructions.setCharacterSize(24);
    instructions.setFillColor(Color::White);
    instructions.setPosition(50, 50);
    instructions.setString("\t\t\t\t\tRules\n\n"
        "1. Use arrow keys to navigate the snake.\n\n\n"
        "2. Eat the food for growth of snake.\n\n\n"
        "3.Press 'P' to pause the game at any time.\n\n\n"
        "4. Score as high as possible.\n\n\n"
        "5.Press 'Esc' to return to the main menu.");
    RenderWindow window(VideoMode(780, 780), "How to operate?", Style::Close);
    while (window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
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

int SnakeGameMenu::display_menu(Leaderboard1* lead)
{
    window.create(VideoMode(800, 500), "Snake Game Menu");
    window.setFramerateLimit(60);
    men = 1;
    menHor = 3;
    int check = 0;
    while (window.isOpen()) {
        Event e;

        while (window.pollEvent(e)) {

            if (e.type == Event::Closed)
                window.close();

            if (check == 0)
            {
                Easy.setFillColor(sf::Color::White);
                check++;
            }
            if (e.type == sf::Event::KeyPressed)
            {
                if (e.key.code == (Keyboard::Down))
                {
                    menHor++;
                    if (menHor == 4)
                    {
                        Easy.setFillColor(sf::Color::Black);
                        Medium.setFillColor(sf::Color::Black);
                        Hard.setFillColor(sf::Color::Black);
						Leaderboard.setFillColor(sf::Color::White);
                        instructions.setFillColor(sf::Color::Black);
                        exit.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                    }
                    else if (menHor == 5)
                    {
                        Easy.setFillColor(sf::Color::Black);
                        Medium.setFillColor(sf::Color::Black);
                        Hard.setFillColor(sf::Color::Black);
                        Leaderboard.setFillColor(sf::Color::Black);
                        instructions.setFillColor(sf::Color::White);
                        exit.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();

                    }
                    else if (menHor == 6)
                    {
                        Easy.setFillColor(sf::Color::Black);
                        Medium.setFillColor(sf::Color::Black);
                        Hard.setFillColor(sf::Color::Black);
                        Leaderboard.setFillColor(sf::Color::Black);
                        instructions.setFillColor(sf::Color::Black);
                        exit.setFillColor(sf::Color::White);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                       
                    }
                    else if (menHor > 6)
                    {
                        Easy.setFillColor(sf::Color::White);
                        Medium.setFillColor(sf::Color::Black);
                        Hard.setFillColor(sf::Color::Black);
                        Leaderboard.setFillColor(sf::Color::Black);
                        instructions.setFillColor(sf::Color::Black);
                        exit.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                        men = 1;
                        menHor = 3;
                    }

                }
                else if (e.key.code == (Keyboard::Up))
                {


                    menHor--;
                    if (menHor == 4)
                    {
                        Easy.setFillColor(sf::Color::Black);
                        Medium.setFillColor(sf::Color::Black);
                        Hard.setFillColor(sf::Color::Black);
                        Leaderboard.setFillColor(sf::Color::White);
                        instructions.setFillColor(sf::Color::Black);
                        exit.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                    }
                    else if (menHor == 5)
                    {
                        Easy.setFillColor(sf::Color::Black);
                        Medium.setFillColor(sf::Color::Black);
                        Hard.setFillColor(sf::Color::Black);
                        Leaderboard.setFillColor(sf::Color::Black);
                        instructions.setFillColor(sf::Color::White);
                        exit.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                    }
                    else if (menHor == 6)
                    {
                        Easy.setFillColor(sf::Color::Black);
                        Medium.setFillColor(sf::Color::Black);
                        Hard.setFillColor(sf::Color::Black);
                        Leaderboard.setFillColor(sf::Color::Black);
                        instructions.setFillColor(sf::Color::Black);
                        exit.setFillColor(sf::Color::White);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();

                    }
                    else if (menHor <= 3)
                    {
                        Easy.setFillColor(sf::Color::White);
                        Medium.setFillColor(sf::Color::Black);
                        Hard.setFillColor(sf::Color::Black);
                        Leaderboard.setFillColor(sf::Color::Black);
                        instructions.setFillColor(sf::Color::Black);
                        exit.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                        menHor = 5;
                    }

                }
                if (e.key.code == (Keyboard::Right))
                {
                    men++;
                    if (men == 3)
                    {
                        Easy.setFillColor(sf::Color::Black);
                        Medium.setFillColor(sf::Color::Black);
                        Hard.setFillColor(sf::Color::White);
						Leaderboard.setFillColor(sf::Color::Black);
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
                        Easy.setFillColor(sf::Color::Black);
                        Medium.setFillColor(sf::Color::White);
                        Hard.setFillColor(sf::Color::Black);
						Leaderboard.setFillColor(sf::Color::Black);
                        instructions.setFillColor(sf::Color::Black);
                        exit.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();

                    }
                    else if (men == 1)
                    {
                        Easy.setFillColor(sf::Color::White);
                        Medium.setFillColor(sf::Color::Black);
                        Hard.setFillColor(sf::Color::Black);
						Leaderboard.setFillColor(sf::Color::Black);
                        instructions.setFillColor(sf::Color::Black);
                        exit.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                        men = 1;
                        menHor = 3;
                    }
                    else if (men > 3)
                    {
                        Easy.setFillColor(sf::Color::White);
                        Medium.setFillColor(sf::Color::Black);
                        Hard.setFillColor(sf::Color::Black);
						Leaderboard.setFillColor(sf::Color::Black);
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
                else if (e.key.code == (Keyboard::Left))
                {
                    men--;
                    if (men == 3)
                    {
                        Easy.setFillColor(sf::Color::Black);
                        Medium.setFillColor(sf::Color::Black);
                        Hard.setFillColor(sf::Color::White);
						Leaderboard.setFillColor(sf::Color::Black);
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
                        Easy.setFillColor(sf::Color::Black);
                        Medium.setFillColor(sf::Color::White);
                        Hard.setFillColor(sf::Color::Black);
						Leaderboard.setFillColor(sf::Color::Black);
                        instructions.setFillColor(sf::Color::Black);
                        exit.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();

                    }
                    else if (men == 1)
                    {
                        Easy.setFillColor(sf::Color::White);
                        Medium.setFillColor(sf::Color::Black);
                        Hard.setFillColor(sf::Color::Black);
						Leaderboard.setFillColor(sf::Color::Black);
                        instructions.setFillColor(sf::Color::Black);
                        exit.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                        men = 1;
                        menHor = 3;
                    }
                    else if (men < 1)
                    {
                        Easy.setFillColor(sf::Color::Black);
                        Medium.setFillColor(sf::Color::Black);
                        Hard.setFillColor(sf::Color::White);
						Leaderboard.setFillColor(sf::Color::Black);
                        instructions.setFillColor(sf::Color::Black);
                        exit.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                        men = 3;
                    }

                }

                if (e.key.code == (Keyboard::Enter))
                {



                    Color a, b, c, d, e, f;
                    a = Easy.getFillColor();
                    b = Medium.getFillColor();
                    c = Hard.getFillColor();
                    d = instructions.getFillColor();
                    e = exit.getFillColor();
					f = Leaderboard.getFillColor();
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
						sf::sleep(sf::seconds(0.5));
						return 0;
                    }
                    else if (f == Color::White)
                    {
                        lead->loadLeaderboard(0);
                        lead->displayTopScores();
                    }
                }
            }
            
        }
        window.clear(Color::Green);
        window.draw(menus);
        window.draw(menu);
        window.draw(Easy);
		window.draw(Medium);
		window.draw(Hard);
		window.draw(Leaderboard);
        window.draw(instructions);
        window.draw(exit);
        window.setIcon(32, 32, icon1.getPixelsPtr());


        window.display();
    }


}