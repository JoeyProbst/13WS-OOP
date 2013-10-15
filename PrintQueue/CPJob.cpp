#include <cstring>
#include "CPJob.h"

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
	
}

//accessor::returns text-field
char * CPJob::getText(void)
{
	return 0;
}

//accessor::returns process id
long CPJob::getPid(void)
{
	return 0;
}