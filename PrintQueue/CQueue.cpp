#include "CQueue.h"
#include <iostream>


//constructor ::sets .first and .last on the same CldContainer 
CQueue::CQueue(void)
{
	first= new CdlContainer();
	last=first;
	counter=0;
}

//deconstructor ::deletes allocated mem for all Containers???
CQueue::~CQueue(void)
{
}

//accessor::Adds a new list-element and assigns the given CPJob address.
void CQueue::push(CPJob *Job)
{
	//data of existing CdlContainer (see constructor of CQueue) geting Job 
	last->data=Job;
	//filled CdlContainer has to point on an empty CdlContainer as next
	last->next= new CdlContainer();
	//the empty CdlContainer has to point on the filled one as prev
	last->next->prev=last;
	//CQueues' last has to point on the empty CdlContainer
	last=last->next;
	//As CQueue got a Job in its empty CdlContainer counter increases
	counter++;
}

//accessor::Removes oldest element from the list and returns the pointer to the CPJob.
CPJob* CQueue::pop(void)
{
	if(first->next==nullptr)
	{
		std::cout<<"The Queue is already empty!"<<std::endl;
		return 0;
	}
	else
	{
		CdlContainer *help;
		help=first->next;
		CPJob *pJob= first->data;   
		//first->~CdlContainer();  // Theo: hier haut es mich immer aus dem Programm raus
		delete [] first->data;  //			Das geht aber leider auch nicht..
		first=help;
		first->prev=nullptr;
		counter--;


		return pJob;//points into nothing as ~CdlContainer called ~CJob!? 
	}
}

//accessor::Prints all elements of the list to the console.
void CQueue::printJobs(void)
{
		CdlContainer *help2;  // Theo: Du brauchst hier einen Hilfspointer sonst überschreibst du first und du bekommst den Zugriffsfehler.
		help2 = first;		
	for(int i=0;i<counter;i++)
	{
		
		std::cout<<help2->data->getText()<<help2->data->getPid()<<std::endl;
		help2=help2->next;
	}
}
