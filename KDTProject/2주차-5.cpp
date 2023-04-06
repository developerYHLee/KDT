#include <iostream>
#include <vector>

#include "Snack.h"

using namespace std;


int main() {
	while (true) {
		cout << "과자 바구니에 추가할 간식을 고르시오. (1 : 사탕, 2 : 초콜릿, 0 : 종료) : ";
		int num;
		cin >> num;

		string str;
		if (num == 0) break;
		else if (num == 1) {
			cout << "맛을 입력하세요 : ";
			cin >> str;
			str += "맛 사탕";
			Snack::hasSnack.push_back(str);
			Snack::count++;
		}
		else if (num == 2) {
			cout << "모양을 입력하세요 : ";
			cin >> str;
			str += "모양 초콜릿";
			Snack::hasSnack.push_back(str);
			Snack::count++;
		}
		else cout << "0~2 사이의 숫자를 입력하세요." << endl;
		cout << endl;
	}

	Snack::printSnack();
}