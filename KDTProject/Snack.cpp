#include "Snack.h"

int Snack::count = 0;
vector<string> Snack::hasSnack;

void Snack::printSnack() {
	cout << "\n���� �ٱ��Ͽ� ��� ������ ������ " << Snack::count << "�� �Դϴ�." << endl << endl;
	cout << "���� �ٱ��Ͽ� ��� ���� Ȯ���ϱ�!" << endl;
	for (string s : Snack::hasSnack) cout << s << endl;
}