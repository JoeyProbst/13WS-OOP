#include "cAnt.h"
#include "cArea.h"
#include "cItem.h"
#include <typeinfo>


cAnt::cAnt(cField* position):ActualPosition(position),typ(3),TTL((LINES+COLUMNS+(LINES+COLUMNS)/2)*3),roundBasedTurnIndicator(0),Fund(NULL)//,Lunchbox(100)//Joey: Lunchbox muss noch ausgearbeitet werden!
{
	//Fund=0;
	state = true; //true = Futtersuche/ false = on my way home
	ActualPosition->adItem(this);
	carrymehomelist.push_front(ActualPosition);
//	Lunchbox=100;
	
}


cAnt::~cAnt(void)
{
ActualPosition->remItem(this);//Ameise aus ItemListe des aktuellen Fields herauslöschen
if(Fund)//eventuell transportiertes Futter an aktuelles Feld abgeben
{
ActualPosition->adItem(Fund);
Fund=NULL;
}
 //cCreator::Instance()->create(1, ActualPosition);//und ein neues cFood für die gefallene Ameise entstehen lassen //Ameise kann ohne Lanchbox nicht zum Futter werden, da die ganze Simulation sonst zur Endlosschleife wird!
//reduceAntcounter;//TODO: Ausstehendes reduceAntcounter muss ausprogrammiert werden!	
}

//accessors
void cAnt::act(int roundIndicator)
{
	//phNorth=0; //Pheromonstatus im Norden, wenn true dann Pheromon vorhanden wenn false dann keines
	//phEast=0;
	//phSouth=0;
	//phWest=0;
	int	pheromonIntensity=0;//????
	int lastdirection=0;//????

	if(roundIndicator!=roundBasedTurnIndicator)
	{
		if(TTL==0)// || Lunchbox==0)//kill! Für Ameise aus ItemListe des aktuellen Fields herauszulöschen, eventuell transportiertes Futter an aktuelles Feld abzugeben und ein neues cFood für die gefallene Ameise entstehen zu lassen  SIEHE DESTRUCTOR
		{
			delete this;
		}
		else //THE SHOW MUST GO ON! Proviantstatus -- und Lebensstatus --
		{
			//Lunchbox--;//Joey: Der Umgang mit der Lunchbox ist noch nicht zu ende gedacht!!!
			TTL--;
		
			if (state)//Auf Futtersuche!
			{
				search();//Wegentscheidung
				take();//Futter aufnehmen, falls vorhanden
			}
			else
			{
				gohome();//Mit bereits gefundenem Futter nach Hause gehen
				giveback();//Legt Pheromon ab oder das gefundene Futter falls am aktuellen Feld der Ameisenhügel liegt
			}
		}
		roundBasedTurnIndicator=roundIndicator;
	}
}

	//std::cout<<"SIR. Ich bin eine Ameise!, SIR."<<std::endl; 
	
	//PART 1:
		//Was ist mein Lebensstatus und Proviantstatus?
		//wenn Lebensstatus oder Proviant aufgebraucht 
			//kill und Futter an aktuelles Feld abgeben und ein neues cFood entsteht für die gefallene Ameise sonst
		//Proviantstatus -- und Lebensstatus --
	

	//PART 2:

		//{//Futtersuche oder am Heimweg?
		////Wenn auf Futtersuche, dann 
		//		//ist auf meinem Feld der Ameisenhügel? wenn ja, dann was ist sonst um mich herum?
		//		//Ist Futter auf meinem Feld? 
		//			//wenn Futter, dann Futter aufnehmen und Status auf Home! 
		//			//sonst Was ist um mich herum?
		//				//wenn Futter, dann
		//					//wenn dort auch der Ameisenhügel, dann dieses Feld ausschließen
		//					//sonst dorthin gehen
		//				//wenn Pheromon, dann dorthin gehen
		//}				//sonst Random nach LROU (falls Anthill, hier mit Parameter mitgeben auf welchem der Felder (north=1, east=2, south=3 west=4), um es auszuschließen) 

		//Was ist um mich herum?
			//Himmelsrichtung:
				//Komme ich von hier?	Yes - return NULL und Intensität=0 
				//Steht hier der Ameisenhügel? Yes - return cField* und Intensität=0
				//Liegt hier Futter? return cField* und Intensität=0 und Futtertrue=true
				//Liegt hier Pheromon? return cField* und Intensitätswert //vergleiche intensität
				//else return mit Random
			//wenn Futter, dann
				//wenn dort auch der Ameisenhügel, dann dieses Feld ausschließen
				//sonst dorthin gehen
			//wenn Pheromon, dann dorthin gehen
			//sonst Random nach LROU (falls Anthill, hier mit Parameter mitgeben auf welchem der Felder (north=1, east=2, south=3 west=4), um es auszuschließen) 


		

