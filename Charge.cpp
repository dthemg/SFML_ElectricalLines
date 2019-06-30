#include "Charge.h"


// Default constructor
Charge::Charge() {
	loc = Vector2D<double>();
	ch = 0;
}

// Regular constructor
Charge::Charge(Vector2D<double> location, int charge)
{
	loc = location;
	ch = charge;
}