//#pragma once
#ifndef CAREA_HEADER
#define CAREA_HEADER

#define COLUMNS 10
#define LINES 10

#include "cField.h"

class cArea
{
protected:
	cArea(void);//FOR SINGLETONPETTERN: Constructor has to be protected for a SingletonPattern
private:
	cField* Array_ofFieldptrs[LINES][COLUMNS]; //Joey: Ich denke die beste Variante ist die eines Arrays von Zeigern auf Fields  
	static cArea* _instance;//FOR SINGLETONPETTERN: is NULL if there is no Area; is the Pointer to the Area if Area is already created
public:
	~cArea(void);
	//accessors
	static	cArea* Instance();//FOR SINGLETONPETTERN: Method to control if there is already an Area
	cField* getFieldptr(int z,int sp);//returns a pointer to a cField from the Array_ofFieldptrs through the index of the Fieldptr in the array
};

#endif // !CAREA_HEADER



