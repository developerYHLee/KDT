#include "Gun.h"

Gun::Gun() : Equipment(1, 10) {

}

Gun::Gun(int hasCount) : Equipment(hasCount, 10) {

}

int Gun::attack() {
	if (hasCount <= 0) {
		cout << "���� ��ȸ�� �����ϴ�!\n\n";
		return 0;
	}

	hasCount--;
	cout << "�ѽ��\n\n";
	return damage;
}

void Gun::grabEquipment() {
	cout << "���� �ֿ����ϴ�.\n\n";
	hasCount++;
}