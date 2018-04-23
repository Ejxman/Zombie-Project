#include "Level.h"
#include "Input.h"
#include "Mysprite.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{ 
	window = hwnd;
	input = in;

	rect.setSize(sf::Vector2f(15, 15));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Red);

	circ.setRadius(10);
	circ.setPosition(300, 300);
	circ.setFillColor(sf::Color::Green);

	texture.loadFromFile("gfx/PlayerA0.png");
	testSprite.setTexture(&texture);
	testSprite.setSize(sf::Vector2f(25, 25));
	testSprite.setPosition(100, 100);

	speed = 100.f;



}
Level::~Level() 
{

}

void Level::update(float dT)
{
	circ.move(speed*dT, 0);
}

void Level::handleInput(float dT)
{ 
	// if space is pressed output to console
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		input->setKeyUp(sf::Keyboard::Space);
		std::cout << "Space was pressed\n";
	}
	if (input->isKeyDown(sf::Keyboard::W))
	{
		input->setKeyUp(sf::Keyboard::W);
		std::cout << "W was pressed\n";
	}
	if (input->isKeyDown(sf::Keyboard::A))
	{
		input->setKeyUp(sf::Keyboard::A);
		std::cout << "A was pressed\n";
	}
	if (input->isKeyDown(sf::Keyboard::S))
	{
		input->setKeyUp(sf::Keyboard::S);
		std::cout << "S was pressed\n";
	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		input->setKeyUp(sf::Keyboard::D);
		std::cout << "D was pressed\n";
	}
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		input->setKeyUp(sf::Keyboard::Escape);
		std::cout << "Escape was pressed\n";
		window->close();
	}
}

void Level::render() 
{
	beginDraw();
	window->draw(testSprite);
	endDraw();
}
void Level::beginDraw() 
{ 
	window->clear(sf::Color::Black); 
}

void Level::endDraw() 
{ 
	window->display(); 
}