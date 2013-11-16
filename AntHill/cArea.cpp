#include "cArea.h"
//Variable to control creation of cArea!
cArea* cArea::_instance=NULL;
//Method to control the Variable above!
cArea* cArea::Instance()
{
	if (_instance==NULL)
	{
		_instance= new	cArea();
	}
	return	_instance;
}

//Constructor initializes the m x n Array of cField* (environment of our anthill simulation)
cArea::cArea(void)
{
	for (int z=0; z< LINES ; z++)
	{
		for (int sp= 0; sp< COLUMNS; sp++)
		{
			Array_ofFieldptrs[z][sp]= new cField();
			if (z!=0)//North
			{
				Array_ofFieldptrs[z][sp]->setpNorth(Array_ofFieldptrs[z-1][sp]);
			}
			if(sp<COLUMNS-1)
			{
				Array_ofFieldptrs[z][sp]->setpEast(Array_ofFieldptrs[z][sp+1]);
			}
			if(sp<LINES-1)
			{
				Array_ofFieldptrs[z][sp]->setpSouth(Array_ofFieldptrs[z+1][sp]);
			}
			if(sp!=0)
			{
				Array_ofFieldptrs[z][sp]->setpWest(Array_ofFieldptrs[z][sp-1]);
			}

		}
		
		
	}

}


cArea::~cArea(void)
{
}

cField* cArea::getFieldptr(int z,int sp)
{
	
	return Array_ofFieldptrs[z][sp];
}
