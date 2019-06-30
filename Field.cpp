
#include "Field.h"
#include <vector>
#include <iostream>
#include "Vector2D.h"

// Default constructor
Field::Field()
{
}

// Add charge pointer to vector
void Field::addCharge(Charge *ch_ptr)
{
	chargeList.push_back(ch_ptr);
}

void Field::printCharges()
{
	for (std::vector<Charge *>::iterator it = chargeList.begin(); it != chargeList.end(); it++)
	{
		std::cout << "Charge: " << (*it)->ch << " at (x,y) = (" << (*it)->loc.x << "," << (*it)->loc.y << ")" <<  std::endl;
	}
}

Vector2D<double> Field::E(const Vector2D<double>& pos)
{
	Vector2D<double> sumE = Vector2D<double>();
	for (std::vector<Charge*>::iterator it = chargeList.begin(); it != chargeList.end(); it++)
	{
		Vector2D<double> toPos = pos - ((*it)->loc);
		double len = toPos.length();
		Vector2D<double> result = toPos / pow(len, 3);
		result = result * ((*it)->ch);
		sumE = sumE + result;
	}
	return sumE;
}

double Field::Potential(const Vector2D<double>& pos)
{
	double sumPot = 0;
	for (std::vector<Charge*>::iterator it = chargeList.begin(); it != chargeList.end(); it++)
	{
		sumPot += (*it)->ch / (pos - ((*it)->loc)).length();
	}
	return sumPot;
}

void Field::draw(sf::RenderWindow& win)
{
	for (std::vector<Charge*>::iterator it = chargeList.begin(); it != chargeList.end(); it++)
	{
		double radius = (double)chargeScale * ((*it)->ch);
		sf::CircleShape chRep(20, 50);
		chRep.setOrigin(radius, radius);
		chRep.setPosition((*it)->loc.x, (*it)->loc.y);
		if ((*it)->ch > 0) {
			chRep.setFillColor(posCol);
		} else {
			chRep.setFillColor(negCol);
		}
		win.draw(chRep);
	}
}

Vector2D<double> Field::computeEulerStep(const Vector2D<double>& pos, double stepsize)
{
	Vector2D<double> ef = Field::E(pos);
	Vector2D<double> newPos = pos + ef * stepsize;
	return newPos;
}

