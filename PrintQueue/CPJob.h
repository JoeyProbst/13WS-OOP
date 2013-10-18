//#pragma once
#ifndef CPJOB_HEADER
#define CPJOB_HEADER

//Note: CPJob.h is part of the Assignment1

//
//class CPJob define a simple printjob with id and text
//

class CPJob
{
private:
	long IPid;
	char *szText;
public:
	//constructor
	CPJob(char *, long); //inits text-field and process-id

	//destructor
	~CPJob(void);

	//accessors
	void setText(char *); //sets text-field
	char* getText(void); //returns text-field
	long getPid(void); //returns process-id
};

#endif