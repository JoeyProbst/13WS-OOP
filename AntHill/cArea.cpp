#include "cArea.h"
//Variable to control creation of cArea!
cArea* cArea::_instance=NULL;
//Method to control the Variable above!
cArea* cArea::Instance()
{
	if (_instance==NULL)
	{
		_instance= new	cArea();
	}
	return	_instance;
}

//Constructor initializes the m x n Array of cField* (environment of our anthill simulation)
cArea::cArea(void)
{
	for (int z=0; z< LINES ; z++)
	{
		for (int sp= 0; sp< COLUMNS; sp++)
		{
			Array_ofFieldptrs[z][sp]= new cField();
		}
	}

	for (int z=0; z< LINES ; z++)
	{
		for (int sp= 0; sp< COLUMNS; sp++)
		{
			if (z!=0)//linking Northptr to field above
			{
				Array_ofFieldptrs[z][sp]->setpNorth(Array_ofFieldptrs[z-1][sp]);
			}
			if(sp<COLUMNS-1)//linking Eastptr to field on the right
			{
				Array_ofFieldptrs[z][sp]->setpEast(Array_ofFieldptrs[z][sp+1]);
			}
			if(z<LINES-1)//linking Southptr to field below
			{
				Array_ofFieldptrs[z][sp]->setpSouth(Array_ofFieldptrs[z+1][sp]);
			}
			if(sp!=0)//linking Westptr to the field on the left
			{
				Array_ofFieldptrs[z][sp]->setpWest(Array_ofFieldptrs[z][sp-1]);
			}

		}
		
		
	}

}


cArea::~cArea(void)
{
	for (int z=0; z< LINES ; z++)
	{
		for (int sp= 0; sp< COLUMNS; sp++)
		{
			delete Array_ofFieldptrs[z][sp];//Frage: reicht es einfach das Array zu deleten oder muss jedes Field deletet werden?
			Array_ofFieldptrs[z][sp]=NULL;
		}
	}
}

/*class cIndicesError
{

};*/
//---------set Methods:

void cArea::setAntHill(cCreator* factory, int z, int sp )//Joey: Initialisiert den Ameisenhaufen auf dem Array_ofFieldptrs - d.h. diese Methode ruft den Creator auf um ihn zu erzeugen und positioniert den Ameisenhaufen dann auf einem der Fields des Arrays. 
{
	cItem* anthill=factory->create(2);//Joey: Der Creator wird aufgerufen um einen Ameisenhaufen zu erzeugen
	if (z ==LINES && sp ==COLUMNS )//Joey: Da die Indizes genau dem Grenzwert entsprechen wird der Ameisenhaufen per Random auf ein Field platziert.
	{
		Array_ofFieldptrs[rand()%LINES][rand()%COLUMNS]->adItem(anthill);
	}
	else if (z < LINES && sp < COLUMNS)//Joey: Da die Indizes einen Wert aufweisen der innerhalb des gültigen Wertebereichs liegt wird der Ameisenhaufen dort platziert
	{
		Array_ofFieldptrs[z][sp]->adItem(anthill);
	}
	/*else
	{
		throw cIndicesError(); 
	}*/
}

void cArea::setFood(cCreator* factory, int z, int sp)//Joey: Initialisiert das Essen auf dem Array_ofFieldptrs - d.h. diese Methode ruft den Creator auf um Essen zu erzeugen und positioniert dann das Essen auf dem Array.
{
	cItem* food=factory->create(1);
	if (z ==LINES && sp ==COLUMNS )//Joey: Da die Indizes genau dem Grenzwert entsprechen wird der Ameisenhaufen per Random auf ein Field platziert.
	{
		Array_ofFieldptrs[rand()%LINES][rand()%COLUMNS]->adItem(food);
	}
	else if (z < LINES && sp < COLUMNS)//Joey: Da die Indizes einen Wert aufweisen der innerhalb des gültigen Wertebereichs liegt wird der Ameisenhaufen dort platziert
	{
		Array_ofFieldptrs[z][sp]->adItem(food);
	}
	/*else
	{
		throw cIndicesError(); 
	}*/

}

//---------get Methods:

const cField* cArea::getFieldptr(int z,int sp) const
{
	
	return Array_ofFieldptrs[z][sp];
}

void cArea::actAll()//Joey: actAll() soll das Array_ofFieldptr durchiterieren und bei jedem Field dessen Methode actItems() aufrufen. 
{

	for (int z=0; z< LINES ; z++)
	{
		for (int sp= 0; sp< COLUMNS; sp++)
		{
			Array_ofFieldptrs[z][sp]->actItems();//Joey: Hier kommt die Fieldmethode actItems() zum Einsatz;
		}
	}


}
