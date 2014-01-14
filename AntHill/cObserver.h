#pragma once
class cSubject;

class cObserver
{
public:
	virtual void update(cSubject*)=0;
	cObserver(void);
	virtual ~cObserver(void);
};

