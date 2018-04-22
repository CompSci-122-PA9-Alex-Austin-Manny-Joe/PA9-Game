#pragma once
#include "laser.h"


class Spaceship : public sf::CircleShape//, public sf::Rect<Spaceship>
{
private:
	bool shootSound();
	sf::SoundBuffer laserBuffer;//Sounds can't ever go out of scope. Functions that declare sounds and go
	sf::Sound laser;               //out of scope do not work.
	//Laser *l[];
	sf::CircleShape circle; //Temporary "laser"
	int shipVelocity = 0;

public:
	Spaceship(const sf::Color &c,sf::Vector2f &pos, float r) : CircleShape(r, 3)
	{
		this->setFillColor(c);
		this->setPosition(pos);
		this->rotate(90);	
	}

	void moveSpaceship(sf::Event pressKey, sf::RenderWindow &window);

	void shootSpaceship(sf::Event pressKey);

	sf::CircleShape & getBullet();
};