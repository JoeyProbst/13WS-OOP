#include "cAnthill.h"
#include "cCreator.h"
#include "cField.h"

cAnthill::cAnthill(cField* position):Position(position),typ(2),foodcounter(50)/*Startkapital an Essen*/,antcounter(0)/*noch keine Ameisen am Anfang*/,roundBasedTurnIndicator(0)
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
std::list<cItem*>::iterator cAnthill::act(int roundIndicator, std::list<cItem*>::iterator actualIterator)
{
	std::cout<<"Ich bin ein Ameisenhaufen!"<<std::endl;
	check();

	if (foodcounter>0)
	{
		setAnt();
	}

	check();

	return actualIterator;
}

void cAnthill::setAnt()//Joey: Diese Methode ruft den Creator auf um eine Ameise zu erzeugen und setzt diese dann in der Array_ofFieldptrs auf das Field des AntHill.
{
	cItem* ant;

	//if (antcounter==0 && foodcounter==100)//erste Ameise wird geboren! NUR IN ZUSAMMENHANG MIT LUNCHBOX SINNVOLL!
	//{
		ant=cCreator::Instance()->create(3, Position);
		antcounter++;
		foodcounter--;
	//}
	/*//Wäre nur von nutzen wenn die Lunchbox realisiert worden wäre
	if (!(foodcounter/antcounter<5))//solange noch mehr als 5% Futter im Bau vorhanden, werden Ameisen generiert
	{
		ant=cCreator::Instance()->create(3, Position);
	}
	*/
}

void cAnthill::check()//Überprüft ob Futter auf dem Feld des Ameisenhügels und verarbeitet dieses falls vorhanden
{
	cItem* Food =NULL;

	/*for(int i=Position->getTypamount(1); i>0;i--)
	{
		if((Food=Position->getFOODifTHEREis())!=NULL)
		{*/
			//delete Food;//!!!
			//Position->remByIterator(actualIterator);
			//Position->addDeadItem(Food);
			//foodcounter++;
		/*}
	}*/
	if (Position->getSizeofList(4)>0)
	{
		foodcounter +=Position->clearFoodToHillList();
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

//void cAnthill::redantcounter()
//{
//	antcounter--;
//}