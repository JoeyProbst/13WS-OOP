#pragma once

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

