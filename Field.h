#pragma once

#include <vector>
#include "Vector2D.h"
#include "Charge.h"

class Field
{
public:
		
	std::vector<Charge *> chargeList;
	Field();
	
	void addCharge(Charge *ch_ptr);
};



