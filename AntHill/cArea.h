//#pragma once
#ifndef CAREA_HEADER
#define CAREA_HEADER

#define COLUMNS 10
#define LINES 10

#include "cField.h"

class cArea
{
private:
	cArea(const cArea&); //Standard Copy-Constructor eingebaut um den SingletonPattern abzusichern und die Lücke durch den Standard Copy-Constructor, den C++ per default erstellt, zu schließen
	cField* Array_ofFieldptrs[LINES][COLUMNS]; //Joey: Ich denke die beste Variante ist die eines Arrays von Zeigern auf Fields 
	static cArea* _instance;//FOR SINGLETONPETTERN: is NULL if there is no Area; is the Pointer to the Area if Area is already created
protected:
	cArea(void);//FOR SINGLETONPETTERN: Constructor has to be protected for a SingletonPattern
public:
	~cArea(void);
	//accessors
	static	cArea* Instance();//FOR SINGLETONPETTERN: Method to control if there is already an Area
	const cField* getFieldptr(int z,int sp) const;//returns a pointer to a cField from the Array_ofFieldptrs through the index of the Fieldptr in the array
	void actAll();//start-button
	void setAntHill(cCreator*);//Joey: Initialisiert den Ameisenhaufen auf dem Array_ofFieldptrs - d.h. diese Methode ruft den Creator auf um ihn zu erzeugen und positioniert den Ameisenhaufen dann auf einem der Fields des Arrays. 
	void setFood(cCreator*);//Joey: Initialisiert das Essen auf dem Array_ofFieldptrs - d.h. diese Methode ruft den Creator auf um Essen zu erzeugen und positioniert dann das Essen auf dem Array.
};

#endif // !CAREA_HEADER



