//#pragma once
#ifndef CDLCONTAINER_HEADER
#define CDLCONTAINER_HEADER

#include "CPJob.h"

//class CdlContainer define a Container of a doubly linked list
//with a *next, a *data and a *prev

class CdlContainer
{
public:
//private:
	CdlContainer* prev;
	CPJob* data;
	CdlContainer* next;
public:
	//constructor
	CdlContainer(void); //inits every Container with a Nullpointer for next and prev, and a "NO DATA" string for data.
	
	//destructor
	~CdlContainer(void);
};

#endif // !CDLCONTAINER_HEADER