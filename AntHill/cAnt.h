//#pragma once
#ifndef CANT_HEADER
#define	CANT_HEADER

#include "cItem.h"

class cAnt :
	public cItem
{
public:
	cAnt(void);
	~cAnt(void);
	//accessors
	void act() override;
};

#endif // !CANT_HEADER



