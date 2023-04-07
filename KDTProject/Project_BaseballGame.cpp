#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>

using namespace std;

int computerNum[3];

vector<int> split(string str) {
	int n;
	vector<int> res;
	stringstream sstream(str);
	while (sstream >> n) res.push_back(n);

	return res;
}

void throwTheBall() {
	bool vis[10] = { false };

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 3; i++) {
		int num = rand() % 9 + 1;

		if (vis[num]) {
			i--;
			continue;
		}

		computerNum[i] = num;
	}
}

int main() {
	cout << "�߱� ����\n";
	throwTheBall();

	int count = 0;
	while (true) {
		cout << "1~9 ������ ���� 3���� �Է� �Ͻÿ� (�̿��� ���� : ����)\n";
		string num;
		getline(cin, num);
		vector<int> userNum = split(num);
		
		for (int i = 0; i < 3; i++) {
			if (userNum[i] <= 0 || userNum[i] > 9) {
				cout << "������ �����Ͽ����ϴ�.\n";
				return 0;
			}
		}

		count++;
		int strike = 0, ball = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (userNum[i] != computerNum[j]) continue;

				if (i == j) strike++;
				else ball++;
			}
		}

		if (strike == 3) break;

		cout << "Strike : " << strike << "\tBall : " << ball << endl;
	}

	cout << count << "�� ���� ������ϴ�.\n";
}