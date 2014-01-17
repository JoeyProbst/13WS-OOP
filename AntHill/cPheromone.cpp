#include "cPheromone.h"
#include "cField.h"

cPheromone::cPheromone(cField* position):cItem(4),intensity(30),typ(4),Position(position),roundBasedTurnIndicator(0)
{
}


cPheromone::~cPheromone(void)
{
	//Position->remItem(this);
}

std::list<cItem*>::iterator cPheromone::act(int roundIndicator, std::list<cItem*>::iterator actualIterator)//Joey: zählt die Intensität des Pheromons hinunter!
{
	if(roundIndicator!=roundBasedTurnIndicator)
	{
		std::cout<<"Ich bin Pheromon!"<<"Position: "<<Position<<std::endl;
		intensity--;
		if(intensity==0)
		{
			Position->addDeadItem(this);
			return Position->remByIterator(actualIterator);
		}
		roundBasedTurnIndicator=roundIndicator;
	}
	return actualIterator ;
}