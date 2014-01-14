#include "cAnt.h"
#include "cArea.h"
#include "cItem.h"
#include <typeinfo>


cAnt::cAnt(cField* position):ActualPosition(position),typ(3),TTL((LINES+COLUMNS+(LINES+COLUMNS)/2)*3),roundBasedTurnIndicator(0),Fund(NULL)//,Lunchbox(100)//Joey: Lunchbox muss noch ausgearbeitet werden!
{
	//Fund=0;
	state = true; //true = Futtersuche/ false = on my way home
	ActualPosition->addNewborn(this);
	carrymehomelist.push_front(ActualPosition);
//	Lunchbox=100;
	
}


cAnt::~cAnt(void)
{
//ActualPosition->remItem(this);//Ameise aus ItemListe des aktuellen Fields herauslöschen
if(Fund)//eventuell transportiertes Futter an aktuelles Feld abgeben
{
ActualPosition->adItem(Fund);
Fund=NULL;
}
 //cCreator::Instance()->create(1, ActualPosition);//und ein neues cFood für die gefallene Ameise entstehen lassen //Ameise kann ohne Lanchbox nicht zum Futter werden, da die ganze Simulation sonst zur Endlosschleife wird!
//reduceAntcounter;//TODO: Ausstehendes reduceAntcounter muss ausprogrammiert werden!	
}

//accessors
std::list<cItem*>::iterator cAnt::act(int roundIndicator, std::list<cItem*>::iterator actualIterator)
{

	std::list<cItem*>::iterator newIterator;

	if(roundIndicator!=roundBasedTurnIndicator)
	{
		if(TTL==0)// || Lunchbox==0)//kill! Für Ameise aus ItemListe des aktuellen Fields herauszulöschen, eventuell transportiertes Futter an aktuelles Feld abzugeben und ein neues cFood für die gefallene Ameise entstehen zu lassen  SIEHE DESTRUCTOR
		{
			//delete this;
			ActualPosition->addDeadItem(this);
			return ActualPosition->remByIterator(actualIterator);
		}
		else //THE SHOW MUST GO ON! Proviantstatus -- und Lebensstatus --
		{
			//Lunchbox--;//Joey: Der Umgang mit der Lunchbox ist noch nicht zu ende gedacht!!!
			TTL--;
		
			if (state)//Auf Futtersuche!
			{
				 newIterator=search(actualIterator);//Wegentscheidung
				take();//Futter aufnehmen, falls vorhanden
			}
			else
			{
				newIterator=gohome(actualIterator);//Mit bereits gefundenem Futter nach Hause gehen
				giveback();//Legt Pheromon ab oder das gefundene Futter falls am aktuellen Feld der Ameisenhügel liegt
			}
		}
		roundBasedTurnIndicator=roundIndicator;
		return newIterator;
	}
}


std::list<cItem*>::iterator cAnt::search(std::list<cItem*>::iterator actualIterator)//Auf der Suche nach Futter
{
	/*const*/ cField* choice=NULL;
	std::list</*const*/ cField*>options;
	options.push_front(choice);

	choice=ActualPosition->getpNorth();

	for (int i = 2; i <= 4; i++)
	{
		/*const*/ cField* current=ActualPosition->directioniter(i);

		int result =compare(choice, current);
		if (result==-1)//current schlägt choice
		{
			choice=current;
			options.erase(options.begin(), options.end());
			options.push_front(current);
		}
		if (result==0)//choice und current sind gleich
		{
			options.push_front(current);
		}
		
	}

	//Entscheidung ist gefallen:
	int counter=rand()%options.size();//legt das neue Feld per Random fest; Falls nicht mehrere Felder in der optionsListe dann wird das erste Element genommen, welches dann sowieso der besten Wahl entspricht! 
	for(int i=1; i<counter; i++)
	{
		options.pop_front();
	}

	std::list<cItem*>::iterator newIterator =ActualPosition->remByIterator(actualIterator);//Die Ameise wird aus der Liste des Aktuellen Feldes herausgenommen unter zuhilfenahme des Iterators
	//ActualPosition->remItem(this);//Die Ameise wird aus der Liste des Aktuellen Feldes herausgenommen
	ActualPosition = options.front();//die Wahl des nächsten Feldes wird in die ActualPosition geschrieben
	carrymehomelist.push_back(ActualPosition);//Die neue Actual Position wird in der carrymehomeListe hinten angehängt
	ActualPosition->adItem(this);//Die Ameise wird auf dem neuen Feld in die ItemsListe eingetragen

	return newIterator;
}

