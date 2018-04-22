#include "Spaceship.h"


void Spaceship::moveSpaceship(sf::Event pressKey, sf::RenderWindow &window)
{
	//shipVelocity = 10;
	int acceleration = 2;
	if (pressKey.type == sf::Event::KeyPressed)
	{
		if (pressKey.key.code == sf::Keyboard::W)// && shipVelocity > -10)
		{
			if (shipVelocity > 0)
				shipVelocity = 0;
			if (this->getPosition().y > 0)
			{
				if(shipVelocity > -10)
					shipVelocity -= acceleration;
				this->move(0, shipVelocity);
			}
		}
		else if (pressKey.key.code == sf::Keyboard::S)// && shipVelocity < 10)
		{
			if (shipVelocity < 0)
				shipVelocity = 0;
			if (this->getPosition().y < window.getSize().y - window.getSize().y*0.14)
			{
				if (shipVelocity < 10)
					shipVelocity += acceleration;
				this->move(0, shipVelocity);
			}
				
			
		}
		
	}
}


void Spaceship::shootSpaceship(sf::Event pressKey)
{
	if (pressKey.type == sf::Event::KeyPressed)
	{
		if (pressKey.key.code == sf::Keyboard::Space)
		{
			
			circle.setRadius(20);
			circle.setFillColor(sf::Color::Blue);
			circle.setPosition(this->getPosition().x, this->getPosition().y + 35);
		
			shootSound();
			
			
			
		}
		else
		{
			circle.setRadius(0); //Remove circle when another button is pressed. Probably take out later.
		}
		
	}
	
}

sf::CircleShape & Spaceship::getBullet()
{
	return circle;
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