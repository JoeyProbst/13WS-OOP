//#pragma once
#ifndef CQUEUE_HEADER
#define	CQUEUE_HEADER

#include "CPJob.h"
#include "CdlContainer.h"

class CQueue
{
private:
	CdlContainer *first;
	CdlContainer *last;
	int counter;
public:
	//constructor
	CQueue(void);//inits the Queue with a start Container
	
	//deconstructor
	~CQueue(void);

	//accessors
	void push(CPJob *); //Adds a new list-element and assigns the given CPJob address.
	CPJob* pop(); //Removes oldest element from the list and returns the pointer to the CPJob.
	void printJobs(); //Prints all elements of the list to the console.
};

#endif // !CQUEUE_HEADER