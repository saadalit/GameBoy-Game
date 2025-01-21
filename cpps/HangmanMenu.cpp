#include"HangmanMenu.h"

HangmanMenu::HangmanMenu()
{
    cout << "Hangman Menu created..." << endl;
    men = 0;
    window.create(VideoMode(800, 800), "Hangman Menu");
    window.setFramerateLimit(60);

    font.loadFromFile("main_menu1.ttf");

    music.openFromFile("main_menu_music.ogg");
    music.setPosition(0, 1, 10);
    music.setVolume(30);
    music.play();

    icon1.loadFromFile("images/hangman_icon.png");

    menuback.loadFromFile("images/hangman_menu.png");
    menus.setTexture(menuback);
    menus.setScale(1, 1);

    menu.setFont(font);
    menu.setString("Hangman");
    menu.setCharacterSize(55);
    menu.setFillColor(Color::Black);
    menu.setPosition(325, 65);
    menu.setOutlineThickness(1);
    menu.setStyle(Text::Bold);

    Timed.setFont(font);
    Timed.setString("Timed Game");
    Timed.setCharacterSize(40);
    Timed.setFillColor(Color::Black);
    Timed.setPosition(325, 175);
    Timed.setCharacterSize(30);
    Timed.setOutlineThickness(1);

    Untimed.setFont(font);
    Untimed.setString("Untimed Game");
    Untimed.setCharacterSize(40);
    Untimed.setFillColor(Color::Black);
    Untimed.setPosition(325, 225);
    Untimed.setCharacterSize(30);
    Untimed.setOutlineThickness(1);

    Category.setFont(font);
    Category.setString("Categories");
    Category.setCharacterSize(40);
    Category.setFillColor(Color::Black);
    Category.setPosition(325, 275);
    Category.setCharacterSize(30);
    Category.setOutlineThickness(1);

    Category1.setFont(font);
    Category1.setString("Animals");
    Category1.setCharacterSize(40);
    Category1.setFillColor(Color::Black);
    Category1.setPosition(325, 200);
    Category1.setCharacterSize(40);
    Category1.setOutlineThickness(1);

    Category2.setFont(font);
    Category2.setString("Countries");
    Category2.setCharacterSize(40);
    Category2.setFillColor(Color::Black);
    Category2.setPosition(325, 300);
    Category2.setCharacterSize(40);
    Category2.setOutlineThickness(1);

    Category3.setFont(font);
    Category3.setString("Brands");
    Category3.setCharacterSize(40);
    Category3.setFillColor(Color::Black);
    Category3.setPosition(325, 400);
    Category3.setCharacterSize(40);
    Category3.setOutlineThickness(1);

	Leaderboard.setFont(font);
	Leaderboard.setString("Leaderboard");
	Leaderboard.setCharacterSize(40);
	Leaderboard.setFillColor(Color::Black);
	Leaderboard.setPosition(325, 325);
	Leaderboard.setCharacterSize(30);
	Leaderboard.setOutlineThickness(1);

    instructions.setFont(font);
    instructions.setString("Rules");
    instructions.setCharacterSize(40);
    instructions.setFillColor(Color::Black);
    instructions.setPosition(325, 375);
    instructions.setCharacterSize(30);
    instructions.setOutlineThickness(1);


    exit.setFont(font);
    exit.setString("Exit");
    exit.setCharacterSize(40);
    exit.setFillColor(Color::Black);
    exit.setPosition(325, 425);
    exit.setCharacterSize(30);
    exit.setOutlineThickness(1);

}

