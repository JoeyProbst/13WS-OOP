//#pragma once
#ifndef CPAINTER_HEADER
#define CPAINTER_HEADER


#include "cobserver.h"
class cPainter :
	public cObserver
{
private:
	static cPainter* _instance;
	cPainter(const cPainter&);
	int antcounter;
	int foodcounter;
	int anthill;
	int pheromonecounter;

	int round;
	int lines;
	int columns;
	int fieldcounter;

protected:
	cPainter(void);
public:
	~cPainter(void);
	static cPainter* Instance();
	void update(cSubject*);
	void paintEnvironment();
	void paintLivingEnvironment();
};

#endif // !CPAINTER_HEADER