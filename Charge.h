#pragma once

#include "Vector2D.h"
#include <math.h>


class Charge
{
public:
	Vector2D<double> loc;
	double ch;
	Charge();
	template<typename T> Charge(Vector2D<T>& location, double charge);
};
