//#pragma once
#ifndef CFOOD_HEADER
#define	CFOOD_HEADER

#include "cItem.h"

class cFood :
	public cItem
{
public:
	cFood(void);
	~cFood(void);
	//accessors
	void act() override;
};

#endif // !CFOOD_HEADER



