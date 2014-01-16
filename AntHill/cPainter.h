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
	int multiplier;
	int indexLines;

protected:
	cPainter(void);
public:
	~cPainter(void);
	static cPainter* Instance();
	void update(cSubject*);
	void paintEnvironment();
	void paintIndexColumns();
	void paintHorizontalRaster();
	void paintIndexLines();
	void paintEmptyStartFields();
	void paintInteriorField();
	void paintLivingEnvironment();
	void paintLegende();
};

#endif // !CPAINTER_HEADER