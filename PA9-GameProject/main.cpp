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
using std::cout;
using std::endl;
using std::cin;

int main()
{
	sf::RenderWindow window(sf::VideoMode(450, 450), "SFML works!!!!");
	sf::CircleShape shape(225.f);
	shape.setFillColor(sf::Color::Red);
	sf::Clock tickTock;
	sf::Time time;

	//Game Loop
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



		//Checking for an event
		if (window.waitEvent(event))
		{
			cout << "Test Event" << endl;
		}
		window.clear();
		window.draw(shape);

		time - tickTock.restart();
		cout << time.asSeconds() << endl;

		window.display();

		//time = tickTock.getElapsedTime();

		
	}

	return 0;
}