#include "CdlContainer.h"

//constructor ::sets NULL-pointer to next and prev, "NO DATA" to data.szText and 0 to data.IPid  
CdlContainer::CdlContainer(void)
{
	prev=nullptr;
	data= new CPJob("NO DATA",0);
	next=nullptr;


}

//deconstructor ::deletes allocated mem for data
CdlContainer::~CdlContainer(void)
{
	delete data;
	data=0;

}
