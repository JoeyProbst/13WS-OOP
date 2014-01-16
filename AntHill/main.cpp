#include <iostream>
#include <list>
#include <iomanip>
#include "cArea.h"
#include "cField.h"
#include "cCreator.h"
#include "cItem.h"
#include "cPainter.h"

//using namespace std;
void wait()//Diese Funktion ist von http://www.c-plusplus.de/forum/111042-full um das Automatische Schließen der Konsole zu verhindern! 
{
    // Löscht etwaige Fehlerzustände die das Einlesen verhindern könnten
    std::cin.clear();
    // Ignoriert soviele Zeichen im Puffer wie im Puffer vorhanden sind
    // (= ignoriert alle Zeichen die derzeit im Puffer sind)
    std::cin.ignore(std::cin.rdbuf()->in_avail());
    // Füge alle eingelesenen Zeichen in den Puffer bis ein Enter gedrückt wird
    // cin.get() liefert dann das erste Zeichen aus dem Puffer zurück, welches wir aber ignorieren (interessiert uns ja nicht)
    std::cin.get();
}

void printEnvironment(cArea* environment)//Joey: Nur mal zum überprüfen! ACHTUNG: Dauert bei sehr großem Array(z.B. 300x300) seine Zeit!
{
	 //p;
	std::cout<<"Ausgeben des Arrays von Pointern \"Array_ofFieldptrs\":"<<std::endl;
	wait();
	for (int z= 0; z < LINES; z++)
	{	
		for (int sp = 0; sp < COLUMNS; sp++)
		{
			/*const*/ cField* p=environment->getFieldptr(z,sp);
			std::cout<<"["<<z<<"]["<<sp<<"] "<<p<<"	"<<p->getpNorth()<<" "<<p->getpEast()<<" "<<p->getpSouth()<<" "<<p->getpWest()<<std::endl;
			//std::cout << p <<std::endl;
		}		
		
	}
	
}

int main(int argc, char* argv[])
{
	try{ //hier hab ich die exception hergenommen, einfach nur zu überprüfrn ob die main() funktioniert.

	//Erzeugen eines Painters für die Ausgabe
	cPainter* painter=cPainter::Instance();
	//Erzeugen einer Factory "Creator"
	cCreator* factory=cCreator::Instance();
	//Erzeugen der Simulationsumgebung
	cArea* environment=cArea::Instance();
	//Ausgabe der Inizialisierten Area
	printEnvironment(environment);
	//wait();

		do
		{
			environment->notify();
			environment->actAll();
			wait();
		}while (environment->getEnvironment_ANTamount()  >0 && environment->getHill_FOODamount() >0); //Joey: läuft solange nicht das Essen innerhalb des Ameisenhügels aufgebraucht und Ameisen auf der Area sind! 
		
		//um auf jedem Field die Methode cField::actItems() aufzurufen, in welcher dann die Liste "items" durchlaufen wird
		//um von jedem Item die Methode act() aufzurufen! 
	/*}
	catch(cArea::cIndicesError())//Ich hab mich ein bisschen mit exception handling gespielt - hab aber keine Ahnung ob das so stimmt :)
	{
		std::cout<<"Die Index-Angabe fuer die Methode cArea::setAntHill() liegt NICHT innerhalb des erlaubten Wertebereichs ("<<LINES-1<<"x"<<COLUMNS-1<<"),"<<std::endl<<
			"noch wurde die Methode angewiesen per Random den Ameisenhaufen auf einem Field zu platzieren!"<<std::endl;
	}*/
	wait();
	delete environment;
	
	}
	catch(...) //hier werden alle Fehler abgefangen deshalb (...)
	{
std::cerr<<"Fehler in der main!!"<<std::endl;
	}



	return 0;

}