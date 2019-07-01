
#include "Field.h"
#include <vector>
#include <iostream>
#include "Vector2D.h"
#include <math.h>

constexpr auto PI = 3.14159265;

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
		sf::CircleShape chRep = sf::CircleShape(radius, 50);
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

Vector2D<double> Field::computeEulerStep(const Vector2D<double>& pos)
{
	Vector2D<double> ef = Field::E(pos);
	Vector2D<double> newPos = pos + (ef * stepsize)/ef.length();
	return newPos;
}

double Field::distanceToNearestCharge(const Vector2D<double>& pos)
{
	double maxDist = 0;
	for (std::vector<Charge*>::iterator it = chargeList.begin(); it != chargeList.end(); it++)
	{
		Vector2D<double> diffVec = pos - (*it)->loc;
		double dist = diffVec.length();
		if (dist > maxDist)
			maxDist = dist;
	}
	return maxDist;
}

void Field::drawFieldLines(sf::RenderWindow& win)
{
	int a = 1 + 1;
	/*
	for (std::vector<Charge*>::iterator it = chargeList.begin; it != chargeList.end(); it++)
	{
		unsigned numLines = std::abs((*it)->ch);
		
		for (unsigned i = 0; i < numLines; i++)
		{
			double theta = (double)i * 2 * PI / numLines;
			double startX = (*it)->loc.x + cos(theta) * chargeScale * abs((*it)->ch);
			double startY = (*it)->loc.y + sin(theta) * chargeScale * abs((*it)->ch);
			
			Vector2D<double> thisPos = Vector2D<double>(startX, startY);
			Vector2D<double> prevPos = Vector2D<double>(startX, startY);
			
			for (unsigned i = 0; i < 1000; i++)
			{
				if (distanceToNearestCharge(thisPos) < 10)
					break;

				thisPos = computeEulerStep(thisPos);
				sf::Vertex line[] =
				{
					sf::Vertex(sf::Vector2f(prevPos.x, prevPos.y)),
					sf::Vertex(sf::Vector2f(thisPos.x, thisPos.y))
				};
				win.draw(line, 2, sf::Lines);
				prevPos = thisPos;
			}
			
			
		}
	}*/
}