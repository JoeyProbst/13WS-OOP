#include "cArea.h"
//Variable to control creation of cArea!
cArea* cArea::_instance=NULL;
//Method to control the Variable above!

cArea* cArea::Instance()
{
	if (_instance==NULL)
	{
		_instance= new	cArea();
	}
	return	_instance;
}

//Constructor initializes the m x n Array of cField* (environment of our anthill simulation)
cArea::cArea(void)
{
	FOODamount=0;
	AnthillPosition=0;

	for (int z=0; z< LINES ; z++)
	{
		for (int sp= 0; sp< COLUMNS; sp++)
		{
			Array_ofFieldptrs[z][sp]= new cField();
		}
	}

	for (int z=0; z< LINES ; z++)
	{
		for (int sp= 0; sp< COLUMNS; sp++)
		{
			if (z!=0)//linking Northptr to field above
			{
				Array_ofFieldptrs[z][sp]->setpNorth(Array_ofFieldptrs[z-1][sp]);
			}
			if(sp<COLUMNS-1)//linking Eastptr to field on the right
			{
				Array_ofFieldptrs[z][sp]->setpEast(Array_ofFieldptrs[z][sp+1]);
			}
			if(z<LINES-1)//linking Southptr to field below
			{
				Array_ofFieldptrs[z][sp]->setpSouth(Array_ofFieldptrs[z+1][sp]);
			}
			if(sp!=0)//linking Westptr to the field on the left
			{
				Array_ofFieldptrs[z][sp]->setpWest(Array_ofFieldptrs[z][sp-1]);
			}

		}
		
		
	}

	factory=cCreator::Instance();

	int sp=COLUMNS, z=LINES;
	int xhill =0;
	int yhill=0;

	Anthill = (cAnthill*) setAntHill(z, sp,xhill,yhill);
	// zum testen nur einmal food! für später mit random schleife verteilen!
	setFood(z, sp,xhill,yhill);
}


cArea::~cArea(void)
{
	for (int z=0; z< LINES ; z++)
	{
		for (int sp= 0; sp< COLUMNS; sp++)
		{
			delete Array_ofFieldptrs[z][sp];//Frage: reicht es einfach das Array zu deleten oder muss jedes Field deletet werden?
			Array_ofFieldptrs[z][sp]=NULL;
		}
	}
}

/*class cIndicesError
{

};*/

void cArea::actAll()//Joey: actAll() soll das Array_ofFieldptr durchiterieren und bei jedem Field dessen Methode actItems() aufrufen. 
{

	for (int z=0; z< LINES ; z++)
	{
		for (int sp= 0; sp< COLUMNS; sp++)
		{
			Array_ofFieldptrs[z][sp]->actItems();//Joey: Hier kommt die Fieldmethode actItems() zum Einsatz;
		}
	}


}

//---------set Methods:


cItem* cArea::setAntHill(int z, int sp, int & xhill, int & yhill )//Joey: Initialisiert den Ameisenhaufen auf dem Array_ofFieldptrs - d.h. diese Methode ruft den Creator auf um ihn zu erzeugen und positioniert den Ameisenhaufen dann auf einem der Fields des Arrays. 
{
	cItem* anthill;

	if (z ==LINES && sp ==COLUMNS )//Joey: Da die Indizes genau dem Grenzwert entsprechen wird der Ameisenhaufen per Random auf ein Field platziert.
	{
		xhill = rand()%LINES;
		yhill = rand()%COLUMNS;

		anthill=factory->create(2, Array_ofFieldptrs[xhill][yhill]);//Joey: Der Creator wird aufgerufen um einen Ameisenhaufen zu erzeugen, dabei wird dem Creator das Field auf dem der Anthill abgelegt wird, mitgegeben, damit dieser diese Info dem Construktor des Anthill geben kann	

		//Array_ofFieldptrs[xhill][yhill]->adItem(anthill);//Joey: Das Einfügen in die Liste habe ich in den Constructor des Foods verlegt!

		AnthillPosition= Array_ofFieldptrs[xhill][yhill];
	}
	else if (z < LINES && sp < COLUMNS)//Joey: Da die Indizes einen Wert aufweisen der innerhalb des gültigen Wertebereichs liegt wird der Ameisenhaufen dort platziert
	{
		xhill=z;
		yhill=sp;

		anthill=factory->create(2, Array_ofFieldptrs[xhill][yhill]);//Joey: Der Creator wird aufgerufen um einen Ameisenhaufen zu erzeugen, dabei wird dem Creator das Field auf dem der Anthill abgelegt wird, mitgegeben, damit dieser diese Info dem Construktor des Anthill geben kann	

		//Array_ofFieldptrs[z][sp]->adItem(anthill);//Joey: Das Einfügen in die Liste habe ich in den Constructor des Foods verlegt!
	}
	/*else
	{
		throw cIndicesError(); 
	}*/
	return anthill;
}