//	if(Status) //Futtersuche
//	{
//		if(!ActualPosition->getTypamount(2))//Ist auf meinem aktuellen Feld der Anthill? - NOPE, dann
//		{
//			if(Fund=ActualPosition->getFOODifTHEREis())//Ist Futter auf meinem Aktuellen Feld? - Yes, dann mitnehmen und
//			{
//				Status=0;//Status auf "zurück nach Hause" gesetzt!
//			}
//			else//Was ist sonst um mich herum
//			{
//				for (int i = 1; i < 5; i++)//1=North, 2=East, 3=South, 4=West
//				{
//					
//					if(carrymehomelist.end==ActualPosition->directioniter(i))//Waren wir hier gerade schon? - Yes, dann
//					{
//						lastdirection=i;
//					}
//					
//				}
//
////Suche im norden
//						if(!ActualPosition->getpNorth.getTypamount(2))//Ist im Norden der Ameisenhügel? - Nope, dann
//						{
//							if(ActualPosition->getpNorth.getTypamount(1))//Ist dort Futter? - Ja, dann
//							{   
//								ActualPosition->remItem(this);
//								ActualPosition = ActualPosition->getpNorth;
//								carrymehomelist.push_back(ActualPosition);
//								ActualPosition->adItem(this);
//
//							}
//								if(pheromonIntensity=ActualPosition->getpNorth.getTypamount(4))//Ist dort Pheromon? - Nope, dann
//								{
//
//								}
//
//						}
							
