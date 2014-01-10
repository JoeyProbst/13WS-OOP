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
cItem*	cCreator::create(int selector, cField* position)//1=cFood, 2=cAnthill, 3=cAnt, 4=cPheromone
{
	switch (selector)//schneller als if/else
	{
		case 1: 
			return new cFood(position); 
			break;
		case 2:
			return new cAnthill(position); 
			break;
		case 3:
			return new cAnt(position); 
			break;
		case 4:
			return new cPheromone(position);
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

