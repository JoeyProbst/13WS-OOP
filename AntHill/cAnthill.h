//#pragma once
#ifndef CANTHILL_HEADER
#define	CANTHILL_HEADER

#include "cItem.h"//Basisklassen immer inkludieren

class cCreator;//Forward Declaration

class cAnthill :
	public cItem
{
private:
	int foodcounter;//Zeigt den Essensvorrat an! ist am Anfang mit einem Startkapital gefüllt
	int antcounter;//Zeigt an wie viele Ameisen bestehen!
public:
	cAnthill(void);
	~cAnthill(void);
	//accessors
	void act();
	void setAnt();//Joey: Diese Methode ruft den Creator auf um eine Ameise zu erzeugen und setzt diese dann in der Array_ofFieldptrs auf das Field des AntHill.
};

#endif // !CANTHILL_HEADER


