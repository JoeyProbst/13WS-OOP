//#pragma once
#ifndef CANTHILL_HEADER
#define	CANTHILL_HEADER

#include "cItem.h"

class cAnthill :
	public cItem
{
public:
	cAnthill(void);
	~cAnthill(void);
	//accessors
	void act() override;
};

#endif // !CANTHILL_HEADER


