//#pragma once
#ifndef CAREA_HEADER
#define CAREA_HEADER

#define COLUMNS 3
#define LINES 3

class cField;
class cCreator;
class cItem;
class cAnthill;

#include "cSubject.h"
#include <cstdlib>//f�r die random fkt der setAntHill()

class cArea :
	public cSubject
{
private:
	cArea(const cArea&); //Standard Copy-Constructor eingebaut um den SingletonPattern abzusichern und die L�cke durch den Standard Copy-Constructor, den C++ per default erstellt, zu schlie�en
	cField* Array_ofFieldptrs[LINES][COLUMNS]; //Joey: Ich denke die beste Variante ist die eines Arrays von Zeigern auf Fields 
	static cArea* _instance;//FOR SINGLETONPETTERN: is NULL if there is no Area; is the Pointer to the Area if Area is already created
	cAnthill* Anthill;//Pointer auf AntHill um Abbruchbedingung ohne durchiterieren zu erm�glichen
	cField* AnthillPosition;//Wird dem Anthill mitgegeben, damit dieser den Ameisen ihre Startposition mitgeben kann
	int FOODamount;
	int round;//ACHTUNG: Noch NICHT �berlauf sicher!!!
protected:
	cArea(void);//FOR SINGLETONPETTERN: Constructor has to be protected for a SingletonPattern
public:
	~cArea(void);
	//class cIndicesError;//exception class
	//accessors
	static	cArea* Instance();//FOR SINGLETONPATTERN: Method to control if there is already an Area
	/*const*/ cField* getFieldptr(int z,int sp) /*const*/;//returns a pointer to a cField from the Array_ofFieldptrs through the index of the Fieldptr in the array
	void actAll();//start-button
	cItem* setAntHill(int z, int sp, int & xhill, int & yhill);	//Joey: Initialisiert den Ameisenhaufen auf dem Array_ofFieldptrs - d.h. diese Methode ruft den Creator auf um ihn zu erzeugen und positioniert den Ameisenhaufen dann auf einem der Fields des Arrays. 
												//setAntHill() bekommt den Creator �bergeben und die Indexvariablen z und sp. Wenn dieser Index genau dem Grenzwert entspricht(also z==LINES, sp ==COLUMNS),
												//dann soll der Ameisenhaufen per random auf ein Field gesetzt werden, falls ein Index != DEN GRENZWERTEN mitgegeben wird,
												//soll der Ameisenhaufen auf dieses Field positioniert werden,
												//falls weder das eine noch das andere, gibts eine Fehlermeldung.
	void setFood(int z, int sp, int & xhill, int & yhill);//Joey: Initialisiert das Essen auf dem Array_ofFieldptrs - d.h. diese Methode ruft den Creator auf um Essen zu erzeugen und positioniert dann das Essen auf dem Array.
	int getEnvironment_ANTamount();//liefert die Anzahl der Ameisen innerhalb der Environment; dieser Wert ist im Anthill zu finden
	int getEnvironment_FOODamount();//Teil der Abbruchbedingung; gibt den Wert des Futters innerhalb des Environment ABER exklusive Anthill zur�ck
	int getHill_FOODamount();//Teil der Abbruchbedingung; gibt nur den Wert des Futters innerhalb des Anthills 
	cField* getAnthillPosition();
	int getRound();//Gibt die Rundenzahl zur�ck
	cCreator* factory;
	int getAntcounter();
	int getLines();//liefert die Zeilenl�nge
	int getColumns();//liefert die Spaltenl�nge
};

#endif // !CAREA_HEADER

