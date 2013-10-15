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
	//Using doubly linked list!!!
	//HAS TO BE REDEFINED
	if(last->next);
	last->data=Job;
	last->next= new CdlContainer;
	counter++;
}

//accessor::Removes oldest element from the list and returns the pointer to the CPJob.
CPJob* CQueue::pop(void)
{
	if(first->next!=nullptr)
	{
		CdlContainer *help;
		help=first->next;
		delete[] first;
		first=help;
		counter--;
	}
	return 0;
}

//accessor::Prints all elements of the list to the console.
void CQueue::printJobs(void)
{
	//Be aware to stop before printing a second time (bookmark start value)
	for(int i=0;i<counter;i++)
	{
		std::cout<<first->data->szText<<first->data->IPid<<std::endl;
		first=first->next;
	}
}
