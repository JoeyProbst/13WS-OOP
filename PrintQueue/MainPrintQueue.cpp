#include <iostream>
#include "CPJob.h"
#include "CQueue.h"

// fills queue with CPJob objekts

void fillQueue(CQueue *pQueue, int num)
{
	CPJob *pPJob;
	for(int i=1; i<=num; i++)//Joey: habe i auf 1 ge�ndert und daf�r die schleife bis <= laufen lassen!!! 
	{
		char *help;

		pPJob=new CPJob("text",i);
		help=pPJob->setText(pPJob->getText(),"BlaBla");  //Theo:Zweite Variable(blabla) �bergeben. Hab hier eine Zugriffsverletzung.
		std::cout<<help<<std::endl;						//help wird ausgegeben, w�rde aber besser sein wenn die wieder in die CPJob zur�ckgeschrieben wird.
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
	pQueue->pop();
	pQueue->printJobs();
	return 0;

}