#include <iostream>
#include <list>

#include "cArea.h"
#include "cField.h"
#include "cItem.h"

//using namespace std;
void wait()//Diese Funktion ist von http://www.c-plusplus.de/forum/111042-full um das Automatische Schlie�en der Konsole zu verhindern! 
{
    // L�scht etwaige Fehlerzust�nde die das Einlesen verhindern k�nnten
    std::cin.clear();
    // Ignoriert soviele Zeichen im Puffer wie im Puffer vorhanden sind
    // (= ignoriert alle Zeichen die derzeit im Puffer sind)
    std::cin.ignore(std::cin.rdbuf()->in_avail());
    // F�ge alle eingelesenen Zeichen in den Puffer bis ein Enter gedr�ckt wird
    // cin.get() liefert dann das erste Zeichen aus dem Puffer zur�ck, welches wir aber ignorieren (interessiert uns ja nicht)
    std::cin.get();
}

void printEnvironment(cArea* environment)//Joey: Nur mal zum �berpr�fen! ACHTUNG: Dauert bei sehr gro�em Array(z.B. 300x300) seine Zeit!
{
	cField* p;
	std::cout<<"Ausgeben des Arrays von Pointern \"Array_ofFieldptrs\":"<<std::endl;
	wait();
	for (int z= 0; z < LINES; z++)
	{	
		for (int sp = 0; sp < COLUMNS; sp++)
		{
			p=environment->getFieldptr(z,sp);
			std::cout<<"["<<z<<"]["<<sp<<"] "<<p<<"	"<<p->getpNorth()<<" "<<p->getpEast()<<" "<<p->getpSouth()<<" "<<p->getpWest()<<std::endl;
			//std::cout << p <<std::endl;
		}		
		
	}
	
}

int main(int argc, char* argv[])
{
	cArea* environment=cArea::Instance();
	printEnvironment(environment);
	wait();
	delete environment;
	return 0;
}