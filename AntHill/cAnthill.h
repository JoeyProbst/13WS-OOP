//#pragma once
#ifndef CANTHILL_HEADER
#define	CANTHILL_HEADER

#include "cItem.h"//Basisklassen immer inkludieren
class cField;

//class cCreator;//Forward Declaration

class cAnthill :
	public cItem
{
private:
	int foodcounter;//Zeigt den Essensvorrat an! ist am Anfang mit einem Startkapital gef�llt
	int antcounter;//Zeigt an wie viele Ameisen bestehen!//Sterbende Ameise muss Info �ber ableben an Anthill zur�ckgeben
	cField* Position;
public:
	cAnthill(cField* position);
	~cAnthill(void);
	//accessors
	void act();
	void setAnt();//Joey: Diese Methode ruft den Creator auf um eine Ameise zu erzeugen und setzt diese dann in der Array_oFieldptrs auf das Field des AntHill.
	int getfoodcounter();
	int getantcounter();
};

#endif // !CANTHILL_HEADER


