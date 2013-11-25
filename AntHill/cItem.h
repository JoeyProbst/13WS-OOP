//#pragma once
#ifndef CITEM_HEADER
#define CITEM_HEADER

#include <iostream>

class cItem
{
public:
	cItem(void);
	~cItem(void);
	//accessors
	virtual void act() =0;
};

#endif // !CITEM_HEADER



