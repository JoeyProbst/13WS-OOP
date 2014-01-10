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
	int foodcounter;//Zeigt den Essensvorrat an! ist am Anfang mit einem Startkapital gefüllt
	int antcounter;//Zeigt an wie viele Ameisen bestehen!//Sterbende Ameise muss Info über ableben an Anthill zurückgeben
	cField* Position;
	int typ;
public:
	cAnthill(cField* position);
	~cAnthill(void);
	//accessors
	void act();
	void setAnt();//Joey: Diese Methode ruft den Creator auf um eine Ameise zu erzeugen und setzt diese dann in der Array_oFieldptrs auf das Field des AntHill.
	int getfoodcounter();
	int getantcounter();
	void reduceAntcounter();//Methode um den Tod einer Ameise im Ameisenzähler des Ameisenhügels festzuhalten und gleichzeitig den EnvironmentFoodCounter um eines zu erhöhen (Da die tote Ameise ja zu neuem Futter wird)!
};

#endif // !CANTHILL_HEADER


