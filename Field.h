#pragma once

#include <vector>
#include "Vector2D.h"
#include "Charge.h"
#include <SFML/Graphics.hpp>

class Field
{
public:	
	std::vector<Charge *> chargeList;
	Field();
	// There should be a de-constructor here too.

	void addCharge(Charge *ch_ptr);
	void printCharges();
	void draw(sf::RenderWindow&);

	// Compute field at position E
	Vector2D<double> E(const Vector2D<double>& pos);
	double Potential(const Vector2D<double>& pos);

	// Computational
	Vector2D<double> computeEulerStep(const Vector2D<double>& pos, double stepsize);
	

private:
	double chargeScale = 1.0;
	sf::Color negCol = sf::Color(34, 114, 189);
	sf::Color posCol = sf::Color(199, 44, 30);
};



