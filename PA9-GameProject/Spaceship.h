#pragma once
#include "laser.h"


class Spaceship : public sf::CircleShape
{
private:
	bool shootSound();
	sf::SoundBuffer laserBuffer;//Sounds can't ever go out of scope. Functions that declare sounds and go
	sf::Sound laser;               //out of scope do not work.

public:
	Spaceship(const sf::Color &c,sf::Vector2f &pos, float r) : CircleShape(r, 3)
	{
		this->setFillColor(c);
		this->setPosition(pos);
		this->rotate(90);	
	}

	void moveSpaceship(sf::Event pressKey);

	void shootSpaceship(sf::Event pressKey);

};