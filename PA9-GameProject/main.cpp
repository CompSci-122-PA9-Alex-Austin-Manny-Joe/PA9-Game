/*********************************************************************************
* Team:	Manuel Berrueta, Joe Skranak, Alex Connor, Austin                        *
* SFML Setup: Manuel Berrueta                                                    *
* Class: CptS 122; Lab Section 6                                                 *
* Programming Assignment: PA9 - Game Project                                     *
* Date: 3/23/2018                                                                *
*                                                                                *
* Description: Team game project using a spaceship that moves up and down, &     *
*              shoots down targets                                               *
*                                                                                *
**********************************************************************************/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <random>
#include "Menu.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;


int main(void)
{
	//Makes Window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Da Dream Team Game");

	Menu myMenu(window.getSize().x, window.getSize().y);

	//Event object where events will be stored - An even is anything from moving a mouse, key, etc..
	sf::Event event;

	//screen view
	sf::View view(sf::FloatRect(0, 0, 300, 300));
	window.setView(view);
	//view.move(sf::Vector2f(50, 100));
	window.setView(view);
	//view.setCenter(sf::Vector2f(300, 300));

	//Color of screen
	sf::Color color(sf::Color::Magenta);

	//Clock to keep track of time in game
	sf::Clock clock;
	sf::Time time;

	//Random number generation C++, equivalent to srand(time(NULL)) in C
	std::random_device rnd;
	std::mt19937 randNum(rnd()); //Algorithm to create random numbers


	//Background image
	sf::Texture myBackground;

	//Loading background image and making sure it loaded properly
	if (!myBackground.loadFromFile("ByeWinMac.jpg"/*"tesla.jpg"*/))
	{
		cout << "Background image not found =<(" << endl;
	}

	//A sprite is any graphic with or without motion
	sf::Sprite menubackimg(myBackground);
	//Sets up the background so the whole thing can be seen in window
	menubackimg.setScale(0.25, 0.3f);//the scale depends on the size of the image
	
	//MovingBackground
	sf::Texture spaceImage;
	if (!spaceImage.loadFromFile("Galaxy-universe-space-starry_3840x1200.jpg"/*"tesla.jpg"*/))
	{
		cout << "Background image not found =<(" << endl;
	}

	//Animation of background
	sf::IntRect rectBG(0, 0, 1080, 700);
	sf::Sprite movingBackground(spaceImage/*, rectBG*/);
	movingBackground.setScale(.5f, .5f);
	int movingbgIndex = 0;
	sf::Time SlowDown = clock.getElapsedTime();
	int slowMovingSpeed = 0;

	


	//Test code of circle shape
	//sf::CircleShape circle_shape(225.f);
	//circle_shape.setFillColor(sf::Color::Red);
	
	
	//Game Loop
	while (window.isOpen())
	{
		//if(clock.getElapsedTime().asSeconds() % 10 == 0)
		myMenu.draw(window);


		slowMovingSpeed = SlowDown.asSeconds();
		if(slowMovingSpeed % 20 == 0)
		{
			view.move(sf::Vector2f(1, 0));
			window.setView(view);
			movingbgIndex++;
			if (movingbgIndex == 1080)
			{
				
				view.move(-1080, 0);
				window.setView(view);
				///window.setView(wew(0,0,100,100));
				movingbgIndex = 0;
			}
		}
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed)
			{
				window.close();
			}
			//Checking for an event
			if (window.waitEvent(event))
			{
				cout << "Test Event" << endl;
			}
		}

		//Elapsed time of game 
		cout << "Elapsed time: " << clock.getElapsedTime().asMicroseconds() << endl;
		clock.restart();

		//This updates the visual on our game window
		//Order is very important 1-window.clear,2-window.draw,3-window,display.
		window.clear(color); //Clears the frame from the last frame
		window.draw(menubackimg);
		window.draw(movingBackground);
		window.display(); //Shows changes from last frame
	}
	return 0;
}