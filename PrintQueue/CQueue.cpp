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
	}
	else
	{
		CdlContainer *help;
		help=first->next;
		CPJob *pJob= first->data;
		first->~CdlContainer();
		first=help;
		first->prev=nullptr;
		counter--;

		return pJob;//points into nothing as ~CdlContainer called ~CJob!? 
	}
}

//accessor::Prints all elements of the list to the console.
void CQueue::printJobs(void)
{
	for(int i=0;i<counter;i++)
	{
		//Joey: Hier hab ich noch eine Zugriffsverletzung:
		//		Unbehandelte Ausnahme bei 0x012E55FD in PrintQueue.exe:
		//		0xC0000005: Zugriffsverletzung beim Lesen an Position 0x00000004
		//@Theo: Bitte anschauen!
		std::cout<<first->data->getText()<<first->data->getPid()<<std::endl;
		first=first->next;
	}
}
