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
	return 0;
}

cField* cField::getpEast()
{
	return 0;
}
	
cField* cField::getpSouth()
{
	return 0;
}
	
cField* cField::getpWest()
{
	return 0;
}

/*void cField::adItem()
{
	items.push_back;
}
*/