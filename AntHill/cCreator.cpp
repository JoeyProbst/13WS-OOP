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
	//Joey: hier hätte ich mir eine switch case funktion gedacht um die einzelnen Items zu erzeugen!?
	return 0;
}