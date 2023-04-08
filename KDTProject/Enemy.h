#pragma once

#ifndef __ENEMY_H__
#define __ENEMY_H__
#include <iostream>

#include "Character.h"

class Enemy : public Character {
public:
	Enemy(int hp);
	int computerTurn();
};

#endif // !__ENEMY_H__
