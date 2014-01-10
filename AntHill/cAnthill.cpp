#include "cAnthill.h"
#include "cCreator.h"
#include "cField.h"

cAnthill::cAnthill(cField* position):Position(position),typ(2),foodcounter(50)/*Startkapital an Essen*/,antcounter(0)/*noch keine Ameisen am Anfang*/
{
	Position->adItem(this);
	//ÜBERLEGUNG//Joey: Eine Scheife die für das im foodcounter als Startkapital veranschlagte Essen, cFood in die Liste des Feldes, auf dem der Ameisenhügel steht, legt!
	for (int i = 0; i <= antcounter; i++)
	{
		cCreator::Instance()->create(1,Position);
	}
}


cAnthill::~cAnthill(void)
{
}

//accessors
void cAnthill::act()
{
	std::cout<<"Ich bin ein Ameisenhaufen!"<<std::endl;
	setAnt();
}

void cAnthill::setAnt()//Joey: Diese Methode ruft den Creator auf um eine Ameise zu erzeugen und setzt diese dann in der Array_ofFieldptrs auf das Field des AntHill.
{
	cItem* ant;

	if (antcounter==0 && foodcounter==100)//erste Ameise wird geboren!
	{
		ant=cCreator::Instance()->create(3, Position);
		antcounter++;
	}

	if (!(foodcounter/antcounter<5))//solange noch mehr als 5% Futter im Bau vorhanden, werden Ameisen generiert
	{
		ant=cCreator::Instance()->create(3, Position);
	}

}

int cAnthill::getfoodcounter()
{
	return foodcounter;
}

int cAnthill::getantcounter()
{
	return antcounter;
}

void cAnthill::redantcounter()
{
	antcounter--;
}