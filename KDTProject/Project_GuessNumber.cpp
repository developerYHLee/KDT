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
	cout << "���ڴ� 1~25������ ���ڸ� �Է��� �� �ֽ��ϴ�.\n\n";

	for (int i = 1; i <= 6; i++) {
		cout << i << "��° ��ȣ�� �Է��ϼ��� : ";
		int num;
		cin >> num;

		if (num > 25) {
			cout << "�߸��� �����Դϴ�. �ٽ� �Է����ּ���.\n";
			i--;
			continue;
		}

		if (user[num]) {
			cout << "�̹� �Էµ� �����Դϴ�.\n";
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
	
	cout << "\n��÷��ȣ ����!\n";
	for (int i = 1; i <= 25; i++) {
		if (computer[i]) cout << i << ' ';
	}
	
	int count = 0;
	for (int i = 1; i <= 25; i++) {
		if (user[i] && computer[i]) count++;
	}

	cout << "\n\n1~7����� ����� ���� �� �ֽ��ϴ�.\n��� : ";
	switch (count) {
	case 0:
		cout << "7���Դϴ�!\n";
		break;
	case 1:
		cout << "6���Դϴ�!\n";
		break;
	case 2:
		cout << "5���Դϴ�!\n";
		break;
	case 3:
		cout << "4���Դϴ�!\n";
		break;
	case 4:
		cout << "3���Դϴ�!\n";
		break;
	case 5:
		cout << "5���Դϴ�!\n";
		break;
	case 6:
		cout << "1���Դϴ�!\n";
		break;
	}
}