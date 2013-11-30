//#pragma once
#ifndef CFIELD_HEADER
#define CFIELD_HEADER

#include <list>
#include "cItem.h"
#include "cCreator.h"

class cField
{
private:
	cField* pNorth;
	cField* pEast;
	cField* pSouth;
	cField* pWest;
	
	std::list<cItem*>items;

public:
	cField();
	~cField(void);
	//accessors
	void setpNorth(cField*);
	void setpEast(cField*);
	void setpSouth(cField*);
	void setpWest(cField*);

	const cField* getpNorth() const;
	const cField* getpEast() const;
	const cField* getpSouth() const;
	const cField* getpWest() const;

	void adItem();
	void actItems();

};

#endif // !CFIELD_HEADER