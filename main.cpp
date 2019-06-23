#include <SFML/Graphics.hpp>
#include "Vector2D.h"
#include <iostream>


using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	Vector2D<double> a = Vector2D<double>(2.0, 4.0);
	Vector2D<double> b = Vector2D<double>(4, 1);
	b = b + a;
	cout << a.x << " " << a.y << endl;
	cout << b.x << " " << b.y << endl;
	cout << a.Length() << endl;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}