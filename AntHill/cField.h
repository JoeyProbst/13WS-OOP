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
	cField();
	~cField(void);
	//accessors
	void setpNorth(cField*);
	void setpEast(cField*);
	void setpSouth(cField*);
	void setpWest(cField*);

	cField* getpNorth();
	cField* getpEast();
	cField* getpSouth();
	cField* getpWest();

	void adItem();

};

#endif // !CFIELD_HEADER