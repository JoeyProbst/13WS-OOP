#include "cField.h"
#include <list>
#include <iostream>
using namespace std;

cField::cField()
{
	
	pNorth=NULL;
	pEast=NULL;
	pSouth=NULL;
	pWest=NULL;

	//Joey: hier muss noch die Items liste initialisiert werden!
}


cField::~cField(void)
{
}


//set Functions
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


//get Functions
cField* cField::getpNorth()
{
	return pNorth;
}

cField* cField::getpEast()
{
	return pEast;
}
	
cField* cField::getpSouth()
{
	return pSouth;
}
	
cField* cField::getpWest()
{
	return pWest;
}

/*void cField::adItem()
{
	items.push_back;
}
*/