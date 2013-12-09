//#pragma once
#ifndef CITEM_HEADER
#define CITEM_HEADER

#include <iostream>
#include "cCreator.h"

class cItem
{
public:
	cItem(void);
	~cItem(void);
	//accessors
	virtual void act()=0;//Da eine abstrakte, virtuelle Methode theoretisch noch aufgerufen werden kann setze ich sie hier 0 um das zu verhindern!
	

};

#endif // !CITEM_HEADER



