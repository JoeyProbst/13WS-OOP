//#pragma once
#ifndef CFIELD_HEADER
#define CFIELD_HEADER

#include <list>
#include "cItem.h"
#include "cCreator.h"

class cField
{
private:
	cField* pNorth;
	cField* pEast;
	cField* pSouth;
	cField* pWest;
	
	std::list<cItem*>items;//Beherbergt alle am normalen Rundenzyklus beteiligten Items
	std::list<cItem*>deadObjects;//Beherbergt die zu löschenden Objekte
	std::list<cItem*>newbornAnts;//In diese Liste werden zuerst alle neugeborenen Ameisen geladen um anschließend den ganzen ListenInhalt an die items Liste anzuhängen

public:
	cField();
	~cField(void);
	//accessors
	void setpNorth(cField*);
	void setpEast(cField*);
	void setpSouth(cField*);
	void setpWest(cField*);

	/*const*/ cField* getpNorth() /*const*/;
	/*const*/ cField* getpEast() /*const*/;
	/*const*/ cField* getpSouth() /*const*/;
	/*const*/ cField* getpWest() /*const*/;

	void adItem(cItem*);//Fügt der items Liste hinzu
	void actItems(int roundIndicator);//ruft die Methode act() eines jeden Items der items Liste auf
	void remItem(cItem*);//removed Items aus der item Liste; Wird im Moment glaube ich gar nicht benötigt
	std::list<cItem*>::iterator remByIterator(std::list<cItem*>::iterator actualIterator);//entfernt das Item mittels erase über den mitgegebenen Iterator und gibt den Iterator auf das nächste Feld zurück

	void addDeadItem(cItem*);//fügt ein zu löschendes Item der deadObject Liste hinzu!
	void clearDeadObjects();//deallociert jedes Objekt der deadobjects Liste und leert sie anschließend
	

	void addNewborn(cItem* newAnt);//Fügt eine neue Ameise der newbornAnt Liste hinzu
	void spliceNewbornToItemslist();//hängt die in newbornAnt enthaltenen Ameisen der items Liste an und cleared die newbornAnt Liste


	int getTypamount(int typ);//Joey: Man gibt den Typ von Item an und als Rückgabewert erhält man die Anzahl dieses Itemtyps auf dem jeweiligen Feld
	cItem* getFOODifTHEREis();//Holt Futter von einem Feld falls dort welches liegt und returned dieses

	/*const*/ cField* directioniter(int direction);//Methode um die Nachbarfelder durchzuiterieren
	//int getListSize();
};

#endif // !CFIELD_HEADER