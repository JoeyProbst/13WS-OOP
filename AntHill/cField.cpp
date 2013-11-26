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

	items;//Joey: hier muss noch die Items liste initialisiert werden!
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
/*
void cField::adItem()
{
	items.push_back;
}
*/