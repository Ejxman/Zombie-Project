#include "level.h"
#include "Input.h"
void main()
{
	// Create Window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Zombie");
	//Initialise level object
	Input input;
	Level level(&window, &input);

	//For Delta Time
	sf::Clock clock;
	float deltaTime;

	//enum class Gamestate{Menu, Game, Leaderboard};

	//Game loop
	while (window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
			window.close();
			break;
			case sf::Event::Resized:
				window.setView(sf::View(sf::FloatRect(0, 0, (float)event.size.width, (float)event.size.height)));
				break;
			case sf::Event::KeyPressed:
				// update input class
				input.setKeyDown(event.key.code);
				break;
			case sf::Event::KeyReleased:
				//update input class
				input.setKeyUp(event.key.code);
				break;
			case sf::Event::MouseMoved:
				//update input class
				input.setMousePosition(event.mouseMove.x,
					event.mouseMove.y);
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					//update input class
					input.setMouseLeftDown(true);
				}
				break;
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					//update input class
					input.setMouseLeftDown(false);
				}
				break;
			default:
			//dont handle other events
				break;


			}
		}

		//Calculate delta time. How much time has passed 
		//Since it was last calculated (in seconds) and start the clock
		deltaTime = clock.restart().asSeconds();

		//Level
		//Call standard game loop functions (input, update and render)
		level.handleInput(deltaTime);
		level.update(deltaTime);
		level.render();
	}
}