#include "Gun.h"

Gun::Gun() : Equipment(1, 10) {

}

Gun::Gun(int hasCount) : Equipment(hasCount, 10) {

}

int Gun::attack() {
	if (hasCount <= 0) {
		cout << "°ø°İ ±âÈ¸°¡ ¾ø½À´Ï´Ù!\n\n";
		return 0;
	}

	hasCount--;
	cout << "ÃÑ½î±â\n\n";
	return damage;
}

void Gun::grabEquipment() {
	cout << "ÃÑÀ» ÁÖ¿ü½À´Ï´Ù.\n\n";
	hasCount++;
}