////Suche im osten
//							if(!ActualPosition->getpEast.getTypamount(2))//Ist im osten der Ameisenhügel? - Nope, dann
//							{
//								if(!ActualPosition->getpEast.getTypamount(1))//Ist dort Futter? - Nope, dann
//								{
//									if(!ActualPosition->getpEast.getTypamount(4))//Ist dort Pheromon? - Nope, dann
//									{
////Suche im süden
//														if(!ActualPosition->getpSouth.getTypamount(2))//Ist im süden der Ameisenhügel? - Nope, dann
//														{
//															if(!ActualPosition->getpSouth.getTypamount(1))//Ist dort Futter? - Nope, dann
//															{
//																if(!ActualPosition->getpSouth.getTypamount(4))//Ist dort Pheromon? - Nope, dann
//																{
////Suche im Westen
//																						if(!ActualPosition->getpWest.getTypamount(2))//Ist im Wsten der Ameisenhügel? - Nope, dann
//																						{
//																							if(!ActualPosition->getpWest.getTypamount(1))//Ist dort Futter? - Nope, dann
//																							{
//																								if(!ActualPosition->getpWest.getTypamount(4))//Ist dort Pheromon? - Nope, dann
//																								{
//
//																									ActualPosition = Whatsnext();
//																									carrymehomelist.push_back(ActualPosition);
//
//
//																								}else//Wenn im Wsten ein Pheromon, dann 
//																								{
//																									phWest=1;
//																									ActualPosition = Whatsnext();
//																									carrymehomelist.push_back(ActualPosition);
//																								}
//																							}else //Wenn im westen Futter, Dann setze Actuelle  Pos dorthin
//																							{
//																								ActualPosition = ActualPosition->getpWest;
//																								carrymehomelist.push_back(ActualPosition);
//																							}
//																						}
//
//																}else//Wenn im Süden ein Pheromon, dann setze phSouth auf true und suche im Westen weiter 
//																{
//																	phSouth=1;
////Suche im Westen
//																						if(!ActualPosition->getpWest.getTypamount(2))//Ist im Wsten der Ameisenhügel? - Nope, dann
//																						{
//																							if(!ActualPosition->getpWest.getTypamount(1))//Ist dort Futter? - Nope, dann
//																							{
//																								if(!ActualPosition->getpWest.getTypamount(4))//Ist dort Pheromon? - Nope, dann
//																								{
//																											ActualPosition = Whatsnext();
//																											carrymehomelist.push_back(ActualPosition);
//
//																								}else//Wenn im Wsten ein Pheromon, dann 
//																								{
//																									phWest=1;
//																									ActualPosition = Whatsnext();
//																									carrymehomelist.push_back(ActualPosition);
//																								}
//																							}else //Wenn im westen Futter, Dann setze Actuelle  Pos dorthin
//																							{
//																								ActualPosition = ActualPosition->getpWest;
//																								carrymehomelist.push_back(ActualPosition);
//																							}
//																						}
//																}
//															}else //Wenn im Süden Futter, Dann setze Actuelle  Pos dorthin
//															{
//																ActualPosition = ActualPosition->getpSouth;
//																carrymehomelist.push_back(ActualPosition);
//															}
//				
//
//									}else//Wenn im osten ein Pheromon, dann setze phEast auf true und suche weiter im Süden
//									{
//										phEast=1;
//
////Suche im süden0
//															if(!ActualPosition->getpSouth.getTypamount(2))//Ist im süden der Ameisenhügel? - Nope, dann
//															{
//																if(!ActualPosition->getpSouth.getTypamount(1))//Ist dort Futter? - Nope, dann
//																{
//																	if(!ActualPosition->getpSouth.getTypamount(4))//Ist dort Pheromon? - Nope, dann
//																	{
////Suche im Westen0
//																						if(!ActualPosition->getpWest.getTypamount(2))//Ist im Wsten der Ameisenhügel? - Nope, dann
//																						{
//																							if(!ActualPosition->getpWest.getTypamount(1))//Ist dort Futter? - Nope, dann
//																							{
//																								if(!ActualPosition->getpWest.getTypamount(4))//Ist dort Pheromon? - Nope, dann
//																								{
//
//																									ActualPosition = Whatsnext();
//																									carrymehomelist.push_back(ActualPosition);
//																								}else//Wenn im Wsten ein Pheromon, dann 
//																								{
//																									phWest=1;
//																									ActualPosition = Whatsnext();
//																									carrymehomelist.push_back(ActualPosition);
//																								}
//																							}else //Wenn im westen Futter, Dann setze Actuelle  Pos dorthin
//																							{
//																								ActualPosition = ActualPosition->getpWest;
//																								carrymehomelist.push_back(ActualPosition);
//																							}
//																						}
//
//																	}else//Wenn im Süden ein Pheromon, dann setze phSouth auf true und suche im Westen weiter
//																	{
//																		phSouth=1;
////Suche im Westen0
//																						if(!ActualPosition->getpWest.getTypamount(2))//Ist im Wsten der Ameisenhügel? - Nope, dann
//																						{
//																							if(!ActualPosition->getpWest.getTypamount(1))//Ist dort Futter? - Nope, dann
//																							{
//																								if(!ActualPosition->getpWest.getTypamount(4))//Ist dort Pheromon? - Nope, dann
//																								{
//																									ActualPosition = Whatsnext();
//																									carrymehomelist.push_back(ActualPosition);
//
//																								}else//Wenn im Wsten ein Pheromon, dann 
//																								{
//																									phWest=1;
//																									ActualPosition = Whatsnext();
//																									carrymehomelist.push_back(ActualPosition);
//																								}
//																							}else //Wenn im westen Futter, Dann setze Actuelle  Pos dorthin
//																							{
//																								ActualPosition = ActualPosition->getpWest;
//																								carrymehomelist.push_back(ActualPosition);
//																							}
//																						}
//																	}
//																}else //Wenn im Süden Futter, Dann setze Actuelle  Pos dorthin
//																{
//																	ActualPosition = ActualPosition->getpSouth;
//																	carrymehomelist.push_back(ActualPosition);
//																}
//															}
//									}
//								}else //Wenn im osten Futter, Dann setze Actuelle  Pos dorthin
//								{
//									ActualPosition = ActualPosition->getpEast;
//									carrymehomelist.push_back(ActualPosition);
//								}
//							}
//
//						}else//Wenn im norden ein Pheromon, dann setze phNorth true und suche im osten weiter
//						{
//						phNorth=1;
//
////Suche im osten0
//
//							if(!ActualPosition->getpEast.getTypamount(2))//Ist im osten der Ameisenhügel? - Nope, dann
//							{
//								if(!ActualPosition->getpEast.getTypamount(1))//Ist dort Futter? - Nope, dann
//								{
//									if(!ActualPosition->getpEast.getTypamount(4))//Ist dort Pheromon? - Nope, dann
//									{
////Suche im süden0
//															if(!ActualPosition->getpSouth.getTypamount(2))//Ist im süden der Ameisenhügel? - Nope, dann
//															{
//																if(!ActualPosition->getpSouth.getTypamount(1))//Ist dort Futter? - Nope, dann
//																{
//																	if(!ActualPosition->getpSouth.getTypamount(4))//Ist dort Pheromon? - Nope, dann
//																	{
////Suche im Westen0
//																						if(!ActualPosition->getpWest.getTypamount(2))//Ist im Wsten der Ameisenhügel? - Nope, dann
//																						{
//																							if(!ActualPosition->getpWest.getTypamount(1))//Ist dort Futter? - Nope, dann
//																							{
//																								if(!ActualPosition->getpWest.getTypamount(4))//Ist dort Pheromon? - Nope, dann
//																								{
//																									ActualPosition = Whatsnext();
//																									carrymehomelist.push_back(ActualPosition);
//
//																								}else//Wenn im Wsten ein Pheromon, dann 
//																								{
//																									phWest=1;
//																									ActualPosition = Whatsnext();
//																									carrymehomelist.push_back(ActualPosition);
//																								}
//																							}else //Wenn im westen Futter, Dann setze Actuelle  Pos dorthin
//																							{
//																								ActualPosition = ActualPosition->getpWest;
//																								carrymehomelist.push_back(ActualPosition);
//																							}
//																						}
//
//																	}else//Wenn im Süden ein Pheromon, dann setze phSouth auf true und suche im Westen weiter
//																	{
//																		phSouth=1;
////Suche im Westen
//																						if(!ActualPosition->getpWest.getTypamount(2))//Ist im Wsten der Ameisenhügel? - Nope, dann
//																						{
//																							if(!ActualPosition->getpWest.getTypamount(1))//Ist dort Futter? - Nope, dann
//																							{
//																								if(!ActualPosition->getpWest.getTypamount(4))//Ist dort Pheromon? - Nope, dann
//																								{
//																									ActualPosition = Whatsnext();
//																									carrymehomelist.push_back(ActualPosition);
//																								}else//Wenn im Wsten ein Pheromon, dann 
//																								{
//																									phWest=1;
//																									ActualPosition = Whatsnext();
//																									carrymehomelist.push_back(ActualPosition);
//																								}
//																							}else //Wenn im westen Futter, Dann setze Actuelle  Pos dorthin
//																							{
//																								ActualPosition = ActualPosition->getpWest;
//																								carrymehomelist.push_back(ActualPosition);
//																							}
//																						}
//																	}
//																}else //Wenn im Süden Futter, Dann setze Actuelle  Pos dorthin
//																{
//																	ActualPosition = ActualPosition->getpSouth;
//																	carrymehomelist.push_back(ActualPosition);
//																}
//															}
//									}
//
//									}else//Wenn im osten ein Pheromon, dann setze phEast auf true und suche weiter im Süden
//									{
//										phEast=1;
////Suche im süden0
//															if(!ActualPosition->getpSouth.getTypamount(2))//Ist im süden der Ameisenhügel? - Nope, dann
//															{
//																if(!ActualPosition->getpSouth.getTypamount(1))//Ist dort Futter? - Nope, dann
//																{
//																	if(!ActualPosition->getpSouth.getTypamount(4))//Ist dort Pheromon? - Nope, dann
//																	{
////Suche im Westen0
//																						if(!ActualPosition->getpWest.getTypamount(2))//Ist im Wsten der Ameisenhügel? - Nope, dann
//																						{
//																							if(!ActualPosition->getpWest.getTypamount(1))//Ist dort Futter? - Nope, dann
//																							{
//																								if(!ActualPosition->getpWest.getTypamount(4))//Ist dort Pheromon? - Nope, dann
//																								{
//																									ActualPosition = Whatsnext();
//																									carrymehomelist.push_back(ActualPosition);
//																								}else//Wenn im Wsten ein Pheromon, dann 
//																								{
//																									phWest=1;
//																									ActualPosition = Whatsnext();
//																									carrymehomelist.push_back(ActualPosition);
//																								}
//																							}else //Wenn im westen Futter, Dann setze Actuelle  Pos dorthin
//																							{
//																								ActualPosition = ActualPosition->getpWest;
//																								carrymehomelist.push_back(ActualPosition);
//																							}
//																						}
//
//																	}else//Wenn im Süden ein Pheromon, dann setze phSouth auf true und suche im Westen weiter
//																	{
//																		phSouth=1;
////Suche im Westen0
//																						if(!ActualPosition->getpWest.getTypamount(2))//Ist im Wsten der Ameisenhügel? - Nope, dann
//																						{
//																							if(!ActualPosition->getpWest.getTypamount(1))//Ist dort Futter? - Nope, dann
//																							{
//																								if(!ActualPosition->getpWest.getTypamount(4))//Ist dort Pheromon? - Nope, dann
//																								{
//
//																									ActualPosition = Whatsnext();
//																									carrymehomelist.push_back(ActualPosition);
//																								}else//Wenn im Wsten ein Pheromon, dann 
//																								{
//																									phWest=1;
//																									ActualPosition = Whatsnext();
//																									carrymehomelist.push_back(ActualPosition);
//																								}
//																							}else //Wenn im westen Futter, Dann setze Actuelle  Pos dorthin
//																							{
//																								ActualPosition = ActualPosition->getpWest;
//																								carrymehomelist.push_back(ActualPosition);
//																							}
//																						}
//				
//																	}
//																}else //Wenn im Süden Futter, Dann setze Actuelle  Pos dorthin
//																{
//																	ActualPosition = ActualPosition->getpSouth;
//																	carrymehomelist.push_back(ActualPosition);
//																}
//															}
//									}
//									
//								}else //Wenn im osten Futter, Dann setze Actuelle  Pos dorthin
//								{
//									ActualPosition = ActualPosition->getpEast;
//									carrymehomelist.push_back(ActualPosition);
//								}
//							}
//						}
//					}else //Wenn im norden Futter, Dann setze Actuelle  Pos dorthin
//					{
//						ActualPosition = ActualPosition->getpNorth;
//						carrymehomelist.push_back(ActualPosition);
//					}
//				}
//				
//
//				
//
//				
//			}
//		}else //Wenn Ant auf Anthill dann wird Lunchbox aufgefüllt.
//		{
//			Lunchbox=100;
//		}
	
	//if(true)
	//{
	//	//Futter=333; Pheromon= >0 && <101; Nichts= 0; Anthill=222;
	//	ActualPosition = Whatsnext();
	//	carrymehomelist.push_back(ActualPosition);
	//}

	//Futtersuche oder am Heimweg?
		//Wenn am Heimweg, dann 
			//bin ich schon zuHause? 
				//wenn ja, dann Futter abgeben Proviant aufnehemen und Status auf Futtersuche!
			//sonst Pheromon legen  
			//Homelist abarbeiten!