void HangmanMenu::display_instructions()
{
    Text instructions;

    instructions.setFont(font);
    instructions.setCharacterSize(20);
    instructions.setFillColor(Color::Black);
    instructions.setPosition(300, 50);
    instructions.setString("\t\t\t\t\tRules\n\n"
        "1.Guess the word.\n\n\n"
        "2.Do not let the man hang.\n\n\n"
        "3.Press 'P' to pause\n\n\n"
        "4.Score as high as possible.\n\n\n"
        "5.Press 'Esc' to return.");
    RenderWindow window(VideoMode(800, 800), "How to operate?", Style::Close);
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

int HangmanMenu::display_menu(Leaderboard1* lead)
{
    window.create(VideoMode(800, 800), "Hangman Menu");
    window.setFramerateLimit(60);
    men = 1;
    int check = 0;
    while (window.isOpen()) 
    {
        Event e;

        while (window.pollEvent(e)) 
        {

            if (e.type == Event::Closed)
                window.close();

            if (check == 0)
            {
                Timed.setFillColor(sf::Color::White);
                check++;
            }
            if (e.type == sf::Event::KeyPressed)
            {
                if (e.key.code == (Keyboard::Down))
                {
                    men++;
                    if (men == 1)
                    {
                        Timed.setFillColor(sf::Color::White);
                        Untimed.setFillColor(sf::Color::Black);
                        Category.setFillColor(sf::Color::Black);
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
                        Timed.setFillColor(sf::Color::Black);
                        Untimed.setFillColor(sf::Color::White);
                        Category.setFillColor(sf::Color::Black);
						Leaderboard.setFillColor(sf::Color::Black);
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
                        Timed.setFillColor(sf::Color::Black);
                        Untimed.setFillColor(sf::Color::Black);
                        Category.setFillColor(sf::Color::White);
						Leaderboard.setFillColor(sf::Color::Black);
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
                        Timed.setFillColor(sf::Color::Black);
                        Untimed.setFillColor(sf::Color::Black);
                        Category.setFillColor(sf::Color::Black);
						Leaderboard.setFillColor(sf::Color::White);
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
                        Timed.setFillColor(sf::Color::Black);
                        Untimed.setFillColor(sf::Color::Black);
                        Category.setFillColor(sf::Color::Black);
						Leaderboard.setFillColor(sf::Color::Black);
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
                        Timed.setFillColor(sf::Color::Black);
                        Untimed.setFillColor(sf::Color::Black);
                        Category.setFillColor(sf::Color::Black);
                        Leaderboard.setFillColor(sf::Color::Black);
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
                        men = 1;
                        Timed.setFillColor(sf::Color::White);
                        Untimed.setFillColor(sf::Color::Black);
                        Category.setFillColor(sf::Color::Black);
                        instructions.setFillColor(sf::Color::Black);
                        exit.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                    }


                }
                else if (e.key.code == (Keyboard::Up))
                {


                    men--;
                    if (men == 1)
                    {
                        Timed.setFillColor(sf::Color::White);
                        Untimed.setFillColor(sf::Color::Black);
                        Category.setFillColor(sf::Color::Black);
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
                        Timed.setFillColor(sf::Color::Black);
                        Untimed.setFillColor(sf::Color::White);
                        Category.setFillColor(sf::Color::Black);
						Leaderboard.setFillColor(sf::Color::Black);
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
                        Timed.setFillColor(sf::Color::Black);
                        Untimed.setFillColor(sf::Color::Black);
                        Category.setFillColor(sf::Color::White);
						Leaderboard.setFillColor(sf::Color::Black);
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
                        Timed.setFillColor(sf::Color::Black);
                        Untimed.setFillColor(sf::Color::Black);
                        Category.setFillColor(sf::Color::Black);
						Leaderboard.setFillColor(sf::Color::White);
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
                        Timed.setFillColor(sf::Color::Black);
                        Untimed.setFillColor(sf::Color::Black);
                        Category.setFillColor(sf::Color::Black);
						Leaderboard.setFillColor(sf::Color::Black);
                        instructions.setFillColor(sf::Color::White);
                        exit.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                    }

                    else if (men == 5)
                    {
                        Timed.setFillColor(sf::Color::Black);
                        Untimed.setFillColor(sf::Color::Black);
                        Category.setFillColor(sf::Color::Black);
                        Leaderboard.setFillColor(sf::Color::Black);
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
                        men = 5;
                        Timed.setFillColor(sf::Color::Black);
                        Untimed.setFillColor(sf::Color::Black);
                        Category.setFillColor(sf::Color::Black);
						Leaderboard.setFillColor(sf::Color::Black);
                        instructions.setFillColor(sf::Color::Black);
                        exit.setFillColor(sf::Color::White);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                    }
                }

                if (e.key.code == (Keyboard::Enter))
                {



                    Color a, b, c, d, e, f;
                    a = Timed.getFillColor();
                    b = Untimed.getFillColor();
                    c = Category.getFillColor();
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
                        return display_categories();

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
                        lead->loadLeaderboard(2);
						lead->displayTopScores();
					}
                }
            }

        }
        window.clear(Color::Green);
        window.draw(menus);
        window.draw(menu);
        window.draw(Timed);
        window.draw(Untimed);
        window.draw(Category);
		window.draw(Leaderboard);
        window.draw(instructions);
        window.draw(exit);
        window.setIcon(32, 32, icon1.getPixelsPtr());


        window.display();
    }


}

