#include "Menu.h"

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("consola.ttf"))
	{

	}
	menuText[0].setFont(font);
	//menuText[0].setColor(sf::Color::Blue);
	menuText[0].setString("Play Game");
	menuText[0].setPosition(sf::Vector2f(width / 2, height / 4));


}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(menuText[i]);
	}
}

void Menu::moveUp()
{
}

void Menu::moveDown()
{
}
