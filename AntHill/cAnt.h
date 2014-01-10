//#pragma once
#ifndef CANT_HEADER
#define	CANT_HEADER

#include <list>
#include "cItem.h"

class cField;
class cFood;

class cAnt :
	public cItem
{
private:
	int typ;
	int Lunchbox;//Joey: Der Umgang mit der Lunchbox ist noch nicht zu ende gedacht!!!
	int TTL;
	bool phNorth;
	bool phEast;
	bool phSouth;
	bool phWest;

	bool Status;
	std::list<cField*>carrymehomelist;
	cItem* Fund;
	cField* ActualPosition;
	cField* Whatsnext();
	cField*	randway(); 
public:
	//cAnt(void);//Joey: Ich versuche den Konstruktor mal so umzuschreiben, dass die Ameise beim Entstehen ihre momentane Lage mitgegeben bekommt!
	cAnt(cField* ActualPosition);
	~cAnt(void);
	//accessors
	void act() override;
};

#endif // !CANT_HEADER



