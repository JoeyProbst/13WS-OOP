//#pragma once
#ifndef COBSERVER_HEADER
#define COBSERVER_HEADER

class cSubject;

class cObserver
{
public:
	virtual void update(cSubject*)=0;
	cObserver(void);
	virtual ~cObserver(void);
};

#endif // !COBSERVER_HEADER