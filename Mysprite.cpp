#include "Mysprite.h"
Mysprite::~Mysprite()
{}

Mysprite::Mysprite() : RectangleShape()
{}

//override this function to provide functionality
void Mysprite::update(float dt)
{
}

//sets the velocity of the sprite
void Mysprite::setVelocity(sf::Vector2f vel)
{
	velocity = vel;
}
void Mysprite::setVelocity(float vx, float vy)
{
	velocity.x = vx;
	velocity.y = vy;
}
//get sprite velocity
sf::Vector2f Mysprite::getVelocity()
{
	return velocity;
}

//default function for collision update
void Mysprite::updateCollisionBox()
{
	//Axis aligned bounding Box, based on sprite size and position.
	//shape could be smaller/larger and offset if required
	//can be overwritten by child classes
	collisionBox.left += getPosition().x;
	collisionBox.top += getPosition().y;
}

//response function, what the sprite does based on collision
//colliding object is passed in for information
//e.g. compare sprite positions to determine new velocity direction
//e.g. checking sprite type (world, enemy, bullet, etc) so response is based on that
void Mysprite::collisionResponse(Mysprite* sp)
{
}