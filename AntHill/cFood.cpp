#include "cFood.h"
#include "cField.h"

cFood::cFood(cField* position):typ(1),Position(position),roundBasedTurnIndicator(0)
{
	Position->adItem(this);
}


cFood::~cFood(void)
{
}

//accessors
void cFood::act(int roundIndicator)
{
	std::cout<<"Ich bin Futter! Jammi"<<std::endl;
}