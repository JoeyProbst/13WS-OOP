//#pragma once
#ifndef CAREA_HEADER
#define CAREA_HEADER

#define COLUMNS 20
#define LINES 20

#include "cField.h"

class cArea
{
private:
	cField* Array_ofFieldptrs[LINES][COLUMNS]; //Joey: Ich denke die beste Variante ist die eines Arrays von Zeigern auf Fields  
public:
	cArea(void);
	~cArea(void);
	//accessors
	cField* getFieldptr(int z,int sp);//returns a pointer to a cField from the Array_ofFieldptrs through the index of the Fieldptr in the array
};

#endif // !CAREA_HEADER



