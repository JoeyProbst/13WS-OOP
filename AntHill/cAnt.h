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
	//int Lunchbox;//Joey: Der Umgang mit der Lunchbox ist noch nicht zu ende gedacht!!!
	int TTL;
	/*bool phNorth;
	bool phEast;
	bool phSouth;
	bool phWest;*/
	int roundBasedTurnIndicator;//Zeigt an ob das Item schon dran war
	
	bool state;
	std::list<cField*>carrymehomelist;
	cItem* Fund;
	cField* ActualPosition;
	//cField* whatsNext();
	void search();//Auf der Suche nach Futter
	void take();//Futter aufnehmen
	void gohome();//Mit dem Futter nach Hause gehen
	void giveback();//Legt Pheromon ab oder das gefundene Futter falls am aktuellen Feld der Ameisenhügel liegt
	//cField*	randway();
	int compare(/*const*/ cField* choice, /*const*/ cField* current);
public:
	//cAnt(void);//Joey: Ich versuche den Konstruktor mal so umzuschreiben, dass die Ameise beim Entstehen ihre momentane Lage mitgegeben bekommt!
	cAnt(cField* ActualPosition);
	~cAnt(void);
	//accessors
	void act(int roundIndicator) override;
};

#endif // !CANT_HEADER