int HangmanMenu::display_categories()
{
    menu.setString("Category");
    window.create(VideoMode(800, 800), "Categories");
    window.setFramerateLimit(60);
    men = 1;
    int check = 0;
    while (window.isOpen()) {
        Event e;

        while (window.pollEvent(e)) {

            if (e.type == Event::Closed)
                window.close();

            if (check == 0)
            {
                Category1.setFillColor(sf::Color::White);
                check++;
            }
            if (e.type == sf::Event::KeyPressed)
            {
                if (e.key.code == (Keyboard::Down))
                {
                    men++;
                    if (men == 1)
                    {
                        Category1.setFillColor(sf::Color::White);
                        Category2.setFillColor(sf::Color::Black);
                        Category3.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                    }
                    else if (men == 2)
                    {
                        Category1.setFillColor(sf::Color::Black);
                        Category2.setFillColor(sf::Color::White);
                        Category3.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();

                    }
                    else if (men == 3)
                    {
                        Category1.setFillColor(sf::Color::Black);
                        Category2.setFillColor(sf::Color::Black);
                        Category3.setFillColor(sf::Color::White);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                    }
                    else if (men > 3)
                    {
                        men = 1;
                        Category1.setFillColor(sf::Color::White);
                        Category2.setFillColor(sf::Color::Black);
                        Category3.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                    }


                }
                else if (e.key.code == (Keyboard::Up))
                {

                    men--;
                    if (men == 1)
                    {
                        Category1.setFillColor(sf::Color::White);
                        Category2.setFillColor(sf::Color::Black);
                        Category3.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                    }
                    else if (men == 2)
                    {
                        Category1.setFillColor(sf::Color::Black);
                        Category2.setFillColor(sf::Color::White);
                        Category3.setFillColor(sf::Color::Black);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();

                    }
                    else if (men == 3)
                    {
                        Category1.setFillColor(sf::Color::Black);
                        Category2.setFillColor(sf::Color::Black);
                        Category3.setFillColor(sf::Color::White);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                    }
                    else if (men < 1)
                    {
                        men = 1;
                        Category1.setFillColor(sf::Color::Black);
                        Category2.setFillColor(sf::Color::Black);
                        Category3.setFillColor(sf::Color::White);
                        click.openFromFile("click.ogg");
                        click.setPosition(0, 0, 0);
                        click.setVolume(100);
                        click.setLoop(0);
                        click.play();
                    }

                }
                if (e.key.code == (Keyboard::Enter))
                {



                    Color a, b, c;
                    a = Category1.getFillColor();
                    b = Category2.getFillColor();
                    c = Category3.getFillColor();
                    
                    if (a == Color::White)
                    {
                        window.close();
                        music.stop();
                        return 3;

                    }
                    else if (b == Color::White)
                    {
                        window.close();
                        music.stop();
                        return 4;
                    }
                    else if (c == Color::White)
                    {
                        window.close();
                        music.stop();
                        return 5;
                    }
                   
                }
            }

        }
        window.clear(Color::Green);
        window.draw(menus);
        window.draw(menu);
        window.draw(Category1);
        window.draw(Category2);
        window.draw(Category3);
        window.setIcon(32, 32, icon1.getPixelsPtr());


        window.display();
    }


}
