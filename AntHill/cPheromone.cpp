#include "cPheromone.h"
#include "cField.h"

cPheromone::cPheromone(cField* position):intensity(30),typ(4),Position(position),roundBasedTurnIndicator(0)
{
}


cPheromone::~cPheromone(void)
{
	Position->remItem(this);
}

std::list<cItem*>::iterator cPheromone::act(int roundIndicator, std::list<cItem*>::iterator actualIterator)//Joey: zählt die Intensität des Pheromons hinunter!
{
	intensity--;
	if(intensity==0)
	{
		delete this;
	}

}