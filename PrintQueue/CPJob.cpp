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
void CPJob::setText(char * _szText)
{
	//Joey: Ich habe keine Ahnung für was wir setText brauchen!
	//		soll diese Methode die fillQueue ersetzen?
	//@Theo:falls du das auch denkst, bitte Fertigstellen bzw
	//		wenn du weist für was es sonst sein könnte!
	//
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