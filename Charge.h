#pragma once

#include "Vector2D.h"
#include <math.h>


class Charge
{
public:
	Vector2D<double> loc;
	int ch;
	Charge();
	Charge(Vector2D<double> location, int charge);
};
