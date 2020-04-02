#ifndef BRAIN_H
#define BRAIN_H

#include "macro.h"
enum class MetaDirection { Up, Right, Down, Left };

class Map {
public:
	Map();
	bool map[HORIZONTAL / CUBE][VERITCAL / CUBE];
};

class Ant : public Map {
	struct direction {
		direction* clockwise;
		direction* anti_clockwise;
		MetaDirection meta;
	};
	direction up;
	direction right;
	direction down;
	direction left;
	direction* antDirection = &up;

	void moveAnt(direction* antDirection);
	void trace() {
		this->map[antRow][antColumn] = !(this->map[antRow][antColumn]);
	}

protected:
	int antRow = HORIZONTAL / CUBE / 3;
	int antColumn = VERITCAL / CUBE / 3;

public:

	Ant();
	void nextStep();

};

#endif
