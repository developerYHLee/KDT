#include "Equipment.h"

Equipment::Equipment(int hasCount, int damage) {
	this->hasCount = hasCount;
	this->damage = damage;
}

int Equipment::attackCount() { return hasCount; }