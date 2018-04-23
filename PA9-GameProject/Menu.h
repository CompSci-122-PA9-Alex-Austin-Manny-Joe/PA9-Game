#pragma once

#include "SFML/Graphics.hpp"

class Menu
{
public:
	Menu(float width, float height);
	~Menu();
	
	void draw(sf::RenderWindow &window);
	void moveUp();
	void moveDown();

private:
	int selection;
	sf::Font font;
	sf::Text menuText[3];


};
