#include "Charge.h"


// Default constructor
Charge::Charge() {
	loc = Vector2D<double>();
	ch = 0;
}

// Regular constructor
template<typename T> Charge::Charge(Vector2D<T>& location, double ch)
{
	loc = location;
	ch = charge;
}