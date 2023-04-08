#include "Enemy.h"

Enemy::Enemy(int hp) : Character(hp, hp, 0, 5, 2) {

}

int Enemy::computerTurn() {
	srand((unsigned int)time(NULL));

	//0 : Į �ݱ�, 1 : �� �ݱ�, 2 : Į ����, 3 : �� ����
	int random = rand() % 4;

	if (random == 0) {
		_sword->grabEquipment();
		return 0;
	}
	else if (random == 1) {
		_gun->grabEquipment();
		return 0;
	}
	else if (random == 2) { return _sword->attack(); }
	else { return _gun->attack(); }
}