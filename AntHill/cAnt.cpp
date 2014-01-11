#include "cAnt.h"
#include "cArea.h"
#include "cItem.h"
#include <typeinfo>


cAnt::cAnt(cField* position):ActualPosition(position),typ(3),TTL((LINES+COLUMNS+(LINES+COLUMNS)/2)*3)//,Lunchbox(100)//Joey: Lunchbox muss noch ausgearbeitet werden!
{
	Fund=0;
	Status = true; //true = Futtersuche/ false = Way Home
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
 cCreator::Instance()->create(1, ActualPosition);//und ein neues cFood für die gefallene Ameise entstehen lassen
//reduceAntcounter;//TODO: Ausstehendes reduceAntcounter muss ausprogrammiert werden!	
}

//accessors
void cAnt::act()
{
	//phNorth=0; //Pheromonstatus im Norden, wenn true dann Pheromon vorhanden wenn false dann keines
	//phEast=0;
	//phSouth=0;
	//phWest=0;
	int	pheromonIntensity=0;
	int lastdirection=0;


	//std::cout<<"SIR. Ich bin eine Ameise!, SIR."<<std::endl; 
	
	//PART 1:
		//Was ist mein Lebensstatus und Proviantstatus?
		//wenn Lebensstatus oder Proviant aufgebraucht 
			//kill und Futter an aktuelles Feld abgeben und ein neues cFood entsteht für die gefallene Ameise sonst
		//Proviantstatus -- und Lebensstatus --
	if(TTL==0)// || Lunchbox==0)//kill! Für Ameise aus ItemListe des aktuellen Fields herauszulöschen, eventuell transportiertes Futter an aktuelles Feld abzugeben und ein neues cFood für die gefallene Ameise entstehen zu lassen  SIEHE DESTRUCTOR
	{
		delete this;
	}
	else //THE SHOW MUST GO ON! Proviantstatus -- und Lebensstatus --
	{
		//Lunchbox--;//Joey: Der Umgang mit der Lunchbox ist noch nicht zu ende gedacht!!!
			TTL--;
	}

	//PART 2:
		//Futtersuche oder am Heimweg?
		//Wenn auf Futtersuche, danpn 
				//ist auf meinem Feld der Ameisenhügel? wenn ja, dann was ist sonst um mich herum?
				//Ist Futter auf meinem Feld? 
					//wenn Futter, dann Futter aufnehmen und Status auf Home! 
					//sonst Was ist um mich herum?
						//wenn Futter, dann
							//wenn dort auch der Ameisenhügel, dann dieses Feld ausschließen
							//sonst dorthin gehen
						//wenn Pheromon, dann dorthin gehen
						//sonst Random nach LROU (falls Anthill, hier mit Parameter mitgeben auf welchem der Felder (north=1, east=2, south=3 west=4), um es auszuschließen) 

	if(Status) //Futtersuche : Ist relativ aufwendig geworden, wenn in irgenteiner Richtung futter gefunden wird, wird dort hinge´gangen.
	{
		if(!ActualPosition->getTypamount(2))//Ist auf meinem aktuellen Feld der Anthill? - NOPE, dann
		{
			if(Fund=ActualPosition->getFOODifTHEREis())//Ist Futter auf meinem Aktuellen Feld? - Yes, dann mitnehmen und
			{
				Status=0;//Status auf "zurück nach Hause" gesetzt!
			}
			else//Was ist sonst um mich herum
			{
				for (int i = 1; i < 5; i++)//1=North, 2=East, 3=South, 4=West
				{
					
					if(carrymehomelist.end==ActualPosition->directioniter(i))//Waren wir hier gerade schon? - Yes, dann
					{
						lastdirection=i;
					}
					
				}

//Suche im norden
						if(!ActualPosition->getpNorth.getTypamount(2))//Ist im Norden der Ameisenhügel? - Nope, dann
						{
							if(ActualPosition->getpNorth.getTypamount(1))//Ist dort Futter? - Ja, dann
							{   
								ActualPosition->remItem(this);
								ActualPosition = ActualPosition->getpNorth;
								carrymehomelist.push_back(ActualPosition);
								ActualPosition->adItem(this);

							}
								if(pheromonIntensity=ActualPosition->getpNorth.getTypamount(4))//Ist dort Pheromon? - Nope, dann
								{

								}

						}
							
//Suche im osten
							if(!ActualPosition->getpEast.getTypamount(2))//Ist im osten der Ameisenhügel? - Nope, dann
							{
								if(!ActualPosition->getpEast.getTypamount(1))//Ist dort Futter? - Nope, dann
								{
									if(!ActualPosition->getpEast.getTypamount(4))//Ist dort Pheromon? - Nope, dann
									{
//Suche im süden
														if(!ActualPosition->getpSouth.getTypamount(2))//Ist im süden der Ameisenhügel? - Nope, dann
														{
															if(!ActualPosition->getpSouth.getTypamount(1))//Ist dort Futter? - Nope, dann
															{
																if(!ActualPosition->getpSouth.getTypamount(4))//Ist dort Pheromon? - Nope, dann
																{
//Suche im Westen
																						if(!ActualPosition->getpWest.getTypamount(2))//Ist im Wsten der Ameisenhügel? - Nope, dann
																						{
																							if(!ActualPosition->getpWest.getTypamount(1))//Ist dort Futter? - Nope, dann
																							{
																								if(!ActualPosition->getpWest.getTypamount(4))//Ist dort Pheromon? - Nope, dann
																								{

																									ActualPosition = Whatsnext();
																									carrymehomelist.push_back(ActualPosition);


																								}else//Wenn im Wsten ein Pheromon, dann 
																								{
																									phWest=1;
																									ActualPosition = Whatsnext();
																									carrymehomelist.push_back(ActualPosition);
																								}
																							}else //Wenn im westen Futter, Dann setze Actuelle  Pos dorthin
																							{
																								ActualPosition = ActualPosition->getpWest;
																								carrymehomelist.push_back(ActualPosition);
																							}
																						}

																}else//Wenn im Süden ein Pheromon, dann setze phSouth auf true und suche im Westen weiter 
																{
																	phSouth=1;
//Suche im Westen
																						if(!ActualPosition->getpWest.getTypamount(2))//Ist im Wsten der Ameisenhügel? - Nope, dann
																						{
																							if(!ActualPosition->getpWest.getTypamount(1))//Ist dort Futter? - Nope, dann
																							{
																								if(!ActualPosition->getpWest.getTypamount(4))//Ist dort Pheromon? - Nope, dann
																								{
																											ActualPosition = Whatsnext();
																											carrymehomelist.push_back(ActualPosition);

																								}else//Wenn im Wsten ein Pheromon, dann 
																								{
																									phWest=1;
																									ActualPosition = Whatsnext();
																									carrymehomelist.push_back(ActualPosition);
																								}
																							}else //Wenn im westen Futter, Dann setze Actuelle  Pos dorthin
																							{
																								ActualPosition = ActualPosition->getpWest;
																								carrymehomelist.push_back(ActualPosition);
																							}
																						}
																}
															}else //Wenn im Süden Futter, Dann setze Actuelle  Pos dorthin
															{
																ActualPosition = ActualPosition->getpSouth;
																carrymehomelist.push_back(ActualPosition);
															}
				

									}else//Wenn im osten ein Pheromon, dann setze phEast auf true und suche weiter im Süden
									{
										phEast=1;

//Suche im süden0
															if(!ActualPosition->getpSouth.getTypamount(2))//Ist im süden der Ameisenhügel? - Nope, dann
															{
																if(!ActualPosition->getpSouth.getTypamount(1))//Ist dort Futter? - Nope, dann
																{
																	if(!ActualPosition->getpSouth.getTypamount(4))//Ist dort Pheromon? - Nope, dann
																	{
//Suche im Westen0
																						if(!ActualPosition->getpWest.getTypamount(2))//Ist im Wsten der Ameisenhügel? - Nope, dann
																						{
																							if(!ActualPosition->getpWest.getTypamount(1))//Ist dort Futter? - Nope, dann
																							{
																								if(!ActualPosition->getpWest.getTypamount(4))//Ist dort Pheromon? - Nope, dann
																								{

																									ActualPosition = Whatsnext();
																									carrymehomelist.push_back(ActualPosition);
																								}else//Wenn im Wsten ein Pheromon, dann 
																								{
																									phWest=1;
																									ActualPosition = Whatsnext();
																									carrymehomelist.push_back(ActualPosition);
																								}
																							}else //Wenn im westen Futter, Dann setze Actuelle  Pos dorthin
																							{
																								ActualPosition = ActualPosition->getpWest;
																								carrymehomelist.push_back(ActualPosition);
																							}
																						}

																	}else//Wenn im Süden ein Pheromon, dann setze phSouth auf true und suche im Westen weiter
																	{
																		phSouth=1;
//Suche im Westen0
																						if(!ActualPosition->getpWest.getTypamount(2))//Ist im Wsten der Ameisenhügel? - Nope, dann
																						{
																							if(!ActualPosition->getpWest.getTypamount(1))//Ist dort Futter? - Nope, dann
																							{
																								if(!ActualPosition->getpWest.getTypamount(4))//Ist dort Pheromon? - Nope, dann
																								{
																									ActualPosition = Whatsnext();
																									carrymehomelist.push_back(ActualPosition);

																								}else//Wenn im Wsten ein Pheromon, dann 
																								{
																									phWest=1;
																									ActualPosition = Whatsnext();
																									carrymehomelist.push_back(ActualPosition);
																								}
																							}else //Wenn im westen Futter, Dann setze Actuelle  Pos dorthin
																							{
																								ActualPosition = ActualPosition->getpWest;
																								carrymehomelist.push_back(ActualPosition);
																							}
																						}
																	}
																}else //Wenn im Süden Futter, Dann setze Actuelle  Pos dorthin
																{
																	ActualPosition = ActualPosition->getpSouth;
																	carrymehomelist.push_back(ActualPosition);
																}
															}
									}
								}else //Wenn im osten Futter, Dann setze Actuelle  Pos dorthin
								{
									ActualPosition = ActualPosition->getpEast;
									carrymehomelist.push_back(ActualPosition);
								}
							}

						}else//Wenn im norden ein Pheromon, dann setze phNorth true und suche im osten weiter
						{
						phNorth=1;

//Suche im osten0

							if(!ActualPosition->getpEast.getTypamount(2))//Ist im osten der Ameisenhügel? - Nope, dann
							{
								if(!ActualPosition->getpEast.getTypamount(1))//Ist dort Futter? - Nope, dann
								{
									if(!ActualPosition->getpEast.getTypamount(4))//Ist dort Pheromon? - Nope, dann
									{
//Suche im süden0
															if(!ActualPosition->getpSouth.getTypamount(2))//Ist im süden der Ameisenhügel? - Nope, dann
															{
																if(!ActualPosition->getpSouth.getTypamount(1))//Ist dort Futter? - Nope, dann
																{
																	if(!ActualPosition->getpSouth.getTypamount(4))//Ist dort Pheromon? - Nope, dann
																	{
//Suche im Westen0
																						if(!ActualPosition->getpWest.getTypamount(2))//Ist im Wsten der Ameisenhügel? - Nope, dann
																						{
																							if(!ActualPosition->getpWest.getTypamount(1))//Ist dort Futter? - Nope, dann
																							{
																								if(!ActualPosition->getpWest.getTypamount(4))//Ist dort Pheromon? - Nope, dann
																								{
																									ActualPosition = Whatsnext();
																									carrymehomelist.push_back(ActualPosition);

																								}else//Wenn im Wsten ein Pheromon, dann 
																								{
																									phWest=1;
																									ActualPosition = Whatsnext();
																									carrymehomelist.push_back(ActualPosition);
																								}
																							}else //Wenn im westen Futter, Dann setze Actuelle  Pos dorthin
																							{
																								ActualPosition = ActualPosition->getpWest;
																								carrymehomelist.push_back(ActualPosition);
																							}
																						}

																	}else//Wenn im Süden ein Pheromon, dann setze phSouth auf true und suche im Westen weiter
																	{
																		phSouth=1;
//Suche im Westen
																						if(!ActualPosition->getpWest.getTypamount(2))//Ist im Wsten der Ameisenhügel? - Nope, dann
																						{
																							if(!ActualPosition->getpWest.getTypamount(1))//Ist dort Futter? - Nope, dann
																							{
																								if(!ActualPosition->getpWest.getTypamount(4))//Ist dort Pheromon? - Nope, dann
																								{
																									ActualPosition = Whatsnext();
																									carrymehomelist.push_back(ActualPosition);
																								}else//Wenn im Wsten ein Pheromon, dann 
																								{
																									phWest=1;
																									ActualPosition = Whatsnext();
																									carrymehomelist.push_back(ActualPosition);
																								}
																							}else //Wenn im westen Futter, Dann setze Actuelle  Pos dorthin
																							{
																								ActualPosition = ActualPosition->getpWest;
																								carrymehomelist.push_back(ActualPosition);
																							}
																						}
																	}
																}else //Wenn im Süden Futter, Dann setze Actuelle  Pos dorthin
																{
																	ActualPosition = ActualPosition->getpSouth;
																	carrymehomelist.push_back(ActualPosition);
																}
															}
									}

									}else//Wenn im osten ein Pheromon, dann setze phEast auf true und suche weiter im Süden
									{
										phEast=1;
//Suche im süden0
															if(!ActualPosition->getpSouth.getTypamount(2))//Ist im süden der Ameisenhügel? - Nope, dann
															{
																if(!ActualPosition->getpSouth.getTypamount(1))//Ist dort Futter? - Nope, dann
																{
																	if(!ActualPosition->getpSouth.getTypamount(4))//Ist dort Pheromon? - Nope, dann
																	{
//Suche im Westen0
																						if(!ActualPosition->getpWest.getTypamount(2))//Ist im Wsten der Ameisenhügel? - Nope, dann
																						{
																							if(!ActualPosition->getpWest.getTypamount(1))//Ist dort Futter? - Nope, dann
																							{
																								if(!ActualPosition->getpWest.getTypamount(4))//Ist dort Pheromon? - Nope, dann
																								{
																									ActualPosition = Whatsnext();
																									carrymehomelist.push_back(ActualPosition);
																								}else//Wenn im Wsten ein Pheromon, dann 
																								{
																									phWest=1;
																									ActualPosition = Whatsnext();
																									carrymehomelist.push_back(ActualPosition);
																								}
																							}else //Wenn im westen Futter, Dann setze Actuelle  Pos dorthin
																							{
																								ActualPosition = ActualPosition->getpWest;
																								carrymehomelist.push_back(ActualPosition);
																							}
																						}

																	}else//Wenn im Süden ein Pheromon, dann setze phSouth auf true und suche im Westen weiter
																	{
																		phSouth=1;
//Suche im Westen0
																						if(!ActualPosition->getpWest.getTypamount(2))//Ist im Wsten der Ameisenhügel? - Nope, dann
																						{
																							if(!ActualPosition->getpWest.getTypamount(1))//Ist dort Futter? - Nope, dann
																							{
																								if(!ActualPosition->getpWest.getTypamount(4))//Ist dort Pheromon? - Nope, dann
																								{

																									ActualPosition = Whatsnext();
																									carrymehomelist.push_back(ActualPosition);
																								}else//Wenn im Wsten ein Pheromon, dann 
																								{
																									phWest=1;
																									ActualPosition = Whatsnext();
																									carrymehomelist.push_back(ActualPosition);
																								}
																							}else //Wenn im westen Futter, Dann setze Actuelle  Pos dorthin
																							{
																								ActualPosition = ActualPosition->getpWest;
																								carrymehomelist.push_back(ActualPosition);
																							}
																						}
				
																	}
																}else //Wenn im Süden Futter, Dann setze Actuelle  Pos dorthin
																{
																	ActualPosition = ActualPosition->getpSouth;
																	carrymehomelist.push_back(ActualPosition);
																}
															}
									}
									
								}else //Wenn im osten Futter, Dann setze Actuelle  Pos dorthin
								{
									ActualPosition = ActualPosition->getpEast;
									carrymehomelist.push_back(ActualPosition);
								}
							}
						}
					}else //Wenn im norden Futter, Dann setze Actuelle  Pos dorthin
					{
						ActualPosition = ActualPosition->getpNorth;
						carrymehomelist.push_back(ActualPosition);
					}
				}
				

				

				
			}
		}else //Wenn Ant auf Anthill dann wird Lunchbox aufgefüllt.
		{
			Lunchbox=100;
		}
	
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


	}else //Weg heim
	{
		


		//Homelist abarbeiten
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

	
	cField*	cAnt::Whatsnext() // TDOO: es muss noch verglichen werden wenn mehrere Pheromone da sind.
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
	}*/


	//cField* cAnt::randway() // gibt eine Zufallsrichtung zurück! muss noch ausprogrammiert werden!
	//{


	//}
