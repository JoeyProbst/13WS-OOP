//#pragma once
#ifndef CITEM_HEADER
#define CITEM_HEADER

#include <iostream>

class cItem
{
public:
	cItem(void);
	virtual ~cItem(void);//Joey: Da die Klasse Items eine rein virtuelle Basisklasse ist, muss ihr Destruktor virtual gesetzt werden, da sonst nie die Destruktoren der Kindklassen aufgerufen werden!
	int typ;//Gibt an was für eine Abgeleitete Klasse es ist: 1=Food; 2=Anthill; 3=Ant
	//accessors
	virtual void act()=0;//Da eine abstrakte, virtuelle Methode theoretisch noch aufgerufen werden kann setze ich sie hier 0 um das zu verhindern!
};

#endif // !CITEM_HEADER



