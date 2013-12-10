#include "cAnthill.h"


cAnthill::cAnthill(void)
{
}


cAnthill::~cAnthill(void)
{
}

//accessors
void cAnthill::act()
{
	std::cout<<"Ich bin ein Ameisenhaufen!"<<std::endl;
}
/*
void setAnt(cCreator* factory)//Joey: Diese Methode ruft den Creator auf um eine Ameise zu erzeugen und setzt diese dann in der Array_ofFieldptrs auf das Field des AntHill.
{
	cItem* ant=factory->create(3);
}
*/