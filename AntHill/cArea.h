//#pragma once
#ifndef CAREA_HEADER
#define CAREA_HEADER

#define COLUMNS 300
#define LINES 300

#include "cField.h"

class cArea
{
private:
	cField* Field_array[COLUMNS][LINES]; //Joey: Ich denke die simpelste (schöner wäre eine Vierfachverkettete Liste) Variante ist die eines Arrays von Zeigern auf Fields  
public:
	cArea(void);
	~cArea(void);
};

#endif // !CAREA_HEADER



