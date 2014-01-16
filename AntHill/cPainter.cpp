#include "cPainter.h"
#include "cSubject.h"
#include "cArea.h"
#include "cField.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>

cPainter* cPainter::_instance=0;//WARUM GEHT NULL NICHT?

cPainter* cPainter::Instance()
{
	if (_instance==0)
	{
		_instance= new cPainter();
	}
	return _instance;
}

cPainter::cPainter(void):fieldcounter(0),multiplier(0),indexLines(0)
{
}


cPainter::~cPainter(void)
{
}

void cPainter::update(cSubject* sub)
{
	//cArea* ptr;
	if (/*ptr= dynamic_cast<cArea*>(sub))*/sub->getSubjectTyp()==1)//Die Parameter f�r die Ameisensimulation werden upgedatet
	{
		round=(*(cArea*)sub).getRound();
		lines=(*(cArea*)sub).getLines();
		columns=(*(cArea*)sub).getColumns();
		paintEnvironment();
	}

	 antcounter= 0;
	 foodcounter= 0;
	 anthill= 0;
	 pheromonecounter= 0;
	if (sub->getSubjectTyp()==2)//Die Felder updaten �ber ihren Status nach dem actAll()
	{
		fieldcounter++;

		for (int i = 1; i <= 4; i++)
		{
			int counter=0;

			if(counter= (*(cField*)sub).getTypamount(i)>0)//1=Food; 2=Anthill; 3=Ant; 4=Pheromon
			{
				if (i==3)//Ameise
				{
					antcounter=counter;
				}
				if (i==1)//Futter
				{
					foodcounter=counter;
				}
				if (i==2)//Ameisenh�gel
				{
					anthill=counter;
				}
				if (i==4)//Pheromon
				{
					pheromonecounter=counter;
				}
			}
		}

		paintLivingEnvironment();
	}
	
	if (fieldcounter==(lines*columns))
	{
		fieldcounter=0;
		multiplier=0;
		paintLegende();
		indexLines=0;
		
		//system("cls");
		//Sleep(1000);//in millisek
	}
}

void cPainter::paintEnvironment()//Zeichnet eine leere Umgebung
{
	paintIndexColumns();
	for (int i = 0; i < lines; i++)
	{
		paintHorizontalRaster();
		paintIndexLines();
		paintEmptyStartFields();	
	}
	paintHorizontalRaster();
	paintLegende();
	indexLines=0;
}

void cPainter::paintLivingEnvironment()
{
		if(fieldcounter==1)//Die Indize der Spalten werden vor dem zeichnen des ersten fields ausgegeben
		{
			paintIndexColumns();
		}
		if (fieldcounter==((columns*multiplier)+1))
		{
			paintHorizontalRaster();
			paintIndexLines();
			multiplier++;
		}
		paintInteriorField();
		if (fieldcounter==(lines*columns))
		{
			paintHorizontalRaster();
		}
		
}

void cPainter::paintIndexColumns()
{
	std::cout<<"	";
	for (int i = 0; i < columns; i++)
	{
		std::cout<<" "<<std::setfill('0')<<std::setw(3)<<i;
		//std::cout<<" "<<std::printf("%02i",i);
	}
	std::cout<<std::endl;
	
}

void cPainter::paintHorizontalRaster()
{
	std::cout<<"	";

	for (int i = 0; i < columns; i++)
	{
		std::cout<<"+---";
	}

	std::cout<<"+"<<std::endl;
}

void cPainter::paintIndexLines()
{
	std::cout<<"   ";
	std::cout<<" "<<std::setfill('0')<<std::setw(3)<<indexLines;
	//std::cout<<printf("%02i",indexLines);
	indexLines++;
	std::cout<<" ";
}

void cPainter::paintInteriorField()
{
	std::cout<<"|";
	if (antcounter)//Es sind Ameisen auf dem Feld!
	{
		if (antcounter<10)
		{
			std::cout<<antcounter;
		}
		else//Falls �ber neun Ameisen auf einem Feld, dann wird nur noch # ausgegeben
		{
			std::cout<<"#";
		}
		if (anthill)//Ist dort auch der Ameisenh�gel
		{
			std::cout<<"H";
		}
		else if(pheromonecounter)//oder ist dort Pheromon
		{
			std::cout<<"*";
		}
		else if (foodcounter && anthill==0)//oder ist dort Futter, aber ohne den Ameisenh�gel
		{
			std::cout<<"F";
		}
		else//Anscheinend ist dort au�er Ameisen nichts
		{
			std::cout<<"A ";
		}
	}
	else//Es sind keine Ameisen auf dem Feld!
	{
		std::cout<<" ";

		if (anthill)
		{
			std::cout<<"H";
		}
		else if(pheromonecounter)//oder ist dort Pheromon
		{
			std::cout<<"*";
		}
		else if (foodcounter && anthill==0)//oder ist dort Futter, aber ohne den Ameisenh�gel
		{
			std::cout<<"F";
		}
		else//Anscheinend ist hier nichts
		{
			std::cout<<"  ";
		}
	}
	if (foodcounter)//Es ist Futter auf diesem Feld
	{
		if(foodcounter<10)
		{
			std::cout<<foodcounter;
		}
		else//Auf diesem Feld liegt eine FutterMenge �ber 9
		{
			std::cout<<"#";
		}
	}
	else if (pheromonecounter)
	{
		if (pheromonecounter<10)
		{
			std::cout<<pheromonecounter;
		}
		else//Es liegt mehr als 9 Pheromon auf diesem Feld
		{
			std::cout<<"#";
		}
	}
	
	if (fieldcounter==(columns*multiplier))
	{
		std::cout<<"|";
		std::cout<<std::endl;
	}
}

