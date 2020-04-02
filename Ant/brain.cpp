#include "brain.h"

Map::Map() {
	for (auto i = 0; i < HORIZONTAL / CUBE; i++)
		for (auto j = 0; j < VERITCAL / CUBE; j++)
			this->map[i][j] = false;
}

Ant::Ant() {
	this->up.meta = MetaDirection::Up;
	this->up.clockwise = &(this->right);
	this->up.anti_clockwise = &(this->left);

	this->right.meta = MetaDirection::Right;
	this->right.clockwise = &(this->down);
	this->right.anti_clockwise = &(this->up);

	this->down.meta = MetaDirection::Down;
	this->down.clockwise = &(this->left);
	this->down.anti_clockwise = &(this->right);

	this->left.meta = MetaDirection::Left;
	this->left.clockwise = &(this->up);
	this->left.anti_clockwise = &(this->down);

	this->antDirection = &(this->up);

	this->antRow = HORIZONTAL / CUBE / 3;
	this->antColumn = VERITCAL / CUBE / 3;
}

void Ant::nextStep() {
	if (this->map[this->antRow][this->antColumn])
		this->antDirection = this->antDirection->clockwise;
	else
		this->antDirection = this->antDirection->anti_clockwise;
	trace();
	moveAnt(this->antDirection);
}

void Ant::moveAnt(direction* antDirection) {
	switch (antDirection->meta) {
	case MetaDirection::Up:
		--this->antRow;
		break;
	case MetaDirection::Right:
		++this->antColumn;
		break;
	case MetaDirection::Down:
		++this->antRow;
		break;
	case MetaDirection::Left:
		--this->antColumn;
		break;
	}
}
