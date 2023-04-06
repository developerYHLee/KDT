#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int num = 0;
bool sayNum(int count) {
	for (int i = 1; i <= count; i++) {
		num++;
		cout << num << endl;
		if (num == 31) return false;
	}
	return true;
}

int main() {
	srand((unsigned int)time(NULL));

	while (true) {
		cout << "개수를 입력하세요 : ";
		int count;
		cin >> count;

		if (count < 1 || count > 3) {
			cout << "1~3 사이의 수를 입력하세요.\n\n";
			continue;
		}

		cout << "사용자가 부른 숫자!\n";
		if (!sayNum(count)) {
			cout << "게임 종료! 사용자의 패배입니다.\n";
			break;
		}

		int computer = rand() % 3 + 1;
		cout << "\n컴퓨터가 부른 숫자!\n";
		if (!sayNum(computer)) {
			cout << "게임 종료! 사용자의 승리입니다.\n";
			break;
		}

		cout << endl;
	}
}