#include <iostream>
#include <list>

#include "cArea.h"
#include "cField.h"
#include "cItem.h"

//using namespace std;

void printEnvironment(cArea environment)//Joey: Nur mal zum überprüfen! ACHTUNG: sehr großes Array(300x300), kann seine Zeit dauern!
{
	std::cout<<"Ausgeben des Arrays von Pointern \"Array_ofFieldptrs\":"<<std::endl;
	
	for (int z= 0; z < LINES; z++)
	{	
		for (int sp = 0; sp < COLUMNS; sp++)
		{
			std::cout<<"["<<z<<"]["<<sp<<"] "<<environment.getFieldptr(z,sp) <<std::endl;
		}		
		
	}
	
}

int main(int argc, char* argv[])
{
	cArea environment;
	printEnvironment(environment);
	return 0;
}