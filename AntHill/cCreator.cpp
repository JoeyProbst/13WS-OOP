#include "cCreator.h"

cCreator* cCreator::_instance=NULL;//needed for SingletonPattern

cCreator* cCreator::Instance()//needed for SingletonPattern
{
	if (_instance==NULL)
	{
		_instance= new cCreator();
	}
	return	_instance;
}

cCreator::cCreator(void)
{
}


cCreator::~cCreator(void)
{
}

//accessors
cItem*	cCreator::create(int selector)
{
	switch (selector)//schneller als if/else
	{
		case 1: 
			return new cFood; 
			break;
		case 2:
			return new cAnthill; 
			break;
		case 3:
			return new cAnt; 
			break;
	default: 
		return 0;
		break;
		/*
		oder:
		if(selector==FOOD) return new cFood;
		if(selector==ANT) return new cAnt;
		if(selector==ANTHILL) return new cAnthill;
		*/
	}
	//Joey: hier hätte ich mir eine switch case funktion gedacht um die einzelnen Items zu erzeugen!?
	return 0;
}