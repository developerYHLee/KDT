#include "Sword.h"

Sword::Sword() : Equipment(3, 5) {

}

Sword::Sword(int hasCount) : Equipment(hasCount, 5) {

}

int Sword::attack() {
	if (hasCount <= 0) {
		cout << "공격 기회가 없습니다!\n\n";
		return 0;
	}

	hasCount--;
	cout << "찌르기\n\n";
	return damage;
}

void Sword::grabEquipment() {
	cout << "칼을 주웠습니다.\n\n";
	hasCount += 3;
}