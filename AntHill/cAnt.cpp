#include "cAnt.h"
#include "cArea.h"
#include "cItem.h"

#include <typeinfo>


cAnt::cAnt(cField* position):ActualPosition(position)
{
	Fund=0;
	Status = true; //true = Futtersuche/ false = Way Home
	ActualPosition->adItem(this);
	carrymehomelist.push_front(ActualPosition);
}


cAnt::~cAnt(void)
{
ActualPosition->remItem(this);
//redAntcounter;//TODO: KILL AUSPROGRAMMIEREN!!!	
}

//accessors
void cAnt::act()
{
	//std::cout<<"SIR. Ich bin eine Ameise!, SIR."<<std::endl; 
	//if(TTL==0 || Lunchbox==0)
	//{
	////kill
	//	delete this;

	//}
	
	if(Status) //Futtersuche
	{
		Fund=ActualPosition->getfoodstati();

		if(Fund!=0)
		Status=0;
	}
	if(Status)
	{
		//Futter=333; Pheromon= >0 && <101; Nichts= 0; Anthill=222;
		ActualPosition = Whatsnext();
		carrymehomelist.push_back(ActualPosition);
	}
	else //Weg heim
	{
		ActualPosition->remItem(this);
		ActualPosition= carrymehomelist.back();
		carrymehomelist.pop_back();
	}


}


// Gehen:
//Was ist mein Lebensstatus und Provinatstatus?
	//wenn Lebensstatus oder Proviant aufgebraucht 
		//kill
		// Futter an aktuelles Feld abgeben und ein neues cFood entsteht für die gefallene Ameise sonst
	//--
//Was ist mein Status? 
		//Futtersuche oder am Heimweg! STATUS 
				//Wenn heim dann 
					//wenn @Home 
						//Futter abgeben Proviant aufnehemen und Status auf Futtersuche!
					//Pheromon legen  
					//Homelist abarbeiten! sonst						
				//Futtersuche dann 
					//Ist Futter auf meinem Feld? 
						//wenn Futter ,
							//Futter aufnehmen 
							//und Status auf Home! sonst
						//Was ist um mich herum? 
							//Futter oder Pheromonstärke sonst
								//Random nach LROU 
 
//

	
	cField*	cAnt::Whatsnext()
	{
		//Futter=333; Pheromon= >0 && <101; Nichts= 0; Anthill=222;
		ActualPosition->getpNorth
		if(typeid().name ==typeid(cFood).name)
		ActualPosition->getpNorth

	}