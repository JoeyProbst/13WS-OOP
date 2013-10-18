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
	//Joey: hab einfach den Teil aus dem Constructor kopiert, da das ja genau das ist was wir machen wollen.
	//nur delete hab ich hinzugefügt um den zuvor allozierten speicher aufzuräumen.
	delete[] szText;
	szText= new char[std::strlen(_szText)+1];
	std::strcpy(szText, _szText);
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