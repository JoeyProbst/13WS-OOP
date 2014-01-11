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

cItem* cField::getFOODifTHEREis()
{
	cItem* Food=NULL;

	for (std::list<cItem*>::iterator listItemsIterator=items.begin() ; listItemsIterator != items.end(); ++listItemsIterator)
			{
				if((*listItemsIterator)->typ==2)
				{
					Food=(*listItemsIterator);
					items.remove(*listItemsIterator);
					return Food;
				}
			}
}

int cField::getTypamount(int typ)// Joey: z�hlt die Items eines Typs auf einem Feld: TYPNR: 1=Food; 2=Anthill; 3=Ant; 4=Pheromon
{
	int counter=0;

	switch (typ)
	{
		case 2://Anthill
			for (std::list<cItem*>::iterator listItemsIterator=items.begin() ; listItemsIterator != items.end(); ++listItemsIterator)
			{
				if((*listItemsIterator)->typ==2)
				{
					
					return 1;
				}
			}
			return 0;
			break;
		case 1://Food
			for (std::list<cItem*>::iterator listItemsIterator=items.begin() ; listItemsIterator != items.end(); ++listItemsIterator)
			{
				if((*listItemsIterator)->typ==1)
				{
					counter++;
				}
			}
			return counter;
			break;
		case 3://Ant
			for (std::list<cItem*>::iterator listItemsIterator=items.begin() ; listItemsIterator != items.end(); ++listItemsIterator)
			{
				if((*listItemsIterator)->typ==3)
				{
					counter++;
				}
			}
			return counter;
			break;
		case 4://Pheromone
			for (std::list<cItem*>::iterator listItemsIterator=items.begin() ; listItemsIterator != items.end(); ++listItemsIterator)
			{
				if((*listItemsIterator)->typ==4)
				{
					counter++;
				}
			}
			return counter;
			break;
	}
	return 999;//Falscher Parameter!//hier w�re eine M�glichkeit Exceptionhandling zu �ben!
}

/*const*/ cField* cField::directioniter(int direction)
{
	switch (direction)
	{
		case 1:
			return this->getpNorth();
			break;
		case 2:
			return this->getpEast();
			break;
		case 3:
			return this->getpSouth();
			break;
		case 4:
			return this->getpWest();
			break;
			return NULL;
	}
}

//cItem* cField::getFieldInfo(int typ)// 1=Food; 2=Anthill; 3=Ant; 4=Pheromon
//{
//	cItem* Item=NULL;
//
//	switch (typ)
//	{
//		case 2://Anthill
//			for (std::list<cItem*>::iterator listItemsIterator=items.begin() ; listItemsIterator != items.end(); ++listItemsIterator)
//			{
//				if((*listItemsIterator)->typ==2)
//				{
//					Item=(*listItemsIterator);
//					items.remove(*listItemsIterator);
//					return Item;
//				}
//			}
//			return Item;
//		case 1://Food
//			for (std::list<cItem*>::iterator listItemsIterator=items.begin() ; listItemsIterator != items.end(); ++listItemsIterator)
//			{
//				if((*listItemsIterator)->typ==1)
//				{
//					Item=(*listItemsIterator);
//					items.remove(*listItemsIterator);
//					return Item;
//				}
//			}
//			return Item;
//		case 3://Ant
//			for (std::list<cItem*>::iterator listItemsIterator=items.begin() ; listItemsIterator != items.end(); ++listItemsIterator)
//			{
//				if((*listItemsIterator)->typ==3)
//				{
//					Item=(*listItemsIterator);
//					items.remove(*listItemsIterator);
//					return Item;
//				}
//			}
//			return Item;
//		case 4://Pheromone
//			for (std::list<cItem*>::iterator listItemsIterator=items.begin() ; listItemsIterator != items.end(); ++listItemsIterator)
//			{
//				if((*listItemsIterator)->typ==4)
//				{
//					Item=(*listItemsIterator);
//					items.remove(*listItemsIterator);
//					return Item;
//				}
//			}
//			return Item;
//	}
//	return Item;
//}

