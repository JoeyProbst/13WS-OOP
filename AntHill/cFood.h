//#pragma once
#ifndef CFOOD_HEADER
#define	CFOOD_HEADER

#include <iostream>
#include "cItem.h"
class cField;

class cFood : public cItem
{
private:
	int typ;
	cField* Position;
	//AUSBAUF�HIGE IDEE//int energy;//Joey: Jedes Food liefert 10 Energie. Mit dieser Energie wird der Proviant der Ameisen aufgef�llt. Gleichzeitig mit dem Auff�llen muss dieese Energie nat�rlich bei einem, bereits im Ameisenbau abgelegten, Food reduziert werden!  
public:
	cFood(cField* position);
	~cFood(void);
	//accessors
	void act() override;
};

#endif // !CFOOD_HEADER



