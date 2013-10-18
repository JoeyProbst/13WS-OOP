#include <cstring>
#include "CPJob.h"

//Note: CPJob constructor is part of the Assignment1

//constructor ::sets text-field and process-id
CPJob::CPJob(char *_szText, long _IPid)
{
	IPid= _IPid;
	szText= new char[std::strlen(_szText)+1];
	std::strcpy(szText, _szText);
}

//destructor ::deletes allocated mem for text-field
CPJob::~CPJob(void)
{
	delete[] szText;
}

//accessor::sets text-field
char* CPJob::setText(char * _szText,char *prevText)  //Theo: gibt dann das zussamengeh�ngte char* zur�ck.
{
	
	//szText= new char[std::strlen(_szText)+1];
	_szText= std::strcat(prevText, _szText);			//Theo:H�ngt char* an char* an, bekomm aber hier eine Zugriffsverletzung
	return _szText;
}

//accessor::returns text-field
char * CPJob::getText(void)
{
	return szText;
}

//accessor::returns process id
long CPJob::getPid(void)
{
	return IPid;
}