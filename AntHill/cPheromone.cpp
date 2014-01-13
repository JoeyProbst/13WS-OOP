#include "cPheromone.h"
#include "cField.h"

cPheromone::cPheromone(cField* position):intensity(30),typ(4),Position(position),roundBasedTurnIndicator(0)
{
}


cPheromone::~cPheromone(void)
{
	Position->remItem(this);
}

void cPheromone::act(int roundIndicator)//Joey: zählt die Intensität des Pheromons hinunter!
{
	intensity--;
	if(intensity==0)
	{
		delete this;
	}

}