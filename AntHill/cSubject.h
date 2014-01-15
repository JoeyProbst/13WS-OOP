//#pragma once
#ifndef CSUBJECT_HEADER
#define	CSUBJECT_HEADER

class cObserver;
#include <list>

class cSubject
{
public:
	void attach(cObserver*);
	void detach(cObserver*);
	void notify();
	~cSubject(void);
protected:
	cSubject(void);
private:
	std::list<cObserver*>observerList;
};

#endif // !CSUBJECT_HEADER