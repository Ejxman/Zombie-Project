#pragma once
#include "SFML\Graphics.hpp"
#include "Input.h"

class Mysprite : public sf::RectangleShape
{
public:

	Mysprite();
	~Mysprite();

	virtual void update(float dt);

	// sprite speed and direction
	void setVelocity(sf::Vector2f vel);
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocity();

	//sprite state
	bool isAlive() { return alive; }
	void setAlive(bool b) { alive = b; };

	//for sprite collision
	bool isCollider() { return collider; };
	void setCollider(bool b) { collider = b; };
	sf::FloatRect getCollisionBox() { return collisionBox; };
	void setCollisionBox(float x, float y, float width, float height) { collisionBox = sf::FloatRect(x, y, width, height); };
	void setCollisionBox(sf::FloatRect fr) { collisionBox = fr; };
	virtual void updateCollisionBox();
	virtual void collisionResponse(Mysprite* sp);

	//input component
	void setIput(Input* in) { input = in; }

protected:
	//sprite properties
	sf::Vector2f velocity;
	bool alive;

	//collision vars
	sf::FloatRect collisionBox;
	bool collider;

	//input component
	Input* input;

};