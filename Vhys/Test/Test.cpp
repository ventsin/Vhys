#include <SFML\Graphics.hpp>
#include "..\Vhys\World.hpp"
#include <sstream>

void main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Vhys");
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
		return;

	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(24);
	text.setColor(sf::Color::Cyan);
	text.setString("Hello World");

	//Create our world and set gravity
	vh::World world;
	world.setGravity(vh::Vector(0.f, 9.8f));

	//Create our body
	vh::Body* body = world.registerBody(
		vh::Vector(100.f, 100.f), //Position
		vh::Vector(50.f, 50.f), //Size
		10.f, //Mass
		true, //Dynamic body?
		0); //Automatically generate body ID

			//Start our game loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Update the world every tick
		world.update();
		
		std::ostringstream oss;
		oss << "Body X: " << body->m_position.x
			<< " Body Y: " << body->m_position.y
			<< " Body Width: " << body->m_size.x
			<< " Body Height: " << body->m_size.y << ".\n";

		text.setString(oss.str());

		window.clear();
		window.draw(text);
		window.display();
	}
}