#pragma once

#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#include <iostream>
#include "Sword.h"
#include "Gun.h"

using std::cout;
using std::endl;

class Character {
private:
	int m_hp, _level, _fullHp;

	void resetCharater();
public:
	Sword* _sword;
	Gun* _gun;

	int getHp();
	void setHp(int _hp);

	__declspec(property(get = getHp, put = setHp)) int hp;

	Character();

	Character(int hp, int fullHp, int level, int countSword, int countGun);

	int swordAttack();
	int gunAttack();
	void grabItem(int item);
	void levelUp();

	void printInfo();

	void printEquipmentCount();

	int getLevel();
	int getFullHp();
	int getAttackCount_Sword();
	int getAttackCount_Gun();
};

#endif // !__CHARACTER_H__
