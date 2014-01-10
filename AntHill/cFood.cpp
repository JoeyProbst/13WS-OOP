#include "cFood.h"
#include "cField.h"

cFood::cFood(cField* position):typ(1),Position(position)
{
	Position->adItem(this);
}


cFood::~cFood(void)
{
}

//accessors
void cFood::act()
{
	std::cout<<"Ich bin Futter! Jammi"<<std::endl;
}