//#pragma once
#ifndef CAREA_HEADER
#define CAREA_HEADER

#define COLUMNS 10
#define LINES 10

#include "cField.h"

#include <cstdlib>//für die random fkt der setAntHill()

class cArea
{
private:
	cArea(const cArea&); //Standard Copy-Constructor eingebaut um den SingletonPattern abzusichern und die Lücke durch den Standard Copy-Constructor, den C++ per default erstellt, zu schließen
	cField* Array_ofFieldptrs[LINES][COLUMNS]; //Joey: Ich denke die beste Variante ist die eines Arrays von Zeigern auf Fields 
	static cArea* _instance;//FOR SINGLETONPETTERN: is NULL if there is no Area; is the Pointer to the Area if Area is already created
	cAnthill* Anthill;//Pointer auf AntHill um Abbruchbedingung ohne durchiterieren zu ermöglichen
	cField* AnthillPosition;//Wird dem Anthill mitgegeben, damit dieser den Ameisen ihre Startposition mitgeben kann
	int FOODamount;
protected:
	cArea(void);//FOR SINGLETONPETTERN: Constructor has to be protected for a SingletonPattern
public:
	~cArea(void);
	//class cIndicesError;//exception class
	//accessors
	static	cArea* Instance();//FOR SINGLETONPATTERN: Method to control if there is already an Area
	const cField* getFieldptr(int z,int sp) const;//returns a pointer to a cField from the Array_ofFieldptrs through the index of the Fieldptr in the array
	void actAll();//start-button
	cItem* setAntHill(int z, int sp, int & xhill, int & yhill);	//Joey: Initialisiert den Ameisenhaufen auf dem Array_ofFieldptrs - d.h. diese Methode ruft den Creator auf um ihn zu erzeugen und positioniert den Ameisenhaufen dann auf einem der Fields des Arrays. 
												//setAntHill() bekommt den Creator übergeben und die Indexvariablen z und sp. Wenn dieser Index genau dem Grenzwert entspricht(also z==LINES, sp ==COLUMNS),
												//dann soll der Ameisenhaufen per random auf ein Field gesetzt werden, falls ein Index != DEN GRENZWERTEN mitgegeben wird,
												//soll der Ameisenhaufen auf dieses Field positioniert werden,
												//falls weder das eine noch das andere, gibts eine Fehlermeldung.
	void setFood(int z, int sp, int & xhill, int & yhill);//Joey: Initialisiert das Essen auf dem Array_ofFieldptrs - d.h. diese Methode ruft den Creator auf um Essen zu erzeugen und positioniert dann das Essen auf dem Array.
	int getEnvironment_ANTamount();//liefert die Anzahl der Ameisen innerhalb der Environment; dieser Wert ist im Anthill zu finden
	int getEnvironment_FOODamount();//Teil der Abbruchbedingung; gibt den Wert des Futters innerhalb des Environment ABER exklusive Anthill zurück
	int getHill_FOODamount();//Teil der Abbruchbedingung; gibt nur den Wert des Futters innerhalb des Anthills 
	cField* getAnthillPosition();

	cCreator* factory;
};

#endif // !CAREA_HEADER

/*
Ausprogrammieren der Ausgabe:
Ausgabe und Menü in jeweils eigene Methoden der Area (eventuell beides in späterer Folge in eine eigene Ausgabe-Klasse):
Jede Ausgabe wird 5Sekunden angezeigt!
Ausgabe:
//erste zeile
std:cout<<"/t "<<

#include <cstdlib>
#include <windows.h>
system("cls");
Sleep(1000);//in millisek

Menü:


/*

/* Visualisierung der Environment:

Round: 3

	 000 001 002 003 004 005 006 007 008 009 010 011 012 013
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
001	|   |   |   |   |   |   |   | F6|   |   |   |   |   |   |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
002	|   |   |   | F3|   |   |   |   |   |   |   |   |   |   |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
003	|   |   |   |   |   |   |   |   |   |   |   | F8|   |   |	
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
004	|   |   |   |   |   |   | F7|   |   |   |   |   |   |   |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
005	|   | F7|   |   |   |   |   |   |   | * | * | * |3A9|   |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
006	|   |   |   |   |   |   |   |   |   | * |   |   |   |   |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
007	|   |   |   |   | F5|   | H | * |   | * |   |   |   |   |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
008	|   |   |   |   |   |   |   | * | * | * |   |   | F3|   |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
009	|   |   |   | F9|   |   |   |   |   |   |   |   |   |   |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
010	|   |   |   |   |   |   |   |   | F8|   |   |   |   |   |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
011	|   |   |   |   | F6|   |   |   |   |   |   |   |   |   |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
012	|   |   |   |   |   |   |   |   |   |   |   | F5|   |   |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+

Legende: A...Ant; *... Pheromone; H...Anthill; F...Food; B...Barrier;*/

/*
Anzahl der Futterplätze entspricht 10% der Felder: ((LINES*COLUMNS)*100)/10;
Auf jedem Futterplatz können zwischen 3 und 30 Stück Futter liegen;
Nach jeder "Visualisierung der Environment" kann man Anweisungen durchführen:
- mit "get" bekommt man Informationen: 
	"get z sp" liefert einem alle Infos über das Feld mit Zeilennr. z und Spaltennr. sp
	"get ttl" liefert einem wie viel Essen im Ameisenhaufen liegt und wie viele Ameisen gerade leben
- mit "?" bekommt man Hilfe:
	"?" liefert die komplette Anweisungsliste
	"get ?" liefert alle Anweisungen die Informationen erfragen
	"set ?" liefert alle Anweisungen die Einstellungen verstellen
- mit "set" verstellt man Einstellungen:
	"set ttl-" Fragt einen, auf wie viel man das Futter und die Ameisen reduzieren möchte
	"set ttl+" Fragt einen, auf wie viel man das Futter und die Ameisen erhöhen möchte
	"set z sp" fragt einen was (Ameise, Futter, oder Barriere) man auf das Feld mit Zeilennr. z und Spaltennr. sp setzen möchte
- mit "kill" löscht man Items:
	"kill ant" fragt einen nach den Koordinaten der Ameise welche man töten möchte
	"kill food" fragt einen nach den Koordinaten des Futters welches man auflösen möchte
	"kill barrier" fragt einen nach den Koordinaten der Barriere welche man zerstören möchte
	"kill pheromons" fragt einen nach den Koordinaten der Pheromone welche man löschen möchte
- mit "undo" springt man wieder aus einer Anweisung
- mit einem einfachen Enter leitet man die nächste Runde ein! 
*/