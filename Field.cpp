
#include "Field.h"
#include <vector>

// Default constructor
Field::Field()
{
}

void Field::addCharge(Charge *ch_ptr)
{
	chargeList.push_back(ch_ptr);
}