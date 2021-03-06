//#pragma once
#ifndef CANTHILL_HEADER
#define	CANTHILL_HEADER

#include "cObserver.h"
#include "cItem.h"//Basisklassen immer inkludieren
//#include <list>
class cField;

//class cCreator;//Forward Declaration

class cAnthill :
	public cItem, public cObserver
{
private:
	int foodcounter;//Zeigt den Essensvorrat an! ist am Anfang mit einem Startkapital gef�llt
	int antcounter;//Zeigt an wie viele Ameisen bestehen!//Sterbende Ameise muss Info �ber ableben an Anthill zur�ckgeben
	cField* Position;
	int typ;
	int roundBasedTurnIndicator;
	void check();//�berpr�ft ob Futter auf dem Feld des Ameisenh�gels und verarbeitet dieses falls vorhanden
	void setAnt();//Joey: Diese Methode ruft den Creator auf um eine Ameise zu erzeugen und setzt diese dann in der Array_oFieldptrs auf das Field des AntHill.
public:
	cAnthill(cField* position);
	~cAnthill(void);
	//accessors
	std::list<cItem*>::iterator act(int roundIndicator, std::list<cItem*>::iterator actualIterator);
	void update(cSubject*);
	int getfoodcounter();
	int getantcounter();
	void reduceAntcounter();//Methode um den Tod einer Ameise im Ameisenz�hler des Ameisenh�gels festzuhalten und gleichzeitig den EnvironmentFoodCounter um eines zu erh�hen (Da die tote Ameise ja zu neuem Futter wird)!
};

#endif // !CANTHILL_HEADER


