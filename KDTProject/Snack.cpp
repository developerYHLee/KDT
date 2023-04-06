#include "Snack.h"

int Snack::count = 0;
vector<string> Snack::hasSnack;

void Snack::printSnack() {
	cout << "\n과자 바구니에 담긴 간식의 개수는 " << Snack::count << "개 입니다." << endl << endl;
	cout << "과자 바구니에 담긴 간식 확인하기!" << endl;
	for (string s : Snack::hasSnack) cout << s << endl;
}