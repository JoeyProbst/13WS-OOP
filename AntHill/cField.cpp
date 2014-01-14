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
	deadObjects;
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

void cField::adItem(cItem* Item)//Joey: Fügt Items zur Liste hinzu
{
	items.push_back(Item);
}

void cField::actItems(int roundIndicator)//Joey: Diese Methode wird von der Methode actAll() der Klasse Area aufgerufen und soll ihrerseits die Liste des Fields durchiterieren und von jedem Item aus der Liste die Methode act() aufrufen.
{
	for (std::list<cItem*>::iterator listItemsIterator=items.begin() ; listItemsIterator != items.end(); /*++listItemsIterator*/)
	{
		std::list<cItem*>::iterator actualIterator =(*listItemsIterator)->act(roundIndicator, listItemsIterator);//Joey: Hier dereferenzieren wir (also wir greifen auf die Variable auf die der Zeiger listItemsIterator zeigt zu) und um die Abarbeitungsreihenfolge sicherzustellen muss das in Klammer gesetzt werden!
		if (actualIterator==listItemsIterator)
		{
			++listItemsIterator;
		}
		else
		{
			listItemsIterator=actualIterator;
		}
	}
	clearDeadObjects();//deallociere alle toten Items und lösche die Liste der Toten Items

	if (getTypamount(2)==1)//Liegt auf diesem Feld der Ameisenhügel?
	{
		spliceNewbornToItemslist();
	}
}

void cField::remItem(cItem* Item) //Löscht das Item aus der Liste
{
	
			items.remove (Item);

}




//get Functions:
/*const*/ cField* cField::getpNorth() /*const*/
{
	return pNorth;
}

/*const*/ cField* cField::getpEast() /*const*/
{
	return pEast;
}
	
/*const*/ cField* cField::getpSouth() /*const*/
{
	return pSouth;
}
	
/*const*/ cField* cField::getpWest() /*const*/
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
	//Perfekter platz für eine exception!!! Compiler sagt: Nicht alle Steuerelementpfade geben einen Wert zurück.
}

int cField::getTypamount(int typ)// Joey: zählt die Items eines Typs auf einem Feld: TYPNR: 1=Food; 2=Anthill; 3=Ant; 4=Pheromon
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
	return 999;//Unpassender Parameterwert!//hier wäre eine Möglichkeit Exceptionhandling zu üben!
}

//int cField::getListSize()
//{
//	return items.size();
//}

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
		default:
			return NULL;
	}
	//Perfekter platz für eine exception!!! Compiler sagt: Nicht alle Steuerelementpfade geben einen Wert zurück.
}

void cField::addDeadItem(cItem* item)//fügt ein zu löschendes Item der deadObject Liste hinzu!
{
	deadObjects.push_back(item);
}

void cField::clearDeadObjects()//deletet jedes Objekt der deadobjects Liste und leert sie anschließend
{
	for (std::list<cItem*>::iterator i=deadObjects.begin(); i !=deadObjects.end(); ++i)
	{
		delete (*i);
		(*i)=NULL;
	}
	deadObjects.clear();
}

std::list<cItem*>::iterator cField::remByIterator(std::list<cItem*>::iterator actualIterator)//entfernt das Item mittels erase über den mitgegebenen Iterator und gibt den Iterator auf das nächste Feld zurück
{
	return items.erase(actualIterator);
}

void cField::addNewborn(cItem* newAnt)//Fügt eine neue Ameise der newbornAnt Liste hinzu
{
	newbornAnts.push_back(newAnt);		
}

void cField::spliceNewbornToItemslist()//hängt die in newbornAnt enthaltenen Ameisen der items Liste an und cleared die newbornAnt Liste
{
	items.splice(items.end(),newbornAnts);
}

void cField::addFoodToHillList(cItem* Food)
{
	foodToAnthill.push_back(Food);
}

int cField::getSizeofList(int whichList)//gibt die Größen der listen zurück
{
	switch(whichList)
	{
	case 1:
		return items.size();
		break;
	case 2:
		return deadObjects.size();
		break;
	case 3:
		return newbornAnts.size();
		break;
	case 4:
		return foodToAnthill.size();
		break;
	default:
		return 0;
}
	//Perfekter platz für eine exception!!! Compiler sagt: Nicht alle Steuerelementpfade geben einen Wert zurück.
}
	int cField::clearFoodToHillList()
	{
		int Foodcounter=0;

		for (std::list<cItem*>::iterator i=foodToAnthill.begin(); i !=foodToAnthill.end(); ++i)
		{
			delete (*i);
			(*i)=NULL;
			Foodcounter++;
		}
		foodToAnthill.clear();
		return Foodcounter;
	}