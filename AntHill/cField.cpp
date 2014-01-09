#include "cField.h"
//#include <list>
#include <iostream>
#include <typeinfo>
#include "cAnthill.h"
using namespace std;

cField::cField()
{
	
	pNorth=NULL;
	pEast=NULL;
	pSouth=NULL;
	pWest=NULL;

	items;//Joey: hier muss noch die Items liste initialisiert werden!
}


cField::~cField(void)
{
}

//set Functions:

void cField::setpNorth(cField* North )
{
	pNorth=North;
}

void cField::setpEast(cField* East)
{
	pEast=East;
}

void cField::setpSouth(cField* South)
{
	pSouth=South;
}

void cField::setpWest(cField* West)
{
	pWest=West;
}

void cField::adItem(cItem* Item)//Joey: F�gt Items zur Liste hinzu
{
	items.push_back(Item);
}

void cField::actItems()//Joey: Diese Methode wird von der Methode actAll() der Klasse Area aufgerufen und soll ihrerseits die Liste des Fields durchiterieren und von jedem Item aus der Liste die Methode act() aufrufen.
{
	for (std::list<cItem*>::iterator listItemsIterator=items.begin() ; listItemsIterator != items.end(); ++listItemsIterator)
	{
		(*listItemsIterator)->act();//Joey: Hier dereferenzieren wir (also wir greifen auf die Variable auf die der Zeiger listItemsIterator zeigt zu) und um die Abarbeitungsreihenfolge sicherzustellen muss das in Klammer gesetzt werden!
	}
}

void cField::remItem(cItem* Item) //L�scht das Item aus der Liste
{
	
			items.remove (Item);

}




//get Functions:
const cField* cField::getpNorth() const
{
	return pNorth;
}

const cField* cField::getpEast() const
{
	return pEast;
}
	
const cField* cField::getpSouth() const
{
	return pSouth;
}
	
const cField* cField::getpWest() const
{
	return pWest;
}

cItem* cField::getfoodstati()
{
	cItem* Food=NULL;

	for (std::list<cItem*>::iterator listItemsIterator=items.begin() ; listItemsIterator != items.end(); ++listItemsIterator)
	{
		if((*listItemsIterator)->typ==1)
		{
			Food=(*listItemsIterator);
			items.remove(*listItemsIterator);
			return Food;
		}
	}
	return Food;
}

