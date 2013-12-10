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
	class cIndicesError;//exception class
	//accessors
	static	cArea* Instance();//FOR SINGLETONPETTERN: Method to control if there is already an Area
	const cField* getFieldptr(int z,int sp) const;//returns a pointer to a cField from the Array_ofFieldptrs through the index of the Fieldptr in the array
	void actAll();//start-button
	void setAntHill(cCreator*, int z, int sp);	//Joey: Initialisiert den Ameisenhaufen auf dem Array_ofFieldptrs - d.h. diese Methode ruft den Creator auf um ihn zu erzeugen und positioniert den Ameisenhaufen dann auf einem der Fields des Arrays. 
												//setAntHill() bekommt den Creator übergeben und die Indexvariablen z und sp. Wenn dieser Index genau dem Grenzwert entspricht(also z==LINES, sp ==COLUMNS),
												//dann soll der Ameisenhaufen per random auf ein Field gesetzt werden, falls ein Index != DEN GRENZWERTEN mitgegeben wird,
												//soll der Ameisenhaufen auf dieses Field positioniert werden,
												//falls weder das eine noch das andere, gibts eine Fehlermeldung.
	void setFood(cCreator*);//Joey: Initialisiert das Essen auf dem Array_ofFieldptrs - d.h. diese Methode ruft den Creator auf um Essen zu erzeugen und positioniert dann das Essen auf dem Array.
};

#endif // !CAREA_HEADER



