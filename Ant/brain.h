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

public:
	direction up;
	direction right;
	direction down;
	direction left;

	direction* antDirection;

	int antRow;
	int antColumn;

	Ant();
	void nextStep();
	void moveAnt(direction* antDirection);
	void trace() {
		this->map[antRow][antColumn] = !(this->map[antRow][antColumn]);
	}
};

#endif
