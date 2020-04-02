#ifndef DISPLAY_H
#define DISPLAY_H
#include "color.h"

#include "brain.h"

class Window : public Ant, Color {
public:
	Window();
	void printTrace();
	void printAnt();
	void printStep(int step);
};



#endif