/*	else //Weg heim
	{
		


		//Homelist abarbeiten
		ActualPosition->remItem(this);
		ActualPosition= carrymehomelist.back();
		carrymehomelist.pop_back();
	}


}
*/


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

	
	/*cField*	cAnt::Whatsnext() // TDOO: es muss noch verglichen werden wenn mehrere Pheromone da sind.
	{
		////Futter=333; Pheromon= >0 && <101; Nichts= 0; Anthill=222;
		//ActualPosition->getpNorth
		//if(typeid().name ==typeid(cFood).name)
		//ActualPosition->getpNorth

	/*	if(!phNorth && !phEast && !phSouth && !phWest)
		{	
			return randway();
		}else if(phNorth && !phEast && !phSouth && !phWest)
		{
			return ActualPosition->getpNorth;

		}else if(!phNorth && phEast && !phSouth && !phWest)
		{
			return ActualPosition->getpEast;

		}else if(!phNorth && !phEast && phSouth && !phWest)
		{
			return ActualPosition->getpSouth;

		}else if(!phNorth && !phEast && !phSouth && phWest)
		{
			return ActualPosition->getpWest;
		}
	}


	//cField* cAnt::randway() // gibt eine Zufallsrichtung zurück! muss noch ausprogrammiert werden!
	//{


	}*/

