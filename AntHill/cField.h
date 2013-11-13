//#pragma once
#ifndef CFIELD_HEADER
#define CFIELD_HEADER

#include <list>
#include "cItem.h"

class cField
{
private:
	cField* pNorth;
	cField* pEast;
	cField* pSouth;
	cField* pWest;
	
	std::list<cItem>items;

public:
	cField(void);
	~cField(void);
	//accessors
	cField* getpNorth();
	cField* getpEast();
	cField* getpSouth();
	cField* getpWest();
};

#endif // !CFIELD_HEADER