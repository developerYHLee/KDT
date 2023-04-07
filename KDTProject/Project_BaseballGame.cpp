#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>
#define SIZE 3

using namespace std;

int computerNum[3];

int* split(string str) {
	int n, i = 0;
	int* res = new int[SIZE];
	stringstream sstream(str);
	while (sstream >> n) res[i++] = n;

	return res;
}

void throwTheBall() {
	bool vis[10] = { false };

	srand((unsigned int)time(NULL));

	for (int i = 0; i < SIZE; i++) {
		int num = rand() % 9 + 1;

		if (vis[num]) {
			i--;
			continue;
		}
		vis[num] = true;

		computerNum[i] = num;
	}
}

int main() {
	cout << "�߱� ����\n";
	throwTheBall();

	int count = 0;
	while (true) {
		start:
		cout << "1~9 ������ ���� 3���� �Է� �Ͻÿ� (�̿��� ���� : ����)\n";
		string num;
		getline(cin, num);
		int* userNum = split(num);
		
		bool vis[10] = { false };
		for (int i = 0; i < SIZE; i++) {
			if (userNum[i] <= 0 || userNum[i] > 9) {
				cout << "������ �����Ͽ����ϴ�.\n";
				return 0;
			}

			if (vis[userNum[i]]) {
				cout << "�ߺ��ؼ� �Է����� ������.\n";
				goto start;
			}
			vis[userNum[i]] = true;
		}

		count++;
		int strike = 0, ball = 0;
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				if (userNum[i] != computerNum[j]) continue;

				if (i == j) strike++;
				else ball++;
				break;
			}
		}

		if (strike == 3) break;

		cout << "Strike : " << strike << "\tBall : " << ball << endl;
	}

	cout << count << "�� ���� ������ϴ�.\n";
}