void cAnt::search()//Auf der Suche nach Futter
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


	ActualPosition->remItem(this);//Die Ameise wird aus der Liste des Aktuellen Feldes herausgenommen
	ActualPosition = options.front();//die Wahl des nächsten Feldes wird in die ActualPosition geschrieben
	carrymehomelist.push_back(ActualPosition);//Die neue Actual Position wird in der carrymehomeListe hinten angehängt
	ActualPosition->adItem(this);//Die Ameise wird auf dem neuen Feld in die ItemsListe eingetragen

	//Was ist um mich herum?
			//Himmelsrichtung:
				//Komme ich von hier?	Yes - return NULL und Intensität=0 
				//Steht hier der Ameisenhügel? Yes - return cField* und Intensität=0
				//Liegt hier Futter? return cField* und Intensität=0 und Futtertrue=true
				//Liegt hier Pheromon? return cField* und Intensitätswert //vergleiche intensität
				//else return mit Random
			//wenn Futter, dann
				//wenn dort auch der Ameisenhügel, dann dieses Feld ausschließen
				//sonst dorthin gehen
			//wenn Pheromon, dann dorthin gehen
			//sonst Random nach LROU (falls Anthill, hier mit Parameter mitgeben auf welchem der Felder (north=1, east=2, south=3 west=4), um es auszuschließen)
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

void cAnt::gohome()//Mit gefundenem Futter nach Hause gehen
{
	ActualPosition->remItem(this);//Ameise wird vom aktuellen Feld aus dessen Liste genommen!
	carrymehomelist.pop_back();//das letzte Element in der carrymehomelist wird herausgenommen!
	ActualPosition= carrymehomelist.back();//das nächste letzte Element wird zur ActualPosition!
	ActualPosition->adItem(this);//auf dem neuen Feld wird die Ameise in die Liste eingetragen!
}

void cAnt::giveback()
{
				if (ActualPosition->getTypamount(2)==1)//Steht die Ameise schon auf dem Ameisenhügel?
				{
					ActualPosition->adItem(Fund);
					Fund=NULL;
				}
				else//Pheromon wird abgelegt!
				{
					cCreator* factory=cCreator::Instance();
					factory->create(4, ActualPosition);
				}
}