int cAnt::compare(/*const*/ cField* choice, /*const*/ cField* current)
{
	if (carrymehomelist.back()==choice)//choice entspricht dem letzten besuchten Feld
	{
		return -1; //choice ist falsch
	}
	if (carrymehomelist.back()==current)//current entspricht dem letzten besuchten Feld
	{
		return 1;//current ist falsch
	}

	//Die Überprüfung auf den Ameisenhaufen würde ich sagen lassen wir weg: Das ist eher Zusatz - ohne funktionierts auch; wir müssen halt beim cAnt::take() dann überprüfen auf den Hügel

	if (choice->getTypamount(1) >0 && current->getTypamount(1) >0)//Auf choice UND current liegt Futter
	{
		return 0;
	}
	if (choice->getTypamount(1) >0 && current->getTypamount(1) ==0)//Es liegt nur auf choice Futter
	{
		return 1;
	}
	if (choice->getTypamount(1) ==0 && current->getTypamount(1) >0)//Es liegt nur auf current Futter
	{
		return -1;
	}

	//Es liegt nirgends Futter ergo ich bin auf der Suche nach Pheromon!

	if(choice->getTypamount(4) == current->getTypamount(4))//Auf choice und current liegt gleich viel Pheromon
	{
		return 0;
	}

	if (choice->getTypamount(4) > current->getTypamount(4))//Auf choice liegt mehr Pheromon als auf current
	{
		return 1;
	}

	if(choice->getTypamount(4) < current->getTypamount(4))//Auf current liegt mehr Pheromon als auf current
	{
		return -1;
	}

	return 0;//beide, current und choice, sind mögliche nächste Felder
}

void cAnt::take()//Futter aufnehmen
{
	if(ActualPosition->getTypamount(2)==0)//ist dort wo ich bin NICHT der Ameisenhügel?
	{
		if (ActualPosition->getTypamount(1)>0)//Liegt hier Futter?
		{
			Fund=ActualPosition->getFOODifTHEREis();//Futter nehmen!
		}
		
	}
}

std::list<cItem*>::iterator cAnt::gohome(std::list<cItem*>::iterator actualIterator)//Mit gefundenem Futter nach Hause gehen
{
	std::list<cItem*>::iterator newIterator =ActualPosition->remByIterator(actualIterator);//Die Ameise wird aus der Liste des Aktuellen Feldes herausgenommen unter zuhilfenahme des Iterators
	//ActualPosition->remItem(this);//Ameise wird vom aktuellen Feld aus dessen Liste genommen!
	carrymehomelist.pop_back();//das letzte Element in der carrymehomelist wird herausgenommen!
	ActualPosition= carrymehomelist.back();//das nächste letzte Element wird zur ActualPosition!
	ActualPosition->adItem(this);//auf dem neuen Feld wird die Ameise in die Liste eingetragen!

	return newIterator;
}

void cAnt::giveback()
{
				if (ActualPosition->getTypamount(2)==1)//Steht die Ameise schon auf dem Ameisenhügel?
				{
					ActualPosition->addFoodToHillList(Fund);
					Fund=NULL;
				}
				else//Pheromon wird abgelegt!
				{
					cCreator* factory=cCreator::Instance();
					factory->create(4, ActualPosition);
				}
}