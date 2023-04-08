#pragma once

#ifndef __GUN_H__
#define __GUN_H__
#include <iostream>

#include "Equipment.h"

using std::cout;

class Gun : public Equipment {
public:
	Gun();
	Gun(int hasCount);
	int attack();
	void grabEquipment();
};

#endif // __GUN_H__
