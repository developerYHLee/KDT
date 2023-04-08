#include "Sword.h"

Sword::Sword() : Equipment(3, 5) {

}

Sword::Sword(int hasCount) : Equipment(hasCount, 5) {

}

int Sword::attack() {
	if (hasCount <= 0) {
		cout << "���� ��ȸ�� �����ϴ�!\n\n";
		return 0;
	}

	hasCount--;
	cout << "���\n\n";
	return damage;
}

void Sword::grabEquipment() {
	cout << "Į�� �ֿ����ϴ�.\n\n";
	hasCount += 3;
}