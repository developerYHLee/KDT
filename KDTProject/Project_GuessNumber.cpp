#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool computer[26];
bool user[26];

void makeComputerNum() {
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 6; i++) {
		int randNum = rand() % 25 + 1;

		if (computer[randNum]) {
			i--;
			continue;
		}
		computer[randNum] = true;
	}
}

void makeUserNum() {
	cout << "숫자는 1~25까지의 숫자만 입력할 수 있습니다.\n\n";

	for (int i = 1; i <= 6; i++) {
		cout << i << "번째 번호를 입력하세요 : ";
		int num;
		cin >> num;

		if (num > 25) {
			cout << "잘못된 숫자입니다. 다시 입력해주세요.\n";
			i--;
			continue;
		}

		if (user[num]) {
			cout << "이미 입력된 숫자입니다.\n";
			i--;
			continue;
		}

		user[num] = true;
	}
	cout << "-------------------------\n";
}

int main() {
	makeComputerNum();
	makeUserNum();
	
	cout << "\n당첨번호 공개!\n";
	for (int i = 1; i <= 25; i++) {
		if (computer[i]) cout << i << ' ';
	}
	
	int count = 0;
	for (int i = 1; i <= 25; i++) {
		if (user[i] && computer[i]) count++;
	}

	cout << "\n\n1~7등까지 결과가 나올 수 있습니다.\n결과 : ";
	switch (count) {
	case 0:
		cout << "7등입니다!\n";
		break;
	case 1:
		cout << "6등입니다!\n";
		break;
	case 2:
		cout << "5등입니다!\n";
		break;
	case 3:
		cout << "4등입니다!\n";
		break;
	case 4:
		cout << "3등입니다!\n";
		break;
	case 5:
		cout << "5등입니다!\n";
		break;
	case 6:
		cout << "1등입니다!\n";
		break;
	}
}