//#pragma once
#ifndef CCREATOR_HEADER
#define CCREATOR_HEADER


#include "cFood.h"
#include "cAnthill.h"
#include "cAnt.h"


#define ANT 3
#define ANTHILL 2
#define FOOD 1

class cCreator
{
private:
	static cCreator* _instance;//needed for SingletonPattern
	cCreator(const	cCreator&);//Standard-Copy-Constructor important for a secure SingletonPattern
protected:
	cCreator(void);//Constructor has to be protected for SingletonPattern
public:
	~cCreator(void);
	//accessors
	static cCreator* Instance();//needed for SingletonPattern
	cItem* create(int selector);//Methode to create Anthills, Food, Ants, etc. ; in the selector integer is the information what should be created
};

#endif // !CCREATOR_HEADER


