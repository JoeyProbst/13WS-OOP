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
		}
	}

	for (int z=0; z< LINES ; z++)
	{
		for (int sp= 0; sp< COLUMNS; sp++)
		{
			if (z!=0)//linking Northptr to field above
			{
				Array_ofFieldptrs[z][sp]->setpNorth(Array_ofFieldptrs[z-1][sp]);
			}
			if(sp<COLUMNS-1)//linking Eastptr to field on the right
			{
				Array_ofFieldptrs[z][sp]->setpEast(Array_ofFieldptrs[z][sp+1]);
			}
			if(z<LINES-1)//linking Southptr to field below
			{
				Array_ofFieldptrs[z][sp]->setpSouth(Array_ofFieldptrs[z+1][sp]);
			}
			if(sp!=0)//linking Westptr to the field on the left
			{
				Array_ofFieldptrs[z][sp]->setpWest(Array_ofFieldptrs[z][sp-1]);
			}

		}
		
		
	}

}


cArea::~cArea(void)
{
	for (int z=0; z< LINES ; z++)
	{
		for (int sp= 0; sp< COLUMNS; sp++)
		{
			delete Array_ofFieldptrs[z][sp];//Frage: reicht es einfach das Array zu deleten oder muss jedes Field deletet werden?
			Array_ofFieldptrs[z][sp]=NULL;
		}
	}
}

const cField* cArea::getFieldptr(int z,int sp) const
{
	
	return Array_ofFieldptrs[z][sp];
}

void cArea::actAll()
{
	cCreator* factory=cCreator::Instance();

	cItem* food=factory->create(1);
	food->act();
	cItem* anthill=factory->create(2);
	anthill->act();
	cItem* ant=factory->create(3);
	ant->act();

}