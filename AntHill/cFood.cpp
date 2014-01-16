#include "cFood.h"
#include "cField.h"

cFood::cFood(cField* position):typ(1),Position(position),roundBasedTurnIndicator(0),cItem(1)
{
	Position->adItem(this);
}


cFood::~cFood(void)
{
}

//accessors
std::list<cItem*>::iterator cFood::act(int roundIndicator, std::list<cItem*>::iterator actualIterator)
{
	std::cout<<"Ich bin Futter! Jammi"<<"Auf dem Feld: "<<Position<<std::endl;
	return actualIterator;
}