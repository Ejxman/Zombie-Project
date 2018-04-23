#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Input.h"
#include "Mysprite.h"

class Level {
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float); 
	void update(float); 
	void render();

private: 
	Input* input;

	sf::RenderWindow* window;
	sf::RectangleShape rect;

	Mysprite testSprite;
	sf::Texture texture;

	//moving variables
	sf::CircleShape circ;
	float speed;
	void beginDraw(); 
	void endDraw();
};
