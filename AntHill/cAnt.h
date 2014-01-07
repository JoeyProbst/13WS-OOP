//#pragma once
#ifndef CANT_HEADER
#define	CANT_HEADER

#include "cItem.h"
class cField;
class cFood;

class cAnt :
	public cItem
{
private:
	int Lunchbox;
	int TTL;
	bool Status;
	std::list<cField*>carrymehomelist;
	cFood* Fund;
	cField* ActualPosition;
public:
	cAnt(void);
	~cAnt(void);
	//accessors
	void act() override;
};

#endif // !CANT_HEADER



