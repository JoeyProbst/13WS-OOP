#include <iostream>
#include "CPJob.h"
#include "CQueue.h"

// fills queue with CPJob objekts

void fillQueue(CQueue *pQueue, int num)
{
	CPJob *pPJob;
	for(int i=1; i<=num; i++)//Joey: habe i auf 1 geändert und dafür die schleife bis <= laufen lassen!!! 
	{
		pPJob=new CPJob("text",i);						
		pQueue -> push(pPJob);						
	}
}
// driver: simple testing
int main(int argc, char* argv[])
{
	CQueue *pQueue;
	pQueue= new CQueue();
	fillQueue (pQueue,3);//generates three CPJobs and integrates them one after another, each in a separate CdlContainer (by accessor push()) 
	pQueue->printJobs();
	delete pQueue->pop(); //deleting from pop returned Job as this one isn't in the Queue anymore
	pQueue->printJobs();

	//clear Queue
	delete pQueue;
	pQueue=0;

	return 0;

}