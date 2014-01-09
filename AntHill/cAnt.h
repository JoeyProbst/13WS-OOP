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
	int Lunchbox;
	int TTL;
	bool Status;
	std::list<cField*>carrymehomelist;
	cFood* Fund;
	cField* ActualPosition;
public:
	//cAnt(void);//Joey: Ich versuche den Konstruktor mal so umzuschreiben, dass die Ameise beim Entstehen ihre momentane Lage mitgegeben bekommt!
	cAnt(cField* ActualPosition);
	~cAnt(void);
	//accessors
	void act() override;
};

#endif // !CANT_HEADER



