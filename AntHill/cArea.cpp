#include "cArea.h"

//Constructor initializes the m x n Array of cField* (environment of our anthill simulation)
cArea::cArea(void)
{
	
	Array_ofFieldptrs;
	cField **pEnvironment=&(Array_ofFieldptrs[0][0]);//Joey: pEnvironment ist ein pointer auf das Array von Fields, "Array_ofFieldptrs"! 
	for (int i = LINES*COLUMNS; i > 0; i--)//Joey: mit 0 vergleichen da schneller!
	{
		*pEnvironment++=NULL;
	}
}


cArea::~cArea(void)
{
}

cField* cArea::getFieldptr(int z,int sp)
{
	
	return Array_ofFieldptrs[z][sp];
}
