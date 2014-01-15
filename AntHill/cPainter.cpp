#include "cPainter.h"
#include "cSubject.h"
#include "cArea.h"
#include "cField.h"
#include <iostream>

cPainter* cPainter::_instance=0;//WARUM GEHT NULL NICHT?

cPainter* cPainter::Instance()
{
	if (_instance==0)
	{
		_instance= new cPainter();
	}
	return _instance;
}

cPainter::cPainter(void):fieldcounter(0)
{
}


cPainter::~cPainter(void)
{
}

void cPainter::update(cSubject* sub)
{
	if (sub->getSubjectTyp()==1)//Die Parameter f�r die Ameisensimulation werden upgedatet
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
	 fieldcounter++;
	if (sub->getSubjectTyp()==2)//Die Felder updaten �ber ihren Status nach dem actAll()
	{
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
	}
	paintLivingEnvironment();
}

void cPainter::paintEnvironment()
{
	if (fieldcounter)
	{

	}
}

void cPainter::paintLivingEnvironment()
{

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
003	|   |   |   |   |   |   |   |   |   |   |   | F8|   |   |	
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
004	|   |   |   |   |   |   | F7|   |   |   |   |   |   |   |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
005	|   | F7|   |   |   |   |   |   |   | * | * | * |3A9|   |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
006	|   |   |   |   |   |   |   |   |   | * |   |   |   |   |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
007	|   |   |   |   | F5|   | H | * |   | * |   |   |   |   |
	+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
008	|   |   |   |   |   |   |   | * | * | * |   |   | F3|   |
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
		The number on a Field BEFORE an Letter shows its Antamount
		The number on a Field AFTER an Letter shows its  Food Amount*/

/*
Anzahl der Futterpl�tze entspricht 10% der Felder: ((LINES*COLUMNS)*100)/10;
Auf jedem Futterplatz k�nnen zwischen 3 und 30 St�ck Futter liegen;
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
*/