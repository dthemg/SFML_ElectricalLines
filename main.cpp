#include <SFML/Graphics.hpp>
//#include "Vector2D.h"
#include <iostream>
//#include "Charge.cpp"
#include "Field.h"

using namespace std;

int main()
{
	const int width = 800;
	const int height = 800;
	
	sf::RenderWindow window(sf::VideoMode(width, height), "Field Lines");
	window.setFramerateLimit(10); // Limit to 10 Hz

	Vector2D<double> chargePos1 = Vector2D<double>(200.0, 100.0);
	Vector2D<double> chargePos2 = Vector2D<double>(500.0, 600.0);

	Charge C1 = Charge(chargePos1, 10);
	Charge C2 = Charge(chargePos2, -5);

	Field F = Field();
	F.addCharge(&C1);
	F.addCharge(&C2);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		F.draw(window);
		
		window.display();
	}

	return 0;
}