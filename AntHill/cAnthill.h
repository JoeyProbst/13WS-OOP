//#pragma once
#ifndef CANTHILL_HEADER
#define	CANTHILL_HEADER

#include "cItem.h"

class cAnthill :
	public cItem
{
public:
	cAnthill(void);
	~cAnthill(void);
	//accessors
	void act() override;
	//void setAnt(cCreator*);//Joey: Diese Methode ruft den Creator auf um eine Ameise zu erzeugen und setzt diese dann in der Array_ofFieldptrs auf das Field des AntHill.
};

#endif // !CANTHILL_HEADER


