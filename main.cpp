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

	Vector2D<double> chargePos1 = Vector2D<double>(100.0, 100.0);
	Vector2D<double> chargePos2 = Vector2D<double>(200.0, 200.0);

	Charge C1 = Charge(chargePos1, 20);
	Charge C2 = Charge(chargePos2, -30);

	Field F = Field();
	F.addCharge(&C1);
	F.addCharge(&C2);

	F.printCharges();

	Vector2D<double> sumPos1 = F.E(Vector2D<double>(101.0, 101.0));
	Vector2D<double> sumPos2 = F.E(Vector2D<double>(400.0, 400.0));

	cout << sumPos1.x << " " << sumPos1.y << endl;
	cout << sumPos2.x << " " << sumPos2.y << endl;

	double startX = 200.0;
	double startY = 140.0;

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
		
		Vector2D<double> prevPos = Vector2D<double>(startX, startY);
		Vector2D<double> thisPos = Vector2D<double>(startX, startY);
		for (unsigned i = 0; i < 1000; i++)
		{
			thisPos = F.computeEulerStep(thisPos, 5);
			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(prevPos.x, prevPos.y)),
				sf::Vertex(sf::Vector2f(thisPos.x, thisPos.y))
			};
			window.draw(line, 2, sf::Lines);
			prevPos = thisPos;
		}
		
		window.display();
	}

	return 0;
}