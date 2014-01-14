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
	int roundBasedTurnIndicator;//Zeigt an ob das Item schon dran war
	//AUSBAUFÄHIGE IDEE//int energy;//Joey: Jedes Food liefert 10 Energie. Mit dieser Energie wird der Proviant der Ameisen aufgefüllt. Gleichzeitig mit dem Auffüllen muss dieese Energie natürlich bei einem, bereits im Ameisenbau abgelegten, Food reduziert werden!  
public:
	cFood(cField* position);
	~cFood(void);
	//accessors
	std::list<cItem*>::iterator act(int roundIndicator, std::list<cItem*>::iterator actualIterator) override;
};

#endif // !CFOOD_HEADER



