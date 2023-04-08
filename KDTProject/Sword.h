#pragma once

#ifndef __SWORD_H__
#define __SWORD_H__
#include <iostream>

#include "Equipment.h"

using std::cout;

class Sword : public Equipment {
public:
	Sword();
	Sword(int hasCount);
	int attack();
	void grabEquipment();
};

#endif // !__SWORD_H__