void cPainter::paintEmptyStartFields()
{
	for (int i = 0; i < columns; i++)
	{
		std::cout<<"|   ";

	}
	std::cout<<"|"<<std::endl;

}

void cPainter::paintLegende()
{
	std::cout<<std::endl<<"Legende: A...Ant; *... Pheromone; H...Hill of the Ants; F...Food;"<<std::endl
		<<std::endl<<"Syntax:"<<std::endl<<std::endl 
		<<"\t"<<"-The number on a Field BEFORE an letter shows its Ant amount"<<std::endl
		<<"\t"<<"-The number on a Field AFTER an letter shows its  Food amount"<<std::endl
		<<"\t"<<"-The number on a Field AFTER an * shows its Pheromone amount"<<std::endl
		<<"\t"<<"-The # symbol stands for a number higher then ten"<<std::endl;
}
/*
	
+-----------+
|Food	  0	|
|Hill	  1	|
|Ant	  4	|
|Pheromon 2	|
+-----------+

/*
Ausprogrammieren der Ausgabe:
Ausgabe und Men� in jeweils eigene Methoden der Area (eventuell beides in sp�terer Folge in eine eigene Ausgabe-Klasse):
Jede Ausgabe wird 5Sekunden angezeigt!
Ausgabe:
//erste zeile
std:cout<<"/t "<<

#include <cstdlib>
#include <windows.h>
system("cls");
Sleep(1000);//in millisek

Men�:


/*

/* Visualisierung der Environment:

Round: 3

	 000 001 002 003 004 005 006 007 008 009 010 011 012 013
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
001	|   |   |   |   |   |   |   | F6|   |   |   |   |   |   |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
002	|   |   |   | F3|   |   |   |   |   |   |   |   |   |   |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
003	|   |   |   |   |   |   |   |   |   |   |   |8F |   |   |	
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
004	|   |   |   |   |   |   | F7|   |   |   |   |   |   |   |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
005	|   | F7|   |   |   |   |   |   |   | * | * | * |3F9|   |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
006	|   |   |   |   |   |   |   |   |   | * |   |   |   |   |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
007	|   |   |   |   | F5|   | H | * |   | * |   |   |   |   |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
008	|   |   |   |   |   |   |   | * |4*2|3*2|   |   | F3|   |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
009	|   |   |   | F9|   |   |   |   |   |   |   |   |   |   |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
010	|   |   |   |   |   |   |   |   | F8|   |   |   |   |   |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
011	|   |   |   |   | F6|   |   |   |   |   |   |   |   |   |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
012	|   |   |   |   |   |   |   |   |   |   |   | F5|   |   |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+

Legende: A...Ant; *... Pheromone; H...Anthill; F...Food; B...Barrier;
Syntax: 
		-The number on a Field BEFORE an letter shows its Ant amount
		-The number on a Field AFTER an letter shows its  Food amount
		-The number on a Field AFTER an * shows its Food amount
		-The # symbol stands for a number higher then ten */

/*
Anzahl der Futterpl�tze entspricht 10% der Felder: ((LINES*COLUMNS)*100)/10;
Auf jedem Futterplatz k�nnen zwischen 3 und 30 St�ck Futter liegen;

Parameter�bergabe und Kontrolle der Environment: SCH�N W�RS!!!
Nach jeder "Visualisierung der Environment" kann man Anweisungen durchf�hren:
- mit "get" bekommt man Informationen: 
	"get z sp" liefert einem alle Infos �ber das Feld mit Zeilennr. z und Spaltennr. sp
	"get ttl" liefert einem wie viel Essen im Ameisenhaufen liegt und wie viele Ameisen gerade leben
- mit "?" bekommt man Hilfe:
	"?" liefert die komplette Anweisungsliste
	"get ?" liefert alle Anweisungen die Informationen erfragen
	"set ?" liefert alle Anweisungen die Einstellungen verstellen
- mit "set" verstellt man Einstellungen:
	"set ttl-" Fragt einen, auf wie viel man das Futter und die Ameisen reduzieren m�chte
	"set ttl+" Fragt einen, auf wie viel man das Futter und die Ameisen erh�hen m�chte
	"set z sp" fragt einen was (Ameise, Futter, oder Barriere) man auf das Feld mit Zeilennr. z und Spaltennr. sp setzen m�chte
- mit "kill" l�scht man Items:
	"kill ant" fragt einen nach den Koordinaten der Ameise welche man t�ten m�chte
	"kill food" fragt einen nach den Koordinaten des Futters welches man aufl�sen m�chte
	"kill barrier" fragt einen nach den Koordinaten der Barriere welche man zerst�ren m�chte
	"kill pheromons" fragt einen nach den Koordinaten der Pheromone welche man l�schen m�chte
- mit "undo" springt man wieder aus einer Anweisung
- mit einem einfachen Enter leitet man die n�chste Runde ein! 
*/
