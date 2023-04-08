#include "Character.h"

void Character::resetCharater() {
	m_hp = 100;
	_fullHp = 100;
	_level = 1;
	_sword = new Sword();
	_gun = new Gun(0);
}

int Character::getHp() { return m_hp; }
void Character::setHp(int _hp) { this->m_hp = _hp; }

Character::Character() {
		resetCharater();
}

Character::Character(int hp, int fullHp, int level, int countSword, int countGun) {
	this->m_hp = hp;
	this->_fullHp = fullHp;
	this->_level = level;
	_sword = new Sword(countSword);
	_gun = new Gun(countGun);
}

int Character::swordAttack() { return _sword->attack(); }
int Character::gunAttack() { return _gun->attack(); }
void Character::grabItem(int item) {
	if (item == 0) _sword->grabEquipment();
	else _gun->grabEquipment();
}
void Character::levelUp() {
	_level++;
	_fullHp *= 1.2;
	m_hp = _fullHp;

	cout << "������ �ö����ϴ�!\n���� ���� : " << _level << endl << endl;
}

void Character::printInfo() {
	cout << "�ִ� ü�� : " << _fullHp << endl;
	cout << "���� ü�� : " << m_hp << endl;
	cout << "���� : " << _level << endl;
	cout << "Į ��� ���� Ƚ�� : " << _sword->attackCount() << endl;
	cout << "�� ��� ���� Ƚ�� : " << _gun->attackCount() << endl << endl;
}

void Character::printEquipmentCount() {
	cout << "Į ��� ���� Ƚ�� : " << _sword->attackCount() << endl;
	cout << "�� ��� ���� Ƚ�� : " << _gun->attackCount() << endl << endl;
}

int Character::getLevel() { return _level; }
int Character::getFullHp() { return _fullHp; }
int Character::getAttackCount_Sword() { return _sword->attackCount(); }
int Character::getAttackCount_Gun() { return _gun->attackCount(); }