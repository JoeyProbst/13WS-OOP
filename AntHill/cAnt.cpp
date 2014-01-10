#include "cAnt.h"
#include "cArea.h"
#include "cItem.h"

#include <typeinfo>


cAnt::cAnt(cField* position):ActualPosition(position),typ(3),TTL((LINES+COLUMNS+(LINES+COLUMNS)/2)*3),Lunchbox(0)//Joey: Lunchbox muss noch ausgearbeitet werden!
{
	Fund=0;
	Status = true; //true = Futtersuche/ false = Way Home
	ActualPosition->adItem(this);
	carrymehomelist.push_front(ActualPosition);
}


cAnt::~cAnt(void)
{
ActualPosition->remItem(this);//Ameise aus ItemListe des aktuellen Fields herauslöschen
if(Fund)//eventuell transportiertes Futter an aktuelles Feld abgeben
{
ActualPosition->adItem(Fund);
Fund=NULL;
}
 cCreator::Instance()->create(1, ActualPosition);//und ein neues cFood für die gefallene Ameise entstehen lassen
//reduceAntcounter;//TODO: Ausstehendes reduceAntcounter muss ausprogrammiert werden!	
}

//accessors
void cAnt::act()
{
	//std::cout<<"SIR. Ich bin eine Ameise!, SIR."<<std::endl; 
	
	//PART 1:
		//Was ist mein Lebensstatus und Proviantstatus?
		//wenn Lebensstatus oder Proviant aufgebraucht 
			//kill und Futter an aktuelles Feld abgeben und ein neues cFood entsteht für die gefallene Ameise sonst
		//Proviantstatus -- und Lebensstatus --
	if(TTL==0 || Lunchbox==0)//kill! Für Ameise aus ItemListe des aktuellen Fields herauszulöschen, eventuell transportiertes Futter an aktuelles Feld abzugeben und ein neues cFood für die gefallene Ameise entstehen zu lassen  SIEHE DESTRUCTOR
	{
		delete this;
	}
	else //THE SHOW MUST GO ON! Proviantstatus -- und Lebensstatus --
	{
		Lunchbox--,//Joey: Der Umgang mit der Lunchbox ist noch nicht zu ende gedacht!!!
			TTL--;
	}

	//PART 2:
		//Futtersuche oder am Heimweg?
		//Wenn auf Futtersuche, dann 
				//ist auf meinem Feld der Ameisenhügel? wenn ja, dann was ist sonst um mich herum?
				//Ist Futter auf meinem Feld? 
					//wenn Futter, dann Futter aufnehmen und Status auf Home! 
					//sonst Was ist um mich herum?
						//wenn Futter, dann
							//wenn dort auch der Ameisenhügel, dann dieses Feld ausschließen
							//sonst dorthin gehen
						//wenn Pheromon, dann dorthin gehen
						//sonst Random nach LROU (falls Anthill, hier mit Parameter mitgeben auf welchem der Felder (north=1, east=2, south=3 west=4), um es auszuschließen) 

	if(Status) //Futtersuche
	{
		if(!ActualPosition->getTypamount(2))//Ist auf meinem aktuellen Feld der Anthill? - NOPE, dann
		{
			if(Fund=ActualPosition->getFOODifTHEREis())//Ist Futter auf meinem Aktuellen Feld? - Yes, dann mitnehmen und
			{
				Status=0;//Status auf "zurück nach Hause" gesetzt!
			}
			else//Was ist sonst um mich herum
			{
				if(!ActualPosition->getpNorth.getTypamount(2))//Ist im Norden der Ameisenhügel? - Nope, dann
				{
					if(!ActualPosition->getpNorth.getTypamount(1))//Ist dort Futter? - Nope, dann
					{
						if(!ActualPosition->getpNorth.getTypamount(4))//Ist dort Pheromon? - Nope, dann
						{

						}
					}
				}
			}
		}
	}
	if(Status)
	{
		//Futter=333; Pheromon= >0 && <101; Nichts= 0; Anthill=222;
		ActualPosition = Whatsnext();
		carrymehomelist.push_back(ActualPosition);
	}

	//Futtersuche oder am Heimweg?
		//Wenn am Heimweg, dann 
			//bin ich schon zuHause? 
				//wenn ja, dann Futter abgeben Proviant aufnehemen und Status auf Futtersuche!
			//sonst Pheromon legen  
			//Homelist abarbeiten!


	else //Weg heim
	{
		ActualPosition->remItem(this);
		ActualPosition= carrymehomelist.back();
		carrymehomelist.pop_back();
	}


}


//act der Ameise:

//Was ist mein Lebensstatus und Proviantstatus?
	//wenn Lebensstatus oder Proviant aufgebraucht 
		//kill
		// Futter an aktuelles Feld abgeben und ein neues cFood entsteht für die gefallene Ameise sonst
	//Proviantstatus -- und Lebensstatus --

//Was ist mein Status? 
		
	//Futtersuche oder am Heimweg!
		//Wenn am Heimweg, dann 
			//bin ich schon zuHause? 
				//wenn ja, dann Futter abgeben Proviant aufnehemen und Status auf Futtersuche!
			//sonst Pheromon legen  
			//Homelist abarbeiten!

		//Wenn auf Futtersuche, dann 
			//Ist Futter auf meinem Feld? 
				//wenn Futter, dann Futter aufnehmen und Status auf Home! 
				//sonst Was ist um mich herum?
					//wenn Futter, dann
						//wenn Ameisenhügel, dann diese Richtung ausschließen
						//sonst dorthin gehen
					//wenn Pheromon, dann dorthin gehen
					//sonst Random nach LROU (falls Anthill, hier mit Parameter mitgeben auf welchem der Felder (north=1, east=2, south=3 west=4), um es auszuschließen)  

	
	cField*	cAnt::Whatsnext()
	{
		//Futter=333; Pheromon= >0 && <101; Nichts= 0; Anthill=222;
		ActualPosition->getpNorth
		if(typeid().name ==typeid(cFood).name)
		ActualPosition->getpNorth

	}