void cArea::setFood(int z, int sp, int & xhill, int & yhill )//Joey: Initialisiert das Essen auf dem Array_ofFieldptrs - d.h. diese Methode ruft den Creator auf um Essen zu erzeugen und positioniert dann das Essen auf dem Array.
{
	cItem* food;
	FOODamount++;

	if (z ==LINES && sp ==COLUMNS )//Joey: Da die Indizes genau dem Grenzwert entsprechen wird food per Random auf ein Field platziert.
	{
		int random_sp = rand()%LINES;
		int random_z = rand()%LINES;

		while(random_z == xhill && random_sp == yhill )
		{
		random_z =rand()%LINES;
		random_sp = rand()%COLUMNS;
		}
		
		//food=cCreator::Instance()->create(1,Array_ofFieldptrs[z][sp]);
		factory->create(1,Array_ofFieldptrs[random_z][random_sp]);//Joey: Das Einfügen in die Liste habe ich in den Constructor des Foods verlegt!
		//Array_ofFieldptrs[rand()%LINES][rand()%COLUMNS]->adItem(food);
	}
	else if (z < LINES && sp < COLUMNS)//Joey: Da die Indizes einen Wert aufweisen der innerhalb des gültigen Wertebereichs liegt wird der Ameisenhaufen dort platziert
	{
		//TODO: Warnung falls das Field des Anthill ausgewählt worden ist, sollte noch eingebaut werden!

		//food=cCreator::Instance()->create(1,Array_ofFieldptrs[z][sp]);
		factory->create(1,Array_ofFieldptrs[z][sp]);//Joey: Das Einfügen in die Liste habe ich in den Constructor des Foods verlegt!
		//Array_ofFieldptrs[z][sp]->adItem(food);
	}
	/*else
	{
		throw cIndicesError(); 
	}*/

}

//---------get Methods:

const cField* cArea::getFieldptr(int z,int sp) const
{
	
	return Array_ofFieldptrs[z][sp];
}


//
//int cArea::getEnvironment_ANTamount()//liefert die Anzahl der Ameisen innerhalb der Environment; dieser Wert ist im Anthill zu finden
//{
//
//}
//
int cArea::getEnvironment_FOODamount()//Teil der ABBRUCHBEDINGUNG; gibt den Wert des Futters innerhalb des Environment ABER exklusive Anthill zurück
{
	return FOODamount;

}
//
int cArea::getHill_FOODamount()//Teil der ABBRUCHBEDINGUNG; gibt nur den Wert des Futters innerhalb des Anthills zurück
{
	return Anthill->getfoodcounter();//16.12.2013 Joey: da Anthill ja eine cItem ist kann ich nicht auf die Methoden von cAnthill zugreifen - was machen wir da? 
}

cField* cArea::getAnthillPosition()
{
	return AnthillPosition;
}

void cArea::redAntcounter()
{
	Anthill->redantcounter();
}