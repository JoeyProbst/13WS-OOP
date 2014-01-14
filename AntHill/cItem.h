//#pragma once
#ifndef CITEM_HEADER
#define CITEM_HEADER

#include <iostream>
#include <list>

class cItem :
	public cSubject
{
public:
	cItem(void):cSubject(){};
	virtual ~cItem(void);//Joey: Da die Klasse Items eine rein virtuelle Basisklasse ist, muss ihr Destruktor virtual gesetzt werden, da sonst nie die Destruktoren der Kindklassen aufgerufen werden!
	int typ;//Gibt an was für eine Abgeleitete Klasse es ist: 1=Food; 2=Anthill; 3=Ant; 4=Pheromon
	int roundBasedTurnIndicator;//Zeigt an ob das Item schon dran war
	
	//accessors
	virtual std::list<cItem*>::iterator act(int roundIndicator, std::list<cItem*>::iterator actualIterator)=0;//Da eine abstrakte, virtuelle Methode theoretisch noch aufgerufen werden kann setze ich sie hier 0 um das zu verhindern!
};

#endif // !CITEM_HEADER



