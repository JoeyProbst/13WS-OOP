#include "cSubject.h"
#include "cObserver.h"

cSubject::cSubject(void)
{
}


cSubject::~cSubject(void)
{
}

void cSubject::attach(cObserver* obs)
{
	observerList.push_back(obs);
}

void cSubject::detach(cObserver* obs)
{
	observerList.remove(obs);
}

void cSubject::notify()
{
	for (std::list<cObserver*>::iterator i = observerList.begin(); i != observerList.end(); ++i)
	{
		(*i)->update(this);
	}
}

int cSubject::getSubjectTyp()
{
	return subjectTyp;
}