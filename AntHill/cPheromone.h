//#pragma once
#ifndef CPHEROMONE_HEADER
#define CPHEROMONE_HEADER

#include "cItem.h"

class cField;

class cPheromone :
	public cItem
{
private:
	int intensity;//Joey: zeigt die Intensität des Pheromons an!
	int typ;
	cField* Position;
public:
	cPheromone(cField* position);
	~cPheromone(void);
	void act();//Joey: zählt die Intensität des Pheromons hinunter!
};

#endif // !CPHEROMONE_HEADER