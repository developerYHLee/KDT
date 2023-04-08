#pragma once

#ifndef __EQUIPMENT_H__
#define __EQUIPMENT_H__

class Equipment {
public:
	int hasCount, damage;

	Equipment(int hasCount, int damage);

	virtual int attack() = 0;
	virtual void grabEquipment() = 0;

	int attackCount();
};

#endif // !__EQUIPMENT_H__
