#include "cAnt.h"
#include "cArea.h"
#include "cItem.h"

cAnt::cAnt(void)
{
	Status = true; //true = Futtersuche/ false = Way Home
	ActualPosition=getAnthillPosition();
}


cAnt::~cAnt(void)
{
}

//accessors
void cAnt::act()
{
	//std::cout<<"SIR. Ich bin eine Ameise!, SIR."<<std::endl; 
	if(TTL==0 || Lunchbox==0)
	{
	//kill	
	}
	
	if(Status)
	{
//Futtersuche
ActualPosition
	}
	else{
//Weg heim

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