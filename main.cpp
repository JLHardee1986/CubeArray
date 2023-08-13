#include <iostream>

#include <SFML/Graphics.hpp>

#include <memory>
#include <utility>
#include "Cube.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	std::unique_ptr<sf::RenderWindow> upWnd = std::make_unique<sf::RenderWindow>(sf::VideoMode(640U, 480U, 32U), "Template", sf::Style::Fullscreen, settings);

	Cube aCube(sf::Color(155,155,255,255), { 100.f, 100.f }, { 64U , 64U });
	float dt;
	TextBox* tBox = nullptr;
	sf::Clock frameTime;
	while (upWnd->isOpen())
	{


		dt = frameTime.restart().asSeconds();
		sf::Event e;
		while (upWnd->pollEvent(e))
		{
			switch (e.type)
			{
				case sf::Event::Closed:
					upWnd->close();
					break;
				case sf::Event::KeyPressed:
					if (e.key.code == sf::Keyboard::Escape)
					{
						upWnd->close();
					}
					else if (e.key.code == sf::Keyboard::T)
					{

					}
					break;
				case sf::Event::TextEntered:
					if (tBox)
						tBox->typedOn(e);
					break;
				default:
					break;
			}

		}

		aCube.update(dt, *upWnd);
		if (aCube.currTextBox)
		{
			tBox = aCube.currTextBox;
		}

		upWnd->clear(sf::Color(sf::Color::Black));
		upWnd->draw(aCube);
		if (tBox)
		{
			tBox->drawTo(*upWnd);
		}
		upWnd->display();
	}

	return EXIT_SUCCESS;
}


