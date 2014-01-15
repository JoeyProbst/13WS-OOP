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
	int getSubjectTyp();
	~cSubject(void);
protected:
	cSubject(void);
private:
	int subjectTyp;//typ=1 für cArea Objecte; typ=2 für cField Objekte
	std::list<cObserver*>observerList;
};

#endif // !CSUBJECT_HEADER