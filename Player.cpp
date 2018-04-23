#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::update(float dt)
{
	if (input->isKeyDown(sf::Keyboard::D))
	{
		move(velocity*dt);
	}
	if (input->isKeyDown(sf::Keyboard::A))
	{
		move(-velocity * dt);
	}
}