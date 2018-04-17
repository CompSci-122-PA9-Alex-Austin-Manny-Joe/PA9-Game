#include "Spaceship.h"


void Spaceship::moveSpaceship(sf::Event pressKey)
{
	
	if (pressKey.type == sf::Event::KeyPressed)
	{
		if (pressKey.key.code == sf::Keyboard::W)
		{
			this->move(0, -10);
		}
		else if (pressKey.key.code == sf::Keyboard::S)
		{
			this->move(0, 10);
		}
	}
}


void Spaceship::shootSpaceship(sf::Event pressKey)
{
	if (pressKey.type == sf::Event::KeyPressed)
	{
		if (pressKey.key.code == sf::Keyboard::Space)
		{
			this->rotate(10);
			shootSound();
			
			
		}
	}
}

bool Spaceship::shootSound()
{
	

	if (!laserBuffer.loadFromFile("blaster-firing.wav"))
	{
		return false;
	}

	
	laser.setBuffer(laserBuffer);
	laser.play();
	return true;
}