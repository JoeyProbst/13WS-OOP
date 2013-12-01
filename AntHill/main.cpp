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
	 //p;
	std::cout<<"Ausgeben des Arrays von Pointern \"Array_ofFieldptrs\":"<<std::endl;
	wait();
	for (int z= 0; z < LINES; z++)
	{	
		for (int sp = 0; sp < COLUMNS; sp++)
		{
			const cField* p=environment->getFieldptr(z,sp);
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
	
	//Erzeugen einer Factory "Creator"
	cCreator* factory=cCreator::Instance();
	
	//Aufruf der factory method durch zb Area, Anthill, etc. ANFANG 
	cItem* food=factory->create(1);	
	cItem* anthill=factory->create(2);	
	cItem* ant=factory->create(3);
	//Aufruf der factory method durch zb Area, Anthill, etc. ENDE

	//Einf�llen der neuen Items in die Liste "items" ANFANG 
	environment->getFieldptr(0,0)->adItem(food);// kann nicht verwendet werden da ihr R�ckgabewert const ist um das Rumpfuschen nicht zu erlauben!
	environment->Array_ofFieldptrs[0][0]->adItem(food);//Wir k�nnen nicht direkt auf das Array zugreifen, da es, um es zu sch�tzen, ja private gesetzt ist! 
		//D.h um es zu testen k�nnten wir die getFieldptr() Methode verwenden (wenn wir den R�ckgabewert nicht mehr const setzen), 
		//ABER sp�ter m�ssen wir sowieso das Einf�llen in die Listen dorthin verschieben,
		//wo auch der Creator aufgerufen wird und in dieser ausf�hren. Was meinst?
	
	//Einf�llen der neuen Items in die Liste "items" ENDE

	//Durchiterieren der Area mittels cArea::actAll(), 
	environment->actAll();
	//um auf jedem Field die Methode cField::actItems() aufzurufen, in welcher dann die Liste "items" durchlaufen wird
	//um von jedem Item die Methode act() aufzurufen! 
	
	wait();
	delete environment;
	return 0;
}