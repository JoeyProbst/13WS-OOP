#include "cPheromone.h"
#include "cField.h"

cPheromone::cPheromone(cField* position):intensity(30),typ(4),Position(position)
{
}


cPheromone::~cPheromone(void)
{
	Position->remItem(this);
}

void cPheromone::act()//Joey: z�hlt die Intensit�t des Pheromons hinunter!
{
	intensity--;
	if(intensity==0)
	{
		delete this;
	}

}